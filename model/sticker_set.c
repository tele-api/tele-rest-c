#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "sticker_set.h"


char* sticker_set_sticker_type_ToString(telegram_bot_api_sticker_set_STICKERTYPE_e sticker_type) {
    char* sticker_typeArray[] =  { "NULL", "regular", "mask", "custom_emoji" };
    return sticker_typeArray[sticker_type];
}

telegram_bot_api_sticker_set_STICKERTYPE_e sticker_set_sticker_type_FromString(char* sticker_type){
    int stringToReturn = 0;
    char *sticker_typeArray[] =  { "NULL", "regular", "mask", "custom_emoji" };
    size_t sizeofArray = sizeof(sticker_typeArray) / sizeof(sticker_typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(sticker_type, sticker_typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static sticker_set_t *sticker_set_create_internal(
    char *name,
    char *title,
    telegram_bot_api_sticker_set_STICKERTYPE_e sticker_type,
    list_t *stickers,
    photo_size_t *thumbnail
    ) {
    sticker_set_t *sticker_set_local_var = malloc(sizeof(sticker_set_t));
    if (!sticker_set_local_var) {
        return NULL;
    }
    sticker_set_local_var->name = name;
    sticker_set_local_var->title = title;
    sticker_set_local_var->sticker_type = sticker_type;
    sticker_set_local_var->stickers = stickers;
    sticker_set_local_var->thumbnail = thumbnail;

    sticker_set_local_var->_library_owned = 1;
    return sticker_set_local_var;
}

__attribute__((deprecated)) sticker_set_t *sticker_set_create(
    char *name,
    char *title,
    telegram_bot_api_sticker_set_STICKERTYPE_e sticker_type,
    list_t *stickers,
    photo_size_t *thumbnail
    ) {
    return sticker_set_create_internal (
        name,
        title,
        sticker_type,
        stickers,
        thumbnail
        );
}

void sticker_set_free(sticker_set_t *sticker_set) {
    if(NULL == sticker_set){
        return ;
    }
    if(sticker_set->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "sticker_set_free");
        return ;
    }
    listEntry_t *listEntry;
    if (sticker_set->name) {
        free(sticker_set->name);
        sticker_set->name = NULL;
    }
    if (sticker_set->title) {
        free(sticker_set->title);
        sticker_set->title = NULL;
    }
    if (sticker_set->stickers) {
        list_ForEach(listEntry, sticker_set->stickers) {
            sticker_free(listEntry->data);
        }
        list_freeList(sticker_set->stickers);
        sticker_set->stickers = NULL;
    }
    if (sticker_set->thumbnail) {
        photo_size_free(sticker_set->thumbnail);
        sticker_set->thumbnail = NULL;
    }
    free(sticker_set);
}

cJSON *sticker_set_convertToJSON(sticker_set_t *sticker_set) {
    cJSON *item = cJSON_CreateObject();

    // sticker_set->name
    if (!sticker_set->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", sticker_set->name) == NULL) {
    goto fail; //String
    }


    // sticker_set->title
    if (!sticker_set->title) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "title", sticker_set->title) == NULL) {
    goto fail; //String
    }


    // sticker_set->sticker_type
    if (telegram_bot_api_sticker_set_STICKERTYPE_NULL == sticker_set->sticker_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "sticker_type", sticker_set_sticker_type_ToString(sticker_set->sticker_type)) == NULL)
    {
    goto fail; //Enum
    }


    // sticker_set->stickers
    if (!sticker_set->stickers) {
        goto fail;
    }
    cJSON *stickers = cJSON_AddArrayToObject(item, "stickers");
    if(stickers == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *stickersListEntry;
    if (sticker_set->stickers) {
    list_ForEach(stickersListEntry, sticker_set->stickers) {
    cJSON *itemLocal = sticker_convertToJSON(stickersListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(stickers, itemLocal);
    }
    }


    // sticker_set->thumbnail
    if(sticker_set->thumbnail) {
    cJSON *thumbnail_local_JSON = photo_size_convertToJSON(sticker_set->thumbnail);
    if(thumbnail_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "thumbnail", thumbnail_local_JSON);
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

sticker_set_t *sticker_set_parseFromJSON(cJSON *sticker_setJSON){

    sticker_set_t *sticker_set_local_var = NULL;

    // define the local list for sticker_set->stickers
    list_t *stickersList = NULL;

    // define the local variable for sticker_set->thumbnail
    photo_size_t *thumbnail_local_nonprim = NULL;

    // sticker_set->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(sticker_setJSON, "name");
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

    // sticker_set->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(sticker_setJSON, "title");
    if (cJSON_IsNull(title)) {
        title = NULL;
    }
    if (!title) {
        goto end;
    }

    
    if(!cJSON_IsString(title))
    {
    goto end; //String
    }

    // sticker_set->sticker_type
    cJSON *sticker_type = cJSON_GetObjectItemCaseSensitive(sticker_setJSON, "sticker_type");
    if (cJSON_IsNull(sticker_type)) {
        sticker_type = NULL;
    }
    if (!sticker_type) {
        goto end;
    }

    telegram_bot_api_sticker_set_STICKERTYPE_e sticker_typeVariable;
    
    if(!cJSON_IsString(sticker_type))
    {
    goto end; //Enum
    }
    sticker_typeVariable = sticker_set_sticker_type_FromString(sticker_type->valuestring);

    // sticker_set->stickers
    cJSON *stickers = cJSON_GetObjectItemCaseSensitive(sticker_setJSON, "stickers");
    if (cJSON_IsNull(stickers)) {
        stickers = NULL;
    }
    if (!stickers) {
        goto end;
    }

    
    cJSON *stickers_local_nonprimitive = NULL;
    if(!cJSON_IsArray(stickers)){
        goto end; //nonprimitive container
    }

    stickersList = list_createList();

    cJSON_ArrayForEach(stickers_local_nonprimitive,stickers )
    {
        if(!cJSON_IsObject(stickers_local_nonprimitive)){
            goto end;
        }
        sticker_t *stickersItem = sticker_parseFromJSON(stickers_local_nonprimitive);

        list_addElement(stickersList, stickersItem);
    }

    // sticker_set->thumbnail
    cJSON *thumbnail = cJSON_GetObjectItemCaseSensitive(sticker_setJSON, "thumbnail");
    if (cJSON_IsNull(thumbnail)) {
        thumbnail = NULL;
    }
    if (thumbnail) { 
    thumbnail_local_nonprim = photo_size_parseFromJSON(thumbnail); //nonprimitive
    }


    sticker_set_local_var = sticker_set_create_internal (
        strdup(name->valuestring),
        strdup(title->valuestring),
        sticker_typeVariable,
        stickersList,
        thumbnail ? thumbnail_local_nonprim : NULL
        );

    return sticker_set_local_var;
end:
    if (stickersList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, stickersList) {
            sticker_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(stickersList);
        stickersList = NULL;
    }
    if (thumbnail_local_nonprim) {
        photo_size_free(thumbnail_local_nonprim);
        thumbnail_local_nonprim = NULL;
    }
    return NULL;

}
