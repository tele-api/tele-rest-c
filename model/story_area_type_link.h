/*
 * story_area_type_link.h
 *
 * Describes a story area pointing to an HTTP or tg:// link. Currently, a story can have up to 3 link areas.
 */

#ifndef _story_area_type_link_H_
#define _story_area_type_link_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct story_area_type_link_t story_area_type_link_t;




typedef struct story_area_type_link_t {
    char *type; // string
    char *url; // string

    int _library_owned; // Is the library responsible for freeing this object?
} story_area_type_link_t;

__attribute__((deprecated)) story_area_type_link_t *story_area_type_link_create(
    char *type,
    char *url
);

void story_area_type_link_free(story_area_type_link_t *story_area_type_link);

story_area_type_link_t *story_area_type_link_parseFromJSON(cJSON *story_area_type_linkJSON);

cJSON *story_area_type_link_convertToJSON(story_area_type_link_t *story_area_type_link);

#endif /* _story_area_type_link_H_ */

