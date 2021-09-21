#include <stdio.h>
#include <stdio.h>

int main(){
  int i, a[10];
  for(i=0; i<10; i++){
    a[i] = 1;
  }
  for(i = 0; i < 10; i++){
    printf("a(%d) = %d\n",i, a[i]);
  }
  return 0;
}
