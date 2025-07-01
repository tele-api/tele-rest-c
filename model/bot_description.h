/*
 * bot_description.h
 *
 * This object represents the bot&#39;s description.
 */

#ifndef _bot_description_H_
#define _bot_description_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct bot_description_t bot_description_t;




typedef struct bot_description_t {
    char *description; // string

    int _library_owned; // Is the library responsible for freeing this object?
} bot_description_t;

__attribute__((deprecated)) bot_description_t *bot_description_create(
    char *description
);

void bot_description_free(bot_description_t *bot_description);

bot_description_t *bot_description_parseFromJSON(cJSON *bot_descriptionJSON);

cJSON *bot_description_convertToJSON(bot_description_t *bot_description);

#endif /* _bot_description_H_ */

