#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "create_forum_topic_request.h"


char* create_forum_topic_request_icon_color_ToString(telegram_bot_api_create_forum_topic_request_ICONCOLOR_e icon_color) {
    char* icon_colorArray[] =  { "NULL", "7322096", "16766590", "13338331", "9367192", "16749490", "16478047" };
    return icon_colorArray[icon_color];
}

telegram_bot_api_create_forum_topic_request_ICONCOLOR_e create_forum_topic_request_icon_color_FromString(char* icon_color){
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

static create_forum_topic_request_t *create_forum_topic_request_create_internal(
    bot_command_scope_chat_chat_id_t *chat_id,
    char *name,
    int icon_color,
    char *icon_custom_emoji_id
    ) {
    create_forum_topic_request_t *create_forum_topic_request_local_var = malloc(sizeof(create_forum_topic_request_t));
    if (!create_forum_topic_request_local_var) {
        return NULL;
    }
    create_forum_topic_request_local_var->chat_id = chat_id;
    create_forum_topic_request_local_var->name = name;
    create_forum_topic_request_local_var->icon_color = icon_color;
    create_forum_topic_request_local_var->icon_custom_emoji_id = icon_custom_emoji_id;

    create_forum_topic_request_local_var->_library_owned = 1;
    return create_forum_topic_request_local_var;
}

__attribute__((deprecated)) create_forum_topic_request_t *create_forum_topic_request_create(
    bot_command_scope_chat_chat_id_t *chat_id,
    char *name,
    int icon_color,
    char *icon_custom_emoji_id
    ) {
    return create_forum_topic_request_create_internal (
        chat_id,
        name,
        icon_color,
        icon_custom_emoji_id
        );
}

void create_forum_topic_request_free(create_forum_topic_request_t *create_forum_topic_request) {
    if(NULL == create_forum_topic_request){
        return ;
    }
    if(create_forum_topic_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "create_forum_topic_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (create_forum_topic_request->chat_id) {
        bot_command_scope_chat_chat_id_free(create_forum_topic_request->chat_id);
        create_forum_topic_request->chat_id = NULL;
    }
    if (create_forum_topic_request->name) {
        free(create_forum_topic_request->name);
        create_forum_topic_request->name = NULL;
    }
    if (create_forum_topic_request->icon_custom_emoji_id) {
        free(create_forum_topic_request->icon_custom_emoji_id);
        create_forum_topic_request->icon_custom_emoji_id = NULL;
    }
    free(create_forum_topic_request);
}

cJSON *create_forum_topic_request_convertToJSON(create_forum_topic_request_t *create_forum_topic_request) {
    cJSON *item = cJSON_CreateObject();

    // create_forum_topic_request->chat_id
    if (!create_forum_topic_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = bot_command_scope_chat_chat_id_convertToJSON(create_forum_topic_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // create_forum_topic_request->name
    if (!create_forum_topic_request->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", create_forum_topic_request->name) == NULL) {
    goto fail; //String
    }


    // create_forum_topic_request->icon_color
    if(create_forum_topic_request->icon_color != telegram_bot_api_create_forum_topic_request_ICONCOLOR_NULL) {
    if(cJSON_AddNumberToObject(item, "icon_color", create_forum_topic_request->icon_color) == NULL) {
    goto fail; //Numeric
    }
    }


    // create_forum_topic_request->icon_custom_emoji_id
    if(create_forum_topic_request->icon_custom_emoji_id) {
    if(cJSON_AddStringToObject(item, "icon_custom_emoji_id", create_forum_topic_request->icon_custom_emoji_id) == NULL) {
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

create_forum_topic_request_t *create_forum_topic_request_parseFromJSON(cJSON *create_forum_topic_requestJSON){

    create_forum_topic_request_t *create_forum_topic_request_local_var = NULL;

    // define the local variable for create_forum_topic_request->chat_id
    bot_command_scope_chat_chat_id_t *chat_id_local_nonprim = NULL;

    // create_forum_topic_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(create_forum_topic_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = bot_command_scope_chat_chat_id_parseFromJSON(chat_id); //nonprimitive

    // create_forum_topic_request->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(create_forum_topic_requestJSON, "name");
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

    // create_forum_topic_request->icon_color
    cJSON *icon_color = cJSON_GetObjectItemCaseSensitive(create_forum_topic_requestJSON, "icon_color");
    if (cJSON_IsNull(icon_color)) {
        icon_color = NULL;
    }
    if (icon_color) { 
    if(!cJSON_IsNumber(icon_color))
    {
    goto end; //Numeric
    }
    }

    // create_forum_topic_request->icon_custom_emoji_id
    cJSON *icon_custom_emoji_id = cJSON_GetObjectItemCaseSensitive(create_forum_topic_requestJSON, "icon_custom_emoji_id");
    if (cJSON_IsNull(icon_custom_emoji_id)) {
        icon_custom_emoji_id = NULL;
    }
    if (icon_custom_emoji_id) { 
    if(!cJSON_IsString(icon_custom_emoji_id) && !cJSON_IsNull(icon_custom_emoji_id))
    {
    goto end; //String
    }
    }


    create_forum_topic_request_local_var = create_forum_topic_request_create_internal (
        chat_id_local_nonprim,
        strdup(name->valuestring),
        icon_color ? icon_color->valuedouble : 0,
        icon_custom_emoji_id && !cJSON_IsNull(icon_custom_emoji_id) ? strdup(icon_custom_emoji_id->valuestring) : NULL
        );

    return create_forum_topic_request_local_var;
end:
    if (chat_id_local_nonprim) {
        bot_command_scope_chat_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
