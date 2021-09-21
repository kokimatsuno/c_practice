#include <stdio.h>
#include <stdlib.h>

double mean(double x, double y){
  double c;
  c = (x + y)/2;
  return c;
}

int main(int argc, char *argv[]){
  double a,b,c;
  a = 12.0;
  b = 5.0;
  c = mean(a,b);
  printf("aとcの平均は%fです",c);
  exit(0);
}
