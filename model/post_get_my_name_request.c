#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_get_my_name_request.h"



static post_get_my_name_request_t *post_get_my_name_request_create_internal(
    char *language_code
    ) {
    post_get_my_name_request_t *post_get_my_name_request_local_var = malloc(sizeof(post_get_my_name_request_t));
    if (!post_get_my_name_request_local_var) {
        return NULL;
    }
    post_get_my_name_request_local_var->language_code = language_code;

    post_get_my_name_request_local_var->_library_owned = 1;
    return post_get_my_name_request_local_var;
}

__attribute__((deprecated)) post_get_my_name_request_t *post_get_my_name_request_create(
    char *language_code
    ) {
    return post_get_my_name_request_create_internal (
        language_code
        );
}

void post_get_my_name_request_free(post_get_my_name_request_t *post_get_my_name_request) {
    if(NULL == post_get_my_name_request){
        return ;
    }
    if(post_get_my_name_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_get_my_name_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_get_my_name_request->language_code) {
        free(post_get_my_name_request->language_code);
        post_get_my_name_request->language_code = NULL;
    }
    free(post_get_my_name_request);
}

cJSON *post_get_my_name_request_convertToJSON(post_get_my_name_request_t *post_get_my_name_request) {
    cJSON *item = cJSON_CreateObject();

    // post_get_my_name_request->language_code
    if(post_get_my_name_request->language_code) {
    if(cJSON_AddStringToObject(item, "language_code", post_get_my_name_request->language_code) == NULL) {
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

post_get_my_name_request_t *post_get_my_name_request_parseFromJSON(cJSON *post_get_my_name_requestJSON){

    post_get_my_name_request_t *post_get_my_name_request_local_var = NULL;

    // post_get_my_name_request->language_code
    cJSON *language_code = cJSON_GetObjectItemCaseSensitive(post_get_my_name_requestJSON, "language_code");
    if (cJSON_IsNull(language_code)) {
        language_code = NULL;
    }
    if (language_code) { 
    if(!cJSON_IsString(language_code) && !cJSON_IsNull(language_code))
    {
    goto end; //String
    }
    }


    post_get_my_name_request_local_var = post_get_my_name_request_create_internal (
        language_code && !cJSON_IsNull(language_code) ? strdup(language_code->valuestring) : NULL
        );

    return post_get_my_name_request_local_var;
end:
    return NULL;

}
