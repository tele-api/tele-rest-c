#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "get_user_chat_boosts_request_chat_id.h"



static get_user_chat_boosts_request_chat_id_t *get_user_chat_boosts_request_chat_id_create_internal(
    ) {
    get_user_chat_boosts_request_chat_id_t *get_user_chat_boosts_request_chat_id_local_var = malloc(sizeof(get_user_chat_boosts_request_chat_id_t));
    if (!get_user_chat_boosts_request_chat_id_local_var) {
        return NULL;
    }

    get_user_chat_boosts_request_chat_id_local_var->_library_owned = 1;
    return get_user_chat_boosts_request_chat_id_local_var;
}

__attribute__((deprecated)) get_user_chat_boosts_request_chat_id_t *get_user_chat_boosts_request_chat_id_create(
    ) {
    return get_user_chat_boosts_request_chat_id_create_internal (
        );
}

void get_user_chat_boosts_request_chat_id_free(get_user_chat_boosts_request_chat_id_t *get_user_chat_boosts_request_chat_id) {
    if(NULL == get_user_chat_boosts_request_chat_id){
        return ;
    }
    if(get_user_chat_boosts_request_chat_id->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "get_user_chat_boosts_request_chat_id_free");
        return ;
    }
    listEntry_t *listEntry;
    free(get_user_chat_boosts_request_chat_id);
}

cJSON *get_user_chat_boosts_request_chat_id_convertToJSON(get_user_chat_boosts_request_chat_id_t *get_user_chat_boosts_request_chat_id) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

get_user_chat_boosts_request_chat_id_t *get_user_chat_boosts_request_chat_id_parseFromJSON(cJSON *get_user_chat_boosts_request_chat_idJSON){

    get_user_chat_boosts_request_chat_id_t *get_user_chat_boosts_request_chat_id_local_var = NULL;


    get_user_chat_boosts_request_chat_id_local_var = get_user_chat_boosts_request_chat_id_create_internal (
        );

    return get_user_chat_boosts_request_chat_id_local_var;
end:
    return NULL;

}
