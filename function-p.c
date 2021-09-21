#include <stdio.h>
#include <stdlib.h>

int multi2(int a, int b){
  b = a * 2;
  printf("a = %d, b = %d\n", a, b);

  return a, b;
}

int main(){
  int p=10, q=0;

  multi2(p,q);
  printf("p=%d, q=%d", p, q);

  return 0;
}
