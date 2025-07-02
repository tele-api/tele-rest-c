#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "create_chat_subscription_invite_link_request_chat_id.h"



static create_chat_subscription_invite_link_request_chat_id_t *create_chat_subscription_invite_link_request_chat_id_create_internal(
    ) {
    create_chat_subscription_invite_link_request_chat_id_t *create_chat_subscription_invite_link_request_chat_id_local_var = malloc(sizeof(create_chat_subscription_invite_link_request_chat_id_t));
    if (!create_chat_subscription_invite_link_request_chat_id_local_var) {
        return NULL;
    }

    create_chat_subscription_invite_link_request_chat_id_local_var->_library_owned = 1;
    return create_chat_subscription_invite_link_request_chat_id_local_var;
}

__attribute__((deprecated)) create_chat_subscription_invite_link_request_chat_id_t *create_chat_subscription_invite_link_request_chat_id_create(
    ) {
    return create_chat_subscription_invite_link_request_chat_id_create_internal (
        );
}

void create_chat_subscription_invite_link_request_chat_id_free(create_chat_subscription_invite_link_request_chat_id_t *create_chat_subscription_invite_link_request_chat_id) {
    if(NULL == create_chat_subscription_invite_link_request_chat_id){
        return ;
    }
    if(create_chat_subscription_invite_link_request_chat_id->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "create_chat_subscription_invite_link_request_chat_id_free");
        return ;
    }
    listEntry_t *listEntry;
    free(create_chat_subscription_invite_link_request_chat_id);
}

cJSON *create_chat_subscription_invite_link_request_chat_id_convertToJSON(create_chat_subscription_invite_link_request_chat_id_t *create_chat_subscription_invite_link_request_chat_id) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

create_chat_subscription_invite_link_request_chat_id_t *create_chat_subscription_invite_link_request_chat_id_parseFromJSON(cJSON *create_chat_subscription_invite_link_request_chat_idJSON){

    create_chat_subscription_invite_link_request_chat_id_t *create_chat_subscription_invite_link_request_chat_id_local_var = NULL;


    create_chat_subscription_invite_link_request_chat_id_local_var = create_chat_subscription_invite_link_request_chat_id_create_internal (
        );

    return create_chat_subscription_invite_link_request_chat_id_local_var;
end:
    return NULL;

}
