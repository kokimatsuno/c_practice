//list構造を用いた入力単語の表示


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 8


struct LIST{
  int number;
  char word[MAXLINE];
  struct LIST *next;
};

int displayList(struct LIST *list){
  while(list != NULL){
    printf("%d:%s\n", list->number, list->word);
    list = list->next;
  }
  return 0;
}


struct LIST* AddList(struct LIST *list, char *word, int number){
  struct LIST *item;
  struct LIST *top;

  top = list;

//入力された単語を新たな領域に記憶させる。
  item = malloc(sizeof(struct LIST));
  item->number = number;
  strcpy(item->word, word);
  item->next = NULL;

//リストがからの場合
  if(list == NULL){
    list = item;
    return list;
  }

//すでに持っているリストの最後に新たなLIST構造体を付け加える
  while(list->next != NULL){
    list = list->next;
  }
  list->next = item;

//リストの先頭のポインタを返す
  return top;
}


int main(){
  char operation[MAXLINE];
  char inputword[MAXLINE], *s;
  struct LIST *list = NULL;
  int number = 0;

  while(1){
  //追加単語の入力
    printf("add word:");
    s = fgets(inputword, MAXLINE, stdin);
    if(s == NULL){
      printf("fishich or Error");
      break;
    }
    s = index(inputword, '\n');
    if(s != NULL){
      *s = '\0';
    }else{
      while(getchar() != '\n');
    }
  //リスト構造を用いた単語追加
    list = AddList(list, inputword, number);
    number++;

  }

//単語追加終了後に全リスト表示

  printf("\n\nYou're input word list is following.\n");
  displayList(list);
}
