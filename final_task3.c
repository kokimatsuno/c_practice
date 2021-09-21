//氏名：松野光希
//学籍番号：71907528

#include <stdio.h>
#include <pthread.h>

#define MAX_NUM 100000
#define THREAD_NUM 5

pthread_t tid[THREAD_NUM];
pthread_mutex_t mutex;

//1つ目には、素数のとき1、素数でないときは0を格納
//2つ目には、調べたものには1を入れる。
_Bool check[MAX_NUM+1][2];

//素数かどうかをチェックする関数
void *num_check(void *arg){
  pthread_t thread_num;     //thread番号を格納

  for (int i = 3;i <= MAX_NUM; i++){
    pthread_mutex_lock(&mutex);         //LOCK
    thread_num = pthread_self();        //thread番号を取得
    for (int j = 2; j < i; j++){
  //すでに調べたもにに関してはとばす。
      if(check[i][1] ==1){
        break;
      }
//2~i-1でiを割ったときに割れる数があれば素数でないと判断
      if(i % j ==0){
        check[i][0] = 0;
        check[i][1] = 1;
        break;
      }
//最後まで割り切れる数がなければ、素数と判断
      else if(j+1 == i){
        check[i][0] = 1;
        check[i][1] = 1;
        break;
    }
    }
    pthread_mutex_unlock(&mutex);     //UNLOCK
  }
  return NULL;
}

int main(){
  pthread_mutex_init(&mutex, NULL);     //thread初期化

  for(int i; i<=MAX_NUM; i++){       //check配列の初期化
    check[i][0] = 0;
    check[i][1] = 0;
  }
//0~2は先にいれてしまう。
  check[0][0] = 0;
  check[0][1] = 1;
  check[1][0] = 0;
  check[1][1] = 1;
  check[2][0] = 1;
  check[2][1] = 1;

//thread生成
  for(int i = 0; i < THREAD_NUM; i++){
    pthread_create(&tid[i], NULL, num_check, 0);
  }
  for(int i = 0; i<THREAD_NUM; i++){
    pthread_join(tid[i], NULL);
  }

//素数を表示
  printf("\n素数：\n\n");
  for(int i = 0; i<=MAX_NUM; i++){
    if(check[i][0] == 1){
      printf("%d\n", i);
    }
  }
}
