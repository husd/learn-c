//
// Created by 胡胜冬 on 2020/12/4.
//
// 这个方法想解析MYSQL的DDL语句，自动创建对应的Java实体类，和insert语句

#include <stdio.h>
#include <string.h>

#define DEBUG 1

typedef struct ddl_column {

    char *col_name;             /* 列的名字 */
    char *col_type;             /* 列的类型，例如 bigint(20) varchar(10) */
    char *col_comment;          /* 备注 */
} ddl_column;

typedef struct ddl {

    char *t_name;       /* 表名字 */
    ddl_column **cols;  /* 所有的列 */
} ddl;

int main(int argc, char *argv[])
{
    if (DEBUG) {
        printf("argc is %d \n", argc);
    }
    if (argc <= 1) {
        printf("处理失败，请输入文件参数的名称 \n");
        return 0;
    }
    char *f_name = argv[1];
    printf("开始处理文件 %s \n", f_name);

    FILE *fp = fopen(f_name, "r");
    if (!fp) {
        printf("处理失败，文件 %s 不存在或者打开文件失败 \n", f_name);
        return 0;
    }

    printf("处理文件 成功 %s \n", f_name);
    return 0;
}

