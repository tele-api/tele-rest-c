#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "get_chat_request.h"



static get_chat_request_t *get_chat_request_create_internal(
    leave_chat_request_chat_id_t *chat_id
    ) {
    get_chat_request_t *get_chat_request_local_var = malloc(sizeof(get_chat_request_t));
    if (!get_chat_request_local_var) {
        return NULL;
    }
    get_chat_request_local_var->chat_id = chat_id;

    get_chat_request_local_var->_library_owned = 1;
    return get_chat_request_local_var;
}

__attribute__((deprecated)) get_chat_request_t *get_chat_request_create(
    leave_chat_request_chat_id_t *chat_id
    ) {
    return get_chat_request_create_internal (
        chat_id
        );
}

void get_chat_request_free(get_chat_request_t *get_chat_request) {
    if(NULL == get_chat_request){
        return ;
    }
    if(get_chat_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "get_chat_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (get_chat_request->chat_id) {
        leave_chat_request_chat_id_free(get_chat_request->chat_id);
        get_chat_request->chat_id = NULL;
    }
    free(get_chat_request);
}

cJSON *get_chat_request_convertToJSON(get_chat_request_t *get_chat_request) {
    cJSON *item = cJSON_CreateObject();

    // get_chat_request->chat_id
    if (!get_chat_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = leave_chat_request_chat_id_convertToJSON(get_chat_request->chat_id);
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

get_chat_request_t *get_chat_request_parseFromJSON(cJSON *get_chat_requestJSON){

    get_chat_request_t *get_chat_request_local_var = NULL;

    // define the local variable for get_chat_request->chat_id
    leave_chat_request_chat_id_t *chat_id_local_nonprim = NULL;

    // get_chat_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(get_chat_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = leave_chat_request_chat_id_parseFromJSON(chat_id); //nonprimitive


    get_chat_request_local_var = get_chat_request_create_internal (
        chat_id_local_nonprim
        );

    return get_chat_request_local_var;
end:
    if (chat_id_local_nonprim) {
        leave_chat_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
