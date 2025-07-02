#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_set_my_name_request.h"



static post_set_my_name_request_t *post_set_my_name_request_create_internal(
    char *name,
    char *language_code
    ) {
    post_set_my_name_request_t *post_set_my_name_request_local_var = malloc(sizeof(post_set_my_name_request_t));
    if (!post_set_my_name_request_local_var) {
        return NULL;
    }
    post_set_my_name_request_local_var->name = name;
    post_set_my_name_request_local_var->language_code = language_code;

    post_set_my_name_request_local_var->_library_owned = 1;
    return post_set_my_name_request_local_var;
}

__attribute__((deprecated)) post_set_my_name_request_t *post_set_my_name_request_create(
    char *name,
    char *language_code
    ) {
    return post_set_my_name_request_create_internal (
        name,
        language_code
        );
}

void post_set_my_name_request_free(post_set_my_name_request_t *post_set_my_name_request) {
    if(NULL == post_set_my_name_request){
        return ;
    }
    if(post_set_my_name_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_set_my_name_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_set_my_name_request->name) {
        free(post_set_my_name_request->name);
        post_set_my_name_request->name = NULL;
    }
    if (post_set_my_name_request->language_code) {
        free(post_set_my_name_request->language_code);
        post_set_my_name_request->language_code = NULL;
    }
    free(post_set_my_name_request);
}

cJSON *post_set_my_name_request_convertToJSON(post_set_my_name_request_t *post_set_my_name_request) {
    cJSON *item = cJSON_CreateObject();

    // post_set_my_name_request->name
    if(post_set_my_name_request->name) {
    if(cJSON_AddStringToObject(item, "name", post_set_my_name_request->name) == NULL) {
    goto fail; //String
    }
    }


    // post_set_my_name_request->language_code
    if(post_set_my_name_request->language_code) {
    if(cJSON_AddStringToObject(item, "language_code", post_set_my_name_request->language_code) == NULL) {
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

post_set_my_name_request_t *post_set_my_name_request_parseFromJSON(cJSON *post_set_my_name_requestJSON){

    post_set_my_name_request_t *post_set_my_name_request_local_var = NULL;

    // post_set_my_name_request->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(post_set_my_name_requestJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // post_set_my_name_request->language_code
    cJSON *language_code = cJSON_GetObjectItemCaseSensitive(post_set_my_name_requestJSON, "language_code");
    if (cJSON_IsNull(language_code)) {
        language_code = NULL;
    }
    if (language_code) { 
    if(!cJSON_IsString(language_code) && !cJSON_IsNull(language_code))
    {
    goto end; //String
    }
    }


    post_set_my_name_request_local_var = post_set_my_name_request_create_internal (
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        language_code && !cJSON_IsNull(language_code) ? strdup(language_code->valuestring) : NULL
        );

    return post_set_my_name_request_local_var;
end:
    return NULL;

}
