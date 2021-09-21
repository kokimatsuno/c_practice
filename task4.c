 /* -*- coding: utf-8 -*- */
//
//氏名：松野　光希
//学籍番号：71907528
//鶴亀算
//


#include <stdio.h>
#include <string.h>
#define MAXLINE 256

int a, b, x, y;
char input[MAXLINE];
char input2[MAXLINE];


//足と頭の数の入力
void scan(){
  int ret0 = 0, ret1 = 0;
  while(ret0 != 1){
    printf("足の本数：");
    fgets(input, MAXLINE, stdin);
    ret0 = sscanf(input, "%d", &a);
    if (ret0 <= 0){
      printf("Invalid input. Please enter an integer\n");
    }
    }

  while(ret1 != 1){
    printf("頭の数：");
    fgets(input, MAXLINE, stdin);
    ret1 = sscanf(input, "%d", &b);
    if (ret1 <=0){
      printf("Invalid input. Please enter an integer\n");
    }
  }

  return;
}


int main(){
while(1){

 scan();

//鶴亀算
  x = a - 2 * b;
  x = x / 2;
  y = b - x;

//正しい組み合わせのときのみ、亀と鶴の数を表示
  if(x + y == b && 4*x + 2*y == a && x >= 0 && y >= 0){
  printf("亀の数：%d, 鶴の数：%d\n", x, y);
}else{
  printf("正しい数の組み合わせを入力してください。\n");
  continue;
}

//繰り返しの確認
  printf("Do you continue?[y/n]");
  fgets(input2, MAXLINE, stdin);
  sscanf(input2, "%s", input2);

  if(strcmp(input2, "y") == 0 || strcmp(input2, "yes") == 0 || strcmp(input2, "Y") == 0){
    continue;
  }else{
    break;
  }
}
  return 0;
}
