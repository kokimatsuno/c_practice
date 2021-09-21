#include<stdio.h>

int main(){
  int a = 0;
  int b = 1;
  int c;
  for(int x = 0; x < 30; x = x+1){
    c = a + b;
    printf("%d\n",b);
    a = b;
    b =  c;
  }
  return 0;
}
