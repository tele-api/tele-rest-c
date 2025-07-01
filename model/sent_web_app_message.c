#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "sent_web_app_message.h"



static sent_web_app_message_t *sent_web_app_message_create_internal(
    char *inline_message_id
    ) {
    sent_web_app_message_t *sent_web_app_message_local_var = malloc(sizeof(sent_web_app_message_t));
    if (!sent_web_app_message_local_var) {
        return NULL;
    }
    sent_web_app_message_local_var->inline_message_id = inline_message_id;

    sent_web_app_message_local_var->_library_owned = 1;
    return sent_web_app_message_local_var;
}

__attribute__((deprecated)) sent_web_app_message_t *sent_web_app_message_create(
    char *inline_message_id
    ) {
    return sent_web_app_message_create_internal (
        inline_message_id
        );
}

void sent_web_app_message_free(sent_web_app_message_t *sent_web_app_message) {
    if(NULL == sent_web_app_message){
        return ;
    }
    if(sent_web_app_message->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "sent_web_app_message_free");
        return ;
    }
    listEntry_t *listEntry;
    if (sent_web_app_message->inline_message_id) {
        free(sent_web_app_message->inline_message_id);
        sent_web_app_message->inline_message_id = NULL;
    }
    free(sent_web_app_message);
}

cJSON *sent_web_app_message_convertToJSON(sent_web_app_message_t *sent_web_app_message) {
    cJSON *item = cJSON_CreateObject();

    // sent_web_app_message->inline_message_id
    if(sent_web_app_message->inline_message_id) {
    if(cJSON_AddStringToObject(item, "inline_message_id", sent_web_app_message->inline_message_id) == NULL) {
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

sent_web_app_message_t *sent_web_app_message_parseFromJSON(cJSON *sent_web_app_messageJSON){

    sent_web_app_message_t *sent_web_app_message_local_var = NULL;

    // sent_web_app_message->inline_message_id
    cJSON *inline_message_id = cJSON_GetObjectItemCaseSensitive(sent_web_app_messageJSON, "inline_message_id");
    if (cJSON_IsNull(inline_message_id)) {
        inline_message_id = NULL;
    }
    if (inline_message_id) { 
    if(!cJSON_IsString(inline_message_id) && !cJSON_IsNull(inline_message_id))
    {
    goto end; //String
    }
    }


    sent_web_app_message_local_var = sent_web_app_message_create_internal (
        inline_message_id && !cJSON_IsNull(inline_message_id) ? strdup(inline_message_id->valuestring) : NULL
        );

    return sent_web_app_message_local_var;
end:
    return NULL;

}
