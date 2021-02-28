#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <hiredis/hiredis.h>

//gcc conn_redis_demo.c -lhiredis
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
    printf("reply-str is %s\n", reply->str);
    printf("reply->dval is %f\n", reply->dval);
    printf("reply->elements is %zu\n", reply->elements);
    printf("reply-integer is %l\n", reply->integer);
    printf("reply-len is %zu\n", reply->len);
    printf("reply-type is %d\n", reply->type);
    printf("reply-vtype is %s\n", reply->vtype);
    printf("------------------------------\n");

    freeReplyObject(reply);

    /* PING server */
    reply = redisCommand(context, "PING");
    printf("PING: %s\n", reply->str);
    freeReplyObject(reply);

    /* Set a key */
    reply = redisCommand(context, "SET %s %s", "foo", "hello world");
    printf("SET: %s\n", reply->str);
    freeReplyObject(reply);

    /* Set a key using binary safe API */
    reply = redisCommand(context, "SET %b %b", "bar", (size_t) 3, "hello", (size_t) 5);
    printf("SET (binary API): %s\n", reply->str);
    freeReplyObject(reply);

    /* Try a GET and two INCR */
    reply = redisCommand(context, "GET foo");
    printf("GET foo: %s\n", reply->str);
    freeReplyObject(reply);

    reply = redisCommand(context, "INCR counter");
    printf("INCR counter: %lld\n", reply->integer);
    freeReplyObject(reply);
    /* again ... */
    reply = redisCommand(context, "INCR counter");
    printf("INCR counter: %lld\n", reply->integer);
    freeReplyObject(reply);

    /* Create a list of numbers, from 0 to 9 */
    reply = redisCommand(context, "DEL mylist");
    freeReplyObject(reply);
    for (int j = 0; j < 10; j++) {
        char buf[64];

        snprintf(buf, 64, "%u", j);
        reply = redisCommand(context, "LPUSH mylist element-%s", buf);
        freeReplyObject(reply);
    }

    /* Let's check what we have inside the list */
    reply = redisCommand(context, "LRANGE mylist 0 -1");
    if (reply->type == REDIS_REPLY_ARRAY) {
        for (int j = 0; j < reply->elements; j++) {
            printf("%u) %s\n", j, reply->element[j]->str);
        }
    }
    freeReplyObject(reply);
    
    //freeReplyObject(reply);

    char *map_key = "husd:map";
    char *map_field = "name";
    char *map_val = "husd";
    reply = redisCommand(context, "HSET %s %s %s", map_key, map_field, map_val);
    printf("HSET :%s\n", reply->str);
    freeReplyObject(reply);

    map_field = "name2";
    map_val = "husd2";
    reply = redisCommand(context, "HSET %s %s %s", map_key, map_field, map_val);
    printf("HSET :%s\n", reply->str);
    freeReplyObject(reply);

    reply = redisCommand(context, "HGET %s %s", map_key, map_field);
    printf("HGET :%s\n", reply->str);
    freeReplyObject(reply);

    redisFree(context);

    return 0;
}
