/*
 * story_area.h
 *
 * Describes a clickable area on a story media.
 */

#ifndef _story_area_H_
#define _story_area_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct story_area_t story_area_t;

#include "story_area_position.h"
#include "story_area_type.h"



typedef struct story_area_t {
    struct story_area_position_t *position; //model
    struct story_area_type_t *type; //model

    int _library_owned; // Is the library responsible for freeing this object?
} story_area_t;

__attribute__((deprecated)) story_area_t *story_area_create(
    story_area_position_t *position,
    story_area_type_t *type
);

void story_area_free(story_area_t *story_area);

story_area_t *story_area_parseFromJSON(cJSON *story_areaJSON);

cJSON *story_area_convertToJSON(story_area_t *story_area);

#endif /* _story_area_H_ */

