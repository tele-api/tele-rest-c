#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "inaccessible_message.h"



static inaccessible_message_t *inaccessible_message_create_internal(
    chat_t *chat,
    int message_id,
    int date
    ) {
    inaccessible_message_t *inaccessible_message_local_var = malloc(sizeof(inaccessible_message_t));
    if (!inaccessible_message_local_var) {
        return NULL;
    }
    inaccessible_message_local_var->chat = chat;
    inaccessible_message_local_var->message_id = message_id;
    inaccessible_message_local_var->date = date;

    inaccessible_message_local_var->_library_owned = 1;
    return inaccessible_message_local_var;
}

__attribute__((deprecated)) inaccessible_message_t *inaccessible_message_create(
    chat_t *chat,
    int message_id,
    int date
    ) {
    return inaccessible_message_create_internal (
        chat,
        message_id,
        date
        );
}

void inaccessible_message_free(inaccessible_message_t *inaccessible_message) {
    if(NULL == inaccessible_message){
        return ;
    }
    if(inaccessible_message->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "inaccessible_message_free");
        return ;
    }
    listEntry_t *listEntry;
    if (inaccessible_message->chat) {
        chat_free(inaccessible_message->chat);
        inaccessible_message->chat = NULL;
    }
    free(inaccessible_message);
}

cJSON *inaccessible_message_convertToJSON(inaccessible_message_t *inaccessible_message) {
    cJSON *item = cJSON_CreateObject();

    // inaccessible_message->chat
    if (!inaccessible_message->chat) {
        goto fail;
    }
    cJSON *chat_local_JSON = chat_convertToJSON(inaccessible_message->chat);
    if(chat_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat", chat_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // inaccessible_message->message_id
    if (!inaccessible_message->message_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "message_id", inaccessible_message->message_id) == NULL) {
    goto fail; //Numeric
    }


    // inaccessible_message->date
    if (!inaccessible_message->date) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "date", inaccessible_message->date) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

inaccessible_message_t *inaccessible_message_parseFromJSON(cJSON *inaccessible_messageJSON){

    inaccessible_message_t *inaccessible_message_local_var = NULL;

    // define the local variable for inaccessible_message->chat
    chat_t *chat_local_nonprim = NULL;

    // inaccessible_message->chat
    cJSON *chat = cJSON_GetObjectItemCaseSensitive(inaccessible_messageJSON, "chat");
    if (cJSON_IsNull(chat)) {
        chat = NULL;
    }
    if (!chat) {
        goto end;
    }

    
    chat_local_nonprim = chat_parseFromJSON(chat); //nonprimitive

    // inaccessible_message->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(inaccessible_messageJSON, "message_id");
    if (cJSON_IsNull(message_id)) {
        message_id = NULL;
    }
    if (!message_id) {
        goto end;
    }

    
    if(!cJSON_IsNumber(message_id))
    {
    goto end; //Numeric
    }

    // inaccessible_message->date
    cJSON *date = cJSON_GetObjectItemCaseSensitive(inaccessible_messageJSON, "date");
    if (cJSON_IsNull(date)) {
        date = NULL;
    }
    if (!date) {
        goto end;
    }

    
    if(!cJSON_IsNumber(date))
    {
    goto end; //Numeric
    }


    inaccessible_message_local_var = inaccessible_message_create_internal (
        chat_local_nonprim,
        message_id->valuedouble,
        date->valuedouble
        );

    return inaccessible_message_local_var;
end:
    if (chat_local_nonprim) {
        chat_free(chat_local_nonprim);
        chat_local_nonprim = NULL;
    }
    return NULL;

}
