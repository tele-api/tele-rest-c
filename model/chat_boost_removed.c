#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "chat_boost_removed.h"



static chat_boost_removed_t *chat_boost_removed_create_internal(
    chat_t *chat,
    char *boost_id,
    int remove_date,
    chat_boost_source_t *source
    ) {
    chat_boost_removed_t *chat_boost_removed_local_var = malloc(sizeof(chat_boost_removed_t));
    if (!chat_boost_removed_local_var) {
        return NULL;
    }
    chat_boost_removed_local_var->chat = chat;
    chat_boost_removed_local_var->boost_id = boost_id;
    chat_boost_removed_local_var->remove_date = remove_date;
    chat_boost_removed_local_var->source = source;

    chat_boost_removed_local_var->_library_owned = 1;
    return chat_boost_removed_local_var;
}

__attribute__((deprecated)) chat_boost_removed_t *chat_boost_removed_create(
    chat_t *chat,
    char *boost_id,
    int remove_date,
    chat_boost_source_t *source
    ) {
    return chat_boost_removed_create_internal (
        chat,
        boost_id,
        remove_date,
        source
        );
}

void chat_boost_removed_free(chat_boost_removed_t *chat_boost_removed) {
    if(NULL == chat_boost_removed){
        return ;
    }
    if(chat_boost_removed->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "chat_boost_removed_free");
        return ;
    }
    listEntry_t *listEntry;
    if (chat_boost_removed->chat) {
        chat_free(chat_boost_removed->chat);
        chat_boost_removed->chat = NULL;
    }
    if (chat_boost_removed->boost_id) {
        free(chat_boost_removed->boost_id);
        chat_boost_removed->boost_id = NULL;
    }
    if (chat_boost_removed->source) {
        chat_boost_source_free(chat_boost_removed->source);
        chat_boost_removed->source = NULL;
    }
    free(chat_boost_removed);
}

cJSON *chat_boost_removed_convertToJSON(chat_boost_removed_t *chat_boost_removed) {
    cJSON *item = cJSON_CreateObject();

    // chat_boost_removed->chat
    if (!chat_boost_removed->chat) {
        goto fail;
    }
    cJSON *chat_local_JSON = chat_convertToJSON(chat_boost_removed->chat);
    if(chat_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat", chat_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // chat_boost_removed->boost_id
    if (!chat_boost_removed->boost_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "boost_id", chat_boost_removed->boost_id) == NULL) {
    goto fail; //String
    }


    // chat_boost_removed->remove_date
    if (!chat_boost_removed->remove_date) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "remove_date", chat_boost_removed->remove_date) == NULL) {
    goto fail; //Numeric
    }


    // chat_boost_removed->source
    if (!chat_boost_removed->source) {
        goto fail;
    }
    cJSON *source_local_JSON = chat_boost_source_convertToJSON(chat_boost_removed->source);
    if(source_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "source", source_local_JSON);
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

chat_boost_removed_t *chat_boost_removed_parseFromJSON(cJSON *chat_boost_removedJSON){

    chat_boost_removed_t *chat_boost_removed_local_var = NULL;

    // define the local variable for chat_boost_removed->chat
    chat_t *chat_local_nonprim = NULL;

    // define the local variable for chat_boost_removed->source
    chat_boost_source_t *source_local_nonprim = NULL;

    // chat_boost_removed->chat
    cJSON *chat = cJSON_GetObjectItemCaseSensitive(chat_boost_removedJSON, "chat");
    if (cJSON_IsNull(chat)) {
        chat = NULL;
    }
    if (!chat) {
        goto end;
    }

    
    chat_local_nonprim = chat_parseFromJSON(chat); //nonprimitive

    // chat_boost_removed->boost_id
    cJSON *boost_id = cJSON_GetObjectItemCaseSensitive(chat_boost_removedJSON, "boost_id");
    if (cJSON_IsNull(boost_id)) {
        boost_id = NULL;
    }
    if (!boost_id) {
        goto end;
    }

    
    if(!cJSON_IsString(boost_id))
    {
    goto end; //String
    }

    // chat_boost_removed->remove_date
    cJSON *remove_date = cJSON_GetObjectItemCaseSensitive(chat_boost_removedJSON, "remove_date");
    if (cJSON_IsNull(remove_date)) {
        remove_date = NULL;
    }
    if (!remove_date) {
        goto end;
    }

    
    if(!cJSON_IsNumber(remove_date))
    {
    goto end; //Numeric
    }

    // chat_boost_removed->source
    cJSON *source = cJSON_GetObjectItemCaseSensitive(chat_boost_removedJSON, "source");
    if (cJSON_IsNull(source)) {
        source = NULL;
    }
    if (!source) {
        goto end;
    }

    
    source_local_nonprim = chat_boost_source_parseFromJSON(source); //nonprimitive


    chat_boost_removed_local_var = chat_boost_removed_create_internal (
        chat_local_nonprim,
        strdup(boost_id->valuestring),
        remove_date->valuedouble,
        source_local_nonprim
        );

    return chat_boost_removed_local_var;
end:
    if (chat_local_nonprim) {
        chat_free(chat_local_nonprim);
        chat_local_nonprim = NULL;
    }
    if (source_local_nonprim) {
        chat_boost_source_free(source_local_nonprim);
        source_local_nonprim = NULL;
    }
    return NULL;

}
