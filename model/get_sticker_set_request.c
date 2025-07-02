#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "get_sticker_set_request.h"



static get_sticker_set_request_t *get_sticker_set_request_create_internal(
    char *name
    ) {
    get_sticker_set_request_t *get_sticker_set_request_local_var = malloc(sizeof(get_sticker_set_request_t));
    if (!get_sticker_set_request_local_var) {
        return NULL;
    }
    get_sticker_set_request_local_var->name = name;

    get_sticker_set_request_local_var->_library_owned = 1;
    return get_sticker_set_request_local_var;
}

__attribute__((deprecated)) get_sticker_set_request_t *get_sticker_set_request_create(
    char *name
    ) {
    return get_sticker_set_request_create_internal (
        name
        );
}

void get_sticker_set_request_free(get_sticker_set_request_t *get_sticker_set_request) {
    if(NULL == get_sticker_set_request){
        return ;
    }
    if(get_sticker_set_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "get_sticker_set_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (get_sticker_set_request->name) {
        free(get_sticker_set_request->name);
        get_sticker_set_request->name = NULL;
    }
    free(get_sticker_set_request);
}

cJSON *get_sticker_set_request_convertToJSON(get_sticker_set_request_t *get_sticker_set_request) {
    cJSON *item = cJSON_CreateObject();

    // get_sticker_set_request->name
    if (!get_sticker_set_request->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", get_sticker_set_request->name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

get_sticker_set_request_t *get_sticker_set_request_parseFromJSON(cJSON *get_sticker_set_requestJSON){

    get_sticker_set_request_t *get_sticker_set_request_local_var = NULL;

    // get_sticker_set_request->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(get_sticker_set_requestJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }


    get_sticker_set_request_local_var = get_sticker_set_request_create_internal (
        strdup(name->valuestring)
        );

    return get_sticker_set_request_local_var;
end:
    return NULL;

}
