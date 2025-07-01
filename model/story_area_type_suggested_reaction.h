/*
 * story_area_type_suggested_reaction.h
 *
 * Describes a story area pointing to a suggested reaction. Currently, a story can have up to 5 suggested reaction areas.
 */

#ifndef _story_area_type_suggested_reaction_H_
#define _story_area_type_suggested_reaction_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct story_area_type_suggested_reaction_t story_area_type_suggested_reaction_t;

#include "reaction_type.h"



typedef struct story_area_type_suggested_reaction_t {
    char *type; // string
    struct reaction_type_t *reaction_type; //model
    int is_dark; //boolean
    int is_flipped; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} story_area_type_suggested_reaction_t;

__attribute__((deprecated)) story_area_type_suggested_reaction_t *story_area_type_suggested_reaction_create(
    char *type,
    reaction_type_t *reaction_type,
    int is_dark,
    int is_flipped
);

void story_area_type_suggested_reaction_free(story_area_type_suggested_reaction_t *story_area_type_suggested_reaction);

story_area_type_suggested_reaction_t *story_area_type_suggested_reaction_parseFromJSON(cJSON *story_area_type_suggested_reactionJSON);

cJSON *story_area_type_suggested_reaction_convertToJSON(story_area_type_suggested_reaction_t *story_area_type_suggested_reaction);

#endif /* _story_area_type_suggested_reaction_H_ */

