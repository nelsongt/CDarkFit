/* 
////////////////////////////////////////////////////////////////////////////////////
// 
//  Definitions file for function solver and returner
//
////////////////////////////////////////////////////////////////////////////////////
*/

#include "function.h"


double function_solver (void *params)
{
  struct solver_params *p = (struct solver_params *) params;
  
  int status = p->status;
  int iter = p->iter; 
  int max_iter = p->max_iter;
  const gsl_root_fsolver_type *T = p->T;
  gsl_root_fsolver *s = p->s;
  double r = p->r;
  double x_lo = p->x_lo;
  double x_hi = p->x_hi;
  gsl_function F = p->F;
  
  
  
  
  struct singleDiode_params diode_params = {1.0E-4, 0.0259, 2.0E-4, 100000, 0.1};

  F.function = &singleDiode_func;
  F.params = &params;

  T = gsl_root_fsolver_brent;
  s = gsl_root_fsolver_alloc (T);
  gsl_root_fsolver_set (s, &F, x_lo, x_hi);

  printf ("using %s method\n", 
          gsl_root_fsolver_name (s));

  printf ("%5s [%9s, %9s] %9s %9s\n",
          "iter", "lower", "upper", "root", 
          "err(est)");

  do
    {
      iter++;
      status = gsl_root_fsolver_iterate (s);
      r = gsl_root_fsolver_root (s);
      x_lo = gsl_root_fsolver_x_lower (s);
      x_hi = gsl_root_fsolver_x_upper (s);
      status = gsl_root_test_interval (x_lo, x_hi,
                                       0, 0.001);

      if (status == GSL_SUCCESS)
        printf ("Converged:\n");

      printf ("%5d [%.7f, %.7f] %.7f %.7f\n",
              iter, x_lo, x_hi,
              r, x_hi - x_lo);
    }
  while (status == GSL_CONTINUE && iter < max_iter);

  gsl_root_fsolver_free (s);

  return r;
}
