#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "force_reply.h"



static force_reply_t *force_reply_create_internal(
    int force_reply,
    char *input_field_placeholder,
    int selective
    ) {
    force_reply_t *force_reply_local_var = malloc(sizeof(force_reply_t));
    if (!force_reply_local_var) {
        return NULL;
    }
    force_reply_local_var->force_reply = force_reply;
    force_reply_local_var->input_field_placeholder = input_field_placeholder;
    force_reply_local_var->selective = selective;

    force_reply_local_var->_library_owned = 1;
    return force_reply_local_var;
}

__attribute__((deprecated)) force_reply_t *force_reply_create(
    int force_reply,
    char *input_field_placeholder,
    int selective
    ) {
    return force_reply_create_internal (
        force_reply,
        input_field_placeholder,
        selective
        );
}

void force_reply_free(force_reply_t *force_reply) {
    if(NULL == force_reply){
        return ;
    }
    if(force_reply->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "force_reply_free");
        return ;
    }
    listEntry_t *listEntry;
    if (force_reply->input_field_placeholder) {
        free(force_reply->input_field_placeholder);
        force_reply->input_field_placeholder = NULL;
    }
    free(force_reply);
}

cJSON *force_reply_convertToJSON(force_reply_t *force_reply) {
    cJSON *item = cJSON_CreateObject();

    // force_reply->force_reply
    if (!force_reply->force_reply) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "force_reply", force_reply->force_reply) == NULL) {
    goto fail; //Bool
    }


    // force_reply->input_field_placeholder
    if(force_reply->input_field_placeholder) {
    if(cJSON_AddStringToObject(item, "input_field_placeholder", force_reply->input_field_placeholder) == NULL) {
    goto fail; //String
    }
    }


    // force_reply->selective
    if(force_reply->selective) {
    if(cJSON_AddBoolToObject(item, "selective", force_reply->selective) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

force_reply_t *force_reply_parseFromJSON(cJSON *force_replyJSON){

    force_reply_t *force_reply_local_var = NULL;

    // force_reply->force_reply
    cJSON *force_reply = cJSON_GetObjectItemCaseSensitive(force_replyJSON, "force_reply");
    if (cJSON_IsNull(force_reply)) {
        force_reply = NULL;
    }
    if (!force_reply) {
        goto end;
    }

    
    if(!cJSON_IsBool(force_reply))
    {
    goto end; //Bool
    }

    // force_reply->input_field_placeholder
    cJSON *input_field_placeholder = cJSON_GetObjectItemCaseSensitive(force_replyJSON, "input_field_placeholder");
    if (cJSON_IsNull(input_field_placeholder)) {
        input_field_placeholder = NULL;
    }
    if (input_field_placeholder) { 
    if(!cJSON_IsString(input_field_placeholder) && !cJSON_IsNull(input_field_placeholder))
    {
    goto end; //String
    }
    }

    // force_reply->selective
    cJSON *selective = cJSON_GetObjectItemCaseSensitive(force_replyJSON, "selective");
    if (cJSON_IsNull(selective)) {
        selective = NULL;
    }
    if (selective) { 
    if(!cJSON_IsBool(selective))
    {
    goto end; //Bool
    }
    }


    force_reply_local_var = force_reply_create_internal (
        force_reply->valueint,
        input_field_placeholder && !cJSON_IsNull(input_field_placeholder) ? strdup(input_field_placeholder->valuestring) : NULL,
        selective ? selective->valueint : 0
        );

    return force_reply_local_var;
end:
    return NULL;

}
