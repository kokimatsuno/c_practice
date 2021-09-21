//task8.c
//学籍番号：71907528
//氏名：松野　光希

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS 10
#define NUM_DATA 1000000

unsigned long data[NUM_DATA][3];    //dataを入れる配列
unsigned long sum = 0;

pthread_t tid[NUM_THREADS];
pthread_mutex_t mutex;

void *do_sum(void *arg);    //宣言


//メイン関数
int main(){
  pthread_mutex_init(&mutex, NULL);   //mutexの初期化
  long i;
  long sum_num=0;     //各スレッドがsumに足した回数

//dataの初期化
  for (i=0; i<NUM_DATA; i++){
    data[i][0] = 0;
    data[i][1] = i;
    data[i][2] = NUM_THREADS;
  }


//threadの生成と実行
  for (i = 0; i < NUM_THREADS; i++){
    pthread_create(&tid[i], NULL, do_sum, 0);
  }
  for (i = 0; i < NUM_THREADS; i++){
    pthread_join(tid[i], NULL);
  }

  printf("sum=%lu\n", sum);
  //スレッドごとにsumに足した回数を求める。
  for(i = 0; i < NUM_THREADS; i++){
    sum_num = 0;
    for(long j = 0; j< NUM_DATA; j++){
      if(data[j][2] == i){
        sum_num++ ;
      }
    }
    printf("thread %ld : %ld\n", i, sum_num);
  }

pthread_mutex_destroy(&mutex);
  return 0;
}


//合計を出す関数
void *do_sum(void *arg){
pthread_t thread_num;
int thread_id;
//thread_num : スレッド番号
//thread_id : スレッドid

  for (long i = 0; i<NUM_DATA; i++){
    pthread_mutex_lock(&mutex);
    if(data[i][0] == 0){
      sum += data[i][1];
      data[i][0] = 1;
  //thread番号からthread idを求める
      thread_num = pthread_self();
      for(int i = 0; i < NUM_THREADS; i++){
        if(tid[i] == thread_num){
          thread_id = i;
          break;
        }
      }
      data[i][2] = thread_id;
    }
    pthread_mutex_unlock(&mutex);
  }

  return NULL;
}
