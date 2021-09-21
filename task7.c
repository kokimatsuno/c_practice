//task7.c
//学籍番号：71907528
//氏名：松野　光希

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS 5
#define NUM_DATA 10

unsigned long data[NUM_DATA][2];    //dataを入れる配列
unsigned long sum = 0;

pthread_t tid[NUM_THREADS];
pthread_mutex_t mutex;

void *do_sum(void *arg);    //宣言


//メイン関数
int main(){
  pthread_mutex_init(&mutex, NULL);   //mutexの初期化
  long i;

//dataの初期化
  for (i=0; i<NUM_DATA; i++){
    data[i][0] = 0;
    data[i][1] = i;
  }


//threadの生成と実行
  for (i = 0; i < NUM_THREADS; i++){
    pthread_create(&tid[i], NULL, do_sum, 0);
  }
  for (i = 0; i < NUM_THREADS; i++){
    pthread_join(tid[i], NULL);
  }

  printf("%lu\n", sum);

pthread_mutex_destroy(&mutex);
  return 0;
}


//合計を出す関数
void *do_sum(void *arg){
  for (long i = 0; i<NUM_DATA; i++){
    pthread_mutex_lock(&mutex);
    printf("Thread %ld:data[%lu][0] = %lu, data[%lu][1] = %lu\n",
           (long)pthread_self(), i, data[i][0], i, data[i][1]);
    if(data[i][0] == 0){
      sum += data[i][1];
      data[i][0] = 1;
    }
    pthread_mutex_unlock(&mutex);
  }

  return NULL;
}
