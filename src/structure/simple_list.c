
#include <stdlib.h>
#include <stdio.h>

#define FALSE 0
#define TRUE 1

// 这个实现，是1个玩具类型的list，最主要的是不支持任意类型的节点
// 不存储tail 可用性有限
//多看看redis的adlist.h
typedef struct NODE {

    struct NODE *next;
    int val;
} NODE;

int list_insert(NODE *curr,int val) {
    NODE *new_node;
    while(curr->next != NULL) {
        curr = curr->next;
    }
    new_node = malloc(sizeof(NODE));
    if(new_node == NULL) {
        printf("out of mem \n");
        return FALSE;
    }
    new_node->val = val;
    new_node->next = NULL;
    //把新节点插入到tail
    curr-> next = new_node;
    return TRUE;
}

void list_print(NODE *head) {

    while(head != NULL) {
        printf("node is :%d \n" ,head->val);
        head = head->next;
    }
}

NODE *list_init(int val) {

    NODE *node;
    node = malloc(sizeof(NODE));
    if(node == NULL) {
        printf("out of mem \n");
        exit(1);
    }
    node->val = val;
    node->next = NULL;
    return node;
}

void list_clear(NODE *head) {

    if(head == NULL) return;
    NODE *curr = head;
    NODE *next;
    while(curr != NULL) {
        next = curr->next;
        printf("clear list node :%d \n",curr->val);
        free(curr);
        curr = next;
    }
    printf("clear end ,free head \n");
}

//返回指定值的index，没有就返回-1
NODE  *list_remove(NODE *head,NODE *entry) {

    // the indirect pointer points to the
    //*address* of the thing we will update
    //我们要找到我们需要更新的节点，然后更新它
    NODE **indirect = &head;

    //walk the list,looking for the thing that
    //points to the entry we want to remove
    while((*indirect) != entry) {
        indirect = &((*indirect)->next);
    }

    // .. and just remove it
    *indirect = entry->next;
    //free memory 刚开始写的是free(*indirect) 看起来没问题
    //实际上报错了，而且，entry是要删除的节点，直接释放它的空间就好了
    //为啥要干别的呢
    free(entry);
    return head;
}

int main() {

    NODE *head = list_init(10);
    list_insert(head,1);
    list_insert(head,2);
    list_insert(head,3);
    list_insert(head,4);
    if(head == NULL) {
        printf("list init false \n");
        exit(1);
    }
    list_print(head);
    printf("now remove the head node \n");
    head = list_remove(head,head->next);
    list_print(head);
    printf("head has been cleared \n");
    list_clear(head);
    //此时不能再free(head)了，因为head已经被释放了
    head = NULL;
    printf("the end head has been cleared \n");
    return 0;
}