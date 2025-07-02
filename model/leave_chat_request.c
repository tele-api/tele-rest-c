#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "leave_chat_request.h"



static leave_chat_request_t *leave_chat_request_create_internal(
    leave_chat_request_chat_id_t *chat_id
    ) {
    leave_chat_request_t *leave_chat_request_local_var = malloc(sizeof(leave_chat_request_t));
    if (!leave_chat_request_local_var) {
        return NULL;
    }
    leave_chat_request_local_var->chat_id = chat_id;

    leave_chat_request_local_var->_library_owned = 1;
    return leave_chat_request_local_var;
}

__attribute__((deprecated)) leave_chat_request_t *leave_chat_request_create(
    leave_chat_request_chat_id_t *chat_id
    ) {
    return leave_chat_request_create_internal (
        chat_id
        );
}

void leave_chat_request_free(leave_chat_request_t *leave_chat_request) {
    if(NULL == leave_chat_request){
        return ;
    }
    if(leave_chat_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "leave_chat_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (leave_chat_request->chat_id) {
        leave_chat_request_chat_id_free(leave_chat_request->chat_id);
        leave_chat_request->chat_id = NULL;
    }
    free(leave_chat_request);
}

cJSON *leave_chat_request_convertToJSON(leave_chat_request_t *leave_chat_request) {
    cJSON *item = cJSON_CreateObject();

    // leave_chat_request->chat_id
    if (!leave_chat_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = leave_chat_request_chat_id_convertToJSON(leave_chat_request->chat_id);
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

leave_chat_request_t *leave_chat_request_parseFromJSON(cJSON *leave_chat_requestJSON){

    leave_chat_request_t *leave_chat_request_local_var = NULL;

    // define the local variable for leave_chat_request->chat_id
    leave_chat_request_chat_id_t *chat_id_local_nonprim = NULL;

    // leave_chat_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(leave_chat_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = leave_chat_request_chat_id_parseFromJSON(chat_id); //nonprimitive


    leave_chat_request_local_var = leave_chat_request_create_internal (
        chat_id_local_nonprim
        );

    return leave_chat_request_local_var;
end:
    if (chat_id_local_nonprim) {
        leave_chat_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
