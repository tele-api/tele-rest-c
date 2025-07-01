#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "chat_boost_source_gift_code.h"



static chat_boost_source_gift_code_t *chat_boost_source_gift_code_create_internal(
    char *source,
    user_t *user
    ) {
    chat_boost_source_gift_code_t *chat_boost_source_gift_code_local_var = malloc(sizeof(chat_boost_source_gift_code_t));
    if (!chat_boost_source_gift_code_local_var) {
        return NULL;
    }
    chat_boost_source_gift_code_local_var->source = source;
    chat_boost_source_gift_code_local_var->user = user;

    chat_boost_source_gift_code_local_var->_library_owned = 1;
    return chat_boost_source_gift_code_local_var;
}

__attribute__((deprecated)) chat_boost_source_gift_code_t *chat_boost_source_gift_code_create(
    char *source,
    user_t *user
    ) {
    return chat_boost_source_gift_code_create_internal (
        source,
        user
        );
}

void chat_boost_source_gift_code_free(chat_boost_source_gift_code_t *chat_boost_source_gift_code) {
    if(NULL == chat_boost_source_gift_code){
        return ;
    }
    if(chat_boost_source_gift_code->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "chat_boost_source_gift_code_free");
        return ;
    }
    listEntry_t *listEntry;
    if (chat_boost_source_gift_code->source) {
        free(chat_boost_source_gift_code->source);
        chat_boost_source_gift_code->source = NULL;
    }
    if (chat_boost_source_gift_code->user) {
        user_free(chat_boost_source_gift_code->user);
        chat_boost_source_gift_code->user = NULL;
    }
    free(chat_boost_source_gift_code);
}

cJSON *chat_boost_source_gift_code_convertToJSON(chat_boost_source_gift_code_t *chat_boost_source_gift_code) {
    cJSON *item = cJSON_CreateObject();

    // chat_boost_source_gift_code->source
    if (!chat_boost_source_gift_code->source) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "source", chat_boost_source_gift_code->source) == NULL) {
    goto fail; //String
    }


    // chat_boost_source_gift_code->user
    if (!chat_boost_source_gift_code->user) {
        goto fail;
    }
    cJSON *user_local_JSON = user_convertToJSON(chat_boost_source_gift_code->user);
    if(user_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "user", user_local_JSON);
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

chat_boost_source_gift_code_t *chat_boost_source_gift_code_parseFromJSON(cJSON *chat_boost_source_gift_codeJSON){

    chat_boost_source_gift_code_t *chat_boost_source_gift_code_local_var = NULL;

    // define the local variable for chat_boost_source_gift_code->user
    user_t *user_local_nonprim = NULL;

    // chat_boost_source_gift_code->source
    cJSON *source = cJSON_GetObjectItemCaseSensitive(chat_boost_source_gift_codeJSON, "source");
    if (cJSON_IsNull(source)) {
        source = NULL;
    }
    if (!source) {
        goto end;
    }

    
    if(!cJSON_IsString(source))
    {
    goto end; //String
    }

    // chat_boost_source_gift_code->user
    cJSON *user = cJSON_GetObjectItemCaseSensitive(chat_boost_source_gift_codeJSON, "user");
    if (cJSON_IsNull(user)) {
        user = NULL;
    }
    if (!user) {
        goto end;
    }

    
    user_local_nonprim = user_parseFromJSON(user); //nonprimitive


    chat_boost_source_gift_code_local_var = chat_boost_source_gift_code_create_internal (
        strdup(source->valuestring),
        user_local_nonprim
        );

    return chat_boost_source_gift_code_local_var;
end:
    if (user_local_nonprim) {
        user_free(user_local_nonprim);
        user_local_nonprim = NULL;
    }
    return NULL;

}
