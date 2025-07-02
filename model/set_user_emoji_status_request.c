#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "set_user_emoji_status_request.h"



static set_user_emoji_status_request_t *set_user_emoji_status_request_create_internal(
    int user_id,
    char *emoji_status_custom_emoji_id,
    int emoji_status_expiration_date
    ) {
    set_user_emoji_status_request_t *set_user_emoji_status_request_local_var = malloc(sizeof(set_user_emoji_status_request_t));
    if (!set_user_emoji_status_request_local_var) {
        return NULL;
    }
    set_user_emoji_status_request_local_var->user_id = user_id;
    set_user_emoji_status_request_local_var->emoji_status_custom_emoji_id = emoji_status_custom_emoji_id;
    set_user_emoji_status_request_local_var->emoji_status_expiration_date = emoji_status_expiration_date;

    set_user_emoji_status_request_local_var->_library_owned = 1;
    return set_user_emoji_status_request_local_var;
}

__attribute__((deprecated)) set_user_emoji_status_request_t *set_user_emoji_status_request_create(
    int user_id,
    char *emoji_status_custom_emoji_id,
    int emoji_status_expiration_date
    ) {
    return set_user_emoji_status_request_create_internal (
        user_id,
        emoji_status_custom_emoji_id,
        emoji_status_expiration_date
        );
}

void set_user_emoji_status_request_free(set_user_emoji_status_request_t *set_user_emoji_status_request) {
    if(NULL == set_user_emoji_status_request){
        return ;
    }
    if(set_user_emoji_status_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "set_user_emoji_status_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (set_user_emoji_status_request->emoji_status_custom_emoji_id) {
        free(set_user_emoji_status_request->emoji_status_custom_emoji_id);
        set_user_emoji_status_request->emoji_status_custom_emoji_id = NULL;
    }
    free(set_user_emoji_status_request);
}

cJSON *set_user_emoji_status_request_convertToJSON(set_user_emoji_status_request_t *set_user_emoji_status_request) {
    cJSON *item = cJSON_CreateObject();

    // set_user_emoji_status_request->user_id
    if (!set_user_emoji_status_request->user_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "user_id", set_user_emoji_status_request->user_id) == NULL) {
    goto fail; //Numeric
    }


    // set_user_emoji_status_request->emoji_status_custom_emoji_id
    if(set_user_emoji_status_request->emoji_status_custom_emoji_id) {
    if(cJSON_AddStringToObject(item, "emoji_status_custom_emoji_id", set_user_emoji_status_request->emoji_status_custom_emoji_id) == NULL) {
    goto fail; //String
    }
    }


    // set_user_emoji_status_request->emoji_status_expiration_date
    if(set_user_emoji_status_request->emoji_status_expiration_date) {
    if(cJSON_AddNumberToObject(item, "emoji_status_expiration_date", set_user_emoji_status_request->emoji_status_expiration_date) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

set_user_emoji_status_request_t *set_user_emoji_status_request_parseFromJSON(cJSON *set_user_emoji_status_requestJSON){

    set_user_emoji_status_request_t *set_user_emoji_status_request_local_var = NULL;

    // set_user_emoji_status_request->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(set_user_emoji_status_requestJSON, "user_id");
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

    // set_user_emoji_status_request->emoji_status_custom_emoji_id
    cJSON *emoji_status_custom_emoji_id = cJSON_GetObjectItemCaseSensitive(set_user_emoji_status_requestJSON, "emoji_status_custom_emoji_id");
    if (cJSON_IsNull(emoji_status_custom_emoji_id)) {
        emoji_status_custom_emoji_id = NULL;
    }
    if (emoji_status_custom_emoji_id) { 
    if(!cJSON_IsString(emoji_status_custom_emoji_id) && !cJSON_IsNull(emoji_status_custom_emoji_id))
    {
    goto end; //String
    }
    }

    // set_user_emoji_status_request->emoji_status_expiration_date
    cJSON *emoji_status_expiration_date = cJSON_GetObjectItemCaseSensitive(set_user_emoji_status_requestJSON, "emoji_status_expiration_date");
    if (cJSON_IsNull(emoji_status_expiration_date)) {
        emoji_status_expiration_date = NULL;
    }
    if (emoji_status_expiration_date) { 
    if(!cJSON_IsNumber(emoji_status_expiration_date))
    {
    goto end; //Numeric
    }
    }


    set_user_emoji_status_request_local_var = set_user_emoji_status_request_create_internal (
        user_id->valuedouble,
        emoji_status_custom_emoji_id && !cJSON_IsNull(emoji_status_custom_emoji_id) ? strdup(emoji_status_custom_emoji_id->valuestring) : NULL,
        emoji_status_expiration_date ? emoji_status_expiration_date->valuedouble : 0
        );

    return set_user_emoji_status_request_local_var;
end:
    return NULL;

}
