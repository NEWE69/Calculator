#include <stdio.h>
#include <math.h>
#include "converter.h"
#include "element.h"

/**
 * Convert String caracter into number
 */
void convertIntoNumber(char (*character)[128], int *pos, Element *e){
  int i = 0;
  double number = 0;
  while((*character)[i] != '\0'){
    number = number*10 + (double)((*character)[i] - '0');
    i++;
  }
  initializeElement(e, number, ' ', pos);
}

/**
 * Convert String caracter into logic operator 
 */
void convertIntoLogicOperator(char *character, int *pos, Element *e){
  initializeElement(e, NAN, *character, pos);
}

int findSize(char (*ptInstruction)[256]){
  int i = 0;
  while((*ptInstruction)[i] != '\n'){
    i++;
  }
  return i;
}

/**
 * Convert a String into a liste of numbers and operators
 */
void converter(char (*ptInstruction)[256], Element *e){
  int sizeText = findSize(ptInstruction);
  char c;
  char tabC[128];

  for(int i = 0; i < sizeText; i++){
    c = (*ptInstruction)[i];

    
    if(c >= '0' && c <= '9'){
      int j = i+1;

      // Check how long if the number
      while((*ptInstruction)[j] >= '0' && (*ptInstruction)[j] >= '9' 
          || (*ptInstruction)[j] == '.' || (*ptInstruction)[j] == ','){
        j++;
      }

      if(i+1 != j){
        for(int k = i; k < j; k++){
          tabC[i - k] = (*ptInstruction)[k]; 
        }
      }
      
      convertIntoNumber(&tabC, &i, e);

    }else if(c == '+' ||
              c == '-' ||
              c == '^'||
              c == ' '){

      convertIntoLogicOperator(&c, &i, e);

    }else{
      printf("Erreur, saisie non reconnue");
    }

  }
  printf("\n");
  
}
