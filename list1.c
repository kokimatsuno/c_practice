#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLEN 8

struct list{
  struct list *next;
  char *name;
};

int main(){
  struct list *p, *q;
  char *s;

  p = (struct list*)malloc(sizeof(struct list));
  p ->name = malloc(sizeof(char)*6);
  strcpy(p->name, "START");
  q = malloc(sizeof(struct list));
  p->next = q;
  q->next = NULL;
  q->name = malloc(sizeof(char)*4);
  strcpy(q->name, "END");
  printf("%s, %s", p->name, q->name);


return 0;
}
