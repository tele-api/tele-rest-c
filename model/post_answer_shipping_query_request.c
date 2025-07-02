#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_answer_shipping_query_request.h"



static post_answer_shipping_query_request_t *post_answer_shipping_query_request_create_internal(
    char *shipping_query_id,
    int ok,
    list_t *shipping_options,
    char *error_message
    ) {
    post_answer_shipping_query_request_t *post_answer_shipping_query_request_local_var = malloc(sizeof(post_answer_shipping_query_request_t));
    if (!post_answer_shipping_query_request_local_var) {
        return NULL;
    }
    post_answer_shipping_query_request_local_var->shipping_query_id = shipping_query_id;
    post_answer_shipping_query_request_local_var->ok = ok;
    post_answer_shipping_query_request_local_var->shipping_options = shipping_options;
    post_answer_shipping_query_request_local_var->error_message = error_message;

    post_answer_shipping_query_request_local_var->_library_owned = 1;
    return post_answer_shipping_query_request_local_var;
}

__attribute__((deprecated)) post_answer_shipping_query_request_t *post_answer_shipping_query_request_create(
    char *shipping_query_id,
    int ok,
    list_t *shipping_options,
    char *error_message
    ) {
    return post_answer_shipping_query_request_create_internal (
        shipping_query_id,
        ok,
        shipping_options,
        error_message
        );
}

void post_answer_shipping_query_request_free(post_answer_shipping_query_request_t *post_answer_shipping_query_request) {
    if(NULL == post_answer_shipping_query_request){
        return ;
    }
    if(post_answer_shipping_query_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_answer_shipping_query_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_answer_shipping_query_request->shipping_query_id) {
        free(post_answer_shipping_query_request->shipping_query_id);
        post_answer_shipping_query_request->shipping_query_id = NULL;
    }
    if (post_answer_shipping_query_request->shipping_options) {
        list_ForEach(listEntry, post_answer_shipping_query_request->shipping_options) {
            shipping_option_free(listEntry->data);
        }
        list_freeList(post_answer_shipping_query_request->shipping_options);
        post_answer_shipping_query_request->shipping_options = NULL;
    }
    if (post_answer_shipping_query_request->error_message) {
        free(post_answer_shipping_query_request->error_message);
        post_answer_shipping_query_request->error_message = NULL;
    }
    free(post_answer_shipping_query_request);
}

cJSON *post_answer_shipping_query_request_convertToJSON(post_answer_shipping_query_request_t *post_answer_shipping_query_request) {
    cJSON *item = cJSON_CreateObject();

    // post_answer_shipping_query_request->shipping_query_id
    if (!post_answer_shipping_query_request->shipping_query_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "shipping_query_id", post_answer_shipping_query_request->shipping_query_id) == NULL) {
    goto fail; //String
    }


    // post_answer_shipping_query_request->ok
    if (!post_answer_shipping_query_request->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", post_answer_shipping_query_request->ok) == NULL) {
    goto fail; //Bool
    }


    // post_answer_shipping_query_request->shipping_options
    if(post_answer_shipping_query_request->shipping_options) {
    cJSON *shipping_options = cJSON_AddArrayToObject(item, "shipping_options");
    if(shipping_options == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *shipping_optionsListEntry;
    if (post_answer_shipping_query_request->shipping_options) {
    list_ForEach(shipping_optionsListEntry, post_answer_shipping_query_request->shipping_options) {
    cJSON *itemLocal = shipping_option_convertToJSON(shipping_optionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(shipping_options, itemLocal);
    }
    }
    }


    // post_answer_shipping_query_request->error_message
    if(post_answer_shipping_query_request->error_message) {
    if(cJSON_AddStringToObject(item, "error_message", post_answer_shipping_query_request->error_message) == NULL) {
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

post_answer_shipping_query_request_t *post_answer_shipping_query_request_parseFromJSON(cJSON *post_answer_shipping_query_requestJSON){

    post_answer_shipping_query_request_t *post_answer_shipping_query_request_local_var = NULL;

    // define the local list for post_answer_shipping_query_request->shipping_options
    list_t *shipping_optionsList = NULL;

    // post_answer_shipping_query_request->shipping_query_id
    cJSON *shipping_query_id = cJSON_GetObjectItemCaseSensitive(post_answer_shipping_query_requestJSON, "shipping_query_id");
    if (cJSON_IsNull(shipping_query_id)) {
        shipping_query_id = NULL;
    }
    if (!shipping_query_id) {
        goto end;
    }

    
    if(!cJSON_IsString(shipping_query_id))
    {
    goto end; //String
    }

    // post_answer_shipping_query_request->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(post_answer_shipping_query_requestJSON, "ok");
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

    // post_answer_shipping_query_request->shipping_options
    cJSON *shipping_options = cJSON_GetObjectItemCaseSensitive(post_answer_shipping_query_requestJSON, "shipping_options");
    if (cJSON_IsNull(shipping_options)) {
        shipping_options = NULL;
    }
    if (shipping_options) { 
    cJSON *shipping_options_local_nonprimitive = NULL;
    if(!cJSON_IsArray(shipping_options)){
        goto end; //nonprimitive container
    }

    shipping_optionsList = list_createList();

    cJSON_ArrayForEach(shipping_options_local_nonprimitive,shipping_options )
    {
        if(!cJSON_IsObject(shipping_options_local_nonprimitive)){
            goto end;
        }
        shipping_option_t *shipping_optionsItem = shipping_option_parseFromJSON(shipping_options_local_nonprimitive);

        list_addElement(shipping_optionsList, shipping_optionsItem);
    }
    }

    // post_answer_shipping_query_request->error_message
    cJSON *error_message = cJSON_GetObjectItemCaseSensitive(post_answer_shipping_query_requestJSON, "error_message");
    if (cJSON_IsNull(error_message)) {
        error_message = NULL;
    }
    if (error_message) { 
    if(!cJSON_IsString(error_message) && !cJSON_IsNull(error_message))
    {
    goto end; //String
    }
    }


    post_answer_shipping_query_request_local_var = post_answer_shipping_query_request_create_internal (
        strdup(shipping_query_id->valuestring),
        ok->valueint,
        shipping_options ? shipping_optionsList : NULL,
        error_message && !cJSON_IsNull(error_message) ? strdup(error_message->valuestring) : NULL
        );

    return post_answer_shipping_query_request_local_var;
end:
    if (shipping_optionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, shipping_optionsList) {
            shipping_option_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(shipping_optionsList);
        shipping_optionsList = NULL;
    }
    return NULL;

}
