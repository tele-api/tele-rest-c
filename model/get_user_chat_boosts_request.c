#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "get_user_chat_boosts_request.h"



static get_user_chat_boosts_request_t *get_user_chat_boosts_request_create_internal(
    get_user_chat_boosts_request_chat_id_t *chat_id,
    int user_id
    ) {
    get_user_chat_boosts_request_t *get_user_chat_boosts_request_local_var = malloc(sizeof(get_user_chat_boosts_request_t));
    if (!get_user_chat_boosts_request_local_var) {
        return NULL;
    }
    get_user_chat_boosts_request_local_var->chat_id = chat_id;
    get_user_chat_boosts_request_local_var->user_id = user_id;

    get_user_chat_boosts_request_local_var->_library_owned = 1;
    return get_user_chat_boosts_request_local_var;
}

__attribute__((deprecated)) get_user_chat_boosts_request_t *get_user_chat_boosts_request_create(
    get_user_chat_boosts_request_chat_id_t *chat_id,
    int user_id
    ) {
    return get_user_chat_boosts_request_create_internal (
        chat_id,
        user_id
        );
}

void get_user_chat_boosts_request_free(get_user_chat_boosts_request_t *get_user_chat_boosts_request) {
    if(NULL == get_user_chat_boosts_request){
        return ;
    }
    if(get_user_chat_boosts_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "get_user_chat_boosts_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (get_user_chat_boosts_request->chat_id) {
        get_user_chat_boosts_request_chat_id_free(get_user_chat_boosts_request->chat_id);
        get_user_chat_boosts_request->chat_id = NULL;
    }
    free(get_user_chat_boosts_request);
}

cJSON *get_user_chat_boosts_request_convertToJSON(get_user_chat_boosts_request_t *get_user_chat_boosts_request) {
    cJSON *item = cJSON_CreateObject();

    // get_user_chat_boosts_request->chat_id
    if (!get_user_chat_boosts_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = get_user_chat_boosts_request_chat_id_convertToJSON(get_user_chat_boosts_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // get_user_chat_boosts_request->user_id
    if (!get_user_chat_boosts_request->user_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "user_id", get_user_chat_boosts_request->user_id) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

get_user_chat_boosts_request_t *get_user_chat_boosts_request_parseFromJSON(cJSON *get_user_chat_boosts_requestJSON){

    get_user_chat_boosts_request_t *get_user_chat_boosts_request_local_var = NULL;

    // define the local variable for get_user_chat_boosts_request->chat_id
    get_user_chat_boosts_request_chat_id_t *chat_id_local_nonprim = NULL;

    // get_user_chat_boosts_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(get_user_chat_boosts_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = get_user_chat_boosts_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // get_user_chat_boosts_request->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(get_user_chat_boosts_requestJSON, "user_id");
    if (cJSON_IsNull(user_id)) {
        user_id = NULL;
    }
    if (!user_id) {
        goto end;
    }

    
    if(!cJSON_IsNumber(user_id))
    {
    goto end; //Numeric
    }


    get_user_chat_boosts_request_local_var = get_user_chat_boosts_request_create_internal (
        chat_id_local_nonprim,
        user_id->valuedouble
        );

    return get_user_chat_boosts_request_local_var;
end:
    if (chat_id_local_nonprim) {
        get_user_chat_boosts_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
