/*
 * story_area_position.h
 *
 * Describes the position of a clickable area within a story.
 */

#ifndef _story_area_position_H_
#define _story_area_position_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct story_area_position_t story_area_position_t;




typedef struct story_area_position_t {
    double x_percentage; //numeric
    double y_percentage; //numeric
    double width_percentage; //numeric
    double height_percentage; //numeric
    double rotation_angle; //numeric
    double corner_radius_percentage; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} story_area_position_t;

__attribute__((deprecated)) story_area_position_t *story_area_position_create(
    double x_percentage,
    double y_percentage,
    double width_percentage,
    double height_percentage,
    double rotation_angle,
    double corner_radius_percentage
);

void story_area_position_free(story_area_position_t *story_area_position);

story_area_position_t *story_area_position_parseFromJSON(cJSON *story_area_positionJSON);

cJSON *story_area_position_convertToJSON(story_area_position_t *story_area_position);

#endif /* _story_area_position_H_ */

