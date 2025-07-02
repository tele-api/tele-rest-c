#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "set_my_name_request.h"



static set_my_name_request_t *set_my_name_request_create_internal(
    char *name,
    char *language_code
    ) {
    set_my_name_request_t *set_my_name_request_local_var = malloc(sizeof(set_my_name_request_t));
    if (!set_my_name_request_local_var) {
        return NULL;
    }
    set_my_name_request_local_var->name = name;
    set_my_name_request_local_var->language_code = language_code;

    set_my_name_request_local_var->_library_owned = 1;
    return set_my_name_request_local_var;
}

__attribute__((deprecated)) set_my_name_request_t *set_my_name_request_create(
    char *name,
    char *language_code
    ) {
    return set_my_name_request_create_internal (
        name,
        language_code
        );
}

void set_my_name_request_free(set_my_name_request_t *set_my_name_request) {
    if(NULL == set_my_name_request){
        return ;
    }
    if(set_my_name_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "set_my_name_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (set_my_name_request->name) {
        free(set_my_name_request->name);
        set_my_name_request->name = NULL;
    }
    if (set_my_name_request->language_code) {
        free(set_my_name_request->language_code);
        set_my_name_request->language_code = NULL;
    }
    free(set_my_name_request);
}

cJSON *set_my_name_request_convertToJSON(set_my_name_request_t *set_my_name_request) {
    cJSON *item = cJSON_CreateObject();

    // set_my_name_request->name
    if(set_my_name_request->name) {
    if(cJSON_AddStringToObject(item, "name", set_my_name_request->name) == NULL) {
    goto fail; //String
    }
    }


    // set_my_name_request->language_code
    if(set_my_name_request->language_code) {
    if(cJSON_AddStringToObject(item, "language_code", set_my_name_request->language_code) == NULL) {
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

set_my_name_request_t *set_my_name_request_parseFromJSON(cJSON *set_my_name_requestJSON){

    set_my_name_request_t *set_my_name_request_local_var = NULL;

    // set_my_name_request->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(set_my_name_requestJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // set_my_name_request->language_code
    cJSON *language_code = cJSON_GetObjectItemCaseSensitive(set_my_name_requestJSON, "language_code");
    if (cJSON_IsNull(language_code)) {
        language_code = NULL;
    }
    if (language_code) { 
    if(!cJSON_IsString(language_code) && !cJSON_IsNull(language_code))
    {
    goto end; //String
    }
    }


    set_my_name_request_local_var = set_my_name_request_create_internal (
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        language_code && !cJSON_IsNull(language_code) ? strdup(language_code->valuestring) : NULL
        );

    return set_my_name_request_local_var;
end:
    return NULL;

}
