#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "chat_background.h"



static chat_background_t *chat_background_create_internal(
    background_type_t *type
    ) {
    chat_background_t *chat_background_local_var = malloc(sizeof(chat_background_t));
    if (!chat_background_local_var) {
        return NULL;
    }
    chat_background_local_var->type = type;

    chat_background_local_var->_library_owned = 1;
    return chat_background_local_var;
}

__attribute__((deprecated)) chat_background_t *chat_background_create(
    background_type_t *type
    ) {
    return chat_background_create_internal (
        type
        );
}

void chat_background_free(chat_background_t *chat_background) {
    if(NULL == chat_background){
        return ;
    }
    if(chat_background->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "chat_background_free");
        return ;
    }
    listEntry_t *listEntry;
    if (chat_background->type) {
        background_type_free(chat_background->type);
        chat_background->type = NULL;
    }
    free(chat_background);
}

cJSON *chat_background_convertToJSON(chat_background_t *chat_background) {
    cJSON *item = cJSON_CreateObject();

    // chat_background->type
    if (!chat_background->type) {
        goto fail;
    }
    cJSON *type_local_JSON = background_type_convertToJSON(chat_background->type);
    if(type_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "type", type_local_JSON);
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

chat_background_t *chat_background_parseFromJSON(cJSON *chat_backgroundJSON){

    chat_background_t *chat_background_local_var = NULL;

    // define the local variable for chat_background->type
    background_type_t *type_local_nonprim = NULL;

    // chat_background->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(chat_backgroundJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    
    type_local_nonprim = background_type_parseFromJSON(type); //nonprimitive


    chat_background_local_var = chat_background_create_internal (
        type_local_nonprim
        );

    return chat_background_local_var;
end:
    if (type_local_nonprim) {
        background_type_free(type_local_nonprim);
        type_local_nonprim = NULL;
    }
    return NULL;

}
