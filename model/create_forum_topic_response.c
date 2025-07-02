#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "create_forum_topic_response.h"



static create_forum_topic_response_t *create_forum_topic_response_create_internal(
    int ok,
    forum_topic_t *result
    ) {
    create_forum_topic_response_t *create_forum_topic_response_local_var = malloc(sizeof(create_forum_topic_response_t));
    if (!create_forum_topic_response_local_var) {
        return NULL;
    }
    create_forum_topic_response_local_var->ok = ok;
    create_forum_topic_response_local_var->result = result;

    create_forum_topic_response_local_var->_library_owned = 1;
    return create_forum_topic_response_local_var;
}

__attribute__((deprecated)) create_forum_topic_response_t *create_forum_topic_response_create(
    int ok,
    forum_topic_t *result
    ) {
    return create_forum_topic_response_create_internal (
        ok,
        result
        );
}

void create_forum_topic_response_free(create_forum_topic_response_t *create_forum_topic_response) {
    if(NULL == create_forum_topic_response){
        return ;
    }
    if(create_forum_topic_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "create_forum_topic_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (create_forum_topic_response->result) {
        forum_topic_free(create_forum_topic_response->result);
        create_forum_topic_response->result = NULL;
    }
    free(create_forum_topic_response);
}

cJSON *create_forum_topic_response_convertToJSON(create_forum_topic_response_t *create_forum_topic_response) {
    cJSON *item = cJSON_CreateObject();

    // create_forum_topic_response->ok
    if (!create_forum_topic_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", create_forum_topic_response->ok) == NULL) {
    goto fail; //Bool
    }


    // create_forum_topic_response->result
    if (!create_forum_topic_response->result) {
        goto fail;
    }
    cJSON *result_local_JSON = forum_topic_convertToJSON(create_forum_topic_response->result);
    if(result_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "result", result_local_JSON);
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

create_forum_topic_response_t *create_forum_topic_response_parseFromJSON(cJSON *create_forum_topic_responseJSON){

    create_forum_topic_response_t *create_forum_topic_response_local_var = NULL;

    // define the local variable for create_forum_topic_response->result
    forum_topic_t *result_local_nonprim = NULL;

    // create_forum_topic_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(create_forum_topic_responseJSON, "ok");
    if (cJSON_IsNull(ok)) {
        ok = NULL;
    }
    if (!ok) {
        goto end;
    }

    
    if(!cJSON_IsBool(ok))
    {
    goto end; //Bool
    }

    // create_forum_topic_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(create_forum_topic_responseJSON, "result");
    if (cJSON_IsNull(result)) {
        result = NULL;
    }
    if (!result) {
        goto end;
    }

    
    result_local_nonprim = forum_topic_parseFromJSON(result); //nonprimitive


    create_forum_topic_response_local_var = create_forum_topic_response_create_internal (
        ok->valueint,
        result_local_nonprim
        );

    return create_forum_topic_response_local_var;
end:
    if (result_local_nonprim) {
        forum_topic_free(result_local_nonprim);
        result_local_nonprim = NULL;
    }
    return NULL;

}
