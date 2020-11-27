//
// Created by doubleKing on 2020/11/23.
//
//867. 转置矩阵
//https://leetcode-cn.com/problems/transpose-matrix/
//给定一个矩阵 A， 返回 A 的转置矩阵。
//
//矩阵的转置是指将矩阵的主对角线翻转，交换矩阵的行索引与列索引。
//
// 
//
//示例 1：
//
//输入：[[1,2,3],[4,5,6],[7,8,9]]
//输出：[[1,4,7],[2,5,8],[3,6,9]]
//示例 2：
//
//输入：[[1,2,3],[4,5,6]]
//输出：[[1,4],[2,5],[3,6]]
// 
//
//提示：
//
//1 <= A.length <= 1000
//1 <= A[0].length <= 1000
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/transpose-matrix
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
//这种变量的2维数组，要多联系

// *returnSize 和 **returnColumnSizes 是为了调用方，能够拿到这2个值，所以传得指针。服了，这么搞
int **transpose(int **A, int ASize, int *AColSize, int *returnSize, int **returnColumnSizes) {

    //好好学习下这个转置
    int **res;
    //注意这种申请指针得指针得用法
    res = (int **) malloc(sizeof(int *) * (*AColSize));
    for (int i = 0; i < *AColSize; ++i) {
        //先申请空间
        res[i] = (int *) malloc(sizeof(int) * ASize);
    }

    for (int i = 0; i < ASize; i++) {
        for (int j = 0; j < *AColSize; j++) {
            //执行真正得转置代码
            res[j][i] = A[i][j];
        }
    }

    //赋值2个返回值
    *returnSize = *AColSize;
    //返回这个指针，这个指针存得是转置后，每个数组得长度
    *returnColumnSizes = (int *) malloc(sizeof(int) * *AColSize);

    //ASize是常量，所以这个数组，是1个常量数组
    for (int i = 0; i < *AColSize; i++) {
        (*returnColumnSizes)[i] = ASize;
    }

    return res;
}

