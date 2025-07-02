#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_create_forum_topic_request.h"


char* post_create_forum_topic_request_icon_color_ToString(telegram_bot_api_post_create_forum_topic_request_ICONCOLOR_e icon_color) {
    char* icon_colorArray[] =  { "NULL", "7322096", "16766590", "13338331", "9367192", "16749490", "16478047" };
    return icon_colorArray[icon_color];
}

telegram_bot_api_post_create_forum_topic_request_ICONCOLOR_e post_create_forum_topic_request_icon_color_FromString(char* icon_color){
    int stringToReturn = 0;
    char *icon_colorArray[] =  { "NULL", "7322096", "16766590", "13338331", "9367192", "16749490", "16478047" };
    size_t sizeofArray = sizeof(icon_colorArray) / sizeof(icon_colorArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(icon_color, icon_colorArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static post_create_forum_topic_request_t *post_create_forum_topic_request_create_internal(
    post_restrict_chat_member_request_chat_id_t *chat_id,
    char *name,
    int icon_color,
    char *icon_custom_emoji_id
    ) {
    post_create_forum_topic_request_t *post_create_forum_topic_request_local_var = malloc(sizeof(post_create_forum_topic_request_t));
    if (!post_create_forum_topic_request_local_var) {
        return NULL;
    }
    post_create_forum_topic_request_local_var->chat_id = chat_id;
    post_create_forum_topic_request_local_var->name = name;
    post_create_forum_topic_request_local_var->icon_color = icon_color;
    post_create_forum_topic_request_local_var->icon_custom_emoji_id = icon_custom_emoji_id;

    post_create_forum_topic_request_local_var->_library_owned = 1;
    return post_create_forum_topic_request_local_var;
}

__attribute__((deprecated)) post_create_forum_topic_request_t *post_create_forum_topic_request_create(
    post_restrict_chat_member_request_chat_id_t *chat_id,
    char *name,
    int icon_color,
    char *icon_custom_emoji_id
    ) {
    return post_create_forum_topic_request_create_internal (
        chat_id,
        name,
        icon_color,
        icon_custom_emoji_id
        );
}

void post_create_forum_topic_request_free(post_create_forum_topic_request_t *post_create_forum_topic_request) {
    if(NULL == post_create_forum_topic_request){
        return ;
    }
    if(post_create_forum_topic_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_create_forum_topic_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_create_forum_topic_request->chat_id) {
        post_restrict_chat_member_request_chat_id_free(post_create_forum_topic_request->chat_id);
        post_create_forum_topic_request->chat_id = NULL;
    }
    if (post_create_forum_topic_request->name) {
        free(post_create_forum_topic_request->name);
        post_create_forum_topic_request->name = NULL;
    }
    if (post_create_forum_topic_request->icon_custom_emoji_id) {
        free(post_create_forum_topic_request->icon_custom_emoji_id);
        post_create_forum_topic_request->icon_custom_emoji_id = NULL;
    }
    free(post_create_forum_topic_request);
}

cJSON *post_create_forum_topic_request_convertToJSON(post_create_forum_topic_request_t *post_create_forum_topic_request) {
    cJSON *item = cJSON_CreateObject();

    // post_create_forum_topic_request->chat_id
    if (!post_create_forum_topic_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = post_restrict_chat_member_request_chat_id_convertToJSON(post_create_forum_topic_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // post_create_forum_topic_request->name
    if (!post_create_forum_topic_request->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", post_create_forum_topic_request->name) == NULL) {
    goto fail; //String
    }


    // post_create_forum_topic_request->icon_color
    if(post_create_forum_topic_request->icon_color != telegram_bot_api_post_create_forum_topic_request_ICONCOLOR_NULL) {
    if(cJSON_AddNumberToObject(item, "icon_color", post_create_forum_topic_request->icon_color) == NULL) {
    goto fail; //Numeric
    }
    }


    // post_create_forum_topic_request->icon_custom_emoji_id
    if(post_create_forum_topic_request->icon_custom_emoji_id) {
    if(cJSON_AddStringToObject(item, "icon_custom_emoji_id", post_create_forum_topic_request->icon_custom_emoji_id) == NULL) {
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

post_create_forum_topic_request_t *post_create_forum_topic_request_parseFromJSON(cJSON *post_create_forum_topic_requestJSON){

    post_create_forum_topic_request_t *post_create_forum_topic_request_local_var = NULL;

    // define the local variable for post_create_forum_topic_request->chat_id
    post_restrict_chat_member_request_chat_id_t *chat_id_local_nonprim = NULL;

    // post_create_forum_topic_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(post_create_forum_topic_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = post_restrict_chat_member_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // post_create_forum_topic_request->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(post_create_forum_topic_requestJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // post_create_forum_topic_request->icon_color
    cJSON *icon_color = cJSON_GetObjectItemCaseSensitive(post_create_forum_topic_requestJSON, "icon_color");
    if (cJSON_IsNull(icon_color)) {
        icon_color = NULL;
    }
    if (icon_color) { 
    if(!cJSON_IsNumber(icon_color))
    {
    goto end; //Numeric
    }
    }

    // post_create_forum_topic_request->icon_custom_emoji_id
    cJSON *icon_custom_emoji_id = cJSON_GetObjectItemCaseSensitive(post_create_forum_topic_requestJSON, "icon_custom_emoji_id");
    if (cJSON_IsNull(icon_custom_emoji_id)) {
        icon_custom_emoji_id = NULL;
    }
    if (icon_custom_emoji_id) { 
    if(!cJSON_IsString(icon_custom_emoji_id) && !cJSON_IsNull(icon_custom_emoji_id))
    {
    goto end; //String
    }
    }


    post_create_forum_topic_request_local_var = post_create_forum_topic_request_create_internal (
        chat_id_local_nonprim,
        strdup(name->valuestring),
        icon_color ? icon_color->valuedouble : 0,
        icon_custom_emoji_id && !cJSON_IsNull(icon_custom_emoji_id) ? strdup(icon_custom_emoji_id->valuestring) : NULL
        );

    return post_create_forum_topic_request_local_var;
end:
    if (chat_id_local_nonprim) {
        post_restrict_chat_member_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
