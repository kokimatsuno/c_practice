// arrayobj.c
//
// 配列オブジェクトひな型
//
// C言語でJavascriptのような配列オブジェクト機能を作成してください
// 扱う要素は、long型とします
//
// プロトタイプ宣言が書かれている4つの関数の作成は必須です。
// main関数の中からの呼び出しの記述がうまく動作するように作成してください。
// Javascriptの配列データのほかのメソッド、shift(先頭要素の削除)、
// unshift(先頭への要素の追加)などは、加点対象にしますが、
// main関数の最後に、その関数を使って呼び出しを記述して、
// どのような表示結果になるかを、元からある呼び出し例にならって記述してください
//
// aobj_push(),aobj_pop()の返すポインタを使っていませんが、
// 機能を追加する場合には、意味のあるポインタを返すようにしてかまいません
// ただし、元のプログラムはそのまま動作しないといけません。
//
// グローバル変数は使わないようにしてください。
// また、static変数も使わないようにして、
// 複数のスレッドから同時に呼び出されても不具合が生じないようにしてください
// 提出するのは、作成した関数の記述を追加した、本プログラムarrayobj.cです
// コンパイラの種類にもよりますが、基本的に注意メッセージがでないようにしてください
// また、動作や変数、関数の説明も必ずコメントとして記述してください
//
//氏名：松野光希
//学籍番号：71907528
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
// 必要なヘッダファイルはこの後に追加してください

// ここに、自分で考えた構造体の定義を記述します
struct aobj {
  struct aobj *next;
  long number;
};

// 次の4つの関数は、プロトタイプ宣言は、そのまま変更せず、
// これらに合致するように関数を作成してください
//
// 初期化の関数のプロトタイプ宣言
struct aobj *aobj_init();
//
// 配列の末尾に要素を追加する関数のプロトタイプ宣言
// 追加する要素を第2引数に入れて関数を呼び出す
struct aobj *aobj_push(struct aobj *a, long item);
//
// 配列の末尾の要素を削除する関数のプロトタイプ宣言
// 削除される要素を第2引数に入れ、その後でその要素を削除する
struct aobj *aobj_pop(struct aobj *a, long *item);
//
// 要素の個数を返す関数のプロトタイプ宣言
// 個数を返せる場合は関数の値として1を返し、エラーの場合は0を返す
// 個数は第2引数に入れる
// 配列の要素の個数が0の場合には，関数の値として1が返り，個数には0が入る
int aobj_len(struct aobj *a, unsigned int *len);      //長さ関数

//
// ここに必要な関数を作成し、記述してください
// struct aobj *aobj_push(struct aobj *a, long item){
//   ....
//   ....
// }


//新たなaobj構造体をつくり、NULLをいれておく
//作った構造体のポインタを返す
struct aobj *aobj_init(){
  struct aobj *first;
    first = NULL;
    return first;
}


//先頭を示すポインタを返す
struct aobj *aobj_push(struct aobj *a, long item){
 //new:新しく入力された数字をいれる構造体
 //top:先頭を示すポインタ
  struct aobj *new, *top;
   top = a;

   new = (struct aobj*)malloc(sizeof(struct aobj));   //aobj構造体の場所を確保
   new->number = (long)malloc(sizeof(long));          //long型の数字の格納する場所の確保
   new->number = item;          //入力されたlong型数字を格納
   new->next = NULL;            //次の構造体にはNULLポインタを入れる

//初めての追加か判定
//aがNULLであれば、newをそのまま、aに入れ、そのポインタを返す
   if(a == NULL){
     a = new;
     return a;
   }
   //初めての追加でなければ、aの最後を探し、そこにnewを入れる
   while(a->next != NULL){
     a = a->next;
   }
   a->next = new;
//先頭を示すポインタを返す
   return top;
}

//消去後の最後の構造体のポインタを返す
struct aobj *aobj_pop(struct aobj *a, long *item){
  //tmp : 現在の構造体のポインタ
  //top : 先頭を示すポインタ
  struct aobj *tmp;
  struct aobj *top;

  top = a;

  while (a != NULL){
    if(a->next->number == *item){
  //現在いる構造体の次の構造体のnumberが消去される値のとき
      tmp = a;
      free(a->next);  //次の構造体のメモリを解放
      a->next = NULL;   //現在のポインタのnextにNULLを入れ直す

      a = top;    //aを先頭ポインタに戻す
      break;
    }
    a = a->next;
  }
  a = top;
  return tmp;   //現在（最後）の構造のポインタを返す
}

int aobj_len(struct aobj *a, unsigned int *len){
//top:先頭のポインタを格納
  struct aobj *top;
  top = a;
  *len = 1;
  if(a==NULL){    //aになにも入っていないときは*lenに0をいれる
    *len=0;
  }else{
//a->nextがNULLになるまで*lenに１を加えながら繰り返す。
  while(a->next != NULL){
    *len = *len + 1;
     a = a->next;
  }
}
  a = top;

  if(*len < 0){   //lenが不正な値であれば0を返す。
    return 0;
  }   //それ以外であれば1を返す
    return 1;
}


//
// mainは次のとおりとし、そのままコンパイルし、実行できるようにします
// 例えば、実行例は次のようになります
//
// %./kadai
// 10
// 20
// 40
// 30 <- このあとctrl-Dを入力
// len = 4  <- 入れた個数が表示されます
// remove 30, len = 3  <- 最後の要素を削除した結果
// remove 40, len = 2  <- もう一度、最後の要素を削除した結果
// %
//
//
#define MAXINPUT 10

int main(){
  struct aobj *myobj;
  char input[MAXINPUT];
  char *ret;
  long num, lastone;
  unsigned int len;
  struct aobj *lastone_a;

//lastone : 最後の数字
//lastone_a : 最後の構造体

  myobj = aobj_init();
  // 数値の入力の繰り返し
  for(;;){
    ret = fgets(input,MAXINPUT,stdin);
    if(ret == NULL){
      break;
    }
    ret = strchr(input,'\n');
      if(ret!=NULL){
      *ret = '\0';
    }else{
      while(getchar()!='\n');
    }
   num = strtol(input,NULL,10);//long型に変換
      lastone =num;       //入力した文字をlastoneに入れる
    myobj = aobj_push(myobj, num);          //入力した数字をlist型構造へ入力
  }
  // 長さの表示
  aobj_len(myobj,&len);
  printf("len = %u\n",len);
  // 最後の要素の削除と長さの表示、lastone_a : 消去後の最後の構造体のポインタ
  lastone_a = aobj_pop(myobj, &lastone);
  aobj_len(myobj,&len);
  printf("remove %ld, len = %u\n",lastone,len);
  // もう一度、最後の要素の削除と長さの表示、lastoneに消去すべき残存の構造体の最後の数字を入れる
  lastone = lastone_a->number;
  aobj_pop(myobj, &lastone);
  aobj_len(myobj,&len);
  printf("remove %ld, len = %u\n",lastone,len);
  exit(0);
}
