
// 经典的八皇后问题
// 在1个MAX*MAX的棋盘上，放置MAX个皇后，每个皇后都不能攻击其它皇后
//这个问题，可以用回溯的思想来解决
//把皇后放在某一行的第一列，然后检查它是否可以攻击其它的皇后
//如果互相攻击，就放在该行的第2列进行检查，如果每列都存在互相攻击，就返回
//如果皇后可以放在某个位置，函数就应该递归的调用自己，把1个皇后放在下一行
//当递归调用返回的时候，函数再把原来的那个皇后移动到下一列
//当一个皇后成功的放在最后一行的时候，函数应该打印出整个棋盘，显示MAX个皇后的位置

// 不考虑棋盘的对称性，一共有92种
#include <stdio.h>
#include <assert.h>

#define TRUE 1
#define FALSE 0
#define MAX 8

//这里演示了二维数组的传递参数的方法，仔细体会
void print_arr(int  (*arr)[]);

void clean_arr(int (*arr)[MAX]) {

    for(int i=0;i<MAX;++i) {
        for(int j=0;j<MAX;++j) {
            arr[i][j] = 0;
        }
    }
}

int check_token(int (*arr)[MAX], int pos_x, int pos_y) {
    //界外了，就返回没有占用，可以降低编程难度
    if(pos_x < 0 || pos_x >= MAX || pos_y < 0 || pos_y >= MAX)
        return FALSE;
    return arr[pos_x][pos_y] == 1 ? TRUE : FALSE;
}

int check(int (*arr)[MAX], int pos_x, int pos_y) {

    int step = 0;
    for (int j = 0; j < MAX; ++j) {
        //判断这一列是否有皇后
        if(j == pos_x) continue;
        if (check_token(arr, j, pos_y) == TRUE) {
            return FALSE;
        }
    }
    //判断斜线是否有皇后
    for(int k = 1 ;k < MAX ;k++) {
        if(check_token(arr,pos_x + k, pos_y + k) == TRUE ||
           check_token(arr,pos_x - k, pos_y - k) == TRUE ||
           check_token(arr,pos_x - k, pos_y + k) == TRUE ||
           check_token(arr,pos_x + k, pos_y - k) == TRUE) {
           return FALSE;
        }
    }
    return TRUE;
}

void print_arr(int (*arr)[MAX]) {

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    //printf("\n");
}

static int sum = 0;

//好好体会这种回溯方法的思想
//用递归一条道走到黑，不行回来之后，从原来的位置继续走
void backtracking(int (*arr)[MAX], int x) {

    if(x == MAX) {
        print_arr(arr);
        printf("---------------------------------\n");
        sum++;
        return;
    }
    for(int y = 0; y < MAX; y++) {

        if(check(arr, x, y) == TRUE) {

            arr[x][y] = 1;
            backtracking(arr,x + 1);
            //清0 ，以免出现脏数据
            arr[x][y] = 0;
        }
    }
}

//backtracking.c
int main() {

    int arr[MAX][MAX] = {
            {0},
            {0},
            {0},
            {0},
            {0},
            {0},
            {0},
            {0}
    };
    backtracking(arr, 0);
    printf("the end ! total:%d \n",sum);
}

