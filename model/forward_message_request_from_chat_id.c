#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "forward_message_request_from_chat_id.h"



static forward_message_request_from_chat_id_t *forward_message_request_from_chat_id_create_internal(
    ) {
    forward_message_request_from_chat_id_t *forward_message_request_from_chat_id_local_var = malloc(sizeof(forward_message_request_from_chat_id_t));
    if (!forward_message_request_from_chat_id_local_var) {
        return NULL;
    }

    forward_message_request_from_chat_id_local_var->_library_owned = 1;
    return forward_message_request_from_chat_id_local_var;
}

__attribute__((deprecated)) forward_message_request_from_chat_id_t *forward_message_request_from_chat_id_create(
    ) {
    return forward_message_request_from_chat_id_create_internal (
        );
}

void forward_message_request_from_chat_id_free(forward_message_request_from_chat_id_t *forward_message_request_from_chat_id) {
    if(NULL == forward_message_request_from_chat_id){
        return ;
    }
    if(forward_message_request_from_chat_id->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "forward_message_request_from_chat_id_free");
        return ;
    }
    listEntry_t *listEntry;
    free(forward_message_request_from_chat_id);
}

cJSON *forward_message_request_from_chat_id_convertToJSON(forward_message_request_from_chat_id_t *forward_message_request_from_chat_id) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

forward_message_request_from_chat_id_t *forward_message_request_from_chat_id_parseFromJSON(cJSON *forward_message_request_from_chat_idJSON){

    forward_message_request_from_chat_id_t *forward_message_request_from_chat_id_local_var = NULL;


    forward_message_request_from_chat_id_local_var = forward_message_request_from_chat_id_create_internal (
        );

    return forward_message_request_from_chat_id_local_var;
end:
    return NULL;

}
