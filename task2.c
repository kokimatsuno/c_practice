#include <stdio.h>
#include <stdlib.h>
int main(){
  char a[6]; char *p;
  char c[] = "koki";
  long x;
  long y[5];


  a[0] ='K'; a[1] = 'O'; a[2] = 'K'; a[3] = 'I';
  a[4] = '\0';
  p = a;
  for(int i = 0; i<5; i++){
    printf("i%d=%p\n", i, &i);
    printf("a[%d] = %c, &a[%d] = %p\n", i, a[i], i, &a[i]);
  }
  printf("p = %p, *p = %c\n", &p, *p);
  printf("&x = %p\n", &x);

  for(int i = 0; i<5; i++){
      y[i] = i;
  }

  for(int i = 0; i<5; i++){
    printf("i%d=%p\n", i, &i);
    printf("y[%d] = %ld, &y[%d] = %p\n", i, y[i], i, &y[i]);
  }

  return 0;
}
