//氏名：松野　光希
//学籍番号：71907528

#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 256

struct frac{
  int shi;
  int bo;
}f, g, h;

int mygcd(int a, int b){
  int c;
  while (b != 0){
    c = a % b;
    a = b;
    b = c;
  }
  if(a<0){a *= -1;}
  return a;
}

void reduction_print(char x){
  int gcd;
  gcd = mygcd(h.shi, h.bo);

  h.shi = h.shi / gcd;
  h.bo = h.bo / gcd;

  if(h.bo == 1){
  printf("%d/%d %c %d/%d = %d\n", f.shi, f.bo, x, g.shi, g.bo, h.shi);
} else if(h.bo < 0){
  h.shi *= -1; h.bo *= -1;
  if(h.bo == 1){
    printf("%d/%d %c %d/%d = %d\n", f.shi, f.bo, x, g.shi, g.bo, h.shi);
  } else{
    printf("%d/%d %c %d/%d = %d/%d\n", f.shi, f.bo, x, g.shi, g.bo, h.shi, h.bo);
    }
} else{
    printf("%d/%d %c %d/%d = %d/%d\n", f.shi, f.bo, x, g.shi, g.bo, h.shi, h.bo);
  }

  return;
}

int main(){
  int ret;
  char input[MAXLINE];

  fgets(input, MAXLINE, stdin);
  ret = sscanf(input, "%d/%d", &f.shi, &f.bo);
  if(ret != 2){exit(1);}
  fgets(input, MAXLINE, stdin);
  ret = sscanf(input, "%d/%d", &g.shi, &g.bo);
  if(ret != 2){exit(1);}

 //足し算
  h.shi = f.shi * g.bo
         + g.shi * f.bo;
  h.bo = f.bo * g.bo;
  reduction_print('+');


//引き算
  h.shi = f.shi * g.bo - g.shi * f.bo;
  h.bo = f.bo * g.bo;
  reduction_print('-');


//掛け算
  h.shi = f.shi * g.shi;
  h.bo = f.bo * g.bo;
  reduction_print('*');


//割り算
  h.shi = f.shi * g.bo;
  h.bo = f.bo * g.shi;
  reduction_print('/');


  return 0;
}
