
//一种特殊的set数据结构,由多个整型元素组成。intset也是一个有序整型集合，其内部设计非常精巧
#ifndef __INTSET_H
#define __INTSET_H
#include <stdint.h>

typedef struct intset {
    uint32_t encoding; // 有3中 INTSET_ENC_INT16 < INTSET_ENC_INT32 < INTSET_ENC_INT64
    //这样可以在数字小的时候，尽量的节省空间
    uint32_t length; //集合元素大小,时间复杂度由O(n)->O(1)
    int8_t contents[]; //元素数组
} intset;

intset *intsetNew(void);
intset *intsetAdd(intset *is, int64_t value, uint8_t *success);
intset *intsetRemove(intset *is, int64_t value, int *success);
uint8_t intsetFind(intset *is, int64_t value);
int64_t intsetRandom(intset *is);
uint8_t intsetGet(intset *is, uint32_t pos, int64_t *value);
uint32_t intsetLen(const intset *is);
size_t intsetBlobLen(intset *is);

#ifdef REDIS_TEST
int intsetTest(int argc, char *argv[]);
#endif

#endif // __INTSET_H
