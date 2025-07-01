#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "sticker.h"


char* sticker_type_ToString(telegram_bot_api_sticker_TYPE_e type) {
    char* typeArray[] =  { "NULL", "regular", "mask", "custom_emoji" };
    return typeArray[type];
}

telegram_bot_api_sticker_TYPE_e sticker_type_FromString(char* type){
    int stringToReturn = 0;
    char *typeArray[] =  { "NULL", "regular", "mask", "custom_emoji" };
    size_t sizeofArray = sizeof(typeArray) / sizeof(typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(type, typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static sticker_t *sticker_create_internal(
    char *file_id,
    char *file_unique_id,
    telegram_bot_api_sticker_TYPE_e type,
    int width,
    int height,
    int is_animated,
    int is_video,
    photo_size_t *thumbnail,
    char *emoji,
    char *set_name,
    binary_t*_t *premium_animation,
    mask_position_t *mask_position,
    char *custom_emoji_id,
    int needs_repainting,
    int file_size
    ) {
    sticker_t *sticker_local_var = malloc(sizeof(sticker_t));
    if (!sticker_local_var) {
        return NULL;
    }
    sticker_local_var->file_id = file_id;
    sticker_local_var->file_unique_id = file_unique_id;
    sticker_local_var->type = type;
    sticker_local_var->width = width;
    sticker_local_var->height = height;
    sticker_local_var->is_animated = is_animated;
    sticker_local_var->is_video = is_video;
    sticker_local_var->thumbnail = thumbnail;
    sticker_local_var->emoji = emoji;
    sticker_local_var->set_name = set_name;
    sticker_local_var->premium_animation = premium_animation;
    sticker_local_var->mask_position = mask_position;
    sticker_local_var->custom_emoji_id = custom_emoji_id;
    sticker_local_var->needs_repainting = needs_repainting;
    sticker_local_var->file_size = file_size;

    sticker_local_var->_library_owned = 1;
    return sticker_local_var;
}

__attribute__((deprecated)) sticker_t *sticker_create(
    char *file_id,
    char *file_unique_id,
    telegram_bot_api_sticker_TYPE_e type,
    int width,
    int height,
    int is_animated,
    int is_video,
    photo_size_t *thumbnail,
    char *emoji,
    char *set_name,
    binary_t*_t *premium_animation,
    mask_position_t *mask_position,
    char *custom_emoji_id,
    int needs_repainting,
    int file_size
    ) {
    return sticker_create_internal (
        file_id,
        file_unique_id,
        type,
        width,
        height,
        is_animated,
        is_video,
        thumbnail,
        emoji,
        set_name,
        premium_animation,
        mask_position,
        custom_emoji_id,
        needs_repainting,
        file_size
        );
}

void sticker_free(sticker_t *sticker) {
    if(NULL == sticker){
        return ;
    }
    if(sticker->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "sticker_free");
        return ;
    }
    listEntry_t *listEntry;
    if (sticker->file_id) {
        free(sticker->file_id);
        sticker->file_id = NULL;
    }
    if (sticker->file_unique_id) {
        free(sticker->file_unique_id);
        sticker->file_unique_id = NULL;
    }
    if (sticker->thumbnail) {
        photo_size_free(sticker->thumbnail);
        sticker->thumbnail = NULL;
    }
    if (sticker->emoji) {
        free(sticker->emoji);
        sticker->emoji = NULL;
    }
    if (sticker->set_name) {
        free(sticker->set_name);
        sticker->set_name = NULL;
    }
    if (sticker->premium_animation) {
        file_free(sticker->premium_animation);
        sticker->premium_animation = NULL;
    }
    if (sticker->mask_position) {
        mask_position_free(sticker->mask_position);
        sticker->mask_position = NULL;
    }
    if (sticker->custom_emoji_id) {
        free(sticker->custom_emoji_id);
        sticker->custom_emoji_id = NULL;
    }
    free(sticker);
}

cJSON *sticker_convertToJSON(sticker_t *sticker) {
    cJSON *item = cJSON_CreateObject();

    // sticker->file_id
    if (!sticker->file_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "file_id", sticker->file_id) == NULL) {
    goto fail; //String
    }


    // sticker->file_unique_id
    if (!sticker->file_unique_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "file_unique_id", sticker->file_unique_id) == NULL) {
    goto fail; //String
    }


    // sticker->type
    if (telegram_bot_api_sticker_TYPE_NULL == sticker->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", sticker_type_ToString(sticker->type)) == NULL)
    {
    goto fail; //Enum
    }


    // sticker->width
    if (!sticker->width) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "width", sticker->width) == NULL) {
    goto fail; //Numeric
    }


    // sticker->height
    if (!sticker->height) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "height", sticker->height) == NULL) {
    goto fail; //Numeric
    }


    // sticker->is_animated
    if (!sticker->is_animated) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "is_animated", sticker->is_animated) == NULL) {
    goto fail; //Bool
    }


    // sticker->is_video
    if (!sticker->is_video) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "is_video", sticker->is_video) == NULL) {
    goto fail; //Bool
    }


    // sticker->thumbnail
    if(sticker->thumbnail) {
    cJSON *thumbnail_local_JSON = photo_size_convertToJSON(sticker->thumbnail);
    if(thumbnail_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "thumbnail", thumbnail_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // sticker->emoji
    if(sticker->emoji) {
    if(cJSON_AddStringToObject(item, "emoji", sticker->emoji) == NULL) {
    goto fail; //String
    }
    }


    // sticker->set_name
    if(sticker->set_name) {
    if(cJSON_AddStringToObject(item, "set_name", sticker->set_name) == NULL) {
    goto fail; //String
    }
    }


    // sticker->premium_animation
    if(sticker->premium_animation) {
    cJSON *premium_animation_local_JSON = file_convertToJSON(sticker->premium_animation);
    if(premium_animation_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "premium_animation", premium_animation_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // sticker->mask_position
    if(sticker->mask_position) {
    cJSON *mask_position_local_JSON = mask_position_convertToJSON(sticker->mask_position);
    if(mask_position_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "mask_position", mask_position_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // sticker->custom_emoji_id
    if(sticker->custom_emoji_id) {
    if(cJSON_AddStringToObject(item, "custom_emoji_id", sticker->custom_emoji_id) == NULL) {
    goto fail; //String
    }
    }


    // sticker->needs_repainting
    if(sticker->needs_repainting) {
    if(cJSON_AddBoolToObject(item, "needs_repainting", sticker->needs_repainting) == NULL) {
    goto fail; //Bool
    }
    }


    // sticker->file_size
    if(sticker->file_size) {
    if(cJSON_AddNumberToObject(item, "file_size", sticker->file_size) == NULL) {
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

sticker_t *sticker_parseFromJSON(cJSON *stickerJSON){

    sticker_t *sticker_local_var = NULL;

    // define the local variable for sticker->thumbnail
    photo_size_t *thumbnail_local_nonprim = NULL;

    // define the local variable for sticker->premium_animation
    file_t *premium_animation_local_nonprim = NULL;

    // define the local variable for sticker->mask_position
    mask_position_t *mask_position_local_nonprim = NULL;

    // sticker->file_id
    cJSON *file_id = cJSON_GetObjectItemCaseSensitive(stickerJSON, "file_id");
    if (cJSON_IsNull(file_id)) {
        file_id = NULL;
    }
    if (!file_id) {
        goto end;
    }

    
    if(!cJSON_IsString(file_id))
    {
    goto end; //String
    }

    // sticker->file_unique_id
    cJSON *file_unique_id = cJSON_GetObjectItemCaseSensitive(stickerJSON, "file_unique_id");
    if (cJSON_IsNull(file_unique_id)) {
        file_unique_id = NULL;
    }
    if (!file_unique_id) {
        goto end;
    }

    
    if(!cJSON_IsString(file_unique_id))
    {
    goto end; //String
    }

    // sticker->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(stickerJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    telegram_bot_api_sticker_TYPE_e typeVariable;
    
    if(!cJSON_IsString(type))
    {
    goto end; //Enum
    }
    typeVariable = sticker_type_FromString(type->valuestring);

    // sticker->width
    cJSON *width = cJSON_GetObjectItemCaseSensitive(stickerJSON, "width");
    if (cJSON_IsNull(width)) {
        width = NULL;
    }
    if (!width) {
        goto end;
    }

    
    if(!cJSON_IsNumber(width))
    {
    goto end; //Numeric
    }

    // sticker->height
    cJSON *height = cJSON_GetObjectItemCaseSensitive(stickerJSON, "height");
    if (cJSON_IsNull(height)) {
        height = NULL;
    }
    if (!height) {
        goto end;
    }

    
    if(!cJSON_IsNumber(height))
    {
    goto end; //Numeric
    }

    // sticker->is_animated
    cJSON *is_animated = cJSON_GetObjectItemCaseSensitive(stickerJSON, "is_animated");
    if (cJSON_IsNull(is_animated)) {
        is_animated = NULL;
    }
    if (!is_animated) {
        goto end;
    }

    
    if(!cJSON_IsBool(is_animated))
    {
    goto end; //Bool
    }

    // sticker->is_video
    cJSON *is_video = cJSON_GetObjectItemCaseSensitive(stickerJSON, "is_video");
    if (cJSON_IsNull(is_video)) {
        is_video = NULL;
    }
    if (!is_video) {
        goto end;
    }

    
    if(!cJSON_IsBool(is_video))
    {
    goto end; //Bool
    }

    // sticker->thumbnail
    cJSON *thumbnail = cJSON_GetObjectItemCaseSensitive(stickerJSON, "thumbnail");
    if (cJSON_IsNull(thumbnail)) {
        thumbnail = NULL;
    }
    if (thumbnail) { 
    thumbnail_local_nonprim = photo_size_parseFromJSON(thumbnail); //nonprimitive
    }

    // sticker->emoji
    cJSON *emoji = cJSON_GetObjectItemCaseSensitive(stickerJSON, "emoji");
    if (cJSON_IsNull(emoji)) {
        emoji = NULL;
    }
    if (emoji) { 
    if(!cJSON_IsString(emoji) && !cJSON_IsNull(emoji))
    {
    goto end; //String
    }
    }

    // sticker->set_name
    cJSON *set_name = cJSON_GetObjectItemCaseSensitive(stickerJSON, "set_name");
    if (cJSON_IsNull(set_name)) {
        set_name = NULL;
    }
    if (set_name) { 
    if(!cJSON_IsString(set_name) && !cJSON_IsNull(set_name))
    {
    goto end; //String
    }
    }

    // sticker->premium_animation
    cJSON *premium_animation = cJSON_GetObjectItemCaseSensitive(stickerJSON, "premium_animation");
    if (cJSON_IsNull(premium_animation)) {
        premium_animation = NULL;
    }
    if (premium_animation) { 
    premium_animation_local_nonprim = file_parseFromJSON(premium_animation); //nonprimitive
    }

    // sticker->mask_position
    cJSON *mask_position = cJSON_GetObjectItemCaseSensitive(stickerJSON, "mask_position");
    if (cJSON_IsNull(mask_position)) {
        mask_position = NULL;
    }
    if (mask_position) { 
    mask_position_local_nonprim = mask_position_parseFromJSON(mask_position); //nonprimitive
    }

    // sticker->custom_emoji_id
    cJSON *custom_emoji_id = cJSON_GetObjectItemCaseSensitive(stickerJSON, "custom_emoji_id");
    if (cJSON_IsNull(custom_emoji_id)) {
        custom_emoji_id = NULL;
    }
    if (custom_emoji_id) { 
    if(!cJSON_IsString(custom_emoji_id) && !cJSON_IsNull(custom_emoji_id))
    {
    goto end; //String
    }
    }

    // sticker->needs_repainting
    cJSON *needs_repainting = cJSON_GetObjectItemCaseSensitive(stickerJSON, "needs_repainting");
    if (cJSON_IsNull(needs_repainting)) {
        needs_repainting = NULL;
    }
    if (needs_repainting) { 
    if(!cJSON_IsBool(needs_repainting))
    {
    goto end; //Bool
    }
    }

    // sticker->file_size
    cJSON *file_size = cJSON_GetObjectItemCaseSensitive(stickerJSON, "file_size");
    if (cJSON_IsNull(file_size)) {
        file_size = NULL;
    }
    if (file_size) { 
    if(!cJSON_IsNumber(file_size))
    {
    goto end; //Numeric
    }
    }


    sticker_local_var = sticker_create_internal (
        strdup(file_id->valuestring),
        strdup(file_unique_id->valuestring),
        typeVariable,
        width->valuedouble,
        height->valuedouble,
        is_animated->valueint,
        is_video->valueint,
        thumbnail ? thumbnail_local_nonprim : NULL,
        emoji && !cJSON_IsNull(emoji) ? strdup(emoji->valuestring) : NULL,
        set_name && !cJSON_IsNull(set_name) ? strdup(set_name->valuestring) : NULL,
        premium_animation ? premium_animation_local_nonprim : NULL,
        mask_position ? mask_position_local_nonprim : NULL,
        custom_emoji_id && !cJSON_IsNull(custom_emoji_id) ? strdup(custom_emoji_id->valuestring) : NULL,
        needs_repainting ? needs_repainting->valueint : 0,
        file_size ? file_size->valuedouble : 0
        );

    return sticker_local_var;
end:
    if (thumbnail_local_nonprim) {
        photo_size_free(thumbnail_local_nonprim);
        thumbnail_local_nonprim = NULL;
    }
    if (premium_animation_local_nonprim) {
        file_free(premium_animation_local_nonprim);
        premium_animation_local_nonprim = NULL;
    }
    if (mask_position_local_nonprim) {
        mask_position_free(mask_position_local_nonprim);
        mask_position_local_nonprim = NULL;
    }
    return NULL;

}
