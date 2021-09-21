
//refer to sfc-sfs.
//
//
/*getchar()による改行文字までの読み飛ばしをしないと次のような出力結果になります。
%./fgets-loop
012345678901234567890123456789
0123456
7890123
4567890
1234567
^C <-- (この段階で、まだ「89」が残っています。
%
読み飛ばすと次のようになります。
012345678901234567890123456789
0123456
abc
abc
*/

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#define MAXLEN 8

int main(){
  char input[MAXLEN], *s;

  for(;;){
    s = fgets(input, MAXLEN, stdin);
    if(s == NULL){
      break;
    }
    s = index(input, '\n');
    if(s != NULL){          //^Dをおしたら終了
      *s = '\0';
    }else{
      while(getchar()!='\n');   //標準入力のバッファを空にする。MAXLINE以上の文字が入力された時用
    }
    printf("%s\n", input);
  }
  exit(0);
}
