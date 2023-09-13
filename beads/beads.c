/*
ID: ahmbarr1
LANG: C
TASK: beads
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
  //FILE* fIn = fopen("beadsIn.txt", "r");
  //FILE* fOut = fopen("beadsOut.txt", "w");

  FILE* fIn = fopen("beads.in", "r");
  FILE* fOut = fopen("beads.out", "w");
  
  int numberOfBeads;
  fscanf(fIn, "%d", &numberOfBeads);
  
  char necklace[350];
  fscanf(fIn, "%s", necklace);
  
  int necklaceLength = strlen(necklace);
  
  int maxNumberForward = 0;
  int maxNumberBackwards = 0;
  
  //int fPosition = 0;
  //int bPosition = 0;
  
  for(int i = 0; i < necklaceLength; i++) {
    
    //printf("---------- I: %d ------------\n", i);
    
    char necklaceBead = necklace[i];
    
    int numberBackwards = 1;
    int numberForward = 0;
    int usedForward = 0;
    int isWhite = 0;
    int isPainted = 0;
    if(necklaceBead == 'w') {
      int isWhite = 1;
    }
    
    for(int j = i+1; j != i; j++) {
      if(j > necklaceLength-1) {
	j = j - necklaceLength;
      }
      if(i+1 == j && !isPainted && (necklace[i] == necklace[j] || necklace[j] == 'w')) {
	usedForward = 1;
	++numberForward;
	necklaceBead = necklace[i];
	//printf("I: %d - J: %d\n", i, j);
	//printf("%c - %c\n", necklaceBead, necklace[j]);
      } else if(!usedForward && !isPainted && i != necklaceLength - 1) {
	necklaceBead = necklace[i + 1];
	if(necklaceBead == 'w') {
	  isWhite = 1;
	}
	//printf("I: %d - J: %d\n", i, j);
	//printf("%c - %c\n", necklaceBead, necklace[j]);
      } else if(!isPainted) {
	necklaceBead = necklace[i];
	//printf("I: %d - J: %d\n", i, j);
	//printf("%c - %c\n", necklaceBead, necklace[j]);
      }
      //printf("\t is white?: %d\n", isWhite);
      

	
	/* printf("1 - done!!\n"); */
      
      if(isWhite && necklace[j] != 'w') {
	//printf("\tCASE 1\n");
	necklaceBead = necklace[j];
	isWhite = 0;
	isPainted = 1;
	++numberForward;
      } else if(isPainted && (necklaceBead == necklace[j] || necklace[j] == 'w')) {
	//printf("\tCASE 2\n");
	//printf("%c - %c\n", necklaceBead, necklace[j]);
	++numberForward;
      } else if(necklaceBead == necklace[j] || necklace[j] == 'w') {
	//printf("\tCASE 3\n");
	++numberForward;
      } else {
	//printf("\tCASE 4\n");
	break;
      } 
    }
    isPainted = 0;
    //printf("forwards: %d\n", numberForward);
    //printf("used forward?: %d\n", usedForward);
    /* if(numberForward+numberBackwards > maxNumberForward+maxNumberBackwards) { */
    /* 	maxNumberForward = numberForward; */
    /* 	fPosition = i; */
    /* } */
    for(int j = i-1; j != i; j--) {
      if(j < 0) {
	j = necklaceLength + j;
      } else if(j == 0) {
	j = necklaceLength - 1;
      }
      if(usedForward) {
	necklaceBead = necklace[i - 1];

	//printf("I: %d - J: %d\n", i, j);
	//printf("%c - %c\n", necklaceBead, necklace[j]);
      } else {
	necklaceBead = necklace[i];
	//printf("I: %d - J: %d\n", i, j);
	//printf("%c - %c\n", necklaceBead, necklace[j]);
      }
      if(necklaceBead == 'w') {
	isWhite = 1;
      }
      
      if(isWhite && necklace[j] != 'w') {
	//printf("\tCASE 1\n");
	isPainted = 1;
	isWhite = 0;
	necklaceBead = necklace[j];
	++numberBackwards;
	break;
      }else if(isPainted && (necklaceBead == necklace[j] || necklace[j] == 'w')) {
	//printf("\tCASE 2\n");
	++numberBackwards;
      } else if(necklaceBead == necklace[j] || necklace[j] == 'w') {
	//printf("\tCASE 3\n");
	++numberBackwards;
      } else {
	//printf("\tCASE 4\n");
	break;
      }
    }
    if(usedForward) {
      numberBackwards--;
    }
    //printf("backwards: %d\n", numberBackwards);
    if(numberForward+numberBackwards > maxNumberForward+maxNumberBackwards) {
      maxNumberBackwards = numberBackwards;
      maxNumberForward = numberForward;
      //bPosition = i;
      //fPosition = i;
    }
  }
  int total = maxNumberForward + maxNumberBackwards;
  fprintf(fOut, "%d\n", total);
  //printf("forward: %d\nbackwards: %d\ntotal: %d\n", maxNumberForward, maxNumberBackwards, total);
  //printf("forward: %d, backwards: %d\n", fPosition, bPosition);
  fclose(fIn);
  fclose(fOut);
  exit(0);
}
