/* kadai5.c */
// 課題No5(5月28日の課題)プログラム例
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#define MAXLEN 8

// 自己参照構造体の定義
struct list {
  struct list *next;
  char *name;
};

int main(){
  char input[MAXLEN], *s;
  // 自己参照構造体によるリスト構造を示すポインタの定義
  // start: 先頭を示すポインタ(最初に割り当てて以降変化しない)
  // current: メモリが割り当てられている最後のポインタ
  // new:1行入力されたときに、新たに割り当てた領域を示すポインタ
  struct list *start, *current, *new;

  // 最初は、データを格納する領域が割り当てられていないので、startをNULLにする
  start = NULL;
  // fgetsで、control-Dがおされるまで1行入力
  for(;;){
    s = fgets(input,MAXLEN,stdin);
    if(s == NULL){
      break;
    }
    s = index(input,'\n');
    if(s!=NULL){ // 改行文字を終端文字で置き換え
      *s = '\0';
    }else{ // 次の改行まで読み飛ばす
      while(getchar()!='\n');
    }

    // 配列 input にある文字列を、新たに確保した構造体に格納する
    // まず、list構造体の場所を確保
    new = malloc(sizeof(struct list));
    // 次に、inputを格納する文字列の領域を確保し、list構造体のnameメンバにポインタを格納
    new->name = malloc(sizeof(char)*strlen(input)+1);
    // 確保した領域にinputにある文字列を複製する
    strcpy(new->name,input);
    // list構造体のnextメンバをNULLポインタにする
    new->next = NULL;
    // startがNULLかどうかを調べる
    // NULLだったら、最初の1行の入力なので、新しく確保したlist構造体のポインタをstartに入れる
    if(start == NULL){
      start = new;
    }else{ // 最初の1行でない場合
           // 新しく確保したlist構造体のポインタを、この時点での最後のlist構造体のnextメンバに入れる
      current->next = new;
    }
    current = new; // 新たに確保したlist構造体を、最後のlist構造体にする
  }
  // 登録されたlist構造体データを順番に表示
  // startのポインタから順番に、NULLポインタになるところまでたどる
  // nameメンバを表示して、ポインタをnextメンバにしてくりかえす
  for(current = start; current!=NULL; current = current->next){
    printf("%s\n",current->name);
  }
  exit(0);
}


//#define MAXLEN 8
