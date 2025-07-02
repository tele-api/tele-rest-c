#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "delete_chat_sticker_set_request.h"



static delete_chat_sticker_set_request_t *delete_chat_sticker_set_request_create_internal(
    bot_command_scope_chat_chat_id_t *chat_id
    ) {
    delete_chat_sticker_set_request_t *delete_chat_sticker_set_request_local_var = malloc(sizeof(delete_chat_sticker_set_request_t));
    if (!delete_chat_sticker_set_request_local_var) {
        return NULL;
    }
    delete_chat_sticker_set_request_local_var->chat_id = chat_id;

    delete_chat_sticker_set_request_local_var->_library_owned = 1;
    return delete_chat_sticker_set_request_local_var;
}

__attribute__((deprecated)) delete_chat_sticker_set_request_t *delete_chat_sticker_set_request_create(
    bot_command_scope_chat_chat_id_t *chat_id
    ) {
    return delete_chat_sticker_set_request_create_internal (
        chat_id
        );
}

void delete_chat_sticker_set_request_free(delete_chat_sticker_set_request_t *delete_chat_sticker_set_request) {
    if(NULL == delete_chat_sticker_set_request){
        return ;
    }
    if(delete_chat_sticker_set_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "delete_chat_sticker_set_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (delete_chat_sticker_set_request->chat_id) {
        bot_command_scope_chat_chat_id_free(delete_chat_sticker_set_request->chat_id);
        delete_chat_sticker_set_request->chat_id = NULL;
    }
    free(delete_chat_sticker_set_request);
}

cJSON *delete_chat_sticker_set_request_convertToJSON(delete_chat_sticker_set_request_t *delete_chat_sticker_set_request) {
    cJSON *item = cJSON_CreateObject();

    // delete_chat_sticker_set_request->chat_id
    if (!delete_chat_sticker_set_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = bot_command_scope_chat_chat_id_convertToJSON(delete_chat_sticker_set_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
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

delete_chat_sticker_set_request_t *delete_chat_sticker_set_request_parseFromJSON(cJSON *delete_chat_sticker_set_requestJSON){

    delete_chat_sticker_set_request_t *delete_chat_sticker_set_request_local_var = NULL;

    // define the local variable for delete_chat_sticker_set_request->chat_id
    bot_command_scope_chat_chat_id_t *chat_id_local_nonprim = NULL;

    // delete_chat_sticker_set_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(delete_chat_sticker_set_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = bot_command_scope_chat_chat_id_parseFromJSON(chat_id); //nonprimitive


    delete_chat_sticker_set_request_local_var = delete_chat_sticker_set_request_create_internal (
        chat_id_local_nonprim
        );

    return delete_chat_sticker_set_request_local_var;
end:
    if (chat_id_local_nonprim) {
        bot_command_scope_chat_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
