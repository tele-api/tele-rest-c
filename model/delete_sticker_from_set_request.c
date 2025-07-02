#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "delete_sticker_from_set_request.h"



static delete_sticker_from_set_request_t *delete_sticker_from_set_request_create_internal(
    char *sticker
    ) {
    delete_sticker_from_set_request_t *delete_sticker_from_set_request_local_var = malloc(sizeof(delete_sticker_from_set_request_t));
    if (!delete_sticker_from_set_request_local_var) {
        return NULL;
    }
    delete_sticker_from_set_request_local_var->sticker = sticker;

    delete_sticker_from_set_request_local_var->_library_owned = 1;
    return delete_sticker_from_set_request_local_var;
}

__attribute__((deprecated)) delete_sticker_from_set_request_t *delete_sticker_from_set_request_create(
    char *sticker
    ) {
    return delete_sticker_from_set_request_create_internal (
        sticker
        );
}

void delete_sticker_from_set_request_free(delete_sticker_from_set_request_t *delete_sticker_from_set_request) {
    if(NULL == delete_sticker_from_set_request){
        return ;
    }
    if(delete_sticker_from_set_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "delete_sticker_from_set_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (delete_sticker_from_set_request->sticker) {
        free(delete_sticker_from_set_request->sticker);
        delete_sticker_from_set_request->sticker = NULL;
    }
    free(delete_sticker_from_set_request);
}

cJSON *delete_sticker_from_set_request_convertToJSON(delete_sticker_from_set_request_t *delete_sticker_from_set_request) {
    cJSON *item = cJSON_CreateObject();

    // delete_sticker_from_set_request->sticker
    if (!delete_sticker_from_set_request->sticker) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "sticker", delete_sticker_from_set_request->sticker) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

delete_sticker_from_set_request_t *delete_sticker_from_set_request_parseFromJSON(cJSON *delete_sticker_from_set_requestJSON){

    delete_sticker_from_set_request_t *delete_sticker_from_set_request_local_var = NULL;

    // delete_sticker_from_set_request->sticker
    cJSON *sticker = cJSON_GetObjectItemCaseSensitive(delete_sticker_from_set_requestJSON, "sticker");
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


    delete_sticker_from_set_request_local_var = delete_sticker_from_set_request_create_internal (
        strdup(sticker->valuestring)
        );

    return delete_sticker_from_set_request_local_var;
end:
    return NULL;

}
