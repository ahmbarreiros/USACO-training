/*
ID: ahmbarr1
LANG: C
TASK: ride
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
  //FILE* fIn = fopen("ride.in", "r");
  //FILE* fOut = fopen("ride.out", "w");

  FILE* fIn = fopen("rideIn.txt", "r");
  FILE* fOut = fopen("rideOut.txt", "w");
  char comet[8], group[8];
  unsigned int cometCode = 1, groupCode = 1;
  int i = 0;
  
  fscanf(fIn, "%s", comet);
  fscanf(fIn, "%s", group);
  int sizeofComet = strlen(comet);
  int sizeofGroup = strlen(group);
  
  for(i = 0; i < sizeofComet; i++) {
    if(comet[i] >= 65 && comet[i] <= 90) {
      cometCode *= (comet[i] - 64);
    }
  }

  for(i = 0; i < sizeofGroup; i++) {
    if(group[i] >= 65 && group[i] <= 90) {
      groupCode *= (group[i] - 64);
    }
  }

  cometCode = cometCode % 47;
  groupCode = groupCode % 47;

  if(cometCode == groupCode) {
    printf("GO\n");
    fprintf(fOut, "GO\n");
  }
  else {
    printf("STAY\n");
    fprintf(fOut, "STAY\n");
  }
  
  fclose(fIn);
  fclose(fOut);
  exit(0);
}
