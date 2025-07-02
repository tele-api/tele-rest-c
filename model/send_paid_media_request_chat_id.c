#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "send_paid_media_request_chat_id.h"



static send_paid_media_request_chat_id_t *send_paid_media_request_chat_id_create_internal(
    ) {
    send_paid_media_request_chat_id_t *send_paid_media_request_chat_id_local_var = malloc(sizeof(send_paid_media_request_chat_id_t));
    if (!send_paid_media_request_chat_id_local_var) {
        return NULL;
    }

    send_paid_media_request_chat_id_local_var->_library_owned = 1;
    return send_paid_media_request_chat_id_local_var;
}

__attribute__((deprecated)) send_paid_media_request_chat_id_t *send_paid_media_request_chat_id_create(
    ) {
    return send_paid_media_request_chat_id_create_internal (
        );
}

void send_paid_media_request_chat_id_free(send_paid_media_request_chat_id_t *send_paid_media_request_chat_id) {
    if(NULL == send_paid_media_request_chat_id){
        return ;
    }
    if(send_paid_media_request_chat_id->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "send_paid_media_request_chat_id_free");
        return ;
    }
    listEntry_t *listEntry;
    free(send_paid_media_request_chat_id);
}

cJSON *send_paid_media_request_chat_id_convertToJSON(send_paid_media_request_chat_id_t *send_paid_media_request_chat_id) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

send_paid_media_request_chat_id_t *send_paid_media_request_chat_id_parseFromJSON(cJSON *send_paid_media_request_chat_idJSON){

    send_paid_media_request_chat_id_t *send_paid_media_request_chat_id_local_var = NULL;


    send_paid_media_request_chat_id_local_var = send_paid_media_request_chat_id_create_internal (
        );

    return send_paid_media_request_chat_id_local_var;
end:
    return NULL;

}
