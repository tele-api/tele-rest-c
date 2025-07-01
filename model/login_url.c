#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "login_url.h"



static login_url_t *login_url_create_internal(
    char *url,
    char *forward_text,
    char *bot_username,
    int request_write_access
    ) {
    login_url_t *login_url_local_var = malloc(sizeof(login_url_t));
    if (!login_url_local_var) {
        return NULL;
    }
    login_url_local_var->url = url;
    login_url_local_var->forward_text = forward_text;
    login_url_local_var->bot_username = bot_username;
    login_url_local_var->request_write_access = request_write_access;

    login_url_local_var->_library_owned = 1;
    return login_url_local_var;
}

__attribute__((deprecated)) login_url_t *login_url_create(
    char *url,
    char *forward_text,
    char *bot_username,
    int request_write_access
    ) {
    return login_url_create_internal (
        url,
        forward_text,
        bot_username,
        request_write_access
        );
}

void login_url_free(login_url_t *login_url) {
    if(NULL == login_url){
        return ;
    }
    if(login_url->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "login_url_free");
        return ;
    }
    listEntry_t *listEntry;
    if (login_url->url) {
        free(login_url->url);
        login_url->url = NULL;
    }
    if (login_url->forward_text) {
        free(login_url->forward_text);
        login_url->forward_text = NULL;
    }
    if (login_url->bot_username) {
        free(login_url->bot_username);
        login_url->bot_username = NULL;
    }
    free(login_url);
}

cJSON *login_url_convertToJSON(login_url_t *login_url) {
    cJSON *item = cJSON_CreateObject();

    // login_url->url
    if (!login_url->url) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "url", login_url->url) == NULL) {
    goto fail; //String
    }


    // login_url->forward_text
    if(login_url->forward_text) {
    if(cJSON_AddStringToObject(item, "forward_text", login_url->forward_text) == NULL) {
    goto fail; //String
    }
    }


    // login_url->bot_username
    if(login_url->bot_username) {
    if(cJSON_AddStringToObject(item, "bot_username", login_url->bot_username) == NULL) {
    goto fail; //String
    }
    }


    // login_url->request_write_access
    if(login_url->request_write_access) {
    if(cJSON_AddBoolToObject(item, "request_write_access", login_url->request_write_access) == NULL) {
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

login_url_t *login_url_parseFromJSON(cJSON *login_urlJSON){

    login_url_t *login_url_local_var = NULL;

    // login_url->url
    cJSON *url = cJSON_GetObjectItemCaseSensitive(login_urlJSON, "url");
    if (cJSON_IsNull(url)) {
        url = NULL;
    }
    if (!url) {
        goto end;
    }

    
    if(!cJSON_IsString(url))
    {
    goto end; //String
    }

    // login_url->forward_text
    cJSON *forward_text = cJSON_GetObjectItemCaseSensitive(login_urlJSON, "forward_text");
    if (cJSON_IsNull(forward_text)) {
        forward_text = NULL;
    }
    if (forward_text) { 
    if(!cJSON_IsString(forward_text) && !cJSON_IsNull(forward_text))
    {
    goto end; //String
    }
    }

    // login_url->bot_username
    cJSON *bot_username = cJSON_GetObjectItemCaseSensitive(login_urlJSON, "bot_username");
    if (cJSON_IsNull(bot_username)) {
        bot_username = NULL;
    }
    if (bot_username) { 
    if(!cJSON_IsString(bot_username) && !cJSON_IsNull(bot_username))
    {
    goto end; //String
    }
    }

    // login_url->request_write_access
    cJSON *request_write_access = cJSON_GetObjectItemCaseSensitive(login_urlJSON, "request_write_access");
    if (cJSON_IsNull(request_write_access)) {
        request_write_access = NULL;
    }
    if (request_write_access) { 
    if(!cJSON_IsBool(request_write_access))
    {
    goto end; //Bool
    }
    }


    login_url_local_var = login_url_create_internal (
        strdup(url->valuestring),
        forward_text && !cJSON_IsNull(forward_text) ? strdup(forward_text->valuestring) : NULL,
        bot_username && !cJSON_IsNull(bot_username) ? strdup(bot_username->valuestring) : NULL,
        request_write_access ? request_write_access->valueint : 0
        );

    return login_url_local_var;
end:
    return NULL;

}
