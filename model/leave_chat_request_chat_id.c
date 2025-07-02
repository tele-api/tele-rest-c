#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "leave_chat_request_chat_id.h"



static leave_chat_request_chat_id_t *leave_chat_request_chat_id_create_internal(
    ) {
    leave_chat_request_chat_id_t *leave_chat_request_chat_id_local_var = malloc(sizeof(leave_chat_request_chat_id_t));
    if (!leave_chat_request_chat_id_local_var) {
        return NULL;
    }

    leave_chat_request_chat_id_local_var->_library_owned = 1;
    return leave_chat_request_chat_id_local_var;
}

__attribute__((deprecated)) leave_chat_request_chat_id_t *leave_chat_request_chat_id_create(
    ) {
    return leave_chat_request_chat_id_create_internal (
        );
}

void leave_chat_request_chat_id_free(leave_chat_request_chat_id_t *leave_chat_request_chat_id) {
    if(NULL == leave_chat_request_chat_id){
        return ;
    }
    if(leave_chat_request_chat_id->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "leave_chat_request_chat_id_free");
        return ;
    }
    listEntry_t *listEntry;
    free(leave_chat_request_chat_id);
}

cJSON *leave_chat_request_chat_id_convertToJSON(leave_chat_request_chat_id_t *leave_chat_request_chat_id) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

leave_chat_request_chat_id_t *leave_chat_request_chat_id_parseFromJSON(cJSON *leave_chat_request_chat_idJSON){

    leave_chat_request_chat_id_t *leave_chat_request_chat_id_local_var = NULL;


    leave_chat_request_chat_id_local_var = leave_chat_request_chat_id_create_internal (
        );

    return leave_chat_request_chat_id_local_var;
end:
    return NULL;

}
