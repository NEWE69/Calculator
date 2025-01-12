#include "exponential.h"
#include <stdbool.h>

/**
 * Square of a number
 */
void nbSquare(double *n, double *r){
  *r = *r * *n;
}

/**
 * Exponential of a number | exponential in Z
 */
void exponential(double *n, double *e, double *r){
  bool isNegative = false;
  *r = 1;

  if(*e == 1){
    return;
  }
  
  if(*e<0){
    isNegative = true;
    *e = -*e;
  }

  for(int i = 0; i < *e; i++){
    nbSquare(n, r);
  }
  
  if(isNegative){
    *r =  1.0 / *r;
  }
}


