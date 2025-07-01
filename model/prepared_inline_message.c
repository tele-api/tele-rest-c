#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "prepared_inline_message.h"



static prepared_inline_message_t *prepared_inline_message_create_internal(
    char *id,
    int expiration_date
    ) {
    prepared_inline_message_t *prepared_inline_message_local_var = malloc(sizeof(prepared_inline_message_t));
    if (!prepared_inline_message_local_var) {
        return NULL;
    }
    prepared_inline_message_local_var->id = id;
    prepared_inline_message_local_var->expiration_date = expiration_date;

    prepared_inline_message_local_var->_library_owned = 1;
    return prepared_inline_message_local_var;
}

__attribute__((deprecated)) prepared_inline_message_t *prepared_inline_message_create(
    char *id,
    int expiration_date
    ) {
    return prepared_inline_message_create_internal (
        id,
        expiration_date
        );
}

void prepared_inline_message_free(prepared_inline_message_t *prepared_inline_message) {
    if(NULL == prepared_inline_message){
        return ;
    }
    if(prepared_inline_message->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "prepared_inline_message_free");
        return ;
    }
    listEntry_t *listEntry;
    if (prepared_inline_message->id) {
        free(prepared_inline_message->id);
        prepared_inline_message->id = NULL;
    }
    free(prepared_inline_message);
}

cJSON *prepared_inline_message_convertToJSON(prepared_inline_message_t *prepared_inline_message) {
    cJSON *item = cJSON_CreateObject();

    // prepared_inline_message->id
    if (!prepared_inline_message->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", prepared_inline_message->id) == NULL) {
    goto fail; //String
    }


    // prepared_inline_message->expiration_date
    if (!prepared_inline_message->expiration_date) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "expiration_date", prepared_inline_message->expiration_date) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

prepared_inline_message_t *prepared_inline_message_parseFromJSON(cJSON *prepared_inline_messageJSON){

    prepared_inline_message_t *prepared_inline_message_local_var = NULL;

    // prepared_inline_message->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(prepared_inline_messageJSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (!id) {
        goto end;
    }

    
    if(!cJSON_IsString(id))
    {
    goto end; //String
    }

    // prepared_inline_message->expiration_date
    cJSON *expiration_date = cJSON_GetObjectItemCaseSensitive(prepared_inline_messageJSON, "expiration_date");
    if (cJSON_IsNull(expiration_date)) {
        expiration_date = NULL;
    }
    if (!expiration_date) {
        goto end;
    }

    
    if(!cJSON_IsNumber(expiration_date))
    {
    goto end; //Numeric
    }


    prepared_inline_message_local_var = prepared_inline_message_create_internal (
        strdup(id->valuestring),
        expiration_date->valuedouble
        );

    return prepared_inline_message_local_var;
end:
    return NULL;

}
