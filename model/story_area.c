#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "story_area.h"



static story_area_t *story_area_create_internal(
    story_area_position_t *position,
    story_area_type_t *type
    ) {
    story_area_t *story_area_local_var = malloc(sizeof(story_area_t));
    if (!story_area_local_var) {
        return NULL;
    }
    story_area_local_var->position = position;
    story_area_local_var->type = type;

    story_area_local_var->_library_owned = 1;
    return story_area_local_var;
}

__attribute__((deprecated)) story_area_t *story_area_create(
    story_area_position_t *position,
    story_area_type_t *type
    ) {
    return story_area_create_internal (
        position,
        type
        );
}

void story_area_free(story_area_t *story_area) {
    if(NULL == story_area){
        return ;
    }
    if(story_area->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "story_area_free");
        return ;
    }
    listEntry_t *listEntry;
    if (story_area->position) {
        story_area_position_free(story_area->position);
        story_area->position = NULL;
    }
    if (story_area->type) {
        story_area_type_free(story_area->type);
        story_area->type = NULL;
    }
    free(story_area);
}

cJSON *story_area_convertToJSON(story_area_t *story_area) {
    cJSON *item = cJSON_CreateObject();

    // story_area->position
    if (!story_area->position) {
        goto fail;
    }
    cJSON *position_local_JSON = story_area_position_convertToJSON(story_area->position);
    if(position_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "position", position_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // story_area->type
    if (!story_area->type) {
        goto fail;
    }
    cJSON *type_local_JSON = story_area_type_convertToJSON(story_area->type);
    if(type_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "type", type_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

story_area_t *story_area_parseFromJSON(cJSON *story_areaJSON){

    story_area_t *story_area_local_var = NULL;

    // define the local variable for story_area->position
    story_area_position_t *position_local_nonprim = NULL;

    // define the local variable for story_area->type
    story_area_type_t *type_local_nonprim = NULL;

    // story_area->position
    cJSON *position = cJSON_GetObjectItemCaseSensitive(story_areaJSON, "position");
    if (cJSON_IsNull(position)) {
        position = NULL;
    }
    if (!position) {
        goto end;
    }

    
    position_local_nonprim = story_area_position_parseFromJSON(position); //nonprimitive

    // story_area->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(story_areaJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    
    type_local_nonprim = story_area_type_parseFromJSON(type); //nonprimitive


    story_area_local_var = story_area_create_internal (
        position_local_nonprim,
        type_local_nonprim
        );

    return story_area_local_var;
end:
    if (position_local_nonprim) {
        story_area_position_free(position_local_nonprim);
        position_local_nonprim = NULL;
    }
    if (type_local_nonprim) {
        story_area_type_free(type_local_nonprim);
        type_local_nonprim = NULL;
    }
    return NULL;

}
