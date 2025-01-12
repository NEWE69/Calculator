#ifndef ELEMENT_H
#define ELEMENT_H

typedef struct{
  double number;
  char operator;
  double result;
}Element;

void initializeElement(Element *e, double num, char operator, int *i);

#endif
