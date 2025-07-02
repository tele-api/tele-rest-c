#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "set_my_description_request.h"



static set_my_description_request_t *set_my_description_request_create_internal(
    char *description,
    char *language_code
    ) {
    set_my_description_request_t *set_my_description_request_local_var = malloc(sizeof(set_my_description_request_t));
    if (!set_my_description_request_local_var) {
        return NULL;
    }
    set_my_description_request_local_var->description = description;
    set_my_description_request_local_var->language_code = language_code;

    set_my_description_request_local_var->_library_owned = 1;
    return set_my_description_request_local_var;
}

__attribute__((deprecated)) set_my_description_request_t *set_my_description_request_create(
    char *description,
    char *language_code
    ) {
    return set_my_description_request_create_internal (
        description,
        language_code
        );
}

void set_my_description_request_free(set_my_description_request_t *set_my_description_request) {
    if(NULL == set_my_description_request){
        return ;
    }
    if(set_my_description_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "set_my_description_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (set_my_description_request->description) {
        free(set_my_description_request->description);
        set_my_description_request->description = NULL;
    }
    if (set_my_description_request->language_code) {
        free(set_my_description_request->language_code);
        set_my_description_request->language_code = NULL;
    }
    free(set_my_description_request);
}

cJSON *set_my_description_request_convertToJSON(set_my_description_request_t *set_my_description_request) {
    cJSON *item = cJSON_CreateObject();

    // set_my_description_request->description
    if(set_my_description_request->description) {
    if(cJSON_AddStringToObject(item, "description", set_my_description_request->description) == NULL) {
    goto fail; //String
    }
    }


    // set_my_description_request->language_code
    if(set_my_description_request->language_code) {
    if(cJSON_AddStringToObject(item, "language_code", set_my_description_request->language_code) == NULL) {
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

set_my_description_request_t *set_my_description_request_parseFromJSON(cJSON *set_my_description_requestJSON){

    set_my_description_request_t *set_my_description_request_local_var = NULL;

    // set_my_description_request->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(set_my_description_requestJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (description) { 
    if(!cJSON_IsString(description) && !cJSON_IsNull(description))
    {
    goto end; //String
    }
    }

    // set_my_description_request->language_code
    cJSON *language_code = cJSON_GetObjectItemCaseSensitive(set_my_description_requestJSON, "language_code");
    if (cJSON_IsNull(language_code)) {
        language_code = NULL;
    }
    if (language_code) { 
    if(!cJSON_IsString(language_code) && !cJSON_IsNull(language_code))
    {
    goto end; //String
    }
    }


    set_my_description_request_local_var = set_my_description_request_create_internal (
        description && !cJSON_IsNull(description) ? strdup(description->valuestring) : NULL,
        language_code && !cJSON_IsNull(language_code) ? strdup(language_code->valuestring) : NULL
        );

    return set_my_description_request_local_var;
end:
    return NULL;

}
