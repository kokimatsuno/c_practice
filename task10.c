//氏名：松野光希
//学籍番号：71907528

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int charcmp(char *a, char *b){
//a,bの長さを格納
  unsigned long a_len;
  unsigned long b_len;

//文字列の長さ取得
  a_len = strlen(a);
  b_len = strlen(b);
  //aのほうがながければ-1を返し、bの方がながければ1を返す。
  if(a_len < b_len){
    return (-1);
  }else if(a_len > b_len){
    return (1);
  }else{            //a,bが同じ長さのとき
//aとbを一文字ずつ比較し、同じ限り続ける
//辞書的にaの方が先なら-1,bの方が先だったら1を返す
    while(*a == *b){
      if(strcmp(a, "\0") == 0){
        return (0);
      }
      a++;
      b++;
    }
    if(*a < *b){
      return (-1);
    }else{
      return (1);
    }
  }
}

int main(){
  char d[10][10]={"abc", "bbbb", "c", "aa", "koki", "sai", "keio", "keio", "cpp", "py"};
  int i;
  qsort((char *)d, 10, sizeof(d[0]), (void *)charcmp);
  for(i=0;i<10;i++){
    printf("%s, ", d[i]);
  }
  printf("\n");
}
