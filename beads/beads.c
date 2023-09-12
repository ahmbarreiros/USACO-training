/*
ID: ahmbarr1
LANG: C
TASK: beads
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
  FILE* fIn = fopen("beadsIn.txt", "r");
  FILE* fOut = fopen("beadsOut.txt", "w");
  int numberOfBeads;
  fscanf(fIn, "%d", &numberOfBeads);
  char necklace[350];
  fscanf(fIn, "%s", necklace);
  int necklaceLength = strlen(necklace);
  int maxNumberForward = 0;
  int maxNumberBackwards = 0;
  int fPosition = 0;
  int bPosition = 0;
  for(int i = 0; i < necklaceLength; i++) {
    printf("---------- I: %d ------------\n", i);
    char necklaceBead = necklace[i];
    int numberForward = 0;
    int isWhite = 0;
    int numberBackwards = 1;
    if(necklaceBead == 'w') {
      int isWhite = 1;
    }
    for(int j = i+1; j != i; j++) {
      
      if(j >= necklaceLength-1) {
	j = j - necklaceLength;
      }
      
      
      printf("I: %d - J: %d\n", i, j);
      printf("%c - %c\n", necklace[i+1], necklace[j]);

	
	/* printf("1 - done!!\n"); */
      
      if(isWhite && necklace[j] != 'w') {
	++numberForward;
	break;
      }else if(necklace[i+1] == necklace[j] || necklace[j] == 'w') {
	++numberForward;
      } else {
	break;
      } 
    }
    printf("forwards: %d\n", numberForward);
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
      if(i == 4) {
	/* printf("I: %d - J: %d\n", i, j); */
	/* printf("%c - %c\n", necklaceBead, necklace[j]); */
      }
      if(isWhite && necklace[j] != 'w') {
	++numberBackwards;
	break;
      }else if(necklaceBead == necklace[j] || necklace[j] == 'w') {
	++numberBackwards;
      } else {
	break;
      }
    }
    printf("backwards: %d\n", numberBackwards);
    if(numberForward+numberBackwards > maxNumberForward+maxNumberBackwards) {
      maxNumberBackwards = numberBackwards;
      maxNumberForward = numberForward;
      bPosition = i;
      fPosition = i;
    }
  }
  int total = maxNumberForward + maxNumberBackwards;
  printf("forward: %d\nbackwards: %d\ntotal: %d\n", maxNumberForward, maxNumberBackwards, total);
  printf("forward: %d, backwards: %d\n", fPosition, bPosition);
  fclose(fIn);
  fclose(fOut);
  exit(0);
}
