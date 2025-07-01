#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_send_media_group_post_request_media_inner.h"



static _send_media_group_post_request_media_inner_t *_send_media_group_post_request_media_inner_create_internal(
    char *type,
    char *media,
    char *thumbnail,
    char *caption,
    char *parse_mode,
    list_t *caption_entities,
    int duration,
    char *performer,
    char *title,
    int disable_content_type_detection,
    int show_caption_above_media,
    int has_spoiler,
    char *cover,
    int start_timestamp,
    int width,
    int height,
    int supports_streaming
    ) {
    _send_media_group_post_request_media_inner_t *_send_media_group_post_request_media_inner_local_var = malloc(sizeof(_send_media_group_post_request_media_inner_t));
    if (!_send_media_group_post_request_media_inner_local_var) {
        return NULL;
    }
    _send_media_group_post_request_media_inner_local_var->type = type;
    _send_media_group_post_request_media_inner_local_var->media = media;
    _send_media_group_post_request_media_inner_local_var->thumbnail = thumbnail;
    _send_media_group_post_request_media_inner_local_var->caption = caption;
    _send_media_group_post_request_media_inner_local_var->parse_mode = parse_mode;
    _send_media_group_post_request_media_inner_local_var->caption_entities = caption_entities;
    _send_media_group_post_request_media_inner_local_var->duration = duration;
    _send_media_group_post_request_media_inner_local_var->performer = performer;
    _send_media_group_post_request_media_inner_local_var->title = title;
    _send_media_group_post_request_media_inner_local_var->disable_content_type_detection = disable_content_type_detection;
    _send_media_group_post_request_media_inner_local_var->show_caption_above_media = show_caption_above_media;
    _send_media_group_post_request_media_inner_local_var->has_spoiler = has_spoiler;
    _send_media_group_post_request_media_inner_local_var->cover = cover;
    _send_media_group_post_request_media_inner_local_var->start_timestamp = start_timestamp;
    _send_media_group_post_request_media_inner_local_var->width = width;
    _send_media_group_post_request_media_inner_local_var->height = height;
    _send_media_group_post_request_media_inner_local_var->supports_streaming = supports_streaming;

    _send_media_group_post_request_media_inner_local_var->_library_owned = 1;
    return _send_media_group_post_request_media_inner_local_var;
}

__attribute__((deprecated)) _send_media_group_post_request_media_inner_t *_send_media_group_post_request_media_inner_create(
    char *type,
    char *media,
    char *thumbnail,
    char *caption,
    char *parse_mode,
    list_t *caption_entities,
    int duration,
    char *performer,
    char *title,
    int disable_content_type_detection,
    int show_caption_above_media,
    int has_spoiler,
    char *cover,
    int start_timestamp,
    int width,
    int height,
    int supports_streaming
    ) {
    return _send_media_group_post_request_media_inner_create_internal (
        type,
        media,
        thumbnail,
        caption,
        parse_mode,
        caption_entities,
        duration,
        performer,
        title,
        disable_content_type_detection,
        show_caption_above_media,
        has_spoiler,
        cover,
        start_timestamp,
        width,
        height,
        supports_streaming
        );
}

void _send_media_group_post_request_media_inner_free(_send_media_group_post_request_media_inner_t *_send_media_group_post_request_media_inner) {
    if(NULL == _send_media_group_post_request_media_inner){
        return ;
    }
    if(_send_media_group_post_request_media_inner->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_send_media_group_post_request_media_inner_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_send_media_group_post_request_media_inner->type) {
        free(_send_media_group_post_request_media_inner->type);
        _send_media_group_post_request_media_inner->type = NULL;
    }
    if (_send_media_group_post_request_media_inner->media) {
        free(_send_media_group_post_request_media_inner->media);
        _send_media_group_post_request_media_inner->media = NULL;
    }
    if (_send_media_group_post_request_media_inner->thumbnail) {
        free(_send_media_group_post_request_media_inner->thumbnail);
        _send_media_group_post_request_media_inner->thumbnail = NULL;
    }
    if (_send_media_group_post_request_media_inner->caption) {
        free(_send_media_group_post_request_media_inner->caption);
        _send_media_group_post_request_media_inner->caption = NULL;
    }
    if (_send_media_group_post_request_media_inner->parse_mode) {
        free(_send_media_group_post_request_media_inner->parse_mode);
        _send_media_group_post_request_media_inner->parse_mode = NULL;
    }
    if (_send_media_group_post_request_media_inner->caption_entities) {
        list_ForEach(listEntry, _send_media_group_post_request_media_inner->caption_entities) {
            message_entity_free(listEntry->data);
        }
        list_freeList(_send_media_group_post_request_media_inner->caption_entities);
        _send_media_group_post_request_media_inner->caption_entities = NULL;
    }
    if (_send_media_group_post_request_media_inner->performer) {
        free(_send_media_group_post_request_media_inner->performer);
        _send_media_group_post_request_media_inner->performer = NULL;
    }
    if (_send_media_group_post_request_media_inner->title) {
        free(_send_media_group_post_request_media_inner->title);
        _send_media_group_post_request_media_inner->title = NULL;
    }
    if (_send_media_group_post_request_media_inner->cover) {
        free(_send_media_group_post_request_media_inner->cover);
        _send_media_group_post_request_media_inner->cover = NULL;
    }
    free(_send_media_group_post_request_media_inner);
}

