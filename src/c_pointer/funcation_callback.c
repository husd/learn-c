//函数回调
//回调的格式是 ： int () 先这么写，表示返回值是int 后面紧跟着括号,再写括号里的值
// int (*func()) 表示1个指向函数的指针，再补充函数的参数
// int (*func(int,int)); 这样就清楚了，func是1个函数指针；
//指针

#include <stdio.h>
#include <string.h>

//定义链表的节点
typedef struct NODE {

    struct NODE *next;
    int val;
} NODE;

//注意体会C语言的值传递，所以不会修改原来的指针
//这个函数可以在链表中寻找1个值，但是如果链表是1个字符串类型的，怎么办呢？
//java有范型
//可以使查找和类型无关
NODE *list_search(NODE *head,int const val) {

    while(head != NULL) {
        if(head->val == val) {
            break;
        } else {
            head = head->next;
        }
    }
    return head;
}

//函数回调版本的代码
NODE *list_search_callback(NODE *head,int const val,
        int (*compare(void const *,void const *))) {

    while(head != NULL) {
        if(compare(&head.val,val) == 0) {
            break;
        } else {
            head = head->next;
        }
    }
    return head;
}

int compare_int(void const *A,void const *B) {

    //这1步，是1个强制转换
    if( *(int *)A == *(int *)B ) {
        return 0;
    } else {
        return 1;
    }
}

//字符串的比较，可以用
int main() {

    //这段代码不能运行
    NODE *head;
    NODE *h;
    h = list_search(head,"abc",strcmp);
    return 0;
}

