#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "set_chat_description_request.h"



static set_chat_description_request_t *set_chat_description_request_create_internal(
    send_message_request_chat_id_t *chat_id,
    char *description
    ) {
    set_chat_description_request_t *set_chat_description_request_local_var = malloc(sizeof(set_chat_description_request_t));
    if (!set_chat_description_request_local_var) {
        return NULL;
    }
    set_chat_description_request_local_var->chat_id = chat_id;
    set_chat_description_request_local_var->description = description;

    set_chat_description_request_local_var->_library_owned = 1;
    return set_chat_description_request_local_var;
}

__attribute__((deprecated)) set_chat_description_request_t *set_chat_description_request_create(
    send_message_request_chat_id_t *chat_id,
    char *description
    ) {
    return set_chat_description_request_create_internal (
        chat_id,
        description
        );
}

void set_chat_description_request_free(set_chat_description_request_t *set_chat_description_request) {
    if(NULL == set_chat_description_request){
        return ;
    }
    if(set_chat_description_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "set_chat_description_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (set_chat_description_request->chat_id) {
        send_message_request_chat_id_free(set_chat_description_request->chat_id);
        set_chat_description_request->chat_id = NULL;
    }
    if (set_chat_description_request->description) {
        free(set_chat_description_request->description);
        set_chat_description_request->description = NULL;
    }
    free(set_chat_description_request);
}

cJSON *set_chat_description_request_convertToJSON(set_chat_description_request_t *set_chat_description_request) {
    cJSON *item = cJSON_CreateObject();

    // set_chat_description_request->chat_id
    if (!set_chat_description_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = send_message_request_chat_id_convertToJSON(set_chat_description_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // set_chat_description_request->description
    if(set_chat_description_request->description) {
    if(cJSON_AddStringToObject(item, "description", set_chat_description_request->description) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

set_chat_description_request_t *set_chat_description_request_parseFromJSON(cJSON *set_chat_description_requestJSON){

    set_chat_description_request_t *set_chat_description_request_local_var = NULL;

    // define the local variable for set_chat_description_request->chat_id
    send_message_request_chat_id_t *chat_id_local_nonprim = NULL;

    // set_chat_description_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(set_chat_description_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = send_message_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // set_chat_description_request->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(set_chat_description_requestJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (description) { 
    if(!cJSON_IsString(description) && !cJSON_IsNull(description))
    {
    goto end; //String
    }
    }


    set_chat_description_request_local_var = set_chat_description_request_create_internal (
        chat_id_local_nonprim,
        description && !cJSON_IsNull(description) ? strdup(description->valuestring) : NULL
        );

    return set_chat_description_request_local_var;
end:
    if (chat_id_local_nonprim) {
        send_message_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
