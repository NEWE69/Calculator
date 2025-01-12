#include <stdio.h>
#include <math.h>

#include "element.h"

void initializeElement(Element *e, double num, char operator, int *i){
  e[*i].number = num;
  e[*i].operator = operator;
}
