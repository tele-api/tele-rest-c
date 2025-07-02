#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "export_chat_invite_link_request.h"



static export_chat_invite_link_request_t *export_chat_invite_link_request_create_internal(
    send_message_request_chat_id_t *chat_id
    ) {
    export_chat_invite_link_request_t *export_chat_invite_link_request_local_var = malloc(sizeof(export_chat_invite_link_request_t));
    if (!export_chat_invite_link_request_local_var) {
        return NULL;
    }
    export_chat_invite_link_request_local_var->chat_id = chat_id;

    export_chat_invite_link_request_local_var->_library_owned = 1;
    return export_chat_invite_link_request_local_var;
}

__attribute__((deprecated)) export_chat_invite_link_request_t *export_chat_invite_link_request_create(
    send_message_request_chat_id_t *chat_id
    ) {
    return export_chat_invite_link_request_create_internal (
        chat_id
        );
}

void export_chat_invite_link_request_free(export_chat_invite_link_request_t *export_chat_invite_link_request) {
    if(NULL == export_chat_invite_link_request){
        return ;
    }
    if(export_chat_invite_link_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "export_chat_invite_link_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (export_chat_invite_link_request->chat_id) {
        send_message_request_chat_id_free(export_chat_invite_link_request->chat_id);
        export_chat_invite_link_request->chat_id = NULL;
    }
    free(export_chat_invite_link_request);
}

cJSON *export_chat_invite_link_request_convertToJSON(export_chat_invite_link_request_t *export_chat_invite_link_request) {
    cJSON *item = cJSON_CreateObject();

    // export_chat_invite_link_request->chat_id
    if (!export_chat_invite_link_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = send_message_request_chat_id_convertToJSON(export_chat_invite_link_request->chat_id);
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

export_chat_invite_link_request_t *export_chat_invite_link_request_parseFromJSON(cJSON *export_chat_invite_link_requestJSON){

    export_chat_invite_link_request_t *export_chat_invite_link_request_local_var = NULL;

    // define the local variable for export_chat_invite_link_request->chat_id
    send_message_request_chat_id_t *chat_id_local_nonprim = NULL;

    // export_chat_invite_link_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(export_chat_invite_link_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = send_message_request_chat_id_parseFromJSON(chat_id); //nonprimitive


    export_chat_invite_link_request_local_var = export_chat_invite_link_request_create_internal (
        chat_id_local_nonprim
        );

    return export_chat_invite_link_request_local_var;
end:
    if (chat_id_local_nonprim) {
        send_message_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
