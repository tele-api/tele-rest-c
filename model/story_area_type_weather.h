/*
 * story_area_type_weather.h
 *
 * Describes a story area containing weather information. Currently, a story can have up to 3 weather areas.
 */

#ifndef _story_area_type_weather_H_
#define _story_area_type_weather_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct story_area_type_weather_t story_area_type_weather_t;




typedef struct story_area_type_weather_t {
    char *type; // string
    double temperature; //numeric
    char *emoji; // string
    int background_color; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} story_area_type_weather_t;

__attribute__((deprecated)) story_area_type_weather_t *story_area_type_weather_create(
    char *type,
    double temperature,
    char *emoji,
    int background_color
);

void story_area_type_weather_free(story_area_type_weather_t *story_area_type_weather);

story_area_type_weather_t *story_area_type_weather_parseFromJSON(cJSON *story_area_type_weatherJSON);

cJSON *story_area_type_weather_convertToJSON(story_area_type_weather_t *story_area_type_weather);

#endif /* _story_area_type_weather_H_ */

