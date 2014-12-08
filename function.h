/* 
////////////////////////////////////////////////////////////////////////////////////
// 
//  Header file for function solver and returner
//
////////////////////////////////////////////////////////////////////////////////////
*/

#include <gsl/gsl_errno.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_roots.h>

#include "singlediode.h"


struct solver_params
  {
    int status, iter, max_iter;
    const gsl_root_fsolver_type *T;
    gsl_root_fsolver *s;
    double r, x_lo, x_hi;
    gsl_function F;
    struct singleDiode_params params;
  };
  
  
double function_solver (void *params);