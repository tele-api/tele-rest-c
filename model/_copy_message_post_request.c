#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_copy_message_post_request.h"



static _copy_message_post_request_t *_copy_message_post_request_create_internal(
    _send_message_post_request_chat_id_t *chat_id,
    _forward_message_post_request_from_chat_id_t *from_chat_id,
    int message_id,
    int message_thread_id,
    int video_start_timestamp,
    char *caption,
    char *parse_mode,
    list_t *caption_entities,
    int show_caption_above_media,
    int disable_notification,
    int protect_content,
    int allow_paid_broadcast,
    reply_parameters_t *reply_parameters,
    _send_message_post_request_reply_markup_t *reply_markup
    ) {
    _copy_message_post_request_t *_copy_message_post_request_local_var = malloc(sizeof(_copy_message_post_request_t));
    if (!_copy_message_post_request_local_var) {
        return NULL;
    }
    _copy_message_post_request_local_var->chat_id = chat_id;
    _copy_message_post_request_local_var->from_chat_id = from_chat_id;
    _copy_message_post_request_local_var->message_id = message_id;
    _copy_message_post_request_local_var->message_thread_id = message_thread_id;
    _copy_message_post_request_local_var->video_start_timestamp = video_start_timestamp;
    _copy_message_post_request_local_var->caption = caption;
    _copy_message_post_request_local_var->parse_mode = parse_mode;
    _copy_message_post_request_local_var->caption_entities = caption_entities;
    _copy_message_post_request_local_var->show_caption_above_media = show_caption_above_media;
    _copy_message_post_request_local_var->disable_notification = disable_notification;
    _copy_message_post_request_local_var->protect_content = protect_content;
    _copy_message_post_request_local_var->allow_paid_broadcast = allow_paid_broadcast;
    _copy_message_post_request_local_var->reply_parameters = reply_parameters;
    _copy_message_post_request_local_var->reply_markup = reply_markup;

    _copy_message_post_request_local_var->_library_owned = 1;
    return _copy_message_post_request_local_var;
}

__attribute__((deprecated)) _copy_message_post_request_t *_copy_message_post_request_create(
    _send_message_post_request_chat_id_t *chat_id,
    _forward_message_post_request_from_chat_id_t *from_chat_id,
    int message_id,
    int message_thread_id,
    int video_start_timestamp,
    char *caption,
    char *parse_mode,
    list_t *caption_entities,
    int show_caption_above_media,
    int disable_notification,
    int protect_content,
    int allow_paid_broadcast,
    reply_parameters_t *reply_parameters,
    _send_message_post_request_reply_markup_t *reply_markup
    ) {
    return _copy_message_post_request_create_internal (
        chat_id,
        from_chat_id,
        message_id,
        message_thread_id,
        video_start_timestamp,
        caption,
        parse_mode,
        caption_entities,
        show_caption_above_media,
        disable_notification,
        protect_content,
        allow_paid_broadcast,
        reply_parameters,
        reply_markup
        );
}

void _copy_message_post_request_free(_copy_message_post_request_t *_copy_message_post_request) {
    if(NULL == _copy_message_post_request){
        return ;
    }
    if(_copy_message_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_copy_message_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_copy_message_post_request->chat_id) {
        _send_message_post_request_chat_id_free(_copy_message_post_request->chat_id);
        _copy_message_post_request->chat_id = NULL;
    }
    if (_copy_message_post_request->from_chat_id) {
        _forward_message_post_request_from_chat_id_free(_copy_message_post_request->from_chat_id);
        _copy_message_post_request->from_chat_id = NULL;
    }
    if (_copy_message_post_request->caption) {
        free(_copy_message_post_request->caption);
        _copy_message_post_request->caption = NULL;
    }
    if (_copy_message_post_request->parse_mode) {
        free(_copy_message_post_request->parse_mode);
        _copy_message_post_request->parse_mode = NULL;
    }
    if (_copy_message_post_request->caption_entities) {
        list_ForEach(listEntry, _copy_message_post_request->caption_entities) {
            message_entity_free(listEntry->data);
        }
        list_freeList(_copy_message_post_request->caption_entities);
        _copy_message_post_request->caption_entities = NULL;
    }
    if (_copy_message_post_request->reply_parameters) {
        reply_parameters_free(_copy_message_post_request->reply_parameters);
        _copy_message_post_request->reply_parameters = NULL;
    }
    if (_copy_message_post_request->reply_markup) {
        _send_message_post_request_reply_markup_free(_copy_message_post_request->reply_markup);
        _copy_message_post_request->reply_markup = NULL;
    }
    free(_copy_message_post_request);
}

