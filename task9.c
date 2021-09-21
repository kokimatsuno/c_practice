#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 3
pthread_t tid[NUM_THREADS];
pthread_mutex_t mutex;

int k = 20;

void *func_a(){
  pthread_mutex_lock(&mutex);
  auto int a = 10;
  static int b = 5;
  pthread_t thread_num = pthread_self();
  int thread_id;
  for(int i=0; i < NUM_THREADS; i++){
    if(pthread_equal(thread_num, tid[i]) != 0){
      thread_id = i;
      break;
    }
  }
   printf("thread_id = %d\n", thread_id);
  printf("auto int a = %d, &a = %p\n",a, &a);
  printf("static b = %d, &b = %p\n",b, &b);
  printf("global k = %d, &k = %p\n\n", k, &k);
  pthread_mutex_unlock(&mutex);
  return NULL;
}

int main(){
pthread_mutex_init(&mutex, NULL);

  int a = 20;
  for (int i = 0; i <NUM_THREADS; i++){
  pthread_create(&tid[i], NULL, func_a, NULL);
}
for(int i = 0; i< NUM_THREADS; i++){
  pthread_join(tid[i], NULL);
}

}
