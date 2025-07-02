#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "read_business_message_request.h"



static read_business_message_request_t *read_business_message_request_create_internal(
    char *business_connection_id,
    int chat_id,
    int message_id
    ) {
    read_business_message_request_t *read_business_message_request_local_var = malloc(sizeof(read_business_message_request_t));
    if (!read_business_message_request_local_var) {
        return NULL;
    }
    read_business_message_request_local_var->business_connection_id = business_connection_id;
    read_business_message_request_local_var->chat_id = chat_id;
    read_business_message_request_local_var->message_id = message_id;

    read_business_message_request_local_var->_library_owned = 1;
    return read_business_message_request_local_var;
}

__attribute__((deprecated)) read_business_message_request_t *read_business_message_request_create(
    char *business_connection_id,
    int chat_id,
    int message_id
    ) {
    return read_business_message_request_create_internal (
        business_connection_id,
        chat_id,
        message_id
        );
}

void read_business_message_request_free(read_business_message_request_t *read_business_message_request) {
    if(NULL == read_business_message_request){
        return ;
    }
    if(read_business_message_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "read_business_message_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (read_business_message_request->business_connection_id) {
        free(read_business_message_request->business_connection_id);
        read_business_message_request->business_connection_id = NULL;
    }
    free(read_business_message_request);
}

cJSON *read_business_message_request_convertToJSON(read_business_message_request_t *read_business_message_request) {
    cJSON *item = cJSON_CreateObject();

    // read_business_message_request->business_connection_id
    if (!read_business_message_request->business_connection_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "business_connection_id", read_business_message_request->business_connection_id) == NULL) {
    goto fail; //String
    }


    // read_business_message_request->chat_id
    if (!read_business_message_request->chat_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "chat_id", read_business_message_request->chat_id) == NULL) {
    goto fail; //Numeric
    }


    // read_business_message_request->message_id
    if (!read_business_message_request->message_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "message_id", read_business_message_request->message_id) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

read_business_message_request_t *read_business_message_request_parseFromJSON(cJSON *read_business_message_requestJSON){

    read_business_message_request_t *read_business_message_request_local_var = NULL;

    // read_business_message_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(read_business_message_requestJSON, "business_connection_id");
    if (cJSON_IsNull(business_connection_id)) {
        business_connection_id = NULL;
    }
    if (!business_connection_id) {
        goto end;
    }

    
    if(!cJSON_IsString(business_connection_id))
    {
    goto end; //String
    }

    // read_business_message_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(read_business_message_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    if(!cJSON_IsNumber(chat_id))
    {
    goto end; //Numeric
    }

    // read_business_message_request->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(read_business_message_requestJSON, "message_id");
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


    read_business_message_request_local_var = read_business_message_request_create_internal (
        strdup(business_connection_id->valuestring),
        chat_id->valuedouble,
        message_id->valuedouble
        );

    return read_business_message_request_local_var;
end:
    return NULL;

}
