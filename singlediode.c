/* 
////////////////////////////////////////////////////////////////////////////////////
// 
//  Definitions file for single diode model function
//
////////////////////////////////////////////////////////////////////////////////////
*/

#include "singlediode.h"

double singleDiode_func (double x, void *params)
{
  struct singleDiode_params *p = (struct singleDiode_params *) params;

  double a = p->a;
  double b = p->b;
  double c = p->c;
  double d = p->d;
  double e = p->e;
  
  return a * exp((e - x*c)/b) + ((e - x*c)/d) - x;
}

/*double singleDiode_deriv (double x, void *params)
{
  struct singleDiode_params *p 
    = (struct singleDiode_params *) params;

  double a = p->a;
  double b = p->b;
  double c = p->c;

  return 2.0 * a * x + b;
}*/

/*void singleDiode_fdf (double x, void *params, double *y, double *dy)
{
  struct singleDiode_params *p 
    = (struct singleDiode_params *) params;

  double a = p->a;
  double b = p->b;
  double c = p->c;

  *y = (a * x + b) * x + c;
  *dy = 2.0 * a * x + b;
}*/