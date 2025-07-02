#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "answer_shipping_query_request.h"



static answer_shipping_query_request_t *answer_shipping_query_request_create_internal(
    char *shipping_query_id,
    int ok,
    list_t *shipping_options,
    char *error_message
    ) {
    answer_shipping_query_request_t *answer_shipping_query_request_local_var = malloc(sizeof(answer_shipping_query_request_t));
    if (!answer_shipping_query_request_local_var) {
        return NULL;
    }
    answer_shipping_query_request_local_var->shipping_query_id = shipping_query_id;
    answer_shipping_query_request_local_var->ok = ok;
    answer_shipping_query_request_local_var->shipping_options = shipping_options;
    answer_shipping_query_request_local_var->error_message = error_message;

    answer_shipping_query_request_local_var->_library_owned = 1;
    return answer_shipping_query_request_local_var;
}

__attribute__((deprecated)) answer_shipping_query_request_t *answer_shipping_query_request_create(
    char *shipping_query_id,
    int ok,
    list_t *shipping_options,
    char *error_message
    ) {
    return answer_shipping_query_request_create_internal (
        shipping_query_id,
        ok,
        shipping_options,
        error_message
        );
}

void answer_shipping_query_request_free(answer_shipping_query_request_t *answer_shipping_query_request) {
    if(NULL == answer_shipping_query_request){
        return ;
    }
    if(answer_shipping_query_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "answer_shipping_query_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (answer_shipping_query_request->shipping_query_id) {
        free(answer_shipping_query_request->shipping_query_id);
        answer_shipping_query_request->shipping_query_id = NULL;
    }
    if (answer_shipping_query_request->shipping_options) {
        list_ForEach(listEntry, answer_shipping_query_request->shipping_options) {
            shipping_option_free(listEntry->data);
        }
        list_freeList(answer_shipping_query_request->shipping_options);
        answer_shipping_query_request->shipping_options = NULL;
    }
    if (answer_shipping_query_request->error_message) {
        free(answer_shipping_query_request->error_message);
        answer_shipping_query_request->error_message = NULL;
    }
    free(answer_shipping_query_request);
}

cJSON *answer_shipping_query_request_convertToJSON(answer_shipping_query_request_t *answer_shipping_query_request) {
    cJSON *item = cJSON_CreateObject();

    // answer_shipping_query_request->shipping_query_id
    if (!answer_shipping_query_request->shipping_query_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "shipping_query_id", answer_shipping_query_request->shipping_query_id) == NULL) {
    goto fail; //String
    }


    // answer_shipping_query_request->ok
    if (!answer_shipping_query_request->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", answer_shipping_query_request->ok) == NULL) {
    goto fail; //Bool
    }


    // answer_shipping_query_request->shipping_options
    if(answer_shipping_query_request->shipping_options) {
    cJSON *shipping_options = cJSON_AddArrayToObject(item, "shipping_options");
    if(shipping_options == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *shipping_optionsListEntry;
    if (answer_shipping_query_request->shipping_options) {
    list_ForEach(shipping_optionsListEntry, answer_shipping_query_request->shipping_options) {
    cJSON *itemLocal = shipping_option_convertToJSON(shipping_optionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(shipping_options, itemLocal);
    }
    }
    }


    // answer_shipping_query_request->error_message
    if(answer_shipping_query_request->error_message) {
    if(cJSON_AddStringToObject(item, "error_message", answer_shipping_query_request->error_message) == NULL) {
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

answer_shipping_query_request_t *answer_shipping_query_request_parseFromJSON(cJSON *answer_shipping_query_requestJSON){

    answer_shipping_query_request_t *answer_shipping_query_request_local_var = NULL;

    // define the local list for answer_shipping_query_request->shipping_options
    list_t *shipping_optionsList = NULL;

    // answer_shipping_query_request->shipping_query_id
    cJSON *shipping_query_id = cJSON_GetObjectItemCaseSensitive(answer_shipping_query_requestJSON, "shipping_query_id");
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

    // answer_shipping_query_request->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(answer_shipping_query_requestJSON, "ok");
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

    // answer_shipping_query_request->shipping_options
    cJSON *shipping_options = cJSON_GetObjectItemCaseSensitive(answer_shipping_query_requestJSON, "shipping_options");
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

    // answer_shipping_query_request->error_message
    cJSON *error_message = cJSON_GetObjectItemCaseSensitive(answer_shipping_query_requestJSON, "error_message");
    if (cJSON_IsNull(error_message)) {
        error_message = NULL;
    }
    if (error_message) { 
    if(!cJSON_IsString(error_message) && !cJSON_IsNull(error_message))
    {
    goto end; //String
    }
    }


    answer_shipping_query_request_local_var = answer_shipping_query_request_create_internal (
        strdup(shipping_query_id->valuestring),
        ok->valueint,
        shipping_options ? shipping_optionsList : NULL,
        error_message && !cJSON_IsNull(error_message) ? strdup(error_message->valuestring) : NULL
        );

    return answer_shipping_query_request_local_var;
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
