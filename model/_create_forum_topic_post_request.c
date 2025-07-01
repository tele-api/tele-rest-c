#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_create_forum_topic_post_request.h"


char* _create_forum_topic_post_request_icon_color_ToString(telegram_bot_api__create_forum_topic_post_request_ICONCOLOR_e icon_color) {
    char* icon_colorArray[] =  { "NULL", "7322096", "16766590", "13338331", "9367192", "16749490", "16478047" };
    return icon_colorArray[icon_color];
}

telegram_bot_api__create_forum_topic_post_request_ICONCOLOR_e _create_forum_topic_post_request_icon_color_FromString(char* icon_color){
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

static _create_forum_topic_post_request_t *_create_forum_topic_post_request_create_internal(
    _restrict_chat_member_post_request_chat_id_t *chat_id,
    char *name,
    int icon_color,
    char *icon_custom_emoji_id
    ) {
    _create_forum_topic_post_request_t *_create_forum_topic_post_request_local_var = malloc(sizeof(_create_forum_topic_post_request_t));
    if (!_create_forum_topic_post_request_local_var) {
        return NULL;
    }
    _create_forum_topic_post_request_local_var->chat_id = chat_id;
    _create_forum_topic_post_request_local_var->name = name;
    _create_forum_topic_post_request_local_var->icon_color = icon_color;
    _create_forum_topic_post_request_local_var->icon_custom_emoji_id = icon_custom_emoji_id;

    _create_forum_topic_post_request_local_var->_library_owned = 1;
    return _create_forum_topic_post_request_local_var;
}

__attribute__((deprecated)) _create_forum_topic_post_request_t *_create_forum_topic_post_request_create(
    _restrict_chat_member_post_request_chat_id_t *chat_id,
    char *name,
    int icon_color,
    char *icon_custom_emoji_id
    ) {
    return _create_forum_topic_post_request_create_internal (
        chat_id,
        name,
        icon_color,
        icon_custom_emoji_id
        );
}

void _create_forum_topic_post_request_free(_create_forum_topic_post_request_t *_create_forum_topic_post_request) {
    if(NULL == _create_forum_topic_post_request){
        return ;
    }
    if(_create_forum_topic_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_create_forum_topic_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_create_forum_topic_post_request->chat_id) {
        _restrict_chat_member_post_request_chat_id_free(_create_forum_topic_post_request->chat_id);
        _create_forum_topic_post_request->chat_id = NULL;
    }
    if (_create_forum_topic_post_request->name) {
        free(_create_forum_topic_post_request->name);
        _create_forum_topic_post_request->name = NULL;
    }
    if (_create_forum_topic_post_request->icon_custom_emoji_id) {
        free(_create_forum_topic_post_request->icon_custom_emoji_id);
        _create_forum_topic_post_request->icon_custom_emoji_id = NULL;
    }
    free(_create_forum_topic_post_request);
}

cJSON *_create_forum_topic_post_request_convertToJSON(_create_forum_topic_post_request_t *_create_forum_topic_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _create_forum_topic_post_request->chat_id
    if (!_create_forum_topic_post_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = _restrict_chat_member_post_request_chat_id_convertToJSON(_create_forum_topic_post_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // _create_forum_topic_post_request->name
    if (!_create_forum_topic_post_request->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", _create_forum_topic_post_request->name) == NULL) {
    goto fail; //String
    }


    // _create_forum_topic_post_request->icon_color
    if(_create_forum_topic_post_request->icon_color != telegram_bot_api__create_forum_topic_post_request_ICONCOLOR_NULL) {
    if(cJSON_AddNumberToObject(item, "icon_color", _create_forum_topic_post_request->icon_color) == NULL) {
    goto fail; //Numeric
    }
    }


    // _create_forum_topic_post_request->icon_custom_emoji_id
    if(_create_forum_topic_post_request->icon_custom_emoji_id) {
    if(cJSON_AddStringToObject(item, "icon_custom_emoji_id", _create_forum_topic_post_request->icon_custom_emoji_id) == NULL) {
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

_create_forum_topic_post_request_t *_create_forum_topic_post_request_parseFromJSON(cJSON *_create_forum_topic_post_requestJSON){

    _create_forum_topic_post_request_t *_create_forum_topic_post_request_local_var = NULL;

    // define the local variable for _create_forum_topic_post_request->chat_id
    _restrict_chat_member_post_request_chat_id_t *chat_id_local_nonprim = NULL;

    // _create_forum_topic_post_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(_create_forum_topic_post_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = _restrict_chat_member_post_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // _create_forum_topic_post_request->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(_create_forum_topic_post_requestJSON, "name");
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

    // _create_forum_topic_post_request->icon_color
    cJSON *icon_color = cJSON_GetObjectItemCaseSensitive(_create_forum_topic_post_requestJSON, "icon_color");
    if (cJSON_IsNull(icon_color)) {
        icon_color = NULL;
    }
    if (icon_color) { 
    if(!cJSON_IsNumber(icon_color))
    {
    goto end; //Numeric
    }
    }

    // _create_forum_topic_post_request->icon_custom_emoji_id
    cJSON *icon_custom_emoji_id = cJSON_GetObjectItemCaseSensitive(_create_forum_topic_post_requestJSON, "icon_custom_emoji_id");
    if (cJSON_IsNull(icon_custom_emoji_id)) {
        icon_custom_emoji_id = NULL;
    }
    if (icon_custom_emoji_id) { 
    if(!cJSON_IsString(icon_custom_emoji_id) && !cJSON_IsNull(icon_custom_emoji_id))
    {
    goto end; //String
    }
    }


    _create_forum_topic_post_request_local_var = _create_forum_topic_post_request_create_internal (
        chat_id_local_nonprim,
        strdup(name->valuestring),
        icon_color ? icon_color->valuedouble : 0,
        icon_custom_emoji_id && !cJSON_IsNull(icon_custom_emoji_id) ? strdup(icon_custom_emoji_id->valuestring) : NULL
        );

    return _create_forum_topic_post_request_local_var;
end:
    if (chat_id_local_nonprim) {
        _restrict_chat_member_post_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
