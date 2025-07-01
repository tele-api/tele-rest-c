#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "chat_boost_updated.h"



static chat_boost_updated_t *chat_boost_updated_create_internal(
    chat_t *chat,
    chat_boost_t *boost
    ) {
    chat_boost_updated_t *chat_boost_updated_local_var = malloc(sizeof(chat_boost_updated_t));
    if (!chat_boost_updated_local_var) {
        return NULL;
    }
    chat_boost_updated_local_var->chat = chat;
    chat_boost_updated_local_var->boost = boost;

    chat_boost_updated_local_var->_library_owned = 1;
    return chat_boost_updated_local_var;
}

__attribute__((deprecated)) chat_boost_updated_t *chat_boost_updated_create(
    chat_t *chat,
    chat_boost_t *boost
    ) {
    return chat_boost_updated_create_internal (
        chat,
        boost
        );
}

void chat_boost_updated_free(chat_boost_updated_t *chat_boost_updated) {
    if(NULL == chat_boost_updated){
        return ;
    }
    if(chat_boost_updated->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "chat_boost_updated_free");
        return ;
    }
    listEntry_t *listEntry;
    if (chat_boost_updated->chat) {
        chat_free(chat_boost_updated->chat);
        chat_boost_updated->chat = NULL;
    }
    if (chat_boost_updated->boost) {
        chat_boost_free(chat_boost_updated->boost);
        chat_boost_updated->boost = NULL;
    }
    free(chat_boost_updated);
}

cJSON *chat_boost_updated_convertToJSON(chat_boost_updated_t *chat_boost_updated) {
    cJSON *item = cJSON_CreateObject();

    // chat_boost_updated->chat
    if (!chat_boost_updated->chat) {
        goto fail;
    }
    cJSON *chat_local_JSON = chat_convertToJSON(chat_boost_updated->chat);
    if(chat_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat", chat_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // chat_boost_updated->boost
    if (!chat_boost_updated->boost) {
        goto fail;
    }
    cJSON *boost_local_JSON = chat_boost_convertToJSON(chat_boost_updated->boost);
    if(boost_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "boost", boost_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

chat_boost_updated_t *chat_boost_updated_parseFromJSON(cJSON *chat_boost_updatedJSON){

    chat_boost_updated_t *chat_boost_updated_local_var = NULL;

    // define the local variable for chat_boost_updated->chat
    chat_t *chat_local_nonprim = NULL;

    // define the local variable for chat_boost_updated->boost
    chat_boost_t *boost_local_nonprim = NULL;

    // chat_boost_updated->chat
    cJSON *chat = cJSON_GetObjectItemCaseSensitive(chat_boost_updatedJSON, "chat");
    if (cJSON_IsNull(chat)) {
        chat = NULL;
    }
    if (!chat) {
        goto end;
    }

    
    chat_local_nonprim = chat_parseFromJSON(chat); //nonprimitive

    // chat_boost_updated->boost
    cJSON *boost = cJSON_GetObjectItemCaseSensitive(chat_boost_updatedJSON, "boost");
    if (cJSON_IsNull(boost)) {
        boost = NULL;
    }
    if (!boost) {
        goto end;
    }

    
    boost_local_nonprim = chat_boost_parseFromJSON(boost); //nonprimitive


    chat_boost_updated_local_var = chat_boost_updated_create_internal (
        chat_local_nonprim,
        boost_local_nonprim
        );

    return chat_boost_updated_local_var;
end:
    if (chat_local_nonprim) {
        chat_free(chat_local_nonprim);
        chat_local_nonprim = NULL;
    }
    if (boost_local_nonprim) {
        chat_boost_free(boost_local_nonprim);
        boost_local_nonprim = NULL;
    }
    return NULL;

}