cJSON *_copy_message_post_request_convertToJSON(_copy_message_post_request_t *_copy_message_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _copy_message_post_request->chat_id
    if (!_copy_message_post_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = _send_message_post_request_chat_id_convertToJSON(_copy_message_post_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // _copy_message_post_request->from_chat_id
    if (!_copy_message_post_request->from_chat_id) {
        goto fail;
    }
    cJSON *from_chat_id_local_JSON = _forward_message_post_request_from_chat_id_convertToJSON(_copy_message_post_request->from_chat_id);
    if(from_chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "from_chat_id", from_chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // _copy_message_post_request->message_id
    if (!_copy_message_post_request->message_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "message_id", _copy_message_post_request->message_id) == NULL) {
    goto fail; //Numeric
    }


    // _copy_message_post_request->message_thread_id
    if(_copy_message_post_request->message_thread_id) {
    if(cJSON_AddNumberToObject(item, "message_thread_id", _copy_message_post_request->message_thread_id) == NULL) {
    goto fail; //Numeric
    }
    }


    // _copy_message_post_request->video_start_timestamp
    if(_copy_message_post_request->video_start_timestamp) {
    if(cJSON_AddNumberToObject(item, "video_start_timestamp", _copy_message_post_request->video_start_timestamp) == NULL) {
    goto fail; //Numeric
    }
    }


    // _copy_message_post_request->caption
    if(_copy_message_post_request->caption) {
    if(cJSON_AddStringToObject(item, "caption", _copy_message_post_request->caption) == NULL) {
    goto fail; //String
    }
    }


    // _copy_message_post_request->parse_mode
    if(_copy_message_post_request->parse_mode) {
    if(cJSON_AddStringToObject(item, "parse_mode", _copy_message_post_request->parse_mode) == NULL) {
    goto fail; //String
    }
    }


    // _copy_message_post_request->caption_entities
    if(_copy_message_post_request->caption_entities) {
    cJSON *caption_entities = cJSON_AddArrayToObject(item, "caption_entities");
    if(caption_entities == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *caption_entitiesListEntry;
    if (_copy_message_post_request->caption_entities) {
    list_ForEach(caption_entitiesListEntry, _copy_message_post_request->caption_entities) {
    cJSON *itemLocal = message_entity_convertToJSON(caption_entitiesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(caption_entities, itemLocal);
    }
    }
    }


    // _copy_message_post_request->show_caption_above_media
    if(_copy_message_post_request->show_caption_above_media) {
    if(cJSON_AddBoolToObject(item, "show_caption_above_media", _copy_message_post_request->show_caption_above_media) == NULL) {
    goto fail; //Bool
    }
    }


    // _copy_message_post_request->disable_notification
    if(_copy_message_post_request->disable_notification) {
    if(cJSON_AddBoolToObject(item, "disable_notification", _copy_message_post_request->disable_notification) == NULL) {
    goto fail; //Bool
    }
    }


    // _copy_message_post_request->protect_content
    if(_copy_message_post_request->protect_content) {
    if(cJSON_AddBoolToObject(item, "protect_content", _copy_message_post_request->protect_content) == NULL) {
    goto fail; //Bool
    }
    }


    // _copy_message_post_request->allow_paid_broadcast
    if(_copy_message_post_request->allow_paid_broadcast) {
    if(cJSON_AddBoolToObject(item, "allow_paid_broadcast", _copy_message_post_request->allow_paid_broadcast) == NULL) {
    goto fail; //Bool
    }
    }


    // _copy_message_post_request->reply_parameters
    if(_copy_message_post_request->reply_parameters) {
    cJSON *reply_parameters_local_JSON = reply_parameters_convertToJSON(_copy_message_post_request->reply_parameters);
    if(reply_parameters_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "reply_parameters", reply_parameters_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // _copy_message_post_request->reply_markup
    if(_copy_message_post_request->reply_markup) {
    cJSON *reply_markup_local_JSON = _send_message_post_request_reply_markup_convertToJSON(_copy_message_post_request->reply_markup);
    if(reply_markup_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "reply_markup", reply_markup_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

_copy_message_post_request_t *_copy_message_post_request_parseFromJSON(cJSON *_copy_message_post_requestJSON){

    _copy_message_post_request_t *_copy_message_post_request_local_var = NULL;

    // define the local variable for _copy_message_post_request->chat_id
    _send_message_post_request_chat_id_t *chat_id_local_nonprim = NULL;

    // define the local variable for _copy_message_post_request->from_chat_id
    _forward_message_post_request_from_chat_id_t *from_chat_id_local_nonprim = NULL;

    // define the local list for _copy_message_post_request->caption_entities
    list_t *caption_entitiesList = NULL;

    // define the local variable for _copy_message_post_request->reply_parameters
    reply_parameters_t *reply_parameters_local_nonprim = NULL;

    // define the local variable for _copy_message_post_request->reply_markup
    _send_message_post_request_reply_markup_t *reply_markup_local_nonprim = NULL;

    // _copy_message_post_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(_copy_message_post_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = _send_message_post_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // _copy_message_post_request->from_chat_id
    cJSON *from_chat_id = cJSON_GetObjectItemCaseSensitive(_copy_message_post_requestJSON, "from_chat_id");
    if (cJSON_IsNull(from_chat_id)) {
        from_chat_id = NULL;
    }
    if (!from_chat_id) {
        goto end;
    }

    
    from_chat_id_local_nonprim = _forward_message_post_request_from_chat_id_parseFromJSON(from_chat_id); //nonprimitive

    // _copy_message_post_request->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(_copy_message_post_requestJSON, "message_id");
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

    // _copy_message_post_request->message_thread_id
    cJSON *message_thread_id = cJSON_GetObjectItemCaseSensitive(_copy_message_post_requestJSON, "message_thread_id");
    if (cJSON_IsNull(message_thread_id)) {
        message_thread_id = NULL;
    }
    if (message_thread_id) { 
    if(!cJSON_IsNumber(message_thread_id))
    {
    goto end; //Numeric
    }
    }

    // _copy_message_post_request->video_start_timestamp
    cJSON *video_start_timestamp = cJSON_GetObjectItemCaseSensitive(_copy_message_post_requestJSON, "video_start_timestamp");
    if (cJSON_IsNull(video_start_timestamp)) {
        video_start_timestamp = NULL;
    }
    if (video_start_timestamp) { 
    if(!cJSON_IsNumber(video_start_timestamp))
    {
    goto end; //Numeric
    }
    }

    // _copy_message_post_request->caption
    cJSON *caption = cJSON_GetObjectItemCaseSensitive(_copy_message_post_requestJSON, "caption");
    if (cJSON_IsNull(caption)) {
        caption = NULL;
    }
    if (caption) { 
    if(!cJSON_IsString(caption) && !cJSON_IsNull(caption))
    {
    goto end; //String
    }
    }

    // _copy_message_post_request->parse_mode
    cJSON *parse_mode = cJSON_GetObjectItemCaseSensitive(_copy_message_post_requestJSON, "parse_mode");
    if (cJSON_IsNull(parse_mode)) {
        parse_mode = NULL;
    }
    if (parse_mode) { 
    if(!cJSON_IsString(parse_mode) && !cJSON_IsNull(parse_mode))
    {
    goto end; //String
    }
    }

    // _copy_message_post_request->caption_entities
    cJSON *caption_entities = cJSON_GetObjectItemCaseSensitive(_copy_message_post_requestJSON, "caption_entities");
    if (cJSON_IsNull(caption_entities)) {
        caption_entities = NULL;
    }
    if (caption_entities) { 
    cJSON *caption_entities_local_nonprimitive = NULL;
    if(!cJSON_IsArray(caption_entities)){
        goto end; //nonprimitive container
    }

    caption_entitiesList = list_createList();

    cJSON_ArrayForEach(caption_entities_local_nonprimitive,caption_entities )
    {
        if(!cJSON_IsObject(caption_entities_local_nonprimitive)){
            goto end;
        }
        message_entity_t *caption_entitiesItem = message_entity_parseFromJSON(caption_entities_local_nonprimitive);

        list_addElement(caption_entitiesList, caption_entitiesItem);
    }
    }

    // _copy_message_post_request->show_caption_above_media
    cJSON *show_caption_above_media = cJSON_GetObjectItemCaseSensitive(_copy_message_post_requestJSON, "show_caption_above_media");
    if (cJSON_IsNull(show_caption_above_media)) {
        show_caption_above_media = NULL;
    }
    if (show_caption_above_media) { 
    if(!cJSON_IsBool(show_caption_above_media))
    {
    goto end; //Bool
    }
    }

    // _copy_message_post_request->disable_notification
    cJSON *disable_notification = cJSON_GetObjectItemCaseSensitive(_copy_message_post_requestJSON, "disable_notification");
    if (cJSON_IsNull(disable_notification)) {
        disable_notification = NULL;
    }
    if (disable_notification) { 
    if(!cJSON_IsBool(disable_notification))
    {
    goto end; //Bool
    }
    }

    // _copy_message_post_request->protect_content
    cJSON *protect_content = cJSON_GetObjectItemCaseSensitive(_copy_message_post_requestJSON, "protect_content");
    if (cJSON_IsNull(protect_content)) {
        protect_content = NULL;
    }
    if (protect_content) { 
    if(!cJSON_IsBool(protect_content))
    {
    goto end; //Bool
    }
    }

    // _copy_message_post_request->allow_paid_broadcast
    cJSON *allow_paid_broadcast = cJSON_GetObjectItemCaseSensitive(_copy_message_post_requestJSON, "allow_paid_broadcast");
    if (cJSON_IsNull(allow_paid_broadcast)) {
        allow_paid_broadcast = NULL;
    }
    if (allow_paid_broadcast) { 
    if(!cJSON_IsBool(allow_paid_broadcast))
    {
    goto end; //Bool
    }
    }

    // _copy_message_post_request->reply_parameters
    cJSON *reply_parameters = cJSON_GetObjectItemCaseSensitive(_copy_message_post_requestJSON, "reply_parameters");
    if (cJSON_IsNull(reply_parameters)) {
        reply_parameters = NULL;
    }
    if (reply_parameters) { 
    reply_parameters_local_nonprim = reply_parameters_parseFromJSON(reply_parameters); //nonprimitive
    }

    // _copy_message_post_request->reply_markup
    cJSON *reply_markup = cJSON_GetObjectItemCaseSensitive(_copy_message_post_requestJSON, "reply_markup");
    if (cJSON_IsNull(reply_markup)) {
        reply_markup = NULL;
    }
    if (reply_markup) { 
    reply_markup_local_nonprim = _send_message_post_request_reply_markup_parseFromJSON(reply_markup); //nonprimitive
    }


    _copy_message_post_request_local_var = _copy_message_post_request_create_internal (
        chat_id_local_nonprim,
        from_chat_id_local_nonprim,
        message_id->valuedouble,
        message_thread_id ? message_thread_id->valuedouble : 0,
        video_start_timestamp ? video_start_timestamp->valuedouble : 0,
        caption && !cJSON_IsNull(caption) ? strdup(caption->valuestring) : NULL,
        parse_mode && !cJSON_IsNull(parse_mode) ? strdup(parse_mode->valuestring) : NULL,
        caption_entities ? caption_entitiesList : NULL,
        show_caption_above_media ? show_caption_above_media->valueint : 0,
        disable_notification ? disable_notification->valueint : 0,
        protect_content ? protect_content->valueint : 0,
        allow_paid_broadcast ? allow_paid_broadcast->valueint : 0,
        reply_parameters ? reply_parameters_local_nonprim : NULL,
        reply_markup ? reply_markup_local_nonprim : NULL
        );

    return _copy_message_post_request_local_var;
end:
    if (chat_id_local_nonprim) {
        _send_message_post_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    if (from_chat_id_local_nonprim) {
        _forward_message_post_request_from_chat_id_free(from_chat_id_local_nonprim);
        from_chat_id_local_nonprim = NULL;
    }
    if (caption_entitiesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, caption_entitiesList) {
            message_entity_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(caption_entitiesList);
        caption_entitiesList = NULL;
    }
    if (reply_parameters_local_nonprim) {
        reply_parameters_free(reply_parameters_local_nonprim);
        reply_parameters_local_nonprim = NULL;
    }
    if (reply_markup_local_nonprim) {
        _send_message_post_request_reply_markup_free(reply_markup_local_nonprim);
        reply_markup_local_nonprim = NULL;
    }
    return NULL;

}
