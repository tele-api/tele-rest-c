#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ban_chat_member_request_chat_id.h"



static ban_chat_member_request_chat_id_t *ban_chat_member_request_chat_id_create_internal(
    ) {
    ban_chat_member_request_chat_id_t *ban_chat_member_request_chat_id_local_var = malloc(sizeof(ban_chat_member_request_chat_id_t));
    if (!ban_chat_member_request_chat_id_local_var) {
        return NULL;
    }

    ban_chat_member_request_chat_id_local_var->_library_owned = 1;
    return ban_chat_member_request_chat_id_local_var;
}

__attribute__((deprecated)) ban_chat_member_request_chat_id_t *ban_chat_member_request_chat_id_create(
    ) {
    return ban_chat_member_request_chat_id_create_internal (
        );
}

void ban_chat_member_request_chat_id_free(ban_chat_member_request_chat_id_t *ban_chat_member_request_chat_id) {
    if(NULL == ban_chat_member_request_chat_id){
        return ;
    }
    if(ban_chat_member_request_chat_id->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ban_chat_member_request_chat_id_free");
        return ;
    }
    listEntry_t *listEntry;
    free(ban_chat_member_request_chat_id);
}

cJSON *ban_chat_member_request_chat_id_convertToJSON(ban_chat_member_request_chat_id_t *ban_chat_member_request_chat_id) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

ban_chat_member_request_chat_id_t *ban_chat_member_request_chat_id_parseFromJSON(cJSON *ban_chat_member_request_chat_idJSON){

    ban_chat_member_request_chat_id_t *ban_chat_member_request_chat_id_local_var = NULL;


    ban_chat_member_request_chat_id_local_var = ban_chat_member_request_chat_id_create_internal (
        );

    return ban_chat_member_request_chat_id_local_var;
end:
    return NULL;

}
