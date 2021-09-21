/* kadai6.c */
// 課題No6(6月4日の課題)プログラム例
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

// 一度に読み書きするバイト数
// コンピューターの仕組み上、大きいほうがよい
// 通常は 8192 程度
// stdio.h に #define BUFSIZ 8192 という似た目的で使う定義があるので、それを流用する場合もある
#define CSIZE 8192

int main(int argc, char *argv[]){
  char buf[CSIZE];
  int fd;
  ssize_t rcc, wcc;
  // コマンド行引数があったら、そのファイルをオープンする
  // コマンド行引数がなかったら、標準入力から読み込む
  if(argc > 1){
    fd = open(argv[1],O_RDONLY);
    if(fd == -1){
      fprintf(stderr,"open() failed, ");
      perror(argv[1]);
      exit(1);
    }
  }else{
    fd = 0;
    // あるいは、fd = STDIN_FILENO;
    // STDIN_FILENO は unistd.hで定義されている標準入力のファイル識別子の値
  }
  //
  // displayfile.c からの変更部分
  // 複数回読み込むための繰り返し
  for(;;){
    rcc = read(fd,buf,CSIZE);
    if(rcc > 0){
      wcc = write(1,buf,rcc);
      // あるいは、wcc = write(STDOUT_FILENO,buf,rcc);
      if(wcc == -1){
        perror("write");
        exit(1);
      }
    // ファイル終了でrccに0が入る
    // エラーのときは-1が入る
    }else{
      break;
    }
  } // for(;;)の終わり
  exit(0);
}

