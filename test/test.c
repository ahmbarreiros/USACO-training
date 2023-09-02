/*
ID: ahmbarr1
LANG: C
TASK: test
*/

#include <stdio.h>
#include <stdlib.h>

void main() {
  
  FILE *fIn = fopen("test.in", "r");
  FILE *fOut = fopen("test.out", "w");

  int a, b;

  fscanf(fIn, "%d %d", &a, &b);
  fprintf(fOut, "%d\n", a+b);
  
  exit(0);
}
