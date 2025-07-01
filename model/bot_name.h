/*
 * bot_name.h
 *
 * This object represents the bot&#39;s name.
 */

#ifndef _bot_name_H_
#define _bot_name_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct bot_name_t bot_name_t;




typedef struct bot_name_t {
    char *name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} bot_name_t;

__attribute__((deprecated)) bot_name_t *bot_name_create(
    char *name
);

void bot_name_free(bot_name_t *bot_name);

bot_name_t *bot_name_parseFromJSON(cJSON *bot_nameJSON);

cJSON *bot_name_convertToJSON(bot_name_t *bot_name);

#endif /* _bot_name_H_ */

