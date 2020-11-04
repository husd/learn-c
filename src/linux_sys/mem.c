#include <stdio.h>
#include <stdlib.h>

typedef struct person {
    char *name;
    int age;
} person;

int main() {

    //内存
    //结构体
   person *p1;
   p1 = malloc(sizeof(struct person));
   if(p1 == NULL) {
       perror("malloc error \n");
       return 1;
   }
   p1->name = "this is name";
   p1->age = 10;
   printf("p is %d %s \n" ,p1->age,p1->name);
   //don't forget free
   free(p1);

   //数组
   int *arr;
   arr = malloc(sizeof(int) * 20);
   for(int i =0;i<20;i++) {
      arr[i] = i;
   }
    for(int i =0;i<20;i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}