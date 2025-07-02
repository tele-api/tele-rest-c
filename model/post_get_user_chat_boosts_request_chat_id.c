#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_get_user_chat_boosts_request_chat_id.h"



static post_get_user_chat_boosts_request_chat_id_t *post_get_user_chat_boosts_request_chat_id_create_internal(
    ) {
    post_get_user_chat_boosts_request_chat_id_t *post_get_user_chat_boosts_request_chat_id_local_var = malloc(sizeof(post_get_user_chat_boosts_request_chat_id_t));
    if (!post_get_user_chat_boosts_request_chat_id_local_var) {
        return NULL;
    }

    post_get_user_chat_boosts_request_chat_id_local_var->_library_owned = 1;
    return post_get_user_chat_boosts_request_chat_id_local_var;
}

__attribute__((deprecated)) post_get_user_chat_boosts_request_chat_id_t *post_get_user_chat_boosts_request_chat_id_create(
    ) {
    return post_get_user_chat_boosts_request_chat_id_create_internal (
        );
}

void post_get_user_chat_boosts_request_chat_id_free(post_get_user_chat_boosts_request_chat_id_t *post_get_user_chat_boosts_request_chat_id) {
    if(NULL == post_get_user_chat_boosts_request_chat_id){
        return ;
    }
    if(post_get_user_chat_boosts_request_chat_id->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_get_user_chat_boosts_request_chat_id_free");
        return ;
    }
    listEntry_t *listEntry;
    free(post_get_user_chat_boosts_request_chat_id);
}

cJSON *post_get_user_chat_boosts_request_chat_id_convertToJSON(post_get_user_chat_boosts_request_chat_id_t *post_get_user_chat_boosts_request_chat_id) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

post_get_user_chat_boosts_request_chat_id_t *post_get_user_chat_boosts_request_chat_id_parseFromJSON(cJSON *post_get_user_chat_boosts_request_chat_idJSON){

    post_get_user_chat_boosts_request_chat_id_t *post_get_user_chat_boosts_request_chat_id_local_var = NULL;


    post_get_user_chat_boosts_request_chat_id_local_var = post_get_user_chat_boosts_request_chat_id_create_internal (
        );

    return post_get_user_chat_boosts_request_chat_id_local_var;
end:
    return NULL;

}
