/*
 * story_area_type_unique_gift.h
 *
 * Describes a story area pointing to a unique gift. Currently, a story can have at most 1 unique gift area.
 */

#ifndef _story_area_type_unique_gift_H_
#define _story_area_type_unique_gift_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct story_area_type_unique_gift_t story_area_type_unique_gift_t;




typedef struct story_area_type_unique_gift_t {
    char *type; // string
    char *name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} story_area_type_unique_gift_t;

__attribute__((deprecated)) story_area_type_unique_gift_t *story_area_type_unique_gift_create(
    char *type,
    char *name
);

void story_area_type_unique_gift_free(story_area_type_unique_gift_t *story_area_type_unique_gift);

story_area_type_unique_gift_t *story_area_type_unique_gift_parseFromJSON(cJSON *story_area_type_unique_giftJSON);

cJSON *story_area_type_unique_gift_convertToJSON(story_area_type_unique_gift_t *story_area_type_unique_gift);

#endif /* _story_area_type_unique_gift_H_ */

