/*
ID: ahmbarr1
LANG: C
TASK: gift1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person {
  char name[16];
  int money;
};

void main() {
  //FILE* fIn = fopen("gift1.in", "r");
  //FILE* fOut = fopen("gift1.out", "w");
  FILE* fIn = fopen("gift1In.txt", "r");
  FILE* fOut = fopen("gift1Out.txt", "w");
  char line[216];
  int NP = 0;
  fscanf(fIn, "%d", &NP);
  int lineCount = 1, i = 0;
  struct Person *people;
  if(NP) {
    people = malloc(NP * sizeof(struct Person));
    for(i = 0; i < NP; i++) {
      fscanf(fIn, "%s", line);
      strcpy(people[i].name, line);
      people[i].money = 0;
      lineCount++;
    }
  }

  int lineMoney = 0, lineDivide = 0, divideIteration = 0;
  int isInPerson = 0;
  int isFirst = 1;
  struct Person *personGiving;
  while(fscanf(fIn, "%s", line) == 1) {
    if(line != "" || line != " " || line != "\n" || line != "\r" || line != NULL || line != "/t" || line != "/f" || line != "/v") {
      if(!isInPerson) {
	for(i = 0; i < NP; i++) {
	  if(strcmp(line, people[i].name) == 0) {
	    personGiving = &people[i];
	    fscanf(fIn, "%d %d", &lineMoney, &lineDivide);
	    lineCount++;
	    if(lineDivide != 0) {
	      personGiving->money = (personGiving->money - lineMoney) + (lineMoney % lineDivide);
	    } else {
	      personGiving->money -= 0;
	    }
	    isInPerson = 1;
	  }
	}
      } else if(isInPerson) {
	for(i = 0; i < NP; i++) {
	  if(strcmp(line, people[i].name) == 0) {
	    if(lineDivide != 0) {
	      people[i].money += (lineMoney / lineDivide);
	    } else {
	      people[i].money += 0;
	    }
	  }
	}
      }
      if(lineDivide) {
	if(divideIteration < lineDivide) {
	  divideIteration++;
	} else if(divideIteration == lineDivide) {
	  lineDivide = 0;
	  isInPerson = 0;
	  divideIteration = 0;
	  lineMoney = 0;
	}
      
      }

      if(isInPerson == 1 && lineDivide == 0) {
	isInPerson = 0;
      }
      lineCount++;
      isFirst = 0;
    }
  }

  for(i = 0; i < NP; i++) {
    printf("%s %d\n", people[i].name, people[i].money);
    fprintf(fOut, "%s %d\n", people[i].name, people[i].money);
  }

  
  free(people);
  fclose(fIn);
  fclose(fOut);
  exit(0);
}
