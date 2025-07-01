/*
 * reaction_type_custom_emoji.h
 *
 * The reaction is based on a custom emoji.
 */

#ifndef _reaction_type_custom_emoji_H_
#define _reaction_type_custom_emoji_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct reaction_type_custom_emoji_t reaction_type_custom_emoji_t;




typedef struct reaction_type_custom_emoji_t {
    char *type; // string
    char *custom_emoji_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} reaction_type_custom_emoji_t;

__attribute__((deprecated)) reaction_type_custom_emoji_t *reaction_type_custom_emoji_create(
    char *type,
    char *custom_emoji_id
);

void reaction_type_custom_emoji_free(reaction_type_custom_emoji_t *reaction_type_custom_emoji);

reaction_type_custom_emoji_t *reaction_type_custom_emoji_parseFromJSON(cJSON *reaction_type_custom_emojiJSON);

cJSON *reaction_type_custom_emoji_convertToJSON(reaction_type_custom_emoji_t *reaction_type_custom_emoji);

#endif /* _reaction_type_custom_emoji_H_ */

