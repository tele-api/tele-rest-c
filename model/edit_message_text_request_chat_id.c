#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "edit_message_text_request_chat_id.h"



static edit_message_text_request_chat_id_t *edit_message_text_request_chat_id_create_internal(
    ) {
    edit_message_text_request_chat_id_t *edit_message_text_request_chat_id_local_var = malloc(sizeof(edit_message_text_request_chat_id_t));
    if (!edit_message_text_request_chat_id_local_var) {
        return NULL;
    }

    edit_message_text_request_chat_id_local_var->_library_owned = 1;
    return edit_message_text_request_chat_id_local_var;
}

__attribute__((deprecated)) edit_message_text_request_chat_id_t *edit_message_text_request_chat_id_create(
    ) {
    return edit_message_text_request_chat_id_create_internal (
        );
}

void edit_message_text_request_chat_id_free(edit_message_text_request_chat_id_t *edit_message_text_request_chat_id) {
    if(NULL == edit_message_text_request_chat_id){
        return ;
    }
    if(edit_message_text_request_chat_id->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "edit_message_text_request_chat_id_free");
        return ;
    }
    listEntry_t *listEntry;
    free(edit_message_text_request_chat_id);
}

cJSON *edit_message_text_request_chat_id_convertToJSON(edit_message_text_request_chat_id_t *edit_message_text_request_chat_id) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

edit_message_text_request_chat_id_t *edit_message_text_request_chat_id_parseFromJSON(cJSON *edit_message_text_request_chat_idJSON){

    edit_message_text_request_chat_id_t *edit_message_text_request_chat_id_local_var = NULL;


    edit_message_text_request_chat_id_local_var = edit_message_text_request_chat_id_create_internal (
        );

    return edit_message_text_request_chat_id_local_var;
end:
    return NULL;

}
