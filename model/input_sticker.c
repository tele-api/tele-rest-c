#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "input_sticker.h"


char* input_sticker_format_ToString(telegram_bot_api_input_sticker_FORMAT_e format) {
    char* formatArray[] =  { "NULL", "static", "animated", "video" };
    return formatArray[format];
}

telegram_bot_api_input_sticker_FORMAT_e input_sticker_format_FromString(char* format){
    int stringToReturn = 0;
    char *formatArray[] =  { "NULL", "static", "animated", "video" };
    size_t sizeofArray = sizeof(formatArray) / sizeof(formatArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(format, formatArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static input_sticker_t *input_sticker_create_internal(
    char *sticker,
    telegram_bot_api_input_sticker_FORMAT_e format,
    list_t *emoji_list,
    mask_position_t *mask_position,
    list_t *keywords
    ) {
    input_sticker_t *input_sticker_local_var = malloc(sizeof(input_sticker_t));
    if (!input_sticker_local_var) {
        return NULL;
    }
    input_sticker_local_var->sticker = sticker;
    input_sticker_local_var->format = format;
    input_sticker_local_var->emoji_list = emoji_list;
    input_sticker_local_var->mask_position = mask_position;
    input_sticker_local_var->keywords = keywords;

    input_sticker_local_var->_library_owned = 1;
    return input_sticker_local_var;
}

__attribute__((deprecated)) input_sticker_t *input_sticker_create(
    char *sticker,
    telegram_bot_api_input_sticker_FORMAT_e format,
    list_t *emoji_list,
    mask_position_t *mask_position,
    list_t *keywords
    ) {
    return input_sticker_create_internal (
        sticker,
        format,
        emoji_list,
        mask_position,
        keywords
        );
}

void input_sticker_free(input_sticker_t *input_sticker) {
    if(NULL == input_sticker){
        return ;
    }
    if(input_sticker->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "input_sticker_free");
        return ;
    }
    listEntry_t *listEntry;
    if (input_sticker->sticker) {
        free(input_sticker->sticker);
        input_sticker->sticker = NULL;
    }
    if (input_sticker->emoji_list) {
        list_ForEach(listEntry, input_sticker->emoji_list) {
            free(listEntry->data);
        }
        list_freeList(input_sticker->emoji_list);
        input_sticker->emoji_list = NULL;
    }
    if (input_sticker->mask_position) {
        mask_position_free(input_sticker->mask_position);
        input_sticker->mask_position = NULL;
    }
    if (input_sticker->keywords) {
        list_ForEach(listEntry, input_sticker->keywords) {
            free(listEntry->data);
        }
        list_freeList(input_sticker->keywords);
        input_sticker->keywords = NULL;
    }
    free(input_sticker);
}

cJSON *input_sticker_convertToJSON(input_sticker_t *input_sticker) {
    cJSON *item = cJSON_CreateObject();

    // input_sticker->sticker
    if (!input_sticker->sticker) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "sticker", input_sticker->sticker) == NULL) {
    goto fail; //String
    }


    // input_sticker->format
    if (telegram_bot_api_input_sticker_FORMAT_NULL == input_sticker->format) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "format", input_sticker_format_ToString(input_sticker->format)) == NULL)
    {
    goto fail; //Enum
    }


    // input_sticker->emoji_list
    if (!input_sticker->emoji_list) {
        goto fail;
    }
    cJSON *emoji_list = cJSON_AddArrayToObject(item, "emoji_list");
    if(emoji_list == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *emoji_listListEntry;
    list_ForEach(emoji_listListEntry, input_sticker->emoji_list) {
    if(cJSON_AddStringToObject(emoji_list, "", emoji_listListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // input_sticker->mask_position
    if(input_sticker->mask_position) {
    cJSON *mask_position_local_JSON = mask_position_convertToJSON(input_sticker->mask_position);
    if(mask_position_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "mask_position", mask_position_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // input_sticker->keywords
    if(input_sticker->keywords) {
    cJSON *keywords = cJSON_AddArrayToObject(item, "keywords");
    if(keywords == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *keywordsListEntry;
    list_ForEach(keywordsListEntry, input_sticker->keywords) {
    if(cJSON_AddStringToObject(keywords, "", keywordsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

input_sticker_t *input_sticker_parseFromJSON(cJSON *input_stickerJSON){

    input_sticker_t *input_sticker_local_var = NULL;

    // define the local list for input_sticker->emoji_list
    list_t *emoji_listList = NULL;

    // define the local variable for input_sticker->mask_position
    mask_position_t *mask_position_local_nonprim = NULL;

    // define the local list for input_sticker->keywords
    list_t *keywordsList = NULL;

    // input_sticker->sticker
    cJSON *sticker = cJSON_GetObjectItemCaseSensitive(input_stickerJSON, "sticker");
    if (cJSON_IsNull(sticker)) {
        sticker = NULL;
    }
    if (!sticker) {
        goto end;
    }

    
    if(!cJSON_IsString(sticker))
    {
    goto end; //String
    }

    // input_sticker->format
    cJSON *format = cJSON_GetObjectItemCaseSensitive(input_stickerJSON, "format");
    if (cJSON_IsNull(format)) {
        format = NULL;
    }
    if (!format) {
        goto end;
    }

    telegram_bot_api_input_sticker_FORMAT_e formatVariable;
    
    if(!cJSON_IsString(format))
    {
    goto end; //Enum
    }
    formatVariable = input_sticker_format_FromString(format->valuestring);

    // input_sticker->emoji_list
    cJSON *emoji_list = cJSON_GetObjectItemCaseSensitive(input_stickerJSON, "emoji_list");
    if (cJSON_IsNull(emoji_list)) {
        emoji_list = NULL;
    }
    if (!emoji_list) {
        goto end;
    }

    
    cJSON *emoji_list_local = NULL;
    if(!cJSON_IsArray(emoji_list)) {
        goto end;//primitive container
    }
    emoji_listList = list_createList();

    cJSON_ArrayForEach(emoji_list_local, emoji_list)
    {
        if(!cJSON_IsString(emoji_list_local))
        {
            goto end;
        }
        list_addElement(emoji_listList , strdup(emoji_list_local->valuestring));
    }

    // input_sticker->mask_position
    cJSON *mask_position = cJSON_GetObjectItemCaseSensitive(input_stickerJSON, "mask_position");
    if (cJSON_IsNull(mask_position)) {
        mask_position = NULL;
    }
    if (mask_position) { 
    mask_position_local_nonprim = mask_position_parseFromJSON(mask_position); //nonprimitive
    }

    // input_sticker->keywords
    cJSON *keywords = cJSON_GetObjectItemCaseSensitive(input_stickerJSON, "keywords");
    if (cJSON_IsNull(keywords)) {
        keywords = NULL;
    }
    if (keywords) { 
    cJSON *keywords_local = NULL;
    if(!cJSON_IsArray(keywords)) {
        goto end;//primitive container
    }
    keywordsList = list_createList();

    cJSON_ArrayForEach(keywords_local, keywords)
    {
        if(!cJSON_IsString(keywords_local))
        {
            goto end;
        }
        list_addElement(keywordsList , strdup(keywords_local->valuestring));
    }
    }


    input_sticker_local_var = input_sticker_create_internal (
        strdup(sticker->valuestring),
        formatVariable,
        emoji_listList,
        mask_position ? mask_position_local_nonprim : NULL,
        keywords ? keywordsList : NULL
        );

    return input_sticker_local_var;
end:
    if (emoji_listList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, emoji_listList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(emoji_listList);
        emoji_listList = NULL;
    }
    if (mask_position_local_nonprim) {
        mask_position_free(mask_position_local_nonprim);
        mask_position_local_nonprim = NULL;
    }
    if (keywordsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, keywordsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(keywordsList);
        keywordsList = NULL;
    }
    return NULL;

}