cJSON *_send_media_group_post_request_media_inner_convertToJSON(_send_media_group_post_request_media_inner_t *_send_media_group_post_request_media_inner) {
    cJSON *item = cJSON_CreateObject();

    // _send_media_group_post_request_media_inner->type
    if (!_send_media_group_post_request_media_inner->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", _send_media_group_post_request_media_inner->type) == NULL) {
    goto fail; //String
    }


    // _send_media_group_post_request_media_inner->media
    if (!_send_media_group_post_request_media_inner->media) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "media", _send_media_group_post_request_media_inner->media) == NULL) {
    goto fail; //String
    }


    // _send_media_group_post_request_media_inner->thumbnail
    if(_send_media_group_post_request_media_inner->thumbnail) {
    if(cJSON_AddStringToObject(item, "thumbnail", _send_media_group_post_request_media_inner->thumbnail) == NULL) {
    goto fail; //String
    }
    }


    // _send_media_group_post_request_media_inner->caption
    if(_send_media_group_post_request_media_inner->caption) {
    if(cJSON_AddStringToObject(item, "caption", _send_media_group_post_request_media_inner->caption) == NULL) {
    goto fail; //String
    }
    }


    // _send_media_group_post_request_media_inner->parse_mode
    if(_send_media_group_post_request_media_inner->parse_mode) {
    if(cJSON_AddStringToObject(item, "parse_mode", _send_media_group_post_request_media_inner->parse_mode) == NULL) {
    goto fail; //String
    }
    }


    // _send_media_group_post_request_media_inner->caption_entities
    if(_send_media_group_post_request_media_inner->caption_entities) {
    cJSON *caption_entities = cJSON_AddArrayToObject(item, "caption_entities");
    if(caption_entities == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *caption_entitiesListEntry;
    if (_send_media_group_post_request_media_inner->caption_entities) {
    list_ForEach(caption_entitiesListEntry, _send_media_group_post_request_media_inner->caption_entities) {
    cJSON *itemLocal = message_entity_convertToJSON(caption_entitiesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(caption_entities, itemLocal);
    }
    }
    }


    // _send_media_group_post_request_media_inner->duration
    if(_send_media_group_post_request_media_inner->duration) {
    if(cJSON_AddNumberToObject(item, "duration", _send_media_group_post_request_media_inner->duration) == NULL) {
    goto fail; //Numeric
    }
    }


    // _send_media_group_post_request_media_inner->performer
    if(_send_media_group_post_request_media_inner->performer) {
    if(cJSON_AddStringToObject(item, "performer", _send_media_group_post_request_media_inner->performer) == NULL) {
    goto fail; //String
    }
    }


    // _send_media_group_post_request_media_inner->title
    if(_send_media_group_post_request_media_inner->title) {
    if(cJSON_AddStringToObject(item, "title", _send_media_group_post_request_media_inner->title) == NULL) {
    goto fail; //String
    }
    }


    // _send_media_group_post_request_media_inner->disable_content_type_detection
    if(_send_media_group_post_request_media_inner->disable_content_type_detection) {
    if(cJSON_AddBoolToObject(item, "disable_content_type_detection", _send_media_group_post_request_media_inner->disable_content_type_detection) == NULL) {
    goto fail; //Bool
    }
    }


    // _send_media_group_post_request_media_inner->show_caption_above_media
    if(_send_media_group_post_request_media_inner->show_caption_above_media) {
    if(cJSON_AddBoolToObject(item, "show_caption_above_media", _send_media_group_post_request_media_inner->show_caption_above_media) == NULL) {
    goto fail; //Bool
    }
    }


    // _send_media_group_post_request_media_inner->has_spoiler
    if(_send_media_group_post_request_media_inner->has_spoiler) {
    if(cJSON_AddBoolToObject(item, "has_spoiler", _send_media_group_post_request_media_inner->has_spoiler) == NULL) {
    goto fail; //Bool
    }
    }


    // _send_media_group_post_request_media_inner->cover
    if(_send_media_group_post_request_media_inner->cover) {
    if(cJSON_AddStringToObject(item, "cover", _send_media_group_post_request_media_inner->cover) == NULL) {
    goto fail; //String
    }
    }


    // _send_media_group_post_request_media_inner->start_timestamp
    if(_send_media_group_post_request_media_inner->start_timestamp) {
    if(cJSON_AddNumberToObject(item, "start_timestamp", _send_media_group_post_request_media_inner->start_timestamp) == NULL) {
    goto fail; //Numeric
    }
    }


    // _send_media_group_post_request_media_inner->width
    if(_send_media_group_post_request_media_inner->width) {
    if(cJSON_AddNumberToObject(item, "width", _send_media_group_post_request_media_inner->width) == NULL) {
    goto fail; //Numeric
    }
    }


    // _send_media_group_post_request_media_inner->height
    if(_send_media_group_post_request_media_inner->height) {
    if(cJSON_AddNumberToObject(item, "height", _send_media_group_post_request_media_inner->height) == NULL) {
    goto fail; //Numeric
    }
    }


    // _send_media_group_post_request_media_inner->supports_streaming
    if(_send_media_group_post_request_media_inner->supports_streaming) {
    if(cJSON_AddBoolToObject(item, "supports_streaming", _send_media_group_post_request_media_inner->supports_streaming) == NULL) {
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

_send_media_group_post_request_media_inner_t *_send_media_group_post_request_media_inner_parseFromJSON(cJSON *_send_media_group_post_request_media_innerJSON){

    _send_media_group_post_request_media_inner_t *_send_media_group_post_request_media_inner_local_var = NULL;

    // define the local list for _send_media_group_post_request_media_inner->caption_entities
    list_t *caption_entitiesList = NULL;

    // _send_media_group_post_request_media_inner->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(_send_media_group_post_request_media_innerJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }

    // _send_media_group_post_request_media_inner->media
    cJSON *media = cJSON_GetObjectItemCaseSensitive(_send_media_group_post_request_media_innerJSON, "media");
    if (cJSON_IsNull(media)) {
        media = NULL;
    }
    if (!media) {
        goto end;
    }

    
    if(!cJSON_IsString(media))
    {
    goto end; //String
    }

    // _send_media_group_post_request_media_inner->thumbnail
    cJSON *thumbnail = cJSON_GetObjectItemCaseSensitive(_send_media_group_post_request_media_innerJSON, "thumbnail");
    if (cJSON_IsNull(thumbnail)) {
        thumbnail = NULL;
    }
    if (thumbnail) { 
    if(!cJSON_IsString(thumbnail) && !cJSON_IsNull(thumbnail))
    {
    goto end; //String
    }
    }

    // _send_media_group_post_request_media_inner->caption
    cJSON *caption = cJSON_GetObjectItemCaseSensitive(_send_media_group_post_request_media_innerJSON, "caption");
    if (cJSON_IsNull(caption)) {
        caption = NULL;
    }
    if (caption) { 
    if(!cJSON_IsString(caption) && !cJSON_IsNull(caption))
    {
    goto end; //String
    }
    }

    // _send_media_group_post_request_media_inner->parse_mode
    cJSON *parse_mode = cJSON_GetObjectItemCaseSensitive(_send_media_group_post_request_media_innerJSON, "parse_mode");
    if (cJSON_IsNull(parse_mode)) {
        parse_mode = NULL;
    }
    if (parse_mode) { 
    if(!cJSON_IsString(parse_mode) && !cJSON_IsNull(parse_mode))
    {
    goto end; //String
    }
    }

    // _send_media_group_post_request_media_inner->caption_entities
    cJSON *caption_entities = cJSON_GetObjectItemCaseSensitive(_send_media_group_post_request_media_innerJSON, "caption_entities");
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

    // _send_media_group_post_request_media_inner->duration
    cJSON *duration = cJSON_GetObjectItemCaseSensitive(_send_media_group_post_request_media_innerJSON, "duration");
    if (cJSON_IsNull(duration)) {
        duration = NULL;
    }
    if (duration) { 
    if(!cJSON_IsNumber(duration))
    {
    goto end; //Numeric
    }
    }

    // _send_media_group_post_request_media_inner->performer
    cJSON *performer = cJSON_GetObjectItemCaseSensitive(_send_media_group_post_request_media_innerJSON, "performer");
    if (cJSON_IsNull(performer)) {
        performer = NULL;
    }
    if (performer) { 
    if(!cJSON_IsString(performer) && !cJSON_IsNull(performer))
    {
    goto end; //String
    }
    }

    // _send_media_group_post_request_media_inner->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(_send_media_group_post_request_media_innerJSON, "title");
    if (cJSON_IsNull(title)) {
        title = NULL;
    }
    if (title) { 
    if(!cJSON_IsString(title) && !cJSON_IsNull(title))
    {
    goto end; //String
    }
    }

    // _send_media_group_post_request_media_inner->disable_content_type_detection
    cJSON *disable_content_type_detection = cJSON_GetObjectItemCaseSensitive(_send_media_group_post_request_media_innerJSON, "disable_content_type_detection");
    if (cJSON_IsNull(disable_content_type_detection)) {
        disable_content_type_detection = NULL;
    }
    if (disable_content_type_detection) { 
    if(!cJSON_IsBool(disable_content_type_detection))
    {
    goto end; //Bool
    }
    }

    // _send_media_group_post_request_media_inner->show_caption_above_media
    cJSON *show_caption_above_media = cJSON_GetObjectItemCaseSensitive(_send_media_group_post_request_media_innerJSON, "show_caption_above_media");
    if (cJSON_IsNull(show_caption_above_media)) {
        show_caption_above_media = NULL;
    }
    if (show_caption_above_media) { 
    if(!cJSON_IsBool(show_caption_above_media))
    {
    goto end; //Bool
    }
    }

    // _send_media_group_post_request_media_inner->has_spoiler
    cJSON *has_spoiler = cJSON_GetObjectItemCaseSensitive(_send_media_group_post_request_media_innerJSON, "has_spoiler");
    if (cJSON_IsNull(has_spoiler)) {
        has_spoiler = NULL;
    }
    if (has_spoiler) { 
    if(!cJSON_IsBool(has_spoiler))
    {
    goto end; //Bool
    }
    }

    // _send_media_group_post_request_media_inner->cover
    cJSON *cover = cJSON_GetObjectItemCaseSensitive(_send_media_group_post_request_media_innerJSON, "cover");
    if (cJSON_IsNull(cover)) {
        cover = NULL;
    }
    if (cover) { 
    if(!cJSON_IsString(cover) && !cJSON_IsNull(cover))
    {
    goto end; //String
    }
    }

    // _send_media_group_post_request_media_inner->start_timestamp
    cJSON *start_timestamp = cJSON_GetObjectItemCaseSensitive(_send_media_group_post_request_media_innerJSON, "start_timestamp");
    if (cJSON_IsNull(start_timestamp)) {
        start_timestamp = NULL;
    }
    if (start_timestamp) { 
    if(!cJSON_IsNumber(start_timestamp))
    {
    goto end; //Numeric
    }
    }

    // _send_media_group_post_request_media_inner->width
    cJSON *width = cJSON_GetObjectItemCaseSensitive(_send_media_group_post_request_media_innerJSON, "width");
    if (cJSON_IsNull(width)) {
        width = NULL;
    }
    if (width) { 
    if(!cJSON_IsNumber(width))
    {
    goto end; //Numeric
    }
    }

    // _send_media_group_post_request_media_inner->height
    cJSON *height = cJSON_GetObjectItemCaseSensitive(_send_media_group_post_request_media_innerJSON, "height");
    if (cJSON_IsNull(height)) {
        height = NULL;
    }
    if (height) { 
    if(!cJSON_IsNumber(height))
    {
    goto end; //Numeric
    }
    }

    // _send_media_group_post_request_media_inner->supports_streaming
    cJSON *supports_streaming = cJSON_GetObjectItemCaseSensitive(_send_media_group_post_request_media_innerJSON, "supports_streaming");
    if (cJSON_IsNull(supports_streaming)) {
        supports_streaming = NULL;
    }
    if (supports_streaming) { 
    if(!cJSON_IsBool(supports_streaming))
    {
    goto end; //Bool
    }
    }


    _send_media_group_post_request_media_inner_local_var = _send_media_group_post_request_media_inner_create_internal (
        strdup(type->valuestring),
        strdup(media->valuestring),
        thumbnail && !cJSON_IsNull(thumbnail) ? strdup(thumbnail->valuestring) : NULL,
        caption && !cJSON_IsNull(caption) ? strdup(caption->valuestring) : NULL,
        parse_mode && !cJSON_IsNull(parse_mode) ? strdup(parse_mode->valuestring) : NULL,
        caption_entities ? caption_entitiesList : NULL,
        duration ? duration->valuedouble : 0,
        performer && !cJSON_IsNull(performer) ? strdup(performer->valuestring) : NULL,
        title && !cJSON_IsNull(title) ? strdup(title->valuestring) : NULL,
        disable_content_type_detection ? disable_content_type_detection->valueint : 0,
        show_caption_above_media ? show_caption_above_media->valueint : 0,
        has_spoiler ? has_spoiler->valueint : 0,
        cover && !cJSON_IsNull(cover) ? strdup(cover->valuestring) : NULL,
        start_timestamp ? start_timestamp->valuedouble : 0,
        width ? width->valuedouble : 0,
        height ? height->valuedouble : 0,
        supports_streaming ? supports_streaming->valueint : 0
        );

    return _send_media_group_post_request_media_inner_local_var;
end:
    if (caption_entitiesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, caption_entitiesList) {
            message_entity_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(caption_entitiesList);
        caption_entitiesList = NULL;
    }
    return NULL;

}
