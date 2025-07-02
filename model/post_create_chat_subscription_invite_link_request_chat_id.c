#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_create_chat_subscription_invite_link_request_chat_id.h"



static post_create_chat_subscription_invite_link_request_chat_id_t *post_create_chat_subscription_invite_link_request_chat_id_create_internal(
    ) {
    post_create_chat_subscription_invite_link_request_chat_id_t *post_create_chat_subscription_invite_link_request_chat_id_local_var = malloc(sizeof(post_create_chat_subscription_invite_link_request_chat_id_t));
    if (!post_create_chat_subscription_invite_link_request_chat_id_local_var) {
        return NULL;
    }

    post_create_chat_subscription_invite_link_request_chat_id_local_var->_library_owned = 1;
    return post_create_chat_subscription_invite_link_request_chat_id_local_var;
}

__attribute__((deprecated)) post_create_chat_subscription_invite_link_request_chat_id_t *post_create_chat_subscription_invite_link_request_chat_id_create(
    ) {
    return post_create_chat_subscription_invite_link_request_chat_id_create_internal (
        );
}

void post_create_chat_subscription_invite_link_request_chat_id_free(post_create_chat_subscription_invite_link_request_chat_id_t *post_create_chat_subscription_invite_link_request_chat_id) {
    if(NULL == post_create_chat_subscription_invite_link_request_chat_id){
        return ;
    }
    if(post_create_chat_subscription_invite_link_request_chat_id->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_create_chat_subscription_invite_link_request_chat_id_free");
        return ;
    }
    listEntry_t *listEntry;
    free(post_create_chat_subscription_invite_link_request_chat_id);
}

cJSON *post_create_chat_subscription_invite_link_request_chat_id_convertToJSON(post_create_chat_subscription_invite_link_request_chat_id_t *post_create_chat_subscription_invite_link_request_chat_id) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

post_create_chat_subscription_invite_link_request_chat_id_t *post_create_chat_subscription_invite_link_request_chat_id_parseFromJSON(cJSON *post_create_chat_subscription_invite_link_request_chat_idJSON){

    post_create_chat_subscription_invite_link_request_chat_id_t *post_create_chat_subscription_invite_link_request_chat_id_local_var = NULL;


    post_create_chat_subscription_invite_link_request_chat_id_local_var = post_create_chat_subscription_invite_link_request_chat_id_create_internal (
        );

    return post_create_chat_subscription_invite_link_request_chat_id_local_var;
end:
    return NULL;

}
