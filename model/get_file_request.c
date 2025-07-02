#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "get_file_request.h"



static get_file_request_t *get_file_request_create_internal(
    char *file_id
    ) {
    get_file_request_t *get_file_request_local_var = malloc(sizeof(get_file_request_t));
    if (!get_file_request_local_var) {
        return NULL;
    }
    get_file_request_local_var->file_id = file_id;

    get_file_request_local_var->_library_owned = 1;
    return get_file_request_local_var;
}

__attribute__((deprecated)) get_file_request_t *get_file_request_create(
    char *file_id
    ) {
    return get_file_request_create_internal (
        file_id
        );
}

void get_file_request_free(get_file_request_t *get_file_request) {
    if(NULL == get_file_request){
        return ;
    }
    if(get_file_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "get_file_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (get_file_request->file_id) {
        free(get_file_request->file_id);
        get_file_request->file_id = NULL;
    }
    free(get_file_request);
}

cJSON *get_file_request_convertToJSON(get_file_request_t *get_file_request) {
    cJSON *item = cJSON_CreateObject();

    // get_file_request->file_id
    if (!get_file_request->file_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "file_id", get_file_request->file_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

get_file_request_t *get_file_request_parseFromJSON(cJSON *get_file_requestJSON){

    get_file_request_t *get_file_request_local_var = NULL;

    // get_file_request->file_id
    cJSON *file_id = cJSON_GetObjectItemCaseSensitive(get_file_requestJSON, "file_id");
    if (cJSON_IsNull(file_id)) {
        file_id = NULL;
    }
    if (!file_id) {
        goto end;
    }

    
    if(!cJSON_IsString(file_id))
    {
    goto end; //String
    }


    get_file_request_local_var = get_file_request_create_internal (
        strdup(file_id->valuestring)
        );

    return get_file_request_local_var;
end:
    return NULL;

}
