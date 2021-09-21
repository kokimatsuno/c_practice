

//refer to https://daeudaeu.com/programming/c-language/list-structure/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 会員情報を登録する構造体 */

struct LIST{
  unsigned int number;
  char name[256];
  struct LIST *next;
} ;

/* 会員情報を全て表示する関数 */
int displayList(struct LIST *list){
  while(list != NULL){
    printf("%d:%s\n", list->number, list->name);
    list = list->next;
  }
  return 0;
}

/* 会員情報を全て削除する関数 */
struct LIST* deleteAllList(struct LIST *list){
  struct LIST *tmp;

  while(list != NULL){
    tmp = list->next;
    free(list);
    list = tmp;
  }

  return NULL;
}


/* 会員情報をリストの最後に追加し、リストの先頭アドレスを返却する関数 */
struct LIST* addList(struct LIST *list, char *name, unsigned int number){
  struct LIST *item;
  struct LIST *top;

  top = list;

  item = (struct LIST*)malloc(sizeof(struct LIST));
  item->number = number;
  strcpy(item->name, name);
  item->next = NULL;


  /* リストが空の場合は先頭に追加して終了 */
  if(list == NULL){
    list = item;
    return list;
  }

  /* リストのnextを辿ってリストの最後を探す */
  /* リストの最後とは、nextがNULLの要素 */
  while(list->next != NULL){
    list = list->next;
  }
  list->next = item;

  /* ここでreturnする場合は先頭アドレスは変わらない */
  return top;
}

/* 会員情報を削除し、リストの先頭アドレスを返却する関数 */
struct LIST* deleteList(struct LIST *list, unsigned int number){
  struct LIST *tmp;
  struct LIST *top;
  top = list;

  /* 先頭ノードの場合だけ別処理 */
  if(list != NULL && list->number == number){
    tmp = list->next;
    free(list);

    /* 次の要素のアドレスをリストの先頭アドレスとして返却 */
    return tmp;
  }

  /* リストを辿って指定された会員番号の要素を探す */
  while(list != NULL && list-> next != NULL){
    if(list->next->number == number){
      tmp = list->next->next;
      free(list->next);
      list->next = tmp;
      return top;
    }
    list = list->next;
  }
  printf("Number %d not found!\n", number);

  return top;
}

int main(void){
  int operation;
  unsigned int inputnumber = 1;
  unsigned int number = 1;
  char inputname[256];

  struct LIST *list = NULL;

  /* 会員登録情報に対する操作 */
  while(1){
    printf("operation(1:add, 2:delete, etc:exit) = ");
    scanf("%d", &operation);

    if(operation == 1){
      /* 1が入力されれば必要な情報を取得してリストに追加 */
      printf("add name = ");
      scanf("%s", inputname);

      list = addList(list, inputname, number);
      number++;
    } else if(operation == 2){
      /* 2が入力されれば必要な情報を取得してリストから削除 */
      if(list == NULL){
        printf("list is empty\n");
      } else {
        printf("delete number = ");
        scanf("%d", &inputnumber);
        list = deleteList(list, inputnumber);
      }

    } else {
      /* それ以外はwhileを抜ける */
      break;
    }

    displayList(list);

  }

  list = deleteAllList(list);

  return 0;
}
