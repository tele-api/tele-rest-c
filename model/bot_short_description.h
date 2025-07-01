/*
 * bot_short_description.h
 *
 * This object represents the bot&#39;s short description.
 */

#ifndef _bot_short_description_H_
#define _bot_short_description_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct bot_short_description_t bot_short_description_t;




typedef struct bot_short_description_t {
    char *short_description; // string

    int _library_owned; // Is the library responsible for freeing this object?
} bot_short_description_t;

__attribute__((deprecated)) bot_short_description_t *bot_short_description_create(
    char *short_description
);

void bot_short_description_free(bot_short_description_t *bot_short_description);

bot_short_description_t *bot_short_description_parseFromJSON(cJSON *bot_short_descriptionJSON);

cJSON *bot_short_description_convertToJSON(bot_short_description_t *bot_short_description);

#endif /* _bot_short_description_H_ */

