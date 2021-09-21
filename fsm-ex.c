#include <stdio.h>
#include <unistd.h>

#define NODE_1 0
#define NODE_2 1
#define NODE_3 2
#define NODE_4 3
#define NODE_A 4
#define NODE_B 5
#define NODE_C 6
#define NODE_D 7
#define NODE_END 100

#define NODE_START NODE_1

void func_a();

void hello_func(){
  printf("hello");
}

struct fsm_trans{
  int node;
  int yes;
  int no;
  void (*func_a)(void);
  char message[100];
};

struct fsm_trans fsmtable[] = {
  {NODE_1, NODE_2, NODE_3, hello_func, "You like cow(y/n)"},
  { NODE_2, NODE_A, NODE_4, hello_func, "You like whale (y/n)" },
{ NODE_3, NODE_4, NODE_C, hello_func, "You like mouse (y/n)" },
{ NODE_4, NODE_B, NODE_D, hello_func, "You like rabbit (y/n)" },
{ NODE_A, NODE_END, NODE_END,hello_func, "You are type A" },
{ NODE_B, NODE_END, NODE_END,hello_func, "You are type B" },
{ NODE_C, NODE_END, NODE_END,hello_func, "You are type C" },
{ NODE_D, NODE_END, NODE_END,hello_func, "You are type D"}
};

int main(){
  int state;
  char input[256], *p;

  for(;;){
    if(fsmtable[state].yes == NODE_END){
      break;
    }
    printf("%d", state);
    hello_func();
    printf("Question:%s\n", fsmtable[state].message);
    p = fgets(input, 255, stdin);
    if(p != NULL){
      if(input[0] == 'y'){
      state = fsmtable[state].yes;
    }else if(input[0] == 'n'){
      state = fsmtable[state].no;
    }else{
    }
  }
}
  printf("%s\n", fsmtable[state].message);
  return 0;
}
