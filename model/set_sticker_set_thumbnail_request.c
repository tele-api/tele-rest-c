#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "set_sticker_set_thumbnail_request.h"


char* set_sticker_set_thumbnail_request_format_ToString(telegram_bot_api_set_sticker_set_thumbnail_request_FORMAT_e format) {
    char* formatArray[] =  { "NULL", "static", "animated", "video" };
    return formatArray[format];
}

telegram_bot_api_set_sticker_set_thumbnail_request_FORMAT_e set_sticker_set_thumbnail_request_format_FromString(char* format){
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

static set_sticker_set_thumbnail_request_t *set_sticker_set_thumbnail_request_create_internal(
    char *name,
    int user_id,
    telegram_bot_api_set_sticker_set_thumbnail_request_FORMAT_e format,
    char *thumbnail
    ) {
    set_sticker_set_thumbnail_request_t *set_sticker_set_thumbnail_request_local_var = malloc(sizeof(set_sticker_set_thumbnail_request_t));
    if (!set_sticker_set_thumbnail_request_local_var) {
        return NULL;
    }
    set_sticker_set_thumbnail_request_local_var->name = name;
    set_sticker_set_thumbnail_request_local_var->user_id = user_id;
    set_sticker_set_thumbnail_request_local_var->format = format;
    set_sticker_set_thumbnail_request_local_var->thumbnail = thumbnail;

    set_sticker_set_thumbnail_request_local_var->_library_owned = 1;
    return set_sticker_set_thumbnail_request_local_var;
}

__attribute__((deprecated)) set_sticker_set_thumbnail_request_t *set_sticker_set_thumbnail_request_create(
    char *name,
    int user_id,
    telegram_bot_api_set_sticker_set_thumbnail_request_FORMAT_e format,
    char *thumbnail
    ) {
    return set_sticker_set_thumbnail_request_create_internal (
        name,
        user_id,
        format,
        thumbnail
        );
}

void set_sticker_set_thumbnail_request_free(set_sticker_set_thumbnail_request_t *set_sticker_set_thumbnail_request) {
    if(NULL == set_sticker_set_thumbnail_request){
        return ;
    }
    if(set_sticker_set_thumbnail_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "set_sticker_set_thumbnail_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (set_sticker_set_thumbnail_request->name) {
        free(set_sticker_set_thumbnail_request->name);
        set_sticker_set_thumbnail_request->name = NULL;
    }
    if (set_sticker_set_thumbnail_request->thumbnail) {
        free(set_sticker_set_thumbnail_request->thumbnail);
        set_sticker_set_thumbnail_request->thumbnail = NULL;
    }
    free(set_sticker_set_thumbnail_request);
}

cJSON *set_sticker_set_thumbnail_request_convertToJSON(set_sticker_set_thumbnail_request_t *set_sticker_set_thumbnail_request) {
    cJSON *item = cJSON_CreateObject();

    // set_sticker_set_thumbnail_request->name
    if (!set_sticker_set_thumbnail_request->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", set_sticker_set_thumbnail_request->name) == NULL) {
    goto fail; //String
    }


    // set_sticker_set_thumbnail_request->user_id
    if (!set_sticker_set_thumbnail_request->user_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "user_id", set_sticker_set_thumbnail_request->user_id) == NULL) {
    goto fail; //Numeric
    }


    // set_sticker_set_thumbnail_request->format
    if (telegram_bot_api_set_sticker_set_thumbnail_request_FORMAT_NULL == set_sticker_set_thumbnail_request->format) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "format", set_sticker_set_thumbnail_request_format_ToString(set_sticker_set_thumbnail_request->format)) == NULL)
    {
    goto fail; //Enum
    }


    // set_sticker_set_thumbnail_request->thumbnail
    if(set_sticker_set_thumbnail_request->thumbnail) {
    if(cJSON_AddStringToObject(item, "thumbnail", set_sticker_set_thumbnail_request->thumbnail) == NULL) {
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

set_sticker_set_thumbnail_request_t *set_sticker_set_thumbnail_request_parseFromJSON(cJSON *set_sticker_set_thumbnail_requestJSON){

    set_sticker_set_thumbnail_request_t *set_sticker_set_thumbnail_request_local_var = NULL;

    // set_sticker_set_thumbnail_request->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(set_sticker_set_thumbnail_requestJSON, "name");
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

    // set_sticker_set_thumbnail_request->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(set_sticker_set_thumbnail_requestJSON, "user_id");
    if (cJSON_IsNull(user_id)) {
        user_id = NULL;
    }
    if (!user_id) {
        goto end;
    }

    
    if(!cJSON_IsNumber(user_id))
    {
    goto end; //Numeric
    }

    // set_sticker_set_thumbnail_request->format
    cJSON *format = cJSON_GetObjectItemCaseSensitive(set_sticker_set_thumbnail_requestJSON, "format");
    if (cJSON_IsNull(format)) {
        format = NULL;
    }
    if (!format) {
        goto end;
    }

    telegram_bot_api_set_sticker_set_thumbnail_request_FORMAT_e formatVariable;
    
    if(!cJSON_IsString(format))
    {
    goto end; //Enum
    }
    formatVariable = set_sticker_set_thumbnail_request_format_FromString(format->valuestring);

    // set_sticker_set_thumbnail_request->thumbnail
    cJSON *thumbnail = cJSON_GetObjectItemCaseSensitive(set_sticker_set_thumbnail_requestJSON, "thumbnail");
    if (cJSON_IsNull(thumbnail)) {
        thumbnail = NULL;
    }
    if (thumbnail) { 
    if(!cJSON_IsString(thumbnail) && !cJSON_IsNull(thumbnail))
    {
    goto end; //String
    }
    }


    set_sticker_set_thumbnail_request_local_var = set_sticker_set_thumbnail_request_create_internal (
        strdup(name->valuestring),
        user_id->valuedouble,
        formatVariable,
        thumbnail && !cJSON_IsNull(thumbnail) ? strdup(thumbnail->valuestring) : NULL
        );

    return set_sticker_set_thumbnail_request_local_var;
end:
    return NULL;

}
