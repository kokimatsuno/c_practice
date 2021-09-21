//学籍番号：71907528
//氏名：松野光希
//初めにゲームを始めるか聞き、くじをするか、じゃんけんをするかを順に聞き、点数を獲得していき、10点獲得したら、終了
//くじ：0~4点獲得、じゃんけん：勝ち→2点　アイコ→１点、まけ→0点
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NODE_0 0
#define NODE_1 1
#define NODE_2 2
#define NODE_3 3
#define NODE_END 4

void lottery(void);     //くじをする関数
void jan(void);         //じゃんけんをする関数
void no_func(void);     //何もしない関数
int sum = 0;            //獲得合計点

struct fsm_trans{
  int node;               //現在のノード
  int yes;                //yesを選択した時の次のノード
  int no;                 //noを選択した時の次のノード
  void (*func)(void);     //yesを選択したときに動かす関数
  char message[100];
};

struct fsm_trans fsmtable[] = {
  {NODE_0, NODE_1, NODE_END, no_func, "10点獲得したら完了です。\nゲームをはじめますか？(y/n)"},
  {NODE_1, NODE_2, NODE_3, lottery, "くじをしますか？(y/n)"},
  {NODE_2, NODE_1, NODE_3, jan, "じゃんけんをしますか？(y/n)"},
  {NODE_3, NODE_2, NODE_END, no_func, "ゲームを続けますか？(y/n)"},
  {NODE_END, NODE_0, NODE_END, no_func, ""}
};

int main(){
  int state=0;
  char input[256], *p;

  while(sum < 10){          //合計点が10点未満である限り続ける
    if(fsmtable[state].node == NODE_END){
      break;
    }
  //出題・y or nの入力
    printf("問題：%s\n", fsmtable[state].message);
    p = fgets(input, 255, stdin);
    if(p != NULL){
      if(input[0] == 'y'){
        fsmtable[state].func();
        state = fsmtable[state].yes;
      }else if(input[0] == 'n'){
        state = fsmtable[state].no;
      }else{
        printf("不正な文字が入力されたため終了します\n");
        break;
      }
    }
  }
  printf("ゲームを終了します\n");
  return 0;
}

void lottery(){
  int num=0;
  num = random() % 5;       //ランダムで0~4点がでる
  sum += num;
  printf("%d点です。\n合計は%d点です。\n", num, sum);
  return;
}

void jan(){
  char a[255];        //入力されたじゃんけんの手を格納
  char *p = NULL;     //fgetsの返り値を格納
  while(p == NULL){
    printf("じゃんけんの手(gu/choki/pa)：");
    p = fgets(a, 255, stdin);
    sscanf(a, "%s", a);
}
  if(strcmp(a, "gu") == 0){
    printf("相手はチョキを出しました。\nあなたの勝ちです。\n3点獲得!\n");
    sum += 3;
    printf("現在の合計点は%d点です。", sum);
    return;
  }else if(strcmp(a, "choki") == 0){
    printf("相手はチョキを出しました。\n1点獲得!\n");
    sum += 1;
    printf("現在の合計点は%d点です。", sum);
    return;
  }else if(strcmp(a, "pa") == 0){
    printf("相手はチョキを出しました。\n負けです。点数獲得ならず.\n");
    printf("現在の合計点は%dです。", sum);
    return;
  }else{
    printf("不正な文字です");
    exit(1);
  }
}

void no_func() { ;}
