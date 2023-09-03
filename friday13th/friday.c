/*
ID: ahmbarr1
LANG: C
TASK: friday
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct WeekDay {
  char Day[16];
  int Quantity;
} WeekDay;

typedef struct Node {
  WeekDay value;
  struct Node* next;
} Node;

typedef struct LinkedList {
  Node* head;
  Node* tail;
} LinkedList;

typedef struct Date {
  unsigned int Day;
  unsigned int Month;
  unsigned int Year;
  WeekDay* DayOfWeek;
} Date;


LinkedList* create_list() {
  LinkedList* li = (LinkedList*)malloc(sizeof(LinkedList));
  if(li != NULL) {
    li->head = NULL;
    li->tail = NULL;
    return li;
  } else {
    printf("fail creating list\n");
  }
}

void free_list(LinkedList* li) {
  if(li != NULL && li->head != NULL) {
    Node* node = li->head;
    
    do {
      Node* next_node = node->next;
      free(node);
      node = next_node;
    } while(node != li->head);
    free(li);
  }
}

int append_list(LinkedList* li, char* value) {
  if(li != NULL) {
    Node* new_node = (Node*)malloc(sizeof(struct Node));
    strcpy(new_node->value.Day, value);
    new_node->value.Quantity = 0;
    new_node->next = NULL;
    if(li->head == NULL) {
      li->head = new_node;
      li->tail = new_node;
    } else {
      li->tail->next = new_node;
      li->tail = new_node;
      new_node->next = li->head;
    }
    return 1;
  }
  return 0;
}

WeekDay* find_list(LinkedList* li, char* value) {
  if(li != NULL) {
    Node* node = li->head;
    do {
      if(strcmp(node->value.Day, value) == 0) {
	return &node->value;
      }
      node = node->next;
    } while(node != li->head);
    
  }
}

void print_list(LinkedList* li) {
  if(li != NULL && li->head != NULL) {
    Node* node = li->head;
    printf("[");
    do {
      printf("%s - %d -> ", node->value.Day, node->value.Quantity);
      node = node->next;
    } while(node != li->head);
    printf("]\n");
  }
}

int is_leap_year(int year) {
  if(year % 100 == 0 && year % 400 == 0) {
    return 1;
  } else if(year % 100 != 0 && year % 4 == 0) {
    return 1;
  } else {
    return 0;
  }
}

int give_month_days(int month, int year) {
  switch(month) {
  case 4:
  case 6:
  case 9:
  case 11:
    return 30;
  case 2:
    if(is_leap_year(year)) {
      return 29;
    } else {
      return 28;
    }
  default:
    return 31;
  }
}

void main() {
  
  //FILE* fIn = fopen("fridayIn.txt", "r");
  //FILE* fpout = fopen("fridayOut.txt", "w");

  FILE* fIn = fopen("friday.in", "r");
  FILE* fpout = fopen("friday.out", "w");
  
  unsigned int NumberOfYears;
  fscanf(fIn, "%d", &NumberOfYears);
  LinkedList* li = create_list();
  append_list(li, "Saturday");
  append_list(li, "Sunday");
  append_list(li, "Monday");
  append_list(li, "Tuesday");
  append_list(li, "Wednesday");
  append_list(li, "Thursday");
  append_list(li, "Friday");
  Date CurrentDate;
  
  CurrentDate.Day = 1;
  CurrentDate.Month = 1;
  CurrentDate.Year = 1900;
  CurrentDate.DayOfWeek = (find_list(li, "Monday"));
    

  Node* current_node = li->head->next->next;
  int TimePeriod = CurrentDate.Year + NumberOfYears;
  
  while(CurrentDate.Year != TimePeriod) {
    int CurrentMonthDays = give_month_days(CurrentDate.Month, CurrentDate.Year);
       
    for(CurrentDate.Day; CurrentDate.Day <= CurrentMonthDays; CurrentDate.Day++) {
      if(CurrentDate.Day == 13) {
	CurrentDate.DayOfWeek->Quantity++;
      }
      current_node = current_node->next;
      CurrentDate.DayOfWeek = &current_node->value;
    }
    CurrentDate.Day = 1;
    if(CurrentDate.Month == 12) {
      CurrentDate.Month = 1;
      CurrentDate.Year++;
    } else {
      CurrentDate.Month++;
    }
    
  }
  
  Node* node_write = li->head;
  do {
    int value = node_write->value.Quantity;
    if(node_write->next != li->head) {
      fprintf(fpout, "%d ", value);
    } else {
      fprintf(fpout, "%d", value);
    }
    //printf("%d ", node_write->value.Quantity);

    node_write = node_write->next;
  } while(node_write != li->head);
  fprintf(fpout, "%s", "\n");

  fclose(fIn);
  fclose(fpout);
  free_list(li);
  exit(0);
}
