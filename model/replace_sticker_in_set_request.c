#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "replace_sticker_in_set_request.h"



static replace_sticker_in_set_request_t *replace_sticker_in_set_request_create_internal(
    int user_id,
    char *name,
    char *old_sticker,
    input_sticker_t *sticker
    ) {
    replace_sticker_in_set_request_t *replace_sticker_in_set_request_local_var = malloc(sizeof(replace_sticker_in_set_request_t));
    if (!replace_sticker_in_set_request_local_var) {
        return NULL;
    }
    replace_sticker_in_set_request_local_var->user_id = user_id;
    replace_sticker_in_set_request_local_var->name = name;
    replace_sticker_in_set_request_local_var->old_sticker = old_sticker;
    replace_sticker_in_set_request_local_var->sticker = sticker;

    replace_sticker_in_set_request_local_var->_library_owned = 1;
    return replace_sticker_in_set_request_local_var;
}

__attribute__((deprecated)) replace_sticker_in_set_request_t *replace_sticker_in_set_request_create(
    int user_id,
    char *name,
    char *old_sticker,
    input_sticker_t *sticker
    ) {
    return replace_sticker_in_set_request_create_internal (
        user_id,
        name,
        old_sticker,
        sticker
        );
}

void replace_sticker_in_set_request_free(replace_sticker_in_set_request_t *replace_sticker_in_set_request) {
    if(NULL == replace_sticker_in_set_request){
        return ;
    }
    if(replace_sticker_in_set_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "replace_sticker_in_set_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (replace_sticker_in_set_request->name) {
        free(replace_sticker_in_set_request->name);
        replace_sticker_in_set_request->name = NULL;
    }
    if (replace_sticker_in_set_request->old_sticker) {
        free(replace_sticker_in_set_request->old_sticker);
        replace_sticker_in_set_request->old_sticker = NULL;
    }
    if (replace_sticker_in_set_request->sticker) {
        input_sticker_free(replace_sticker_in_set_request->sticker);
        replace_sticker_in_set_request->sticker = NULL;
    }
    free(replace_sticker_in_set_request);
}

cJSON *replace_sticker_in_set_request_convertToJSON(replace_sticker_in_set_request_t *replace_sticker_in_set_request) {
    cJSON *item = cJSON_CreateObject();

    // replace_sticker_in_set_request->user_id
    if (!replace_sticker_in_set_request->user_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "user_id", replace_sticker_in_set_request->user_id) == NULL) {
    goto fail; //Numeric
    }


    // replace_sticker_in_set_request->name
    if (!replace_sticker_in_set_request->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", replace_sticker_in_set_request->name) == NULL) {
    goto fail; //String
    }


    // replace_sticker_in_set_request->old_sticker
    if (!replace_sticker_in_set_request->old_sticker) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "old_sticker", replace_sticker_in_set_request->old_sticker) == NULL) {
    goto fail; //String
    }


    // replace_sticker_in_set_request->sticker
    if (!replace_sticker_in_set_request->sticker) {
        goto fail;
    }
    cJSON *sticker_local_JSON = input_sticker_convertToJSON(replace_sticker_in_set_request->sticker);
    if(sticker_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "sticker", sticker_local_JSON);
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

replace_sticker_in_set_request_t *replace_sticker_in_set_request_parseFromJSON(cJSON *replace_sticker_in_set_requestJSON){

    replace_sticker_in_set_request_t *replace_sticker_in_set_request_local_var = NULL;

    // define the local variable for replace_sticker_in_set_request->sticker
    input_sticker_t *sticker_local_nonprim = NULL;

    // replace_sticker_in_set_request->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(replace_sticker_in_set_requestJSON, "user_id");
    if (cJSON_IsNull(user_id)) {
        user_id = NULL;
    }
    if (!user_id) {
        goto end;
    }

    
    if(!cJSON_IsNumber(user_id))
    {
    goto end; //Numeric
    }

    // replace_sticker_in_set_request->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(replace_sticker_in_set_requestJSON, "name");
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

    // replace_sticker_in_set_request->old_sticker
    cJSON *old_sticker = cJSON_GetObjectItemCaseSensitive(replace_sticker_in_set_requestJSON, "old_sticker");
    if (cJSON_IsNull(old_sticker)) {
        old_sticker = NULL;
    }
    if (!old_sticker) {
        goto end;
    }

    
    if(!cJSON_IsString(old_sticker))
    {
    goto end; //String
    }

    // replace_sticker_in_set_request->sticker
    cJSON *sticker = cJSON_GetObjectItemCaseSensitive(replace_sticker_in_set_requestJSON, "sticker");
    if (cJSON_IsNull(sticker)) {
        sticker = NULL;
    }
    if (!sticker) {
        goto end;
    }

    
    sticker_local_nonprim = input_sticker_parseFromJSON(sticker); //nonprimitive


    replace_sticker_in_set_request_local_var = replace_sticker_in_set_request_create_internal (
        user_id->valuedouble,
        strdup(name->valuestring),
        strdup(old_sticker->valuestring),
        sticker_local_nonprim
        );

    return replace_sticker_in_set_request_local_var;
end:
    if (sticker_local_nonprim) {
        input_sticker_free(sticker_local_nonprim);
        sticker_local_nonprim = NULL;
    }
    return NULL;

}
