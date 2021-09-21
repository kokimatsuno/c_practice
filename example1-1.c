#include <stdio.h>
#include <stdlib.h>

int mygcd(int a, int b){
  int c;
  while(b != 0){
    c = a%b;
    a = b;
    b = c;
  }
  return a;
}

int main(int argc, char *argv[]){
  int i,j,k;
  i = 1000;
  j = 35;
  k = mygcd(i,j);
  printf("最大公約数は%dです。\n", k);
  exit(0);
}
