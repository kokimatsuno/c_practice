#include <stdio.h>
#include <stdlib.h>

union uni_const{
  int a;
  long b;
  long long c;
}v;

int main(){
  v.a = 10;
  printf("v.a = 10, &v.a = %p\n", &v.a);
  v.b = 20;
  printf("v.b = 20, &v.b = %p\n", &v.b);
  v.c = 30;
  printf("v.c = 30, &v.c = %p\n", &v.c);

  return 0;
}
