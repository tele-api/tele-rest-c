#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "upload_sticker_file_request.h"


char* upload_sticker_file_request_sticker_format_ToString(telegram_bot_api_upload_sticker_file_request_STICKERFORMAT_e sticker_format) {
    char* sticker_formatArray[] =  { "NULL", "static", "animated", "video" };
    return sticker_formatArray[sticker_format];
}

telegram_bot_api_upload_sticker_file_request_STICKERFORMAT_e upload_sticker_file_request_sticker_format_FromString(char* sticker_format){
    int stringToReturn = 0;
    char *sticker_formatArray[] =  { "NULL", "static", "animated", "video" };
    size_t sizeofArray = sizeof(sticker_formatArray) / sizeof(sticker_formatArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(sticker_format, sticker_formatArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static upload_sticker_file_request_t *upload_sticker_file_request_create_internal(
    int user_id,
    any_type_t *sticker,
    telegram_bot_api_upload_sticker_file_request_STICKERFORMAT_e sticker_format
    ) {
    upload_sticker_file_request_t *upload_sticker_file_request_local_var = malloc(sizeof(upload_sticker_file_request_t));
    if (!upload_sticker_file_request_local_var) {
        return NULL;
    }
    upload_sticker_file_request_local_var->user_id = user_id;
    upload_sticker_file_request_local_var->sticker = sticker;
    upload_sticker_file_request_local_var->sticker_format = sticker_format;

    upload_sticker_file_request_local_var->_library_owned = 1;
    return upload_sticker_file_request_local_var;
}

__attribute__((deprecated)) upload_sticker_file_request_t *upload_sticker_file_request_create(
    int user_id,
    any_type_t *sticker,
    telegram_bot_api_upload_sticker_file_request_STICKERFORMAT_e sticker_format
    ) {
    return upload_sticker_file_request_create_internal (
        user_id,
        sticker,
        sticker_format
        );
}

void upload_sticker_file_request_free(upload_sticker_file_request_t *upload_sticker_file_request) {
    if(NULL == upload_sticker_file_request){
        return ;
    }
    if(upload_sticker_file_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "upload_sticker_file_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (upload_sticker_file_request->sticker) {
        _free(upload_sticker_file_request->sticker);
        upload_sticker_file_request->sticker = NULL;
    }
    free(upload_sticker_file_request);
}

cJSON *upload_sticker_file_request_convertToJSON(upload_sticker_file_request_t *upload_sticker_file_request) {
    cJSON *item = cJSON_CreateObject();

    // upload_sticker_file_request->user_id
    if (!upload_sticker_file_request->user_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "user_id", upload_sticker_file_request->user_id) == NULL) {
    goto fail; //Numeric
    }


    // upload_sticker_file_request->sticker
    if (!upload_sticker_file_request->sticker) {
        goto fail;
    }
    cJSON *sticker_local_JSON = _convertToJSON(upload_sticker_file_request->sticker);
    if(sticker_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "sticker", sticker_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // upload_sticker_file_request->sticker_format
    if (telegram_bot_api_upload_sticker_file_request_STICKERFORMAT_NULL == upload_sticker_file_request->sticker_format) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "sticker_format", upload_sticker_file_request_sticker_format_ToString(upload_sticker_file_request->sticker_format)) == NULL)
    {
    goto fail; //Enum
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

upload_sticker_file_request_t *upload_sticker_file_request_parseFromJSON(cJSON *upload_sticker_file_requestJSON){

    upload_sticker_file_request_t *upload_sticker_file_request_local_var = NULL;

    // define the local variable for upload_sticker_file_request->sticker
    _t *sticker_local_nonprim = NULL;

    // upload_sticker_file_request->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(upload_sticker_file_requestJSON, "user_id");
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

    // upload_sticker_file_request->sticker
    cJSON *sticker = cJSON_GetObjectItemCaseSensitive(upload_sticker_file_requestJSON, "sticker");
    if (cJSON_IsNull(sticker)) {
        sticker = NULL;
    }
    if (!sticker) {
        goto end;
    }

    
    sticker_local_nonprim = _parseFromJSON(sticker); //custom

    // upload_sticker_file_request->sticker_format
    cJSON *sticker_format = cJSON_GetObjectItemCaseSensitive(upload_sticker_file_requestJSON, "sticker_format");
    if (cJSON_IsNull(sticker_format)) {
        sticker_format = NULL;
    }
    if (!sticker_format) {
        goto end;
    }

    telegram_bot_api_upload_sticker_file_request_STICKERFORMAT_e sticker_formatVariable;
    
    if(!cJSON_IsString(sticker_format))
    {
    goto end; //Enum
    }
    sticker_formatVariable = upload_sticker_file_request_sticker_format_FromString(sticker_format->valuestring);


    upload_sticker_file_request_local_var = upload_sticker_file_request_create_internal (
        user_id->valuedouble,
        sticker_local_nonprim,
        sticker_formatVariable
        );

    return upload_sticker_file_request_local_var;
end:
    if (sticker_local_nonprim) {
        _free(sticker_local_nonprim);
        sticker_local_nonprim = NULL;
    }
    return NULL;

}
