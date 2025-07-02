#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "get_my_description_request.h"



static get_my_description_request_t *get_my_description_request_create_internal(
    char *language_code
    ) {
    get_my_description_request_t *get_my_description_request_local_var = malloc(sizeof(get_my_description_request_t));
    if (!get_my_description_request_local_var) {
        return NULL;
    }
    get_my_description_request_local_var->language_code = language_code;

    get_my_description_request_local_var->_library_owned = 1;
    return get_my_description_request_local_var;
}

__attribute__((deprecated)) get_my_description_request_t *get_my_description_request_create(
    char *language_code
    ) {
    return get_my_description_request_create_internal (
        language_code
        );
}

void get_my_description_request_free(get_my_description_request_t *get_my_description_request) {
    if(NULL == get_my_description_request){
        return ;
    }
    if(get_my_description_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "get_my_description_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (get_my_description_request->language_code) {
        free(get_my_description_request->language_code);
        get_my_description_request->language_code = NULL;
    }
    free(get_my_description_request);
}

cJSON *get_my_description_request_convertToJSON(get_my_description_request_t *get_my_description_request) {
    cJSON *item = cJSON_CreateObject();

    // get_my_description_request->language_code
    if(get_my_description_request->language_code) {
    if(cJSON_AddStringToObject(item, "language_code", get_my_description_request->language_code) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

get_my_description_request_t *get_my_description_request_parseFromJSON(cJSON *get_my_description_requestJSON){

    get_my_description_request_t *get_my_description_request_local_var = NULL;

    // get_my_description_request->language_code
    cJSON *language_code = cJSON_GetObjectItemCaseSensitive(get_my_description_requestJSON, "language_code");
    if (cJSON_IsNull(language_code)) {
        language_code = NULL;
    }
    if (language_code) { 
    if(!cJSON_IsString(language_code) && !cJSON_IsNull(language_code))
    {
    goto end; //String
    }
    }


    get_my_description_request_local_var = get_my_description_request_create_internal (
        language_code && !cJSON_IsNull(language_code) ? strdup(language_code->valuestring) : NULL
        );

    return get_my_description_request_local_var;
end:
    return NULL;

}
