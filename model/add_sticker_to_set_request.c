#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "add_sticker_to_set_request.h"



static add_sticker_to_set_request_t *add_sticker_to_set_request_create_internal(
    int user_id,
    char *name,
    input_sticker_t *sticker
    ) {
    add_sticker_to_set_request_t *add_sticker_to_set_request_local_var = malloc(sizeof(add_sticker_to_set_request_t));
    if (!add_sticker_to_set_request_local_var) {
        return NULL;
    }
    add_sticker_to_set_request_local_var->user_id = user_id;
    add_sticker_to_set_request_local_var->name = name;
    add_sticker_to_set_request_local_var->sticker = sticker;

    add_sticker_to_set_request_local_var->_library_owned = 1;
    return add_sticker_to_set_request_local_var;
}

__attribute__((deprecated)) add_sticker_to_set_request_t *add_sticker_to_set_request_create(
    int user_id,
    char *name,
    input_sticker_t *sticker
    ) {
    return add_sticker_to_set_request_create_internal (
        user_id,
        name,
        sticker
        );
}

void add_sticker_to_set_request_free(add_sticker_to_set_request_t *add_sticker_to_set_request) {
    if(NULL == add_sticker_to_set_request){
        return ;
    }
    if(add_sticker_to_set_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "add_sticker_to_set_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (add_sticker_to_set_request->name) {
        free(add_sticker_to_set_request->name);
        add_sticker_to_set_request->name = NULL;
    }
    if (add_sticker_to_set_request->sticker) {
        input_sticker_free(add_sticker_to_set_request->sticker);
        add_sticker_to_set_request->sticker = NULL;
    }
    free(add_sticker_to_set_request);
}

cJSON *add_sticker_to_set_request_convertToJSON(add_sticker_to_set_request_t *add_sticker_to_set_request) {
    cJSON *item = cJSON_CreateObject();

    // add_sticker_to_set_request->user_id
    if (!add_sticker_to_set_request->user_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "user_id", add_sticker_to_set_request->user_id) == NULL) {
    goto fail; //Numeric
    }


    // add_sticker_to_set_request->name
    if (!add_sticker_to_set_request->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", add_sticker_to_set_request->name) == NULL) {
    goto fail; //String
    }


    // add_sticker_to_set_request->sticker
    if (!add_sticker_to_set_request->sticker) {
        goto fail;
    }
    cJSON *sticker_local_JSON = input_sticker_convertToJSON(add_sticker_to_set_request->sticker);
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

add_sticker_to_set_request_t *add_sticker_to_set_request_parseFromJSON(cJSON *add_sticker_to_set_requestJSON){

    add_sticker_to_set_request_t *add_sticker_to_set_request_local_var = NULL;

    // define the local variable for add_sticker_to_set_request->sticker
    input_sticker_t *sticker_local_nonprim = NULL;

    // add_sticker_to_set_request->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(add_sticker_to_set_requestJSON, "user_id");
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

    // add_sticker_to_set_request->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(add_sticker_to_set_requestJSON, "name");
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

    // add_sticker_to_set_request->sticker
    cJSON *sticker = cJSON_GetObjectItemCaseSensitive(add_sticker_to_set_requestJSON, "sticker");
    if (cJSON_IsNull(sticker)) {
        sticker = NULL;
    }
    if (!sticker) {
        goto end;
    }

    
    sticker_local_nonprim = input_sticker_parseFromJSON(sticker); //nonprimitive


    add_sticker_to_set_request_local_var = add_sticker_to_set_request_create_internal (
        user_id->valuedouble,
        strdup(name->valuestring),
        sticker_local_nonprim
        );

    return add_sticker_to_set_request_local_var;
end:
    if (sticker_local_nonprim) {
        input_sticker_free(sticker_local_nonprim);
        sticker_local_nonprim = NULL;
    }
    return NULL;

}
