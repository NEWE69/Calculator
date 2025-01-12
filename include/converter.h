#ifndef CONVERTER_H
#define CONVERTER_H

#include "element.h"

void convertIntoNumber(char (*character)[128], int *i, Element *e);

void convertIntoLogicOperator(char *character, int *i, Element *e);

int findSize(char (*text)[256]);

void converter(char (*text)[256], Element *e);

#endif
