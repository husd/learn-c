#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <hiredis/hiredis.h>

int main()
{

    redisContext *context = redisConnect("127.0.0.1", 6379);
    if (context == NULL || context->err) {
        if (context) {
            printf("Error: %s\n", context->errstr);
            // handle error
        } else {
            printf("Can't allocate redis context\n");
        }
        return 1;
    }
    //Note: A redisContext is not thread-safe.
    redisReply *reply;
    reply = redisCommand(context, "SET foo bar");
    printf("------------------------------\n");
    printf("reply-str is %s\n",reply->str);
    printf("reply->dval is %f\n",reply->dval);
    printf("reply->elements is %zu\n",reply->elements);
    printf("reply-integer is %l\n",reply->integer);
    printf("reply-len is %zu\n",reply->len);
    printf("reply-type is %d\n",reply->type);
    printf("reply-vtype is %s\n",reply->vtype);
    printf("------------------------------\n");

    freeReplyObject(reply);

    redisFree(context);
    return 0;
}
