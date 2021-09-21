#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 256

struct frac{
  int shi;
  int bo;
};

int main(){
  int ret;
  char input[MAXLINE];
  struct frac f,g,h;

  fgets(input, MAXLINE, stdin);
  ret = sscanf(input, "%d/%d", &f.shi, &f.bo);
  //printf("%d/%d\n", f.shi, f.bo);
  if(ret != 2){exit(1);}
  fgets(input, MAXLINE, stdin);
  ret = sscanf(input, "%d/%d", &g.shi, &g.bo);
  if(ret != 2){exit(1);}
  //printf("%d/%d", g.shi, g.bo);

 h.shi = f.shi * g.bo
         + g.shi * f.bo;
  h.bo = f.bo * g.bo;
  printf("%d/%d + %d/%d = %d/%d\n", f.shi, f.bo, g.shi, g.bo, h.shi, h.bo);
  exit(0);
}
