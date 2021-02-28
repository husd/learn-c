//三色旗的问题最早由 E.W.Dijkstra所提出，
// 他所使用的用语为 Dutch Nation Flag(Dijkstra为荷兰 人)，
// 而多数的作者则使用Three-Color Flag来称之。
//假设有一条绳子，上面有红、白、蓝三种颜色的旗子，
// 起初绳子上的旗子颜色并没有顺序，
// 您 希望将之分类，并排列为蓝、白、红的顺序，
// 要如何移动次数才会最少，注意您只能在绳子上
// 进行这个动作，而且一次只能调换两个旗子。
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLUE 'b'
#define WHITE 'w'
#define RED 'r'
#define SWAP(x, y) { char temp; \
                    temp = color[x]; \
                    color[x] = color[y]; \
                    color[y] = temp; }

int main()
{
    char color[] = {'r', 'w', 'b', 'w', 'w',
                    'b', 'r', 'b', 'w', 'r', '\0'};
    int wFlag = 0;
    int bFlag = 0;
    int rFlag = strlen(color) - 1;
    int i;
    for (i = 0; i < strlen(color); i++)
        printf("%c ", color[i]);
    printf("\n");
    while (wFlag <= rFlag) {
        if (color[wFlag] == WHITE)
            wFlag++;
        else if (color[wFlag] == BLUE) {
            SWAP(bFlag, wFlag);
            bFlag++;
            wFlag++;
        } else {
            while (wFlag < rFlag && color[rFlag] == RED)
                rFlag--;
            SWAP(rFlag, wFlag);
            rFlag--;
        }
    }
    for (i = 0; i < strlen(color); i++)
        printf("%c ", color[i]);
    printf("\n");
    return 0;
}