#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "set_sticker_position_in_set_request.h"



static set_sticker_position_in_set_request_t *set_sticker_position_in_set_request_create_internal(
    char *sticker,
    int position
    ) {
    set_sticker_position_in_set_request_t *set_sticker_position_in_set_request_local_var = malloc(sizeof(set_sticker_position_in_set_request_t));
    if (!set_sticker_position_in_set_request_local_var) {
        return NULL;
    }
    set_sticker_position_in_set_request_local_var->sticker = sticker;
    set_sticker_position_in_set_request_local_var->position = position;

    set_sticker_position_in_set_request_local_var->_library_owned = 1;
    return set_sticker_position_in_set_request_local_var;
}

__attribute__((deprecated)) set_sticker_position_in_set_request_t *set_sticker_position_in_set_request_create(
    char *sticker,
    int position
    ) {
    return set_sticker_position_in_set_request_create_internal (
        sticker,
        position
        );
}

void set_sticker_position_in_set_request_free(set_sticker_position_in_set_request_t *set_sticker_position_in_set_request) {
    if(NULL == set_sticker_position_in_set_request){
        return ;
    }
    if(set_sticker_position_in_set_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "set_sticker_position_in_set_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (set_sticker_position_in_set_request->sticker) {
        free(set_sticker_position_in_set_request->sticker);
        set_sticker_position_in_set_request->sticker = NULL;
    }
    free(set_sticker_position_in_set_request);
}

cJSON *set_sticker_position_in_set_request_convertToJSON(set_sticker_position_in_set_request_t *set_sticker_position_in_set_request) {
    cJSON *item = cJSON_CreateObject();

    // set_sticker_position_in_set_request->sticker
    if (!set_sticker_position_in_set_request->sticker) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "sticker", set_sticker_position_in_set_request->sticker) == NULL) {
    goto fail; //String
    }


    // set_sticker_position_in_set_request->position
    if (!set_sticker_position_in_set_request->position) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "position", set_sticker_position_in_set_request->position) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

set_sticker_position_in_set_request_t *set_sticker_position_in_set_request_parseFromJSON(cJSON *set_sticker_position_in_set_requestJSON){

    set_sticker_position_in_set_request_t *set_sticker_position_in_set_request_local_var = NULL;

    // set_sticker_position_in_set_request->sticker
    cJSON *sticker = cJSON_GetObjectItemCaseSensitive(set_sticker_position_in_set_requestJSON, "sticker");
    if (cJSON_IsNull(sticker)) {
        sticker = NULL;
    }
    if (!sticker) {
        goto end;
    }

    
    if(!cJSON_IsString(sticker))
    {
    goto end; //String
    }

    // set_sticker_position_in_set_request->position
    cJSON *position = cJSON_GetObjectItemCaseSensitive(set_sticker_position_in_set_requestJSON, "position");
    if (cJSON_IsNull(position)) {
        position = NULL;
    }
    if (!position) {
        goto end;
    }

    
    if(!cJSON_IsNumber(position))
    {
    goto end; //Numeric
    }


    set_sticker_position_in_set_request_local_var = set_sticker_position_in_set_request_create_internal (
        strdup(sticker->valuestring),
        position->valuedouble
        );

    return set_sticker_position_in_set_request_local_var;
end:
    return NULL;

}
