#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#include "converter.h"
#include "element.h"

int main(void){
  char instruction[256];
  bool running = true;

  char (*ptInstruction)[256] = &instruction;
  Element *listCalc = malloc(256* sizeof(Element));

  while(1){
      
      if(fgets(instruction, sizeof(instruction), stdin) != NULL){

        //Quit the program
        if(strcmp(instruction, "exit\n") ==0){
          break;
        } 

        converter(ptInstruction, listCalc);
        
        int numberElements = findSize(ptInstruction);

        for(int i = 0; i < numberElements; i++){
          if(!isnan(listCalc[i].number)){
            printf("%.2f", listCalc[i].number);
          }else if(listCalc[i].operator != ' '){
            printf("%c", listCalc[i].operator);
        }
        }
      }else{
        printf("Reading error");
      }
  }

  return 0;
}
