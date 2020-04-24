#include <stdio.h>
/**
  * 计算机的大端和小端的判断方法
  *
  **/
int main() {

  int i=1;
  char c= *((char*)&i);
  if(c==1) {
    printf("small\n");
  } else {
    printf("big\n");
  }

}
