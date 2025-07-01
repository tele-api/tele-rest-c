/*
 * story_area_type.h
 *
 * Describes the type of a clickable area on a story. Currently, it can be one of  * [StoryAreaTypeLocation](https://core.telegram.org/bots/api/#storyareatypelocation) * [StoryAreaTypeSuggestedReaction](https://core.telegram.org/bots/api/#storyareatypesuggestedreaction) * [StoryAreaTypeLink](https://core.telegram.org/bots/api/#storyareatypelink) * [StoryAreaTypeWeather](https://core.telegram.org/bots/api/#storyareatypeweather) * [StoryAreaTypeUniqueGift](https://core.telegram.org/bots/api/#storyareatypeuniquegift)
 */

#ifndef _story_area_type_H_
#define _story_area_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct story_area_type_t story_area_type_t;

#include "location_address.h"
#include "reaction_type.h"
#include "story_area_type_link.h"
#include "story_area_type_location.h"
#include "story_area_type_suggested_reaction.h"
#include "story_area_type_unique_gift.h"
#include "story_area_type_weather.h"



typedef struct story_area_type_t {
    char *type; // string
    double latitude; //numeric
    double longitude; //numeric
    struct reaction_type_t *reaction_type; //model
    char *url; // string
    double temperature; //numeric
    char *emoji; // string
    int background_color; //numeric
    char *name; // string
    struct location_address_t *address; //model
    int is_dark; //boolean
    int is_flipped; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} story_area_type_t;

__attribute__((deprecated)) story_area_type_t *story_area_type_create(
    char *type,
    double latitude,
    double longitude,
    reaction_type_t *reaction_type,
    char *url,
    double temperature,
    char *emoji,
    int background_color,
    char *name,
    location_address_t *address,
    int is_dark,
    int is_flipped
);

void story_area_type_free(story_area_type_t *story_area_type);

story_area_type_t *story_area_type_parseFromJSON(cJSON *story_area_typeJSON);

cJSON *story_area_type_convertToJSON(story_area_type_t *story_area_type);

#endif /* _story_area_type_H_ */

