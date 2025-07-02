#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "DefaultAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096

// Functions for enum ICONCOLOR for DefaultAPI_postCreateForumTopic

static char* postCreateForumTopic_ICONCOLOR_ToString(telegram_bot_api_postCreateForumTopic_icon_color_e ICONCOLOR){
    char *ICONCOLORArray[] =  { "NULL", "7322096", "16766590", "13338331", "9367192", "16749490", "16478047" };
    return ICONCOLORArray[ICONCOLOR];
}

static telegram_bot_api_postCreateForumTopic_icon_color_e postCreateForumTopic_ICONCOLOR_FromString(char* ICONCOLOR){
    int stringToReturn = 0;
    char *ICONCOLORArray[] =  { "NULL", "7322096", "16766590", "13338331", "9367192", "16749490", "16478047" };
    size_t sizeofArray = sizeof(ICONCOLORArray) / sizeof(ICONCOLORArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(ICONCOLOR, ICONCOLORArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

/*
// Function postCreateForumTopic_ICONCOLOR_convertToJSON is not currently used,
// since conversion to JSON passes through the conversion of the model, and ToString. The function is kept for future reference.
//
static cJSON *postCreateForumTopic_ICONCOLOR_convertToJSON(telegram_bot_api_postCreateForumTopic_icon_color_e ICONCOLOR) {
    cJSON *item = cJSON_CreateObject();
    return item;
    fail:
    cJSON_Delete(item);
    return NULL;
}

// Function postCreateForumTopic_ICONCOLOR_parseFromJSON is not currently used,
// since conversion from JSON passes through the conversion of the model, and FromString. The function is kept for future reference.
//
static telegram_bot_api_postCreateForumTopic_icon_color_e postCreateForumTopic_ICONCOLOR_parseFromJSON(cJSON* ICONCOLORJSON) {
    telegram_bot_api_postCreateForumTopic_icon_color_e ICONCOLORVariable = 0;
    return ICONCOLORVariable;
end:
    return 0;
}
*/

// Functions for enum STICKERTYPE for DefaultAPI_postCreateNewStickerSet

static char* postCreateNewStickerSet_STICKERTYPE_ToString(telegram_bot_api_postCreateNewStickerSet_sticker_type_e STICKERTYPE){
    char *STICKERTYPEArray[] =  { "NULL", "mask", "custom_emoji" };
    return STICKERTYPEArray[STICKERTYPE];
}

static telegram_bot_api_postCreateNewStickerSet_sticker_type_e postCreateNewStickerSet_STICKERTYPE_FromString(char* STICKERTYPE){
    int stringToReturn = 0;
    char *STICKERTYPEArray[] =  { "NULL", "mask", "custom_emoji" };
    size_t sizeofArray = sizeof(STICKERTYPEArray) / sizeof(STICKERTYPEArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(STICKERTYPE, STICKERTYPEArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

/*
// Function postCreateNewStickerSet_STICKERTYPE_convertToJSON is not currently used,
// since conversion to JSON passes through the conversion of the model, and ToString. The function is kept for future reference.
//
static cJSON *postCreateNewStickerSet_STICKERTYPE_convertToJSON(telegram_bot_api_postCreateNewStickerSet_sticker_type_e STICKERTYPE) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "sticker_type", postCreateNewStickerSet_STICKERTYPE_ToString(STICKERTYPE)) == NULL) {
        goto fail;
    }
    return item;
    fail:
    cJSON_Delete(item);
    return NULL;
}

// Function postCreateNewStickerSet_STICKERTYPE_parseFromJSON is not currently used,
// since conversion from JSON passes through the conversion of the model, and FromString. The function is kept for future reference.
//
static telegram_bot_api_postCreateNewStickerSet_sticker_type_e postCreateNewStickerSet_STICKERTYPE_parseFromJSON(cJSON* STICKERTYPEJSON) {
    telegram_bot_api_postCreateNewStickerSet_sticker_type_e STICKERTYPEVariable = 0;
    cJSON *STICKERTYPEVar = cJSON_GetObjectItemCaseSensitive(STICKERTYPEJSON, "sticker_type");
    if(!cJSON_IsString(STICKERTYPEVar) || (STICKERTYPEVar->valuestring == NULL))
    {
        goto end;
    }
    STICKERTYPEVariable = postCreateNewStickerSet_STICKERTYPE_FromString(STICKERTYPEVar->valuestring);
    return STICKERTYPEVariable;
end:
    return 0;
}
*/

// Functions for enum MONTHCOUNT for DefaultAPI_postGiftPremiumSubscription

static char* postGiftPremiumSubscription_MONTHCOUNT_ToString(telegram_bot_api_postGiftPremiumSubscription_month_count_e MONTHCOUNT){
    char *MONTHCOUNTArray[] =  { "NULL", "3", "6", "12" };
    return MONTHCOUNTArray[MONTHCOUNT];
}

static telegram_bot_api_postGiftPremiumSubscription_month_count_e postGiftPremiumSubscription_MONTHCOUNT_FromString(char* MONTHCOUNT){
    int stringToReturn = 0;
    char *MONTHCOUNTArray[] =  { "NULL", "3", "6", "12" };
    size_t sizeofArray = sizeof(MONTHCOUNTArray) / sizeof(MONTHCOUNTArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(MONTHCOUNT, MONTHCOUNTArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

/*
// Function postGiftPremiumSubscription_MONTHCOUNT_convertToJSON is not currently used,
// since conversion to JSON passes through the conversion of the model, and ToString. The function is kept for future reference.
//
static cJSON *postGiftPremiumSubscription_MONTHCOUNT_convertToJSON(telegram_bot_api_postGiftPremiumSubscription_month_count_e MONTHCOUNT) {
    cJSON *item = cJSON_CreateObject();
    return item;
    fail:
    cJSON_Delete(item);
    return NULL;
}

// Function postGiftPremiumSubscription_MONTHCOUNT_parseFromJSON is not currently used,
// since conversion from JSON passes through the conversion of the model, and FromString. The function is kept for future reference.
//
static telegram_bot_api_postGiftPremiumSubscription_month_count_e postGiftPremiumSubscription_MONTHCOUNT_parseFromJSON(cJSON* MONTHCOUNTJSON) {
    telegram_bot_api_postGiftPremiumSubscription_month_count_e MONTHCOUNTVariable = 0;
    return MONTHCOUNTVariable;
end:
    return 0;
}
*/

// Functions for enum ACTIVEPERIOD for DefaultAPI_postPostStory

static char* postPostStory_ACTIVEPERIOD_ToString(telegram_bot_api_postPostStory_active_period_e ACTIVEPERIOD){
    char *ACTIVEPERIODArray[] =  { "NULL", "86400" };
    return ACTIVEPERIODArray[ACTIVEPERIOD];
}

static telegram_bot_api_postPostStory_active_period_e postPostStory_ACTIVEPERIOD_FromString(char* ACTIVEPERIOD){
    int stringToReturn = 0;
    char *ACTIVEPERIODArray[] =  { "NULL", "86400" };
    size_t sizeofArray = sizeof(ACTIVEPERIODArray) / sizeof(ACTIVEPERIODArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(ACTIVEPERIOD, ACTIVEPERIODArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

/*
// Function postPostStory_ACTIVEPERIOD_convertToJSON is not currently used,
// since conversion to JSON passes through the conversion of the model, and ToString. The function is kept for future reference.
//
static cJSON *postPostStory_ACTIVEPERIOD_convertToJSON(telegram_bot_api_postPostStory_active_period_e ACTIVEPERIOD) {
    cJSON *item = cJSON_CreateObject();
    return item;
    fail:
    cJSON_Delete(item);
    return NULL;
}

// Function postPostStory_ACTIVEPERIOD_parseFromJSON is not currently used,
// since conversion from JSON passes through the conversion of the model, and FromString. The function is kept for future reference.
//
static telegram_bot_api_postPostStory_active_period_e postPostStory_ACTIVEPERIOD_parseFromJSON(cJSON* ACTIVEPERIODJSON) {
    telegram_bot_api_postPostStory_active_period_e ACTIVEPERIODVariable = 0;
    return ACTIVEPERIODVariable;
end:
    return 0;
}
*/

// Functions for enum ACTION for DefaultAPI_postSendChatAction

static char* postSendChatAction_ACTION_ToString(telegram_bot_api_postSendChatAction_action_e ACTION){
    char *ACTIONArray[] =  { "NULL", "typing", "upload_photo", "record_video", "upload_video", "record_voice", "upload_voice", "upload_document", "choose_sticker", "find_location", "record_video_note", "upload_video_note" };
    return ACTIONArray[ACTION];
}

static telegram_bot_api_postSendChatAction_action_e postSendChatAction_ACTION_FromString(char* ACTION){
    int stringToReturn = 0;
    char *ACTIONArray[] =  { "NULL", "typing", "upload_photo", "record_video", "upload_video", "record_voice", "upload_voice", "upload_document", "choose_sticker", "find_location", "record_video_note", "upload_video_note" };
    size_t sizeofArray = sizeof(ACTIONArray) / sizeof(ACTIONArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(ACTION, ACTIONArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

/*
// Function postSendChatAction_ACTION_convertToJSON is not currently used,
// since conversion to JSON passes through the conversion of the model, and ToString. The function is kept for future reference.
//
static cJSON *postSendChatAction_ACTION_convertToJSON(telegram_bot_api_postSendChatAction_action_e ACTION) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "action", postSendChatAction_ACTION_ToString(ACTION)) == NULL) {
        goto fail;
    }
    return item;
    fail:
    cJSON_Delete(item);
    return NULL;
}

// Function postSendChatAction_ACTION_parseFromJSON is not currently used,
// since conversion from JSON passes through the conversion of the model, and FromString. The function is kept for future reference.
//
static telegram_bot_api_postSendChatAction_action_e postSendChatAction_ACTION_parseFromJSON(cJSON* ACTIONJSON) {
    telegram_bot_api_postSendChatAction_action_e ACTIONVariable = 0;
    cJSON *ACTIONVar = cJSON_GetObjectItemCaseSensitive(ACTIONJSON, "action");
    if(!cJSON_IsString(ACTIONVar) || (ACTIONVar->valuestring == NULL))
    {
        goto end;
    }
    ACTIONVariable = postSendChatAction_ACTION_FromString(ACTIONVar->valuestring);
    return ACTIONVariable;
end:
    return 0;
}
*/

// Functions for enum EMOJI for DefaultAPI_postSendDice

static char* postSendDice_EMOJI_ToString(telegram_bot_api_postSendDice_emoji_e EMOJI){
    char *EMOJIArray[] =  { "NULL", "🎲", "🎯", "🏀", "⚽", "🎳", "🎰" };
    return EMOJIArray[EMOJI];
}

static telegram_bot_api_postSendDice_emoji_e postSendDice_EMOJI_FromString(char* EMOJI){
    int stringToReturn = 0;
    char *EMOJIArray[] =  { "NULL", "🎲", "🎯", "🏀", "⚽", "🎳", "🎰" };
    size_t sizeofArray = sizeof(EMOJIArray) / sizeof(EMOJIArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(EMOJI, EMOJIArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

/*
// Function postSendDice_EMOJI_convertToJSON is not currently used,
// since conversion to JSON passes through the conversion of the model, and ToString. The function is kept for future reference.
//
static cJSON *postSendDice_EMOJI_convertToJSON(telegram_bot_api_postSendDice_emoji_e EMOJI) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "emoji", postSendDice_EMOJI_ToString(EMOJI)) == NULL) {
        goto fail;
    }
    return item;
    fail:
    cJSON_Delete(item);
    return NULL;
}

// Function postSendDice_EMOJI_parseFromJSON is not currently used,
// since conversion from JSON passes through the conversion of the model, and FromString. The function is kept for future reference.
//
static telegram_bot_api_postSendDice_emoji_e postSendDice_EMOJI_parseFromJSON(cJSON* EMOJIJSON) {
    telegram_bot_api_postSendDice_emoji_e EMOJIVariable = 0;
    cJSON *EMOJIVar = cJSON_GetObjectItemCaseSensitive(EMOJIJSON, "emoji");
    if(!cJSON_IsString(EMOJIVar) || (EMOJIVar->valuestring == NULL))
    {
        goto end;
    }
    EMOJIVariable = postSendDice_EMOJI_FromString(EMOJIVar->valuestring);
    return EMOJIVariable;
end:
    return 0;
}
*/

// Functions for enum TYPE for DefaultAPI_postSendPoll

static char* postSendPoll_TYPE_ToString(telegram_bot_api_postSendPoll_type_e TYPE){
    char *TYPEArray[] =  { "NULL", "quiz", "regular" };
    return TYPEArray[TYPE];
}

static telegram_bot_api_postSendPoll_type_e postSendPoll_TYPE_FromString(char* TYPE){
    int stringToReturn = 0;
    char *TYPEArray[] =  { "NULL", "quiz", "regular" };
    size_t sizeofArray = sizeof(TYPEArray) / sizeof(TYPEArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(TYPE, TYPEArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

/*
// Function postSendPoll_TYPE_convertToJSON is not currently used,
// since conversion to JSON passes through the conversion of the model, and ToString. The function is kept for future reference.
//
static cJSON *postSendPoll_TYPE_convertToJSON(telegram_bot_api_postSendPoll_type_e TYPE) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "type", postSendPoll_TYPE_ToString(TYPE)) == NULL) {
        goto fail;
    }
    return item;
    fail:
    cJSON_Delete(item);
    return NULL;
}

// Function postSendPoll_TYPE_parseFromJSON is not currently used,
// since conversion from JSON passes through the conversion of the model, and FromString. The function is kept for future reference.
//
static telegram_bot_api_postSendPoll_type_e postSendPoll_TYPE_parseFromJSON(cJSON* TYPEJSON) {
    telegram_bot_api_postSendPoll_type_e TYPEVariable = 0;
    cJSON *TYPEVar = cJSON_GetObjectItemCaseSensitive(TYPEJSON, "type");
    if(!cJSON_IsString(TYPEVar) || (TYPEVar->valuestring == NULL))
    {
        goto end;
    }
    TYPEVariable = postSendPoll_TYPE_FromString(TYPEVar->valuestring);
    return TYPEVariable;
end:
    return 0;
}
*/

// Functions for enum FORMAT for DefaultAPI_postSetStickerSetThumbnail

static char* postSetStickerSetThumbnail_FORMAT_ToString(telegram_bot_api_postSetStickerSetThumbnail_format_e FORMAT){
    char *FORMATArray[] =  { "NULL", "static", "animated", "video" };
    return FORMATArray[FORMAT];
}

static telegram_bot_api_postSetStickerSetThumbnail_format_e postSetStickerSetThumbnail_FORMAT_FromString(char* FORMAT){
    int stringToReturn = 0;
    char *FORMATArray[] =  { "NULL", "static", "animated", "video" };
    size_t sizeofArray = sizeof(FORMATArray) / sizeof(FORMATArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(FORMAT, FORMATArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

/*
// Function postSetStickerSetThumbnail_FORMAT_convertToJSON is not currently used,
// since conversion to JSON passes through the conversion of the model, and ToString. The function is kept for future reference.
//
static cJSON *postSetStickerSetThumbnail_FORMAT_convertToJSON(telegram_bot_api_postSetStickerSetThumbnail_format_e FORMAT) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "format", postSetStickerSetThumbnail_FORMAT_ToString(FORMAT)) == NULL) {
        goto fail;
    }
    return item;
    fail:
    cJSON_Delete(item);
    return NULL;
}

// Function postSetStickerSetThumbnail_FORMAT_parseFromJSON is not currently used,
// since conversion from JSON passes through the conversion of the model, and FromString. The function is kept for future reference.
//
static telegram_bot_api_postSetStickerSetThumbnail_format_e postSetStickerSetThumbnail_FORMAT_parseFromJSON(cJSON* FORMATJSON) {
    telegram_bot_api_postSetStickerSetThumbnail_format_e FORMATVariable = 0;
    cJSON *FORMATVar = cJSON_GetObjectItemCaseSensitive(FORMATJSON, "format");
    if(!cJSON_IsString(FORMATVar) || (FORMATVar->valuestring == NULL))
    {
        goto end;
    }
    FORMATVariable = postSetStickerSetThumbnail_FORMAT_FromString(FORMATVar->valuestring);
    return FORMATVariable;
end:
    return 0;
}
*/

// Functions for enum STICKERFORMAT for DefaultAPI_postUploadStickerFile

static char* postUploadStickerFile_STICKERFORMAT_ToString(telegram_bot_api_postUploadStickerFile_sticker_format_e STICKERFORMAT){
    char *STICKERFORMATArray[] =  { "NULL", "static", "animated", "video" };
    return STICKERFORMATArray[STICKERFORMAT];
}

static telegram_bot_api_postUploadStickerFile_sticker_format_e postUploadStickerFile_STICKERFORMAT_FromString(char* STICKERFORMAT){
    int stringToReturn = 0;
    char *STICKERFORMATArray[] =  { "NULL", "static", "animated", "video" };
    size_t sizeofArray = sizeof(STICKERFORMATArray) / sizeof(STICKERFORMATArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(STICKERFORMAT, STICKERFORMATArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

/*
// Function postUploadStickerFile_STICKERFORMAT_convertToJSON is not currently used,
// since conversion to JSON passes through the conversion of the model, and ToString. The function is kept for future reference.
//
static cJSON *postUploadStickerFile_STICKERFORMAT_convertToJSON(telegram_bot_api_postUploadStickerFile_sticker_format_e STICKERFORMAT) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "sticker_format", postUploadStickerFile_STICKERFORMAT_ToString(STICKERFORMAT)) == NULL) {
        goto fail;
    }
    return item;
    fail:
    cJSON_Delete(item);
    return NULL;
}

// Function postUploadStickerFile_STICKERFORMAT_parseFromJSON is not currently used,
// since conversion from JSON passes through the conversion of the model, and FromString. The function is kept for future reference.
//
static telegram_bot_api_postUploadStickerFile_sticker_format_e postUploadStickerFile_STICKERFORMAT_parseFromJSON(cJSON* STICKERFORMATJSON) {
    telegram_bot_api_postUploadStickerFile_sticker_format_e STICKERFORMATVariable = 0;
    cJSON *STICKERFORMATVar = cJSON_GetObjectItemCaseSensitive(STICKERFORMATJSON, "sticker_format");
    if(!cJSON_IsString(STICKERFORMATVar) || (STICKERFORMATVar->valuestring == NULL))
    {
        goto end;
    }
    STICKERFORMATVariable = postUploadStickerFile_STICKERFORMAT_FromString(STICKERFORMATVar->valuestring);
    return STICKERFORMATVariable;
end:
    return 0;
}
*/


// addStickerToSet
//
// Use this method to add a new sticker to a set created by the bot. Emoji sticker sets can have up to 200 stickers. Other sticker sets can have up to 120 stickers. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postAddStickerToSet(apiClient_t *apiClient, int *user_id, char *name, input_sticker_t *sticker)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/addStickerToSet");





    // form parameters
    char *keyForm_user_id = NULL;
    int valueForm_user_id = 0;
    keyValuePair_t *keyPairForm_user_id = 0;
    if (user_id != NULL)
    {
        keyForm_user_id = strdup("user_id");
        valueForm_user_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_user_id, MAX_NUMBER_LENGTH, "%d", *user_id);
        keyPairForm_user_id = keyValuePair_create(keyForm_user_id,&valueForm_user_id);
        list_addElement(localVarFormParameters,keyPairForm_user_id);
    }

    // form parameters
    char *keyForm_name = NULL;
    char * valueForm_name = 0;
    keyValuePair_t *keyPairForm_name = 0;
    if (name != NULL)
    {
        keyForm_name = strdup("name");
        valueForm_name = strdup((name));
        keyPairForm_name = keyValuePair_create(keyForm_name,valueForm_name);
        list_addElement(localVarFormParameters,keyPairForm_name);
    }

    // form parameters
    char *keyForm_sticker = NULL;
    input_sticker_t * valueForm_sticker = 0;
    keyValuePair_t *keyPairForm_sticker = 0;
    if (sticker != NULL)
    {
        keyForm_sticker = strdup("sticker");
        valueForm_sticker = (sticker);
        keyPairForm_sticker = keyValuePair_create(keyForm_sticker,&valueForm_sticker);
        list_addElement(localVarFormParameters,keyPairForm_sticker);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_user_id) {
        free(keyForm_user_id);
        keyForm_user_id = NULL;
    }
    free(keyPairForm_user_id);
    if (keyForm_name) {
        free(keyForm_name);
        keyForm_name = NULL;
    }
    if (valueForm_name) {
        free(valueForm_name);
        valueForm_name = NULL;
    }
    free(keyPairForm_name);
    if (keyForm_sticker) {
        free(keyForm_sticker);
        keyForm_sticker = NULL;
    }
    free(keyPairForm_sticker);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// answerCallbackQuery
//
// Use this method to send answers to callback queries sent from [inline keyboards](https://core.telegram.org/bots/features#inline-keyboards). The answer will be displayed to the user as a notification at the top of the chat screen or as an alert. On success, *True* is returned.  Alternatively, the user can be redirected to the specified Game URL. For this option to work, you must first create a game for your bot via [@BotFather](https://t.me/botfather) and accept the terms. Otherwise, you may use links like `t.me/your_bot?start=XXXX` that open your bot with a parameter.
//
post_set_webhook_200_response_t*
DefaultAPI_postAnswerCallbackQuery(apiClient_t *apiClient, char *callback_query_id, char *text, int *show_alert, char *url, int *cache_time)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/answerCallbackQuery");





    // form parameters
    char *keyForm_callback_query_id = NULL;
    char * valueForm_callback_query_id = 0;
    keyValuePair_t *keyPairForm_callback_query_id = 0;
    if (callback_query_id != NULL)
    {
        keyForm_callback_query_id = strdup("callback_query_id");
        valueForm_callback_query_id = strdup((callback_query_id));
        keyPairForm_callback_query_id = keyValuePair_create(keyForm_callback_query_id,valueForm_callback_query_id);
        list_addElement(localVarFormParameters,keyPairForm_callback_query_id);
    }

    // form parameters
    char *keyForm_text = NULL;
    char * valueForm_text = 0;
    keyValuePair_t *keyPairForm_text = 0;
    if (text != NULL)
    {
        keyForm_text = strdup("text");
        valueForm_text = strdup((text));
        keyPairForm_text = keyValuePair_create(keyForm_text,valueForm_text);
        list_addElement(localVarFormParameters,keyPairForm_text);
    }

    // form parameters
    char *keyForm_show_alert = NULL;
    char * valueForm_show_alert = 0;
    keyValuePair_t *keyPairForm_show_alert = 0;
    if (show_alert != NULL)
    {
        keyForm_show_alert = strdup("show_alert");
        valueForm_show_alert = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_show_alert, MAX_NUMBER_LENGTH, "%d", *show_alert);
        keyPairForm_show_alert = keyValuePair_create(keyForm_show_alert,valueForm_show_alert);
        list_addElement(localVarFormParameters,keyPairForm_show_alert);
    }

    // form parameters
    char *keyForm_url = NULL;
    char * valueForm_url = 0;
    keyValuePair_t *keyPairForm_url = 0;
    if (url != NULL)
    {
        keyForm_url = strdup("url");
        valueForm_url = strdup((url));
        keyPairForm_url = keyValuePair_create(keyForm_url,valueForm_url);
        list_addElement(localVarFormParameters,keyPairForm_url);
    }

    // form parameters
    char *keyForm_cache_time = NULL;
    int valueForm_cache_time = 0;
    keyValuePair_t *keyPairForm_cache_time = 0;
    if (cache_time != NULL)
    {
        keyForm_cache_time = strdup("cache_time");
        valueForm_cache_time = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_cache_time, MAX_NUMBER_LENGTH, "%d", *cache_time);
        keyPairForm_cache_time = keyValuePair_create(keyForm_cache_time,&valueForm_cache_time);
        list_addElement(localVarFormParameters,keyPairForm_cache_time);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_callback_query_id) {
        free(keyForm_callback_query_id);
        keyForm_callback_query_id = NULL;
    }
    if (valueForm_callback_query_id) {
        free(valueForm_callback_query_id);
        valueForm_callback_query_id = NULL;
    }
    free(keyPairForm_callback_query_id);
    if (keyForm_text) {
        free(keyForm_text);
        keyForm_text = NULL;
    }
    if (valueForm_text) {
        free(valueForm_text);
        valueForm_text = NULL;
    }
    free(keyPairForm_text);
    if (keyForm_show_alert) {
        free(keyForm_show_alert);
        keyForm_show_alert = NULL;
    }
    free(keyPairForm_show_alert);
    if (keyForm_url) {
        free(keyForm_url);
        keyForm_url = NULL;
    }
    if (valueForm_url) {
        free(valueForm_url);
        valueForm_url = NULL;
    }
    free(keyPairForm_url);
    if (keyForm_cache_time) {
        free(keyForm_cache_time);
        keyForm_cache_time = NULL;
    }
    free(keyPairForm_cache_time);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// answerInlineQuery
//
// Use this method to send answers to an inline query. On success, *True* is returned.   No more than **50** results per query are allowed.
//
post_set_webhook_200_response_t*
DefaultAPI_postAnswerInlineQuery(apiClient_t *apiClient, char *inline_query_id, list_t *results, int *cache_time, int *is_personal, char *next_offset, inline_query_results_button_t *button)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/answerInlineQuery");





    // form parameters
    char *keyForm_inline_query_id = NULL;
    char * valueForm_inline_query_id = 0;
    keyValuePair_t *keyPairForm_inline_query_id = 0;
    if (inline_query_id != NULL)
    {
        keyForm_inline_query_id = strdup("inline_query_id");
        valueForm_inline_query_id = strdup((inline_query_id));
        keyPairForm_inline_query_id = keyValuePair_create(keyForm_inline_query_id,valueForm_inline_query_id);
        list_addElement(localVarFormParameters,keyPairForm_inline_query_id);
    }

    // form parameters
    char *keyForm_results = NULL;
     valueForm_results = 0;
    keyValuePair_t *keyPairForm_results = 0;
    if (results != NULL)
    {
        keyForm_results = strdup("results");
        valueForm_results = (results);
        keyPairForm_results = keyValuePair_create(keyForm_results,&valueForm_results);
        list_addElement(localVarFormParameters,keyPairForm_results);
    }

    // form parameters
    char *keyForm_cache_time = NULL;
    int valueForm_cache_time = 0;
    keyValuePair_t *keyPairForm_cache_time = 0;
    if (cache_time != NULL)
    {
        keyForm_cache_time = strdup("cache_time");
        valueForm_cache_time = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_cache_time, MAX_NUMBER_LENGTH, "%d", *cache_time);
        keyPairForm_cache_time = keyValuePair_create(keyForm_cache_time,&valueForm_cache_time);
        list_addElement(localVarFormParameters,keyPairForm_cache_time);
    }

    // form parameters
    char *keyForm_is_personal = NULL;
    char * valueForm_is_personal = 0;
    keyValuePair_t *keyPairForm_is_personal = 0;
    if (is_personal != NULL)
    {
        keyForm_is_personal = strdup("is_personal");
        valueForm_is_personal = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_is_personal, MAX_NUMBER_LENGTH, "%d", *is_personal);
        keyPairForm_is_personal = keyValuePair_create(keyForm_is_personal,valueForm_is_personal);
        list_addElement(localVarFormParameters,keyPairForm_is_personal);
    }

    // form parameters
    char *keyForm_next_offset = NULL;
    char * valueForm_next_offset = 0;
    keyValuePair_t *keyPairForm_next_offset = 0;
    if (next_offset != NULL)
    {
        keyForm_next_offset = strdup("next_offset");
        valueForm_next_offset = strdup((next_offset));
        keyPairForm_next_offset = keyValuePair_create(keyForm_next_offset,valueForm_next_offset);
        list_addElement(localVarFormParameters,keyPairForm_next_offset);
    }

    // form parameters
    char *keyForm_button = NULL;
    inline_query_results_button_t * valueForm_button = 0;
    keyValuePair_t *keyPairForm_button = 0;
    if (button != NULL)
    {
        keyForm_button = strdup("button");
        valueForm_button = (button);
        keyPairForm_button = keyValuePair_create(keyForm_button,&valueForm_button);
        list_addElement(localVarFormParameters,keyPairForm_button);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_inline_query_id) {
        free(keyForm_inline_query_id);
        keyForm_inline_query_id = NULL;
    }
    if (valueForm_inline_query_id) {
        free(valueForm_inline_query_id);
        valueForm_inline_query_id = NULL;
    }
    free(keyPairForm_inline_query_id);
    if (keyForm_results) {
        free(keyForm_results);
        keyForm_results = NULL;
    }
    free(keyPairForm_results);
    if (keyForm_cache_time) {
        free(keyForm_cache_time);
        keyForm_cache_time = NULL;
    }
    free(keyPairForm_cache_time);
    if (keyForm_is_personal) {
        free(keyForm_is_personal);
        keyForm_is_personal = NULL;
    }
    free(keyPairForm_is_personal);
    if (keyForm_next_offset) {
        free(keyForm_next_offset);
        keyForm_next_offset = NULL;
    }
    if (valueForm_next_offset) {
        free(valueForm_next_offset);
        valueForm_next_offset = NULL;
    }
    free(keyPairForm_next_offset);
    if (keyForm_button) {
        free(keyForm_button);
        keyForm_button = NULL;
    }
    free(keyPairForm_button);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// answerPreCheckoutQuery
//
// Once the user has confirmed their payment and shipping details, the Bot API sends the final confirmation in the form of an [Update](https://core.telegram.org/bots/api/#update) with the field *pre\\_checkout\\_query*. Use this method to respond to such pre-checkout queries. On success, *True* is returned. **Note:** The Bot API must receive an answer within 10 seconds after the pre-checkout query was sent.
//
post_set_webhook_200_response_t*
DefaultAPI_postAnswerPreCheckoutQuery(apiClient_t *apiClient, char *pre_checkout_query_id, int *ok, char *error_message)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/answerPreCheckoutQuery");





    // form parameters
    char *keyForm_pre_checkout_query_id = NULL;
    char * valueForm_pre_checkout_query_id = 0;
    keyValuePair_t *keyPairForm_pre_checkout_query_id = 0;
    if (pre_checkout_query_id != NULL)
    {
        keyForm_pre_checkout_query_id = strdup("pre_checkout_query_id");
        valueForm_pre_checkout_query_id = strdup((pre_checkout_query_id));
        keyPairForm_pre_checkout_query_id = keyValuePair_create(keyForm_pre_checkout_query_id,valueForm_pre_checkout_query_id);
        list_addElement(localVarFormParameters,keyPairForm_pre_checkout_query_id);
    }

    // form parameters
    char *keyForm_ok = NULL;
    char * valueForm_ok = 0;
    keyValuePair_t *keyPairForm_ok = 0;
    if (ok != NULL)
    {
        keyForm_ok = strdup("ok");
        valueForm_ok = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_ok, MAX_NUMBER_LENGTH, "%d", *ok);
        keyPairForm_ok = keyValuePair_create(keyForm_ok,valueForm_ok);
        list_addElement(localVarFormParameters,keyPairForm_ok);
    }

    // form parameters
    char *keyForm_error_message = NULL;
    char * valueForm_error_message = 0;
    keyValuePair_t *keyPairForm_error_message = 0;
    if (error_message != NULL)
    {
        keyForm_error_message = strdup("error_message");
        valueForm_error_message = strdup((error_message));
        keyPairForm_error_message = keyValuePair_create(keyForm_error_message,valueForm_error_message);
        list_addElement(localVarFormParameters,keyPairForm_error_message);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_pre_checkout_query_id) {
        free(keyForm_pre_checkout_query_id);
        keyForm_pre_checkout_query_id = NULL;
    }
    if (valueForm_pre_checkout_query_id) {
        free(valueForm_pre_checkout_query_id);
        valueForm_pre_checkout_query_id = NULL;
    }
    free(keyPairForm_pre_checkout_query_id);
    if (keyForm_ok) {
        free(keyForm_ok);
        keyForm_ok = NULL;
    }
    free(keyPairForm_ok);
    if (keyForm_error_message) {
        free(keyForm_error_message);
        keyForm_error_message = NULL;
    }
    if (valueForm_error_message) {
        free(valueForm_error_message);
        valueForm_error_message = NULL;
    }
    free(keyPairForm_error_message);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// answerShippingQuery
//
// If you sent an invoice requesting a shipping address and the parameter *is\\_flexible* was specified, the Bot API will send an [Update](https://core.telegram.org/bots/api/#update) with a *shipping\\_query* field to the bot. Use this method to reply to shipping queries. On success, *True* is returned.
//
post_set_webhook_200_response_t*
DefaultAPI_postAnswerShippingQuery(apiClient_t *apiClient, char *shipping_query_id, int *ok, list_t *shipping_options, char *error_message)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/answerShippingQuery");





    // form parameters
    char *keyForm_shipping_query_id = NULL;
    char * valueForm_shipping_query_id = 0;
    keyValuePair_t *keyPairForm_shipping_query_id = 0;
    if (shipping_query_id != NULL)
    {
        keyForm_shipping_query_id = strdup("shipping_query_id");
        valueForm_shipping_query_id = strdup((shipping_query_id));
        keyPairForm_shipping_query_id = keyValuePair_create(keyForm_shipping_query_id,valueForm_shipping_query_id);
        list_addElement(localVarFormParameters,keyPairForm_shipping_query_id);
    }

    // form parameters
    char *keyForm_ok = NULL;
    char * valueForm_ok = 0;
    keyValuePair_t *keyPairForm_ok = 0;
    if (ok != NULL)
    {
        keyForm_ok = strdup("ok");
        valueForm_ok = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_ok, MAX_NUMBER_LENGTH, "%d", *ok);
        keyPairForm_ok = keyValuePair_create(keyForm_ok,valueForm_ok);
        list_addElement(localVarFormParameters,keyPairForm_ok);
    }

    // form parameters
    char *keyForm_shipping_options = NULL;
     valueForm_shipping_options = 0;
    keyValuePair_t *keyPairForm_shipping_options = 0;
    if (shipping_options != NULL)
    {
        keyForm_shipping_options = strdup("shipping_options");
        valueForm_shipping_options = (shipping_options);
        keyPairForm_shipping_options = keyValuePair_create(keyForm_shipping_options,&valueForm_shipping_options);
        list_addElement(localVarFormParameters,keyPairForm_shipping_options);
    }

    // form parameters
    char *keyForm_error_message = NULL;
    char * valueForm_error_message = 0;
    keyValuePair_t *keyPairForm_error_message = 0;
    if (error_message != NULL)
    {
        keyForm_error_message = strdup("error_message");
        valueForm_error_message = strdup((error_message));
        keyPairForm_error_message = keyValuePair_create(keyForm_error_message,valueForm_error_message);
        list_addElement(localVarFormParameters,keyPairForm_error_message);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_shipping_query_id) {
        free(keyForm_shipping_query_id);
        keyForm_shipping_query_id = NULL;
    }
    if (valueForm_shipping_query_id) {
        free(valueForm_shipping_query_id);
        valueForm_shipping_query_id = NULL;
    }
    free(keyPairForm_shipping_query_id);
    if (keyForm_ok) {
        free(keyForm_ok);
        keyForm_ok = NULL;
    }
    free(keyPairForm_ok);
    if (keyForm_shipping_options) {
        free(keyForm_shipping_options);
        keyForm_shipping_options = NULL;
    }
    free(keyPairForm_shipping_options);
    if (keyForm_error_message) {
        free(keyForm_error_message);
        keyForm_error_message = NULL;
    }
    if (valueForm_error_message) {
        free(valueForm_error_message);
        valueForm_error_message = NULL;
    }
    free(keyPairForm_error_message);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// answerWebAppQuery
//
// Use this method to set the result of an interaction with a [Web App](https://core.telegram.org/bots/webapps) and send a corresponding message on behalf of the user to the chat from which the query originated. On success, a [SentWebAppMessage](https://core.telegram.org/bots/api/#sentwebappmessage) object is returned.
//
post_answer_web_app_query_200_response_t*
DefaultAPI_postAnswerWebAppQuery(apiClient_t *apiClient, char *web_app_query_id, inline_query_result_t *result)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/answerWebAppQuery");





    // form parameters
    char *keyForm_web_app_query_id = NULL;
    char * valueForm_web_app_query_id = 0;
    keyValuePair_t *keyPairForm_web_app_query_id = 0;
    if (web_app_query_id != NULL)
    {
        keyForm_web_app_query_id = strdup("web_app_query_id");
        valueForm_web_app_query_id = strdup((web_app_query_id));
        keyPairForm_web_app_query_id = keyValuePair_create(keyForm_web_app_query_id,valueForm_web_app_query_id);
        list_addElement(localVarFormParameters,keyPairForm_web_app_query_id);
    }

    // form parameters
    char *keyForm_result = NULL;
    inline_query_result_t * valueForm_result = 0;
    keyValuePair_t *keyPairForm_result = 0;
    if (result != NULL)
    {
        keyForm_result = strdup("result");
        valueForm_result = (result);
        keyPairForm_result = keyValuePair_create(keyForm_result,&valueForm_result);
        list_addElement(localVarFormParameters,keyPairForm_result);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_answer_web_app_query_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_answer_web_app_query_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_web_app_query_id) {
        free(keyForm_web_app_query_id);
        keyForm_web_app_query_id = NULL;
    }
    if (valueForm_web_app_query_id) {
        free(valueForm_web_app_query_id);
        valueForm_web_app_query_id = NULL;
    }
    free(keyPairForm_web_app_query_id);
    if (keyForm_result) {
        free(keyForm_result);
        keyForm_result = NULL;
    }
    free(keyPairForm_result);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// approveChatJoinRequest
//
// Use this method to approve a chat join request. The bot must be an administrator in the chat for this to work and must have the *can\\_invite\\_users* administrator right. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postApproveChatJoinRequest(apiClient_t *apiClient, post_send_message_request_chat_id_t *chat_id, int *user_id)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/approveChatJoinRequest");





    // form parameters
    char *keyForm_chat_id = NULL;
    post_send_message_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_user_id = NULL;
    int valueForm_user_id = 0;
    keyValuePair_t *keyPairForm_user_id = 0;
    if (user_id != NULL)
    {
        keyForm_user_id = strdup("user_id");
        valueForm_user_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_user_id, MAX_NUMBER_LENGTH, "%d", *user_id);
        keyPairForm_user_id = keyValuePair_create(keyForm_user_id,&valueForm_user_id);
        list_addElement(localVarFormParameters,keyPairForm_user_id);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_user_id) {
        free(keyForm_user_id);
        keyForm_user_id = NULL;
    }
    free(keyPairForm_user_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// banChatMember
//
// Use this method to ban a user in a group, a supergroup or a channel. In the case of supergroups and channels, the user will not be able to return to the chat on their own using invite links, etc., unless [unbanned](https://core.telegram.org/bots/api/#unbanchatmember) first. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postBanChatMember(apiClient_t *apiClient, post_ban_chat_member_request_chat_id_t *chat_id, int *user_id, int *until_date, int *revoke_messages)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/banChatMember");





    // form parameters
    char *keyForm_chat_id = NULL;
    post_ban_chat_member_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_user_id = NULL;
    int valueForm_user_id = 0;
    keyValuePair_t *keyPairForm_user_id = 0;
    if (user_id != NULL)
    {
        keyForm_user_id = strdup("user_id");
        valueForm_user_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_user_id, MAX_NUMBER_LENGTH, "%d", *user_id);
        keyPairForm_user_id = keyValuePair_create(keyForm_user_id,&valueForm_user_id);
        list_addElement(localVarFormParameters,keyPairForm_user_id);
    }

    // form parameters
    char *keyForm_until_date = NULL;
    int valueForm_until_date = 0;
    keyValuePair_t *keyPairForm_until_date = 0;
    if (until_date != NULL)
    {
        keyForm_until_date = strdup("until_date");
        valueForm_until_date = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_until_date, MAX_NUMBER_LENGTH, "%d", *until_date);
        keyPairForm_until_date = keyValuePair_create(keyForm_until_date,&valueForm_until_date);
        list_addElement(localVarFormParameters,keyPairForm_until_date);
    }

    // form parameters
    char *keyForm_revoke_messages = NULL;
    char * valueForm_revoke_messages = 0;
    keyValuePair_t *keyPairForm_revoke_messages = 0;
    if (revoke_messages != NULL)
    {
        keyForm_revoke_messages = strdup("revoke_messages");
        valueForm_revoke_messages = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_revoke_messages, MAX_NUMBER_LENGTH, "%d", *revoke_messages);
        keyPairForm_revoke_messages = keyValuePair_create(keyForm_revoke_messages,valueForm_revoke_messages);
        list_addElement(localVarFormParameters,keyPairForm_revoke_messages);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_user_id) {
        free(keyForm_user_id);
        keyForm_user_id = NULL;
    }
    free(keyPairForm_user_id);
    if (keyForm_until_date) {
        free(keyForm_until_date);
        keyForm_until_date = NULL;
    }
    free(keyPairForm_until_date);
    if (keyForm_revoke_messages) {
        free(keyForm_revoke_messages);
        keyForm_revoke_messages = NULL;
    }
    free(keyPairForm_revoke_messages);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// banChatSenderChat
//
// Use this method to ban a channel chat in a supergroup or a channel. Until the chat is [unbanned](https://core.telegram.org/bots/api/#unbanchatsenderchat), the owner of the banned chat won't be able to send messages on behalf of **any of their channels**. The bot must be an administrator in the supergroup or channel for this to work and must have the appropriate administrator rights. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postBanChatSenderChat(apiClient_t *apiClient, post_send_message_request_chat_id_t *chat_id, int *sender_chat_id)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/banChatSenderChat");





    // form parameters
    char *keyForm_chat_id = NULL;
    post_send_message_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_sender_chat_id = NULL;
    int valueForm_sender_chat_id = 0;
    keyValuePair_t *keyPairForm_sender_chat_id = 0;
    if (sender_chat_id != NULL)
    {
        keyForm_sender_chat_id = strdup("sender_chat_id");
        valueForm_sender_chat_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_sender_chat_id, MAX_NUMBER_LENGTH, "%d", *sender_chat_id);
        keyPairForm_sender_chat_id = keyValuePair_create(keyForm_sender_chat_id,&valueForm_sender_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_sender_chat_id);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_sender_chat_id) {
        free(keyForm_sender_chat_id);
        keyForm_sender_chat_id = NULL;
    }
    free(keyPairForm_sender_chat_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// close
//
// Use this method to close the bot instance before moving it from one local server to another. You need to delete the webhook before calling this method to ensure that the bot isn't launched again after server restart. The method will return error 429 in the first 10 minutes after the bot is launched. Returns *True* on success. Requires no parameters.
//
post_set_webhook_200_response_t*
DefaultAPI_postClose(apiClient_t *apiClient)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/close");




    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// closeForumTopic
//
// Use this method to close an open topic in a forum supergroup chat. The bot must be an administrator in the chat for this to work and must have the *can\\_manage\\_topics* administrator rights, unless it is the creator of the topic. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postCloseForumTopic(apiClient_t *apiClient, post_restrict_chat_member_request_chat_id_t *chat_id, int *message_thread_id)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/closeForumTopic");





    // form parameters
    char *keyForm_chat_id = NULL;
    post_restrict_chat_member_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_message_thread_id = NULL;
    int valueForm_message_thread_id = 0;
    keyValuePair_t *keyPairForm_message_thread_id = 0;
    if (message_thread_id != NULL)
    {
        keyForm_message_thread_id = strdup("message_thread_id");
        valueForm_message_thread_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_message_thread_id, MAX_NUMBER_LENGTH, "%d", *message_thread_id);
        keyPairForm_message_thread_id = keyValuePair_create(keyForm_message_thread_id,&valueForm_message_thread_id);
        list_addElement(localVarFormParameters,keyPairForm_message_thread_id);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_message_thread_id) {
        free(keyForm_message_thread_id);
        keyForm_message_thread_id = NULL;
    }
    free(keyPairForm_message_thread_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// closeGeneralForumTopic
//
// Use this method to close an open 'General' topic in a forum supergroup chat. The bot must be an administrator in the chat for this to work and must have the *can\\_manage\\_topics* administrator rights. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postCloseGeneralForumTopic(apiClient_t *apiClient, post_restrict_chat_member_request_chat_id_t *chat_id)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/closeGeneralForumTopic");





    // form parameters
    char *keyForm_chat_id = NULL;
    post_restrict_chat_member_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// convertGiftToStars
//
// Converts a given regular gift to Telegram Stars. Requires the *can\\_convert\\_gifts\\_to\\_stars* business bot right. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postConvertGiftToStars(apiClient_t *apiClient, char *business_connection_id, char *owned_gift_id)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/convertGiftToStars");





    // form parameters
    char *keyForm_business_connection_id = NULL;
    char * valueForm_business_connection_id = 0;
    keyValuePair_t *keyPairForm_business_connection_id = 0;
    if (business_connection_id != NULL)
    {
        keyForm_business_connection_id = strdup("business_connection_id");
        valueForm_business_connection_id = strdup((business_connection_id));
        keyPairForm_business_connection_id = keyValuePair_create(keyForm_business_connection_id,valueForm_business_connection_id);
        list_addElement(localVarFormParameters,keyPairForm_business_connection_id);
    }

    // form parameters
    char *keyForm_owned_gift_id = NULL;
    char * valueForm_owned_gift_id = 0;
    keyValuePair_t *keyPairForm_owned_gift_id = 0;
    if (owned_gift_id != NULL)
    {
        keyForm_owned_gift_id = strdup("owned_gift_id");
        valueForm_owned_gift_id = strdup((owned_gift_id));
        keyPairForm_owned_gift_id = keyValuePair_create(keyForm_owned_gift_id,valueForm_owned_gift_id);
        list_addElement(localVarFormParameters,keyPairForm_owned_gift_id);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_business_connection_id) {
        free(keyForm_business_connection_id);
        keyForm_business_connection_id = NULL;
    }
    if (valueForm_business_connection_id) {
        free(valueForm_business_connection_id);
        valueForm_business_connection_id = NULL;
    }
    free(keyPairForm_business_connection_id);
    if (keyForm_owned_gift_id) {
        free(keyForm_owned_gift_id);
        keyForm_owned_gift_id = NULL;
    }
    if (valueForm_owned_gift_id) {
        free(valueForm_owned_gift_id);
        valueForm_owned_gift_id = NULL;
    }
    free(keyPairForm_owned_gift_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// copyMessage
//
// Use this method to copy messages of any kind. Service messages, paid media messages, giveaway messages, giveaway winners messages, and invoice messages can't be copied. A quiz [poll](https://core.telegram.org/bots/api/#poll) can be copied only if the value of the field *correct\\_option\\_id* is known to the bot. The method is analogous to the method [forwardMessage](https://core.telegram.org/bots/api/#forwardmessage), but the copied message doesn't have a link to the original message. Returns the [MessageId](https://core.telegram.org/bots/api/#messageid) of the sent message on success.
//
post_copy_message_200_response_t*
DefaultAPI_postCopyMessage(apiClient_t *apiClient, post_send_message_request_chat_id_t *chat_id, post_forward_message_request_from_chat_id_t *from_chat_id, int *message_id, int *message_thread_id, int *video_start_timestamp, char *caption, char *parse_mode, list_t *caption_entities, int *show_caption_above_media, int *disable_notification, int *protect_content, int *allow_paid_broadcast, reply_parameters_t *reply_parameters, post_send_message_request_reply_markup_t *reply_markup)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/copyMessage");





    // form parameters
    char *keyForm_chat_id = NULL;
    post_send_message_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_message_thread_id = NULL;
    int valueForm_message_thread_id = 0;
    keyValuePair_t *keyPairForm_message_thread_id = 0;
    if (message_thread_id != NULL)
    {
        keyForm_message_thread_id = strdup("message_thread_id");
        valueForm_message_thread_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_message_thread_id, MAX_NUMBER_LENGTH, "%d", *message_thread_id);
        keyPairForm_message_thread_id = keyValuePair_create(keyForm_message_thread_id,&valueForm_message_thread_id);
        list_addElement(localVarFormParameters,keyPairForm_message_thread_id);
    }

    // form parameters
    char *keyForm_from_chat_id = NULL;
    post_forward_message_request_from_chat_id_t * valueForm_from_chat_id = 0;
    keyValuePair_t *keyPairForm_from_chat_id = 0;
    if (from_chat_id != NULL)
    {
        keyForm_from_chat_id = strdup("from_chat_id");
        valueForm_from_chat_id = (from_chat_id);
        keyPairForm_from_chat_id = keyValuePair_create(keyForm_from_chat_id,&valueForm_from_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_from_chat_id);
    }

    // form parameters
    char *keyForm_message_id = NULL;
    int valueForm_message_id = 0;
    keyValuePair_t *keyPairForm_message_id = 0;
    if (message_id != NULL)
    {
        keyForm_message_id = strdup("message_id");
        valueForm_message_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_message_id, MAX_NUMBER_LENGTH, "%d", *message_id);
        keyPairForm_message_id = keyValuePair_create(keyForm_message_id,&valueForm_message_id);
        list_addElement(localVarFormParameters,keyPairForm_message_id);
    }

    // form parameters
    char *keyForm_video_start_timestamp = NULL;
    int valueForm_video_start_timestamp = 0;
    keyValuePair_t *keyPairForm_video_start_timestamp = 0;
    if (video_start_timestamp != NULL)
    {
        keyForm_video_start_timestamp = strdup("video_start_timestamp");
        valueForm_video_start_timestamp = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_video_start_timestamp, MAX_NUMBER_LENGTH, "%d", *video_start_timestamp);
        keyPairForm_video_start_timestamp = keyValuePair_create(keyForm_video_start_timestamp,&valueForm_video_start_timestamp);
        list_addElement(localVarFormParameters,keyPairForm_video_start_timestamp);
    }

    // form parameters
    char *keyForm_caption = NULL;
    char * valueForm_caption = 0;
    keyValuePair_t *keyPairForm_caption = 0;
    if (caption != NULL)
    {
        keyForm_caption = strdup("caption");
        valueForm_caption = strdup((caption));
        keyPairForm_caption = keyValuePair_create(keyForm_caption,valueForm_caption);
        list_addElement(localVarFormParameters,keyPairForm_caption);
    }

    // form parameters
    char *keyForm_parse_mode = NULL;
    char * valueForm_parse_mode = 0;
    keyValuePair_t *keyPairForm_parse_mode = 0;
    if (parse_mode != NULL)
    {
        keyForm_parse_mode = strdup("parse_mode");
        valueForm_parse_mode = strdup((parse_mode));
        keyPairForm_parse_mode = keyValuePair_create(keyForm_parse_mode,valueForm_parse_mode);
        list_addElement(localVarFormParameters,keyPairForm_parse_mode);
    }

    // form parameters
    char *keyForm_caption_entities = NULL;
     valueForm_caption_entities = 0;
    keyValuePair_t *keyPairForm_caption_entities = 0;
    if (caption_entities != NULL)
    {
        keyForm_caption_entities = strdup("caption_entities");
        valueForm_caption_entities = (caption_entities);
        keyPairForm_caption_entities = keyValuePair_create(keyForm_caption_entities,&valueForm_caption_entities);
        list_addElement(localVarFormParameters,keyPairForm_caption_entities);
    }

    // form parameters
    char *keyForm_show_caption_above_media = NULL;
    char * valueForm_show_caption_above_media = 0;
    keyValuePair_t *keyPairForm_show_caption_above_media = 0;
    if (show_caption_above_media != NULL)
    {
        keyForm_show_caption_above_media = strdup("show_caption_above_media");
        valueForm_show_caption_above_media = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_show_caption_above_media, MAX_NUMBER_LENGTH, "%d", *show_caption_above_media);
        keyPairForm_show_caption_above_media = keyValuePair_create(keyForm_show_caption_above_media,valueForm_show_caption_above_media);
        list_addElement(localVarFormParameters,keyPairForm_show_caption_above_media);
    }

    // form parameters
    char *keyForm_disable_notification = NULL;
    char * valueForm_disable_notification = 0;
    keyValuePair_t *keyPairForm_disable_notification = 0;
    if (disable_notification != NULL)
    {
        keyForm_disable_notification = strdup("disable_notification");
        valueForm_disable_notification = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_disable_notification, MAX_NUMBER_LENGTH, "%d", *disable_notification);
        keyPairForm_disable_notification = keyValuePair_create(keyForm_disable_notification,valueForm_disable_notification);
        list_addElement(localVarFormParameters,keyPairForm_disable_notification);
    }

    // form parameters
    char *keyForm_protect_content = NULL;
    char * valueForm_protect_content = 0;
    keyValuePair_t *keyPairForm_protect_content = 0;
    if (protect_content != NULL)
    {
        keyForm_protect_content = strdup("protect_content");
        valueForm_protect_content = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_protect_content, MAX_NUMBER_LENGTH, "%d", *protect_content);
        keyPairForm_protect_content = keyValuePair_create(keyForm_protect_content,valueForm_protect_content);
        list_addElement(localVarFormParameters,keyPairForm_protect_content);
    }

    // form parameters
    char *keyForm_allow_paid_broadcast = NULL;
    char * valueForm_allow_paid_broadcast = 0;
    keyValuePair_t *keyPairForm_allow_paid_broadcast = 0;
    if (allow_paid_broadcast != NULL)
    {
        keyForm_allow_paid_broadcast = strdup("allow_paid_broadcast");
        valueForm_allow_paid_broadcast = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_allow_paid_broadcast, MAX_NUMBER_LENGTH, "%d", *allow_paid_broadcast);
        keyPairForm_allow_paid_broadcast = keyValuePair_create(keyForm_allow_paid_broadcast,valueForm_allow_paid_broadcast);
        list_addElement(localVarFormParameters,keyPairForm_allow_paid_broadcast);
    }

    // form parameters
    char *keyForm_reply_parameters = NULL;
    reply_parameters_t * valueForm_reply_parameters = 0;
    keyValuePair_t *keyPairForm_reply_parameters = 0;
    if (reply_parameters != NULL)
    {
        keyForm_reply_parameters = strdup("reply_parameters");
        valueForm_reply_parameters = (reply_parameters);
        keyPairForm_reply_parameters = keyValuePair_create(keyForm_reply_parameters,&valueForm_reply_parameters);
        list_addElement(localVarFormParameters,keyPairForm_reply_parameters);
    }

    // form parameters
    char *keyForm_reply_markup = NULL;
    post_send_message_request_reply_markup_t * valueForm_reply_markup = 0;
    keyValuePair_t *keyPairForm_reply_markup = 0;
    if (reply_markup != NULL)
    {
        keyForm_reply_markup = strdup("reply_markup");
        valueForm_reply_markup = (reply_markup);
        keyPairForm_reply_markup = keyValuePair_create(keyForm_reply_markup,&valueForm_reply_markup);
        list_addElement(localVarFormParameters,keyPairForm_reply_markup);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_copy_message_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_copy_message_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_message_thread_id) {
        free(keyForm_message_thread_id);
        keyForm_message_thread_id = NULL;
    }
    free(keyPairForm_message_thread_id);
    if (keyForm_from_chat_id) {
        free(keyForm_from_chat_id);
        keyForm_from_chat_id = NULL;
    }
    free(keyPairForm_from_chat_id);
    if (keyForm_message_id) {
        free(keyForm_message_id);
        keyForm_message_id = NULL;
    }
    free(keyPairForm_message_id);
    if (keyForm_video_start_timestamp) {
        free(keyForm_video_start_timestamp);
        keyForm_video_start_timestamp = NULL;
    }
    free(keyPairForm_video_start_timestamp);
    if (keyForm_caption) {
        free(keyForm_caption);
        keyForm_caption = NULL;
    }
    if (valueForm_caption) {
        free(valueForm_caption);
        valueForm_caption = NULL;
    }
    free(keyPairForm_caption);
    if (keyForm_parse_mode) {
        free(keyForm_parse_mode);
        keyForm_parse_mode = NULL;
    }
    if (valueForm_parse_mode) {
        free(valueForm_parse_mode);
        valueForm_parse_mode = NULL;
    }
    free(keyPairForm_parse_mode);
    if (keyForm_caption_entities) {
        free(keyForm_caption_entities);
        keyForm_caption_entities = NULL;
    }
    free(keyPairForm_caption_entities);
    if (keyForm_show_caption_above_media) {
        free(keyForm_show_caption_above_media);
        keyForm_show_caption_above_media = NULL;
    }
    free(keyPairForm_show_caption_above_media);
    if (keyForm_disable_notification) {
        free(keyForm_disable_notification);
        keyForm_disable_notification = NULL;
    }
    free(keyPairForm_disable_notification);
    if (keyForm_protect_content) {
        free(keyForm_protect_content);
        keyForm_protect_content = NULL;
    }
    free(keyPairForm_protect_content);
    if (keyForm_allow_paid_broadcast) {
        free(keyForm_allow_paid_broadcast);
        keyForm_allow_paid_broadcast = NULL;
    }
    free(keyPairForm_allow_paid_broadcast);
    if (keyForm_reply_parameters) {
        free(keyForm_reply_parameters);
        keyForm_reply_parameters = NULL;
    }
    free(keyPairForm_reply_parameters);
    if (keyForm_reply_markup) {
        free(keyForm_reply_markup);
        keyForm_reply_markup = NULL;
    }
    free(keyPairForm_reply_markup);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// copyMessages
//
// Use this method to copy messages of any kind. If some of the specified messages can't be found or copied, they are skipped. Service messages, paid media messages, giveaway messages, giveaway winners messages, and invoice messages can't be copied. A quiz [poll](https://core.telegram.org/bots/api/#poll) can be copied only if the value of the field *correct\\_option\\_id* is known to the bot. The method is analogous to the method [forwardMessages](https://core.telegram.org/bots/api/#forwardmessages), but the copied messages don't have a link to the original message. Album grouping is kept for copied messages. On success, an array of [MessageId](https://core.telegram.org/bots/api/#messageid) of the sent messages is returned.
//
post_forward_messages_200_response_t*
DefaultAPI_postCopyMessages(apiClient_t *apiClient, post_send_message_request_chat_id_t *chat_id, post_forward_messages_request_from_chat_id_t *from_chat_id, list_t *message_ids, int *message_thread_id, int *disable_notification, int *protect_content, int *remove_caption)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/copyMessages");





    // form parameters
    char *keyForm_chat_id = NULL;
    post_send_message_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_message_thread_id = NULL;
    int valueForm_message_thread_id = 0;
    keyValuePair_t *keyPairForm_message_thread_id = 0;
    if (message_thread_id != NULL)
    {
        keyForm_message_thread_id = strdup("message_thread_id");
        valueForm_message_thread_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_message_thread_id, MAX_NUMBER_LENGTH, "%d", *message_thread_id);
        keyPairForm_message_thread_id = keyValuePair_create(keyForm_message_thread_id,&valueForm_message_thread_id);
        list_addElement(localVarFormParameters,keyPairForm_message_thread_id);
    }

    // form parameters
    char *keyForm_from_chat_id = NULL;
    post_forward_messages_request_from_chat_id_t * valueForm_from_chat_id = 0;
    keyValuePair_t *keyPairForm_from_chat_id = 0;
    if (from_chat_id != NULL)
    {
        keyForm_from_chat_id = strdup("from_chat_id");
        valueForm_from_chat_id = (from_chat_id);
        keyPairForm_from_chat_id = keyValuePair_create(keyForm_from_chat_id,&valueForm_from_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_from_chat_id);
    }

    // form parameters
    char *keyForm_message_ids = NULL;
     valueForm_message_ids = 0;
    keyValuePair_t *keyPairForm_message_ids = 0;
    if (message_ids != NULL)
    {
        keyForm_message_ids = strdup("message_ids");
        valueForm_message_ids = (message_ids);
        keyPairForm_message_ids = keyValuePair_create(keyForm_message_ids,&valueForm_message_ids);
        list_addElement(localVarFormParameters,keyPairForm_message_ids);
    }

    // form parameters
    char *keyForm_disable_notification = NULL;
    char * valueForm_disable_notification = 0;
    keyValuePair_t *keyPairForm_disable_notification = 0;
    if (disable_notification != NULL)
    {
        keyForm_disable_notification = strdup("disable_notification");
        valueForm_disable_notification = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_disable_notification, MAX_NUMBER_LENGTH, "%d", *disable_notification);
        keyPairForm_disable_notification = keyValuePair_create(keyForm_disable_notification,valueForm_disable_notification);
        list_addElement(localVarFormParameters,keyPairForm_disable_notification);
    }

    // form parameters
    char *keyForm_protect_content = NULL;
    char * valueForm_protect_content = 0;
    keyValuePair_t *keyPairForm_protect_content = 0;
    if (protect_content != NULL)
    {
        keyForm_protect_content = strdup("protect_content");
        valueForm_protect_content = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_protect_content, MAX_NUMBER_LENGTH, "%d", *protect_content);
        keyPairForm_protect_content = keyValuePair_create(keyForm_protect_content,valueForm_protect_content);
        list_addElement(localVarFormParameters,keyPairForm_protect_content);
    }

    // form parameters
    char *keyForm_remove_caption = NULL;
    char * valueForm_remove_caption = 0;
    keyValuePair_t *keyPairForm_remove_caption = 0;
    if (remove_caption != NULL)
    {
        keyForm_remove_caption = strdup("remove_caption");
        valueForm_remove_caption = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_remove_caption, MAX_NUMBER_LENGTH, "%d", *remove_caption);
        keyPairForm_remove_caption = keyValuePair_create(keyForm_remove_caption,valueForm_remove_caption);
        list_addElement(localVarFormParameters,keyPairForm_remove_caption);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_forward_messages_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_forward_messages_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_message_thread_id) {
        free(keyForm_message_thread_id);
        keyForm_message_thread_id = NULL;
    }
    free(keyPairForm_message_thread_id);
    if (keyForm_from_chat_id) {
        free(keyForm_from_chat_id);
        keyForm_from_chat_id = NULL;
    }
    free(keyPairForm_from_chat_id);
    if (keyForm_message_ids) {
        free(keyForm_message_ids);
        keyForm_message_ids = NULL;
    }
    free(keyPairForm_message_ids);
    if (keyForm_disable_notification) {
        free(keyForm_disable_notification);
        keyForm_disable_notification = NULL;
    }
    free(keyPairForm_disable_notification);
    if (keyForm_protect_content) {
        free(keyForm_protect_content);
        keyForm_protect_content = NULL;
    }
    free(keyPairForm_protect_content);
    if (keyForm_remove_caption) {
        free(keyForm_remove_caption);
        keyForm_remove_caption = NULL;
    }
    free(keyPairForm_remove_caption);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// createChatInviteLink
//
// Use this method to create an additional invite link for a chat. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. The link can be revoked using the method [revokeChatInviteLink](https://core.telegram.org/bots/api/#revokechatinvitelink). Returns the new invite link as [ChatInviteLink](https://core.telegram.org/bots/api/#chatinvitelink) object.
//
post_create_chat_invite_link_200_response_t*
DefaultAPI_postCreateChatInviteLink(apiClient_t *apiClient, post_send_message_request_chat_id_t *chat_id, char *name, int *expire_date, int *member_limit, int *creates_join_request)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/createChatInviteLink");





    // form parameters
    char *keyForm_chat_id = NULL;
    post_send_message_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_name = NULL;
    char * valueForm_name = 0;
    keyValuePair_t *keyPairForm_name = 0;
    if (name != NULL)
    {
        keyForm_name = strdup("name");
        valueForm_name = strdup((name));
        keyPairForm_name = keyValuePair_create(keyForm_name,valueForm_name);
        list_addElement(localVarFormParameters,keyPairForm_name);
    }

    // form parameters
    char *keyForm_expire_date = NULL;
    int valueForm_expire_date = 0;
    keyValuePair_t *keyPairForm_expire_date = 0;
    if (expire_date != NULL)
    {
        keyForm_expire_date = strdup("expire_date");
        valueForm_expire_date = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_expire_date, MAX_NUMBER_LENGTH, "%d", *expire_date);
        keyPairForm_expire_date = keyValuePair_create(keyForm_expire_date,&valueForm_expire_date);
        list_addElement(localVarFormParameters,keyPairForm_expire_date);
    }

    // form parameters
    char *keyForm_member_limit = NULL;
    int valueForm_member_limit = 0;
    keyValuePair_t *keyPairForm_member_limit = 0;
    if (member_limit != NULL)
    {
        keyForm_member_limit = strdup("member_limit");
        valueForm_member_limit = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_member_limit, MAX_NUMBER_LENGTH, "%d", *member_limit);
        keyPairForm_member_limit = keyValuePair_create(keyForm_member_limit,&valueForm_member_limit);
        list_addElement(localVarFormParameters,keyPairForm_member_limit);
    }

    // form parameters
    char *keyForm_creates_join_request = NULL;
    char * valueForm_creates_join_request = 0;
    keyValuePair_t *keyPairForm_creates_join_request = 0;
    if (creates_join_request != NULL)
    {
        keyForm_creates_join_request = strdup("creates_join_request");
        valueForm_creates_join_request = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_creates_join_request, MAX_NUMBER_LENGTH, "%d", *creates_join_request);
        keyPairForm_creates_join_request = keyValuePair_create(keyForm_creates_join_request,valueForm_creates_join_request);
        list_addElement(localVarFormParameters,keyPairForm_creates_join_request);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_create_chat_invite_link_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_create_chat_invite_link_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_name) {
        free(keyForm_name);
        keyForm_name = NULL;
    }
    if (valueForm_name) {
        free(valueForm_name);
        valueForm_name = NULL;
    }
    free(keyPairForm_name);
    if (keyForm_expire_date) {
        free(keyForm_expire_date);
        keyForm_expire_date = NULL;
    }
    free(keyPairForm_expire_date);
    if (keyForm_member_limit) {
        free(keyForm_member_limit);
        keyForm_member_limit = NULL;
    }
    free(keyPairForm_member_limit);
    if (keyForm_creates_join_request) {
        free(keyForm_creates_join_request);
        keyForm_creates_join_request = NULL;
    }
    free(keyPairForm_creates_join_request);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// createChatSubscriptionInviteLink
//
// Use this method to create a [subscription invite link](https://telegram.org/blog/superchannels-star-reactions-subscriptions#star-subscriptions) for a channel chat. The bot must have the *can\\_invite\\_users* administrator rights. The link can be edited using the method [editChatSubscriptionInviteLink](https://core.telegram.org/bots/api/#editchatsubscriptioninvitelink) or revoked using the method [revokeChatInviteLink](https://core.telegram.org/bots/api/#revokechatinvitelink). Returns the new invite link as a [ChatInviteLink](https://core.telegram.org/bots/api/#chatinvitelink) object.
//
post_create_chat_invite_link_200_response_t*
DefaultAPI_postCreateChatSubscriptionInviteLink(apiClient_t *apiClient, post_create_chat_subscription_invite_link_request_chat_id_t *chat_id, int *subscription_period, int *subscription_price, char *name)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/createChatSubscriptionInviteLink");





    // form parameters
    char *keyForm_chat_id = NULL;
    post_create_chat_subscription_invite_link_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_name = NULL;
    char * valueForm_name = 0;
    keyValuePair_t *keyPairForm_name = 0;
    if (name != NULL)
    {
        keyForm_name = strdup("name");
        valueForm_name = strdup((name));
        keyPairForm_name = keyValuePair_create(keyForm_name,valueForm_name);
        list_addElement(localVarFormParameters,keyPairForm_name);
    }

    // form parameters
    char *keyForm_subscription_period = NULL;
    int valueForm_subscription_period = 0;
    keyValuePair_t *keyPairForm_subscription_period = 0;
    if (subscription_period != NULL)
    {
        keyForm_subscription_period = strdup("subscription_period");
        valueForm_subscription_period = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_subscription_period, MAX_NUMBER_LENGTH, "%d", *subscription_period);
        keyPairForm_subscription_period = keyValuePair_create(keyForm_subscription_period,&valueForm_subscription_period);
        list_addElement(localVarFormParameters,keyPairForm_subscription_period);
    }

    // form parameters
    char *keyForm_subscription_price = NULL;
    int valueForm_subscription_price = 0;
    keyValuePair_t *keyPairForm_subscription_price = 0;
    if (subscription_price != NULL)
    {
        keyForm_subscription_price = strdup("subscription_price");
        valueForm_subscription_price = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_subscription_price, MAX_NUMBER_LENGTH, "%d", *subscription_price);
        keyPairForm_subscription_price = keyValuePair_create(keyForm_subscription_price,&valueForm_subscription_price);
        list_addElement(localVarFormParameters,keyPairForm_subscription_price);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_create_chat_invite_link_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_create_chat_invite_link_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_name) {
        free(keyForm_name);
        keyForm_name = NULL;
    }
    if (valueForm_name) {
        free(valueForm_name);
        valueForm_name = NULL;
    }
    free(keyPairForm_name);
    if (keyForm_subscription_period) {
        free(keyForm_subscription_period);
        keyForm_subscription_period = NULL;
    }
    free(keyPairForm_subscription_period);
    if (keyForm_subscription_price) {
        free(keyForm_subscription_price);
        keyForm_subscription_price = NULL;
    }
    free(keyPairForm_subscription_price);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// createForumTopic
//
// Use this method to create a topic in a forum supergroup chat. The bot must be an administrator in the chat for this to work and must have the *can\\_manage\\_topics* administrator rights. Returns information about the created topic as a [ForumTopic](https://core.telegram.org/bots/api/#forumtopic) object.
//
post_create_forum_topic_200_response_t*
DefaultAPI_postCreateForumTopic(apiClient_t *apiClient, post_restrict_chat_member_request_chat_id_t *chat_id, char *name, int *icon_color, char *icon_custom_emoji_id)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/createForumTopic");





    // form parameters
    char *keyForm_chat_id = NULL;
    post_restrict_chat_member_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_name = NULL;
    char * valueForm_name = 0;
    keyValuePair_t *keyPairForm_name = 0;
    if (name != NULL)
    {
        keyForm_name = strdup("name");
        valueForm_name = strdup((name));
        keyPairForm_name = keyValuePair_create(keyForm_name,valueForm_name);
        list_addElement(localVarFormParameters,keyPairForm_name);
    }

    // form parameters
    char *keyForm_icon_color = NULL;
    int valueForm_icon_color = 0;
    keyValuePair_t *keyPairForm_icon_color = 0;
    if (icon_color != 0)
    {
        keyForm_icon_color = strdup("icon_color");
        valueForm_icon_color = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_icon_color, MAX_NUMBER_LENGTH, "%d", *icon_color);
        keyPairForm_icon_color = keyValuePair_create(keyForm_icon_color,&valueForm_icon_color);
        list_addElement(localVarFormParameters,keyPairForm_icon_color);
    }

    // form parameters
    char *keyForm_icon_custom_emoji_id = NULL;
    char * valueForm_icon_custom_emoji_id = 0;
    keyValuePair_t *keyPairForm_icon_custom_emoji_id = 0;
    if (icon_custom_emoji_id != NULL)
    {
        keyForm_icon_custom_emoji_id = strdup("icon_custom_emoji_id");
        valueForm_icon_custom_emoji_id = strdup((icon_custom_emoji_id));
        keyPairForm_icon_custom_emoji_id = keyValuePair_create(keyForm_icon_custom_emoji_id,valueForm_icon_custom_emoji_id);
        list_addElement(localVarFormParameters,keyPairForm_icon_custom_emoji_id);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_create_forum_topic_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_create_forum_topic_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_name) {
        free(keyForm_name);
        keyForm_name = NULL;
    }
    if (valueForm_name) {
        free(valueForm_name);
        valueForm_name = NULL;
    }
    free(keyPairForm_name);
    if (keyForm_icon_color) {
        free(keyForm_icon_color);
        keyForm_icon_color = NULL;
    }
    free(keyPairForm_icon_color);
    if (keyForm_icon_custom_emoji_id) {
        free(keyForm_icon_custom_emoji_id);
        keyForm_icon_custom_emoji_id = NULL;
    }
    if (valueForm_icon_custom_emoji_id) {
        free(valueForm_icon_custom_emoji_id);
        valueForm_icon_custom_emoji_id = NULL;
    }
    free(keyPairForm_icon_custom_emoji_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// createInvoiceLink
//
// Use this method to create a link for an invoice. Returns the created invoice link as *String* on success.
//
post_export_chat_invite_link_200_response_t*
DefaultAPI_postCreateInvoiceLink(apiClient_t *apiClient, char *title, char *description, char *payload, char *currency, list_t *prices, char *business_connection_id, char *provider_token, int *subscription_period, int *max_tip_amount, list_t *suggested_tip_amounts, char *provider_data, char *photo_url, int *photo_size, int *photo_width, int *photo_height, int *need_name, int *need_phone_number, int *need_email, int *need_shipping_address, int *send_phone_number_to_provider, int *send_email_to_provider, int *is_flexible)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/createInvoiceLink");





    // form parameters
    char *keyForm_business_connection_id = NULL;
    char * valueForm_business_connection_id = 0;
    keyValuePair_t *keyPairForm_business_connection_id = 0;
    if (business_connection_id != NULL)
    {
        keyForm_business_connection_id = strdup("business_connection_id");
        valueForm_business_connection_id = strdup((business_connection_id));
        keyPairForm_business_connection_id = keyValuePair_create(keyForm_business_connection_id,valueForm_business_connection_id);
        list_addElement(localVarFormParameters,keyPairForm_business_connection_id);
    }

    // form parameters
    char *keyForm_title = NULL;
    char * valueForm_title = 0;
    keyValuePair_t *keyPairForm_title = 0;
    if (title != NULL)
    {
        keyForm_title = strdup("title");
        valueForm_title = strdup((title));
        keyPairForm_title = keyValuePair_create(keyForm_title,valueForm_title);
        list_addElement(localVarFormParameters,keyPairForm_title);
    }

    // form parameters
    char *keyForm_description = NULL;
    char * valueForm_description = 0;
    keyValuePair_t *keyPairForm_description = 0;
    if (description != NULL)
    {
        keyForm_description = strdup("description");
        valueForm_description = strdup((description));
        keyPairForm_description = keyValuePair_create(keyForm_description,valueForm_description);
        list_addElement(localVarFormParameters,keyPairForm_description);
    }

    // form parameters
    char *keyForm_payload = NULL;
    char * valueForm_payload = 0;
    keyValuePair_t *keyPairForm_payload = 0;
    if (payload != NULL)
    {
        keyForm_payload = strdup("payload");
        valueForm_payload = strdup((payload));
        keyPairForm_payload = keyValuePair_create(keyForm_payload,valueForm_payload);
        list_addElement(localVarFormParameters,keyPairForm_payload);
    }

    // form parameters
    char *keyForm_provider_token = NULL;
    char * valueForm_provider_token = 0;
    keyValuePair_t *keyPairForm_provider_token = 0;
    if (provider_token != NULL)
    {
        keyForm_provider_token = strdup("provider_token");
        valueForm_provider_token = strdup((provider_token));
        keyPairForm_provider_token = keyValuePair_create(keyForm_provider_token,valueForm_provider_token);
        list_addElement(localVarFormParameters,keyPairForm_provider_token);
    }

    // form parameters
    char *keyForm_currency = NULL;
    char * valueForm_currency = 0;
    keyValuePair_t *keyPairForm_currency = 0;
    if (currency != NULL)
    {
        keyForm_currency = strdup("currency");
        valueForm_currency = strdup((currency));
        keyPairForm_currency = keyValuePair_create(keyForm_currency,valueForm_currency);
        list_addElement(localVarFormParameters,keyPairForm_currency);
    }

    // form parameters
    char *keyForm_prices = NULL;
     valueForm_prices = 0;
    keyValuePair_t *keyPairForm_prices = 0;
    if (prices != NULL)
    {
        keyForm_prices = strdup("prices");
        valueForm_prices = (prices);
        keyPairForm_prices = keyValuePair_create(keyForm_prices,&valueForm_prices);
        list_addElement(localVarFormParameters,keyPairForm_prices);
    }

    // form parameters
    char *keyForm_subscription_period = NULL;
    int valueForm_subscription_period = 0;
    keyValuePair_t *keyPairForm_subscription_period = 0;
    if (subscription_period != NULL)
    {
        keyForm_subscription_period = strdup("subscription_period");
        valueForm_subscription_period = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_subscription_period, MAX_NUMBER_LENGTH, "%d", *subscription_period);
        keyPairForm_subscription_period = keyValuePair_create(keyForm_subscription_period,&valueForm_subscription_period);
        list_addElement(localVarFormParameters,keyPairForm_subscription_period);
    }

    // form parameters
    char *keyForm_max_tip_amount = NULL;
    int valueForm_max_tip_amount = 0;
    keyValuePair_t *keyPairForm_max_tip_amount = 0;
    if (max_tip_amount != NULL)
    {
        keyForm_max_tip_amount = strdup("max_tip_amount");
        valueForm_max_tip_amount = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_max_tip_amount, MAX_NUMBER_LENGTH, "%d", *max_tip_amount);
        keyPairForm_max_tip_amount = keyValuePair_create(keyForm_max_tip_amount,&valueForm_max_tip_amount);
        list_addElement(localVarFormParameters,keyPairForm_max_tip_amount);
    }

    // form parameters
    char *keyForm_suggested_tip_amounts = NULL;
     valueForm_suggested_tip_amounts = 0;
    keyValuePair_t *keyPairForm_suggested_tip_amounts = 0;
    if (suggested_tip_amounts != NULL)
    {
        keyForm_suggested_tip_amounts = strdup("suggested_tip_amounts");
        valueForm_suggested_tip_amounts = (suggested_tip_amounts);
        keyPairForm_suggested_tip_amounts = keyValuePair_create(keyForm_suggested_tip_amounts,&valueForm_suggested_tip_amounts);
        list_addElement(localVarFormParameters,keyPairForm_suggested_tip_amounts);
    }

    // form parameters
    char *keyForm_provider_data = NULL;
    char * valueForm_provider_data = 0;
    keyValuePair_t *keyPairForm_provider_data = 0;
    if (provider_data != NULL)
    {
        keyForm_provider_data = strdup("provider_data");
        valueForm_provider_data = strdup((provider_data));
        keyPairForm_provider_data = keyValuePair_create(keyForm_provider_data,valueForm_provider_data);
        list_addElement(localVarFormParameters,keyPairForm_provider_data);
    }

    // form parameters
    char *keyForm_photo_url = NULL;
    char * valueForm_photo_url = 0;
    keyValuePair_t *keyPairForm_photo_url = 0;
    if (photo_url != NULL)
    {
        keyForm_photo_url = strdup("photo_url");
        valueForm_photo_url = strdup((photo_url));
        keyPairForm_photo_url = keyValuePair_create(keyForm_photo_url,valueForm_photo_url);
        list_addElement(localVarFormParameters,keyPairForm_photo_url);
    }

    // form parameters
    char *keyForm_photo_size = NULL;
    int valueForm_photo_size = 0;
    keyValuePair_t *keyPairForm_photo_size = 0;
    if (photo_size != NULL)
    {
        keyForm_photo_size = strdup("photo_size");
        valueForm_photo_size = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_photo_size, MAX_NUMBER_LENGTH, "%d", *photo_size);
        keyPairForm_photo_size = keyValuePair_create(keyForm_photo_size,&valueForm_photo_size);
        list_addElement(localVarFormParameters,keyPairForm_photo_size);
    }

    // form parameters
    char *keyForm_photo_width = NULL;
    int valueForm_photo_width = 0;
    keyValuePair_t *keyPairForm_photo_width = 0;
    if (photo_width != NULL)
    {
        keyForm_photo_width = strdup("photo_width");
        valueForm_photo_width = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_photo_width, MAX_NUMBER_LENGTH, "%d", *photo_width);
        keyPairForm_photo_width = keyValuePair_create(keyForm_photo_width,&valueForm_photo_width);
        list_addElement(localVarFormParameters,keyPairForm_photo_width);
    }

    // form parameters
    char *keyForm_photo_height = NULL;
    int valueForm_photo_height = 0;
    keyValuePair_t *keyPairForm_photo_height = 0;
    if (photo_height != NULL)
    {
        keyForm_photo_height = strdup("photo_height");
        valueForm_photo_height = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_photo_height, MAX_NUMBER_LENGTH, "%d", *photo_height);
        keyPairForm_photo_height = keyValuePair_create(keyForm_photo_height,&valueForm_photo_height);
        list_addElement(localVarFormParameters,keyPairForm_photo_height);
    }

    // form parameters
    char *keyForm_need_name = NULL;
    char * valueForm_need_name = 0;
    keyValuePair_t *keyPairForm_need_name = 0;
    if (need_name != NULL)
    {
        keyForm_need_name = strdup("need_name");
        valueForm_need_name = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_need_name, MAX_NUMBER_LENGTH, "%d", *need_name);
        keyPairForm_need_name = keyValuePair_create(keyForm_need_name,valueForm_need_name);
        list_addElement(localVarFormParameters,keyPairForm_need_name);
    }

    // form parameters
    char *keyForm_need_phone_number = NULL;
    char * valueForm_need_phone_number = 0;
    keyValuePair_t *keyPairForm_need_phone_number = 0;
    if (need_phone_number != NULL)
    {
        keyForm_need_phone_number = strdup("need_phone_number");
        valueForm_need_phone_number = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_need_phone_number, MAX_NUMBER_LENGTH, "%d", *need_phone_number);
        keyPairForm_need_phone_number = keyValuePair_create(keyForm_need_phone_number,valueForm_need_phone_number);
        list_addElement(localVarFormParameters,keyPairForm_need_phone_number);
    }

    // form parameters
    char *keyForm_need_email = NULL;
    char * valueForm_need_email = 0;
    keyValuePair_t *keyPairForm_need_email = 0;
    if (need_email != NULL)
    {
        keyForm_need_email = strdup("need_email");
        valueForm_need_email = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_need_email, MAX_NUMBER_LENGTH, "%d", *need_email);
        keyPairForm_need_email = keyValuePair_create(keyForm_need_email,valueForm_need_email);
        list_addElement(localVarFormParameters,keyPairForm_need_email);
    }

    // form parameters
    char *keyForm_need_shipping_address = NULL;
    char * valueForm_need_shipping_address = 0;
    keyValuePair_t *keyPairForm_need_shipping_address = 0;
    if (need_shipping_address != NULL)
    {
        keyForm_need_shipping_address = strdup("need_shipping_address");
        valueForm_need_shipping_address = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_need_shipping_address, MAX_NUMBER_LENGTH, "%d", *need_shipping_address);
        keyPairForm_need_shipping_address = keyValuePair_create(keyForm_need_shipping_address,valueForm_need_shipping_address);
        list_addElement(localVarFormParameters,keyPairForm_need_shipping_address);
    }

    // form parameters
    char *keyForm_send_phone_number_to_provider = NULL;
    char * valueForm_send_phone_number_to_provider = 0;
    keyValuePair_t *keyPairForm_send_phone_number_to_provider = 0;
    if (send_phone_number_to_provider != NULL)
    {
        keyForm_send_phone_number_to_provider = strdup("send_phone_number_to_provider");
        valueForm_send_phone_number_to_provider = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_send_phone_number_to_provider, MAX_NUMBER_LENGTH, "%d", *send_phone_number_to_provider);
        keyPairForm_send_phone_number_to_provider = keyValuePair_create(keyForm_send_phone_number_to_provider,valueForm_send_phone_number_to_provider);
        list_addElement(localVarFormParameters,keyPairForm_send_phone_number_to_provider);
    }

    // form parameters
    char *keyForm_send_email_to_provider = NULL;
    char * valueForm_send_email_to_provider = 0;
    keyValuePair_t *keyPairForm_send_email_to_provider = 0;
    if (send_email_to_provider != NULL)
    {
        keyForm_send_email_to_provider = strdup("send_email_to_provider");
        valueForm_send_email_to_provider = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_send_email_to_provider, MAX_NUMBER_LENGTH, "%d", *send_email_to_provider);
        keyPairForm_send_email_to_provider = keyValuePair_create(keyForm_send_email_to_provider,valueForm_send_email_to_provider);
        list_addElement(localVarFormParameters,keyPairForm_send_email_to_provider);
    }

    // form parameters
    char *keyForm_is_flexible = NULL;
    char * valueForm_is_flexible = 0;
    keyValuePair_t *keyPairForm_is_flexible = 0;
    if (is_flexible != NULL)
    {
        keyForm_is_flexible = strdup("is_flexible");
        valueForm_is_flexible = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_is_flexible, MAX_NUMBER_LENGTH, "%d", *is_flexible);
        keyPairForm_is_flexible = keyValuePair_create(keyForm_is_flexible,valueForm_is_flexible);
        list_addElement(localVarFormParameters,keyPairForm_is_flexible);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_export_chat_invite_link_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_export_chat_invite_link_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_business_connection_id) {
        free(keyForm_business_connection_id);
        keyForm_business_connection_id = NULL;
    }
    if (valueForm_business_connection_id) {
        free(valueForm_business_connection_id);
        valueForm_business_connection_id = NULL;
    }
    free(keyPairForm_business_connection_id);
    if (keyForm_title) {
        free(keyForm_title);
        keyForm_title = NULL;
    }
    if (valueForm_title) {
        free(valueForm_title);
        valueForm_title = NULL;
    }
    free(keyPairForm_title);
    if (keyForm_description) {
        free(keyForm_description);
        keyForm_description = NULL;
    }
    if (valueForm_description) {
        free(valueForm_description);
        valueForm_description = NULL;
    }
    free(keyPairForm_description);
    if (keyForm_payload) {
        free(keyForm_payload);
        keyForm_payload = NULL;
    }
    if (valueForm_payload) {
        free(valueForm_payload);
        valueForm_payload = NULL;
    }
    free(keyPairForm_payload);
    if (keyForm_provider_token) {
        free(keyForm_provider_token);
        keyForm_provider_token = NULL;
    }
    if (valueForm_provider_token) {
        free(valueForm_provider_token);
        valueForm_provider_token = NULL;
    }
    free(keyPairForm_provider_token);
    if (keyForm_currency) {
        free(keyForm_currency);
        keyForm_currency = NULL;
    }
    if (valueForm_currency) {
        free(valueForm_currency);
        valueForm_currency = NULL;
    }
    free(keyPairForm_currency);
    if (keyForm_prices) {
        free(keyForm_prices);
        keyForm_prices = NULL;
    }
    free(keyPairForm_prices);
    if (keyForm_subscription_period) {
        free(keyForm_subscription_period);
        keyForm_subscription_period = NULL;
    }
    free(keyPairForm_subscription_period);
    if (keyForm_max_tip_amount) {
        free(keyForm_max_tip_amount);
        keyForm_max_tip_amount = NULL;
    }
    free(keyPairForm_max_tip_amount);
    if (keyForm_suggested_tip_amounts) {
        free(keyForm_suggested_tip_amounts);
        keyForm_suggested_tip_amounts = NULL;
    }
    free(keyPairForm_suggested_tip_amounts);
    if (keyForm_provider_data) {
        free(keyForm_provider_data);
        keyForm_provider_data = NULL;
    }
    if (valueForm_provider_data) {
        free(valueForm_provider_data);
        valueForm_provider_data = NULL;
    }
    free(keyPairForm_provider_data);
    if (keyForm_photo_url) {
        free(keyForm_photo_url);
        keyForm_photo_url = NULL;
    }
    if (valueForm_photo_url) {
        free(valueForm_photo_url);
        valueForm_photo_url = NULL;
    }
    free(keyPairForm_photo_url);
    if (keyForm_photo_size) {
        free(keyForm_photo_size);
        keyForm_photo_size = NULL;
    }
    free(keyPairForm_photo_size);
    if (keyForm_photo_width) {
        free(keyForm_photo_width);
        keyForm_photo_width = NULL;
    }
    free(keyPairForm_photo_width);
    if (keyForm_photo_height) {
        free(keyForm_photo_height);
        keyForm_photo_height = NULL;
    }
    free(keyPairForm_photo_height);
    if (keyForm_need_name) {
        free(keyForm_need_name);
        keyForm_need_name = NULL;
    }
    free(keyPairForm_need_name);
    if (keyForm_need_phone_number) {
        free(keyForm_need_phone_number);
        keyForm_need_phone_number = NULL;
    }
    free(keyPairForm_need_phone_number);
    if (keyForm_need_email) {
        free(keyForm_need_email);
        keyForm_need_email = NULL;
    }
    free(keyPairForm_need_email);
    if (keyForm_need_shipping_address) {
        free(keyForm_need_shipping_address);
        keyForm_need_shipping_address = NULL;
    }
    free(keyPairForm_need_shipping_address);
    if (keyForm_send_phone_number_to_provider) {
        free(keyForm_send_phone_number_to_provider);
        keyForm_send_phone_number_to_provider = NULL;
    }
    free(keyPairForm_send_phone_number_to_provider);
    if (keyForm_send_email_to_provider) {
        free(keyForm_send_email_to_provider);
        keyForm_send_email_to_provider = NULL;
    }
    free(keyPairForm_send_email_to_provider);
    if (keyForm_is_flexible) {
        free(keyForm_is_flexible);
        keyForm_is_flexible = NULL;
    }
    free(keyPairForm_is_flexible);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// createNewStickerSet
//
// Use this method to create a new sticker set owned by a user. The bot will be able to edit the sticker set thus created. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postCreateNewStickerSet(apiClient_t *apiClient, int *user_id, char *name, char *title, list_t *stickers, telegram_bot_api_postCreateNewStickerSet_sticker_type_e sticker_type, int *needs_repainting)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/createNewStickerSet");





    // form parameters
    char *keyForm_user_id = NULL;
    int valueForm_user_id = 0;
    keyValuePair_t *keyPairForm_user_id = 0;
    if (user_id != NULL)
    {
        keyForm_user_id = strdup("user_id");
        valueForm_user_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_user_id, MAX_NUMBER_LENGTH, "%d", *user_id);
        keyPairForm_user_id = keyValuePair_create(keyForm_user_id,&valueForm_user_id);
        list_addElement(localVarFormParameters,keyPairForm_user_id);
    }

    // form parameters
    char *keyForm_name = NULL;
    char * valueForm_name = 0;
    keyValuePair_t *keyPairForm_name = 0;
    if (name != NULL)
    {
        keyForm_name = strdup("name");
        valueForm_name = strdup((name));
        keyPairForm_name = keyValuePair_create(keyForm_name,valueForm_name);
        list_addElement(localVarFormParameters,keyPairForm_name);
    }

    // form parameters
    char *keyForm_title = NULL;
    char * valueForm_title = 0;
    keyValuePair_t *keyPairForm_title = 0;
    if (title != NULL)
    {
        keyForm_title = strdup("title");
        valueForm_title = strdup((title));
        keyPairForm_title = keyValuePair_create(keyForm_title,valueForm_title);
        list_addElement(localVarFormParameters,keyPairForm_title);
    }

    // form parameters
    char *keyForm_stickers = NULL;
     valueForm_stickers = 0;
    keyValuePair_t *keyPairForm_stickers = 0;
    if (stickers != NULL)
    {
        keyForm_stickers = strdup("stickers");
        valueForm_stickers = (stickers);
        keyPairForm_stickers = keyValuePair_create(keyForm_stickers,&valueForm_stickers);
        list_addElement(localVarFormParameters,keyPairForm_stickers);
    }

    // form parameters
    char *keyForm_sticker_type = NULL;
    telegram_bot_api_postCreateNewStickerSet_sticker_type_e valueForm_sticker_type = 0;
    keyValuePair_t *keyPairForm_sticker_type = 0;
    if (sticker_type != 0)
    {
        keyForm_sticker_type = strdup("sticker_type");
        valueForm_sticker_type = (sticker_type);
        keyPairForm_sticker_type = keyValuePair_create(keyForm_sticker_type,(void *)valueForm_sticker_type);
        list_addElement(localVarFormParameters,keyPairForm_sticker_type);
    }

    // form parameters
    char *keyForm_needs_repainting = NULL;
    char * valueForm_needs_repainting = 0;
    keyValuePair_t *keyPairForm_needs_repainting = 0;
    if (needs_repainting != NULL)
    {
        keyForm_needs_repainting = strdup("needs_repainting");
        valueForm_needs_repainting = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_needs_repainting, MAX_NUMBER_LENGTH, "%d", *needs_repainting);
        keyPairForm_needs_repainting = keyValuePair_create(keyForm_needs_repainting,valueForm_needs_repainting);
        list_addElement(localVarFormParameters,keyPairForm_needs_repainting);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_user_id) {
        free(keyForm_user_id);
        keyForm_user_id = NULL;
    }
    free(keyPairForm_user_id);
    if (keyForm_name) {
        free(keyForm_name);
        keyForm_name = NULL;
    }
    if (valueForm_name) {
        free(valueForm_name);
        valueForm_name = NULL;
    }
    free(keyPairForm_name);
    if (keyForm_title) {
        free(keyForm_title);
        keyForm_title = NULL;
    }
    if (valueForm_title) {
        free(valueForm_title);
        valueForm_title = NULL;
    }
    free(keyPairForm_title);
    if (keyForm_stickers) {
        free(keyForm_stickers);
        keyForm_stickers = NULL;
    }
    free(keyPairForm_stickers);
    if (keyForm_sticker_type) {
        free(keyForm_sticker_type);
        keyForm_sticker_type = NULL;
    }
    if (valueForm_sticker_type) {
        valueForm_sticker_type = 0;
    }
    free(keyPairForm_sticker_type);
    if (keyForm_needs_repainting) {
        free(keyForm_needs_repainting);
        keyForm_needs_repainting = NULL;
    }
    free(keyPairForm_needs_repainting);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// declineChatJoinRequest
//
// Use this method to decline a chat join request. The bot must be an administrator in the chat for this to work and must have the *can\\_invite\\_users* administrator right. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postDeclineChatJoinRequest(apiClient_t *apiClient, post_send_message_request_chat_id_t *chat_id, int *user_id)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/declineChatJoinRequest");





    // form parameters
    char *keyForm_chat_id = NULL;
    post_send_message_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_user_id = NULL;
    int valueForm_user_id = 0;
    keyValuePair_t *keyPairForm_user_id = 0;
    if (user_id != NULL)
    {
        keyForm_user_id = strdup("user_id");
        valueForm_user_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_user_id, MAX_NUMBER_LENGTH, "%d", *user_id);
        keyPairForm_user_id = keyValuePair_create(keyForm_user_id,&valueForm_user_id);
        list_addElement(localVarFormParameters,keyPairForm_user_id);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_user_id) {
        free(keyForm_user_id);
        keyForm_user_id = NULL;
    }
    free(keyPairForm_user_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// deleteBusinessMessages
//
// Delete messages on behalf of a business account. Requires the *can\\_delete\\_sent\\_messages* business bot right to delete messages sent by the bot itself, or the *can\\_delete\\_all\\_messages* business bot right to delete any message. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postDeleteBusinessMessages(apiClient_t *apiClient, char *business_connection_id, list_t *message_ids)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/deleteBusinessMessages");





    // form parameters
    char *keyForm_business_connection_id = NULL;
    char * valueForm_business_connection_id = 0;
    keyValuePair_t *keyPairForm_business_connection_id = 0;
    if (business_connection_id != NULL)
    {
        keyForm_business_connection_id = strdup("business_connection_id");
        valueForm_business_connection_id = strdup((business_connection_id));
        keyPairForm_business_connection_id = keyValuePair_create(keyForm_business_connection_id,valueForm_business_connection_id);
        list_addElement(localVarFormParameters,keyPairForm_business_connection_id);
    }

    // form parameters
    char *keyForm_message_ids = NULL;
     valueForm_message_ids = 0;
    keyValuePair_t *keyPairForm_message_ids = 0;
    if (message_ids != NULL)
    {
        keyForm_message_ids = strdup("message_ids");
        valueForm_message_ids = (message_ids);
        keyPairForm_message_ids = keyValuePair_create(keyForm_message_ids,&valueForm_message_ids);
        list_addElement(localVarFormParameters,keyPairForm_message_ids);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_business_connection_id) {
        free(keyForm_business_connection_id);
        keyForm_business_connection_id = NULL;
    }
    if (valueForm_business_connection_id) {
        free(valueForm_business_connection_id);
        valueForm_business_connection_id = NULL;
    }
    free(keyPairForm_business_connection_id);
    if (keyForm_message_ids) {
        free(keyForm_message_ids);
        keyForm_message_ids = NULL;
    }
    free(keyPairForm_message_ids);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// deleteChatPhoto
//
// Use this method to delete a chat photo. Photos can't be changed for private chats. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postDeleteChatPhoto(apiClient_t *apiClient, post_send_message_request_chat_id_t *chat_id)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/deleteChatPhoto");





    // form parameters
    char *keyForm_chat_id = NULL;
    post_send_message_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// deleteChatStickerSet
//
// Use this method to delete a group sticker set from a supergroup. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Use the field *can\\_set\\_sticker\\_set* optionally returned in [getChat](https://core.telegram.org/bots/api/#getchat) requests to check if the bot can use this method. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postDeleteChatStickerSet(apiClient_t *apiClient, post_restrict_chat_member_request_chat_id_t *chat_id)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/deleteChatStickerSet");





    // form parameters
    char *keyForm_chat_id = NULL;
    post_restrict_chat_member_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// deleteForumTopic
//
// Use this method to delete a forum topic along with all its messages in a forum supergroup chat. The bot must be an administrator in the chat for this to work and must have the *can\\_delete\\_messages* administrator rights. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postDeleteForumTopic(apiClient_t *apiClient, post_restrict_chat_member_request_chat_id_t *chat_id, int *message_thread_id)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/deleteForumTopic");





    // form parameters
    char *keyForm_chat_id = NULL;
    post_restrict_chat_member_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_message_thread_id = NULL;
    int valueForm_message_thread_id = 0;
    keyValuePair_t *keyPairForm_message_thread_id = 0;
    if (message_thread_id != NULL)
    {
        keyForm_message_thread_id = strdup("message_thread_id");
        valueForm_message_thread_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_message_thread_id, MAX_NUMBER_LENGTH, "%d", *message_thread_id);
        keyPairForm_message_thread_id = keyValuePair_create(keyForm_message_thread_id,&valueForm_message_thread_id);
        list_addElement(localVarFormParameters,keyPairForm_message_thread_id);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_message_thread_id) {
        free(keyForm_message_thread_id);
        keyForm_message_thread_id = NULL;
    }
    free(keyPairForm_message_thread_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// deleteMessage
//
// Use this method to delete a message, including service messages, with the following limitations:   \\- A message can only be deleted if it was sent less than 48 hours ago.   \\- Service messages about a supergroup, channel, or forum topic creation can't be deleted.   \\- A dice message in a private chat can only be deleted if it was sent more than 24 hours ago.   \\- Bots can delete outgoing messages in private chats, groups, and supergroups.   \\- Bots can delete incoming messages in private chats.   \\- Bots granted *can\\_post\\_messages* permissions can delete outgoing messages in channels.   \\- If the bot is an administrator of a group, it can delete any message there.   \\- If the bot has *can\\_delete\\_messages* permission in a supergroup or a channel, it can delete any message there.   Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postDeleteMessage(apiClient_t *apiClient, post_send_message_request_chat_id_t *chat_id, int *message_id)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/deleteMessage");





    // form parameters
    char *keyForm_chat_id = NULL;
    post_send_message_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_message_id = NULL;
    int valueForm_message_id = 0;
    keyValuePair_t *keyPairForm_message_id = 0;
    if (message_id != NULL)
    {
        keyForm_message_id = strdup("message_id");
        valueForm_message_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_message_id, MAX_NUMBER_LENGTH, "%d", *message_id);
        keyPairForm_message_id = keyValuePair_create(keyForm_message_id,&valueForm_message_id);
        list_addElement(localVarFormParameters,keyPairForm_message_id);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_message_id) {
        free(keyForm_message_id);
        keyForm_message_id = NULL;
    }
    free(keyPairForm_message_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// deleteMessages
//
// Use this method to delete multiple messages simultaneously. If some of the specified messages can't be found, they are skipped. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postDeleteMessages(apiClient_t *apiClient, post_send_message_request_chat_id_t *chat_id, list_t *message_ids)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/deleteMessages");





    // form parameters
    char *keyForm_chat_id = NULL;
    post_send_message_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_message_ids = NULL;
     valueForm_message_ids = 0;
    keyValuePair_t *keyPairForm_message_ids = 0;
    if (message_ids != NULL)
    {
        keyForm_message_ids = strdup("message_ids");
        valueForm_message_ids = (message_ids);
        keyPairForm_message_ids = keyValuePair_create(keyForm_message_ids,&valueForm_message_ids);
        list_addElement(localVarFormParameters,keyPairForm_message_ids);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_message_ids) {
        free(keyForm_message_ids);
        keyForm_message_ids = NULL;
    }
    free(keyPairForm_message_ids);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// deleteMyCommands
//
// Use this method to delete the list of the bot's commands for the given scope and user language. After deletion, [higher level commands](https://core.telegram.org/bots/api/#determining-list-of-commands) will be shown to affected users. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postDeleteMyCommands(apiClient_t *apiClient, bot_command_scope_t *scope, char *language_code)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/deleteMyCommands");





    // form parameters
    char *keyForm_scope = NULL;
    bot_command_scope_t * valueForm_scope = 0;
    keyValuePair_t *keyPairForm_scope = 0;
    if (scope != NULL)
    {
        keyForm_scope = strdup("scope");
        valueForm_scope = (scope);
        keyPairForm_scope = keyValuePair_create(keyForm_scope,&valueForm_scope);
        list_addElement(localVarFormParameters,keyPairForm_scope);
    }

    // form parameters
    char *keyForm_language_code = NULL;
    char * valueForm_language_code = 0;
    keyValuePair_t *keyPairForm_language_code = 0;
    if (language_code != NULL)
    {
        keyForm_language_code = strdup("language_code");
        valueForm_language_code = strdup((language_code));
        keyPairForm_language_code = keyValuePair_create(keyForm_language_code,valueForm_language_code);
        list_addElement(localVarFormParameters,keyPairForm_language_code);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_scope) {
        free(keyForm_scope);
        keyForm_scope = NULL;
    }
    free(keyPairForm_scope);
    if (keyForm_language_code) {
        free(keyForm_language_code);
        keyForm_language_code = NULL;
    }
    if (valueForm_language_code) {
        free(valueForm_language_code);
        valueForm_language_code = NULL;
    }
    free(keyPairForm_language_code);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// deleteStickerFromSet
//
// Use this method to delete a sticker from a set created by the bot. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postDeleteStickerFromSet(apiClient_t *apiClient, char *sticker)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/deleteStickerFromSet");





    // form parameters
    char *keyForm_sticker = NULL;
    char * valueForm_sticker = 0;
    keyValuePair_t *keyPairForm_sticker = 0;
    if (sticker != NULL)
    {
        keyForm_sticker = strdup("sticker");
        valueForm_sticker = strdup((sticker));
        keyPairForm_sticker = keyValuePair_create(keyForm_sticker,valueForm_sticker);
        list_addElement(localVarFormParameters,keyPairForm_sticker);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_sticker) {
        free(keyForm_sticker);
        keyForm_sticker = NULL;
    }
    if (valueForm_sticker) {
        free(valueForm_sticker);
        valueForm_sticker = NULL;
    }
    free(keyPairForm_sticker);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// deleteStickerSet
//
// Use this method to delete a sticker set that was created by the bot. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postDeleteStickerSet(apiClient_t *apiClient, char *name)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/deleteStickerSet");





    // form parameters
    char *keyForm_name = NULL;
    char * valueForm_name = 0;
    keyValuePair_t *keyPairForm_name = 0;
    if (name != NULL)
    {
        keyForm_name = strdup("name");
        valueForm_name = strdup((name));
        keyPairForm_name = keyValuePair_create(keyForm_name,valueForm_name);
        list_addElement(localVarFormParameters,keyPairForm_name);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_name) {
        free(keyForm_name);
        keyForm_name = NULL;
    }
    if (valueForm_name) {
        free(valueForm_name);
        valueForm_name = NULL;
    }
    free(keyPairForm_name);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// deleteStory
//
// Deletes a story previously posted by the bot on behalf of a managed business account. Requires the *can\\_manage\\_stories* business bot right. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postDeleteStory(apiClient_t *apiClient, char *business_connection_id, int *story_id)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/deleteStory");





    // form parameters
    char *keyForm_business_connection_id = NULL;
    char * valueForm_business_connection_id = 0;
    keyValuePair_t *keyPairForm_business_connection_id = 0;
    if (business_connection_id != NULL)
    {
        keyForm_business_connection_id = strdup("business_connection_id");
        valueForm_business_connection_id = strdup((business_connection_id));
        keyPairForm_business_connection_id = keyValuePair_create(keyForm_business_connection_id,valueForm_business_connection_id);
        list_addElement(localVarFormParameters,keyPairForm_business_connection_id);
    }

    // form parameters
    char *keyForm_story_id = NULL;
    int valueForm_story_id = 0;
    keyValuePair_t *keyPairForm_story_id = 0;
    if (story_id != NULL)
    {
        keyForm_story_id = strdup("story_id");
        valueForm_story_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_story_id, MAX_NUMBER_LENGTH, "%d", *story_id);
        keyPairForm_story_id = keyValuePair_create(keyForm_story_id,&valueForm_story_id);
        list_addElement(localVarFormParameters,keyPairForm_story_id);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_business_connection_id) {
        free(keyForm_business_connection_id);
        keyForm_business_connection_id = NULL;
    }
    if (valueForm_business_connection_id) {
        free(valueForm_business_connection_id);
        valueForm_business_connection_id = NULL;
    }
    free(keyPairForm_business_connection_id);
    if (keyForm_story_id) {
        free(keyForm_story_id);
        keyForm_story_id = NULL;
    }
    free(keyPairForm_story_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// deleteWebhook
//
// Use this method to remove webhook integration if you decide to switch back to [getUpdates](https://core.telegram.org/bots/api/#getupdates). Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postDeleteWebhook(apiClient_t *apiClient, int *drop_pending_updates)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/deleteWebhook");





    // form parameters
    char *keyForm_drop_pending_updates = NULL;
    char * valueForm_drop_pending_updates = 0;
    keyValuePair_t *keyPairForm_drop_pending_updates = 0;
    if (drop_pending_updates != NULL)
    {
        keyForm_drop_pending_updates = strdup("drop_pending_updates");
        valueForm_drop_pending_updates = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_drop_pending_updates, MAX_NUMBER_LENGTH, "%d", *drop_pending_updates);
        keyPairForm_drop_pending_updates = keyValuePair_create(keyForm_drop_pending_updates,valueForm_drop_pending_updates);
        list_addElement(localVarFormParameters,keyPairForm_drop_pending_updates);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_drop_pending_updates) {
        free(keyForm_drop_pending_updates);
        keyForm_drop_pending_updates = NULL;
    }
    free(keyPairForm_drop_pending_updates);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// editChatInviteLink
//
// Use this method to edit a non-primary invite link created by the bot. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Returns the edited invite link as a [ChatInviteLink](https://core.telegram.org/bots/api/#chatinvitelink) object.
//
post_create_chat_invite_link_200_response_t*
DefaultAPI_postEditChatInviteLink(apiClient_t *apiClient, post_send_message_request_chat_id_t *chat_id, char *invite_link, char *name, int *expire_date, int *member_limit, int *creates_join_request)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/editChatInviteLink");





    // form parameters
    char *keyForm_chat_id = NULL;
    post_send_message_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_invite_link = NULL;
    char * valueForm_invite_link = 0;
    keyValuePair_t *keyPairForm_invite_link = 0;
    if (invite_link != NULL)
    {
        keyForm_invite_link = strdup("invite_link");
        valueForm_invite_link = strdup((invite_link));
        keyPairForm_invite_link = keyValuePair_create(keyForm_invite_link,valueForm_invite_link);
        list_addElement(localVarFormParameters,keyPairForm_invite_link);
    }

    // form parameters
    char *keyForm_name = NULL;
    char * valueForm_name = 0;
    keyValuePair_t *keyPairForm_name = 0;
    if (name != NULL)
    {
        keyForm_name = strdup("name");
        valueForm_name = strdup((name));
        keyPairForm_name = keyValuePair_create(keyForm_name,valueForm_name);
        list_addElement(localVarFormParameters,keyPairForm_name);
    }

    // form parameters
    char *keyForm_expire_date = NULL;
    int valueForm_expire_date = 0;
    keyValuePair_t *keyPairForm_expire_date = 0;
    if (expire_date != NULL)
    {
        keyForm_expire_date = strdup("expire_date");
        valueForm_expire_date = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_expire_date, MAX_NUMBER_LENGTH, "%d", *expire_date);
        keyPairForm_expire_date = keyValuePair_create(keyForm_expire_date,&valueForm_expire_date);
        list_addElement(localVarFormParameters,keyPairForm_expire_date);
    }

    // form parameters
    char *keyForm_member_limit = NULL;
    int valueForm_member_limit = 0;
    keyValuePair_t *keyPairForm_member_limit = 0;
    if (member_limit != NULL)
    {
        keyForm_member_limit = strdup("member_limit");
        valueForm_member_limit = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_member_limit, MAX_NUMBER_LENGTH, "%d", *member_limit);
        keyPairForm_member_limit = keyValuePair_create(keyForm_member_limit,&valueForm_member_limit);
        list_addElement(localVarFormParameters,keyPairForm_member_limit);
    }

    // form parameters
    char *keyForm_creates_join_request = NULL;
    char * valueForm_creates_join_request = 0;
    keyValuePair_t *keyPairForm_creates_join_request = 0;
    if (creates_join_request != NULL)
    {
        keyForm_creates_join_request = strdup("creates_join_request");
        valueForm_creates_join_request = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_creates_join_request, MAX_NUMBER_LENGTH, "%d", *creates_join_request);
        keyPairForm_creates_join_request = keyValuePair_create(keyForm_creates_join_request,valueForm_creates_join_request);
        list_addElement(localVarFormParameters,keyPairForm_creates_join_request);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_create_chat_invite_link_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_create_chat_invite_link_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_invite_link) {
        free(keyForm_invite_link);
        keyForm_invite_link = NULL;
    }
    if (valueForm_invite_link) {
        free(valueForm_invite_link);
        valueForm_invite_link = NULL;
    }
    free(keyPairForm_invite_link);
    if (keyForm_name) {
        free(keyForm_name);
        keyForm_name = NULL;
    }
    if (valueForm_name) {
        free(valueForm_name);
        valueForm_name = NULL;
    }
    free(keyPairForm_name);
    if (keyForm_expire_date) {
        free(keyForm_expire_date);
        keyForm_expire_date = NULL;
    }
    free(keyPairForm_expire_date);
    if (keyForm_member_limit) {
        free(keyForm_member_limit);
        keyForm_member_limit = NULL;
    }
    free(keyPairForm_member_limit);
    if (keyForm_creates_join_request) {
        free(keyForm_creates_join_request);
        keyForm_creates_join_request = NULL;
    }
    free(keyPairForm_creates_join_request);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// editChatSubscriptionInviteLink
//
// Use this method to edit a subscription invite link created by the bot. The bot must have the *can\\_invite\\_users* administrator rights. Returns the edited invite link as a [ChatInviteLink](https://core.telegram.org/bots/api/#chatinvitelink) object.
//
post_create_chat_invite_link_200_response_t*
DefaultAPI_postEditChatSubscriptionInviteLink(apiClient_t *apiClient, post_send_message_request_chat_id_t *chat_id, char *invite_link, char *name)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/editChatSubscriptionInviteLink");





    // form parameters
    char *keyForm_chat_id = NULL;
    post_send_message_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_invite_link = NULL;
    char * valueForm_invite_link = 0;
    keyValuePair_t *keyPairForm_invite_link = 0;
    if (invite_link != NULL)
    {
        keyForm_invite_link = strdup("invite_link");
        valueForm_invite_link = strdup((invite_link));
        keyPairForm_invite_link = keyValuePair_create(keyForm_invite_link,valueForm_invite_link);
        list_addElement(localVarFormParameters,keyPairForm_invite_link);
    }

    // form parameters
    char *keyForm_name = NULL;
    char * valueForm_name = 0;
    keyValuePair_t *keyPairForm_name = 0;
    if (name != NULL)
    {
        keyForm_name = strdup("name");
        valueForm_name = strdup((name));
        keyPairForm_name = keyValuePair_create(keyForm_name,valueForm_name);
        list_addElement(localVarFormParameters,keyPairForm_name);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_create_chat_invite_link_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_create_chat_invite_link_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_invite_link) {
        free(keyForm_invite_link);
        keyForm_invite_link = NULL;
    }
    if (valueForm_invite_link) {
        free(valueForm_invite_link);
        valueForm_invite_link = NULL;
    }
    free(keyPairForm_invite_link);
    if (keyForm_name) {
        free(keyForm_name);
        keyForm_name = NULL;
    }
    if (valueForm_name) {
        free(valueForm_name);
        valueForm_name = NULL;
    }
    free(keyPairForm_name);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// editForumTopic
//
// Use this method to edit name and icon of a topic in a forum supergroup chat. The bot must be an administrator in the chat for this to work and must have the *can\\_manage\\_topics* administrator rights, unless it is the creator of the topic. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postEditForumTopic(apiClient_t *apiClient, post_restrict_chat_member_request_chat_id_t *chat_id, int *message_thread_id, char *name, char *icon_custom_emoji_id)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/editForumTopic");





    // form parameters
    char *keyForm_chat_id = NULL;
    post_restrict_chat_member_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_message_thread_id = NULL;
    int valueForm_message_thread_id = 0;
    keyValuePair_t *keyPairForm_message_thread_id = 0;
    if (message_thread_id != NULL)
    {
        keyForm_message_thread_id = strdup("message_thread_id");
        valueForm_message_thread_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_message_thread_id, MAX_NUMBER_LENGTH, "%d", *message_thread_id);
        keyPairForm_message_thread_id = keyValuePair_create(keyForm_message_thread_id,&valueForm_message_thread_id);
        list_addElement(localVarFormParameters,keyPairForm_message_thread_id);
    }

    // form parameters
    char *keyForm_name = NULL;
    char * valueForm_name = 0;
    keyValuePair_t *keyPairForm_name = 0;
    if (name != NULL)
    {
        keyForm_name = strdup("name");
        valueForm_name = strdup((name));
        keyPairForm_name = keyValuePair_create(keyForm_name,valueForm_name);
        list_addElement(localVarFormParameters,keyPairForm_name);
    }

    // form parameters
    char *keyForm_icon_custom_emoji_id = NULL;
    char * valueForm_icon_custom_emoji_id = 0;
    keyValuePair_t *keyPairForm_icon_custom_emoji_id = 0;
    if (icon_custom_emoji_id != NULL)
    {
        keyForm_icon_custom_emoji_id = strdup("icon_custom_emoji_id");
        valueForm_icon_custom_emoji_id = strdup((icon_custom_emoji_id));
        keyPairForm_icon_custom_emoji_id = keyValuePair_create(keyForm_icon_custom_emoji_id,valueForm_icon_custom_emoji_id);
        list_addElement(localVarFormParameters,keyPairForm_icon_custom_emoji_id);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_message_thread_id) {
        free(keyForm_message_thread_id);
        keyForm_message_thread_id = NULL;
    }
    free(keyPairForm_message_thread_id);
    if (keyForm_name) {
        free(keyForm_name);
        keyForm_name = NULL;
    }
    if (valueForm_name) {
        free(valueForm_name);
        valueForm_name = NULL;
    }
    free(keyPairForm_name);
    if (keyForm_icon_custom_emoji_id) {
        free(keyForm_icon_custom_emoji_id);
        keyForm_icon_custom_emoji_id = NULL;
    }
    if (valueForm_icon_custom_emoji_id) {
        free(valueForm_icon_custom_emoji_id);
        valueForm_icon_custom_emoji_id = NULL;
    }
    free(keyPairForm_icon_custom_emoji_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// editGeneralForumTopic
//
// Use this method to edit the name of the 'General' topic in a forum supergroup chat. The bot must be an administrator in the chat for this to work and must have the *can\\_manage\\_topics* administrator rights. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postEditGeneralForumTopic(apiClient_t *apiClient, post_restrict_chat_member_request_chat_id_t *chat_id, char *name)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/editGeneralForumTopic");





    // form parameters
    char *keyForm_chat_id = NULL;
    post_restrict_chat_member_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_name = NULL;
    char * valueForm_name = 0;
    keyValuePair_t *keyPairForm_name = 0;
    if (name != NULL)
    {
        keyForm_name = strdup("name");
        valueForm_name = strdup((name));
        keyPairForm_name = keyValuePair_create(keyForm_name,valueForm_name);
        list_addElement(localVarFormParameters,keyPairForm_name);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_name) {
        free(keyForm_name);
        keyForm_name = NULL;
    }
    if (valueForm_name) {
        free(valueForm_name);
        valueForm_name = NULL;
    }
    free(keyPairForm_name);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// editMessageCaption
//
// Use this method to edit captions of messages. On success, if the edited message is not an inline message, the edited [Message](https://core.telegram.org/bots/api/#message) is returned, otherwise *True* is returned. Note that business messages that were not sent by the bot and do not contain an inline keyboard can only be edited within **48 hours** from the time they were sent.
//
post_edit_message_text_200_response_t*
DefaultAPI_postEditMessageCaption(apiClient_t *apiClient, char *business_connection_id, post_edit_message_text_request_chat_id_t *chat_id, int *message_id, char *inline_message_id, char *caption, char *parse_mode, list_t *caption_entities, int *show_caption_above_media, inline_keyboard_markup_t *reply_markup)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/editMessageCaption");





    // form parameters
    char *keyForm_business_connection_id = NULL;
    char * valueForm_business_connection_id = 0;
    keyValuePair_t *keyPairForm_business_connection_id = 0;
    if (business_connection_id != NULL)
    {
        keyForm_business_connection_id = strdup("business_connection_id");
        valueForm_business_connection_id = strdup((business_connection_id));
        keyPairForm_business_connection_id = keyValuePair_create(keyForm_business_connection_id,valueForm_business_connection_id);
        list_addElement(localVarFormParameters,keyPairForm_business_connection_id);
    }

    // form parameters
    char *keyForm_chat_id = NULL;
    post_edit_message_text_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_message_id = NULL;
    int valueForm_message_id = 0;
    keyValuePair_t *keyPairForm_message_id = 0;
    if (message_id != NULL)
    {
        keyForm_message_id = strdup("message_id");
        valueForm_message_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_message_id, MAX_NUMBER_LENGTH, "%d", *message_id);
        keyPairForm_message_id = keyValuePair_create(keyForm_message_id,&valueForm_message_id);
        list_addElement(localVarFormParameters,keyPairForm_message_id);
    }

    // form parameters
    char *keyForm_inline_message_id = NULL;
    char * valueForm_inline_message_id = 0;
    keyValuePair_t *keyPairForm_inline_message_id = 0;
    if (inline_message_id != NULL)
    {
        keyForm_inline_message_id = strdup("inline_message_id");
        valueForm_inline_message_id = strdup((inline_message_id));
        keyPairForm_inline_message_id = keyValuePair_create(keyForm_inline_message_id,valueForm_inline_message_id);
        list_addElement(localVarFormParameters,keyPairForm_inline_message_id);
    }

    // form parameters
    char *keyForm_caption = NULL;
    char * valueForm_caption = 0;
    keyValuePair_t *keyPairForm_caption = 0;
    if (caption != NULL)
    {
        keyForm_caption = strdup("caption");
        valueForm_caption = strdup((caption));
        keyPairForm_caption = keyValuePair_create(keyForm_caption,valueForm_caption);
        list_addElement(localVarFormParameters,keyPairForm_caption);
    }

    // form parameters
    char *keyForm_parse_mode = NULL;
    char * valueForm_parse_mode = 0;
    keyValuePair_t *keyPairForm_parse_mode = 0;
    if (parse_mode != NULL)
    {
        keyForm_parse_mode = strdup("parse_mode");
        valueForm_parse_mode = strdup((parse_mode));
        keyPairForm_parse_mode = keyValuePair_create(keyForm_parse_mode,valueForm_parse_mode);
        list_addElement(localVarFormParameters,keyPairForm_parse_mode);
    }

    // form parameters
    char *keyForm_caption_entities = NULL;
     valueForm_caption_entities = 0;
    keyValuePair_t *keyPairForm_caption_entities = 0;
    if (caption_entities != NULL)
    {
        keyForm_caption_entities = strdup("caption_entities");
        valueForm_caption_entities = (caption_entities);
        keyPairForm_caption_entities = keyValuePair_create(keyForm_caption_entities,&valueForm_caption_entities);
        list_addElement(localVarFormParameters,keyPairForm_caption_entities);
    }

    // form parameters
    char *keyForm_show_caption_above_media = NULL;
    char * valueForm_show_caption_above_media = 0;
    keyValuePair_t *keyPairForm_show_caption_above_media = 0;
    if (show_caption_above_media != NULL)
    {
        keyForm_show_caption_above_media = strdup("show_caption_above_media");
        valueForm_show_caption_above_media = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_show_caption_above_media, MAX_NUMBER_LENGTH, "%d", *show_caption_above_media);
        keyPairForm_show_caption_above_media = keyValuePair_create(keyForm_show_caption_above_media,valueForm_show_caption_above_media);
        list_addElement(localVarFormParameters,keyPairForm_show_caption_above_media);
    }

    // form parameters
    char *keyForm_reply_markup = NULL;
    inline_keyboard_markup_t * valueForm_reply_markup = 0;
    keyValuePair_t *keyPairForm_reply_markup = 0;
    if (reply_markup != NULL)
    {
        keyForm_reply_markup = strdup("reply_markup");
        valueForm_reply_markup = (reply_markup);
        keyPairForm_reply_markup = keyValuePair_create(keyForm_reply_markup,&valueForm_reply_markup);
        list_addElement(localVarFormParameters,keyPairForm_reply_markup);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_edit_message_text_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_edit_message_text_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_business_connection_id) {
        free(keyForm_business_connection_id);
        keyForm_business_connection_id = NULL;
    }
    if (valueForm_business_connection_id) {
        free(valueForm_business_connection_id);
        valueForm_business_connection_id = NULL;
    }
    free(keyPairForm_business_connection_id);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_message_id) {
        free(keyForm_message_id);
        keyForm_message_id = NULL;
    }
    free(keyPairForm_message_id);
    if (keyForm_inline_message_id) {
        free(keyForm_inline_message_id);
        keyForm_inline_message_id = NULL;
    }
    if (valueForm_inline_message_id) {
        free(valueForm_inline_message_id);
        valueForm_inline_message_id = NULL;
    }
    free(keyPairForm_inline_message_id);
    if (keyForm_caption) {
        free(keyForm_caption);
        keyForm_caption = NULL;
    }
    if (valueForm_caption) {
        free(valueForm_caption);
        valueForm_caption = NULL;
    }
    free(keyPairForm_caption);
    if (keyForm_parse_mode) {
        free(keyForm_parse_mode);
        keyForm_parse_mode = NULL;
    }
    if (valueForm_parse_mode) {
        free(valueForm_parse_mode);
        valueForm_parse_mode = NULL;
    }
    free(keyPairForm_parse_mode);
    if (keyForm_caption_entities) {
        free(keyForm_caption_entities);
        keyForm_caption_entities = NULL;
    }
    free(keyPairForm_caption_entities);
    if (keyForm_show_caption_above_media) {
        free(keyForm_show_caption_above_media);
        keyForm_show_caption_above_media = NULL;
    }
    free(keyPairForm_show_caption_above_media);
    if (keyForm_reply_markup) {
        free(keyForm_reply_markup);
        keyForm_reply_markup = NULL;
    }
    free(keyPairForm_reply_markup);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// editMessageLiveLocation
//
// Use this method to edit live location messages. A location can be edited until its *live\\_period* expires or editing is explicitly disabled by a call to [stopMessageLiveLocation](https://core.telegram.org/bots/api/#stopmessagelivelocation). On success, if the edited message is not an inline message, the edited [Message](https://core.telegram.org/bots/api/#message) is returned, otherwise *True* is returned.
//
post_edit_message_text_200_response_t*
DefaultAPI_postEditMessageLiveLocation(apiClient_t *apiClient, double latitude, double longitude, char *business_connection_id, post_edit_message_text_request_chat_id_t *chat_id, int *message_id, char *inline_message_id, int *live_period, double horizontal_accuracy, int *heading, int *proximity_alert_radius, inline_keyboard_markup_t *reply_markup)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/editMessageLiveLocation");





    // form parameters
    char *keyForm_business_connection_id = NULL;
    char * valueForm_business_connection_id = 0;
    keyValuePair_t *keyPairForm_business_connection_id = 0;
    if (business_connection_id != NULL)
    {
        keyForm_business_connection_id = strdup("business_connection_id");
        valueForm_business_connection_id = strdup((business_connection_id));
        keyPairForm_business_connection_id = keyValuePair_create(keyForm_business_connection_id,valueForm_business_connection_id);
        list_addElement(localVarFormParameters,keyPairForm_business_connection_id);
    }

    // form parameters
    char *keyForm_chat_id = NULL;
    post_edit_message_text_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_message_id = NULL;
    int valueForm_message_id = 0;
    keyValuePair_t *keyPairForm_message_id = 0;
    if (message_id != NULL)
    {
        keyForm_message_id = strdup("message_id");
        valueForm_message_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_message_id, MAX_NUMBER_LENGTH, "%d", *message_id);
        keyPairForm_message_id = keyValuePair_create(keyForm_message_id,&valueForm_message_id);
        list_addElement(localVarFormParameters,keyPairForm_message_id);
    }

    // form parameters
    char *keyForm_inline_message_id = NULL;
    char * valueForm_inline_message_id = 0;
    keyValuePair_t *keyPairForm_inline_message_id = 0;
    if (inline_message_id != NULL)
    {
        keyForm_inline_message_id = strdup("inline_message_id");
        valueForm_inline_message_id = strdup((inline_message_id));
        keyPairForm_inline_message_id = keyValuePair_create(keyForm_inline_message_id,valueForm_inline_message_id);
        list_addElement(localVarFormParameters,keyPairForm_inline_message_id);
    }

    // form parameters
    char *keyForm_latitude = NULL;
    double valueForm_latitude = 0;
    keyValuePair_t *keyPairForm_latitude = 0;
    if (latitude != NULL)
    {
        keyForm_latitude = strdup("latitude");
        valueForm_latitude = (latitude);
        keyPairForm_latitude = keyValuePair_create(keyForm_latitude,&valueForm_latitude);
        list_addElement(localVarFormParameters,keyPairForm_latitude);
    }

    // form parameters
    char *keyForm_longitude = NULL;
    double valueForm_longitude = 0;
    keyValuePair_t *keyPairForm_longitude = 0;
    if (longitude != NULL)
    {
        keyForm_longitude = strdup("longitude");
        valueForm_longitude = (longitude);
        keyPairForm_longitude = keyValuePair_create(keyForm_longitude,&valueForm_longitude);
        list_addElement(localVarFormParameters,keyPairForm_longitude);
    }

    // form parameters
    char *keyForm_live_period = NULL;
    int valueForm_live_period = 0;
    keyValuePair_t *keyPairForm_live_period = 0;
    if (live_period != NULL)
    {
        keyForm_live_period = strdup("live_period");
        valueForm_live_period = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_live_period, MAX_NUMBER_LENGTH, "%d", *live_period);
        keyPairForm_live_period = keyValuePair_create(keyForm_live_period,&valueForm_live_period);
        list_addElement(localVarFormParameters,keyPairForm_live_period);
    }

    // form parameters
    char *keyForm_horizontal_accuracy = NULL;
    double valueForm_horizontal_accuracy = 0;
    keyValuePair_t *keyPairForm_horizontal_accuracy = 0;
    if (horizontal_accuracy != NULL)
    {
        keyForm_horizontal_accuracy = strdup("horizontal_accuracy");
        valueForm_horizontal_accuracy = (horizontal_accuracy);
        keyPairForm_horizontal_accuracy = keyValuePair_create(keyForm_horizontal_accuracy,&valueForm_horizontal_accuracy);
        list_addElement(localVarFormParameters,keyPairForm_horizontal_accuracy);
    }

    // form parameters
    char *keyForm_heading = NULL;
    int valueForm_heading = 0;
    keyValuePair_t *keyPairForm_heading = 0;
    if (heading != NULL)
    {
        keyForm_heading = strdup("heading");
        valueForm_heading = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_heading, MAX_NUMBER_LENGTH, "%d", *heading);
        keyPairForm_heading = keyValuePair_create(keyForm_heading,&valueForm_heading);
        list_addElement(localVarFormParameters,keyPairForm_heading);
    }

    // form parameters
    char *keyForm_proximity_alert_radius = NULL;
    int valueForm_proximity_alert_radius = 0;
    keyValuePair_t *keyPairForm_proximity_alert_radius = 0;
    if (proximity_alert_radius != NULL)
    {
        keyForm_proximity_alert_radius = strdup("proximity_alert_radius");
        valueForm_proximity_alert_radius = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_proximity_alert_radius, MAX_NUMBER_LENGTH, "%d", *proximity_alert_radius);
        keyPairForm_proximity_alert_radius = keyValuePair_create(keyForm_proximity_alert_radius,&valueForm_proximity_alert_radius);
        list_addElement(localVarFormParameters,keyPairForm_proximity_alert_radius);
    }

    // form parameters
    char *keyForm_reply_markup = NULL;
    inline_keyboard_markup_t * valueForm_reply_markup = 0;
    keyValuePair_t *keyPairForm_reply_markup = 0;
    if (reply_markup != NULL)
    {
        keyForm_reply_markup = strdup("reply_markup");
        valueForm_reply_markup = (reply_markup);
        keyPairForm_reply_markup = keyValuePair_create(keyForm_reply_markup,&valueForm_reply_markup);
        list_addElement(localVarFormParameters,keyPairForm_reply_markup);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_edit_message_text_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_edit_message_text_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_business_connection_id) {
        free(keyForm_business_connection_id);
        keyForm_business_connection_id = NULL;
    }
    if (valueForm_business_connection_id) {
        free(valueForm_business_connection_id);
        valueForm_business_connection_id = NULL;
    }
    free(keyPairForm_business_connection_id);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_message_id) {
        free(keyForm_message_id);
        keyForm_message_id = NULL;
    }
    free(keyPairForm_message_id);
    if (keyForm_inline_message_id) {
        free(keyForm_inline_message_id);
        keyForm_inline_message_id = NULL;
    }
    if (valueForm_inline_message_id) {
        free(valueForm_inline_message_id);
        valueForm_inline_message_id = NULL;
    }
    free(keyPairForm_inline_message_id);
    if (keyForm_latitude) {
        free(keyForm_latitude);
        keyForm_latitude = NULL;
    }
    free(keyPairForm_latitude);
    if (keyForm_longitude) {
        free(keyForm_longitude);
        keyForm_longitude = NULL;
    }
    free(keyPairForm_longitude);
    if (keyForm_live_period) {
        free(keyForm_live_period);
        keyForm_live_period = NULL;
    }
    free(keyPairForm_live_period);
    if (keyForm_horizontal_accuracy) {
        free(keyForm_horizontal_accuracy);
        keyForm_horizontal_accuracy = NULL;
    }
    free(keyPairForm_horizontal_accuracy);
    if (keyForm_heading) {
        free(keyForm_heading);
        keyForm_heading = NULL;
    }
    free(keyPairForm_heading);
    if (keyForm_proximity_alert_radius) {
        free(keyForm_proximity_alert_radius);
        keyForm_proximity_alert_radius = NULL;
    }
    free(keyPairForm_proximity_alert_radius);
    if (keyForm_reply_markup) {
        free(keyForm_reply_markup);
        keyForm_reply_markup = NULL;
    }
    free(keyPairForm_reply_markup);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// editMessageMedia
//
// Use this method to edit animation, audio, document, photo, or video messages, or to add media to text messages. If a message is part of a message album, then it can be edited only to an audio for audio albums, only to a document for document albums and to a photo or a video otherwise. When an inline message is edited, a new file can't be uploaded; use a previously uploaded file via its file\\_id or specify a URL. On success, if the edited message is not an inline message, the edited [Message](https://core.telegram.org/bots/api/#message) is returned, otherwise *True* is returned. Note that business messages that were not sent by the bot and do not contain an inline keyboard can only be edited within **48 hours** from the time they were sent.
//
post_edit_message_text_200_response_t*
DefaultAPI_postEditMessageMedia(apiClient_t *apiClient, input_media_t *media, char *business_connection_id, post_edit_message_text_request_chat_id_t *chat_id, int *message_id, char *inline_message_id, inline_keyboard_markup_t *reply_markup)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/editMessageMedia");





    // form parameters
    char *keyForm_business_connection_id = NULL;
    char * valueForm_business_connection_id = 0;
    keyValuePair_t *keyPairForm_business_connection_id = 0;
    if (business_connection_id != NULL)
    {
        keyForm_business_connection_id = strdup("business_connection_id");
        valueForm_business_connection_id = strdup((business_connection_id));
        keyPairForm_business_connection_id = keyValuePair_create(keyForm_business_connection_id,valueForm_business_connection_id);
        list_addElement(localVarFormParameters,keyPairForm_business_connection_id);
    }

    // form parameters
    char *keyForm_chat_id = NULL;
    post_edit_message_text_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_message_id = NULL;
    int valueForm_message_id = 0;
    keyValuePair_t *keyPairForm_message_id = 0;
    if (message_id != NULL)
    {
        keyForm_message_id = strdup("message_id");
        valueForm_message_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_message_id, MAX_NUMBER_LENGTH, "%d", *message_id);
        keyPairForm_message_id = keyValuePair_create(keyForm_message_id,&valueForm_message_id);
        list_addElement(localVarFormParameters,keyPairForm_message_id);
    }

    // form parameters
    char *keyForm_inline_message_id = NULL;
    char * valueForm_inline_message_id = 0;
    keyValuePair_t *keyPairForm_inline_message_id = 0;
    if (inline_message_id != NULL)
    {
        keyForm_inline_message_id = strdup("inline_message_id");
        valueForm_inline_message_id = strdup((inline_message_id));
        keyPairForm_inline_message_id = keyValuePair_create(keyForm_inline_message_id,valueForm_inline_message_id);
        list_addElement(localVarFormParameters,keyPairForm_inline_message_id);
    }

    // form parameters
    char *keyForm_media = NULL;
    input_media_t * valueForm_media = 0;
    keyValuePair_t *keyPairForm_media = 0;
    if (media != NULL)
    {
        keyForm_media = strdup("media");
        valueForm_media = (media);
        keyPairForm_media = keyValuePair_create(keyForm_media,&valueForm_media);
        list_addElement(localVarFormParameters,keyPairForm_media);
    }

    // form parameters
    char *keyForm_reply_markup = NULL;
    inline_keyboard_markup_t * valueForm_reply_markup = 0;
    keyValuePair_t *keyPairForm_reply_markup = 0;
    if (reply_markup != NULL)
    {
        keyForm_reply_markup = strdup("reply_markup");
        valueForm_reply_markup = (reply_markup);
        keyPairForm_reply_markup = keyValuePair_create(keyForm_reply_markup,&valueForm_reply_markup);
        list_addElement(localVarFormParameters,keyPairForm_reply_markup);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_edit_message_text_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_edit_message_text_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_business_connection_id) {
        free(keyForm_business_connection_id);
        keyForm_business_connection_id = NULL;
    }
    if (valueForm_business_connection_id) {
        free(valueForm_business_connection_id);
        valueForm_business_connection_id = NULL;
    }
    free(keyPairForm_business_connection_id);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_message_id) {
        free(keyForm_message_id);
        keyForm_message_id = NULL;
    }
    free(keyPairForm_message_id);
    if (keyForm_inline_message_id) {
        free(keyForm_inline_message_id);
        keyForm_inline_message_id = NULL;
    }
    if (valueForm_inline_message_id) {
        free(valueForm_inline_message_id);
        valueForm_inline_message_id = NULL;
    }
    free(keyPairForm_inline_message_id);
    if (keyForm_media) {
        free(keyForm_media);
        keyForm_media = NULL;
    }
    free(keyPairForm_media);
    if (keyForm_reply_markup) {
        free(keyForm_reply_markup);
        keyForm_reply_markup = NULL;
    }
    free(keyPairForm_reply_markup);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// editMessageReplyMarkup
//
// Use this method to edit only the reply markup of messages. On success, if the edited message is not an inline message, the edited [Message](https://core.telegram.org/bots/api/#message) is returned, otherwise *True* is returned. Note that business messages that were not sent by the bot and do not contain an inline keyboard can only be edited within **48 hours** from the time they were sent.
//
post_edit_message_text_200_response_t*
DefaultAPI_postEditMessageReplyMarkup(apiClient_t *apiClient, char *business_connection_id, post_edit_message_text_request_chat_id_t *chat_id, int *message_id, char *inline_message_id, inline_keyboard_markup_t *reply_markup)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/editMessageReplyMarkup");





    // form parameters
    char *keyForm_business_connection_id = NULL;
    char * valueForm_business_connection_id = 0;
    keyValuePair_t *keyPairForm_business_connection_id = 0;
    if (business_connection_id != NULL)
    {
        keyForm_business_connection_id = strdup("business_connection_id");
        valueForm_business_connection_id = strdup((business_connection_id));
        keyPairForm_business_connection_id = keyValuePair_create(keyForm_business_connection_id,valueForm_business_connection_id);
        list_addElement(localVarFormParameters,keyPairForm_business_connection_id);
    }

    // form parameters
    char *keyForm_chat_id = NULL;
    post_edit_message_text_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_message_id = NULL;
    int valueForm_message_id = 0;
    keyValuePair_t *keyPairForm_message_id = 0;
    if (message_id != NULL)
    {
        keyForm_message_id = strdup("message_id");
        valueForm_message_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_message_id, MAX_NUMBER_LENGTH, "%d", *message_id);
        keyPairForm_message_id = keyValuePair_create(keyForm_message_id,&valueForm_message_id);
        list_addElement(localVarFormParameters,keyPairForm_message_id);
    }

    // form parameters
    char *keyForm_inline_message_id = NULL;
    char * valueForm_inline_message_id = 0;
    keyValuePair_t *keyPairForm_inline_message_id = 0;
    if (inline_message_id != NULL)
    {
        keyForm_inline_message_id = strdup("inline_message_id");
        valueForm_inline_message_id = strdup((inline_message_id));
        keyPairForm_inline_message_id = keyValuePair_create(keyForm_inline_message_id,valueForm_inline_message_id);
        list_addElement(localVarFormParameters,keyPairForm_inline_message_id);
    }

    // form parameters
    char *keyForm_reply_markup = NULL;
    inline_keyboard_markup_t * valueForm_reply_markup = 0;
    keyValuePair_t *keyPairForm_reply_markup = 0;
    if (reply_markup != NULL)
    {
        keyForm_reply_markup = strdup("reply_markup");
        valueForm_reply_markup = (reply_markup);
        keyPairForm_reply_markup = keyValuePair_create(keyForm_reply_markup,&valueForm_reply_markup);
        list_addElement(localVarFormParameters,keyPairForm_reply_markup);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_edit_message_text_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_edit_message_text_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_business_connection_id) {
        free(keyForm_business_connection_id);
        keyForm_business_connection_id = NULL;
    }
    if (valueForm_business_connection_id) {
        free(valueForm_business_connection_id);
        valueForm_business_connection_id = NULL;
    }
    free(keyPairForm_business_connection_id);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_message_id) {
        free(keyForm_message_id);
        keyForm_message_id = NULL;
    }
    free(keyPairForm_message_id);
    if (keyForm_inline_message_id) {
        free(keyForm_inline_message_id);
        keyForm_inline_message_id = NULL;
    }
    if (valueForm_inline_message_id) {
        free(valueForm_inline_message_id);
        valueForm_inline_message_id = NULL;
    }
    free(keyPairForm_inline_message_id);
    if (keyForm_reply_markup) {
        free(keyForm_reply_markup);
        keyForm_reply_markup = NULL;
    }
    free(keyPairForm_reply_markup);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// editMessageText
//
// Use this method to edit text and [game](https://core.telegram.org/bots/api/#games) messages. On success, if the edited message is not an inline message, the edited [Message](https://core.telegram.org/bots/api/#message) is returned, otherwise *True* is returned. Note that business messages that were not sent by the bot and do not contain an inline keyboard can only be edited within **48 hours** from the time they were sent.
//
post_edit_message_text_200_response_t*
DefaultAPI_postEditMessageText(apiClient_t *apiClient, char *text, char *business_connection_id, post_edit_message_text_request_chat_id_t *chat_id, int *message_id, char *inline_message_id, char *parse_mode, list_t *entities, link_preview_options_t *link_preview_options, inline_keyboard_markup_t *reply_markup)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/editMessageText");





    // form parameters
    char *keyForm_business_connection_id = NULL;
    char * valueForm_business_connection_id = 0;
    keyValuePair_t *keyPairForm_business_connection_id = 0;
    if (business_connection_id != NULL)
    {
        keyForm_business_connection_id = strdup("business_connection_id");
        valueForm_business_connection_id = strdup((business_connection_id));
        keyPairForm_business_connection_id = keyValuePair_create(keyForm_business_connection_id,valueForm_business_connection_id);
        list_addElement(localVarFormParameters,keyPairForm_business_connection_id);
    }

    // form parameters
    char *keyForm_chat_id = NULL;
    post_edit_message_text_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_message_id = NULL;
    int valueForm_message_id = 0;
    keyValuePair_t *keyPairForm_message_id = 0;
    if (message_id != NULL)
    {
        keyForm_message_id = strdup("message_id");
        valueForm_message_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_message_id, MAX_NUMBER_LENGTH, "%d", *message_id);
        keyPairForm_message_id = keyValuePair_create(keyForm_message_id,&valueForm_message_id);
        list_addElement(localVarFormParameters,keyPairForm_message_id);
    }

    // form parameters
    char *keyForm_inline_message_id = NULL;
    char * valueForm_inline_message_id = 0;
    keyValuePair_t *keyPairForm_inline_message_id = 0;
    if (inline_message_id != NULL)
    {
        keyForm_inline_message_id = strdup("inline_message_id");
        valueForm_inline_message_id = strdup((inline_message_id));
        keyPairForm_inline_message_id = keyValuePair_create(keyForm_inline_message_id,valueForm_inline_message_id);
        list_addElement(localVarFormParameters,keyPairForm_inline_message_id);
    }

    // form parameters
    char *keyForm_text = NULL;
    char * valueForm_text = 0;
    keyValuePair_t *keyPairForm_text = 0;
    if (text != NULL)
    {
        keyForm_text = strdup("text");
        valueForm_text = strdup((text));
        keyPairForm_text = keyValuePair_create(keyForm_text,valueForm_text);
        list_addElement(localVarFormParameters,keyPairForm_text);
    }

    // form parameters
    char *keyForm_parse_mode = NULL;
    char * valueForm_parse_mode = 0;
    keyValuePair_t *keyPairForm_parse_mode = 0;
    if (parse_mode != NULL)
    {
        keyForm_parse_mode = strdup("parse_mode");
        valueForm_parse_mode = strdup((parse_mode));
        keyPairForm_parse_mode = keyValuePair_create(keyForm_parse_mode,valueForm_parse_mode);
        list_addElement(localVarFormParameters,keyPairForm_parse_mode);
    }

    // form parameters
    char *keyForm_entities = NULL;
     valueForm_entities = 0;
    keyValuePair_t *keyPairForm_entities = 0;
    if (entities != NULL)
    {
        keyForm_entities = strdup("entities");
        valueForm_entities = (entities);
        keyPairForm_entities = keyValuePair_create(keyForm_entities,&valueForm_entities);
        list_addElement(localVarFormParameters,keyPairForm_entities);
    }

    // form parameters
    char *keyForm_link_preview_options = NULL;
    link_preview_options_t * valueForm_link_preview_options = 0;
    keyValuePair_t *keyPairForm_link_preview_options = 0;
    if (link_preview_options != NULL)
    {
        keyForm_link_preview_options = strdup("link_preview_options");
        valueForm_link_preview_options = (link_preview_options);
        keyPairForm_link_preview_options = keyValuePair_create(keyForm_link_preview_options,&valueForm_link_preview_options);
        list_addElement(localVarFormParameters,keyPairForm_link_preview_options);
    }

    // form parameters
    char *keyForm_reply_markup = NULL;
    inline_keyboard_markup_t * valueForm_reply_markup = 0;
    keyValuePair_t *keyPairForm_reply_markup = 0;
    if (reply_markup != NULL)
    {
        keyForm_reply_markup = strdup("reply_markup");
        valueForm_reply_markup = (reply_markup);
        keyPairForm_reply_markup = keyValuePair_create(keyForm_reply_markup,&valueForm_reply_markup);
        list_addElement(localVarFormParameters,keyPairForm_reply_markup);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_edit_message_text_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_edit_message_text_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_business_connection_id) {
        free(keyForm_business_connection_id);
        keyForm_business_connection_id = NULL;
    }
    if (valueForm_business_connection_id) {
        free(valueForm_business_connection_id);
        valueForm_business_connection_id = NULL;
    }
    free(keyPairForm_business_connection_id);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_message_id) {
        free(keyForm_message_id);
        keyForm_message_id = NULL;
    }
    free(keyPairForm_message_id);
    if (keyForm_inline_message_id) {
        free(keyForm_inline_message_id);
        keyForm_inline_message_id = NULL;
    }
    if (valueForm_inline_message_id) {
        free(valueForm_inline_message_id);
        valueForm_inline_message_id = NULL;
    }
    free(keyPairForm_inline_message_id);
    if (keyForm_text) {
        free(keyForm_text);
        keyForm_text = NULL;
    }
    if (valueForm_text) {
        free(valueForm_text);
        valueForm_text = NULL;
    }
    free(keyPairForm_text);
    if (keyForm_parse_mode) {
        free(keyForm_parse_mode);
        keyForm_parse_mode = NULL;
    }
    if (valueForm_parse_mode) {
        free(valueForm_parse_mode);
        valueForm_parse_mode = NULL;
    }
    free(keyPairForm_parse_mode);
    if (keyForm_entities) {
        free(keyForm_entities);
        keyForm_entities = NULL;
    }
    free(keyPairForm_entities);
    if (keyForm_link_preview_options) {
        free(keyForm_link_preview_options);
        keyForm_link_preview_options = NULL;
    }
    free(keyPairForm_link_preview_options);
    if (keyForm_reply_markup) {
        free(keyForm_reply_markup);
        keyForm_reply_markup = NULL;
    }
    free(keyPairForm_reply_markup);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// editStory
//
// Edits a story previously posted by the bot on behalf of a managed business account. Requires the *can\\_manage\\_stories* business bot right. Returns [Story](https://core.telegram.org/bots/api/#story) on success.
//
post_post_story_200_response_t*
DefaultAPI_postEditStory(apiClient_t *apiClient, char *business_connection_id, int *story_id, input_story_content_t *content, char *caption, char *parse_mode, list_t *caption_entities, list_t *areas)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/editStory");





    // form parameters
    char *keyForm_business_connection_id = NULL;
    char * valueForm_business_connection_id = 0;
    keyValuePair_t *keyPairForm_business_connection_id = 0;
    if (business_connection_id != NULL)
    {
        keyForm_business_connection_id = strdup("business_connection_id");
        valueForm_business_connection_id = strdup((business_connection_id));
        keyPairForm_business_connection_id = keyValuePair_create(keyForm_business_connection_id,valueForm_business_connection_id);
        list_addElement(localVarFormParameters,keyPairForm_business_connection_id);
    }

    // form parameters
    char *keyForm_story_id = NULL;
    int valueForm_story_id = 0;
    keyValuePair_t *keyPairForm_story_id = 0;
    if (story_id != NULL)
    {
        keyForm_story_id = strdup("story_id");
        valueForm_story_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_story_id, MAX_NUMBER_LENGTH, "%d", *story_id);
        keyPairForm_story_id = keyValuePair_create(keyForm_story_id,&valueForm_story_id);
        list_addElement(localVarFormParameters,keyPairForm_story_id);
    }

    // form parameters
    char *keyForm_content = NULL;
    input_story_content_t * valueForm_content = 0;
    keyValuePair_t *keyPairForm_content = 0;
    if (content != NULL)
    {
        keyForm_content = strdup("content");
        valueForm_content = (content);
        keyPairForm_content = keyValuePair_create(keyForm_content,&valueForm_content);
        list_addElement(localVarFormParameters,keyPairForm_content);
    }

    // form parameters
    char *keyForm_caption = NULL;
    char * valueForm_caption = 0;
    keyValuePair_t *keyPairForm_caption = 0;
    if (caption != NULL)
    {
        keyForm_caption = strdup("caption");
        valueForm_caption = strdup((caption));
        keyPairForm_caption = keyValuePair_create(keyForm_caption,valueForm_caption);
        list_addElement(localVarFormParameters,keyPairForm_caption);
    }

    // form parameters
    char *keyForm_parse_mode = NULL;
    char * valueForm_parse_mode = 0;
    keyValuePair_t *keyPairForm_parse_mode = 0;
    if (parse_mode != NULL)
    {
        keyForm_parse_mode = strdup("parse_mode");
        valueForm_parse_mode = strdup((parse_mode));
        keyPairForm_parse_mode = keyValuePair_create(keyForm_parse_mode,valueForm_parse_mode);
        list_addElement(localVarFormParameters,keyPairForm_parse_mode);
    }

    // form parameters
    char *keyForm_caption_entities = NULL;
     valueForm_caption_entities = 0;
    keyValuePair_t *keyPairForm_caption_entities = 0;
    if (caption_entities != NULL)
    {
        keyForm_caption_entities = strdup("caption_entities");
        valueForm_caption_entities = (caption_entities);
        keyPairForm_caption_entities = keyValuePair_create(keyForm_caption_entities,&valueForm_caption_entities);
        list_addElement(localVarFormParameters,keyPairForm_caption_entities);
    }

    // form parameters
    char *keyForm_areas = NULL;
     valueForm_areas = 0;
    keyValuePair_t *keyPairForm_areas = 0;
    if (areas != NULL)
    {
        keyForm_areas = strdup("areas");
        valueForm_areas = (areas);
        keyPairForm_areas = keyValuePair_create(keyForm_areas,&valueForm_areas);
        list_addElement(localVarFormParameters,keyPairForm_areas);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_post_story_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_post_story_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_business_connection_id) {
        free(keyForm_business_connection_id);
        keyForm_business_connection_id = NULL;
    }
    if (valueForm_business_connection_id) {
        free(valueForm_business_connection_id);
        valueForm_business_connection_id = NULL;
    }
    free(keyPairForm_business_connection_id);
    if (keyForm_story_id) {
        free(keyForm_story_id);
        keyForm_story_id = NULL;
    }
    free(keyPairForm_story_id);
    if (keyForm_content) {
        free(keyForm_content);
        keyForm_content = NULL;
    }
    free(keyPairForm_content);
    if (keyForm_caption) {
        free(keyForm_caption);
        keyForm_caption = NULL;
    }
    if (valueForm_caption) {
        free(valueForm_caption);
        valueForm_caption = NULL;
    }
    free(keyPairForm_caption);
    if (keyForm_parse_mode) {
        free(keyForm_parse_mode);
        keyForm_parse_mode = NULL;
    }
    if (valueForm_parse_mode) {
        free(valueForm_parse_mode);
        valueForm_parse_mode = NULL;
    }
    free(keyPairForm_parse_mode);
    if (keyForm_caption_entities) {
        free(keyForm_caption_entities);
        keyForm_caption_entities = NULL;
    }
    free(keyPairForm_caption_entities);
    if (keyForm_areas) {
        free(keyForm_areas);
        keyForm_areas = NULL;
    }
    free(keyPairForm_areas);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// editUserStarSubscription
//
// Allows the bot to cancel or re-enable extension of a subscription paid in Telegram Stars. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postEditUserStarSubscription(apiClient_t *apiClient, int *user_id, char *telegram_payment_charge_id, int *is_canceled)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/editUserStarSubscription");





    // form parameters
    char *keyForm_user_id = NULL;
    int valueForm_user_id = 0;
    keyValuePair_t *keyPairForm_user_id = 0;
    if (user_id != NULL)
    {
        keyForm_user_id = strdup("user_id");
        valueForm_user_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_user_id, MAX_NUMBER_LENGTH, "%d", *user_id);
        keyPairForm_user_id = keyValuePair_create(keyForm_user_id,&valueForm_user_id);
        list_addElement(localVarFormParameters,keyPairForm_user_id);
    }

    // form parameters
    char *keyForm_telegram_payment_charge_id = NULL;
    char * valueForm_telegram_payment_charge_id = 0;
    keyValuePair_t *keyPairForm_telegram_payment_charge_id = 0;
    if (telegram_payment_charge_id != NULL)
    {
        keyForm_telegram_payment_charge_id = strdup("telegram_payment_charge_id");
        valueForm_telegram_payment_charge_id = strdup((telegram_payment_charge_id));
        keyPairForm_telegram_payment_charge_id = keyValuePair_create(keyForm_telegram_payment_charge_id,valueForm_telegram_payment_charge_id);
        list_addElement(localVarFormParameters,keyPairForm_telegram_payment_charge_id);
    }

    // form parameters
    char *keyForm_is_canceled = NULL;
    char * valueForm_is_canceled = 0;
    keyValuePair_t *keyPairForm_is_canceled = 0;
    if (is_canceled != NULL)
    {
        keyForm_is_canceled = strdup("is_canceled");
        valueForm_is_canceled = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_is_canceled, MAX_NUMBER_LENGTH, "%d", *is_canceled);
        keyPairForm_is_canceled = keyValuePair_create(keyForm_is_canceled,valueForm_is_canceled);
        list_addElement(localVarFormParameters,keyPairForm_is_canceled);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_user_id) {
        free(keyForm_user_id);
        keyForm_user_id = NULL;
    }
    free(keyPairForm_user_id);
    if (keyForm_telegram_payment_charge_id) {
        free(keyForm_telegram_payment_charge_id);
        keyForm_telegram_payment_charge_id = NULL;
    }
    if (valueForm_telegram_payment_charge_id) {
        free(valueForm_telegram_payment_charge_id);
        valueForm_telegram_payment_charge_id = NULL;
    }
    free(keyPairForm_telegram_payment_charge_id);
    if (keyForm_is_canceled) {
        free(keyForm_is_canceled);
        keyForm_is_canceled = NULL;
    }
    free(keyPairForm_is_canceled);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// exportChatInviteLink
//
// Use this method to generate a new primary invite link for a chat; any previously generated primary link is revoked. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Returns the new invite link as *String* on success.
//
post_export_chat_invite_link_200_response_t*
DefaultAPI_postExportChatInviteLink(apiClient_t *apiClient, post_send_message_request_chat_id_t *chat_id)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/exportChatInviteLink");





    // form parameters
    char *keyForm_chat_id = NULL;
    post_send_message_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_export_chat_invite_link_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_export_chat_invite_link_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// forwardMessage
//
// Use this method to forward messages of any kind. Service messages and messages with protected content can't be forwarded. On success, the sent [Message](https://core.telegram.org/bots/api/#message) is returned.
//
post_send_message_200_response_t*
DefaultAPI_postForwardMessage(apiClient_t *apiClient, post_send_message_request_chat_id_t *chat_id, post_forward_message_request_from_chat_id_t *from_chat_id, int *message_id, int *message_thread_id, int *video_start_timestamp, int *disable_notification, int *protect_content)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/forwardMessage");





    // form parameters
    char *keyForm_chat_id = NULL;
    post_send_message_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_message_thread_id = NULL;
    int valueForm_message_thread_id = 0;
    keyValuePair_t *keyPairForm_message_thread_id = 0;
    if (message_thread_id != NULL)
    {
        keyForm_message_thread_id = strdup("message_thread_id");
        valueForm_message_thread_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_message_thread_id, MAX_NUMBER_LENGTH, "%d", *message_thread_id);
        keyPairForm_message_thread_id = keyValuePair_create(keyForm_message_thread_id,&valueForm_message_thread_id);
        list_addElement(localVarFormParameters,keyPairForm_message_thread_id);
    }

    // form parameters
    char *keyForm_from_chat_id = NULL;
    post_forward_message_request_from_chat_id_t * valueForm_from_chat_id = 0;
    keyValuePair_t *keyPairForm_from_chat_id = 0;
    if (from_chat_id != NULL)
    {
        keyForm_from_chat_id = strdup("from_chat_id");
        valueForm_from_chat_id = (from_chat_id);
        keyPairForm_from_chat_id = keyValuePair_create(keyForm_from_chat_id,&valueForm_from_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_from_chat_id);
    }

    // form parameters
    char *keyForm_video_start_timestamp = NULL;
    int valueForm_video_start_timestamp = 0;
    keyValuePair_t *keyPairForm_video_start_timestamp = 0;
    if (video_start_timestamp != NULL)
    {
        keyForm_video_start_timestamp = strdup("video_start_timestamp");
        valueForm_video_start_timestamp = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_video_start_timestamp, MAX_NUMBER_LENGTH, "%d", *video_start_timestamp);
        keyPairForm_video_start_timestamp = keyValuePair_create(keyForm_video_start_timestamp,&valueForm_video_start_timestamp);
        list_addElement(localVarFormParameters,keyPairForm_video_start_timestamp);
    }

    // form parameters
    char *keyForm_disable_notification = NULL;
    char * valueForm_disable_notification = 0;
    keyValuePair_t *keyPairForm_disable_notification = 0;
    if (disable_notification != NULL)
    {
        keyForm_disable_notification = strdup("disable_notification");
        valueForm_disable_notification = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_disable_notification, MAX_NUMBER_LENGTH, "%d", *disable_notification);
        keyPairForm_disable_notification = keyValuePair_create(keyForm_disable_notification,valueForm_disable_notification);
        list_addElement(localVarFormParameters,keyPairForm_disable_notification);
    }

    // form parameters
    char *keyForm_protect_content = NULL;
    char * valueForm_protect_content = 0;
    keyValuePair_t *keyPairForm_protect_content = 0;
    if (protect_content != NULL)
    {
        keyForm_protect_content = strdup("protect_content");
        valueForm_protect_content = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_protect_content, MAX_NUMBER_LENGTH, "%d", *protect_content);
        keyPairForm_protect_content = keyValuePair_create(keyForm_protect_content,valueForm_protect_content);
        list_addElement(localVarFormParameters,keyPairForm_protect_content);
    }

    // form parameters
    char *keyForm_message_id = NULL;
    int valueForm_message_id = 0;
    keyValuePair_t *keyPairForm_message_id = 0;
    if (message_id != NULL)
    {
        keyForm_message_id = strdup("message_id");
        valueForm_message_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_message_id, MAX_NUMBER_LENGTH, "%d", *message_id);
        keyPairForm_message_id = keyValuePair_create(keyForm_message_id,&valueForm_message_id);
        list_addElement(localVarFormParameters,keyPairForm_message_id);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_send_message_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_send_message_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_message_thread_id) {
        free(keyForm_message_thread_id);
        keyForm_message_thread_id = NULL;
    }
    free(keyPairForm_message_thread_id);
    if (keyForm_from_chat_id) {
        free(keyForm_from_chat_id);
        keyForm_from_chat_id = NULL;
    }
    free(keyPairForm_from_chat_id);
    if (keyForm_video_start_timestamp) {
        free(keyForm_video_start_timestamp);
        keyForm_video_start_timestamp = NULL;
    }
    free(keyPairForm_video_start_timestamp);
    if (keyForm_disable_notification) {
        free(keyForm_disable_notification);
        keyForm_disable_notification = NULL;
    }
    free(keyPairForm_disable_notification);
    if (keyForm_protect_content) {
        free(keyForm_protect_content);
        keyForm_protect_content = NULL;
    }
    free(keyPairForm_protect_content);
    if (keyForm_message_id) {
        free(keyForm_message_id);
        keyForm_message_id = NULL;
    }
    free(keyPairForm_message_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// forwardMessages
//
// Use this method to forward multiple messages of any kind. If some of the specified messages can't be found or forwarded, they are skipped. Service messages and messages with protected content can't be forwarded. Album grouping is kept for forwarded messages. On success, an array of [MessageId](https://core.telegram.org/bots/api/#messageid) of the sent messages is returned.
//
post_forward_messages_200_response_t*
DefaultAPI_postForwardMessages(apiClient_t *apiClient, post_send_message_request_chat_id_t *chat_id, post_forward_messages_request_from_chat_id_t *from_chat_id, list_t *message_ids, int *message_thread_id, int *disable_notification, int *protect_content)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/forwardMessages");





    // form parameters
    char *keyForm_chat_id = NULL;
    post_send_message_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_message_thread_id = NULL;
    int valueForm_message_thread_id = 0;
    keyValuePair_t *keyPairForm_message_thread_id = 0;
    if (message_thread_id != NULL)
    {
        keyForm_message_thread_id = strdup("message_thread_id");
        valueForm_message_thread_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_message_thread_id, MAX_NUMBER_LENGTH, "%d", *message_thread_id);
        keyPairForm_message_thread_id = keyValuePair_create(keyForm_message_thread_id,&valueForm_message_thread_id);
        list_addElement(localVarFormParameters,keyPairForm_message_thread_id);
    }

    // form parameters
    char *keyForm_from_chat_id = NULL;
    post_forward_messages_request_from_chat_id_t * valueForm_from_chat_id = 0;
    keyValuePair_t *keyPairForm_from_chat_id = 0;
    if (from_chat_id != NULL)
    {
        keyForm_from_chat_id = strdup("from_chat_id");
        valueForm_from_chat_id = (from_chat_id);
        keyPairForm_from_chat_id = keyValuePair_create(keyForm_from_chat_id,&valueForm_from_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_from_chat_id);
    }

    // form parameters
    char *keyForm_message_ids = NULL;
     valueForm_message_ids = 0;
    keyValuePair_t *keyPairForm_message_ids = 0;
    if (message_ids != NULL)
    {
        keyForm_message_ids = strdup("message_ids");
        valueForm_message_ids = (message_ids);
        keyPairForm_message_ids = keyValuePair_create(keyForm_message_ids,&valueForm_message_ids);
        list_addElement(localVarFormParameters,keyPairForm_message_ids);
    }

    // form parameters
    char *keyForm_disable_notification = NULL;
    char * valueForm_disable_notification = 0;
    keyValuePair_t *keyPairForm_disable_notification = 0;
    if (disable_notification != NULL)
    {
        keyForm_disable_notification = strdup("disable_notification");
        valueForm_disable_notification = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_disable_notification, MAX_NUMBER_LENGTH, "%d", *disable_notification);
        keyPairForm_disable_notification = keyValuePair_create(keyForm_disable_notification,valueForm_disable_notification);
        list_addElement(localVarFormParameters,keyPairForm_disable_notification);
    }

    // form parameters
    char *keyForm_protect_content = NULL;
    char * valueForm_protect_content = 0;
    keyValuePair_t *keyPairForm_protect_content = 0;
    if (protect_content != NULL)
    {
        keyForm_protect_content = strdup("protect_content");
        valueForm_protect_content = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_protect_content, MAX_NUMBER_LENGTH, "%d", *protect_content);
        keyPairForm_protect_content = keyValuePair_create(keyForm_protect_content,valueForm_protect_content);
        list_addElement(localVarFormParameters,keyPairForm_protect_content);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_forward_messages_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_forward_messages_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_message_thread_id) {
        free(keyForm_message_thread_id);
        keyForm_message_thread_id = NULL;
    }
    free(keyPairForm_message_thread_id);
    if (keyForm_from_chat_id) {
        free(keyForm_from_chat_id);
        keyForm_from_chat_id = NULL;
    }
    free(keyPairForm_from_chat_id);
    if (keyForm_message_ids) {
        free(keyForm_message_ids);
        keyForm_message_ids = NULL;
    }
    free(keyPairForm_message_ids);
    if (keyForm_disable_notification) {
        free(keyForm_disable_notification);
        keyForm_disable_notification = NULL;
    }
    free(keyPairForm_disable_notification);
    if (keyForm_protect_content) {
        free(keyForm_protect_content);
        keyForm_protect_content = NULL;
    }
    free(keyPairForm_protect_content);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// getAvailableGifts
//
// Returns the list of gifts that can be sent by the bot to users and channel chats. Requires no parameters. Returns a [Gifts](https://core.telegram.org/bots/api/#gifts) object.
//
post_get_available_gifts_200_response_t*
DefaultAPI_postGetAvailableGifts(apiClient_t *apiClient)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/getAvailableGifts");




    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_get_available_gifts_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_get_available_gifts_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// getBusinessAccountGifts
//
// Returns the gifts received and owned by a managed business account. Requires the *can\\_view\\_gifts\\_and\\_stars* business bot right. Returns [OwnedGifts](https://core.telegram.org/bots/api/#ownedgifts) on success.
//
post_get_business_account_gifts_200_response_t*
DefaultAPI_postGetBusinessAccountGifts(apiClient_t *apiClient, char *business_connection_id, int *exclude_unsaved, int *exclude_saved, int *exclude_unlimited, int *exclude_limited, int *exclude_unique, int *sort_by_price, char *offset, int *limit)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/getBusinessAccountGifts");





    // form parameters
    char *keyForm_business_connection_id = NULL;
    char * valueForm_business_connection_id = 0;
    keyValuePair_t *keyPairForm_business_connection_id = 0;
    if (business_connection_id != NULL)
    {
        keyForm_business_connection_id = strdup("business_connection_id");
        valueForm_business_connection_id = strdup((business_connection_id));
        keyPairForm_business_connection_id = keyValuePair_create(keyForm_business_connection_id,valueForm_business_connection_id);
        list_addElement(localVarFormParameters,keyPairForm_business_connection_id);
    }

    // form parameters
    char *keyForm_exclude_unsaved = NULL;
    char * valueForm_exclude_unsaved = 0;
    keyValuePair_t *keyPairForm_exclude_unsaved = 0;
    if (exclude_unsaved != NULL)
    {
        keyForm_exclude_unsaved = strdup("exclude_unsaved");
        valueForm_exclude_unsaved = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_exclude_unsaved, MAX_NUMBER_LENGTH, "%d", *exclude_unsaved);
        keyPairForm_exclude_unsaved = keyValuePair_create(keyForm_exclude_unsaved,valueForm_exclude_unsaved);
        list_addElement(localVarFormParameters,keyPairForm_exclude_unsaved);
    }

    // form parameters
    char *keyForm_exclude_saved = NULL;
    char * valueForm_exclude_saved = 0;
    keyValuePair_t *keyPairForm_exclude_saved = 0;
    if (exclude_saved != NULL)
    {
        keyForm_exclude_saved = strdup("exclude_saved");
        valueForm_exclude_saved = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_exclude_saved, MAX_NUMBER_LENGTH, "%d", *exclude_saved);
        keyPairForm_exclude_saved = keyValuePair_create(keyForm_exclude_saved,valueForm_exclude_saved);
        list_addElement(localVarFormParameters,keyPairForm_exclude_saved);
    }

    // form parameters
    char *keyForm_exclude_unlimited = NULL;
    char * valueForm_exclude_unlimited = 0;
    keyValuePair_t *keyPairForm_exclude_unlimited = 0;
    if (exclude_unlimited != NULL)
    {
        keyForm_exclude_unlimited = strdup("exclude_unlimited");
        valueForm_exclude_unlimited = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_exclude_unlimited, MAX_NUMBER_LENGTH, "%d", *exclude_unlimited);
        keyPairForm_exclude_unlimited = keyValuePair_create(keyForm_exclude_unlimited,valueForm_exclude_unlimited);
        list_addElement(localVarFormParameters,keyPairForm_exclude_unlimited);
    }

    // form parameters
    char *keyForm_exclude_limited = NULL;
    char * valueForm_exclude_limited = 0;
    keyValuePair_t *keyPairForm_exclude_limited = 0;
    if (exclude_limited != NULL)
    {
        keyForm_exclude_limited = strdup("exclude_limited");
        valueForm_exclude_limited = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_exclude_limited, MAX_NUMBER_LENGTH, "%d", *exclude_limited);
        keyPairForm_exclude_limited = keyValuePair_create(keyForm_exclude_limited,valueForm_exclude_limited);
        list_addElement(localVarFormParameters,keyPairForm_exclude_limited);
    }

    // form parameters
    char *keyForm_exclude_unique = NULL;
    char * valueForm_exclude_unique = 0;
    keyValuePair_t *keyPairForm_exclude_unique = 0;
    if (exclude_unique != NULL)
    {
        keyForm_exclude_unique = strdup("exclude_unique");
        valueForm_exclude_unique = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_exclude_unique, MAX_NUMBER_LENGTH, "%d", *exclude_unique);
        keyPairForm_exclude_unique = keyValuePair_create(keyForm_exclude_unique,valueForm_exclude_unique);
        list_addElement(localVarFormParameters,keyPairForm_exclude_unique);
    }

    // form parameters
    char *keyForm_sort_by_price = NULL;
    char * valueForm_sort_by_price = 0;
    keyValuePair_t *keyPairForm_sort_by_price = 0;
    if (sort_by_price != NULL)
    {
        keyForm_sort_by_price = strdup("sort_by_price");
        valueForm_sort_by_price = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_sort_by_price, MAX_NUMBER_LENGTH, "%d", *sort_by_price);
        keyPairForm_sort_by_price = keyValuePair_create(keyForm_sort_by_price,valueForm_sort_by_price);
        list_addElement(localVarFormParameters,keyPairForm_sort_by_price);
    }

    // form parameters
    char *keyForm_offset = NULL;
    char * valueForm_offset = 0;
    keyValuePair_t *keyPairForm_offset = 0;
    if (offset != NULL)
    {
        keyForm_offset = strdup("offset");
        valueForm_offset = strdup((offset));
        keyPairForm_offset = keyValuePair_create(keyForm_offset,valueForm_offset);
        list_addElement(localVarFormParameters,keyPairForm_offset);
    }

    // form parameters
    char *keyForm_limit = NULL;
    int valueForm_limit = 0;
    keyValuePair_t *keyPairForm_limit = 0;
    if (limit != NULL)
    {
        keyForm_limit = strdup("limit");
        valueForm_limit = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_limit, MAX_NUMBER_LENGTH, "%d", *limit);
        keyPairForm_limit = keyValuePair_create(keyForm_limit,&valueForm_limit);
        list_addElement(localVarFormParameters,keyPairForm_limit);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_get_business_account_gifts_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_get_business_account_gifts_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_business_connection_id) {
        free(keyForm_business_connection_id);
        keyForm_business_connection_id = NULL;
    }
    if (valueForm_business_connection_id) {
        free(valueForm_business_connection_id);
        valueForm_business_connection_id = NULL;
    }
    free(keyPairForm_business_connection_id);
    if (keyForm_exclude_unsaved) {
        free(keyForm_exclude_unsaved);
        keyForm_exclude_unsaved = NULL;
    }
    free(keyPairForm_exclude_unsaved);
    if (keyForm_exclude_saved) {
        free(keyForm_exclude_saved);
        keyForm_exclude_saved = NULL;
    }
    free(keyPairForm_exclude_saved);
    if (keyForm_exclude_unlimited) {
        free(keyForm_exclude_unlimited);
        keyForm_exclude_unlimited = NULL;
    }
    free(keyPairForm_exclude_unlimited);
    if (keyForm_exclude_limited) {
        free(keyForm_exclude_limited);
        keyForm_exclude_limited = NULL;
    }
    free(keyPairForm_exclude_limited);
    if (keyForm_exclude_unique) {
        free(keyForm_exclude_unique);
        keyForm_exclude_unique = NULL;
    }
    free(keyPairForm_exclude_unique);
    if (keyForm_sort_by_price) {
        free(keyForm_sort_by_price);
        keyForm_sort_by_price = NULL;
    }
    free(keyPairForm_sort_by_price);
    if (keyForm_offset) {
        free(keyForm_offset);
        keyForm_offset = NULL;
    }
    if (valueForm_offset) {
        free(valueForm_offset);
        valueForm_offset = NULL;
    }
    free(keyPairForm_offset);
    if (keyForm_limit) {
        free(keyForm_limit);
        keyForm_limit = NULL;
    }
    free(keyPairForm_limit);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// getBusinessAccountStarBalance
//
// Returns the amount of Telegram Stars owned by a managed business account. Requires the *can\\_view\\_gifts\\_and\\_stars* business bot right. Returns [StarAmount](https://core.telegram.org/bots/api/#staramount) on success.
//
post_get_business_account_star_balance_200_response_t*
DefaultAPI_postGetBusinessAccountStarBalance(apiClient_t *apiClient, char *business_connection_id)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/getBusinessAccountStarBalance");





    // form parameters
    char *keyForm_business_connection_id = NULL;
    char * valueForm_business_connection_id = 0;
    keyValuePair_t *keyPairForm_business_connection_id = 0;
    if (business_connection_id != NULL)
    {
        keyForm_business_connection_id = strdup("business_connection_id");
        valueForm_business_connection_id = strdup((business_connection_id));
        keyPairForm_business_connection_id = keyValuePair_create(keyForm_business_connection_id,valueForm_business_connection_id);
        list_addElement(localVarFormParameters,keyPairForm_business_connection_id);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_get_business_account_star_balance_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_get_business_account_star_balance_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_business_connection_id) {
        free(keyForm_business_connection_id);
        keyForm_business_connection_id = NULL;
    }
    if (valueForm_business_connection_id) {
        free(valueForm_business_connection_id);
        valueForm_business_connection_id = NULL;
    }
    free(keyPairForm_business_connection_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// getBusinessConnection
//
// Use this method to get information about the connection of the bot with a business account. Returns a [BusinessConnection](https://core.telegram.org/bots/api/#businessconnection) object on success.
//
post_get_business_connection_200_response_t*
DefaultAPI_postGetBusinessConnection(apiClient_t *apiClient, char *business_connection_id)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/getBusinessConnection");





    // form parameters
    char *keyForm_business_connection_id = NULL;
    char * valueForm_business_connection_id = 0;
    keyValuePair_t *keyPairForm_business_connection_id = 0;
    if (business_connection_id != NULL)
    {
        keyForm_business_connection_id = strdup("business_connection_id");
        valueForm_business_connection_id = strdup((business_connection_id));
        keyPairForm_business_connection_id = keyValuePair_create(keyForm_business_connection_id,valueForm_business_connection_id);
        list_addElement(localVarFormParameters,keyPairForm_business_connection_id);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_get_business_connection_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_get_business_connection_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_business_connection_id) {
        free(keyForm_business_connection_id);
        keyForm_business_connection_id = NULL;
    }
    if (valueForm_business_connection_id) {
        free(valueForm_business_connection_id);
        valueForm_business_connection_id = NULL;
    }
    free(keyPairForm_business_connection_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// getChat
//
// Use this method to get up-to-date information about the chat. Returns a [ChatFullInfo](https://core.telegram.org/bots/api/#chatfullinfo) object on success.
//
post_get_chat_200_response_t*
DefaultAPI_postGetChat(apiClient_t *apiClient, post_leave_chat_request_chat_id_t *chat_id)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/getChat");





    // form parameters
    char *keyForm_chat_id = NULL;
    post_leave_chat_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_get_chat_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_get_chat_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// getChatAdministrators
//
// Use this method to get a list of administrators in a chat, which aren't bots. Returns an Array of [ChatMember](https://core.telegram.org/bots/api/#chatmember) objects.
//
post_get_chat_administrators_200_response_t*
DefaultAPI_postGetChatAdministrators(apiClient_t *apiClient, post_leave_chat_request_chat_id_t *chat_id)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/getChatAdministrators");





    // form parameters
    char *keyForm_chat_id = NULL;
    post_leave_chat_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_get_chat_administrators_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_get_chat_administrators_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// getChatMember
//
// Use this method to get information about a member of a chat. The method is only guaranteed to work for other users if the bot is an administrator in the chat. Returns a [ChatMember](https://core.telegram.org/bots/api/#chatmember) object on success.
//
post_get_chat_member_200_response_t*
DefaultAPI_postGetChatMember(apiClient_t *apiClient, post_leave_chat_request_chat_id_t *chat_id, int *user_id)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/getChatMember");





    // form parameters
    char *keyForm_chat_id = NULL;
    post_leave_chat_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_user_id = NULL;
    int valueForm_user_id = 0;
    keyValuePair_t *keyPairForm_user_id = 0;
    if (user_id != NULL)
    {
        keyForm_user_id = strdup("user_id");
        valueForm_user_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_user_id, MAX_NUMBER_LENGTH, "%d", *user_id);
        keyPairForm_user_id = keyValuePair_create(keyForm_user_id,&valueForm_user_id);
        list_addElement(localVarFormParameters,keyPairForm_user_id);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_get_chat_member_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_get_chat_member_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_user_id) {
        free(keyForm_user_id);
        keyForm_user_id = NULL;
    }
    free(keyPairForm_user_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// getChatMemberCount
//
// Use this method to get the number of members in a chat. Returns *Int* on success.
//
post_get_chat_member_count_200_response_t*
DefaultAPI_postGetChatMemberCount(apiClient_t *apiClient, post_leave_chat_request_chat_id_t *chat_id)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/getChatMemberCount");





    // form parameters
    char *keyForm_chat_id = NULL;
    post_leave_chat_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_get_chat_member_count_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_get_chat_member_count_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// getChatMenuButton
//
// Use this method to get the current value of the bot's menu button in a private chat, or the default menu button. Returns [MenuButton](https://core.telegram.org/bots/api/#menubutton) on success.
//
post_get_chat_menu_button_200_response_t*
DefaultAPI_postGetChatMenuButton(apiClient_t *apiClient, int *chat_id)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/getChatMenuButton");





    // form parameters
    char *keyForm_chat_id = NULL;
    int valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_chat_id, MAX_NUMBER_LENGTH, "%d", *chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_get_chat_menu_button_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_get_chat_menu_button_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// getCustomEmojiStickers
//
// Use this method to get information about custom emoji stickers by their identifiers. Returns an Array of [Sticker](https://core.telegram.org/bots/api/#sticker) objects.
//
post_get_forum_topic_icon_stickers_200_response_t*
DefaultAPI_postGetCustomEmojiStickers(apiClient_t *apiClient, list_t *custom_emoji_ids)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/getCustomEmojiStickers");





    // form parameters
    char *keyForm_custom_emoji_ids = NULL;
     valueForm_custom_emoji_ids = 0;
    keyValuePair_t *keyPairForm_custom_emoji_ids = 0;
    if (custom_emoji_ids != NULL)
    {
        keyForm_custom_emoji_ids = strdup("custom_emoji_ids");
        valueForm_custom_emoji_ids = (custom_emoji_ids);
        keyPairForm_custom_emoji_ids = keyValuePair_create(keyForm_custom_emoji_ids,&valueForm_custom_emoji_ids);
        list_addElement(localVarFormParameters,keyPairForm_custom_emoji_ids);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_get_forum_topic_icon_stickers_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_get_forum_topic_icon_stickers_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_custom_emoji_ids) {
        free(keyForm_custom_emoji_ids);
        keyForm_custom_emoji_ids = NULL;
    }
    free(keyPairForm_custom_emoji_ids);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// getFile
//
// Use this method to get basic information about a file and prepare it for downloading. For the moment, bots can download files of up to 20MB in size. On success, a [File](https://core.telegram.org/bots/api/#file) object is returned. The file can then be downloaded via the link `https://api.telegram.org/file/bot<token>/<file_path>`, where `<file_path>` is taken from the response. It is guaranteed that the link will be valid for at least 1 hour. When the link expires, a new one can be requested by calling [getFile](https://core.telegram.org/bots/api/#getfile) again.
//
post_get_file_200_response_t*
DefaultAPI_postGetFile(apiClient_t *apiClient, char *file_id)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/getFile");





    // form parameters
    char *keyForm_file_id = NULL;
    char * valueForm_file_id = 0;
    keyValuePair_t *keyPairForm_file_id = 0;
    if (file_id != NULL)
    {
        keyForm_file_id = strdup("file_id");
        valueForm_file_id = strdup((file_id));
        keyPairForm_file_id = keyValuePair_create(keyForm_file_id,valueForm_file_id);
        list_addElement(localVarFormParameters,keyPairForm_file_id);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_get_file_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_get_file_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_file_id) {
        free(keyForm_file_id);
        keyForm_file_id = NULL;
    }
    if (valueForm_file_id) {
        free(valueForm_file_id);
        valueForm_file_id = NULL;
    }
    free(keyPairForm_file_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// getForumTopicIconStickers
//
// Use this method to get custom emoji stickers, which can be used as a forum topic icon by any user. Requires no parameters. Returns an Array of [Sticker](https://core.telegram.org/bots/api/#sticker) objects.
//
post_get_forum_topic_icon_stickers_200_response_t*
DefaultAPI_postGetForumTopicIconStickers(apiClient_t *apiClient)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/getForumTopicIconStickers");




    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_get_forum_topic_icon_stickers_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_get_forum_topic_icon_stickers_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// getGameHighScores
//
// Use this method to get data for high score tables. Will return the score of the specified user and several of their neighbors in a game. Returns an Array of [GameHighScore](https://core.telegram.org/bots/api/#gamehighscore) objects.  This method will currently return scores for the target user, plus two of their closest neighbors on each side. Will also return the top three users if the user and their neighbors are not among them. Please note that this behavior is subject to change.
//
post_get_game_high_scores_200_response_t*
DefaultAPI_postGetGameHighScores(apiClient_t *apiClient, int *user_id, int *chat_id, int *message_id, char *inline_message_id)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/getGameHighScores");





    // form parameters
    char *keyForm_user_id = NULL;
    int valueForm_user_id = 0;
    keyValuePair_t *keyPairForm_user_id = 0;
    if (user_id != NULL)
    {
        keyForm_user_id = strdup("user_id");
        valueForm_user_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_user_id, MAX_NUMBER_LENGTH, "%d", *user_id);
        keyPairForm_user_id = keyValuePair_create(keyForm_user_id,&valueForm_user_id);
        list_addElement(localVarFormParameters,keyPairForm_user_id);
    }

    // form parameters
    char *keyForm_chat_id = NULL;
    int valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_chat_id, MAX_NUMBER_LENGTH, "%d", *chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_message_id = NULL;
    int valueForm_message_id = 0;
    keyValuePair_t *keyPairForm_message_id = 0;
    if (message_id != NULL)
    {
        keyForm_message_id = strdup("message_id");
        valueForm_message_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_message_id, MAX_NUMBER_LENGTH, "%d", *message_id);
        keyPairForm_message_id = keyValuePair_create(keyForm_message_id,&valueForm_message_id);
        list_addElement(localVarFormParameters,keyPairForm_message_id);
    }

    // form parameters
    char *keyForm_inline_message_id = NULL;
    char * valueForm_inline_message_id = 0;
    keyValuePair_t *keyPairForm_inline_message_id = 0;
    if (inline_message_id != NULL)
    {
        keyForm_inline_message_id = strdup("inline_message_id");
        valueForm_inline_message_id = strdup((inline_message_id));
        keyPairForm_inline_message_id = keyValuePair_create(keyForm_inline_message_id,valueForm_inline_message_id);
        list_addElement(localVarFormParameters,keyPairForm_inline_message_id);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_get_game_high_scores_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_get_game_high_scores_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_user_id) {
        free(keyForm_user_id);
        keyForm_user_id = NULL;
    }
    free(keyPairForm_user_id);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_message_id) {
        free(keyForm_message_id);
        keyForm_message_id = NULL;
    }
    free(keyPairForm_message_id);
    if (keyForm_inline_message_id) {
        free(keyForm_inline_message_id);
        keyForm_inline_message_id = NULL;
    }
    if (valueForm_inline_message_id) {
        free(valueForm_inline_message_id);
        valueForm_inline_message_id = NULL;
    }
    free(keyPairForm_inline_message_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// getMe
//
// A simple method for testing your bot's authentication token. Requires no parameters. Returns basic information about the bot in form of a [User](https://core.telegram.org/bots/api/#user) object.
//
post_get_me_200_response_t*
DefaultAPI_postGetMe(apiClient_t *apiClient)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/getMe");




    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_get_me_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_get_me_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// getMyCommands
//
// Use this method to get the current list of the bot's commands for the given scope and user language. Returns an Array of [BotCommand](https://core.telegram.org/bots/api/#botcommand) objects. If commands aren't set, an empty list is returned.
//
post_get_my_commands_200_response_t*
DefaultAPI_postGetMyCommands(apiClient_t *apiClient, bot_command_scope_t *scope, char *language_code)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/getMyCommands");





    // form parameters
    char *keyForm_scope = NULL;
    bot_command_scope_t * valueForm_scope = 0;
    keyValuePair_t *keyPairForm_scope = 0;
    if (scope != NULL)
    {
        keyForm_scope = strdup("scope");
        valueForm_scope = (scope);
        keyPairForm_scope = keyValuePair_create(keyForm_scope,&valueForm_scope);
        list_addElement(localVarFormParameters,keyPairForm_scope);
    }

    // form parameters
    char *keyForm_language_code = NULL;
    char * valueForm_language_code = 0;
    keyValuePair_t *keyPairForm_language_code = 0;
    if (language_code != NULL)
    {
        keyForm_language_code = strdup("language_code");
        valueForm_language_code = strdup((language_code));
        keyPairForm_language_code = keyValuePair_create(keyForm_language_code,valueForm_language_code);
        list_addElement(localVarFormParameters,keyPairForm_language_code);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_get_my_commands_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_get_my_commands_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_scope) {
        free(keyForm_scope);
        keyForm_scope = NULL;
    }
    free(keyPairForm_scope);
    if (keyForm_language_code) {
        free(keyForm_language_code);
        keyForm_language_code = NULL;
    }
    if (valueForm_language_code) {
        free(valueForm_language_code);
        valueForm_language_code = NULL;
    }
    free(keyPairForm_language_code);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// getMyDefaultAdministratorRights
//
// Use this method to get the current default administrator rights of the bot. Returns [ChatAdministratorRights](https://core.telegram.org/bots/api/#chatadministratorrights) on success.
//
post_get_my_default_administrator_rights_200_response_t*
DefaultAPI_postGetMyDefaultAdministratorRights(apiClient_t *apiClient, int *for_channels)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/getMyDefaultAdministratorRights");





    // form parameters
    char *keyForm_for_channels = NULL;
    char * valueForm_for_channels = 0;
    keyValuePair_t *keyPairForm_for_channels = 0;
    if (for_channels != NULL)
    {
        keyForm_for_channels = strdup("for_channels");
        valueForm_for_channels = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_for_channels, MAX_NUMBER_LENGTH, "%d", *for_channels);
        keyPairForm_for_channels = keyValuePair_create(keyForm_for_channels,valueForm_for_channels);
        list_addElement(localVarFormParameters,keyPairForm_for_channels);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_get_my_default_administrator_rights_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_get_my_default_administrator_rights_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_for_channels) {
        free(keyForm_for_channels);
        keyForm_for_channels = NULL;
    }
    free(keyPairForm_for_channels);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// getMyDescription
//
// Use this method to get the current bot description for the given user language. Returns [BotDescription](https://core.telegram.org/bots/api/#botdescription) on success.
//
post_get_my_description_200_response_t*
DefaultAPI_postGetMyDescription(apiClient_t *apiClient, char *language_code)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/getMyDescription");





    // form parameters
    char *keyForm_language_code = NULL;
    char * valueForm_language_code = 0;
    keyValuePair_t *keyPairForm_language_code = 0;
    if (language_code != NULL)
    {
        keyForm_language_code = strdup("language_code");
        valueForm_language_code = strdup((language_code));
        keyPairForm_language_code = keyValuePair_create(keyForm_language_code,valueForm_language_code);
        list_addElement(localVarFormParameters,keyPairForm_language_code);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_get_my_description_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_get_my_description_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_language_code) {
        free(keyForm_language_code);
        keyForm_language_code = NULL;
    }
    if (valueForm_language_code) {
        free(valueForm_language_code);
        valueForm_language_code = NULL;
    }
    free(keyPairForm_language_code);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// getMyName
//
// Use this method to get the current bot name for the given user language. Returns [BotName](https://core.telegram.org/bots/api/#botname) on success.
//
post_get_my_name_200_response_t*
DefaultAPI_postGetMyName(apiClient_t *apiClient, char *language_code)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/getMyName");





    // form parameters
    char *keyForm_language_code = NULL;
    char * valueForm_language_code = 0;
    keyValuePair_t *keyPairForm_language_code = 0;
    if (language_code != NULL)
    {
        keyForm_language_code = strdup("language_code");
        valueForm_language_code = strdup((language_code));
        keyPairForm_language_code = keyValuePair_create(keyForm_language_code,valueForm_language_code);
        list_addElement(localVarFormParameters,keyPairForm_language_code);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_get_my_name_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_get_my_name_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_language_code) {
        free(keyForm_language_code);
        keyForm_language_code = NULL;
    }
    if (valueForm_language_code) {
        free(valueForm_language_code);
        valueForm_language_code = NULL;
    }
    free(keyPairForm_language_code);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// getMyShortDescription
//
// Use this method to get the current bot short description for the given user language. Returns [BotShortDescription](https://core.telegram.org/bots/api/#botshortdescription) on success.
//
post_get_my_short_description_200_response_t*
DefaultAPI_postGetMyShortDescription(apiClient_t *apiClient, char *language_code)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/getMyShortDescription");





    // form parameters
    char *keyForm_language_code = NULL;
    char * valueForm_language_code = 0;
    keyValuePair_t *keyPairForm_language_code = 0;
    if (language_code != NULL)
    {
        keyForm_language_code = strdup("language_code");
        valueForm_language_code = strdup((language_code));
        keyPairForm_language_code = keyValuePair_create(keyForm_language_code,valueForm_language_code);
        list_addElement(localVarFormParameters,keyPairForm_language_code);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_get_my_short_description_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_get_my_short_description_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_language_code) {
        free(keyForm_language_code);
        keyForm_language_code = NULL;
    }
    if (valueForm_language_code) {
        free(valueForm_language_code);
        valueForm_language_code = NULL;
    }
    free(keyPairForm_language_code);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// getStarTransactions
//
// Returns the bot's Telegram Star transactions in chronological order. On success, returns a [StarTransactions](https://core.telegram.org/bots/api/#startransactions) object.
//
post_get_star_transactions_200_response_t*
DefaultAPI_postGetStarTransactions(apiClient_t *apiClient, int *offset, int *limit)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/getStarTransactions");





    // form parameters
    char *keyForm_offset = NULL;
    int valueForm_offset = 0;
    keyValuePair_t *keyPairForm_offset = 0;
    if (offset != NULL)
    {
        keyForm_offset = strdup("offset");
        valueForm_offset = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_offset, MAX_NUMBER_LENGTH, "%d", *offset);
        keyPairForm_offset = keyValuePair_create(keyForm_offset,&valueForm_offset);
        list_addElement(localVarFormParameters,keyPairForm_offset);
    }

    // form parameters
    char *keyForm_limit = NULL;
    int valueForm_limit = 0;
    keyValuePair_t *keyPairForm_limit = 0;
    if (limit != NULL)
    {
        keyForm_limit = strdup("limit");
        valueForm_limit = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_limit, MAX_NUMBER_LENGTH, "%d", *limit);
        keyPairForm_limit = keyValuePair_create(keyForm_limit,&valueForm_limit);
        list_addElement(localVarFormParameters,keyPairForm_limit);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_get_star_transactions_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_get_star_transactions_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_offset) {
        free(keyForm_offset);
        keyForm_offset = NULL;
    }
    free(keyPairForm_offset);
    if (keyForm_limit) {
        free(keyForm_limit);
        keyForm_limit = NULL;
    }
    free(keyPairForm_limit);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// getStickerSet
//
// Use this method to get a sticker set. On success, a [StickerSet](https://core.telegram.org/bots/api/#stickerset) object is returned.
//
post_get_sticker_set_200_response_t*
DefaultAPI_postGetStickerSet(apiClient_t *apiClient, char *name)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/getStickerSet");





    // form parameters
    char *keyForm_name = NULL;
    char * valueForm_name = 0;
    keyValuePair_t *keyPairForm_name = 0;
    if (name != NULL)
    {
        keyForm_name = strdup("name");
        valueForm_name = strdup((name));
        keyPairForm_name = keyValuePair_create(keyForm_name,valueForm_name);
        list_addElement(localVarFormParameters,keyPairForm_name);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_get_sticker_set_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_get_sticker_set_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_name) {
        free(keyForm_name);
        keyForm_name = NULL;
    }
    if (valueForm_name) {
        free(valueForm_name);
        valueForm_name = NULL;
    }
    free(keyPairForm_name);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// getUpdates
//
// Use this method to receive incoming updates using long polling ([wiki](https://en.wikipedia.org/wiki/Push_technology#Long_polling)). Returns an Array of [Update](https://core.telegram.org/bots/api/#update) objects.
//
post_get_updates_200_response_t*
DefaultAPI_postGetUpdates(apiClient_t *apiClient, int *offset, int *limit, int *timeout, list_t *allowed_updates)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/getUpdates");





    // form parameters
    char *keyForm_offset = NULL;
    int valueForm_offset = 0;
    keyValuePair_t *keyPairForm_offset = 0;
    if (offset != NULL)
    {
        keyForm_offset = strdup("offset");
        valueForm_offset = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_offset, MAX_NUMBER_LENGTH, "%d", *offset);
        keyPairForm_offset = keyValuePair_create(keyForm_offset,&valueForm_offset);
        list_addElement(localVarFormParameters,keyPairForm_offset);
    }

    // form parameters
    char *keyForm_limit = NULL;
    int valueForm_limit = 0;
    keyValuePair_t *keyPairForm_limit = 0;
    if (limit != NULL)
    {
        keyForm_limit = strdup("limit");
        valueForm_limit = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_limit, MAX_NUMBER_LENGTH, "%d", *limit);
        keyPairForm_limit = keyValuePair_create(keyForm_limit,&valueForm_limit);
        list_addElement(localVarFormParameters,keyPairForm_limit);
    }

    // form parameters
    char *keyForm_timeout = NULL;
    int valueForm_timeout = 0;
    keyValuePair_t *keyPairForm_timeout = 0;
    if (timeout != NULL)
    {
        keyForm_timeout = strdup("timeout");
        valueForm_timeout = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_timeout, MAX_NUMBER_LENGTH, "%d", *timeout);
        keyPairForm_timeout = keyValuePair_create(keyForm_timeout,&valueForm_timeout);
        list_addElement(localVarFormParameters,keyPairForm_timeout);
    }

    // form parameters
    char *keyForm_allowed_updates = NULL;
     valueForm_allowed_updates = 0;
    keyValuePair_t *keyPairForm_allowed_updates = 0;
    if (allowed_updates != NULL)
    {
        keyForm_allowed_updates = strdup("allowed_updates");
        valueForm_allowed_updates = (allowed_updates);
        keyPairForm_allowed_updates = keyValuePair_create(keyForm_allowed_updates,&valueForm_allowed_updates);
        list_addElement(localVarFormParameters,keyPairForm_allowed_updates);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_get_updates_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_get_updates_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_offset) {
        free(keyForm_offset);
        keyForm_offset = NULL;
    }
    free(keyPairForm_offset);
    if (keyForm_limit) {
        free(keyForm_limit);
        keyForm_limit = NULL;
    }
    free(keyPairForm_limit);
    if (keyForm_timeout) {
        free(keyForm_timeout);
        keyForm_timeout = NULL;
    }
    free(keyPairForm_timeout);
    if (keyForm_allowed_updates) {
        free(keyForm_allowed_updates);
        keyForm_allowed_updates = NULL;
    }
    free(keyPairForm_allowed_updates);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// getUserChatBoosts
//
// Use this method to get the list of boosts added to a chat by a user. Requires administrator rights in the chat. Returns a [UserChatBoosts](https://core.telegram.org/bots/api/#userchatboosts) object.
//
post_get_user_chat_boosts_200_response_t*
DefaultAPI_postGetUserChatBoosts(apiClient_t *apiClient, post_get_user_chat_boosts_request_chat_id_t *chat_id, int *user_id)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/getUserChatBoosts");





    // form parameters
    char *keyForm_chat_id = NULL;
    post_get_user_chat_boosts_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_user_id = NULL;
    int valueForm_user_id = 0;
    keyValuePair_t *keyPairForm_user_id = 0;
    if (user_id != NULL)
    {
        keyForm_user_id = strdup("user_id");
        valueForm_user_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_user_id, MAX_NUMBER_LENGTH, "%d", *user_id);
        keyPairForm_user_id = keyValuePair_create(keyForm_user_id,&valueForm_user_id);
        list_addElement(localVarFormParameters,keyPairForm_user_id);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_get_user_chat_boosts_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_get_user_chat_boosts_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_user_id) {
        free(keyForm_user_id);
        keyForm_user_id = NULL;
    }
    free(keyPairForm_user_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// getUserProfilePhotos
//
// Use this method to get a list of profile pictures for a user. Returns a [UserProfilePhotos](https://core.telegram.org/bots/api/#userprofilephotos) object.
//
post_get_user_profile_photos_200_response_t*
DefaultAPI_postGetUserProfilePhotos(apiClient_t *apiClient, int *user_id, int *offset, int *limit)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/getUserProfilePhotos");





    // form parameters
    char *keyForm_user_id = NULL;
    int valueForm_user_id = 0;
    keyValuePair_t *keyPairForm_user_id = 0;
    if (user_id != NULL)
    {
        keyForm_user_id = strdup("user_id");
        valueForm_user_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_user_id, MAX_NUMBER_LENGTH, "%d", *user_id);
        keyPairForm_user_id = keyValuePair_create(keyForm_user_id,&valueForm_user_id);
        list_addElement(localVarFormParameters,keyPairForm_user_id);
    }

    // form parameters
    char *keyForm_offset = NULL;
    int valueForm_offset = 0;
    keyValuePair_t *keyPairForm_offset = 0;
    if (offset != NULL)
    {
        keyForm_offset = strdup("offset");
        valueForm_offset = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_offset, MAX_NUMBER_LENGTH, "%d", *offset);
        keyPairForm_offset = keyValuePair_create(keyForm_offset,&valueForm_offset);
        list_addElement(localVarFormParameters,keyPairForm_offset);
    }

    // form parameters
    char *keyForm_limit = NULL;
    int valueForm_limit = 0;
    keyValuePair_t *keyPairForm_limit = 0;
    if (limit != NULL)
    {
        keyForm_limit = strdup("limit");
        valueForm_limit = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_limit, MAX_NUMBER_LENGTH, "%d", *limit);
        keyPairForm_limit = keyValuePair_create(keyForm_limit,&valueForm_limit);
        list_addElement(localVarFormParameters,keyPairForm_limit);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_get_user_profile_photos_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_get_user_profile_photos_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_user_id) {
        free(keyForm_user_id);
        keyForm_user_id = NULL;
    }
    free(keyPairForm_user_id);
    if (keyForm_offset) {
        free(keyForm_offset);
        keyForm_offset = NULL;
    }
    free(keyPairForm_offset);
    if (keyForm_limit) {
        free(keyForm_limit);
        keyForm_limit = NULL;
    }
    free(keyPairForm_limit);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// getWebhookInfo
//
// Use this method to get current webhook status. Requires no parameters. On success, returns a [WebhookInfo](https://core.telegram.org/bots/api/#webhookinfo) object. If the bot is using [getUpdates](https://core.telegram.org/bots/api/#getupdates), will return an object with the *url* field empty.
//
post_get_webhook_info_200_response_t*
DefaultAPI_postGetWebhookInfo(apiClient_t *apiClient)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/getWebhookInfo");




    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_get_webhook_info_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_get_webhook_info_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// giftPremiumSubscription
//
// Gifts a Telegram Premium subscription to the given user. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postGiftPremiumSubscription(apiClient_t *apiClient, int *user_id, int *month_count, int *star_count, char *text, char *text_parse_mode, list_t *text_entities)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/giftPremiumSubscription");





    // form parameters
    char *keyForm_user_id = NULL;
    int valueForm_user_id = 0;
    keyValuePair_t *keyPairForm_user_id = 0;
    if (user_id != NULL)
    {
        keyForm_user_id = strdup("user_id");
        valueForm_user_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_user_id, MAX_NUMBER_LENGTH, "%d", *user_id);
        keyPairForm_user_id = keyValuePair_create(keyForm_user_id,&valueForm_user_id);
        list_addElement(localVarFormParameters,keyPairForm_user_id);
    }

    // form parameters
    char *keyForm_month_count = NULL;
    int valueForm_month_count = 0;
    keyValuePair_t *keyPairForm_month_count = 0;
    if (month_count != 0)
    {
        keyForm_month_count = strdup("month_count");
        valueForm_month_count = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_month_count, MAX_NUMBER_LENGTH, "%d", *month_count);
        keyPairForm_month_count = keyValuePair_create(keyForm_month_count,&valueForm_month_count);
        list_addElement(localVarFormParameters,keyPairForm_month_count);
    }

    // form parameters
    char *keyForm_star_count = NULL;
    int valueForm_star_count = 0;
    keyValuePair_t *keyPairForm_star_count = 0;
    if (star_count != NULL)
    {
        keyForm_star_count = strdup("star_count");
        valueForm_star_count = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_star_count, MAX_NUMBER_LENGTH, "%d", *star_count);
        keyPairForm_star_count = keyValuePair_create(keyForm_star_count,&valueForm_star_count);
        list_addElement(localVarFormParameters,keyPairForm_star_count);
    }

    // form parameters
    char *keyForm_text = NULL;
    char * valueForm_text = 0;
    keyValuePair_t *keyPairForm_text = 0;
    if (text != NULL)
    {
        keyForm_text = strdup("text");
        valueForm_text = strdup((text));
        keyPairForm_text = keyValuePair_create(keyForm_text,valueForm_text);
        list_addElement(localVarFormParameters,keyPairForm_text);
    }

    // form parameters
    char *keyForm_text_parse_mode = NULL;
    char * valueForm_text_parse_mode = 0;
    keyValuePair_t *keyPairForm_text_parse_mode = 0;
    if (text_parse_mode != NULL)
    {
        keyForm_text_parse_mode = strdup("text_parse_mode");
        valueForm_text_parse_mode = strdup((text_parse_mode));
        keyPairForm_text_parse_mode = keyValuePair_create(keyForm_text_parse_mode,valueForm_text_parse_mode);
        list_addElement(localVarFormParameters,keyPairForm_text_parse_mode);
    }

    // form parameters
    char *keyForm_text_entities = NULL;
     valueForm_text_entities = 0;
    keyValuePair_t *keyPairForm_text_entities = 0;
    if (text_entities != NULL)
    {
        keyForm_text_entities = strdup("text_entities");
        valueForm_text_entities = (text_entities);
        keyPairForm_text_entities = keyValuePair_create(keyForm_text_entities,&valueForm_text_entities);
        list_addElement(localVarFormParameters,keyPairForm_text_entities);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_user_id) {
        free(keyForm_user_id);
        keyForm_user_id = NULL;
    }
    free(keyPairForm_user_id);
    if (keyForm_month_count) {
        free(keyForm_month_count);
        keyForm_month_count = NULL;
    }
    free(keyPairForm_month_count);
    if (keyForm_star_count) {
        free(keyForm_star_count);
        keyForm_star_count = NULL;
    }
    free(keyPairForm_star_count);
    if (keyForm_text) {
        free(keyForm_text);
        keyForm_text = NULL;
    }
    if (valueForm_text) {
        free(valueForm_text);
        valueForm_text = NULL;
    }
    free(keyPairForm_text);
    if (keyForm_text_parse_mode) {
        free(keyForm_text_parse_mode);
        keyForm_text_parse_mode = NULL;
    }
    if (valueForm_text_parse_mode) {
        free(valueForm_text_parse_mode);
        valueForm_text_parse_mode = NULL;
    }
    free(keyPairForm_text_parse_mode);
    if (keyForm_text_entities) {
        free(keyForm_text_entities);
        keyForm_text_entities = NULL;
    }
    free(keyPairForm_text_entities);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// hideGeneralForumTopic
//
// Use this method to hide the 'General' topic in a forum supergroup chat. The bot must be an administrator in the chat for this to work and must have the *can\\_manage\\_topics* administrator rights. The topic will be automatically closed if it was open. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postHideGeneralForumTopic(apiClient_t *apiClient, post_restrict_chat_member_request_chat_id_t *chat_id)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/hideGeneralForumTopic");





    // form parameters
    char *keyForm_chat_id = NULL;
    post_restrict_chat_member_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// leaveChat
//
// Use this method for your bot to leave a group, supergroup or channel. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postLeaveChat(apiClient_t *apiClient, post_leave_chat_request_chat_id_t *chat_id)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/leaveChat");





    // form parameters
    char *keyForm_chat_id = NULL;
    post_leave_chat_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// logOut
//
// Use this method to log out from the cloud Bot API server before launching the bot locally. You **must** log out the bot before running it locally, otherwise there is no guarantee that the bot will receive updates. After a successful call, you can immediately log in on a local server, but will not be able to log in back to the cloud Bot API server for 10 minutes. Returns *True* on success. Requires no parameters.
//
post_set_webhook_200_response_t*
DefaultAPI_postLogOut(apiClient_t *apiClient)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/logOut");




    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// pinChatMessage
//
// Use this method to add a message to the list of pinned messages in a chat. If the chat is not a private chat, the bot must be an administrator in the chat for this to work and must have the 'can\\_pin\\_messages' administrator right in a supergroup or 'can\\_edit\\_messages' administrator right in a channel. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postPinChatMessage(apiClient_t *apiClient, post_send_message_request_chat_id_t *chat_id, int *message_id, char *business_connection_id, int *disable_notification)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/pinChatMessage");





    // form parameters
    char *keyForm_business_connection_id = NULL;
    char * valueForm_business_connection_id = 0;
    keyValuePair_t *keyPairForm_business_connection_id = 0;
    if (business_connection_id != NULL)
    {
        keyForm_business_connection_id = strdup("business_connection_id");
        valueForm_business_connection_id = strdup((business_connection_id));
        keyPairForm_business_connection_id = keyValuePair_create(keyForm_business_connection_id,valueForm_business_connection_id);
        list_addElement(localVarFormParameters,keyPairForm_business_connection_id);
    }

    // form parameters
    char *keyForm_chat_id = NULL;
    post_send_message_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_message_id = NULL;
    int valueForm_message_id = 0;
    keyValuePair_t *keyPairForm_message_id = 0;
    if (message_id != NULL)
    {
        keyForm_message_id = strdup("message_id");
        valueForm_message_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_message_id, MAX_NUMBER_LENGTH, "%d", *message_id);
        keyPairForm_message_id = keyValuePair_create(keyForm_message_id,&valueForm_message_id);
        list_addElement(localVarFormParameters,keyPairForm_message_id);
    }

    // form parameters
    char *keyForm_disable_notification = NULL;
    char * valueForm_disable_notification = 0;
    keyValuePair_t *keyPairForm_disable_notification = 0;
    if (disable_notification != NULL)
    {
        keyForm_disable_notification = strdup("disable_notification");
        valueForm_disable_notification = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_disable_notification, MAX_NUMBER_LENGTH, "%d", *disable_notification);
        keyPairForm_disable_notification = keyValuePair_create(keyForm_disable_notification,valueForm_disable_notification);
        list_addElement(localVarFormParameters,keyPairForm_disable_notification);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_business_connection_id) {
        free(keyForm_business_connection_id);
        keyForm_business_connection_id = NULL;
    }
    if (valueForm_business_connection_id) {
        free(valueForm_business_connection_id);
        valueForm_business_connection_id = NULL;
    }
    free(keyPairForm_business_connection_id);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_message_id) {
        free(keyForm_message_id);
        keyForm_message_id = NULL;
    }
    free(keyPairForm_message_id);
    if (keyForm_disable_notification) {
        free(keyForm_disable_notification);
        keyForm_disable_notification = NULL;
    }
    free(keyPairForm_disable_notification);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// postStory
//
// Posts a story on behalf of a managed business account. Requires the *can\\_manage\\_stories* business bot right. Returns [Story](https://core.telegram.org/bots/api/#story) on success.
//
post_post_story_200_response_t*
DefaultAPI_postPostStory(apiClient_t *apiClient, char *business_connection_id, input_story_content_t *content, int *active_period, char *caption, char *parse_mode, list_t *caption_entities, list_t *areas, int *post_to_chat_page, int *protect_content)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/postStory");





    // form parameters
    char *keyForm_business_connection_id = NULL;
    char * valueForm_business_connection_id = 0;
    keyValuePair_t *keyPairForm_business_connection_id = 0;
    if (business_connection_id != NULL)
    {
        keyForm_business_connection_id = strdup("business_connection_id");
        valueForm_business_connection_id = strdup((business_connection_id));
        keyPairForm_business_connection_id = keyValuePair_create(keyForm_business_connection_id,valueForm_business_connection_id);
        list_addElement(localVarFormParameters,keyPairForm_business_connection_id);
    }

    // form parameters
    char *keyForm_content = NULL;
    input_story_content_t * valueForm_content = 0;
    keyValuePair_t *keyPairForm_content = 0;
    if (content != NULL)
    {
        keyForm_content = strdup("content");
        valueForm_content = (content);
        keyPairForm_content = keyValuePair_create(keyForm_content,&valueForm_content);
        list_addElement(localVarFormParameters,keyPairForm_content);
    }

    // form parameters
    char *keyForm_active_period = NULL;
    int valueForm_active_period = 0;
    keyValuePair_t *keyPairForm_active_period = 0;
    if (active_period != 0)
    {
        keyForm_active_period = strdup("active_period");
        valueForm_active_period = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_active_period, MAX_NUMBER_LENGTH, "%d", *active_period);
        keyPairForm_active_period = keyValuePair_create(keyForm_active_period,&valueForm_active_period);
        list_addElement(localVarFormParameters,keyPairForm_active_period);
    }

    // form parameters
    char *keyForm_caption = NULL;
    char * valueForm_caption = 0;
    keyValuePair_t *keyPairForm_caption = 0;
    if (caption != NULL)
    {
        keyForm_caption = strdup("caption");
        valueForm_caption = strdup((caption));
        keyPairForm_caption = keyValuePair_create(keyForm_caption,valueForm_caption);
        list_addElement(localVarFormParameters,keyPairForm_caption);
    }

    // form parameters
    char *keyForm_parse_mode = NULL;
    char * valueForm_parse_mode = 0;
    keyValuePair_t *keyPairForm_parse_mode = 0;
    if (parse_mode != NULL)
    {
        keyForm_parse_mode = strdup("parse_mode");
        valueForm_parse_mode = strdup((parse_mode));
        keyPairForm_parse_mode = keyValuePair_create(keyForm_parse_mode,valueForm_parse_mode);
        list_addElement(localVarFormParameters,keyPairForm_parse_mode);
    }

    // form parameters
    char *keyForm_caption_entities = NULL;
     valueForm_caption_entities = 0;
    keyValuePair_t *keyPairForm_caption_entities = 0;
    if (caption_entities != NULL)
    {
        keyForm_caption_entities = strdup("caption_entities");
        valueForm_caption_entities = (caption_entities);
        keyPairForm_caption_entities = keyValuePair_create(keyForm_caption_entities,&valueForm_caption_entities);
        list_addElement(localVarFormParameters,keyPairForm_caption_entities);
    }

    // form parameters
    char *keyForm_areas = NULL;
     valueForm_areas = 0;
    keyValuePair_t *keyPairForm_areas = 0;
    if (areas != NULL)
    {
        keyForm_areas = strdup("areas");
        valueForm_areas = (areas);
        keyPairForm_areas = keyValuePair_create(keyForm_areas,&valueForm_areas);
        list_addElement(localVarFormParameters,keyPairForm_areas);
    }

    // form parameters
    char *keyForm_post_to_chat_page = NULL;
    char * valueForm_post_to_chat_page = 0;
    keyValuePair_t *keyPairForm_post_to_chat_page = 0;
    if (post_to_chat_page != NULL)
    {
        keyForm_post_to_chat_page = strdup("post_to_chat_page");
        valueForm_post_to_chat_page = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_post_to_chat_page, MAX_NUMBER_LENGTH, "%d", *post_to_chat_page);
        keyPairForm_post_to_chat_page = keyValuePair_create(keyForm_post_to_chat_page,valueForm_post_to_chat_page);
        list_addElement(localVarFormParameters,keyPairForm_post_to_chat_page);
    }

    // form parameters
    char *keyForm_protect_content = NULL;
    char * valueForm_protect_content = 0;
    keyValuePair_t *keyPairForm_protect_content = 0;
    if (protect_content != NULL)
    {
        keyForm_protect_content = strdup("protect_content");
        valueForm_protect_content = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_protect_content, MAX_NUMBER_LENGTH, "%d", *protect_content);
        keyPairForm_protect_content = keyValuePair_create(keyForm_protect_content,valueForm_protect_content);
        list_addElement(localVarFormParameters,keyPairForm_protect_content);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_post_story_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_post_story_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_business_connection_id) {
        free(keyForm_business_connection_id);
        keyForm_business_connection_id = NULL;
    }
    if (valueForm_business_connection_id) {
        free(valueForm_business_connection_id);
        valueForm_business_connection_id = NULL;
    }
    free(keyPairForm_business_connection_id);
    if (keyForm_content) {
        free(keyForm_content);
        keyForm_content = NULL;
    }
    free(keyPairForm_content);
    if (keyForm_active_period) {
        free(keyForm_active_period);
        keyForm_active_period = NULL;
    }
    free(keyPairForm_active_period);
    if (keyForm_caption) {
        free(keyForm_caption);
        keyForm_caption = NULL;
    }
    if (valueForm_caption) {
        free(valueForm_caption);
        valueForm_caption = NULL;
    }
    free(keyPairForm_caption);
    if (keyForm_parse_mode) {
        free(keyForm_parse_mode);
        keyForm_parse_mode = NULL;
    }
    if (valueForm_parse_mode) {
        free(valueForm_parse_mode);
        valueForm_parse_mode = NULL;
    }
    free(keyPairForm_parse_mode);
    if (keyForm_caption_entities) {
        free(keyForm_caption_entities);
        keyForm_caption_entities = NULL;
    }
    free(keyPairForm_caption_entities);
    if (keyForm_areas) {
        free(keyForm_areas);
        keyForm_areas = NULL;
    }
    free(keyPairForm_areas);
    if (keyForm_post_to_chat_page) {
        free(keyForm_post_to_chat_page);
        keyForm_post_to_chat_page = NULL;
    }
    free(keyPairForm_post_to_chat_page);
    if (keyForm_protect_content) {
        free(keyForm_protect_content);
        keyForm_protect_content = NULL;
    }
    free(keyPairForm_protect_content);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// promoteChatMember
//
// Use this method to promote or demote a user in a supergroup or a channel. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Pass *False* for all boolean parameters to demote a user. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postPromoteChatMember(apiClient_t *apiClient, post_send_message_request_chat_id_t *chat_id, int *user_id, int *is_anonymous, int *can_manage_chat, int *can_delete_messages, int *can_manage_video_chats, int *can_restrict_members, int *can_promote_members, int *can_change_info, int *can_invite_users, int *can_post_stories, int *can_edit_stories, int *can_delete_stories, int *can_post_messages, int *can_edit_messages, int *can_pin_messages, int *can_manage_topics)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/promoteChatMember");





    // form parameters
    char *keyForm_chat_id = NULL;
    post_send_message_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_user_id = NULL;
    int valueForm_user_id = 0;
    keyValuePair_t *keyPairForm_user_id = 0;
    if (user_id != NULL)
    {
        keyForm_user_id = strdup("user_id");
        valueForm_user_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_user_id, MAX_NUMBER_LENGTH, "%d", *user_id);
        keyPairForm_user_id = keyValuePair_create(keyForm_user_id,&valueForm_user_id);
        list_addElement(localVarFormParameters,keyPairForm_user_id);
    }

    // form parameters
    char *keyForm_is_anonymous = NULL;
    char * valueForm_is_anonymous = 0;
    keyValuePair_t *keyPairForm_is_anonymous = 0;
    if (is_anonymous != NULL)
    {
        keyForm_is_anonymous = strdup("is_anonymous");
        valueForm_is_anonymous = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_is_anonymous, MAX_NUMBER_LENGTH, "%d", *is_anonymous);
        keyPairForm_is_anonymous = keyValuePair_create(keyForm_is_anonymous,valueForm_is_anonymous);
        list_addElement(localVarFormParameters,keyPairForm_is_anonymous);
    }

    // form parameters
    char *keyForm_can_manage_chat = NULL;
    char * valueForm_can_manage_chat = 0;
    keyValuePair_t *keyPairForm_can_manage_chat = 0;
    if (can_manage_chat != NULL)
    {
        keyForm_can_manage_chat = strdup("can_manage_chat");
        valueForm_can_manage_chat = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_can_manage_chat, MAX_NUMBER_LENGTH, "%d", *can_manage_chat);
        keyPairForm_can_manage_chat = keyValuePair_create(keyForm_can_manage_chat,valueForm_can_manage_chat);
        list_addElement(localVarFormParameters,keyPairForm_can_manage_chat);
    }

    // form parameters
    char *keyForm_can_delete_messages = NULL;
    char * valueForm_can_delete_messages = 0;
    keyValuePair_t *keyPairForm_can_delete_messages = 0;
    if (can_delete_messages != NULL)
    {
        keyForm_can_delete_messages = strdup("can_delete_messages");
        valueForm_can_delete_messages = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_can_delete_messages, MAX_NUMBER_LENGTH, "%d", *can_delete_messages);
        keyPairForm_can_delete_messages = keyValuePair_create(keyForm_can_delete_messages,valueForm_can_delete_messages);
        list_addElement(localVarFormParameters,keyPairForm_can_delete_messages);
    }

    // form parameters
    char *keyForm_can_manage_video_chats = NULL;
    char * valueForm_can_manage_video_chats = 0;
    keyValuePair_t *keyPairForm_can_manage_video_chats = 0;
    if (can_manage_video_chats != NULL)
    {
        keyForm_can_manage_video_chats = strdup("can_manage_video_chats");
        valueForm_can_manage_video_chats = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_can_manage_video_chats, MAX_NUMBER_LENGTH, "%d", *can_manage_video_chats);
        keyPairForm_can_manage_video_chats = keyValuePair_create(keyForm_can_manage_video_chats,valueForm_can_manage_video_chats);
        list_addElement(localVarFormParameters,keyPairForm_can_manage_video_chats);
    }

    // form parameters
    char *keyForm_can_restrict_members = NULL;
    char * valueForm_can_restrict_members = 0;
    keyValuePair_t *keyPairForm_can_restrict_members = 0;
    if (can_restrict_members != NULL)
    {
        keyForm_can_restrict_members = strdup("can_restrict_members");
        valueForm_can_restrict_members = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_can_restrict_members, MAX_NUMBER_LENGTH, "%d", *can_restrict_members);
        keyPairForm_can_restrict_members = keyValuePair_create(keyForm_can_restrict_members,valueForm_can_restrict_members);
        list_addElement(localVarFormParameters,keyPairForm_can_restrict_members);
    }

    // form parameters
    char *keyForm_can_promote_members = NULL;
    char * valueForm_can_promote_members = 0;
    keyValuePair_t *keyPairForm_can_promote_members = 0;
    if (can_promote_members != NULL)
    {
        keyForm_can_promote_members = strdup("can_promote_members");
        valueForm_can_promote_members = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_can_promote_members, MAX_NUMBER_LENGTH, "%d", *can_promote_members);
        keyPairForm_can_promote_members = keyValuePair_create(keyForm_can_promote_members,valueForm_can_promote_members);
        list_addElement(localVarFormParameters,keyPairForm_can_promote_members);
    }

    // form parameters
    char *keyForm_can_change_info = NULL;
    char * valueForm_can_change_info = 0;
    keyValuePair_t *keyPairForm_can_change_info = 0;
    if (can_change_info != NULL)
    {
        keyForm_can_change_info = strdup("can_change_info");
        valueForm_can_change_info = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_can_change_info, MAX_NUMBER_LENGTH, "%d", *can_change_info);
        keyPairForm_can_change_info = keyValuePair_create(keyForm_can_change_info,valueForm_can_change_info);
        list_addElement(localVarFormParameters,keyPairForm_can_change_info);
    }

    // form parameters
    char *keyForm_can_invite_users = NULL;
    char * valueForm_can_invite_users = 0;
    keyValuePair_t *keyPairForm_can_invite_users = 0;
    if (can_invite_users != NULL)
    {
        keyForm_can_invite_users = strdup("can_invite_users");
        valueForm_can_invite_users = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_can_invite_users, MAX_NUMBER_LENGTH, "%d", *can_invite_users);
        keyPairForm_can_invite_users = keyValuePair_create(keyForm_can_invite_users,valueForm_can_invite_users);
        list_addElement(localVarFormParameters,keyPairForm_can_invite_users);
    }

    // form parameters
    char *keyForm_can_post_stories = NULL;
    char * valueForm_can_post_stories = 0;
    keyValuePair_t *keyPairForm_can_post_stories = 0;
    if (can_post_stories != NULL)
    {
        keyForm_can_post_stories = strdup("can_post_stories");
        valueForm_can_post_stories = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_can_post_stories, MAX_NUMBER_LENGTH, "%d", *can_post_stories);
        keyPairForm_can_post_stories = keyValuePair_create(keyForm_can_post_stories,valueForm_can_post_stories);
        list_addElement(localVarFormParameters,keyPairForm_can_post_stories);
    }

    // form parameters
    char *keyForm_can_edit_stories = NULL;
    char * valueForm_can_edit_stories = 0;
    keyValuePair_t *keyPairForm_can_edit_stories = 0;
    if (can_edit_stories != NULL)
    {
        keyForm_can_edit_stories = strdup("can_edit_stories");
        valueForm_can_edit_stories = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_can_edit_stories, MAX_NUMBER_LENGTH, "%d", *can_edit_stories);
        keyPairForm_can_edit_stories = keyValuePair_create(keyForm_can_edit_stories,valueForm_can_edit_stories);
        list_addElement(localVarFormParameters,keyPairForm_can_edit_stories);
    }

    // form parameters
    char *keyForm_can_delete_stories = NULL;
    char * valueForm_can_delete_stories = 0;
    keyValuePair_t *keyPairForm_can_delete_stories = 0;
    if (can_delete_stories != NULL)
    {
        keyForm_can_delete_stories = strdup("can_delete_stories");
        valueForm_can_delete_stories = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_can_delete_stories, MAX_NUMBER_LENGTH, "%d", *can_delete_stories);
        keyPairForm_can_delete_stories = keyValuePair_create(keyForm_can_delete_stories,valueForm_can_delete_stories);
        list_addElement(localVarFormParameters,keyPairForm_can_delete_stories);
    }

    // form parameters
    char *keyForm_can_post_messages = NULL;
    char * valueForm_can_post_messages = 0;
    keyValuePair_t *keyPairForm_can_post_messages = 0;
    if (can_post_messages != NULL)
    {
        keyForm_can_post_messages = strdup("can_post_messages");
        valueForm_can_post_messages = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_can_post_messages, MAX_NUMBER_LENGTH, "%d", *can_post_messages);
        keyPairForm_can_post_messages = keyValuePair_create(keyForm_can_post_messages,valueForm_can_post_messages);
        list_addElement(localVarFormParameters,keyPairForm_can_post_messages);
    }

    // form parameters
    char *keyForm_can_edit_messages = NULL;
    char * valueForm_can_edit_messages = 0;
    keyValuePair_t *keyPairForm_can_edit_messages = 0;
    if (can_edit_messages != NULL)
    {
        keyForm_can_edit_messages = strdup("can_edit_messages");
        valueForm_can_edit_messages = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_can_edit_messages, MAX_NUMBER_LENGTH, "%d", *can_edit_messages);
        keyPairForm_can_edit_messages = keyValuePair_create(keyForm_can_edit_messages,valueForm_can_edit_messages);
        list_addElement(localVarFormParameters,keyPairForm_can_edit_messages);
    }

    // form parameters
    char *keyForm_can_pin_messages = NULL;
    char * valueForm_can_pin_messages = 0;
    keyValuePair_t *keyPairForm_can_pin_messages = 0;
    if (can_pin_messages != NULL)
    {
        keyForm_can_pin_messages = strdup("can_pin_messages");
        valueForm_can_pin_messages = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_can_pin_messages, MAX_NUMBER_LENGTH, "%d", *can_pin_messages);
        keyPairForm_can_pin_messages = keyValuePair_create(keyForm_can_pin_messages,valueForm_can_pin_messages);
        list_addElement(localVarFormParameters,keyPairForm_can_pin_messages);
    }

    // form parameters
    char *keyForm_can_manage_topics = NULL;
    char * valueForm_can_manage_topics = 0;
    keyValuePair_t *keyPairForm_can_manage_topics = 0;
    if (can_manage_topics != NULL)
    {
        keyForm_can_manage_topics = strdup("can_manage_topics");
        valueForm_can_manage_topics = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_can_manage_topics, MAX_NUMBER_LENGTH, "%d", *can_manage_topics);
        keyPairForm_can_manage_topics = keyValuePair_create(keyForm_can_manage_topics,valueForm_can_manage_topics);
        list_addElement(localVarFormParameters,keyPairForm_can_manage_topics);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_user_id) {
        free(keyForm_user_id);
        keyForm_user_id = NULL;
    }
    free(keyPairForm_user_id);
    if (keyForm_is_anonymous) {
        free(keyForm_is_anonymous);
        keyForm_is_anonymous = NULL;
    }
    free(keyPairForm_is_anonymous);
    if (keyForm_can_manage_chat) {
        free(keyForm_can_manage_chat);
        keyForm_can_manage_chat = NULL;
    }
    free(keyPairForm_can_manage_chat);
    if (keyForm_can_delete_messages) {
        free(keyForm_can_delete_messages);
        keyForm_can_delete_messages = NULL;
    }
    free(keyPairForm_can_delete_messages);
    if (keyForm_can_manage_video_chats) {
        free(keyForm_can_manage_video_chats);
        keyForm_can_manage_video_chats = NULL;
    }
    free(keyPairForm_can_manage_video_chats);
    if (keyForm_can_restrict_members) {
        free(keyForm_can_restrict_members);
        keyForm_can_restrict_members = NULL;
    }
    free(keyPairForm_can_restrict_members);
    if (keyForm_can_promote_members) {
        free(keyForm_can_promote_members);
        keyForm_can_promote_members = NULL;
    }
    free(keyPairForm_can_promote_members);
    if (keyForm_can_change_info) {
        free(keyForm_can_change_info);
        keyForm_can_change_info = NULL;
    }
    free(keyPairForm_can_change_info);
    if (keyForm_can_invite_users) {
        free(keyForm_can_invite_users);
        keyForm_can_invite_users = NULL;
    }
    free(keyPairForm_can_invite_users);
    if (keyForm_can_post_stories) {
        free(keyForm_can_post_stories);
        keyForm_can_post_stories = NULL;
    }
    free(keyPairForm_can_post_stories);
    if (keyForm_can_edit_stories) {
        free(keyForm_can_edit_stories);
        keyForm_can_edit_stories = NULL;
    }
    free(keyPairForm_can_edit_stories);
    if (keyForm_can_delete_stories) {
        free(keyForm_can_delete_stories);
        keyForm_can_delete_stories = NULL;
    }
    free(keyPairForm_can_delete_stories);
    if (keyForm_can_post_messages) {
        free(keyForm_can_post_messages);
        keyForm_can_post_messages = NULL;
    }
    free(keyPairForm_can_post_messages);
    if (keyForm_can_edit_messages) {
        free(keyForm_can_edit_messages);
        keyForm_can_edit_messages = NULL;
    }
    free(keyPairForm_can_edit_messages);
    if (keyForm_can_pin_messages) {
        free(keyForm_can_pin_messages);
        keyForm_can_pin_messages = NULL;
    }
    free(keyPairForm_can_pin_messages);
    if (keyForm_can_manage_topics) {
        free(keyForm_can_manage_topics);
        keyForm_can_manage_topics = NULL;
    }
    free(keyPairForm_can_manage_topics);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// readBusinessMessage
//
// Marks incoming message as read on behalf of a business account. Requires the *can\\_read\\_messages* business bot right. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postReadBusinessMessage(apiClient_t *apiClient, char *business_connection_id, int *chat_id, int *message_id)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/readBusinessMessage");





    // form parameters
    char *keyForm_business_connection_id = NULL;
    char * valueForm_business_connection_id = 0;
    keyValuePair_t *keyPairForm_business_connection_id = 0;
    if (business_connection_id != NULL)
    {
        keyForm_business_connection_id = strdup("business_connection_id");
        valueForm_business_connection_id = strdup((business_connection_id));
        keyPairForm_business_connection_id = keyValuePair_create(keyForm_business_connection_id,valueForm_business_connection_id);
        list_addElement(localVarFormParameters,keyPairForm_business_connection_id);
    }

    // form parameters
    char *keyForm_chat_id = NULL;
    int valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_chat_id, MAX_NUMBER_LENGTH, "%d", *chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_message_id = NULL;
    int valueForm_message_id = 0;
    keyValuePair_t *keyPairForm_message_id = 0;
    if (message_id != NULL)
    {
        keyForm_message_id = strdup("message_id");
        valueForm_message_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_message_id, MAX_NUMBER_LENGTH, "%d", *message_id);
        keyPairForm_message_id = keyValuePair_create(keyForm_message_id,&valueForm_message_id);
        list_addElement(localVarFormParameters,keyPairForm_message_id);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_business_connection_id) {
        free(keyForm_business_connection_id);
        keyForm_business_connection_id = NULL;
    }
    if (valueForm_business_connection_id) {
        free(valueForm_business_connection_id);
        valueForm_business_connection_id = NULL;
    }
    free(keyPairForm_business_connection_id);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_message_id) {
        free(keyForm_message_id);
        keyForm_message_id = NULL;
    }
    free(keyPairForm_message_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// refundStarPayment
//
// Refunds a successful payment in [Telegram Stars](https://t.me/BotNews/90). Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postRefundStarPayment(apiClient_t *apiClient, int *user_id, char *telegram_payment_charge_id)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/refundStarPayment");





    // form parameters
    char *keyForm_user_id = NULL;
    int valueForm_user_id = 0;
    keyValuePair_t *keyPairForm_user_id = 0;
    if (user_id != NULL)
    {
        keyForm_user_id = strdup("user_id");
        valueForm_user_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_user_id, MAX_NUMBER_LENGTH, "%d", *user_id);
        keyPairForm_user_id = keyValuePair_create(keyForm_user_id,&valueForm_user_id);
        list_addElement(localVarFormParameters,keyPairForm_user_id);
    }

    // form parameters
    char *keyForm_telegram_payment_charge_id = NULL;
    char * valueForm_telegram_payment_charge_id = 0;
    keyValuePair_t *keyPairForm_telegram_payment_charge_id = 0;
    if (telegram_payment_charge_id != NULL)
    {
        keyForm_telegram_payment_charge_id = strdup("telegram_payment_charge_id");
        valueForm_telegram_payment_charge_id = strdup((telegram_payment_charge_id));
        keyPairForm_telegram_payment_charge_id = keyValuePair_create(keyForm_telegram_payment_charge_id,valueForm_telegram_payment_charge_id);
        list_addElement(localVarFormParameters,keyPairForm_telegram_payment_charge_id);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_user_id) {
        free(keyForm_user_id);
        keyForm_user_id = NULL;
    }
    free(keyPairForm_user_id);
    if (keyForm_telegram_payment_charge_id) {
        free(keyForm_telegram_payment_charge_id);
        keyForm_telegram_payment_charge_id = NULL;
    }
    if (valueForm_telegram_payment_charge_id) {
        free(valueForm_telegram_payment_charge_id);
        valueForm_telegram_payment_charge_id = NULL;
    }
    free(keyPairForm_telegram_payment_charge_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// removeBusinessAccountProfilePhoto
//
// Removes the current profile photo of a managed business account. Requires the *can\\_edit\\_profile\\_photo* business bot right. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postRemoveBusinessAccountProfilePhoto(apiClient_t *apiClient, char *business_connection_id, int *is_public)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/removeBusinessAccountProfilePhoto");





    // form parameters
    char *keyForm_business_connection_id = NULL;
    char * valueForm_business_connection_id = 0;
    keyValuePair_t *keyPairForm_business_connection_id = 0;
    if (business_connection_id != NULL)
    {
        keyForm_business_connection_id = strdup("business_connection_id");
        valueForm_business_connection_id = strdup((business_connection_id));
        keyPairForm_business_connection_id = keyValuePair_create(keyForm_business_connection_id,valueForm_business_connection_id);
        list_addElement(localVarFormParameters,keyPairForm_business_connection_id);
    }

    // form parameters
    char *keyForm_is_public = NULL;
    char * valueForm_is_public = 0;
    keyValuePair_t *keyPairForm_is_public = 0;
    if (is_public != NULL)
    {
        keyForm_is_public = strdup("is_public");
        valueForm_is_public = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_is_public, MAX_NUMBER_LENGTH, "%d", *is_public);
        keyPairForm_is_public = keyValuePair_create(keyForm_is_public,valueForm_is_public);
        list_addElement(localVarFormParameters,keyPairForm_is_public);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_business_connection_id) {
        free(keyForm_business_connection_id);
        keyForm_business_connection_id = NULL;
    }
    if (valueForm_business_connection_id) {
        free(valueForm_business_connection_id);
        valueForm_business_connection_id = NULL;
    }
    free(keyPairForm_business_connection_id);
    if (keyForm_is_public) {
        free(keyForm_is_public);
        keyForm_is_public = NULL;
    }
    free(keyPairForm_is_public);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// removeChatVerification
//
// Removes verification from a chat that is currently verified [on behalf of the organization](https://telegram.org/verify#third-party-verification) represented by the bot. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postRemoveChatVerification(apiClient_t *apiClient, post_send_message_request_chat_id_t *chat_id)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/removeChatVerification");





    // form parameters
    char *keyForm_chat_id = NULL;
    post_send_message_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// removeUserVerification
//
// Removes verification from a user who is currently verified [on behalf of the organization](https://telegram.org/verify#third-party-verification) represented by the bot. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postRemoveUserVerification(apiClient_t *apiClient, int *user_id)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/removeUserVerification");





    // form parameters
    char *keyForm_user_id = NULL;
    int valueForm_user_id = 0;
    keyValuePair_t *keyPairForm_user_id = 0;
    if (user_id != NULL)
    {
        keyForm_user_id = strdup("user_id");
        valueForm_user_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_user_id, MAX_NUMBER_LENGTH, "%d", *user_id);
        keyPairForm_user_id = keyValuePair_create(keyForm_user_id,&valueForm_user_id);
        list_addElement(localVarFormParameters,keyPairForm_user_id);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_user_id) {
        free(keyForm_user_id);
        keyForm_user_id = NULL;
    }
    free(keyPairForm_user_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// reopenForumTopic
//
// Use this method to reopen a closed topic in a forum supergroup chat. The bot must be an administrator in the chat for this to work and must have the *can\\_manage\\_topics* administrator rights, unless it is the creator of the topic. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postReopenForumTopic(apiClient_t *apiClient, post_restrict_chat_member_request_chat_id_t *chat_id, int *message_thread_id)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/reopenForumTopic");





    // form parameters
    char *keyForm_chat_id = NULL;
    post_restrict_chat_member_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_message_thread_id = NULL;
    int valueForm_message_thread_id = 0;
    keyValuePair_t *keyPairForm_message_thread_id = 0;
    if (message_thread_id != NULL)
    {
        keyForm_message_thread_id = strdup("message_thread_id");
        valueForm_message_thread_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_message_thread_id, MAX_NUMBER_LENGTH, "%d", *message_thread_id);
        keyPairForm_message_thread_id = keyValuePair_create(keyForm_message_thread_id,&valueForm_message_thread_id);
        list_addElement(localVarFormParameters,keyPairForm_message_thread_id);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_message_thread_id) {
        free(keyForm_message_thread_id);
        keyForm_message_thread_id = NULL;
    }
    free(keyPairForm_message_thread_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// reopenGeneralForumTopic
//
// Use this method to reopen a closed 'General' topic in a forum supergroup chat. The bot must be an administrator in the chat for this to work and must have the *can\\_manage\\_topics* administrator rights. The topic will be automatically unhidden if it was hidden. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postReopenGeneralForumTopic(apiClient_t *apiClient, post_restrict_chat_member_request_chat_id_t *chat_id)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/reopenGeneralForumTopic");





    // form parameters
    char *keyForm_chat_id = NULL;
    post_restrict_chat_member_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// replaceStickerInSet
//
// Use this method to replace an existing sticker in a sticker set with a new one. The method is equivalent to calling [deleteStickerFromSet](https://core.telegram.org/bots/api/#deletestickerfromset), then [addStickerToSet](https://core.telegram.org/bots/api/#addstickertoset), then [setStickerPositionInSet](https://core.telegram.org/bots/api/#setstickerpositioninset). Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postReplaceStickerInSet(apiClient_t *apiClient, int *user_id, char *name, char *old_sticker, input_sticker_t *sticker)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/replaceStickerInSet");





    // form parameters
    char *keyForm_user_id = NULL;
    int valueForm_user_id = 0;
    keyValuePair_t *keyPairForm_user_id = 0;
    if (user_id != NULL)
    {
        keyForm_user_id = strdup("user_id");
        valueForm_user_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_user_id, MAX_NUMBER_LENGTH, "%d", *user_id);
        keyPairForm_user_id = keyValuePair_create(keyForm_user_id,&valueForm_user_id);
        list_addElement(localVarFormParameters,keyPairForm_user_id);
    }

    // form parameters
    char *keyForm_name = NULL;
    char * valueForm_name = 0;
    keyValuePair_t *keyPairForm_name = 0;
    if (name != NULL)
    {
        keyForm_name = strdup("name");
        valueForm_name = strdup((name));
        keyPairForm_name = keyValuePair_create(keyForm_name,valueForm_name);
        list_addElement(localVarFormParameters,keyPairForm_name);
    }

    // form parameters
    char *keyForm_old_sticker = NULL;
    char * valueForm_old_sticker = 0;
    keyValuePair_t *keyPairForm_old_sticker = 0;
    if (old_sticker != NULL)
    {
        keyForm_old_sticker = strdup("old_sticker");
        valueForm_old_sticker = strdup((old_sticker));
        keyPairForm_old_sticker = keyValuePair_create(keyForm_old_sticker,valueForm_old_sticker);
        list_addElement(localVarFormParameters,keyPairForm_old_sticker);
    }

    // form parameters
    char *keyForm_sticker = NULL;
    input_sticker_t * valueForm_sticker = 0;
    keyValuePair_t *keyPairForm_sticker = 0;
    if (sticker != NULL)
    {
        keyForm_sticker = strdup("sticker");
        valueForm_sticker = (sticker);
        keyPairForm_sticker = keyValuePair_create(keyForm_sticker,&valueForm_sticker);
        list_addElement(localVarFormParameters,keyPairForm_sticker);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_user_id) {
        free(keyForm_user_id);
        keyForm_user_id = NULL;
    }
    free(keyPairForm_user_id);
    if (keyForm_name) {
        free(keyForm_name);
        keyForm_name = NULL;
    }
    if (valueForm_name) {
        free(valueForm_name);
        valueForm_name = NULL;
    }
    free(keyPairForm_name);
    if (keyForm_old_sticker) {
        free(keyForm_old_sticker);
        keyForm_old_sticker = NULL;
    }
    if (valueForm_old_sticker) {
        free(valueForm_old_sticker);
        valueForm_old_sticker = NULL;
    }
    free(keyPairForm_old_sticker);
    if (keyForm_sticker) {
        free(keyForm_sticker);
        keyForm_sticker = NULL;
    }
    free(keyPairForm_sticker);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// restrictChatMember
//
// Use this method to restrict a user in a supergroup. The bot must be an administrator in the supergroup for this to work and must have the appropriate administrator rights. Pass *True* for all permissions to lift restrictions from a user. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postRestrictChatMember(apiClient_t *apiClient, post_restrict_chat_member_request_chat_id_t *chat_id, int *user_id, chat_permissions_t *permissions, int *use_independent_chat_permissions, int *until_date)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/restrictChatMember");





    // form parameters
    char *keyForm_chat_id = NULL;
    post_restrict_chat_member_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_user_id = NULL;
    int valueForm_user_id = 0;
    keyValuePair_t *keyPairForm_user_id = 0;
    if (user_id != NULL)
    {
        keyForm_user_id = strdup("user_id");
        valueForm_user_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_user_id, MAX_NUMBER_LENGTH, "%d", *user_id);
        keyPairForm_user_id = keyValuePair_create(keyForm_user_id,&valueForm_user_id);
        list_addElement(localVarFormParameters,keyPairForm_user_id);
    }

    // form parameters
    char *keyForm_permissions = NULL;
    chat_permissions_t * valueForm_permissions = 0;
    keyValuePair_t *keyPairForm_permissions = 0;
    if (permissions != NULL)
    {
        keyForm_permissions = strdup("permissions");
        valueForm_permissions = (permissions);
        keyPairForm_permissions = keyValuePair_create(keyForm_permissions,&valueForm_permissions);
        list_addElement(localVarFormParameters,keyPairForm_permissions);
    }

    // form parameters
    char *keyForm_use_independent_chat_permissions = NULL;
    char * valueForm_use_independent_chat_permissions = 0;
    keyValuePair_t *keyPairForm_use_independent_chat_permissions = 0;
    if (use_independent_chat_permissions != NULL)
    {
        keyForm_use_independent_chat_permissions = strdup("use_independent_chat_permissions");
        valueForm_use_independent_chat_permissions = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_use_independent_chat_permissions, MAX_NUMBER_LENGTH, "%d", *use_independent_chat_permissions);
        keyPairForm_use_independent_chat_permissions = keyValuePair_create(keyForm_use_independent_chat_permissions,valueForm_use_independent_chat_permissions);
        list_addElement(localVarFormParameters,keyPairForm_use_independent_chat_permissions);
    }

    // form parameters
    char *keyForm_until_date = NULL;
    int valueForm_until_date = 0;
    keyValuePair_t *keyPairForm_until_date = 0;
    if (until_date != NULL)
    {
        keyForm_until_date = strdup("until_date");
        valueForm_until_date = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_until_date, MAX_NUMBER_LENGTH, "%d", *until_date);
        keyPairForm_until_date = keyValuePair_create(keyForm_until_date,&valueForm_until_date);
        list_addElement(localVarFormParameters,keyPairForm_until_date);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_user_id) {
        free(keyForm_user_id);
        keyForm_user_id = NULL;
    }
    free(keyPairForm_user_id);
    if (keyForm_permissions) {
        free(keyForm_permissions);
        keyForm_permissions = NULL;
    }
    free(keyPairForm_permissions);
    if (keyForm_use_independent_chat_permissions) {
        free(keyForm_use_independent_chat_permissions);
        keyForm_use_independent_chat_permissions = NULL;
    }
    free(keyPairForm_use_independent_chat_permissions);
    if (keyForm_until_date) {
        free(keyForm_until_date);
        keyForm_until_date = NULL;
    }
    free(keyPairForm_until_date);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// revokeChatInviteLink
//
// Use this method to revoke an invite link created by the bot. If the primary link is revoked, a new link is automatically generated. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Returns the revoked invite link as [ChatInviteLink](https://core.telegram.org/bots/api/#chatinvitelink) object.
//
post_create_chat_invite_link_200_response_t*
DefaultAPI_postRevokeChatInviteLink(apiClient_t *apiClient, post_revoke_chat_invite_link_request_chat_id_t *chat_id, char *invite_link)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/revokeChatInviteLink");





    // form parameters
    char *keyForm_chat_id = NULL;
    post_revoke_chat_invite_link_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_invite_link = NULL;
    char * valueForm_invite_link = 0;
    keyValuePair_t *keyPairForm_invite_link = 0;
    if (invite_link != NULL)
    {
        keyForm_invite_link = strdup("invite_link");
        valueForm_invite_link = strdup((invite_link));
        keyPairForm_invite_link = keyValuePair_create(keyForm_invite_link,valueForm_invite_link);
        list_addElement(localVarFormParameters,keyPairForm_invite_link);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_create_chat_invite_link_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_create_chat_invite_link_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_invite_link) {
        free(keyForm_invite_link);
        keyForm_invite_link = NULL;
    }
    if (valueForm_invite_link) {
        free(valueForm_invite_link);
        valueForm_invite_link = NULL;
    }
    free(keyPairForm_invite_link);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// savePreparedInlineMessage
//
// Stores a message that can be sent by a user of a Mini App. Returns a [PreparedInlineMessage](https://core.telegram.org/bots/api/#preparedinlinemessage) object.
//
post_save_prepared_inline_message_200_response_t*
DefaultAPI_postSavePreparedInlineMessage(apiClient_t *apiClient, int *user_id, inline_query_result_t *result, int *allow_user_chats, int *allow_bot_chats, int *allow_group_chats, int *allow_channel_chats)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/savePreparedInlineMessage");





    // form parameters
    char *keyForm_user_id = NULL;
    int valueForm_user_id = 0;
    keyValuePair_t *keyPairForm_user_id = 0;
    if (user_id != NULL)
    {
        keyForm_user_id = strdup("user_id");
        valueForm_user_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_user_id, MAX_NUMBER_LENGTH, "%d", *user_id);
        keyPairForm_user_id = keyValuePair_create(keyForm_user_id,&valueForm_user_id);
        list_addElement(localVarFormParameters,keyPairForm_user_id);
    }

    // form parameters
    char *keyForm_result = NULL;
    inline_query_result_t * valueForm_result = 0;
    keyValuePair_t *keyPairForm_result = 0;
    if (result != NULL)
    {
        keyForm_result = strdup("result");
        valueForm_result = (result);
        keyPairForm_result = keyValuePair_create(keyForm_result,&valueForm_result);
        list_addElement(localVarFormParameters,keyPairForm_result);
    }

    // form parameters
    char *keyForm_allow_user_chats = NULL;
    char * valueForm_allow_user_chats = 0;
    keyValuePair_t *keyPairForm_allow_user_chats = 0;
    if (allow_user_chats != NULL)
    {
        keyForm_allow_user_chats = strdup("allow_user_chats");
        valueForm_allow_user_chats = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_allow_user_chats, MAX_NUMBER_LENGTH, "%d", *allow_user_chats);
        keyPairForm_allow_user_chats = keyValuePair_create(keyForm_allow_user_chats,valueForm_allow_user_chats);
        list_addElement(localVarFormParameters,keyPairForm_allow_user_chats);
    }

    // form parameters
    char *keyForm_allow_bot_chats = NULL;
    char * valueForm_allow_bot_chats = 0;
    keyValuePair_t *keyPairForm_allow_bot_chats = 0;
    if (allow_bot_chats != NULL)
    {
        keyForm_allow_bot_chats = strdup("allow_bot_chats");
        valueForm_allow_bot_chats = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_allow_bot_chats, MAX_NUMBER_LENGTH, "%d", *allow_bot_chats);
        keyPairForm_allow_bot_chats = keyValuePair_create(keyForm_allow_bot_chats,valueForm_allow_bot_chats);
        list_addElement(localVarFormParameters,keyPairForm_allow_bot_chats);
    }

    // form parameters
    char *keyForm_allow_group_chats = NULL;
    char * valueForm_allow_group_chats = 0;
    keyValuePair_t *keyPairForm_allow_group_chats = 0;
    if (allow_group_chats != NULL)
    {
        keyForm_allow_group_chats = strdup("allow_group_chats");
        valueForm_allow_group_chats = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_allow_group_chats, MAX_NUMBER_LENGTH, "%d", *allow_group_chats);
        keyPairForm_allow_group_chats = keyValuePair_create(keyForm_allow_group_chats,valueForm_allow_group_chats);
        list_addElement(localVarFormParameters,keyPairForm_allow_group_chats);
    }

    // form parameters
    char *keyForm_allow_channel_chats = NULL;
    char * valueForm_allow_channel_chats = 0;
    keyValuePair_t *keyPairForm_allow_channel_chats = 0;
    if (allow_channel_chats != NULL)
    {
        keyForm_allow_channel_chats = strdup("allow_channel_chats");
        valueForm_allow_channel_chats = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_allow_channel_chats, MAX_NUMBER_LENGTH, "%d", *allow_channel_chats);
        keyPairForm_allow_channel_chats = keyValuePair_create(keyForm_allow_channel_chats,valueForm_allow_channel_chats);
        list_addElement(localVarFormParameters,keyPairForm_allow_channel_chats);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_save_prepared_inline_message_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_save_prepared_inline_message_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_user_id) {
        free(keyForm_user_id);
        keyForm_user_id = NULL;
    }
    free(keyPairForm_user_id);
    if (keyForm_result) {
        free(keyForm_result);
        keyForm_result = NULL;
    }
    free(keyPairForm_result);
    if (keyForm_allow_user_chats) {
        free(keyForm_allow_user_chats);
        keyForm_allow_user_chats = NULL;
    }
    free(keyPairForm_allow_user_chats);
    if (keyForm_allow_bot_chats) {
        free(keyForm_allow_bot_chats);
        keyForm_allow_bot_chats = NULL;
    }
    free(keyPairForm_allow_bot_chats);
    if (keyForm_allow_group_chats) {
        free(keyForm_allow_group_chats);
        keyForm_allow_group_chats = NULL;
    }
    free(keyPairForm_allow_group_chats);
    if (keyForm_allow_channel_chats) {
        free(keyForm_allow_channel_chats);
        keyForm_allow_channel_chats = NULL;
    }
    free(keyPairForm_allow_channel_chats);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// sendAnimation
//
// Use this method to send animation files (GIF or H.264/MPEG-4 AVC video without sound). On success, the sent [Message](https://core.telegram.org/bots/api/#message) is returned. Bots can currently send animation files of up to 50 MB in size, this limit may be changed in the future.
//
post_send_message_200_response_t*
DefaultAPI_postSendAnimation(apiClient_t *apiClient, post_send_message_request_chat_id_t *chat_id, post_send_animation_request_animation_t *animation, char *business_connection_id, int *message_thread_id, int *duration, int *width, int *height, post_send_audio_request_thumbnail_t *thumbnail, char *caption, char *parse_mode, list_t *caption_entities, int *show_caption_above_media, int *has_spoiler, int *disable_notification, int *protect_content, int *allow_paid_broadcast, char *message_effect_id, reply_parameters_t *reply_parameters, post_send_message_request_reply_markup_t *reply_markup)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/sendAnimation");





    // form parameters
    char *keyForm_business_connection_id = NULL;
    char * valueForm_business_connection_id = 0;
    keyValuePair_t *keyPairForm_business_connection_id = 0;
    if (business_connection_id != NULL)
    {
        keyForm_business_connection_id = strdup("business_connection_id");
        valueForm_business_connection_id = strdup((business_connection_id));
        keyPairForm_business_connection_id = keyValuePair_create(keyForm_business_connection_id,valueForm_business_connection_id);
        list_addElement(localVarFormParameters,keyPairForm_business_connection_id);
    }

    // form parameters
    char *keyForm_chat_id = NULL;
    post_send_message_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_message_thread_id = NULL;
    int valueForm_message_thread_id = 0;
    keyValuePair_t *keyPairForm_message_thread_id = 0;
    if (message_thread_id != NULL)
    {
        keyForm_message_thread_id = strdup("message_thread_id");
        valueForm_message_thread_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_message_thread_id, MAX_NUMBER_LENGTH, "%d", *message_thread_id);
        keyPairForm_message_thread_id = keyValuePair_create(keyForm_message_thread_id,&valueForm_message_thread_id);
        list_addElement(localVarFormParameters,keyPairForm_message_thread_id);
    }

    // form parameters
    char *keyForm_animation = NULL;
    post_send_animation_request_animation_t * valueForm_animation = 0;
    keyValuePair_t *keyPairForm_animation = 0;
    if (animation != NULL)
    {
        keyForm_animation = strdup("animation");
        valueForm_animation = (animation);
        keyPairForm_animation = keyValuePair_create(keyForm_animation,&valueForm_animation);
        list_addElement(localVarFormParameters,keyPairForm_animation);
    }

    // form parameters
    char *keyForm_duration = NULL;
    int valueForm_duration = 0;
    keyValuePair_t *keyPairForm_duration = 0;
    if (duration != NULL)
    {
        keyForm_duration = strdup("duration");
        valueForm_duration = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_duration, MAX_NUMBER_LENGTH, "%d", *duration);
        keyPairForm_duration = keyValuePair_create(keyForm_duration,&valueForm_duration);
        list_addElement(localVarFormParameters,keyPairForm_duration);
    }

    // form parameters
    char *keyForm_width = NULL;
    int valueForm_width = 0;
    keyValuePair_t *keyPairForm_width = 0;
    if (width != NULL)
    {
        keyForm_width = strdup("width");
        valueForm_width = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_width, MAX_NUMBER_LENGTH, "%d", *width);
        keyPairForm_width = keyValuePair_create(keyForm_width,&valueForm_width);
        list_addElement(localVarFormParameters,keyPairForm_width);
    }

    // form parameters
    char *keyForm_height = NULL;
    int valueForm_height = 0;
    keyValuePair_t *keyPairForm_height = 0;
    if (height != NULL)
    {
        keyForm_height = strdup("height");
        valueForm_height = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_height, MAX_NUMBER_LENGTH, "%d", *height);
        keyPairForm_height = keyValuePair_create(keyForm_height,&valueForm_height);
        list_addElement(localVarFormParameters,keyPairForm_height);
    }

    // form parameters
    char *keyForm_thumbnail = NULL;
    post_send_audio_request_thumbnail_t * valueForm_thumbnail = 0;
    keyValuePair_t *keyPairForm_thumbnail = 0;
    if (thumbnail != NULL)
    {
        keyForm_thumbnail = strdup("thumbnail");
        valueForm_thumbnail = (thumbnail);
        keyPairForm_thumbnail = keyValuePair_create(keyForm_thumbnail,&valueForm_thumbnail);
        list_addElement(localVarFormParameters,keyPairForm_thumbnail);
    }

    // form parameters
    char *keyForm_caption = NULL;
    char * valueForm_caption = 0;
    keyValuePair_t *keyPairForm_caption = 0;
    if (caption != NULL)
    {
        keyForm_caption = strdup("caption");
        valueForm_caption = strdup((caption));
        keyPairForm_caption = keyValuePair_create(keyForm_caption,valueForm_caption);
        list_addElement(localVarFormParameters,keyPairForm_caption);
    }

    // form parameters
    char *keyForm_parse_mode = NULL;
    char * valueForm_parse_mode = 0;
    keyValuePair_t *keyPairForm_parse_mode = 0;
    if (parse_mode != NULL)
    {
        keyForm_parse_mode = strdup("parse_mode");
        valueForm_parse_mode = strdup((parse_mode));
        keyPairForm_parse_mode = keyValuePair_create(keyForm_parse_mode,valueForm_parse_mode);
        list_addElement(localVarFormParameters,keyPairForm_parse_mode);
    }

    // form parameters
    char *keyForm_caption_entities = NULL;
     valueForm_caption_entities = 0;
    keyValuePair_t *keyPairForm_caption_entities = 0;
    if (caption_entities != NULL)
    {
        keyForm_caption_entities = strdup("caption_entities");
        valueForm_caption_entities = (caption_entities);
        keyPairForm_caption_entities = keyValuePair_create(keyForm_caption_entities,&valueForm_caption_entities);
        list_addElement(localVarFormParameters,keyPairForm_caption_entities);
    }

    // form parameters
    char *keyForm_show_caption_above_media = NULL;
    char * valueForm_show_caption_above_media = 0;
    keyValuePair_t *keyPairForm_show_caption_above_media = 0;
    if (show_caption_above_media != NULL)
    {
        keyForm_show_caption_above_media = strdup("show_caption_above_media");
        valueForm_show_caption_above_media = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_show_caption_above_media, MAX_NUMBER_LENGTH, "%d", *show_caption_above_media);
        keyPairForm_show_caption_above_media = keyValuePair_create(keyForm_show_caption_above_media,valueForm_show_caption_above_media);
        list_addElement(localVarFormParameters,keyPairForm_show_caption_above_media);
    }

    // form parameters
    char *keyForm_has_spoiler = NULL;
    char * valueForm_has_spoiler = 0;
    keyValuePair_t *keyPairForm_has_spoiler = 0;
    if (has_spoiler != NULL)
    {
        keyForm_has_spoiler = strdup("has_spoiler");
        valueForm_has_spoiler = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_has_spoiler, MAX_NUMBER_LENGTH, "%d", *has_spoiler);
        keyPairForm_has_spoiler = keyValuePair_create(keyForm_has_spoiler,valueForm_has_spoiler);
        list_addElement(localVarFormParameters,keyPairForm_has_spoiler);
    }

    // form parameters
    char *keyForm_disable_notification = NULL;
    char * valueForm_disable_notification = 0;
    keyValuePair_t *keyPairForm_disable_notification = 0;
    if (disable_notification != NULL)
    {
        keyForm_disable_notification = strdup("disable_notification");
        valueForm_disable_notification = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_disable_notification, MAX_NUMBER_LENGTH, "%d", *disable_notification);
        keyPairForm_disable_notification = keyValuePair_create(keyForm_disable_notification,valueForm_disable_notification);
        list_addElement(localVarFormParameters,keyPairForm_disable_notification);
    }

    // form parameters
    char *keyForm_protect_content = NULL;
    char * valueForm_protect_content = 0;
    keyValuePair_t *keyPairForm_protect_content = 0;
    if (protect_content != NULL)
    {
        keyForm_protect_content = strdup("protect_content");
        valueForm_protect_content = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_protect_content, MAX_NUMBER_LENGTH, "%d", *protect_content);
        keyPairForm_protect_content = keyValuePair_create(keyForm_protect_content,valueForm_protect_content);
        list_addElement(localVarFormParameters,keyPairForm_protect_content);
    }

    // form parameters
    char *keyForm_allow_paid_broadcast = NULL;
    char * valueForm_allow_paid_broadcast = 0;
    keyValuePair_t *keyPairForm_allow_paid_broadcast = 0;
    if (allow_paid_broadcast != NULL)
    {
        keyForm_allow_paid_broadcast = strdup("allow_paid_broadcast");
        valueForm_allow_paid_broadcast = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_allow_paid_broadcast, MAX_NUMBER_LENGTH, "%d", *allow_paid_broadcast);
        keyPairForm_allow_paid_broadcast = keyValuePair_create(keyForm_allow_paid_broadcast,valueForm_allow_paid_broadcast);
        list_addElement(localVarFormParameters,keyPairForm_allow_paid_broadcast);
    }

    // form parameters
    char *keyForm_message_effect_id = NULL;
    char * valueForm_message_effect_id = 0;
    keyValuePair_t *keyPairForm_message_effect_id = 0;
    if (message_effect_id != NULL)
    {
        keyForm_message_effect_id = strdup("message_effect_id");
        valueForm_message_effect_id = strdup((message_effect_id));
        keyPairForm_message_effect_id = keyValuePair_create(keyForm_message_effect_id,valueForm_message_effect_id);
        list_addElement(localVarFormParameters,keyPairForm_message_effect_id);
    }

    // form parameters
    char *keyForm_reply_parameters = NULL;
    reply_parameters_t * valueForm_reply_parameters = 0;
    keyValuePair_t *keyPairForm_reply_parameters = 0;
    if (reply_parameters != NULL)
    {
        keyForm_reply_parameters = strdup("reply_parameters");
        valueForm_reply_parameters = (reply_parameters);
        keyPairForm_reply_parameters = keyValuePair_create(keyForm_reply_parameters,&valueForm_reply_parameters);
        list_addElement(localVarFormParameters,keyPairForm_reply_parameters);
    }

    // form parameters
    char *keyForm_reply_markup = NULL;
    post_send_message_request_reply_markup_t * valueForm_reply_markup = 0;
    keyValuePair_t *keyPairForm_reply_markup = 0;
    if (reply_markup != NULL)
    {
        keyForm_reply_markup = strdup("reply_markup");
        valueForm_reply_markup = (reply_markup);
        keyPairForm_reply_markup = keyValuePair_create(keyForm_reply_markup,&valueForm_reply_markup);
        list_addElement(localVarFormParameters,keyPairForm_reply_markup);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_send_message_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_send_message_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_business_connection_id) {
        free(keyForm_business_connection_id);
        keyForm_business_connection_id = NULL;
    }
    if (valueForm_business_connection_id) {
        free(valueForm_business_connection_id);
        valueForm_business_connection_id = NULL;
    }
    free(keyPairForm_business_connection_id);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_message_thread_id) {
        free(keyForm_message_thread_id);
        keyForm_message_thread_id = NULL;
    }
    free(keyPairForm_message_thread_id);
    if (keyForm_animation) {
        free(keyForm_animation);
        keyForm_animation = NULL;
    }
    free(keyPairForm_animation);
    if (keyForm_duration) {
        free(keyForm_duration);
        keyForm_duration = NULL;
    }
    free(keyPairForm_duration);
    if (keyForm_width) {
        free(keyForm_width);
        keyForm_width = NULL;
    }
    free(keyPairForm_width);
    if (keyForm_height) {
        free(keyForm_height);
        keyForm_height = NULL;
    }
    free(keyPairForm_height);
    if (keyForm_thumbnail) {
        free(keyForm_thumbnail);
        keyForm_thumbnail = NULL;
    }
    free(keyPairForm_thumbnail);
    if (keyForm_caption) {
        free(keyForm_caption);
        keyForm_caption = NULL;
    }
    if (valueForm_caption) {
        free(valueForm_caption);
        valueForm_caption = NULL;
    }
    free(keyPairForm_caption);
    if (keyForm_parse_mode) {
        free(keyForm_parse_mode);
        keyForm_parse_mode = NULL;
    }
    if (valueForm_parse_mode) {
        free(valueForm_parse_mode);
        valueForm_parse_mode = NULL;
    }
    free(keyPairForm_parse_mode);
    if (keyForm_caption_entities) {
        free(keyForm_caption_entities);
        keyForm_caption_entities = NULL;
    }
    free(keyPairForm_caption_entities);
    if (keyForm_show_caption_above_media) {
        free(keyForm_show_caption_above_media);
        keyForm_show_caption_above_media = NULL;
    }
    free(keyPairForm_show_caption_above_media);
    if (keyForm_has_spoiler) {
        free(keyForm_has_spoiler);
        keyForm_has_spoiler = NULL;
    }
    free(keyPairForm_has_spoiler);
    if (keyForm_disable_notification) {
        free(keyForm_disable_notification);
        keyForm_disable_notification = NULL;
    }
    free(keyPairForm_disable_notification);
    if (keyForm_protect_content) {
        free(keyForm_protect_content);
        keyForm_protect_content = NULL;
    }
    free(keyPairForm_protect_content);
    if (keyForm_allow_paid_broadcast) {
        free(keyForm_allow_paid_broadcast);
        keyForm_allow_paid_broadcast = NULL;
    }
    free(keyPairForm_allow_paid_broadcast);
    if (keyForm_message_effect_id) {
        free(keyForm_message_effect_id);
        keyForm_message_effect_id = NULL;
    }
    if (valueForm_message_effect_id) {
        free(valueForm_message_effect_id);
        valueForm_message_effect_id = NULL;
    }
    free(keyPairForm_message_effect_id);
    if (keyForm_reply_parameters) {
        free(keyForm_reply_parameters);
        keyForm_reply_parameters = NULL;
    }
    free(keyPairForm_reply_parameters);
    if (keyForm_reply_markup) {
        free(keyForm_reply_markup);
        keyForm_reply_markup = NULL;
    }
    free(keyPairForm_reply_markup);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// sendAudio
//
// Use this method to send audio files, if you want Telegram clients to display them in the music player. Your audio must be in the .MP3 or .M4A format. On success, the sent [Message](https://core.telegram.org/bots/api/#message) is returned. Bots can currently send audio files of up to 50 MB in size, this limit may be changed in the future.  For sending voice messages, use the [sendVoice](https://core.telegram.org/bots/api/#sendvoice) method instead.
//
post_send_message_200_response_t*
DefaultAPI_postSendAudio(apiClient_t *apiClient, post_send_message_request_chat_id_t *chat_id, post_send_audio_request_audio_t *audio, char *business_connection_id, int *message_thread_id, char *caption, char *parse_mode, list_t *caption_entities, int *duration, char *performer, char *title, post_send_audio_request_thumbnail_t *thumbnail, int *disable_notification, int *protect_content, int *allow_paid_broadcast, char *message_effect_id, reply_parameters_t *reply_parameters, post_send_message_request_reply_markup_t *reply_markup)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/sendAudio");





    // form parameters
    char *keyForm_business_connection_id = NULL;
    char * valueForm_business_connection_id = 0;
    keyValuePair_t *keyPairForm_business_connection_id = 0;
    if (business_connection_id != NULL)
    {
        keyForm_business_connection_id = strdup("business_connection_id");
        valueForm_business_connection_id = strdup((business_connection_id));
        keyPairForm_business_connection_id = keyValuePair_create(keyForm_business_connection_id,valueForm_business_connection_id);
        list_addElement(localVarFormParameters,keyPairForm_business_connection_id);
    }

    // form parameters
    char *keyForm_chat_id = NULL;
    post_send_message_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_message_thread_id = NULL;
    int valueForm_message_thread_id = 0;
    keyValuePair_t *keyPairForm_message_thread_id = 0;
    if (message_thread_id != NULL)
    {
        keyForm_message_thread_id = strdup("message_thread_id");
        valueForm_message_thread_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_message_thread_id, MAX_NUMBER_LENGTH, "%d", *message_thread_id);
        keyPairForm_message_thread_id = keyValuePair_create(keyForm_message_thread_id,&valueForm_message_thread_id);
        list_addElement(localVarFormParameters,keyPairForm_message_thread_id);
    }

    // form parameters
    char *keyForm_audio = NULL;
    post_send_audio_request_audio_t * valueForm_audio = 0;
    keyValuePair_t *keyPairForm_audio = 0;
    if (audio != NULL)
    {
        keyForm_audio = strdup("audio");
        valueForm_audio = (audio);
        keyPairForm_audio = keyValuePair_create(keyForm_audio,&valueForm_audio);
        list_addElement(localVarFormParameters,keyPairForm_audio);
    }

    // form parameters
    char *keyForm_caption = NULL;
    char * valueForm_caption = 0;
    keyValuePair_t *keyPairForm_caption = 0;
    if (caption != NULL)
    {
        keyForm_caption = strdup("caption");
        valueForm_caption = strdup((caption));
        keyPairForm_caption = keyValuePair_create(keyForm_caption,valueForm_caption);
        list_addElement(localVarFormParameters,keyPairForm_caption);
    }

    // form parameters
    char *keyForm_parse_mode = NULL;
    char * valueForm_parse_mode = 0;
    keyValuePair_t *keyPairForm_parse_mode = 0;
    if (parse_mode != NULL)
    {
        keyForm_parse_mode = strdup("parse_mode");
        valueForm_parse_mode = strdup((parse_mode));
        keyPairForm_parse_mode = keyValuePair_create(keyForm_parse_mode,valueForm_parse_mode);
        list_addElement(localVarFormParameters,keyPairForm_parse_mode);
    }

    // form parameters
    char *keyForm_caption_entities = NULL;
     valueForm_caption_entities = 0;
    keyValuePair_t *keyPairForm_caption_entities = 0;
    if (caption_entities != NULL)
    {
        keyForm_caption_entities = strdup("caption_entities");
        valueForm_caption_entities = (caption_entities);
        keyPairForm_caption_entities = keyValuePair_create(keyForm_caption_entities,&valueForm_caption_entities);
        list_addElement(localVarFormParameters,keyPairForm_caption_entities);
    }

    // form parameters
    char *keyForm_duration = NULL;
    int valueForm_duration = 0;
    keyValuePair_t *keyPairForm_duration = 0;
    if (duration != NULL)
    {
        keyForm_duration = strdup("duration");
        valueForm_duration = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_duration, MAX_NUMBER_LENGTH, "%d", *duration);
        keyPairForm_duration = keyValuePair_create(keyForm_duration,&valueForm_duration);
        list_addElement(localVarFormParameters,keyPairForm_duration);
    }

    // form parameters
    char *keyForm_performer = NULL;
    char * valueForm_performer = 0;
    keyValuePair_t *keyPairForm_performer = 0;
    if (performer != NULL)
    {
        keyForm_performer = strdup("performer");
        valueForm_performer = strdup((performer));
        keyPairForm_performer = keyValuePair_create(keyForm_performer,valueForm_performer);
        list_addElement(localVarFormParameters,keyPairForm_performer);
    }

    // form parameters
    char *keyForm_title = NULL;
    char * valueForm_title = 0;
    keyValuePair_t *keyPairForm_title = 0;
    if (title != NULL)
    {
        keyForm_title = strdup("title");
        valueForm_title = strdup((title));
        keyPairForm_title = keyValuePair_create(keyForm_title,valueForm_title);
        list_addElement(localVarFormParameters,keyPairForm_title);
    }

    // form parameters
    char *keyForm_thumbnail = NULL;
    post_send_audio_request_thumbnail_t * valueForm_thumbnail = 0;
    keyValuePair_t *keyPairForm_thumbnail = 0;
    if (thumbnail != NULL)
    {
        keyForm_thumbnail = strdup("thumbnail");
        valueForm_thumbnail = (thumbnail);
        keyPairForm_thumbnail = keyValuePair_create(keyForm_thumbnail,&valueForm_thumbnail);
        list_addElement(localVarFormParameters,keyPairForm_thumbnail);
    }

    // form parameters
    char *keyForm_disable_notification = NULL;
    char * valueForm_disable_notification = 0;
    keyValuePair_t *keyPairForm_disable_notification = 0;
    if (disable_notification != NULL)
    {
        keyForm_disable_notification = strdup("disable_notification");
        valueForm_disable_notification = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_disable_notification, MAX_NUMBER_LENGTH, "%d", *disable_notification);
        keyPairForm_disable_notification = keyValuePair_create(keyForm_disable_notification,valueForm_disable_notification);
        list_addElement(localVarFormParameters,keyPairForm_disable_notification);
    }

    // form parameters
    char *keyForm_protect_content = NULL;
    char * valueForm_protect_content = 0;
    keyValuePair_t *keyPairForm_protect_content = 0;
    if (protect_content != NULL)
    {
        keyForm_protect_content = strdup("protect_content");
        valueForm_protect_content = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_protect_content, MAX_NUMBER_LENGTH, "%d", *protect_content);
        keyPairForm_protect_content = keyValuePair_create(keyForm_protect_content,valueForm_protect_content);
        list_addElement(localVarFormParameters,keyPairForm_protect_content);
    }

    // form parameters
    char *keyForm_allow_paid_broadcast = NULL;
    char * valueForm_allow_paid_broadcast = 0;
    keyValuePair_t *keyPairForm_allow_paid_broadcast = 0;
    if (allow_paid_broadcast != NULL)
    {
        keyForm_allow_paid_broadcast = strdup("allow_paid_broadcast");
        valueForm_allow_paid_broadcast = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_allow_paid_broadcast, MAX_NUMBER_LENGTH, "%d", *allow_paid_broadcast);
        keyPairForm_allow_paid_broadcast = keyValuePair_create(keyForm_allow_paid_broadcast,valueForm_allow_paid_broadcast);
        list_addElement(localVarFormParameters,keyPairForm_allow_paid_broadcast);
    }

    // form parameters
    char *keyForm_message_effect_id = NULL;
    char * valueForm_message_effect_id = 0;
    keyValuePair_t *keyPairForm_message_effect_id = 0;
    if (message_effect_id != NULL)
    {
        keyForm_message_effect_id = strdup("message_effect_id");
        valueForm_message_effect_id = strdup((message_effect_id));
        keyPairForm_message_effect_id = keyValuePair_create(keyForm_message_effect_id,valueForm_message_effect_id);
        list_addElement(localVarFormParameters,keyPairForm_message_effect_id);
    }

    // form parameters
    char *keyForm_reply_parameters = NULL;
    reply_parameters_t * valueForm_reply_parameters = 0;
    keyValuePair_t *keyPairForm_reply_parameters = 0;
    if (reply_parameters != NULL)
    {
        keyForm_reply_parameters = strdup("reply_parameters");
        valueForm_reply_parameters = (reply_parameters);
        keyPairForm_reply_parameters = keyValuePair_create(keyForm_reply_parameters,&valueForm_reply_parameters);
        list_addElement(localVarFormParameters,keyPairForm_reply_parameters);
    }

    // form parameters
    char *keyForm_reply_markup = NULL;
    post_send_message_request_reply_markup_t * valueForm_reply_markup = 0;
    keyValuePair_t *keyPairForm_reply_markup = 0;
    if (reply_markup != NULL)
    {
        keyForm_reply_markup = strdup("reply_markup");
        valueForm_reply_markup = (reply_markup);
        keyPairForm_reply_markup = keyValuePair_create(keyForm_reply_markup,&valueForm_reply_markup);
        list_addElement(localVarFormParameters,keyPairForm_reply_markup);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_send_message_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_send_message_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_business_connection_id) {
        free(keyForm_business_connection_id);
        keyForm_business_connection_id = NULL;
    }
    if (valueForm_business_connection_id) {
        free(valueForm_business_connection_id);
        valueForm_business_connection_id = NULL;
    }
    free(keyPairForm_business_connection_id);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_message_thread_id) {
        free(keyForm_message_thread_id);
        keyForm_message_thread_id = NULL;
    }
    free(keyPairForm_message_thread_id);
    if (keyForm_audio) {
        free(keyForm_audio);
        keyForm_audio = NULL;
    }
    free(keyPairForm_audio);
    if (keyForm_caption) {
        free(keyForm_caption);
        keyForm_caption = NULL;
    }
    if (valueForm_caption) {
        free(valueForm_caption);
        valueForm_caption = NULL;
    }
    free(keyPairForm_caption);
    if (keyForm_parse_mode) {
        free(keyForm_parse_mode);
        keyForm_parse_mode = NULL;
    }
    if (valueForm_parse_mode) {
        free(valueForm_parse_mode);
        valueForm_parse_mode = NULL;
    }
    free(keyPairForm_parse_mode);
    if (keyForm_caption_entities) {
        free(keyForm_caption_entities);
        keyForm_caption_entities = NULL;
    }
    free(keyPairForm_caption_entities);
    if (keyForm_duration) {
        free(keyForm_duration);
        keyForm_duration = NULL;
    }
    free(keyPairForm_duration);
    if (keyForm_performer) {
        free(keyForm_performer);
        keyForm_performer = NULL;
    }
    if (valueForm_performer) {
        free(valueForm_performer);
        valueForm_performer = NULL;
    }
    free(keyPairForm_performer);
    if (keyForm_title) {
        free(keyForm_title);
        keyForm_title = NULL;
    }
    if (valueForm_title) {
        free(valueForm_title);
        valueForm_title = NULL;
    }
    free(keyPairForm_title);
    if (keyForm_thumbnail) {
        free(keyForm_thumbnail);
        keyForm_thumbnail = NULL;
    }
    free(keyPairForm_thumbnail);
    if (keyForm_disable_notification) {
        free(keyForm_disable_notification);
        keyForm_disable_notification = NULL;
    }
    free(keyPairForm_disable_notification);
    if (keyForm_protect_content) {
        free(keyForm_protect_content);
        keyForm_protect_content = NULL;
    }
    free(keyPairForm_protect_content);
    if (keyForm_allow_paid_broadcast) {
        free(keyForm_allow_paid_broadcast);
        keyForm_allow_paid_broadcast = NULL;
    }
    free(keyPairForm_allow_paid_broadcast);
    if (keyForm_message_effect_id) {
        free(keyForm_message_effect_id);
        keyForm_message_effect_id = NULL;
    }
    if (valueForm_message_effect_id) {
        free(valueForm_message_effect_id);
        valueForm_message_effect_id = NULL;
    }
    free(keyPairForm_message_effect_id);
    if (keyForm_reply_parameters) {
        free(keyForm_reply_parameters);
        keyForm_reply_parameters = NULL;
    }
    free(keyPairForm_reply_parameters);
    if (keyForm_reply_markup) {
        free(keyForm_reply_markup);
        keyForm_reply_markup = NULL;
    }
    free(keyPairForm_reply_markup);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// sendChatAction
//
// Use this method when you need to tell the user that something is happening on the bot's side. The status is set for 5 seconds or less (when a message arrives from your bot, Telegram clients clear its typing status). Returns *True* on success.  Example: The [ImageBot](https://t.me/imagebot) needs some time to process a request and upload the image. Instead of sending a text message along the lines of “Retrieving image, please wait…”, the bot may use [sendChatAction](https://core.telegram.org/bots/api/#sendchataction) with *action* = *upload\\_photo*. The user will see a “sending photo” status for the bot.  We only recommend using this method when a response from the bot will take a **noticeable** amount of time to arrive.
//
post_set_webhook_200_response_t*
DefaultAPI_postSendChatAction(apiClient_t *apiClient, post_send_message_request_chat_id_t *chat_id, telegram_bot_api_postSendChatAction_action_e action, char *business_connection_id, int *message_thread_id)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/sendChatAction");





    // form parameters
    char *keyForm_business_connection_id = NULL;
    char * valueForm_business_connection_id = 0;
    keyValuePair_t *keyPairForm_business_connection_id = 0;
    if (business_connection_id != NULL)
    {
        keyForm_business_connection_id = strdup("business_connection_id");
        valueForm_business_connection_id = strdup((business_connection_id));
        keyPairForm_business_connection_id = keyValuePair_create(keyForm_business_connection_id,valueForm_business_connection_id);
        list_addElement(localVarFormParameters,keyPairForm_business_connection_id);
    }

    // form parameters
    char *keyForm_chat_id = NULL;
    post_send_message_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_message_thread_id = NULL;
    int valueForm_message_thread_id = 0;
    keyValuePair_t *keyPairForm_message_thread_id = 0;
    if (message_thread_id != NULL)
    {
        keyForm_message_thread_id = strdup("message_thread_id");
        valueForm_message_thread_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_message_thread_id, MAX_NUMBER_LENGTH, "%d", *message_thread_id);
        keyPairForm_message_thread_id = keyValuePair_create(keyForm_message_thread_id,&valueForm_message_thread_id);
        list_addElement(localVarFormParameters,keyPairForm_message_thread_id);
    }

    // form parameters
    char *keyForm_action = NULL;
    telegram_bot_api_postSendChatAction_action_e valueForm_action = 0;
    keyValuePair_t *keyPairForm_action = 0;
    if (action != 0)
    {
        keyForm_action = strdup("action");
        valueForm_action = (action);
        keyPairForm_action = keyValuePair_create(keyForm_action,(void *)valueForm_action);
        list_addElement(localVarFormParameters,keyPairForm_action);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_business_connection_id) {
        free(keyForm_business_connection_id);
        keyForm_business_connection_id = NULL;
    }
    if (valueForm_business_connection_id) {
        free(valueForm_business_connection_id);
        valueForm_business_connection_id = NULL;
    }
    free(keyPairForm_business_connection_id);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_message_thread_id) {
        free(keyForm_message_thread_id);
        keyForm_message_thread_id = NULL;
    }
    free(keyPairForm_message_thread_id);
    if (keyForm_action) {
        free(keyForm_action);
        keyForm_action = NULL;
    }
    if (valueForm_action) {
        valueForm_action = 0;
    }
    free(keyPairForm_action);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// sendContact
//
// Use this method to send phone contacts. On success, the sent [Message](https://core.telegram.org/bots/api/#message) is returned.
//
post_send_message_200_response_t*
DefaultAPI_postSendContact(apiClient_t *apiClient, post_send_message_request_chat_id_t *chat_id, char *phone_number, char *first_name, char *business_connection_id, int *message_thread_id, char *last_name, char *vcard, int *disable_notification, int *protect_content, int *allow_paid_broadcast, char *message_effect_id, reply_parameters_t *reply_parameters, post_send_message_request_reply_markup_t *reply_markup)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/sendContact");





    // form parameters
    char *keyForm_business_connection_id = NULL;
    char * valueForm_business_connection_id = 0;
    keyValuePair_t *keyPairForm_business_connection_id = 0;
    if (business_connection_id != NULL)
    {
        keyForm_business_connection_id = strdup("business_connection_id");
        valueForm_business_connection_id = strdup((business_connection_id));
        keyPairForm_business_connection_id = keyValuePair_create(keyForm_business_connection_id,valueForm_business_connection_id);
        list_addElement(localVarFormParameters,keyPairForm_business_connection_id);
    }

    // form parameters
    char *keyForm_chat_id = NULL;
    post_send_message_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_message_thread_id = NULL;
    int valueForm_message_thread_id = 0;
    keyValuePair_t *keyPairForm_message_thread_id = 0;
    if (message_thread_id != NULL)
    {
        keyForm_message_thread_id = strdup("message_thread_id");
        valueForm_message_thread_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_message_thread_id, MAX_NUMBER_LENGTH, "%d", *message_thread_id);
        keyPairForm_message_thread_id = keyValuePair_create(keyForm_message_thread_id,&valueForm_message_thread_id);
        list_addElement(localVarFormParameters,keyPairForm_message_thread_id);
    }

    // form parameters
    char *keyForm_phone_number = NULL;
    char * valueForm_phone_number = 0;
    keyValuePair_t *keyPairForm_phone_number = 0;
    if (phone_number != NULL)
    {
        keyForm_phone_number = strdup("phone_number");
        valueForm_phone_number = strdup((phone_number));
        keyPairForm_phone_number = keyValuePair_create(keyForm_phone_number,valueForm_phone_number);
        list_addElement(localVarFormParameters,keyPairForm_phone_number);
    }

    // form parameters
    char *keyForm_first_name = NULL;
    char * valueForm_first_name = 0;
    keyValuePair_t *keyPairForm_first_name = 0;
    if (first_name != NULL)
    {
        keyForm_first_name = strdup("first_name");
        valueForm_first_name = strdup((first_name));
        keyPairForm_first_name = keyValuePair_create(keyForm_first_name,valueForm_first_name);
        list_addElement(localVarFormParameters,keyPairForm_first_name);
    }

    // form parameters
    char *keyForm_last_name = NULL;
    char * valueForm_last_name = 0;
    keyValuePair_t *keyPairForm_last_name = 0;
    if (last_name != NULL)
    {
        keyForm_last_name = strdup("last_name");
        valueForm_last_name = strdup((last_name));
        keyPairForm_last_name = keyValuePair_create(keyForm_last_name,valueForm_last_name);
        list_addElement(localVarFormParameters,keyPairForm_last_name);
    }

    // form parameters
    char *keyForm_vcard = NULL;
    char * valueForm_vcard = 0;
    keyValuePair_t *keyPairForm_vcard = 0;
    if (vcard != NULL)
    {
        keyForm_vcard = strdup("vcard");
        valueForm_vcard = strdup((vcard));
        keyPairForm_vcard = keyValuePair_create(keyForm_vcard,valueForm_vcard);
        list_addElement(localVarFormParameters,keyPairForm_vcard);
    }

    // form parameters
    char *keyForm_disable_notification = NULL;
    char * valueForm_disable_notification = 0;
    keyValuePair_t *keyPairForm_disable_notification = 0;
    if (disable_notification != NULL)
    {
        keyForm_disable_notification = strdup("disable_notification");
        valueForm_disable_notification = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_disable_notification, MAX_NUMBER_LENGTH, "%d", *disable_notification);
        keyPairForm_disable_notification = keyValuePair_create(keyForm_disable_notification,valueForm_disable_notification);
        list_addElement(localVarFormParameters,keyPairForm_disable_notification);
    }

    // form parameters
    char *keyForm_protect_content = NULL;
    char * valueForm_protect_content = 0;
    keyValuePair_t *keyPairForm_protect_content = 0;
    if (protect_content != NULL)
    {
        keyForm_protect_content = strdup("protect_content");
        valueForm_protect_content = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_protect_content, MAX_NUMBER_LENGTH, "%d", *protect_content);
        keyPairForm_protect_content = keyValuePair_create(keyForm_protect_content,valueForm_protect_content);
        list_addElement(localVarFormParameters,keyPairForm_protect_content);
    }

    // form parameters
    char *keyForm_allow_paid_broadcast = NULL;
    char * valueForm_allow_paid_broadcast = 0;
    keyValuePair_t *keyPairForm_allow_paid_broadcast = 0;
    if (allow_paid_broadcast != NULL)
    {
        keyForm_allow_paid_broadcast = strdup("allow_paid_broadcast");
        valueForm_allow_paid_broadcast = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_allow_paid_broadcast, MAX_NUMBER_LENGTH, "%d", *allow_paid_broadcast);
        keyPairForm_allow_paid_broadcast = keyValuePair_create(keyForm_allow_paid_broadcast,valueForm_allow_paid_broadcast);
        list_addElement(localVarFormParameters,keyPairForm_allow_paid_broadcast);
    }

    // form parameters
    char *keyForm_message_effect_id = NULL;
    char * valueForm_message_effect_id = 0;
    keyValuePair_t *keyPairForm_message_effect_id = 0;
    if (message_effect_id != NULL)
    {
        keyForm_message_effect_id = strdup("message_effect_id");
        valueForm_message_effect_id = strdup((message_effect_id));
        keyPairForm_message_effect_id = keyValuePair_create(keyForm_message_effect_id,valueForm_message_effect_id);
        list_addElement(localVarFormParameters,keyPairForm_message_effect_id);
    }

    // form parameters
    char *keyForm_reply_parameters = NULL;
    reply_parameters_t * valueForm_reply_parameters = 0;
    keyValuePair_t *keyPairForm_reply_parameters = 0;
    if (reply_parameters != NULL)
    {
        keyForm_reply_parameters = strdup("reply_parameters");
        valueForm_reply_parameters = (reply_parameters);
        keyPairForm_reply_parameters = keyValuePair_create(keyForm_reply_parameters,&valueForm_reply_parameters);
        list_addElement(localVarFormParameters,keyPairForm_reply_parameters);
    }

    // form parameters
    char *keyForm_reply_markup = NULL;
    post_send_message_request_reply_markup_t * valueForm_reply_markup = 0;
    keyValuePair_t *keyPairForm_reply_markup = 0;
    if (reply_markup != NULL)
    {
        keyForm_reply_markup = strdup("reply_markup");
        valueForm_reply_markup = (reply_markup);
        keyPairForm_reply_markup = keyValuePair_create(keyForm_reply_markup,&valueForm_reply_markup);
        list_addElement(localVarFormParameters,keyPairForm_reply_markup);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_send_message_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_send_message_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_business_connection_id) {
        free(keyForm_business_connection_id);
        keyForm_business_connection_id = NULL;
    }
    if (valueForm_business_connection_id) {
        free(valueForm_business_connection_id);
        valueForm_business_connection_id = NULL;
    }
    free(keyPairForm_business_connection_id);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_message_thread_id) {
        free(keyForm_message_thread_id);
        keyForm_message_thread_id = NULL;
    }
    free(keyPairForm_message_thread_id);
    if (keyForm_phone_number) {
        free(keyForm_phone_number);
        keyForm_phone_number = NULL;
    }
    if (valueForm_phone_number) {
        free(valueForm_phone_number);
        valueForm_phone_number = NULL;
    }
    free(keyPairForm_phone_number);
    if (keyForm_first_name) {
        free(keyForm_first_name);
        keyForm_first_name = NULL;
    }
    if (valueForm_first_name) {
        free(valueForm_first_name);
        valueForm_first_name = NULL;
    }
    free(keyPairForm_first_name);
    if (keyForm_last_name) {
        free(keyForm_last_name);
        keyForm_last_name = NULL;
    }
    if (valueForm_last_name) {
        free(valueForm_last_name);
        valueForm_last_name = NULL;
    }
    free(keyPairForm_last_name);
    if (keyForm_vcard) {
        free(keyForm_vcard);
        keyForm_vcard = NULL;
    }
    if (valueForm_vcard) {
        free(valueForm_vcard);
        valueForm_vcard = NULL;
    }
    free(keyPairForm_vcard);
    if (keyForm_disable_notification) {
        free(keyForm_disable_notification);
        keyForm_disable_notification = NULL;
    }
    free(keyPairForm_disable_notification);
    if (keyForm_protect_content) {
        free(keyForm_protect_content);
        keyForm_protect_content = NULL;
    }
    free(keyPairForm_protect_content);
    if (keyForm_allow_paid_broadcast) {
        free(keyForm_allow_paid_broadcast);
        keyForm_allow_paid_broadcast = NULL;
    }
    free(keyPairForm_allow_paid_broadcast);
    if (keyForm_message_effect_id) {
        free(keyForm_message_effect_id);
        keyForm_message_effect_id = NULL;
    }
    if (valueForm_message_effect_id) {
        free(valueForm_message_effect_id);
        valueForm_message_effect_id = NULL;
    }
    free(keyPairForm_message_effect_id);
    if (keyForm_reply_parameters) {
        free(keyForm_reply_parameters);
        keyForm_reply_parameters = NULL;
    }
    free(keyPairForm_reply_parameters);
    if (keyForm_reply_markup) {
        free(keyForm_reply_markup);
        keyForm_reply_markup = NULL;
    }
    free(keyPairForm_reply_markup);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// sendDice
//
// Use this method to send an animated emoji that will display a random value. On success, the sent [Message](https://core.telegram.org/bots/api/#message) is returned.
//
post_send_message_200_response_t*
DefaultAPI_postSendDice(apiClient_t *apiClient, post_send_message_request_chat_id_t *chat_id, char *business_connection_id, int *message_thread_id, telegram_bot_api_postSendDice_emoji_e emoji, int *disable_notification, int *protect_content, int *allow_paid_broadcast, char *message_effect_id, reply_parameters_t *reply_parameters, post_send_message_request_reply_markup_t *reply_markup)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/sendDice");





    // form parameters
    char *keyForm_business_connection_id = NULL;
    char * valueForm_business_connection_id = 0;
    keyValuePair_t *keyPairForm_business_connection_id = 0;
    if (business_connection_id != NULL)
    {
        keyForm_business_connection_id = strdup("business_connection_id");
        valueForm_business_connection_id = strdup((business_connection_id));
        keyPairForm_business_connection_id = keyValuePair_create(keyForm_business_connection_id,valueForm_business_connection_id);
        list_addElement(localVarFormParameters,keyPairForm_business_connection_id);
    }

    // form parameters
    char *keyForm_chat_id = NULL;
    post_send_message_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_message_thread_id = NULL;
    int valueForm_message_thread_id = 0;
    keyValuePair_t *keyPairForm_message_thread_id = 0;
    if (message_thread_id != NULL)
    {
        keyForm_message_thread_id = strdup("message_thread_id");
        valueForm_message_thread_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_message_thread_id, MAX_NUMBER_LENGTH, "%d", *message_thread_id);
        keyPairForm_message_thread_id = keyValuePair_create(keyForm_message_thread_id,&valueForm_message_thread_id);
        list_addElement(localVarFormParameters,keyPairForm_message_thread_id);
    }

    // form parameters
    char *keyForm_emoji = NULL;
    telegram_bot_api_postSendDice_emoji_e valueForm_emoji = 0;
    keyValuePair_t *keyPairForm_emoji = 0;
    if (emoji != 0)
    {
        keyForm_emoji = strdup("emoji");
        valueForm_emoji = (emoji);
        keyPairForm_emoji = keyValuePair_create(keyForm_emoji,(void *)valueForm_emoji);
        list_addElement(localVarFormParameters,keyPairForm_emoji);
    }

    // form parameters
    char *keyForm_disable_notification = NULL;
    char * valueForm_disable_notification = 0;
    keyValuePair_t *keyPairForm_disable_notification = 0;
    if (disable_notification != NULL)
    {
        keyForm_disable_notification = strdup("disable_notification");
        valueForm_disable_notification = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_disable_notification, MAX_NUMBER_LENGTH, "%d", *disable_notification);
        keyPairForm_disable_notification = keyValuePair_create(keyForm_disable_notification,valueForm_disable_notification);
        list_addElement(localVarFormParameters,keyPairForm_disable_notification);
    }

    // form parameters
    char *keyForm_protect_content = NULL;
    char * valueForm_protect_content = 0;
    keyValuePair_t *keyPairForm_protect_content = 0;
    if (protect_content != NULL)
    {
        keyForm_protect_content = strdup("protect_content");
        valueForm_protect_content = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_protect_content, MAX_NUMBER_LENGTH, "%d", *protect_content);
        keyPairForm_protect_content = keyValuePair_create(keyForm_protect_content,valueForm_protect_content);
        list_addElement(localVarFormParameters,keyPairForm_protect_content);
    }

    // form parameters
    char *keyForm_allow_paid_broadcast = NULL;
    char * valueForm_allow_paid_broadcast = 0;
    keyValuePair_t *keyPairForm_allow_paid_broadcast = 0;
    if (allow_paid_broadcast != NULL)
    {
        keyForm_allow_paid_broadcast = strdup("allow_paid_broadcast");
        valueForm_allow_paid_broadcast = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_allow_paid_broadcast, MAX_NUMBER_LENGTH, "%d", *allow_paid_broadcast);
        keyPairForm_allow_paid_broadcast = keyValuePair_create(keyForm_allow_paid_broadcast,valueForm_allow_paid_broadcast);
        list_addElement(localVarFormParameters,keyPairForm_allow_paid_broadcast);
    }

    // form parameters
    char *keyForm_message_effect_id = NULL;
    char * valueForm_message_effect_id = 0;
    keyValuePair_t *keyPairForm_message_effect_id = 0;
    if (message_effect_id != NULL)
    {
        keyForm_message_effect_id = strdup("message_effect_id");
        valueForm_message_effect_id = strdup((message_effect_id));
        keyPairForm_message_effect_id = keyValuePair_create(keyForm_message_effect_id,valueForm_message_effect_id);
        list_addElement(localVarFormParameters,keyPairForm_message_effect_id);
    }

    // form parameters
    char *keyForm_reply_parameters = NULL;
    reply_parameters_t * valueForm_reply_parameters = 0;
    keyValuePair_t *keyPairForm_reply_parameters = 0;
    if (reply_parameters != NULL)
    {
        keyForm_reply_parameters = strdup("reply_parameters");
        valueForm_reply_parameters = (reply_parameters);
        keyPairForm_reply_parameters = keyValuePair_create(keyForm_reply_parameters,&valueForm_reply_parameters);
        list_addElement(localVarFormParameters,keyPairForm_reply_parameters);
    }

    // form parameters
    char *keyForm_reply_markup = NULL;
    post_send_message_request_reply_markup_t * valueForm_reply_markup = 0;
    keyValuePair_t *keyPairForm_reply_markup = 0;
    if (reply_markup != NULL)
    {
        keyForm_reply_markup = strdup("reply_markup");
        valueForm_reply_markup = (reply_markup);
        keyPairForm_reply_markup = keyValuePair_create(keyForm_reply_markup,&valueForm_reply_markup);
        list_addElement(localVarFormParameters,keyPairForm_reply_markup);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_send_message_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_send_message_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_business_connection_id) {
        free(keyForm_business_connection_id);
        keyForm_business_connection_id = NULL;
    }
    if (valueForm_business_connection_id) {
        free(valueForm_business_connection_id);
        valueForm_business_connection_id = NULL;
    }
    free(keyPairForm_business_connection_id);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_message_thread_id) {
        free(keyForm_message_thread_id);
        keyForm_message_thread_id = NULL;
    }
    free(keyPairForm_message_thread_id);
    if (keyForm_emoji) {
        free(keyForm_emoji);
        keyForm_emoji = NULL;
    }
    if (valueForm_emoji) {
        valueForm_emoji = 0;
    }
    free(keyPairForm_emoji);
    if (keyForm_disable_notification) {
        free(keyForm_disable_notification);
        keyForm_disable_notification = NULL;
    }
    free(keyPairForm_disable_notification);
    if (keyForm_protect_content) {
        free(keyForm_protect_content);
        keyForm_protect_content = NULL;
    }
    free(keyPairForm_protect_content);
    if (keyForm_allow_paid_broadcast) {
        free(keyForm_allow_paid_broadcast);
        keyForm_allow_paid_broadcast = NULL;
    }
    free(keyPairForm_allow_paid_broadcast);
    if (keyForm_message_effect_id) {
        free(keyForm_message_effect_id);
        keyForm_message_effect_id = NULL;
    }
    if (valueForm_message_effect_id) {
        free(valueForm_message_effect_id);
        valueForm_message_effect_id = NULL;
    }
    free(keyPairForm_message_effect_id);
    if (keyForm_reply_parameters) {
        free(keyForm_reply_parameters);
        keyForm_reply_parameters = NULL;
    }
    free(keyPairForm_reply_parameters);
    if (keyForm_reply_markup) {
        free(keyForm_reply_markup);
        keyForm_reply_markup = NULL;
    }
    free(keyPairForm_reply_markup);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// sendDocument
//
// Use this method to send general files. On success, the sent [Message](https://core.telegram.org/bots/api/#message) is returned. Bots can currently send files of any type of up to 50 MB in size, this limit may be changed in the future.
//
post_send_message_200_response_t*
DefaultAPI_postSendDocument(apiClient_t *apiClient, post_send_message_request_chat_id_t *chat_id, post_send_document_request_document_t *document, char *business_connection_id, int *message_thread_id, post_send_audio_request_thumbnail_t *thumbnail, char *caption, char *parse_mode, list_t *caption_entities, int *disable_content_type_detection, int *disable_notification, int *protect_content, int *allow_paid_broadcast, char *message_effect_id, reply_parameters_t *reply_parameters, post_send_message_request_reply_markup_t *reply_markup)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/sendDocument");





    // form parameters
    char *keyForm_business_connection_id = NULL;
    char * valueForm_business_connection_id = 0;
    keyValuePair_t *keyPairForm_business_connection_id = 0;
    if (business_connection_id != NULL)
    {
        keyForm_business_connection_id = strdup("business_connection_id");
        valueForm_business_connection_id = strdup((business_connection_id));
        keyPairForm_business_connection_id = keyValuePair_create(keyForm_business_connection_id,valueForm_business_connection_id);
        list_addElement(localVarFormParameters,keyPairForm_business_connection_id);
    }

    // form parameters
    char *keyForm_chat_id = NULL;
    post_send_message_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_message_thread_id = NULL;
    int valueForm_message_thread_id = 0;
    keyValuePair_t *keyPairForm_message_thread_id = 0;
    if (message_thread_id != NULL)
    {
        keyForm_message_thread_id = strdup("message_thread_id");
        valueForm_message_thread_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_message_thread_id, MAX_NUMBER_LENGTH, "%d", *message_thread_id);
        keyPairForm_message_thread_id = keyValuePair_create(keyForm_message_thread_id,&valueForm_message_thread_id);
        list_addElement(localVarFormParameters,keyPairForm_message_thread_id);
    }

    // form parameters
    char *keyForm_document = NULL;
    post_send_document_request_document_t * valueForm_document = 0;
    keyValuePair_t *keyPairForm_document = 0;
    if (document != NULL)
    {
        keyForm_document = strdup("document");
        valueForm_document = (document);
        keyPairForm_document = keyValuePair_create(keyForm_document,&valueForm_document);
        list_addElement(localVarFormParameters,keyPairForm_document);
    }

    // form parameters
    char *keyForm_thumbnail = NULL;
    post_send_audio_request_thumbnail_t * valueForm_thumbnail = 0;
    keyValuePair_t *keyPairForm_thumbnail = 0;
    if (thumbnail != NULL)
    {
        keyForm_thumbnail = strdup("thumbnail");
        valueForm_thumbnail = (thumbnail);
        keyPairForm_thumbnail = keyValuePair_create(keyForm_thumbnail,&valueForm_thumbnail);
        list_addElement(localVarFormParameters,keyPairForm_thumbnail);
    }

    // form parameters
    char *keyForm_caption = NULL;
    char * valueForm_caption = 0;
    keyValuePair_t *keyPairForm_caption = 0;
    if (caption != NULL)
    {
        keyForm_caption = strdup("caption");
        valueForm_caption = strdup((caption));
        keyPairForm_caption = keyValuePair_create(keyForm_caption,valueForm_caption);
        list_addElement(localVarFormParameters,keyPairForm_caption);
    }

    // form parameters
    char *keyForm_parse_mode = NULL;
    char * valueForm_parse_mode = 0;
    keyValuePair_t *keyPairForm_parse_mode = 0;
    if (parse_mode != NULL)
    {
        keyForm_parse_mode = strdup("parse_mode");
        valueForm_parse_mode = strdup((parse_mode));
        keyPairForm_parse_mode = keyValuePair_create(keyForm_parse_mode,valueForm_parse_mode);
        list_addElement(localVarFormParameters,keyPairForm_parse_mode);
    }

    // form parameters
    char *keyForm_caption_entities = NULL;
     valueForm_caption_entities = 0;
    keyValuePair_t *keyPairForm_caption_entities = 0;
    if (caption_entities != NULL)
    {
        keyForm_caption_entities = strdup("caption_entities");
        valueForm_caption_entities = (caption_entities);
        keyPairForm_caption_entities = keyValuePair_create(keyForm_caption_entities,&valueForm_caption_entities);
        list_addElement(localVarFormParameters,keyPairForm_caption_entities);
    }

    // form parameters
    char *keyForm_disable_content_type_detection = NULL;
    char * valueForm_disable_content_type_detection = 0;
    keyValuePair_t *keyPairForm_disable_content_type_detection = 0;
    if (disable_content_type_detection != NULL)
    {
        keyForm_disable_content_type_detection = strdup("disable_content_type_detection");
        valueForm_disable_content_type_detection = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_disable_content_type_detection, MAX_NUMBER_LENGTH, "%d", *disable_content_type_detection);
        keyPairForm_disable_content_type_detection = keyValuePair_create(keyForm_disable_content_type_detection,valueForm_disable_content_type_detection);
        list_addElement(localVarFormParameters,keyPairForm_disable_content_type_detection);
    }

    // form parameters
    char *keyForm_disable_notification = NULL;
    char * valueForm_disable_notification = 0;
    keyValuePair_t *keyPairForm_disable_notification = 0;
    if (disable_notification != NULL)
    {
        keyForm_disable_notification = strdup("disable_notification");
        valueForm_disable_notification = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_disable_notification, MAX_NUMBER_LENGTH, "%d", *disable_notification);
        keyPairForm_disable_notification = keyValuePair_create(keyForm_disable_notification,valueForm_disable_notification);
        list_addElement(localVarFormParameters,keyPairForm_disable_notification);
    }

    // form parameters
    char *keyForm_protect_content = NULL;
    char * valueForm_protect_content = 0;
    keyValuePair_t *keyPairForm_protect_content = 0;
    if (protect_content != NULL)
    {
        keyForm_protect_content = strdup("protect_content");
        valueForm_protect_content = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_protect_content, MAX_NUMBER_LENGTH, "%d", *protect_content);
        keyPairForm_protect_content = keyValuePair_create(keyForm_protect_content,valueForm_protect_content);
        list_addElement(localVarFormParameters,keyPairForm_protect_content);
    }

    // form parameters
    char *keyForm_allow_paid_broadcast = NULL;
    char * valueForm_allow_paid_broadcast = 0;
    keyValuePair_t *keyPairForm_allow_paid_broadcast = 0;
    if (allow_paid_broadcast != NULL)
    {
        keyForm_allow_paid_broadcast = strdup("allow_paid_broadcast");
        valueForm_allow_paid_broadcast = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_allow_paid_broadcast, MAX_NUMBER_LENGTH, "%d", *allow_paid_broadcast);
        keyPairForm_allow_paid_broadcast = keyValuePair_create(keyForm_allow_paid_broadcast,valueForm_allow_paid_broadcast);
        list_addElement(localVarFormParameters,keyPairForm_allow_paid_broadcast);
    }

    // form parameters
    char *keyForm_message_effect_id = NULL;
    char * valueForm_message_effect_id = 0;
    keyValuePair_t *keyPairForm_message_effect_id = 0;
    if (message_effect_id != NULL)
    {
        keyForm_message_effect_id = strdup("message_effect_id");
        valueForm_message_effect_id = strdup((message_effect_id));
        keyPairForm_message_effect_id = keyValuePair_create(keyForm_message_effect_id,valueForm_message_effect_id);
        list_addElement(localVarFormParameters,keyPairForm_message_effect_id);
    }

    // form parameters
    char *keyForm_reply_parameters = NULL;
    reply_parameters_t * valueForm_reply_parameters = 0;
    keyValuePair_t *keyPairForm_reply_parameters = 0;
    if (reply_parameters != NULL)
    {
        keyForm_reply_parameters = strdup("reply_parameters");
        valueForm_reply_parameters = (reply_parameters);
        keyPairForm_reply_parameters = keyValuePair_create(keyForm_reply_parameters,&valueForm_reply_parameters);
        list_addElement(localVarFormParameters,keyPairForm_reply_parameters);
    }

    // form parameters
    char *keyForm_reply_markup = NULL;
    post_send_message_request_reply_markup_t * valueForm_reply_markup = 0;
    keyValuePair_t *keyPairForm_reply_markup = 0;
    if (reply_markup != NULL)
    {
        keyForm_reply_markup = strdup("reply_markup");
        valueForm_reply_markup = (reply_markup);
        keyPairForm_reply_markup = keyValuePair_create(keyForm_reply_markup,&valueForm_reply_markup);
        list_addElement(localVarFormParameters,keyPairForm_reply_markup);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_send_message_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_send_message_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_business_connection_id) {
        free(keyForm_business_connection_id);
        keyForm_business_connection_id = NULL;
    }
    if (valueForm_business_connection_id) {
        free(valueForm_business_connection_id);
        valueForm_business_connection_id = NULL;
    }
    free(keyPairForm_business_connection_id);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_message_thread_id) {
        free(keyForm_message_thread_id);
        keyForm_message_thread_id = NULL;
    }
    free(keyPairForm_message_thread_id);
    if (keyForm_document) {
        free(keyForm_document);
        keyForm_document = NULL;
    }
    free(keyPairForm_document);
    if (keyForm_thumbnail) {
        free(keyForm_thumbnail);
        keyForm_thumbnail = NULL;
    }
    free(keyPairForm_thumbnail);
    if (keyForm_caption) {
        free(keyForm_caption);
        keyForm_caption = NULL;
    }
    if (valueForm_caption) {
        free(valueForm_caption);
        valueForm_caption = NULL;
    }
    free(keyPairForm_caption);
    if (keyForm_parse_mode) {
        free(keyForm_parse_mode);
        keyForm_parse_mode = NULL;
    }
    if (valueForm_parse_mode) {
        free(valueForm_parse_mode);
        valueForm_parse_mode = NULL;
    }
    free(keyPairForm_parse_mode);
    if (keyForm_caption_entities) {
        free(keyForm_caption_entities);
        keyForm_caption_entities = NULL;
    }
    free(keyPairForm_caption_entities);
    if (keyForm_disable_content_type_detection) {
        free(keyForm_disable_content_type_detection);
        keyForm_disable_content_type_detection = NULL;
    }
    free(keyPairForm_disable_content_type_detection);
    if (keyForm_disable_notification) {
        free(keyForm_disable_notification);
        keyForm_disable_notification = NULL;
    }
    free(keyPairForm_disable_notification);
    if (keyForm_protect_content) {
        free(keyForm_protect_content);
        keyForm_protect_content = NULL;
    }
    free(keyPairForm_protect_content);
    if (keyForm_allow_paid_broadcast) {
        free(keyForm_allow_paid_broadcast);
        keyForm_allow_paid_broadcast = NULL;
    }
    free(keyPairForm_allow_paid_broadcast);
    if (keyForm_message_effect_id) {
        free(keyForm_message_effect_id);
        keyForm_message_effect_id = NULL;
    }
    if (valueForm_message_effect_id) {
        free(valueForm_message_effect_id);
        valueForm_message_effect_id = NULL;
    }
    free(keyPairForm_message_effect_id);
    if (keyForm_reply_parameters) {
        free(keyForm_reply_parameters);
        keyForm_reply_parameters = NULL;
    }
    free(keyPairForm_reply_parameters);
    if (keyForm_reply_markup) {
        free(keyForm_reply_markup);
        keyForm_reply_markup = NULL;
    }
    free(keyPairForm_reply_markup);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// sendGame
//
// Use this method to send a game. On success, the sent [Message](https://core.telegram.org/bots/api/#message) is returned.
//
post_send_message_200_response_t*
DefaultAPI_postSendGame(apiClient_t *apiClient, int *chat_id, char *game_short_name, char *business_connection_id, int *message_thread_id, int *disable_notification, int *protect_content, int *allow_paid_broadcast, char *message_effect_id, reply_parameters_t *reply_parameters, inline_keyboard_markup_t *reply_markup)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/sendGame");





    // form parameters
    char *keyForm_business_connection_id = NULL;
    char * valueForm_business_connection_id = 0;
    keyValuePair_t *keyPairForm_business_connection_id = 0;
    if (business_connection_id != NULL)
    {
        keyForm_business_connection_id = strdup("business_connection_id");
        valueForm_business_connection_id = strdup((business_connection_id));
        keyPairForm_business_connection_id = keyValuePair_create(keyForm_business_connection_id,valueForm_business_connection_id);
        list_addElement(localVarFormParameters,keyPairForm_business_connection_id);
    }

    // form parameters
    char *keyForm_chat_id = NULL;
    int valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_chat_id, MAX_NUMBER_LENGTH, "%d", *chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_message_thread_id = NULL;
    int valueForm_message_thread_id = 0;
    keyValuePair_t *keyPairForm_message_thread_id = 0;
    if (message_thread_id != NULL)
    {
        keyForm_message_thread_id = strdup("message_thread_id");
        valueForm_message_thread_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_message_thread_id, MAX_NUMBER_LENGTH, "%d", *message_thread_id);
        keyPairForm_message_thread_id = keyValuePair_create(keyForm_message_thread_id,&valueForm_message_thread_id);
        list_addElement(localVarFormParameters,keyPairForm_message_thread_id);
    }

    // form parameters
    char *keyForm_game_short_name = NULL;
    char * valueForm_game_short_name = 0;
    keyValuePair_t *keyPairForm_game_short_name = 0;
    if (game_short_name != NULL)
    {
        keyForm_game_short_name = strdup("game_short_name");
        valueForm_game_short_name = strdup((game_short_name));
        keyPairForm_game_short_name = keyValuePair_create(keyForm_game_short_name,valueForm_game_short_name);
        list_addElement(localVarFormParameters,keyPairForm_game_short_name);
    }

    // form parameters
    char *keyForm_disable_notification = NULL;
    char * valueForm_disable_notification = 0;
    keyValuePair_t *keyPairForm_disable_notification = 0;
    if (disable_notification != NULL)
    {
        keyForm_disable_notification = strdup("disable_notification");
        valueForm_disable_notification = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_disable_notification, MAX_NUMBER_LENGTH, "%d", *disable_notification);
        keyPairForm_disable_notification = keyValuePair_create(keyForm_disable_notification,valueForm_disable_notification);
        list_addElement(localVarFormParameters,keyPairForm_disable_notification);
    }

    // form parameters
    char *keyForm_protect_content = NULL;
    char * valueForm_protect_content = 0;
    keyValuePair_t *keyPairForm_protect_content = 0;
    if (protect_content != NULL)
    {
        keyForm_protect_content = strdup("protect_content");
        valueForm_protect_content = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_protect_content, MAX_NUMBER_LENGTH, "%d", *protect_content);
        keyPairForm_protect_content = keyValuePair_create(keyForm_protect_content,valueForm_protect_content);
        list_addElement(localVarFormParameters,keyPairForm_protect_content);
    }

    // form parameters
    char *keyForm_allow_paid_broadcast = NULL;
    char * valueForm_allow_paid_broadcast = 0;
    keyValuePair_t *keyPairForm_allow_paid_broadcast = 0;
    if (allow_paid_broadcast != NULL)
    {
        keyForm_allow_paid_broadcast = strdup("allow_paid_broadcast");
        valueForm_allow_paid_broadcast = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_allow_paid_broadcast, MAX_NUMBER_LENGTH, "%d", *allow_paid_broadcast);
        keyPairForm_allow_paid_broadcast = keyValuePair_create(keyForm_allow_paid_broadcast,valueForm_allow_paid_broadcast);
        list_addElement(localVarFormParameters,keyPairForm_allow_paid_broadcast);
    }

    // form parameters
    char *keyForm_message_effect_id = NULL;
    char * valueForm_message_effect_id = 0;
    keyValuePair_t *keyPairForm_message_effect_id = 0;
    if (message_effect_id != NULL)
    {
        keyForm_message_effect_id = strdup("message_effect_id");
        valueForm_message_effect_id = strdup((message_effect_id));
        keyPairForm_message_effect_id = keyValuePair_create(keyForm_message_effect_id,valueForm_message_effect_id);
        list_addElement(localVarFormParameters,keyPairForm_message_effect_id);
    }

    // form parameters
    char *keyForm_reply_parameters = NULL;
    reply_parameters_t * valueForm_reply_parameters = 0;
    keyValuePair_t *keyPairForm_reply_parameters = 0;
    if (reply_parameters != NULL)
    {
        keyForm_reply_parameters = strdup("reply_parameters");
        valueForm_reply_parameters = (reply_parameters);
        keyPairForm_reply_parameters = keyValuePair_create(keyForm_reply_parameters,&valueForm_reply_parameters);
        list_addElement(localVarFormParameters,keyPairForm_reply_parameters);
    }

    // form parameters
    char *keyForm_reply_markup = NULL;
    inline_keyboard_markup_t * valueForm_reply_markup = 0;
    keyValuePair_t *keyPairForm_reply_markup = 0;
    if (reply_markup != NULL)
    {
        keyForm_reply_markup = strdup("reply_markup");
        valueForm_reply_markup = (reply_markup);
        keyPairForm_reply_markup = keyValuePair_create(keyForm_reply_markup,&valueForm_reply_markup);
        list_addElement(localVarFormParameters,keyPairForm_reply_markup);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_send_message_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_send_message_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_business_connection_id) {
        free(keyForm_business_connection_id);
        keyForm_business_connection_id = NULL;
    }
    if (valueForm_business_connection_id) {
        free(valueForm_business_connection_id);
        valueForm_business_connection_id = NULL;
    }
    free(keyPairForm_business_connection_id);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_message_thread_id) {
        free(keyForm_message_thread_id);
        keyForm_message_thread_id = NULL;
    }
    free(keyPairForm_message_thread_id);
    if (keyForm_game_short_name) {
        free(keyForm_game_short_name);
        keyForm_game_short_name = NULL;
    }
    if (valueForm_game_short_name) {
        free(valueForm_game_short_name);
        valueForm_game_short_name = NULL;
    }
    free(keyPairForm_game_short_name);
    if (keyForm_disable_notification) {
        free(keyForm_disable_notification);
        keyForm_disable_notification = NULL;
    }
    free(keyPairForm_disable_notification);
    if (keyForm_protect_content) {
        free(keyForm_protect_content);
        keyForm_protect_content = NULL;
    }
    free(keyPairForm_protect_content);
    if (keyForm_allow_paid_broadcast) {
        free(keyForm_allow_paid_broadcast);
        keyForm_allow_paid_broadcast = NULL;
    }
    free(keyPairForm_allow_paid_broadcast);
    if (keyForm_message_effect_id) {
        free(keyForm_message_effect_id);
        keyForm_message_effect_id = NULL;
    }
    if (valueForm_message_effect_id) {
        free(valueForm_message_effect_id);
        valueForm_message_effect_id = NULL;
    }
    free(keyPairForm_message_effect_id);
    if (keyForm_reply_parameters) {
        free(keyForm_reply_parameters);
        keyForm_reply_parameters = NULL;
    }
    free(keyPairForm_reply_parameters);
    if (keyForm_reply_markup) {
        free(keyForm_reply_markup);
        keyForm_reply_markup = NULL;
    }
    free(keyPairForm_reply_markup);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// sendGift
//
// Sends a gift to the given user or channel chat. The gift can't be converted to Telegram Stars by the receiver. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postSendGift(apiClient_t *apiClient, char *gift_id, int *user_id, post_send_gift_request_chat_id_t *chat_id, int *pay_for_upgrade, char *text, char *text_parse_mode, list_t *text_entities)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/sendGift");





    // form parameters
    char *keyForm_user_id = NULL;
    int valueForm_user_id = 0;
    keyValuePair_t *keyPairForm_user_id = 0;
    if (user_id != NULL)
    {
        keyForm_user_id = strdup("user_id");
        valueForm_user_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_user_id, MAX_NUMBER_LENGTH, "%d", *user_id);
        keyPairForm_user_id = keyValuePair_create(keyForm_user_id,&valueForm_user_id);
        list_addElement(localVarFormParameters,keyPairForm_user_id);
    }

    // form parameters
    char *keyForm_chat_id = NULL;
    post_send_gift_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_gift_id = NULL;
    char * valueForm_gift_id = 0;
    keyValuePair_t *keyPairForm_gift_id = 0;
    if (gift_id != NULL)
    {
        keyForm_gift_id = strdup("gift_id");
        valueForm_gift_id = strdup((gift_id));
        keyPairForm_gift_id = keyValuePair_create(keyForm_gift_id,valueForm_gift_id);
        list_addElement(localVarFormParameters,keyPairForm_gift_id);
    }

    // form parameters
    char *keyForm_pay_for_upgrade = NULL;
    char * valueForm_pay_for_upgrade = 0;
    keyValuePair_t *keyPairForm_pay_for_upgrade = 0;
    if (pay_for_upgrade != NULL)
    {
        keyForm_pay_for_upgrade = strdup("pay_for_upgrade");
        valueForm_pay_for_upgrade = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_pay_for_upgrade, MAX_NUMBER_LENGTH, "%d", *pay_for_upgrade);
        keyPairForm_pay_for_upgrade = keyValuePair_create(keyForm_pay_for_upgrade,valueForm_pay_for_upgrade);
        list_addElement(localVarFormParameters,keyPairForm_pay_for_upgrade);
    }

    // form parameters
    char *keyForm_text = NULL;
    char * valueForm_text = 0;
    keyValuePair_t *keyPairForm_text = 0;
    if (text != NULL)
    {
        keyForm_text = strdup("text");
        valueForm_text = strdup((text));
        keyPairForm_text = keyValuePair_create(keyForm_text,valueForm_text);
        list_addElement(localVarFormParameters,keyPairForm_text);
    }

    // form parameters
    char *keyForm_text_parse_mode = NULL;
    char * valueForm_text_parse_mode = 0;
    keyValuePair_t *keyPairForm_text_parse_mode = 0;
    if (text_parse_mode != NULL)
    {
        keyForm_text_parse_mode = strdup("text_parse_mode");
        valueForm_text_parse_mode = strdup((text_parse_mode));
        keyPairForm_text_parse_mode = keyValuePair_create(keyForm_text_parse_mode,valueForm_text_parse_mode);
        list_addElement(localVarFormParameters,keyPairForm_text_parse_mode);
    }

    // form parameters
    char *keyForm_text_entities = NULL;
     valueForm_text_entities = 0;
    keyValuePair_t *keyPairForm_text_entities = 0;
    if (text_entities != NULL)
    {
        keyForm_text_entities = strdup("text_entities");
        valueForm_text_entities = (text_entities);
        keyPairForm_text_entities = keyValuePair_create(keyForm_text_entities,&valueForm_text_entities);
        list_addElement(localVarFormParameters,keyPairForm_text_entities);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_user_id) {
        free(keyForm_user_id);
        keyForm_user_id = NULL;
    }
    free(keyPairForm_user_id);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_gift_id) {
        free(keyForm_gift_id);
        keyForm_gift_id = NULL;
    }
    if (valueForm_gift_id) {
        free(valueForm_gift_id);
        valueForm_gift_id = NULL;
    }
    free(keyPairForm_gift_id);
    if (keyForm_pay_for_upgrade) {
        free(keyForm_pay_for_upgrade);
        keyForm_pay_for_upgrade = NULL;
    }
    free(keyPairForm_pay_for_upgrade);
    if (keyForm_text) {
        free(keyForm_text);
        keyForm_text = NULL;
    }
    if (valueForm_text) {
        free(valueForm_text);
        valueForm_text = NULL;
    }
    free(keyPairForm_text);
    if (keyForm_text_parse_mode) {
        free(keyForm_text_parse_mode);
        keyForm_text_parse_mode = NULL;
    }
    if (valueForm_text_parse_mode) {
        free(valueForm_text_parse_mode);
        valueForm_text_parse_mode = NULL;
    }
    free(keyPairForm_text_parse_mode);
    if (keyForm_text_entities) {
        free(keyForm_text_entities);
        keyForm_text_entities = NULL;
    }
    free(keyPairForm_text_entities);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// sendInvoice
//
// Use this method to send invoices. On success, the sent [Message](https://core.telegram.org/bots/api/#message) is returned.
//
post_send_message_200_response_t*
DefaultAPI_postSendInvoice(apiClient_t *apiClient, post_send_message_request_chat_id_t *chat_id, char *title, char *description, char *payload, char *currency, list_t *prices, int *message_thread_id, char *provider_token, int *max_tip_amount, list_t *suggested_tip_amounts, char *start_parameter, char *provider_data, char *photo_url, int *photo_size, int *photo_width, int *photo_height, int *need_name, int *need_phone_number, int *need_email, int *need_shipping_address, int *send_phone_number_to_provider, int *send_email_to_provider, int *is_flexible, int *disable_notification, int *protect_content, int *allow_paid_broadcast, char *message_effect_id, reply_parameters_t *reply_parameters, inline_keyboard_markup_t *reply_markup)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/sendInvoice");





    // form parameters
    char *keyForm_chat_id = NULL;
    post_send_message_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_message_thread_id = NULL;
    int valueForm_message_thread_id = 0;
    keyValuePair_t *keyPairForm_message_thread_id = 0;
    if (message_thread_id != NULL)
    {
        keyForm_message_thread_id = strdup("message_thread_id");
        valueForm_message_thread_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_message_thread_id, MAX_NUMBER_LENGTH, "%d", *message_thread_id);
        keyPairForm_message_thread_id = keyValuePair_create(keyForm_message_thread_id,&valueForm_message_thread_id);
        list_addElement(localVarFormParameters,keyPairForm_message_thread_id);
    }

    // form parameters
    char *keyForm_title = NULL;
    char * valueForm_title = 0;
    keyValuePair_t *keyPairForm_title = 0;
    if (title != NULL)
    {
        keyForm_title = strdup("title");
        valueForm_title = strdup((title));
        keyPairForm_title = keyValuePair_create(keyForm_title,valueForm_title);
        list_addElement(localVarFormParameters,keyPairForm_title);
    }

    // form parameters
    char *keyForm_description = NULL;
    char * valueForm_description = 0;
    keyValuePair_t *keyPairForm_description = 0;
    if (description != NULL)
    {
        keyForm_description = strdup("description");
        valueForm_description = strdup((description));
        keyPairForm_description = keyValuePair_create(keyForm_description,valueForm_description);
        list_addElement(localVarFormParameters,keyPairForm_description);
    }

    // form parameters
    char *keyForm_payload = NULL;
    char * valueForm_payload = 0;
    keyValuePair_t *keyPairForm_payload = 0;
    if (payload != NULL)
    {
        keyForm_payload = strdup("payload");
        valueForm_payload = strdup((payload));
        keyPairForm_payload = keyValuePair_create(keyForm_payload,valueForm_payload);
        list_addElement(localVarFormParameters,keyPairForm_payload);
    }

    // form parameters
    char *keyForm_provider_token = NULL;
    char * valueForm_provider_token = 0;
    keyValuePair_t *keyPairForm_provider_token = 0;
    if (provider_token != NULL)
    {
        keyForm_provider_token = strdup("provider_token");
        valueForm_provider_token = strdup((provider_token));
        keyPairForm_provider_token = keyValuePair_create(keyForm_provider_token,valueForm_provider_token);
        list_addElement(localVarFormParameters,keyPairForm_provider_token);
    }

    // form parameters
    char *keyForm_currency = NULL;
    char * valueForm_currency = 0;
    keyValuePair_t *keyPairForm_currency = 0;
    if (currency != NULL)
    {
        keyForm_currency = strdup("currency");
        valueForm_currency = strdup((currency));
        keyPairForm_currency = keyValuePair_create(keyForm_currency,valueForm_currency);
        list_addElement(localVarFormParameters,keyPairForm_currency);
    }

    // form parameters
    char *keyForm_prices = NULL;
     valueForm_prices = 0;
    keyValuePair_t *keyPairForm_prices = 0;
    if (prices != NULL)
    {
        keyForm_prices = strdup("prices");
        valueForm_prices = (prices);
        keyPairForm_prices = keyValuePair_create(keyForm_prices,&valueForm_prices);
        list_addElement(localVarFormParameters,keyPairForm_prices);
    }

    // form parameters
    char *keyForm_max_tip_amount = NULL;
    int valueForm_max_tip_amount = 0;
    keyValuePair_t *keyPairForm_max_tip_amount = 0;
    if (max_tip_amount != NULL)
    {
        keyForm_max_tip_amount = strdup("max_tip_amount");
        valueForm_max_tip_amount = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_max_tip_amount, MAX_NUMBER_LENGTH, "%d", *max_tip_amount);
        keyPairForm_max_tip_amount = keyValuePair_create(keyForm_max_tip_amount,&valueForm_max_tip_amount);
        list_addElement(localVarFormParameters,keyPairForm_max_tip_amount);
    }

    // form parameters
    char *keyForm_suggested_tip_amounts = NULL;
     valueForm_suggested_tip_amounts = 0;
    keyValuePair_t *keyPairForm_suggested_tip_amounts = 0;
    if (suggested_tip_amounts != NULL)
    {
        keyForm_suggested_tip_amounts = strdup("suggested_tip_amounts");
        valueForm_suggested_tip_amounts = (suggested_tip_amounts);
        keyPairForm_suggested_tip_amounts = keyValuePair_create(keyForm_suggested_tip_amounts,&valueForm_suggested_tip_amounts);
        list_addElement(localVarFormParameters,keyPairForm_suggested_tip_amounts);
    }

    // form parameters
    char *keyForm_start_parameter = NULL;
    char * valueForm_start_parameter = 0;
    keyValuePair_t *keyPairForm_start_parameter = 0;
    if (start_parameter != NULL)
    {
        keyForm_start_parameter = strdup("start_parameter");
        valueForm_start_parameter = strdup((start_parameter));
        keyPairForm_start_parameter = keyValuePair_create(keyForm_start_parameter,valueForm_start_parameter);
        list_addElement(localVarFormParameters,keyPairForm_start_parameter);
    }

    // form parameters
    char *keyForm_provider_data = NULL;
    char * valueForm_provider_data = 0;
    keyValuePair_t *keyPairForm_provider_data = 0;
    if (provider_data != NULL)
    {
        keyForm_provider_data = strdup("provider_data");
        valueForm_provider_data = strdup((provider_data));
        keyPairForm_provider_data = keyValuePair_create(keyForm_provider_data,valueForm_provider_data);
        list_addElement(localVarFormParameters,keyPairForm_provider_data);
    }

    // form parameters
    char *keyForm_photo_url = NULL;
    char * valueForm_photo_url = 0;
    keyValuePair_t *keyPairForm_photo_url = 0;
    if (photo_url != NULL)
    {
        keyForm_photo_url = strdup("photo_url");
        valueForm_photo_url = strdup((photo_url));
        keyPairForm_photo_url = keyValuePair_create(keyForm_photo_url,valueForm_photo_url);
        list_addElement(localVarFormParameters,keyPairForm_photo_url);
    }

    // form parameters
    char *keyForm_photo_size = NULL;
    int valueForm_photo_size = 0;
    keyValuePair_t *keyPairForm_photo_size = 0;
    if (photo_size != NULL)
    {
        keyForm_photo_size = strdup("photo_size");
        valueForm_photo_size = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_photo_size, MAX_NUMBER_LENGTH, "%d", *photo_size);
        keyPairForm_photo_size = keyValuePair_create(keyForm_photo_size,&valueForm_photo_size);
        list_addElement(localVarFormParameters,keyPairForm_photo_size);
    }

    // form parameters
    char *keyForm_photo_width = NULL;
    int valueForm_photo_width = 0;
    keyValuePair_t *keyPairForm_photo_width = 0;
    if (photo_width != NULL)
    {
        keyForm_photo_width = strdup("photo_width");
        valueForm_photo_width = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_photo_width, MAX_NUMBER_LENGTH, "%d", *photo_width);
        keyPairForm_photo_width = keyValuePair_create(keyForm_photo_width,&valueForm_photo_width);
        list_addElement(localVarFormParameters,keyPairForm_photo_width);
    }

    // form parameters
    char *keyForm_photo_height = NULL;
    int valueForm_photo_height = 0;
    keyValuePair_t *keyPairForm_photo_height = 0;
    if (photo_height != NULL)
    {
        keyForm_photo_height = strdup("photo_height");
        valueForm_photo_height = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_photo_height, MAX_NUMBER_LENGTH, "%d", *photo_height);
        keyPairForm_photo_height = keyValuePair_create(keyForm_photo_height,&valueForm_photo_height);
        list_addElement(localVarFormParameters,keyPairForm_photo_height);
    }

    // form parameters
    char *keyForm_need_name = NULL;
    char * valueForm_need_name = 0;
    keyValuePair_t *keyPairForm_need_name = 0;
    if (need_name != NULL)
    {
        keyForm_need_name = strdup("need_name");
        valueForm_need_name = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_need_name, MAX_NUMBER_LENGTH, "%d", *need_name);
        keyPairForm_need_name = keyValuePair_create(keyForm_need_name,valueForm_need_name);
        list_addElement(localVarFormParameters,keyPairForm_need_name);
    }

    // form parameters
    char *keyForm_need_phone_number = NULL;
    char * valueForm_need_phone_number = 0;
    keyValuePair_t *keyPairForm_need_phone_number = 0;
    if (need_phone_number != NULL)
    {
        keyForm_need_phone_number = strdup("need_phone_number");
        valueForm_need_phone_number = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_need_phone_number, MAX_NUMBER_LENGTH, "%d", *need_phone_number);
        keyPairForm_need_phone_number = keyValuePair_create(keyForm_need_phone_number,valueForm_need_phone_number);
        list_addElement(localVarFormParameters,keyPairForm_need_phone_number);
    }

    // form parameters
    char *keyForm_need_email = NULL;
    char * valueForm_need_email = 0;
    keyValuePair_t *keyPairForm_need_email = 0;
    if (need_email != NULL)
    {
        keyForm_need_email = strdup("need_email");
        valueForm_need_email = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_need_email, MAX_NUMBER_LENGTH, "%d", *need_email);
        keyPairForm_need_email = keyValuePair_create(keyForm_need_email,valueForm_need_email);
        list_addElement(localVarFormParameters,keyPairForm_need_email);
    }

    // form parameters
    char *keyForm_need_shipping_address = NULL;
    char * valueForm_need_shipping_address = 0;
    keyValuePair_t *keyPairForm_need_shipping_address = 0;
    if (need_shipping_address != NULL)
    {
        keyForm_need_shipping_address = strdup("need_shipping_address");
        valueForm_need_shipping_address = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_need_shipping_address, MAX_NUMBER_LENGTH, "%d", *need_shipping_address);
        keyPairForm_need_shipping_address = keyValuePair_create(keyForm_need_shipping_address,valueForm_need_shipping_address);
        list_addElement(localVarFormParameters,keyPairForm_need_shipping_address);
    }

    // form parameters
    char *keyForm_send_phone_number_to_provider = NULL;
    char * valueForm_send_phone_number_to_provider = 0;
    keyValuePair_t *keyPairForm_send_phone_number_to_provider = 0;
    if (send_phone_number_to_provider != NULL)
    {
        keyForm_send_phone_number_to_provider = strdup("send_phone_number_to_provider");
        valueForm_send_phone_number_to_provider = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_send_phone_number_to_provider, MAX_NUMBER_LENGTH, "%d", *send_phone_number_to_provider);
        keyPairForm_send_phone_number_to_provider = keyValuePair_create(keyForm_send_phone_number_to_provider,valueForm_send_phone_number_to_provider);
        list_addElement(localVarFormParameters,keyPairForm_send_phone_number_to_provider);
    }

    // form parameters
    char *keyForm_send_email_to_provider = NULL;
    char * valueForm_send_email_to_provider = 0;
    keyValuePair_t *keyPairForm_send_email_to_provider = 0;
    if (send_email_to_provider != NULL)
    {
        keyForm_send_email_to_provider = strdup("send_email_to_provider");
        valueForm_send_email_to_provider = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_send_email_to_provider, MAX_NUMBER_LENGTH, "%d", *send_email_to_provider);
        keyPairForm_send_email_to_provider = keyValuePair_create(keyForm_send_email_to_provider,valueForm_send_email_to_provider);
        list_addElement(localVarFormParameters,keyPairForm_send_email_to_provider);
    }

    // form parameters
    char *keyForm_is_flexible = NULL;
    char * valueForm_is_flexible = 0;
    keyValuePair_t *keyPairForm_is_flexible = 0;
    if (is_flexible != NULL)
    {
        keyForm_is_flexible = strdup("is_flexible");
        valueForm_is_flexible = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_is_flexible, MAX_NUMBER_LENGTH, "%d", *is_flexible);
        keyPairForm_is_flexible = keyValuePair_create(keyForm_is_flexible,valueForm_is_flexible);
        list_addElement(localVarFormParameters,keyPairForm_is_flexible);
    }

    // form parameters
    char *keyForm_disable_notification = NULL;
    char * valueForm_disable_notification = 0;
    keyValuePair_t *keyPairForm_disable_notification = 0;
    if (disable_notification != NULL)
    {
        keyForm_disable_notification = strdup("disable_notification");
        valueForm_disable_notification = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_disable_notification, MAX_NUMBER_LENGTH, "%d", *disable_notification);
        keyPairForm_disable_notification = keyValuePair_create(keyForm_disable_notification,valueForm_disable_notification);
        list_addElement(localVarFormParameters,keyPairForm_disable_notification);
    }

    // form parameters
    char *keyForm_protect_content = NULL;
    char * valueForm_protect_content = 0;
    keyValuePair_t *keyPairForm_protect_content = 0;
    if (protect_content != NULL)
    {
        keyForm_protect_content = strdup("protect_content");
        valueForm_protect_content = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_protect_content, MAX_NUMBER_LENGTH, "%d", *protect_content);
        keyPairForm_protect_content = keyValuePair_create(keyForm_protect_content,valueForm_protect_content);
        list_addElement(localVarFormParameters,keyPairForm_protect_content);
    }

    // form parameters
    char *keyForm_allow_paid_broadcast = NULL;
    char * valueForm_allow_paid_broadcast = 0;
    keyValuePair_t *keyPairForm_allow_paid_broadcast = 0;
    if (allow_paid_broadcast != NULL)
    {
        keyForm_allow_paid_broadcast = strdup("allow_paid_broadcast");
        valueForm_allow_paid_broadcast = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_allow_paid_broadcast, MAX_NUMBER_LENGTH, "%d", *allow_paid_broadcast);
        keyPairForm_allow_paid_broadcast = keyValuePair_create(keyForm_allow_paid_broadcast,valueForm_allow_paid_broadcast);
        list_addElement(localVarFormParameters,keyPairForm_allow_paid_broadcast);
    }

    // form parameters
    char *keyForm_message_effect_id = NULL;
    char * valueForm_message_effect_id = 0;
    keyValuePair_t *keyPairForm_message_effect_id = 0;
    if (message_effect_id != NULL)
    {
        keyForm_message_effect_id = strdup("message_effect_id");
        valueForm_message_effect_id = strdup((message_effect_id));
        keyPairForm_message_effect_id = keyValuePair_create(keyForm_message_effect_id,valueForm_message_effect_id);
        list_addElement(localVarFormParameters,keyPairForm_message_effect_id);
    }

    // form parameters
    char *keyForm_reply_parameters = NULL;
    reply_parameters_t * valueForm_reply_parameters = 0;
    keyValuePair_t *keyPairForm_reply_parameters = 0;
    if (reply_parameters != NULL)
    {
        keyForm_reply_parameters = strdup("reply_parameters");
        valueForm_reply_parameters = (reply_parameters);
        keyPairForm_reply_parameters = keyValuePair_create(keyForm_reply_parameters,&valueForm_reply_parameters);
        list_addElement(localVarFormParameters,keyPairForm_reply_parameters);
    }

    // form parameters
    char *keyForm_reply_markup = NULL;
    inline_keyboard_markup_t * valueForm_reply_markup = 0;
    keyValuePair_t *keyPairForm_reply_markup = 0;
    if (reply_markup != NULL)
    {
        keyForm_reply_markup = strdup("reply_markup");
        valueForm_reply_markup = (reply_markup);
        keyPairForm_reply_markup = keyValuePair_create(keyForm_reply_markup,&valueForm_reply_markup);
        list_addElement(localVarFormParameters,keyPairForm_reply_markup);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_send_message_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_send_message_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_message_thread_id) {
        free(keyForm_message_thread_id);
        keyForm_message_thread_id = NULL;
    }
    free(keyPairForm_message_thread_id);
    if (keyForm_title) {
        free(keyForm_title);
        keyForm_title = NULL;
    }
    if (valueForm_title) {
        free(valueForm_title);
        valueForm_title = NULL;
    }
    free(keyPairForm_title);
    if (keyForm_description) {
        free(keyForm_description);
        keyForm_description = NULL;
    }
    if (valueForm_description) {
        free(valueForm_description);
        valueForm_description = NULL;
    }
    free(keyPairForm_description);
    if (keyForm_payload) {
        free(keyForm_payload);
        keyForm_payload = NULL;
    }
    if (valueForm_payload) {
        free(valueForm_payload);
        valueForm_payload = NULL;
    }
    free(keyPairForm_payload);
    if (keyForm_provider_token) {
        free(keyForm_provider_token);
        keyForm_provider_token = NULL;
    }
    if (valueForm_provider_token) {
        free(valueForm_provider_token);
        valueForm_provider_token = NULL;
    }
    free(keyPairForm_provider_token);
    if (keyForm_currency) {
        free(keyForm_currency);
        keyForm_currency = NULL;
    }
    if (valueForm_currency) {
        free(valueForm_currency);
        valueForm_currency = NULL;
    }
    free(keyPairForm_currency);
    if (keyForm_prices) {
        free(keyForm_prices);
        keyForm_prices = NULL;
    }
    free(keyPairForm_prices);
    if (keyForm_max_tip_amount) {
        free(keyForm_max_tip_amount);
        keyForm_max_tip_amount = NULL;
    }
    free(keyPairForm_max_tip_amount);
    if (keyForm_suggested_tip_amounts) {
        free(keyForm_suggested_tip_amounts);
        keyForm_suggested_tip_amounts = NULL;
    }
    free(keyPairForm_suggested_tip_amounts);
    if (keyForm_start_parameter) {
        free(keyForm_start_parameter);
        keyForm_start_parameter = NULL;
    }
    if (valueForm_start_parameter) {
        free(valueForm_start_parameter);
        valueForm_start_parameter = NULL;
    }
    free(keyPairForm_start_parameter);
    if (keyForm_provider_data) {
        free(keyForm_provider_data);
        keyForm_provider_data = NULL;
    }
    if (valueForm_provider_data) {
        free(valueForm_provider_data);
        valueForm_provider_data = NULL;
    }
    free(keyPairForm_provider_data);
    if (keyForm_photo_url) {
        free(keyForm_photo_url);
        keyForm_photo_url = NULL;
    }
    if (valueForm_photo_url) {
        free(valueForm_photo_url);
        valueForm_photo_url = NULL;
    }
    free(keyPairForm_photo_url);
    if (keyForm_photo_size) {
        free(keyForm_photo_size);
        keyForm_photo_size = NULL;
    }
    free(keyPairForm_photo_size);
    if (keyForm_photo_width) {
        free(keyForm_photo_width);
        keyForm_photo_width = NULL;
    }
    free(keyPairForm_photo_width);
    if (keyForm_photo_height) {
        free(keyForm_photo_height);
        keyForm_photo_height = NULL;
    }
    free(keyPairForm_photo_height);
    if (keyForm_need_name) {
        free(keyForm_need_name);
        keyForm_need_name = NULL;
    }
    free(keyPairForm_need_name);
    if (keyForm_need_phone_number) {
        free(keyForm_need_phone_number);
        keyForm_need_phone_number = NULL;
    }
    free(keyPairForm_need_phone_number);
    if (keyForm_need_email) {
        free(keyForm_need_email);
        keyForm_need_email = NULL;
    }
    free(keyPairForm_need_email);
    if (keyForm_need_shipping_address) {
        free(keyForm_need_shipping_address);
        keyForm_need_shipping_address = NULL;
    }
    free(keyPairForm_need_shipping_address);
    if (keyForm_send_phone_number_to_provider) {
        free(keyForm_send_phone_number_to_provider);
        keyForm_send_phone_number_to_provider = NULL;
    }
    free(keyPairForm_send_phone_number_to_provider);
    if (keyForm_send_email_to_provider) {
        free(keyForm_send_email_to_provider);
        keyForm_send_email_to_provider = NULL;
    }
    free(keyPairForm_send_email_to_provider);
    if (keyForm_is_flexible) {
        free(keyForm_is_flexible);
        keyForm_is_flexible = NULL;
    }
    free(keyPairForm_is_flexible);
    if (keyForm_disable_notification) {
        free(keyForm_disable_notification);
        keyForm_disable_notification = NULL;
    }
    free(keyPairForm_disable_notification);
    if (keyForm_protect_content) {
        free(keyForm_protect_content);
        keyForm_protect_content = NULL;
    }
    free(keyPairForm_protect_content);
    if (keyForm_allow_paid_broadcast) {
        free(keyForm_allow_paid_broadcast);
        keyForm_allow_paid_broadcast = NULL;
    }
    free(keyPairForm_allow_paid_broadcast);
    if (keyForm_message_effect_id) {
        free(keyForm_message_effect_id);
        keyForm_message_effect_id = NULL;
    }
    if (valueForm_message_effect_id) {
        free(valueForm_message_effect_id);
        valueForm_message_effect_id = NULL;
    }
    free(keyPairForm_message_effect_id);
    if (keyForm_reply_parameters) {
        free(keyForm_reply_parameters);
        keyForm_reply_parameters = NULL;
    }
    free(keyPairForm_reply_parameters);
    if (keyForm_reply_markup) {
        free(keyForm_reply_markup);
        keyForm_reply_markup = NULL;
    }
    free(keyPairForm_reply_markup);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// sendLocation
//
// Use this method to send point on the map. On success, the sent [Message](https://core.telegram.org/bots/api/#message) is returned.
//
post_send_message_200_response_t*
DefaultAPI_postSendLocation(apiClient_t *apiClient, post_send_message_request_chat_id_t *chat_id, double latitude, double longitude, char *business_connection_id, int *message_thread_id, double horizontal_accuracy, int *live_period, int *heading, int *proximity_alert_radius, int *disable_notification, int *protect_content, int *allow_paid_broadcast, char *message_effect_id, reply_parameters_t *reply_parameters, post_send_message_request_reply_markup_t *reply_markup)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/sendLocation");





    // form parameters
    char *keyForm_business_connection_id = NULL;
    char * valueForm_business_connection_id = 0;
    keyValuePair_t *keyPairForm_business_connection_id = 0;
    if (business_connection_id != NULL)
    {
        keyForm_business_connection_id = strdup("business_connection_id");
        valueForm_business_connection_id = strdup((business_connection_id));
        keyPairForm_business_connection_id = keyValuePair_create(keyForm_business_connection_id,valueForm_business_connection_id);
        list_addElement(localVarFormParameters,keyPairForm_business_connection_id);
    }

    // form parameters
    char *keyForm_chat_id = NULL;
    post_send_message_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_message_thread_id = NULL;
    int valueForm_message_thread_id = 0;
    keyValuePair_t *keyPairForm_message_thread_id = 0;
    if (message_thread_id != NULL)
    {
        keyForm_message_thread_id = strdup("message_thread_id");
        valueForm_message_thread_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_message_thread_id, MAX_NUMBER_LENGTH, "%d", *message_thread_id);
        keyPairForm_message_thread_id = keyValuePair_create(keyForm_message_thread_id,&valueForm_message_thread_id);
        list_addElement(localVarFormParameters,keyPairForm_message_thread_id);
    }

    // form parameters
    char *keyForm_latitude = NULL;
    double valueForm_latitude = 0;
    keyValuePair_t *keyPairForm_latitude = 0;
    if (latitude != NULL)
    {
        keyForm_latitude = strdup("latitude");
        valueForm_latitude = (latitude);
        keyPairForm_latitude = keyValuePair_create(keyForm_latitude,&valueForm_latitude);
        list_addElement(localVarFormParameters,keyPairForm_latitude);
    }

    // form parameters
    char *keyForm_longitude = NULL;
    double valueForm_longitude = 0;
    keyValuePair_t *keyPairForm_longitude = 0;
    if (longitude != NULL)
    {
        keyForm_longitude = strdup("longitude");
        valueForm_longitude = (longitude);
        keyPairForm_longitude = keyValuePair_create(keyForm_longitude,&valueForm_longitude);
        list_addElement(localVarFormParameters,keyPairForm_longitude);
    }

    // form parameters
    char *keyForm_horizontal_accuracy = NULL;
    double valueForm_horizontal_accuracy = 0;
    keyValuePair_t *keyPairForm_horizontal_accuracy = 0;
    if (horizontal_accuracy != NULL)
    {
        keyForm_horizontal_accuracy = strdup("horizontal_accuracy");
        valueForm_horizontal_accuracy = (horizontal_accuracy);
        keyPairForm_horizontal_accuracy = keyValuePair_create(keyForm_horizontal_accuracy,&valueForm_horizontal_accuracy);
        list_addElement(localVarFormParameters,keyPairForm_horizontal_accuracy);
    }

    // form parameters
    char *keyForm_live_period = NULL;
    int valueForm_live_period = 0;
    keyValuePair_t *keyPairForm_live_period = 0;
    if (live_period != NULL)
    {
        keyForm_live_period = strdup("live_period");
        valueForm_live_period = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_live_period, MAX_NUMBER_LENGTH, "%d", *live_period);
        keyPairForm_live_period = keyValuePair_create(keyForm_live_period,&valueForm_live_period);
        list_addElement(localVarFormParameters,keyPairForm_live_period);
    }

    // form parameters
    char *keyForm_heading = NULL;
    int valueForm_heading = 0;
    keyValuePair_t *keyPairForm_heading = 0;
    if (heading != NULL)
    {
        keyForm_heading = strdup("heading");
        valueForm_heading = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_heading, MAX_NUMBER_LENGTH, "%d", *heading);
        keyPairForm_heading = keyValuePair_create(keyForm_heading,&valueForm_heading);
        list_addElement(localVarFormParameters,keyPairForm_heading);
    }

    // form parameters
    char *keyForm_proximity_alert_radius = NULL;
    int valueForm_proximity_alert_radius = 0;
    keyValuePair_t *keyPairForm_proximity_alert_radius = 0;
    if (proximity_alert_radius != NULL)
    {
        keyForm_proximity_alert_radius = strdup("proximity_alert_radius");
        valueForm_proximity_alert_radius = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_proximity_alert_radius, MAX_NUMBER_LENGTH, "%d", *proximity_alert_radius);
        keyPairForm_proximity_alert_radius = keyValuePair_create(keyForm_proximity_alert_radius,&valueForm_proximity_alert_radius);
        list_addElement(localVarFormParameters,keyPairForm_proximity_alert_radius);
    }

    // form parameters
    char *keyForm_disable_notification = NULL;
    char * valueForm_disable_notification = 0;
    keyValuePair_t *keyPairForm_disable_notification = 0;
    if (disable_notification != NULL)
    {
        keyForm_disable_notification = strdup("disable_notification");
        valueForm_disable_notification = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_disable_notification, MAX_NUMBER_LENGTH, "%d", *disable_notification);
        keyPairForm_disable_notification = keyValuePair_create(keyForm_disable_notification,valueForm_disable_notification);
        list_addElement(localVarFormParameters,keyPairForm_disable_notification);
    }

    // form parameters
    char *keyForm_protect_content = NULL;
    char * valueForm_protect_content = 0;
    keyValuePair_t *keyPairForm_protect_content = 0;
    if (protect_content != NULL)
    {
        keyForm_protect_content = strdup("protect_content");
        valueForm_protect_content = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_protect_content, MAX_NUMBER_LENGTH, "%d", *protect_content);
        keyPairForm_protect_content = keyValuePair_create(keyForm_protect_content,valueForm_protect_content);
        list_addElement(localVarFormParameters,keyPairForm_protect_content);
    }

    // form parameters
    char *keyForm_allow_paid_broadcast = NULL;
    char * valueForm_allow_paid_broadcast = 0;
    keyValuePair_t *keyPairForm_allow_paid_broadcast = 0;
    if (allow_paid_broadcast != NULL)
    {
        keyForm_allow_paid_broadcast = strdup("allow_paid_broadcast");
        valueForm_allow_paid_broadcast = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_allow_paid_broadcast, MAX_NUMBER_LENGTH, "%d", *allow_paid_broadcast);
        keyPairForm_allow_paid_broadcast = keyValuePair_create(keyForm_allow_paid_broadcast,valueForm_allow_paid_broadcast);
        list_addElement(localVarFormParameters,keyPairForm_allow_paid_broadcast);
    }

    // form parameters
    char *keyForm_message_effect_id = NULL;
    char * valueForm_message_effect_id = 0;
    keyValuePair_t *keyPairForm_message_effect_id = 0;
    if (message_effect_id != NULL)
    {
        keyForm_message_effect_id = strdup("message_effect_id");
        valueForm_message_effect_id = strdup((message_effect_id));
        keyPairForm_message_effect_id = keyValuePair_create(keyForm_message_effect_id,valueForm_message_effect_id);
        list_addElement(localVarFormParameters,keyPairForm_message_effect_id);
    }

    // form parameters
    char *keyForm_reply_parameters = NULL;
    reply_parameters_t * valueForm_reply_parameters = 0;
    keyValuePair_t *keyPairForm_reply_parameters = 0;
    if (reply_parameters != NULL)
    {
        keyForm_reply_parameters = strdup("reply_parameters");
        valueForm_reply_parameters = (reply_parameters);
        keyPairForm_reply_parameters = keyValuePair_create(keyForm_reply_parameters,&valueForm_reply_parameters);
        list_addElement(localVarFormParameters,keyPairForm_reply_parameters);
    }

    // form parameters
    char *keyForm_reply_markup = NULL;
    post_send_message_request_reply_markup_t * valueForm_reply_markup = 0;
    keyValuePair_t *keyPairForm_reply_markup = 0;
    if (reply_markup != NULL)
    {
        keyForm_reply_markup = strdup("reply_markup");
        valueForm_reply_markup = (reply_markup);
        keyPairForm_reply_markup = keyValuePair_create(keyForm_reply_markup,&valueForm_reply_markup);
        list_addElement(localVarFormParameters,keyPairForm_reply_markup);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_send_message_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_send_message_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_business_connection_id) {
        free(keyForm_business_connection_id);
        keyForm_business_connection_id = NULL;
    }
    if (valueForm_business_connection_id) {
        free(valueForm_business_connection_id);
        valueForm_business_connection_id = NULL;
    }
    free(keyPairForm_business_connection_id);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_message_thread_id) {
        free(keyForm_message_thread_id);
        keyForm_message_thread_id = NULL;
    }
    free(keyPairForm_message_thread_id);
    if (keyForm_latitude) {
        free(keyForm_latitude);
        keyForm_latitude = NULL;
    }
    free(keyPairForm_latitude);
    if (keyForm_longitude) {
        free(keyForm_longitude);
        keyForm_longitude = NULL;
    }
    free(keyPairForm_longitude);
    if (keyForm_horizontal_accuracy) {
        free(keyForm_horizontal_accuracy);
        keyForm_horizontal_accuracy = NULL;
    }
    free(keyPairForm_horizontal_accuracy);
    if (keyForm_live_period) {
        free(keyForm_live_period);
        keyForm_live_period = NULL;
    }
    free(keyPairForm_live_period);
    if (keyForm_heading) {
        free(keyForm_heading);
        keyForm_heading = NULL;
    }
    free(keyPairForm_heading);
    if (keyForm_proximity_alert_radius) {
        free(keyForm_proximity_alert_radius);
        keyForm_proximity_alert_radius = NULL;
    }
    free(keyPairForm_proximity_alert_radius);
    if (keyForm_disable_notification) {
        free(keyForm_disable_notification);
        keyForm_disable_notification = NULL;
    }
    free(keyPairForm_disable_notification);
    if (keyForm_protect_content) {
        free(keyForm_protect_content);
        keyForm_protect_content = NULL;
    }
    free(keyPairForm_protect_content);
    if (keyForm_allow_paid_broadcast) {
        free(keyForm_allow_paid_broadcast);
        keyForm_allow_paid_broadcast = NULL;
    }
    free(keyPairForm_allow_paid_broadcast);
    if (keyForm_message_effect_id) {
        free(keyForm_message_effect_id);
        keyForm_message_effect_id = NULL;
    }
    if (valueForm_message_effect_id) {
        free(valueForm_message_effect_id);
        valueForm_message_effect_id = NULL;
    }
    free(keyPairForm_message_effect_id);
    if (keyForm_reply_parameters) {
        free(keyForm_reply_parameters);
        keyForm_reply_parameters = NULL;
    }
    free(keyPairForm_reply_parameters);
    if (keyForm_reply_markup) {
        free(keyForm_reply_markup);
        keyForm_reply_markup = NULL;
    }
    free(keyPairForm_reply_markup);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// sendMediaGroup
//
// Use this method to send a group of photos, videos, documents or audios as an album. Documents and audio files can be only grouped in an album with messages of the same type. On success, an array of [Messages](https://core.telegram.org/bots/api/#message) that were sent is returned.
//
post_send_media_group_200_response_t*
DefaultAPI_postSendMediaGroup(apiClient_t *apiClient, post_send_message_request_chat_id_t *chat_id, list_t *media, char *business_connection_id, int *message_thread_id, int *disable_notification, int *protect_content, int *allow_paid_broadcast, char *message_effect_id, reply_parameters_t *reply_parameters)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/sendMediaGroup");





    // form parameters
    char *keyForm_business_connection_id = NULL;
    char * valueForm_business_connection_id = 0;
    keyValuePair_t *keyPairForm_business_connection_id = 0;
    if (business_connection_id != NULL)
    {
        keyForm_business_connection_id = strdup("business_connection_id");
        valueForm_business_connection_id = strdup((business_connection_id));
        keyPairForm_business_connection_id = keyValuePair_create(keyForm_business_connection_id,valueForm_business_connection_id);
        list_addElement(localVarFormParameters,keyPairForm_business_connection_id);
    }

    // form parameters
    char *keyForm_chat_id = NULL;
    post_send_message_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_message_thread_id = NULL;
    int valueForm_message_thread_id = 0;
    keyValuePair_t *keyPairForm_message_thread_id = 0;
    if (message_thread_id != NULL)
    {
        keyForm_message_thread_id = strdup("message_thread_id");
        valueForm_message_thread_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_message_thread_id, MAX_NUMBER_LENGTH, "%d", *message_thread_id);
        keyPairForm_message_thread_id = keyValuePair_create(keyForm_message_thread_id,&valueForm_message_thread_id);
        list_addElement(localVarFormParameters,keyPairForm_message_thread_id);
    }

    // form parameters
    char *keyForm_media = NULL;
     valueForm_media = 0;
    keyValuePair_t *keyPairForm_media = 0;
    if (media != NULL)
    {
        keyForm_media = strdup("media");
        valueForm_media = (media);
        keyPairForm_media = keyValuePair_create(keyForm_media,&valueForm_media);
        list_addElement(localVarFormParameters,keyPairForm_media);
    }

    // form parameters
    char *keyForm_disable_notification = NULL;
    char * valueForm_disable_notification = 0;
    keyValuePair_t *keyPairForm_disable_notification = 0;
    if (disable_notification != NULL)
    {
        keyForm_disable_notification = strdup("disable_notification");
        valueForm_disable_notification = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_disable_notification, MAX_NUMBER_LENGTH, "%d", *disable_notification);
        keyPairForm_disable_notification = keyValuePair_create(keyForm_disable_notification,valueForm_disable_notification);
        list_addElement(localVarFormParameters,keyPairForm_disable_notification);
    }

    // form parameters
    char *keyForm_protect_content = NULL;
    char * valueForm_protect_content = 0;
    keyValuePair_t *keyPairForm_protect_content = 0;
    if (protect_content != NULL)
    {
        keyForm_protect_content = strdup("protect_content");
        valueForm_protect_content = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_protect_content, MAX_NUMBER_LENGTH, "%d", *protect_content);
        keyPairForm_protect_content = keyValuePair_create(keyForm_protect_content,valueForm_protect_content);
        list_addElement(localVarFormParameters,keyPairForm_protect_content);
    }

    // form parameters
    char *keyForm_allow_paid_broadcast = NULL;
    char * valueForm_allow_paid_broadcast = 0;
    keyValuePair_t *keyPairForm_allow_paid_broadcast = 0;
    if (allow_paid_broadcast != NULL)
    {
        keyForm_allow_paid_broadcast = strdup("allow_paid_broadcast");
        valueForm_allow_paid_broadcast = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_allow_paid_broadcast, MAX_NUMBER_LENGTH, "%d", *allow_paid_broadcast);
        keyPairForm_allow_paid_broadcast = keyValuePair_create(keyForm_allow_paid_broadcast,valueForm_allow_paid_broadcast);
        list_addElement(localVarFormParameters,keyPairForm_allow_paid_broadcast);
    }

    // form parameters
    char *keyForm_message_effect_id = NULL;
    char * valueForm_message_effect_id = 0;
    keyValuePair_t *keyPairForm_message_effect_id = 0;
    if (message_effect_id != NULL)
    {
        keyForm_message_effect_id = strdup("message_effect_id");
        valueForm_message_effect_id = strdup((message_effect_id));
        keyPairForm_message_effect_id = keyValuePair_create(keyForm_message_effect_id,valueForm_message_effect_id);
        list_addElement(localVarFormParameters,keyPairForm_message_effect_id);
    }

    // form parameters
    char *keyForm_reply_parameters = NULL;
    reply_parameters_t * valueForm_reply_parameters = 0;
    keyValuePair_t *keyPairForm_reply_parameters = 0;
    if (reply_parameters != NULL)
    {
        keyForm_reply_parameters = strdup("reply_parameters");
        valueForm_reply_parameters = (reply_parameters);
        keyPairForm_reply_parameters = keyValuePair_create(keyForm_reply_parameters,&valueForm_reply_parameters);
        list_addElement(localVarFormParameters,keyPairForm_reply_parameters);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_send_media_group_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_send_media_group_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_business_connection_id) {
        free(keyForm_business_connection_id);
        keyForm_business_connection_id = NULL;
    }
    if (valueForm_business_connection_id) {
        free(valueForm_business_connection_id);
        valueForm_business_connection_id = NULL;
    }
    free(keyPairForm_business_connection_id);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_message_thread_id) {
        free(keyForm_message_thread_id);
        keyForm_message_thread_id = NULL;
    }
    free(keyPairForm_message_thread_id);
    if (keyForm_media) {
        free(keyForm_media);
        keyForm_media = NULL;
    }
    free(keyPairForm_media);
    if (keyForm_disable_notification) {
        free(keyForm_disable_notification);
        keyForm_disable_notification = NULL;
    }
    free(keyPairForm_disable_notification);
    if (keyForm_protect_content) {
        free(keyForm_protect_content);
        keyForm_protect_content = NULL;
    }
    free(keyPairForm_protect_content);
    if (keyForm_allow_paid_broadcast) {
        free(keyForm_allow_paid_broadcast);
        keyForm_allow_paid_broadcast = NULL;
    }
    free(keyPairForm_allow_paid_broadcast);
    if (keyForm_message_effect_id) {
        free(keyForm_message_effect_id);
        keyForm_message_effect_id = NULL;
    }
    if (valueForm_message_effect_id) {
        free(valueForm_message_effect_id);
        valueForm_message_effect_id = NULL;
    }
    free(keyPairForm_message_effect_id);
    if (keyForm_reply_parameters) {
        free(keyForm_reply_parameters);
        keyForm_reply_parameters = NULL;
    }
    free(keyPairForm_reply_parameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// sendMessage
//
// Use this method to send text messages. On success, the sent [Message](https://core.telegram.org/bots/api/#message) is returned.
//
post_send_message_200_response_t*
DefaultAPI_postSendMessage(apiClient_t *apiClient, post_send_message_request_chat_id_t *chat_id, char *text, char *business_connection_id, int *message_thread_id, char *parse_mode, list_t *entities, link_preview_options_t *link_preview_options, int *disable_notification, int *protect_content, int *allow_paid_broadcast, char *message_effect_id, reply_parameters_t *reply_parameters, post_send_message_request_reply_markup_t *reply_markup)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/sendMessage");





    // form parameters
    char *keyForm_business_connection_id = NULL;
    char * valueForm_business_connection_id = 0;
    keyValuePair_t *keyPairForm_business_connection_id = 0;
    if (business_connection_id != NULL)
    {
        keyForm_business_connection_id = strdup("business_connection_id");
        valueForm_business_connection_id = strdup((business_connection_id));
        keyPairForm_business_connection_id = keyValuePair_create(keyForm_business_connection_id,valueForm_business_connection_id);
        list_addElement(localVarFormParameters,keyPairForm_business_connection_id);
    }

    // form parameters
    char *keyForm_chat_id = NULL;
    post_send_message_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_message_thread_id = NULL;
    int valueForm_message_thread_id = 0;
    keyValuePair_t *keyPairForm_message_thread_id = 0;
    if (message_thread_id != NULL)
    {
        keyForm_message_thread_id = strdup("message_thread_id");
        valueForm_message_thread_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_message_thread_id, MAX_NUMBER_LENGTH, "%d", *message_thread_id);
        keyPairForm_message_thread_id = keyValuePair_create(keyForm_message_thread_id,&valueForm_message_thread_id);
        list_addElement(localVarFormParameters,keyPairForm_message_thread_id);
    }

    // form parameters
    char *keyForm_text = NULL;
    char * valueForm_text = 0;
    keyValuePair_t *keyPairForm_text = 0;
    if (text != NULL)
    {
        keyForm_text = strdup("text");
        valueForm_text = strdup((text));
        keyPairForm_text = keyValuePair_create(keyForm_text,valueForm_text);
        list_addElement(localVarFormParameters,keyPairForm_text);
    }

    // form parameters
    char *keyForm_parse_mode = NULL;
    char * valueForm_parse_mode = 0;
    keyValuePair_t *keyPairForm_parse_mode = 0;
    if (parse_mode != NULL)
    {
        keyForm_parse_mode = strdup("parse_mode");
        valueForm_parse_mode = strdup((parse_mode));
        keyPairForm_parse_mode = keyValuePair_create(keyForm_parse_mode,valueForm_parse_mode);
        list_addElement(localVarFormParameters,keyPairForm_parse_mode);
    }

    // form parameters
    char *keyForm_entities = NULL;
     valueForm_entities = 0;
    keyValuePair_t *keyPairForm_entities = 0;
    if (entities != NULL)
    {
        keyForm_entities = strdup("entities");
        valueForm_entities = (entities);
        keyPairForm_entities = keyValuePair_create(keyForm_entities,&valueForm_entities);
        list_addElement(localVarFormParameters,keyPairForm_entities);
    }

    // form parameters
    char *keyForm_link_preview_options = NULL;
    link_preview_options_t * valueForm_link_preview_options = 0;
    keyValuePair_t *keyPairForm_link_preview_options = 0;
    if (link_preview_options != NULL)
    {
        keyForm_link_preview_options = strdup("link_preview_options");
        valueForm_link_preview_options = (link_preview_options);
        keyPairForm_link_preview_options = keyValuePair_create(keyForm_link_preview_options,&valueForm_link_preview_options);
        list_addElement(localVarFormParameters,keyPairForm_link_preview_options);
    }

    // form parameters
    char *keyForm_disable_notification = NULL;
    char * valueForm_disable_notification = 0;
    keyValuePair_t *keyPairForm_disable_notification = 0;
    if (disable_notification != NULL)
    {
        keyForm_disable_notification = strdup("disable_notification");
        valueForm_disable_notification = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_disable_notification, MAX_NUMBER_LENGTH, "%d", *disable_notification);
        keyPairForm_disable_notification = keyValuePair_create(keyForm_disable_notification,valueForm_disable_notification);
        list_addElement(localVarFormParameters,keyPairForm_disable_notification);
    }

    // form parameters
    char *keyForm_protect_content = NULL;
    char * valueForm_protect_content = 0;
    keyValuePair_t *keyPairForm_protect_content = 0;
    if (protect_content != NULL)
    {
        keyForm_protect_content = strdup("protect_content");
        valueForm_protect_content = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_protect_content, MAX_NUMBER_LENGTH, "%d", *protect_content);
        keyPairForm_protect_content = keyValuePair_create(keyForm_protect_content,valueForm_protect_content);
        list_addElement(localVarFormParameters,keyPairForm_protect_content);
    }

    // form parameters
    char *keyForm_allow_paid_broadcast = NULL;
    char * valueForm_allow_paid_broadcast = 0;
    keyValuePair_t *keyPairForm_allow_paid_broadcast = 0;
    if (allow_paid_broadcast != NULL)
    {
        keyForm_allow_paid_broadcast = strdup("allow_paid_broadcast");
        valueForm_allow_paid_broadcast = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_allow_paid_broadcast, MAX_NUMBER_LENGTH, "%d", *allow_paid_broadcast);
        keyPairForm_allow_paid_broadcast = keyValuePair_create(keyForm_allow_paid_broadcast,valueForm_allow_paid_broadcast);
        list_addElement(localVarFormParameters,keyPairForm_allow_paid_broadcast);
    }

    // form parameters
    char *keyForm_message_effect_id = NULL;
    char * valueForm_message_effect_id = 0;
    keyValuePair_t *keyPairForm_message_effect_id = 0;
    if (message_effect_id != NULL)
    {
        keyForm_message_effect_id = strdup("message_effect_id");
        valueForm_message_effect_id = strdup((message_effect_id));
        keyPairForm_message_effect_id = keyValuePair_create(keyForm_message_effect_id,valueForm_message_effect_id);
        list_addElement(localVarFormParameters,keyPairForm_message_effect_id);
    }

    // form parameters
    char *keyForm_reply_parameters = NULL;
    reply_parameters_t * valueForm_reply_parameters = 0;
    keyValuePair_t *keyPairForm_reply_parameters = 0;
    if (reply_parameters != NULL)
    {
        keyForm_reply_parameters = strdup("reply_parameters");
        valueForm_reply_parameters = (reply_parameters);
        keyPairForm_reply_parameters = keyValuePair_create(keyForm_reply_parameters,&valueForm_reply_parameters);
        list_addElement(localVarFormParameters,keyPairForm_reply_parameters);
    }

    // form parameters
    char *keyForm_reply_markup = NULL;
    post_send_message_request_reply_markup_t * valueForm_reply_markup = 0;
    keyValuePair_t *keyPairForm_reply_markup = 0;
    if (reply_markup != NULL)
    {
        keyForm_reply_markup = strdup("reply_markup");
        valueForm_reply_markup = (reply_markup);
        keyPairForm_reply_markup = keyValuePair_create(keyForm_reply_markup,&valueForm_reply_markup);
        list_addElement(localVarFormParameters,keyPairForm_reply_markup);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_send_message_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_send_message_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_business_connection_id) {
        free(keyForm_business_connection_id);
        keyForm_business_connection_id = NULL;
    }
    if (valueForm_business_connection_id) {
        free(valueForm_business_connection_id);
        valueForm_business_connection_id = NULL;
    }
    free(keyPairForm_business_connection_id);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_message_thread_id) {
        free(keyForm_message_thread_id);
        keyForm_message_thread_id = NULL;
    }
    free(keyPairForm_message_thread_id);
    if (keyForm_text) {
        free(keyForm_text);
        keyForm_text = NULL;
    }
    if (valueForm_text) {
        free(valueForm_text);
        valueForm_text = NULL;
    }
    free(keyPairForm_text);
    if (keyForm_parse_mode) {
        free(keyForm_parse_mode);
        keyForm_parse_mode = NULL;
    }
    if (valueForm_parse_mode) {
        free(valueForm_parse_mode);
        valueForm_parse_mode = NULL;
    }
    free(keyPairForm_parse_mode);
    if (keyForm_entities) {
        free(keyForm_entities);
        keyForm_entities = NULL;
    }
    free(keyPairForm_entities);
    if (keyForm_link_preview_options) {
        free(keyForm_link_preview_options);
        keyForm_link_preview_options = NULL;
    }
    free(keyPairForm_link_preview_options);
    if (keyForm_disable_notification) {
        free(keyForm_disable_notification);
        keyForm_disable_notification = NULL;
    }
    free(keyPairForm_disable_notification);
    if (keyForm_protect_content) {
        free(keyForm_protect_content);
        keyForm_protect_content = NULL;
    }
    free(keyPairForm_protect_content);
    if (keyForm_allow_paid_broadcast) {
        free(keyForm_allow_paid_broadcast);
        keyForm_allow_paid_broadcast = NULL;
    }
    free(keyPairForm_allow_paid_broadcast);
    if (keyForm_message_effect_id) {
        free(keyForm_message_effect_id);
        keyForm_message_effect_id = NULL;
    }
    if (valueForm_message_effect_id) {
        free(valueForm_message_effect_id);
        valueForm_message_effect_id = NULL;
    }
    free(keyPairForm_message_effect_id);
    if (keyForm_reply_parameters) {
        free(keyForm_reply_parameters);
        keyForm_reply_parameters = NULL;
    }
    free(keyPairForm_reply_parameters);
    if (keyForm_reply_markup) {
        free(keyForm_reply_markup);
        keyForm_reply_markup = NULL;
    }
    free(keyPairForm_reply_markup);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// sendPaidMedia
//
// Use this method to send paid media. On success, the sent [Message](https://core.telegram.org/bots/api/#message) is returned.
//
post_send_message_200_response_t*
DefaultAPI_postSendPaidMedia(apiClient_t *apiClient, post_send_paid_media_request_chat_id_t *chat_id, int *star_count, list_t *media, char *business_connection_id, char *payload, char *caption, char *parse_mode, list_t *caption_entities, int *show_caption_above_media, int *disable_notification, int *protect_content, int *allow_paid_broadcast, reply_parameters_t *reply_parameters, post_send_message_request_reply_markup_t *reply_markup)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/sendPaidMedia");





    // form parameters
    char *keyForm_business_connection_id = NULL;
    char * valueForm_business_connection_id = 0;
    keyValuePair_t *keyPairForm_business_connection_id = 0;
    if (business_connection_id != NULL)
    {
        keyForm_business_connection_id = strdup("business_connection_id");
        valueForm_business_connection_id = strdup((business_connection_id));
        keyPairForm_business_connection_id = keyValuePair_create(keyForm_business_connection_id,valueForm_business_connection_id);
        list_addElement(localVarFormParameters,keyPairForm_business_connection_id);
    }

    // form parameters
    char *keyForm_chat_id = NULL;
    post_send_paid_media_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_star_count = NULL;
    int valueForm_star_count = 0;
    keyValuePair_t *keyPairForm_star_count = 0;
    if (star_count != NULL)
    {
        keyForm_star_count = strdup("star_count");
        valueForm_star_count = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_star_count, MAX_NUMBER_LENGTH, "%d", *star_count);
        keyPairForm_star_count = keyValuePair_create(keyForm_star_count,&valueForm_star_count);
        list_addElement(localVarFormParameters,keyPairForm_star_count);
    }

    // form parameters
    char *keyForm_media = NULL;
     valueForm_media = 0;
    keyValuePair_t *keyPairForm_media = 0;
    if (media != NULL)
    {
        keyForm_media = strdup("media");
        valueForm_media = (media);
        keyPairForm_media = keyValuePair_create(keyForm_media,&valueForm_media);
        list_addElement(localVarFormParameters,keyPairForm_media);
    }

    // form parameters
    char *keyForm_payload = NULL;
    char * valueForm_payload = 0;
    keyValuePair_t *keyPairForm_payload = 0;
    if (payload != NULL)
    {
        keyForm_payload = strdup("payload");
        valueForm_payload = strdup((payload));
        keyPairForm_payload = keyValuePair_create(keyForm_payload,valueForm_payload);
        list_addElement(localVarFormParameters,keyPairForm_payload);
    }

    // form parameters
    char *keyForm_caption = NULL;
    char * valueForm_caption = 0;
    keyValuePair_t *keyPairForm_caption = 0;
    if (caption != NULL)
    {
        keyForm_caption = strdup("caption");
        valueForm_caption = strdup((caption));
        keyPairForm_caption = keyValuePair_create(keyForm_caption,valueForm_caption);
        list_addElement(localVarFormParameters,keyPairForm_caption);
    }

    // form parameters
    char *keyForm_parse_mode = NULL;
    char * valueForm_parse_mode = 0;
    keyValuePair_t *keyPairForm_parse_mode = 0;
    if (parse_mode != NULL)
    {
        keyForm_parse_mode = strdup("parse_mode");
        valueForm_parse_mode = strdup((parse_mode));
        keyPairForm_parse_mode = keyValuePair_create(keyForm_parse_mode,valueForm_parse_mode);
        list_addElement(localVarFormParameters,keyPairForm_parse_mode);
    }

    // form parameters
    char *keyForm_caption_entities = NULL;
     valueForm_caption_entities = 0;
    keyValuePair_t *keyPairForm_caption_entities = 0;
    if (caption_entities != NULL)
    {
        keyForm_caption_entities = strdup("caption_entities");
        valueForm_caption_entities = (caption_entities);
        keyPairForm_caption_entities = keyValuePair_create(keyForm_caption_entities,&valueForm_caption_entities);
        list_addElement(localVarFormParameters,keyPairForm_caption_entities);
    }

    // form parameters
    char *keyForm_show_caption_above_media = NULL;
    char * valueForm_show_caption_above_media = 0;
    keyValuePair_t *keyPairForm_show_caption_above_media = 0;
    if (show_caption_above_media != NULL)
    {
        keyForm_show_caption_above_media = strdup("show_caption_above_media");
        valueForm_show_caption_above_media = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_show_caption_above_media, MAX_NUMBER_LENGTH, "%d", *show_caption_above_media);
        keyPairForm_show_caption_above_media = keyValuePair_create(keyForm_show_caption_above_media,valueForm_show_caption_above_media);
        list_addElement(localVarFormParameters,keyPairForm_show_caption_above_media);
    }

    // form parameters
    char *keyForm_disable_notification = NULL;
    char * valueForm_disable_notification = 0;
    keyValuePair_t *keyPairForm_disable_notification = 0;
    if (disable_notification != NULL)
    {
        keyForm_disable_notification = strdup("disable_notification");
        valueForm_disable_notification = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_disable_notification, MAX_NUMBER_LENGTH, "%d", *disable_notification);
        keyPairForm_disable_notification = keyValuePair_create(keyForm_disable_notification,valueForm_disable_notification);
        list_addElement(localVarFormParameters,keyPairForm_disable_notification);
    }

    // form parameters
    char *keyForm_protect_content = NULL;
    char * valueForm_protect_content = 0;
    keyValuePair_t *keyPairForm_protect_content = 0;
    if (protect_content != NULL)
    {
        keyForm_protect_content = strdup("protect_content");
        valueForm_protect_content = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_protect_content, MAX_NUMBER_LENGTH, "%d", *protect_content);
        keyPairForm_protect_content = keyValuePair_create(keyForm_protect_content,valueForm_protect_content);
        list_addElement(localVarFormParameters,keyPairForm_protect_content);
    }

    // form parameters
    char *keyForm_allow_paid_broadcast = NULL;
    char * valueForm_allow_paid_broadcast = 0;
    keyValuePair_t *keyPairForm_allow_paid_broadcast = 0;
    if (allow_paid_broadcast != NULL)
    {
        keyForm_allow_paid_broadcast = strdup("allow_paid_broadcast");
        valueForm_allow_paid_broadcast = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_allow_paid_broadcast, MAX_NUMBER_LENGTH, "%d", *allow_paid_broadcast);
        keyPairForm_allow_paid_broadcast = keyValuePair_create(keyForm_allow_paid_broadcast,valueForm_allow_paid_broadcast);
        list_addElement(localVarFormParameters,keyPairForm_allow_paid_broadcast);
    }

    // form parameters
    char *keyForm_reply_parameters = NULL;
    reply_parameters_t * valueForm_reply_parameters = 0;
    keyValuePair_t *keyPairForm_reply_parameters = 0;
    if (reply_parameters != NULL)
    {
        keyForm_reply_parameters = strdup("reply_parameters");
        valueForm_reply_parameters = (reply_parameters);
        keyPairForm_reply_parameters = keyValuePair_create(keyForm_reply_parameters,&valueForm_reply_parameters);
        list_addElement(localVarFormParameters,keyPairForm_reply_parameters);
    }

    // form parameters
    char *keyForm_reply_markup = NULL;
    post_send_message_request_reply_markup_t * valueForm_reply_markup = 0;
    keyValuePair_t *keyPairForm_reply_markup = 0;
    if (reply_markup != NULL)
    {
        keyForm_reply_markup = strdup("reply_markup");
        valueForm_reply_markup = (reply_markup);
        keyPairForm_reply_markup = keyValuePair_create(keyForm_reply_markup,&valueForm_reply_markup);
        list_addElement(localVarFormParameters,keyPairForm_reply_markup);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_send_message_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_send_message_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_business_connection_id) {
        free(keyForm_business_connection_id);
        keyForm_business_connection_id = NULL;
    }
    if (valueForm_business_connection_id) {
        free(valueForm_business_connection_id);
        valueForm_business_connection_id = NULL;
    }
    free(keyPairForm_business_connection_id);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_star_count) {
        free(keyForm_star_count);
        keyForm_star_count = NULL;
    }
    free(keyPairForm_star_count);
    if (keyForm_media) {
        free(keyForm_media);
        keyForm_media = NULL;
    }
    free(keyPairForm_media);
    if (keyForm_payload) {
        free(keyForm_payload);
        keyForm_payload = NULL;
    }
    if (valueForm_payload) {
        free(valueForm_payload);
        valueForm_payload = NULL;
    }
    free(keyPairForm_payload);
    if (keyForm_caption) {
        free(keyForm_caption);
        keyForm_caption = NULL;
    }
    if (valueForm_caption) {
        free(valueForm_caption);
        valueForm_caption = NULL;
    }
    free(keyPairForm_caption);
    if (keyForm_parse_mode) {
        free(keyForm_parse_mode);
        keyForm_parse_mode = NULL;
    }
    if (valueForm_parse_mode) {
        free(valueForm_parse_mode);
        valueForm_parse_mode = NULL;
    }
    free(keyPairForm_parse_mode);
    if (keyForm_caption_entities) {
        free(keyForm_caption_entities);
        keyForm_caption_entities = NULL;
    }
    free(keyPairForm_caption_entities);
    if (keyForm_show_caption_above_media) {
        free(keyForm_show_caption_above_media);
        keyForm_show_caption_above_media = NULL;
    }
    free(keyPairForm_show_caption_above_media);
    if (keyForm_disable_notification) {
        free(keyForm_disable_notification);
        keyForm_disable_notification = NULL;
    }
    free(keyPairForm_disable_notification);
    if (keyForm_protect_content) {
        free(keyForm_protect_content);
        keyForm_protect_content = NULL;
    }
    free(keyPairForm_protect_content);
    if (keyForm_allow_paid_broadcast) {
        free(keyForm_allow_paid_broadcast);
        keyForm_allow_paid_broadcast = NULL;
    }
    free(keyPairForm_allow_paid_broadcast);
    if (keyForm_reply_parameters) {
        free(keyForm_reply_parameters);
        keyForm_reply_parameters = NULL;
    }
    free(keyPairForm_reply_parameters);
    if (keyForm_reply_markup) {
        free(keyForm_reply_markup);
        keyForm_reply_markup = NULL;
    }
    free(keyPairForm_reply_markup);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// sendPhoto
//
// Use this method to send photos. On success, the sent [Message](https://core.telegram.org/bots/api/#message) is returned.
//
post_send_message_200_response_t*
DefaultAPI_postSendPhoto(apiClient_t *apiClient, post_send_message_request_chat_id_t *chat_id, post_send_photo_request_photo_t *photo, char *business_connection_id, int *message_thread_id, char *caption, char *parse_mode, list_t *caption_entities, int *show_caption_above_media, int *has_spoiler, int *disable_notification, int *protect_content, int *allow_paid_broadcast, char *message_effect_id, reply_parameters_t *reply_parameters, post_send_message_request_reply_markup_t *reply_markup)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/sendPhoto");





    // form parameters
    char *keyForm_business_connection_id = NULL;
    char * valueForm_business_connection_id = 0;
    keyValuePair_t *keyPairForm_business_connection_id = 0;
    if (business_connection_id != NULL)
    {
        keyForm_business_connection_id = strdup("business_connection_id");
        valueForm_business_connection_id = strdup((business_connection_id));
        keyPairForm_business_connection_id = keyValuePair_create(keyForm_business_connection_id,valueForm_business_connection_id);
        list_addElement(localVarFormParameters,keyPairForm_business_connection_id);
    }

    // form parameters
    char *keyForm_chat_id = NULL;
    post_send_message_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_message_thread_id = NULL;
    int valueForm_message_thread_id = 0;
    keyValuePair_t *keyPairForm_message_thread_id = 0;
    if (message_thread_id != NULL)
    {
        keyForm_message_thread_id = strdup("message_thread_id");
        valueForm_message_thread_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_message_thread_id, MAX_NUMBER_LENGTH, "%d", *message_thread_id);
        keyPairForm_message_thread_id = keyValuePair_create(keyForm_message_thread_id,&valueForm_message_thread_id);
        list_addElement(localVarFormParameters,keyPairForm_message_thread_id);
    }

    // form parameters
    char *keyForm_photo = NULL;
    post_send_photo_request_photo_t * valueForm_photo = 0;
    keyValuePair_t *keyPairForm_photo = 0;
    if (photo != NULL)
    {
        keyForm_photo = strdup("photo");
        valueForm_photo = (photo);
        keyPairForm_photo = keyValuePair_create(keyForm_photo,&valueForm_photo);
        list_addElement(localVarFormParameters,keyPairForm_photo);
    }

    // form parameters
    char *keyForm_caption = NULL;
    char * valueForm_caption = 0;
    keyValuePair_t *keyPairForm_caption = 0;
    if (caption != NULL)
    {
        keyForm_caption = strdup("caption");
        valueForm_caption = strdup((caption));
        keyPairForm_caption = keyValuePair_create(keyForm_caption,valueForm_caption);
        list_addElement(localVarFormParameters,keyPairForm_caption);
    }

    // form parameters
    char *keyForm_parse_mode = NULL;
    char * valueForm_parse_mode = 0;
    keyValuePair_t *keyPairForm_parse_mode = 0;
    if (parse_mode != NULL)
    {
        keyForm_parse_mode = strdup("parse_mode");
        valueForm_parse_mode = strdup((parse_mode));
        keyPairForm_parse_mode = keyValuePair_create(keyForm_parse_mode,valueForm_parse_mode);
        list_addElement(localVarFormParameters,keyPairForm_parse_mode);
    }

    // form parameters
    char *keyForm_caption_entities = NULL;
     valueForm_caption_entities = 0;
    keyValuePair_t *keyPairForm_caption_entities = 0;
    if (caption_entities != NULL)
    {
        keyForm_caption_entities = strdup("caption_entities");
        valueForm_caption_entities = (caption_entities);
        keyPairForm_caption_entities = keyValuePair_create(keyForm_caption_entities,&valueForm_caption_entities);
        list_addElement(localVarFormParameters,keyPairForm_caption_entities);
    }

    // form parameters
    char *keyForm_show_caption_above_media = NULL;
    char * valueForm_show_caption_above_media = 0;
    keyValuePair_t *keyPairForm_show_caption_above_media = 0;
    if (show_caption_above_media != NULL)
    {
        keyForm_show_caption_above_media = strdup("show_caption_above_media");
        valueForm_show_caption_above_media = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_show_caption_above_media, MAX_NUMBER_LENGTH, "%d", *show_caption_above_media);
        keyPairForm_show_caption_above_media = keyValuePair_create(keyForm_show_caption_above_media,valueForm_show_caption_above_media);
        list_addElement(localVarFormParameters,keyPairForm_show_caption_above_media);
    }

    // form parameters
    char *keyForm_has_spoiler = NULL;
    char * valueForm_has_spoiler = 0;
    keyValuePair_t *keyPairForm_has_spoiler = 0;
    if (has_spoiler != NULL)
    {
        keyForm_has_spoiler = strdup("has_spoiler");
        valueForm_has_spoiler = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_has_spoiler, MAX_NUMBER_LENGTH, "%d", *has_spoiler);
        keyPairForm_has_spoiler = keyValuePair_create(keyForm_has_spoiler,valueForm_has_spoiler);
        list_addElement(localVarFormParameters,keyPairForm_has_spoiler);
    }

    // form parameters
    char *keyForm_disable_notification = NULL;
    char * valueForm_disable_notification = 0;
    keyValuePair_t *keyPairForm_disable_notification = 0;
    if (disable_notification != NULL)
    {
        keyForm_disable_notification = strdup("disable_notification");
        valueForm_disable_notification = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_disable_notification, MAX_NUMBER_LENGTH, "%d", *disable_notification);
        keyPairForm_disable_notification = keyValuePair_create(keyForm_disable_notification,valueForm_disable_notification);
        list_addElement(localVarFormParameters,keyPairForm_disable_notification);
    }

    // form parameters
    char *keyForm_protect_content = NULL;
    char * valueForm_protect_content = 0;
    keyValuePair_t *keyPairForm_protect_content = 0;
    if (protect_content != NULL)
    {
        keyForm_protect_content = strdup("protect_content");
        valueForm_protect_content = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_protect_content, MAX_NUMBER_LENGTH, "%d", *protect_content);
        keyPairForm_protect_content = keyValuePair_create(keyForm_protect_content,valueForm_protect_content);
        list_addElement(localVarFormParameters,keyPairForm_protect_content);
    }

    // form parameters
    char *keyForm_allow_paid_broadcast = NULL;
    char * valueForm_allow_paid_broadcast = 0;
    keyValuePair_t *keyPairForm_allow_paid_broadcast = 0;
    if (allow_paid_broadcast != NULL)
    {
        keyForm_allow_paid_broadcast = strdup("allow_paid_broadcast");
        valueForm_allow_paid_broadcast = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_allow_paid_broadcast, MAX_NUMBER_LENGTH, "%d", *allow_paid_broadcast);
        keyPairForm_allow_paid_broadcast = keyValuePair_create(keyForm_allow_paid_broadcast,valueForm_allow_paid_broadcast);
        list_addElement(localVarFormParameters,keyPairForm_allow_paid_broadcast);
    }

    // form parameters
    char *keyForm_message_effect_id = NULL;
    char * valueForm_message_effect_id = 0;
    keyValuePair_t *keyPairForm_message_effect_id = 0;
    if (message_effect_id != NULL)
    {
        keyForm_message_effect_id = strdup("message_effect_id");
        valueForm_message_effect_id = strdup((message_effect_id));
        keyPairForm_message_effect_id = keyValuePair_create(keyForm_message_effect_id,valueForm_message_effect_id);
        list_addElement(localVarFormParameters,keyPairForm_message_effect_id);
    }

    // form parameters
    char *keyForm_reply_parameters = NULL;
    reply_parameters_t * valueForm_reply_parameters = 0;
    keyValuePair_t *keyPairForm_reply_parameters = 0;
    if (reply_parameters != NULL)
    {
        keyForm_reply_parameters = strdup("reply_parameters");
        valueForm_reply_parameters = (reply_parameters);
        keyPairForm_reply_parameters = keyValuePair_create(keyForm_reply_parameters,&valueForm_reply_parameters);
        list_addElement(localVarFormParameters,keyPairForm_reply_parameters);
    }

    // form parameters
    char *keyForm_reply_markup = NULL;
    post_send_message_request_reply_markup_t * valueForm_reply_markup = 0;
    keyValuePair_t *keyPairForm_reply_markup = 0;
    if (reply_markup != NULL)
    {
        keyForm_reply_markup = strdup("reply_markup");
        valueForm_reply_markup = (reply_markup);
        keyPairForm_reply_markup = keyValuePair_create(keyForm_reply_markup,&valueForm_reply_markup);
        list_addElement(localVarFormParameters,keyPairForm_reply_markup);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_send_message_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_send_message_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_business_connection_id) {
        free(keyForm_business_connection_id);
        keyForm_business_connection_id = NULL;
    }
    if (valueForm_business_connection_id) {
        free(valueForm_business_connection_id);
        valueForm_business_connection_id = NULL;
    }
    free(keyPairForm_business_connection_id);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_message_thread_id) {
        free(keyForm_message_thread_id);
        keyForm_message_thread_id = NULL;
    }
    free(keyPairForm_message_thread_id);
    if (keyForm_photo) {
        free(keyForm_photo);
        keyForm_photo = NULL;
    }
    free(keyPairForm_photo);
    if (keyForm_caption) {
        free(keyForm_caption);
        keyForm_caption = NULL;
    }
    if (valueForm_caption) {
        free(valueForm_caption);
        valueForm_caption = NULL;
    }
    free(keyPairForm_caption);
    if (keyForm_parse_mode) {
        free(keyForm_parse_mode);
        keyForm_parse_mode = NULL;
    }
    if (valueForm_parse_mode) {
        free(valueForm_parse_mode);
        valueForm_parse_mode = NULL;
    }
    free(keyPairForm_parse_mode);
    if (keyForm_caption_entities) {
        free(keyForm_caption_entities);
        keyForm_caption_entities = NULL;
    }
    free(keyPairForm_caption_entities);
    if (keyForm_show_caption_above_media) {
        free(keyForm_show_caption_above_media);
        keyForm_show_caption_above_media = NULL;
    }
    free(keyPairForm_show_caption_above_media);
    if (keyForm_has_spoiler) {
        free(keyForm_has_spoiler);
        keyForm_has_spoiler = NULL;
    }
    free(keyPairForm_has_spoiler);
    if (keyForm_disable_notification) {
        free(keyForm_disable_notification);
        keyForm_disable_notification = NULL;
    }
    free(keyPairForm_disable_notification);
    if (keyForm_protect_content) {
        free(keyForm_protect_content);
        keyForm_protect_content = NULL;
    }
    free(keyPairForm_protect_content);
    if (keyForm_allow_paid_broadcast) {
        free(keyForm_allow_paid_broadcast);
        keyForm_allow_paid_broadcast = NULL;
    }
    free(keyPairForm_allow_paid_broadcast);
    if (keyForm_message_effect_id) {
        free(keyForm_message_effect_id);
        keyForm_message_effect_id = NULL;
    }
    if (valueForm_message_effect_id) {
        free(valueForm_message_effect_id);
        valueForm_message_effect_id = NULL;
    }
    free(keyPairForm_message_effect_id);
    if (keyForm_reply_parameters) {
        free(keyForm_reply_parameters);
        keyForm_reply_parameters = NULL;
    }
    free(keyPairForm_reply_parameters);
    if (keyForm_reply_markup) {
        free(keyForm_reply_markup);
        keyForm_reply_markup = NULL;
    }
    free(keyPairForm_reply_markup);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// sendPoll
//
// Use this method to send a native poll. On success, the sent [Message](https://core.telegram.org/bots/api/#message) is returned.
//
post_send_message_200_response_t*
DefaultAPI_postSendPoll(apiClient_t *apiClient, post_send_message_request_chat_id_t *chat_id, char *question, list_t *options, char *business_connection_id, int *message_thread_id, char *question_parse_mode, list_t *question_entities, int *is_anonymous, telegram_bot_api_postSendPoll_type_e type, int *allows_multiple_answers, int *correct_option_id, char *explanation, char *explanation_parse_mode, list_t *explanation_entities, int *open_period, int *close_date, int *is_closed, int *disable_notification, int *protect_content, int *allow_paid_broadcast, char *message_effect_id, reply_parameters_t *reply_parameters, post_send_message_request_reply_markup_t *reply_markup)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/sendPoll");





    // form parameters
    char *keyForm_business_connection_id = NULL;
    char * valueForm_business_connection_id = 0;
    keyValuePair_t *keyPairForm_business_connection_id = 0;
    if (business_connection_id != NULL)
    {
        keyForm_business_connection_id = strdup("business_connection_id");
        valueForm_business_connection_id = strdup((business_connection_id));
        keyPairForm_business_connection_id = keyValuePair_create(keyForm_business_connection_id,valueForm_business_connection_id);
        list_addElement(localVarFormParameters,keyPairForm_business_connection_id);
    }

    // form parameters
    char *keyForm_chat_id = NULL;
    post_send_message_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_message_thread_id = NULL;
    int valueForm_message_thread_id = 0;
    keyValuePair_t *keyPairForm_message_thread_id = 0;
    if (message_thread_id != NULL)
    {
        keyForm_message_thread_id = strdup("message_thread_id");
        valueForm_message_thread_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_message_thread_id, MAX_NUMBER_LENGTH, "%d", *message_thread_id);
        keyPairForm_message_thread_id = keyValuePair_create(keyForm_message_thread_id,&valueForm_message_thread_id);
        list_addElement(localVarFormParameters,keyPairForm_message_thread_id);
    }

    // form parameters
    char *keyForm_question = NULL;
    char * valueForm_question = 0;
    keyValuePair_t *keyPairForm_question = 0;
    if (question != NULL)
    {
        keyForm_question = strdup("question");
        valueForm_question = strdup((question));
        keyPairForm_question = keyValuePair_create(keyForm_question,valueForm_question);
        list_addElement(localVarFormParameters,keyPairForm_question);
    }

    // form parameters
    char *keyForm_question_parse_mode = NULL;
    char * valueForm_question_parse_mode = 0;
    keyValuePair_t *keyPairForm_question_parse_mode = 0;
    if (question_parse_mode != NULL)
    {
        keyForm_question_parse_mode = strdup("question_parse_mode");
        valueForm_question_parse_mode = strdup((question_parse_mode));
        keyPairForm_question_parse_mode = keyValuePair_create(keyForm_question_parse_mode,valueForm_question_parse_mode);
        list_addElement(localVarFormParameters,keyPairForm_question_parse_mode);
    }

    // form parameters
    char *keyForm_question_entities = NULL;
     valueForm_question_entities = 0;
    keyValuePair_t *keyPairForm_question_entities = 0;
    if (question_entities != NULL)
    {
        keyForm_question_entities = strdup("question_entities");
        valueForm_question_entities = (question_entities);
        keyPairForm_question_entities = keyValuePair_create(keyForm_question_entities,&valueForm_question_entities);
        list_addElement(localVarFormParameters,keyPairForm_question_entities);
    }

    // form parameters
    char *keyForm_options = NULL;
     valueForm_options = 0;
    keyValuePair_t *keyPairForm_options = 0;
    if (options != NULL)
    {
        keyForm_options = strdup("options");
        valueForm_options = (options);
        keyPairForm_options = keyValuePair_create(keyForm_options,&valueForm_options);
        list_addElement(localVarFormParameters,keyPairForm_options);
    }

    // form parameters
    char *keyForm_is_anonymous = NULL;
    char * valueForm_is_anonymous = 0;
    keyValuePair_t *keyPairForm_is_anonymous = 0;
    if (is_anonymous != NULL)
    {
        keyForm_is_anonymous = strdup("is_anonymous");
        valueForm_is_anonymous = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_is_anonymous, MAX_NUMBER_LENGTH, "%d", *is_anonymous);
        keyPairForm_is_anonymous = keyValuePair_create(keyForm_is_anonymous,valueForm_is_anonymous);
        list_addElement(localVarFormParameters,keyPairForm_is_anonymous);
    }

    // form parameters
    char *keyForm_type = NULL;
    telegram_bot_api_postSendPoll_type_e valueForm_type = 0;
    keyValuePair_t *keyPairForm_type = 0;
    if (type != 0)
    {
        keyForm_type = strdup("type");
        valueForm_type = (type);
        keyPairForm_type = keyValuePair_create(keyForm_type,(void *)valueForm_type);
        list_addElement(localVarFormParameters,keyPairForm_type);
    }

    // form parameters
    char *keyForm_allows_multiple_answers = NULL;
    char * valueForm_allows_multiple_answers = 0;
    keyValuePair_t *keyPairForm_allows_multiple_answers = 0;
    if (allows_multiple_answers != NULL)
    {
        keyForm_allows_multiple_answers = strdup("allows_multiple_answers");
        valueForm_allows_multiple_answers = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_allows_multiple_answers, MAX_NUMBER_LENGTH, "%d", *allows_multiple_answers);
        keyPairForm_allows_multiple_answers = keyValuePair_create(keyForm_allows_multiple_answers,valueForm_allows_multiple_answers);
        list_addElement(localVarFormParameters,keyPairForm_allows_multiple_answers);
    }

    // form parameters
    char *keyForm_correct_option_id = NULL;
    int valueForm_correct_option_id = 0;
    keyValuePair_t *keyPairForm_correct_option_id = 0;
    if (correct_option_id != NULL)
    {
        keyForm_correct_option_id = strdup("correct_option_id");
        valueForm_correct_option_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_correct_option_id, MAX_NUMBER_LENGTH, "%d", *correct_option_id);
        keyPairForm_correct_option_id = keyValuePair_create(keyForm_correct_option_id,&valueForm_correct_option_id);
        list_addElement(localVarFormParameters,keyPairForm_correct_option_id);
    }

    // form parameters
    char *keyForm_explanation = NULL;
    char * valueForm_explanation = 0;
    keyValuePair_t *keyPairForm_explanation = 0;
    if (explanation != NULL)
    {
        keyForm_explanation = strdup("explanation");
        valueForm_explanation = strdup((explanation));
        keyPairForm_explanation = keyValuePair_create(keyForm_explanation,valueForm_explanation);
        list_addElement(localVarFormParameters,keyPairForm_explanation);
    }

    // form parameters
    char *keyForm_explanation_parse_mode = NULL;
    char * valueForm_explanation_parse_mode = 0;
    keyValuePair_t *keyPairForm_explanation_parse_mode = 0;
    if (explanation_parse_mode != NULL)
    {
        keyForm_explanation_parse_mode = strdup("explanation_parse_mode");
        valueForm_explanation_parse_mode = strdup((explanation_parse_mode));
        keyPairForm_explanation_parse_mode = keyValuePair_create(keyForm_explanation_parse_mode,valueForm_explanation_parse_mode);
        list_addElement(localVarFormParameters,keyPairForm_explanation_parse_mode);
    }

    // form parameters
    char *keyForm_explanation_entities = NULL;
     valueForm_explanation_entities = 0;
    keyValuePair_t *keyPairForm_explanation_entities = 0;
    if (explanation_entities != NULL)
    {
        keyForm_explanation_entities = strdup("explanation_entities");
        valueForm_explanation_entities = (explanation_entities);
        keyPairForm_explanation_entities = keyValuePair_create(keyForm_explanation_entities,&valueForm_explanation_entities);
        list_addElement(localVarFormParameters,keyPairForm_explanation_entities);
    }

    // form parameters
    char *keyForm_open_period = NULL;
    int valueForm_open_period = 0;
    keyValuePair_t *keyPairForm_open_period = 0;
    if (open_period != NULL)
    {
        keyForm_open_period = strdup("open_period");
        valueForm_open_period = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_open_period, MAX_NUMBER_LENGTH, "%d", *open_period);
        keyPairForm_open_period = keyValuePair_create(keyForm_open_period,&valueForm_open_period);
        list_addElement(localVarFormParameters,keyPairForm_open_period);
    }

    // form parameters
    char *keyForm_close_date = NULL;
    int valueForm_close_date = 0;
    keyValuePair_t *keyPairForm_close_date = 0;
    if (close_date != NULL)
    {
        keyForm_close_date = strdup("close_date");
        valueForm_close_date = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_close_date, MAX_NUMBER_LENGTH, "%d", *close_date);
        keyPairForm_close_date = keyValuePair_create(keyForm_close_date,&valueForm_close_date);
        list_addElement(localVarFormParameters,keyPairForm_close_date);
    }

    // form parameters
    char *keyForm_is_closed = NULL;
    char * valueForm_is_closed = 0;
    keyValuePair_t *keyPairForm_is_closed = 0;
    if (is_closed != NULL)
    {
        keyForm_is_closed = strdup("is_closed");
        valueForm_is_closed = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_is_closed, MAX_NUMBER_LENGTH, "%d", *is_closed);
        keyPairForm_is_closed = keyValuePair_create(keyForm_is_closed,valueForm_is_closed);
        list_addElement(localVarFormParameters,keyPairForm_is_closed);
    }

    // form parameters
    char *keyForm_disable_notification = NULL;
    char * valueForm_disable_notification = 0;
    keyValuePair_t *keyPairForm_disable_notification = 0;
    if (disable_notification != NULL)
    {
        keyForm_disable_notification = strdup("disable_notification");
        valueForm_disable_notification = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_disable_notification, MAX_NUMBER_LENGTH, "%d", *disable_notification);
        keyPairForm_disable_notification = keyValuePair_create(keyForm_disable_notification,valueForm_disable_notification);
        list_addElement(localVarFormParameters,keyPairForm_disable_notification);
    }

    // form parameters
    char *keyForm_protect_content = NULL;
    char * valueForm_protect_content = 0;
    keyValuePair_t *keyPairForm_protect_content = 0;
    if (protect_content != NULL)
    {
        keyForm_protect_content = strdup("protect_content");
        valueForm_protect_content = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_protect_content, MAX_NUMBER_LENGTH, "%d", *protect_content);
        keyPairForm_protect_content = keyValuePair_create(keyForm_protect_content,valueForm_protect_content);
        list_addElement(localVarFormParameters,keyPairForm_protect_content);
    }

    // form parameters
    char *keyForm_allow_paid_broadcast = NULL;
    char * valueForm_allow_paid_broadcast = 0;
    keyValuePair_t *keyPairForm_allow_paid_broadcast = 0;
    if (allow_paid_broadcast != NULL)
    {
        keyForm_allow_paid_broadcast = strdup("allow_paid_broadcast");
        valueForm_allow_paid_broadcast = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_allow_paid_broadcast, MAX_NUMBER_LENGTH, "%d", *allow_paid_broadcast);
        keyPairForm_allow_paid_broadcast = keyValuePair_create(keyForm_allow_paid_broadcast,valueForm_allow_paid_broadcast);
        list_addElement(localVarFormParameters,keyPairForm_allow_paid_broadcast);
    }

    // form parameters
    char *keyForm_message_effect_id = NULL;
    char * valueForm_message_effect_id = 0;
    keyValuePair_t *keyPairForm_message_effect_id = 0;
    if (message_effect_id != NULL)
    {
        keyForm_message_effect_id = strdup("message_effect_id");
        valueForm_message_effect_id = strdup((message_effect_id));
        keyPairForm_message_effect_id = keyValuePair_create(keyForm_message_effect_id,valueForm_message_effect_id);
        list_addElement(localVarFormParameters,keyPairForm_message_effect_id);
    }

    // form parameters
    char *keyForm_reply_parameters = NULL;
    reply_parameters_t * valueForm_reply_parameters = 0;
    keyValuePair_t *keyPairForm_reply_parameters = 0;
    if (reply_parameters != NULL)
    {
        keyForm_reply_parameters = strdup("reply_parameters");
        valueForm_reply_parameters = (reply_parameters);
        keyPairForm_reply_parameters = keyValuePair_create(keyForm_reply_parameters,&valueForm_reply_parameters);
        list_addElement(localVarFormParameters,keyPairForm_reply_parameters);
    }

    // form parameters
    char *keyForm_reply_markup = NULL;
    post_send_message_request_reply_markup_t * valueForm_reply_markup = 0;
    keyValuePair_t *keyPairForm_reply_markup = 0;
    if (reply_markup != NULL)
    {
        keyForm_reply_markup = strdup("reply_markup");
        valueForm_reply_markup = (reply_markup);
        keyPairForm_reply_markup = keyValuePair_create(keyForm_reply_markup,&valueForm_reply_markup);
        list_addElement(localVarFormParameters,keyPairForm_reply_markup);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_send_message_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_send_message_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_business_connection_id) {
        free(keyForm_business_connection_id);
        keyForm_business_connection_id = NULL;
    }
    if (valueForm_business_connection_id) {
        free(valueForm_business_connection_id);
        valueForm_business_connection_id = NULL;
    }
    free(keyPairForm_business_connection_id);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_message_thread_id) {
        free(keyForm_message_thread_id);
        keyForm_message_thread_id = NULL;
    }
    free(keyPairForm_message_thread_id);
    if (keyForm_question) {
        free(keyForm_question);
        keyForm_question = NULL;
    }
    if (valueForm_question) {
        free(valueForm_question);
        valueForm_question = NULL;
    }
    free(keyPairForm_question);
    if (keyForm_question_parse_mode) {
        free(keyForm_question_parse_mode);
        keyForm_question_parse_mode = NULL;
    }
    if (valueForm_question_parse_mode) {
        free(valueForm_question_parse_mode);
        valueForm_question_parse_mode = NULL;
    }
    free(keyPairForm_question_parse_mode);
    if (keyForm_question_entities) {
        free(keyForm_question_entities);
        keyForm_question_entities = NULL;
    }
    free(keyPairForm_question_entities);
    if (keyForm_options) {
        free(keyForm_options);
        keyForm_options = NULL;
    }
    free(keyPairForm_options);
    if (keyForm_is_anonymous) {
        free(keyForm_is_anonymous);
        keyForm_is_anonymous = NULL;
    }
    free(keyPairForm_is_anonymous);
    if (keyForm_type) {
        free(keyForm_type);
        keyForm_type = NULL;
    }
    if (valueForm_type) {
        valueForm_type = 0;
    }
    free(keyPairForm_type);
    if (keyForm_allows_multiple_answers) {
        free(keyForm_allows_multiple_answers);
        keyForm_allows_multiple_answers = NULL;
    }
    free(keyPairForm_allows_multiple_answers);
    if (keyForm_correct_option_id) {
        free(keyForm_correct_option_id);
        keyForm_correct_option_id = NULL;
    }
    free(keyPairForm_correct_option_id);
    if (keyForm_explanation) {
        free(keyForm_explanation);
        keyForm_explanation = NULL;
    }
    if (valueForm_explanation) {
        free(valueForm_explanation);
        valueForm_explanation = NULL;
    }
    free(keyPairForm_explanation);
    if (keyForm_explanation_parse_mode) {
        free(keyForm_explanation_parse_mode);
        keyForm_explanation_parse_mode = NULL;
    }
    if (valueForm_explanation_parse_mode) {
        free(valueForm_explanation_parse_mode);
        valueForm_explanation_parse_mode = NULL;
    }
    free(keyPairForm_explanation_parse_mode);
    if (keyForm_explanation_entities) {
        free(keyForm_explanation_entities);
        keyForm_explanation_entities = NULL;
    }
    free(keyPairForm_explanation_entities);
    if (keyForm_open_period) {
        free(keyForm_open_period);
        keyForm_open_period = NULL;
    }
    free(keyPairForm_open_period);
    if (keyForm_close_date) {
        free(keyForm_close_date);
        keyForm_close_date = NULL;
    }
    free(keyPairForm_close_date);
    if (keyForm_is_closed) {
        free(keyForm_is_closed);
        keyForm_is_closed = NULL;
    }
    free(keyPairForm_is_closed);
    if (keyForm_disable_notification) {
        free(keyForm_disable_notification);
        keyForm_disable_notification = NULL;
    }
    free(keyPairForm_disable_notification);
    if (keyForm_protect_content) {
        free(keyForm_protect_content);
        keyForm_protect_content = NULL;
    }
    free(keyPairForm_protect_content);
    if (keyForm_allow_paid_broadcast) {
        free(keyForm_allow_paid_broadcast);
        keyForm_allow_paid_broadcast = NULL;
    }
    free(keyPairForm_allow_paid_broadcast);
    if (keyForm_message_effect_id) {
        free(keyForm_message_effect_id);
        keyForm_message_effect_id = NULL;
    }
    if (valueForm_message_effect_id) {
        free(valueForm_message_effect_id);
        valueForm_message_effect_id = NULL;
    }
    free(keyPairForm_message_effect_id);
    if (keyForm_reply_parameters) {
        free(keyForm_reply_parameters);
        keyForm_reply_parameters = NULL;
    }
    free(keyPairForm_reply_parameters);
    if (keyForm_reply_markup) {
        free(keyForm_reply_markup);
        keyForm_reply_markup = NULL;
    }
    free(keyPairForm_reply_markup);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// sendSticker
//
// Use this method to send static .WEBP, [animated](https://telegram.org/blog/animated-stickers) .TGS, or [video](https://telegram.org/blog/video-stickers-better-reactions) .WEBM stickers. On success, the sent [Message](https://core.telegram.org/bots/api/#message) is returned.
//
post_send_message_200_response_t*
DefaultAPI_postSendSticker(apiClient_t *apiClient, post_send_message_request_chat_id_t *chat_id, post_send_sticker_request_sticker_t *sticker, char *business_connection_id, int *message_thread_id, char *emoji, int *disable_notification, int *protect_content, int *allow_paid_broadcast, char *message_effect_id, reply_parameters_t *reply_parameters, post_send_message_request_reply_markup_t *reply_markup)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/sendSticker");





    // form parameters
    char *keyForm_business_connection_id = NULL;
    char * valueForm_business_connection_id = 0;
    keyValuePair_t *keyPairForm_business_connection_id = 0;
    if (business_connection_id != NULL)
    {
        keyForm_business_connection_id = strdup("business_connection_id");
        valueForm_business_connection_id = strdup((business_connection_id));
        keyPairForm_business_connection_id = keyValuePair_create(keyForm_business_connection_id,valueForm_business_connection_id);
        list_addElement(localVarFormParameters,keyPairForm_business_connection_id);
    }

    // form parameters
    char *keyForm_chat_id = NULL;
    post_send_message_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_message_thread_id = NULL;
    int valueForm_message_thread_id = 0;
    keyValuePair_t *keyPairForm_message_thread_id = 0;
    if (message_thread_id != NULL)
    {
        keyForm_message_thread_id = strdup("message_thread_id");
        valueForm_message_thread_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_message_thread_id, MAX_NUMBER_LENGTH, "%d", *message_thread_id);
        keyPairForm_message_thread_id = keyValuePair_create(keyForm_message_thread_id,&valueForm_message_thread_id);
        list_addElement(localVarFormParameters,keyPairForm_message_thread_id);
    }

    // form parameters
    char *keyForm_sticker = NULL;
    post_send_sticker_request_sticker_t * valueForm_sticker = 0;
    keyValuePair_t *keyPairForm_sticker = 0;
    if (sticker != NULL)
    {
        keyForm_sticker = strdup("sticker");
        valueForm_sticker = (sticker);
        keyPairForm_sticker = keyValuePair_create(keyForm_sticker,&valueForm_sticker);
        list_addElement(localVarFormParameters,keyPairForm_sticker);
    }

    // form parameters
    char *keyForm_emoji = NULL;
    char * valueForm_emoji = 0;
    keyValuePair_t *keyPairForm_emoji = 0;
    if (emoji != NULL)
    {
        keyForm_emoji = strdup("emoji");
        valueForm_emoji = strdup((emoji));
        keyPairForm_emoji = keyValuePair_create(keyForm_emoji,valueForm_emoji);
        list_addElement(localVarFormParameters,keyPairForm_emoji);
    }

    // form parameters
    char *keyForm_disable_notification = NULL;
    char * valueForm_disable_notification = 0;
    keyValuePair_t *keyPairForm_disable_notification = 0;
    if (disable_notification != NULL)
    {
        keyForm_disable_notification = strdup("disable_notification");
        valueForm_disable_notification = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_disable_notification, MAX_NUMBER_LENGTH, "%d", *disable_notification);
        keyPairForm_disable_notification = keyValuePair_create(keyForm_disable_notification,valueForm_disable_notification);
        list_addElement(localVarFormParameters,keyPairForm_disable_notification);
    }

    // form parameters
    char *keyForm_protect_content = NULL;
    char * valueForm_protect_content = 0;
    keyValuePair_t *keyPairForm_protect_content = 0;
    if (protect_content != NULL)
    {
        keyForm_protect_content = strdup("protect_content");
        valueForm_protect_content = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_protect_content, MAX_NUMBER_LENGTH, "%d", *protect_content);
        keyPairForm_protect_content = keyValuePair_create(keyForm_protect_content,valueForm_protect_content);
        list_addElement(localVarFormParameters,keyPairForm_protect_content);
    }

    // form parameters
    char *keyForm_allow_paid_broadcast = NULL;
    char * valueForm_allow_paid_broadcast = 0;
    keyValuePair_t *keyPairForm_allow_paid_broadcast = 0;
    if (allow_paid_broadcast != NULL)
    {
        keyForm_allow_paid_broadcast = strdup("allow_paid_broadcast");
        valueForm_allow_paid_broadcast = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_allow_paid_broadcast, MAX_NUMBER_LENGTH, "%d", *allow_paid_broadcast);
        keyPairForm_allow_paid_broadcast = keyValuePair_create(keyForm_allow_paid_broadcast,valueForm_allow_paid_broadcast);
        list_addElement(localVarFormParameters,keyPairForm_allow_paid_broadcast);
    }

    // form parameters
    char *keyForm_message_effect_id = NULL;
    char * valueForm_message_effect_id = 0;
    keyValuePair_t *keyPairForm_message_effect_id = 0;
    if (message_effect_id != NULL)
    {
        keyForm_message_effect_id = strdup("message_effect_id");
        valueForm_message_effect_id = strdup((message_effect_id));
        keyPairForm_message_effect_id = keyValuePair_create(keyForm_message_effect_id,valueForm_message_effect_id);
        list_addElement(localVarFormParameters,keyPairForm_message_effect_id);
    }

    // form parameters
    char *keyForm_reply_parameters = NULL;
    reply_parameters_t * valueForm_reply_parameters = 0;
    keyValuePair_t *keyPairForm_reply_parameters = 0;
    if (reply_parameters != NULL)
    {
        keyForm_reply_parameters = strdup("reply_parameters");
        valueForm_reply_parameters = (reply_parameters);
        keyPairForm_reply_parameters = keyValuePair_create(keyForm_reply_parameters,&valueForm_reply_parameters);
        list_addElement(localVarFormParameters,keyPairForm_reply_parameters);
    }

    // form parameters
    char *keyForm_reply_markup = NULL;
    post_send_message_request_reply_markup_t * valueForm_reply_markup = 0;
    keyValuePair_t *keyPairForm_reply_markup = 0;
    if (reply_markup != NULL)
    {
        keyForm_reply_markup = strdup("reply_markup");
        valueForm_reply_markup = (reply_markup);
        keyPairForm_reply_markup = keyValuePair_create(keyForm_reply_markup,&valueForm_reply_markup);
        list_addElement(localVarFormParameters,keyPairForm_reply_markup);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_send_message_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_send_message_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_business_connection_id) {
        free(keyForm_business_connection_id);
        keyForm_business_connection_id = NULL;
    }
    if (valueForm_business_connection_id) {
        free(valueForm_business_connection_id);
        valueForm_business_connection_id = NULL;
    }
    free(keyPairForm_business_connection_id);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_message_thread_id) {
        free(keyForm_message_thread_id);
        keyForm_message_thread_id = NULL;
    }
    free(keyPairForm_message_thread_id);
    if (keyForm_sticker) {
        free(keyForm_sticker);
        keyForm_sticker = NULL;
    }
    free(keyPairForm_sticker);
    if (keyForm_emoji) {
        free(keyForm_emoji);
        keyForm_emoji = NULL;
    }
    if (valueForm_emoji) {
        free(valueForm_emoji);
        valueForm_emoji = NULL;
    }
    free(keyPairForm_emoji);
    if (keyForm_disable_notification) {
        free(keyForm_disable_notification);
        keyForm_disable_notification = NULL;
    }
    free(keyPairForm_disable_notification);
    if (keyForm_protect_content) {
        free(keyForm_protect_content);
        keyForm_protect_content = NULL;
    }
    free(keyPairForm_protect_content);
    if (keyForm_allow_paid_broadcast) {
        free(keyForm_allow_paid_broadcast);
        keyForm_allow_paid_broadcast = NULL;
    }
    free(keyPairForm_allow_paid_broadcast);
    if (keyForm_message_effect_id) {
        free(keyForm_message_effect_id);
        keyForm_message_effect_id = NULL;
    }
    if (valueForm_message_effect_id) {
        free(valueForm_message_effect_id);
        valueForm_message_effect_id = NULL;
    }
    free(keyPairForm_message_effect_id);
    if (keyForm_reply_parameters) {
        free(keyForm_reply_parameters);
        keyForm_reply_parameters = NULL;
    }
    free(keyPairForm_reply_parameters);
    if (keyForm_reply_markup) {
        free(keyForm_reply_markup);
        keyForm_reply_markup = NULL;
    }
    free(keyPairForm_reply_markup);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// sendVenue
//
// Use this method to send information about a venue. On success, the sent [Message](https://core.telegram.org/bots/api/#message) is returned.
//
post_send_message_200_response_t*
DefaultAPI_postSendVenue(apiClient_t *apiClient, post_send_message_request_chat_id_t *chat_id, double latitude, double longitude, char *title, char *address, char *business_connection_id, int *message_thread_id, char *foursquare_id, char *foursquare_type, char *google_place_id, char *google_place_type, int *disable_notification, int *protect_content, int *allow_paid_broadcast, char *message_effect_id, reply_parameters_t *reply_parameters, post_send_message_request_reply_markup_t *reply_markup)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/sendVenue");





    // form parameters
    char *keyForm_business_connection_id = NULL;
    char * valueForm_business_connection_id = 0;
    keyValuePair_t *keyPairForm_business_connection_id = 0;
    if (business_connection_id != NULL)
    {
        keyForm_business_connection_id = strdup("business_connection_id");
        valueForm_business_connection_id = strdup((business_connection_id));
        keyPairForm_business_connection_id = keyValuePair_create(keyForm_business_connection_id,valueForm_business_connection_id);
        list_addElement(localVarFormParameters,keyPairForm_business_connection_id);
    }

    // form parameters
    char *keyForm_chat_id = NULL;
    post_send_message_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_message_thread_id = NULL;
    int valueForm_message_thread_id = 0;
    keyValuePair_t *keyPairForm_message_thread_id = 0;
    if (message_thread_id != NULL)
    {
        keyForm_message_thread_id = strdup("message_thread_id");
        valueForm_message_thread_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_message_thread_id, MAX_NUMBER_LENGTH, "%d", *message_thread_id);
        keyPairForm_message_thread_id = keyValuePair_create(keyForm_message_thread_id,&valueForm_message_thread_id);
        list_addElement(localVarFormParameters,keyPairForm_message_thread_id);
    }

    // form parameters
    char *keyForm_latitude = NULL;
    double valueForm_latitude = 0;
    keyValuePair_t *keyPairForm_latitude = 0;
    if (latitude != NULL)
    {
        keyForm_latitude = strdup("latitude");
        valueForm_latitude = (latitude);
        keyPairForm_latitude = keyValuePair_create(keyForm_latitude,&valueForm_latitude);
        list_addElement(localVarFormParameters,keyPairForm_latitude);
    }

    // form parameters
    char *keyForm_longitude = NULL;
    double valueForm_longitude = 0;
    keyValuePair_t *keyPairForm_longitude = 0;
    if (longitude != NULL)
    {
        keyForm_longitude = strdup("longitude");
        valueForm_longitude = (longitude);
        keyPairForm_longitude = keyValuePair_create(keyForm_longitude,&valueForm_longitude);
        list_addElement(localVarFormParameters,keyPairForm_longitude);
    }

    // form parameters
    char *keyForm_title = NULL;
    char * valueForm_title = 0;
    keyValuePair_t *keyPairForm_title = 0;
    if (title != NULL)
    {
        keyForm_title = strdup("title");
        valueForm_title = strdup((title));
        keyPairForm_title = keyValuePair_create(keyForm_title,valueForm_title);
        list_addElement(localVarFormParameters,keyPairForm_title);
    }

    // form parameters
    char *keyForm_address = NULL;
    char * valueForm_address = 0;
    keyValuePair_t *keyPairForm_address = 0;
    if (address != NULL)
    {
        keyForm_address = strdup("address");
        valueForm_address = strdup((address));
        keyPairForm_address = keyValuePair_create(keyForm_address,valueForm_address);
        list_addElement(localVarFormParameters,keyPairForm_address);
    }

    // form parameters
    char *keyForm_foursquare_id = NULL;
    char * valueForm_foursquare_id = 0;
    keyValuePair_t *keyPairForm_foursquare_id = 0;
    if (foursquare_id != NULL)
    {
        keyForm_foursquare_id = strdup("foursquare_id");
        valueForm_foursquare_id = strdup((foursquare_id));
        keyPairForm_foursquare_id = keyValuePair_create(keyForm_foursquare_id,valueForm_foursquare_id);
        list_addElement(localVarFormParameters,keyPairForm_foursquare_id);
    }

    // form parameters
    char *keyForm_foursquare_type = NULL;
    char * valueForm_foursquare_type = 0;
    keyValuePair_t *keyPairForm_foursquare_type = 0;
    if (foursquare_type != NULL)
    {
        keyForm_foursquare_type = strdup("foursquare_type");
        valueForm_foursquare_type = strdup((foursquare_type));
        keyPairForm_foursquare_type = keyValuePair_create(keyForm_foursquare_type,valueForm_foursquare_type);
        list_addElement(localVarFormParameters,keyPairForm_foursquare_type);
    }

    // form parameters
    char *keyForm_google_place_id = NULL;
    char * valueForm_google_place_id = 0;
    keyValuePair_t *keyPairForm_google_place_id = 0;
    if (google_place_id != NULL)
    {
        keyForm_google_place_id = strdup("google_place_id");
        valueForm_google_place_id = strdup((google_place_id));
        keyPairForm_google_place_id = keyValuePair_create(keyForm_google_place_id,valueForm_google_place_id);
        list_addElement(localVarFormParameters,keyPairForm_google_place_id);
    }

    // form parameters
    char *keyForm_google_place_type = NULL;
    char * valueForm_google_place_type = 0;
    keyValuePair_t *keyPairForm_google_place_type = 0;
    if (google_place_type != NULL)
    {
        keyForm_google_place_type = strdup("google_place_type");
        valueForm_google_place_type = strdup((google_place_type));
        keyPairForm_google_place_type = keyValuePair_create(keyForm_google_place_type,valueForm_google_place_type);
        list_addElement(localVarFormParameters,keyPairForm_google_place_type);
    }

    // form parameters
    char *keyForm_disable_notification = NULL;
    char * valueForm_disable_notification = 0;
    keyValuePair_t *keyPairForm_disable_notification = 0;
    if (disable_notification != NULL)
    {
        keyForm_disable_notification = strdup("disable_notification");
        valueForm_disable_notification = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_disable_notification, MAX_NUMBER_LENGTH, "%d", *disable_notification);
        keyPairForm_disable_notification = keyValuePair_create(keyForm_disable_notification,valueForm_disable_notification);
        list_addElement(localVarFormParameters,keyPairForm_disable_notification);
    }

    // form parameters
    char *keyForm_protect_content = NULL;
    char * valueForm_protect_content = 0;
    keyValuePair_t *keyPairForm_protect_content = 0;
    if (protect_content != NULL)
    {
        keyForm_protect_content = strdup("protect_content");
        valueForm_protect_content = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_protect_content, MAX_NUMBER_LENGTH, "%d", *protect_content);
        keyPairForm_protect_content = keyValuePair_create(keyForm_protect_content,valueForm_protect_content);
        list_addElement(localVarFormParameters,keyPairForm_protect_content);
    }

    // form parameters
    char *keyForm_allow_paid_broadcast = NULL;
    char * valueForm_allow_paid_broadcast = 0;
    keyValuePair_t *keyPairForm_allow_paid_broadcast = 0;
    if (allow_paid_broadcast != NULL)
    {
        keyForm_allow_paid_broadcast = strdup("allow_paid_broadcast");
        valueForm_allow_paid_broadcast = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_allow_paid_broadcast, MAX_NUMBER_LENGTH, "%d", *allow_paid_broadcast);
        keyPairForm_allow_paid_broadcast = keyValuePair_create(keyForm_allow_paid_broadcast,valueForm_allow_paid_broadcast);
        list_addElement(localVarFormParameters,keyPairForm_allow_paid_broadcast);
    }

    // form parameters
    char *keyForm_message_effect_id = NULL;
    char * valueForm_message_effect_id = 0;
    keyValuePair_t *keyPairForm_message_effect_id = 0;
    if (message_effect_id != NULL)
    {
        keyForm_message_effect_id = strdup("message_effect_id");
        valueForm_message_effect_id = strdup((message_effect_id));
        keyPairForm_message_effect_id = keyValuePair_create(keyForm_message_effect_id,valueForm_message_effect_id);
        list_addElement(localVarFormParameters,keyPairForm_message_effect_id);
    }

    // form parameters
    char *keyForm_reply_parameters = NULL;
    reply_parameters_t * valueForm_reply_parameters = 0;
    keyValuePair_t *keyPairForm_reply_parameters = 0;
    if (reply_parameters != NULL)
    {
        keyForm_reply_parameters = strdup("reply_parameters");
        valueForm_reply_parameters = (reply_parameters);
        keyPairForm_reply_parameters = keyValuePair_create(keyForm_reply_parameters,&valueForm_reply_parameters);
        list_addElement(localVarFormParameters,keyPairForm_reply_parameters);
    }

    // form parameters
    char *keyForm_reply_markup = NULL;
    post_send_message_request_reply_markup_t * valueForm_reply_markup = 0;
    keyValuePair_t *keyPairForm_reply_markup = 0;
    if (reply_markup != NULL)
    {
        keyForm_reply_markup = strdup("reply_markup");
        valueForm_reply_markup = (reply_markup);
        keyPairForm_reply_markup = keyValuePair_create(keyForm_reply_markup,&valueForm_reply_markup);
        list_addElement(localVarFormParameters,keyPairForm_reply_markup);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_send_message_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_send_message_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_business_connection_id) {
        free(keyForm_business_connection_id);
        keyForm_business_connection_id = NULL;
    }
    if (valueForm_business_connection_id) {
        free(valueForm_business_connection_id);
        valueForm_business_connection_id = NULL;
    }
    free(keyPairForm_business_connection_id);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_message_thread_id) {
        free(keyForm_message_thread_id);
        keyForm_message_thread_id = NULL;
    }
    free(keyPairForm_message_thread_id);
    if (keyForm_latitude) {
        free(keyForm_latitude);
        keyForm_latitude = NULL;
    }
    free(keyPairForm_latitude);
    if (keyForm_longitude) {
        free(keyForm_longitude);
        keyForm_longitude = NULL;
    }
    free(keyPairForm_longitude);
    if (keyForm_title) {
        free(keyForm_title);
        keyForm_title = NULL;
    }
    if (valueForm_title) {
        free(valueForm_title);
        valueForm_title = NULL;
    }
    free(keyPairForm_title);
    if (keyForm_address) {
        free(keyForm_address);
        keyForm_address = NULL;
    }
    if (valueForm_address) {
        free(valueForm_address);
        valueForm_address = NULL;
    }
    free(keyPairForm_address);
    if (keyForm_foursquare_id) {
        free(keyForm_foursquare_id);
        keyForm_foursquare_id = NULL;
    }
    if (valueForm_foursquare_id) {
        free(valueForm_foursquare_id);
        valueForm_foursquare_id = NULL;
    }
    free(keyPairForm_foursquare_id);
    if (keyForm_foursquare_type) {
        free(keyForm_foursquare_type);
        keyForm_foursquare_type = NULL;
    }
    if (valueForm_foursquare_type) {
        free(valueForm_foursquare_type);
        valueForm_foursquare_type = NULL;
    }
    free(keyPairForm_foursquare_type);
    if (keyForm_google_place_id) {
        free(keyForm_google_place_id);
        keyForm_google_place_id = NULL;
    }
    if (valueForm_google_place_id) {
        free(valueForm_google_place_id);
        valueForm_google_place_id = NULL;
    }
    free(keyPairForm_google_place_id);
    if (keyForm_google_place_type) {
        free(keyForm_google_place_type);
        keyForm_google_place_type = NULL;
    }
    if (valueForm_google_place_type) {
        free(valueForm_google_place_type);
        valueForm_google_place_type = NULL;
    }
    free(keyPairForm_google_place_type);
    if (keyForm_disable_notification) {
        free(keyForm_disable_notification);
        keyForm_disable_notification = NULL;
    }
    free(keyPairForm_disable_notification);
    if (keyForm_protect_content) {
        free(keyForm_protect_content);
        keyForm_protect_content = NULL;
    }
    free(keyPairForm_protect_content);
    if (keyForm_allow_paid_broadcast) {
        free(keyForm_allow_paid_broadcast);
        keyForm_allow_paid_broadcast = NULL;
    }
    free(keyPairForm_allow_paid_broadcast);
    if (keyForm_message_effect_id) {
        free(keyForm_message_effect_id);
        keyForm_message_effect_id = NULL;
    }
    if (valueForm_message_effect_id) {
        free(valueForm_message_effect_id);
        valueForm_message_effect_id = NULL;
    }
    free(keyPairForm_message_effect_id);
    if (keyForm_reply_parameters) {
        free(keyForm_reply_parameters);
        keyForm_reply_parameters = NULL;
    }
    free(keyPairForm_reply_parameters);
    if (keyForm_reply_markup) {
        free(keyForm_reply_markup);
        keyForm_reply_markup = NULL;
    }
    free(keyPairForm_reply_markup);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// sendVideo
//
// Use this method to send video files, Telegram clients support MPEG4 videos (other formats may be sent as [Document](https://core.telegram.org/bots/api/#document)). On success, the sent [Message](https://core.telegram.org/bots/api/#message) is returned. Bots can currently send video files of up to 50 MB in size, this limit may be changed in the future.
//
post_send_message_200_response_t*
DefaultAPI_postSendVideo(apiClient_t *apiClient, post_send_message_request_chat_id_t *chat_id, post_send_video_request_video_t *video, char *business_connection_id, int *message_thread_id, int *duration, int *width, int *height, post_send_audio_request_thumbnail_t *thumbnail, post_send_video_request_cover_t *cover, int *start_timestamp, char *caption, char *parse_mode, list_t *caption_entities, int *show_caption_above_media, int *has_spoiler, int *supports_streaming, int *disable_notification, int *protect_content, int *allow_paid_broadcast, char *message_effect_id, reply_parameters_t *reply_parameters, post_send_message_request_reply_markup_t *reply_markup)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/sendVideo");





    // form parameters
    char *keyForm_business_connection_id = NULL;
    char * valueForm_business_connection_id = 0;
    keyValuePair_t *keyPairForm_business_connection_id = 0;
    if (business_connection_id != NULL)
    {
        keyForm_business_connection_id = strdup("business_connection_id");
        valueForm_business_connection_id = strdup((business_connection_id));
        keyPairForm_business_connection_id = keyValuePair_create(keyForm_business_connection_id,valueForm_business_connection_id);
        list_addElement(localVarFormParameters,keyPairForm_business_connection_id);
    }

    // form parameters
    char *keyForm_chat_id = NULL;
    post_send_message_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_message_thread_id = NULL;
    int valueForm_message_thread_id = 0;
    keyValuePair_t *keyPairForm_message_thread_id = 0;
    if (message_thread_id != NULL)
    {
        keyForm_message_thread_id = strdup("message_thread_id");
        valueForm_message_thread_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_message_thread_id, MAX_NUMBER_LENGTH, "%d", *message_thread_id);
        keyPairForm_message_thread_id = keyValuePair_create(keyForm_message_thread_id,&valueForm_message_thread_id);
        list_addElement(localVarFormParameters,keyPairForm_message_thread_id);
    }

    // form parameters
    char *keyForm_video = NULL;
    post_send_video_request_video_t * valueForm_video = 0;
    keyValuePair_t *keyPairForm_video = 0;
    if (video != NULL)
    {
        keyForm_video = strdup("video");
        valueForm_video = (video);
        keyPairForm_video = keyValuePair_create(keyForm_video,&valueForm_video);
        list_addElement(localVarFormParameters,keyPairForm_video);
    }

    // form parameters
    char *keyForm_duration = NULL;
    int valueForm_duration = 0;
    keyValuePair_t *keyPairForm_duration = 0;
    if (duration != NULL)
    {
        keyForm_duration = strdup("duration");
        valueForm_duration = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_duration, MAX_NUMBER_LENGTH, "%d", *duration);
        keyPairForm_duration = keyValuePair_create(keyForm_duration,&valueForm_duration);
        list_addElement(localVarFormParameters,keyPairForm_duration);
    }

    // form parameters
    char *keyForm_width = NULL;
    int valueForm_width = 0;
    keyValuePair_t *keyPairForm_width = 0;
    if (width != NULL)
    {
        keyForm_width = strdup("width");
        valueForm_width = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_width, MAX_NUMBER_LENGTH, "%d", *width);
        keyPairForm_width = keyValuePair_create(keyForm_width,&valueForm_width);
        list_addElement(localVarFormParameters,keyPairForm_width);
    }

    // form parameters
    char *keyForm_height = NULL;
    int valueForm_height = 0;
    keyValuePair_t *keyPairForm_height = 0;
    if (height != NULL)
    {
        keyForm_height = strdup("height");
        valueForm_height = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_height, MAX_NUMBER_LENGTH, "%d", *height);
        keyPairForm_height = keyValuePair_create(keyForm_height,&valueForm_height);
        list_addElement(localVarFormParameters,keyPairForm_height);
    }

    // form parameters
    char *keyForm_thumbnail = NULL;
    post_send_audio_request_thumbnail_t * valueForm_thumbnail = 0;
    keyValuePair_t *keyPairForm_thumbnail = 0;
    if (thumbnail != NULL)
    {
        keyForm_thumbnail = strdup("thumbnail");
        valueForm_thumbnail = (thumbnail);
        keyPairForm_thumbnail = keyValuePair_create(keyForm_thumbnail,&valueForm_thumbnail);
        list_addElement(localVarFormParameters,keyPairForm_thumbnail);
    }

    // form parameters
    char *keyForm_cover = NULL;
    post_send_video_request_cover_t * valueForm_cover = 0;
    keyValuePair_t *keyPairForm_cover = 0;
    if (cover != NULL)
    {
        keyForm_cover = strdup("cover");
        valueForm_cover = (cover);
        keyPairForm_cover = keyValuePair_create(keyForm_cover,&valueForm_cover);
        list_addElement(localVarFormParameters,keyPairForm_cover);
    }

    // form parameters
    char *keyForm_start_timestamp = NULL;
    int valueForm_start_timestamp = 0;
    keyValuePair_t *keyPairForm_start_timestamp = 0;
    if (start_timestamp != NULL)
    {
        keyForm_start_timestamp = strdup("start_timestamp");
        valueForm_start_timestamp = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_start_timestamp, MAX_NUMBER_LENGTH, "%d", *start_timestamp);
        keyPairForm_start_timestamp = keyValuePair_create(keyForm_start_timestamp,&valueForm_start_timestamp);
        list_addElement(localVarFormParameters,keyPairForm_start_timestamp);
    }

    // form parameters
    char *keyForm_caption = NULL;
    char * valueForm_caption = 0;
    keyValuePair_t *keyPairForm_caption = 0;
    if (caption != NULL)
    {
        keyForm_caption = strdup("caption");
        valueForm_caption = strdup((caption));
        keyPairForm_caption = keyValuePair_create(keyForm_caption,valueForm_caption);
        list_addElement(localVarFormParameters,keyPairForm_caption);
    }

    // form parameters
    char *keyForm_parse_mode = NULL;
    char * valueForm_parse_mode = 0;
    keyValuePair_t *keyPairForm_parse_mode = 0;
    if (parse_mode != NULL)
    {
        keyForm_parse_mode = strdup("parse_mode");
        valueForm_parse_mode = strdup((parse_mode));
        keyPairForm_parse_mode = keyValuePair_create(keyForm_parse_mode,valueForm_parse_mode);
        list_addElement(localVarFormParameters,keyPairForm_parse_mode);
    }

    // form parameters
    char *keyForm_caption_entities = NULL;
     valueForm_caption_entities = 0;
    keyValuePair_t *keyPairForm_caption_entities = 0;
    if (caption_entities != NULL)
    {
        keyForm_caption_entities = strdup("caption_entities");
        valueForm_caption_entities = (caption_entities);
        keyPairForm_caption_entities = keyValuePair_create(keyForm_caption_entities,&valueForm_caption_entities);
        list_addElement(localVarFormParameters,keyPairForm_caption_entities);
    }

    // form parameters
    char *keyForm_show_caption_above_media = NULL;
    char * valueForm_show_caption_above_media = 0;
    keyValuePair_t *keyPairForm_show_caption_above_media = 0;
    if (show_caption_above_media != NULL)
    {
        keyForm_show_caption_above_media = strdup("show_caption_above_media");
        valueForm_show_caption_above_media = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_show_caption_above_media, MAX_NUMBER_LENGTH, "%d", *show_caption_above_media);
        keyPairForm_show_caption_above_media = keyValuePair_create(keyForm_show_caption_above_media,valueForm_show_caption_above_media);
        list_addElement(localVarFormParameters,keyPairForm_show_caption_above_media);
    }

    // form parameters
    char *keyForm_has_spoiler = NULL;
    char * valueForm_has_spoiler = 0;
    keyValuePair_t *keyPairForm_has_spoiler = 0;
    if (has_spoiler != NULL)
    {
        keyForm_has_spoiler = strdup("has_spoiler");
        valueForm_has_spoiler = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_has_spoiler, MAX_NUMBER_LENGTH, "%d", *has_spoiler);
        keyPairForm_has_spoiler = keyValuePair_create(keyForm_has_spoiler,valueForm_has_spoiler);
        list_addElement(localVarFormParameters,keyPairForm_has_spoiler);
    }

    // form parameters
    char *keyForm_supports_streaming = NULL;
    char * valueForm_supports_streaming = 0;
    keyValuePair_t *keyPairForm_supports_streaming = 0;
    if (supports_streaming != NULL)
    {
        keyForm_supports_streaming = strdup("supports_streaming");
        valueForm_supports_streaming = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_supports_streaming, MAX_NUMBER_LENGTH, "%d", *supports_streaming);
        keyPairForm_supports_streaming = keyValuePair_create(keyForm_supports_streaming,valueForm_supports_streaming);
        list_addElement(localVarFormParameters,keyPairForm_supports_streaming);
    }

    // form parameters
    char *keyForm_disable_notification = NULL;
    char * valueForm_disable_notification = 0;
    keyValuePair_t *keyPairForm_disable_notification = 0;
    if (disable_notification != NULL)
    {
        keyForm_disable_notification = strdup("disable_notification");
        valueForm_disable_notification = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_disable_notification, MAX_NUMBER_LENGTH, "%d", *disable_notification);
        keyPairForm_disable_notification = keyValuePair_create(keyForm_disable_notification,valueForm_disable_notification);
        list_addElement(localVarFormParameters,keyPairForm_disable_notification);
    }

    // form parameters
    char *keyForm_protect_content = NULL;
    char * valueForm_protect_content = 0;
    keyValuePair_t *keyPairForm_protect_content = 0;
    if (protect_content != NULL)
    {
        keyForm_protect_content = strdup("protect_content");
        valueForm_protect_content = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_protect_content, MAX_NUMBER_LENGTH, "%d", *protect_content);
        keyPairForm_protect_content = keyValuePair_create(keyForm_protect_content,valueForm_protect_content);
        list_addElement(localVarFormParameters,keyPairForm_protect_content);
    }

    // form parameters
    char *keyForm_allow_paid_broadcast = NULL;
    char * valueForm_allow_paid_broadcast = 0;
    keyValuePair_t *keyPairForm_allow_paid_broadcast = 0;
    if (allow_paid_broadcast != NULL)
    {
        keyForm_allow_paid_broadcast = strdup("allow_paid_broadcast");
        valueForm_allow_paid_broadcast = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_allow_paid_broadcast, MAX_NUMBER_LENGTH, "%d", *allow_paid_broadcast);
        keyPairForm_allow_paid_broadcast = keyValuePair_create(keyForm_allow_paid_broadcast,valueForm_allow_paid_broadcast);
        list_addElement(localVarFormParameters,keyPairForm_allow_paid_broadcast);
    }

    // form parameters
    char *keyForm_message_effect_id = NULL;
    char * valueForm_message_effect_id = 0;
    keyValuePair_t *keyPairForm_message_effect_id = 0;
    if (message_effect_id != NULL)
    {
        keyForm_message_effect_id = strdup("message_effect_id");
        valueForm_message_effect_id = strdup((message_effect_id));
        keyPairForm_message_effect_id = keyValuePair_create(keyForm_message_effect_id,valueForm_message_effect_id);
        list_addElement(localVarFormParameters,keyPairForm_message_effect_id);
    }

    // form parameters
    char *keyForm_reply_parameters = NULL;
    reply_parameters_t * valueForm_reply_parameters = 0;
    keyValuePair_t *keyPairForm_reply_parameters = 0;
    if (reply_parameters != NULL)
    {
        keyForm_reply_parameters = strdup("reply_parameters");
        valueForm_reply_parameters = (reply_parameters);
        keyPairForm_reply_parameters = keyValuePair_create(keyForm_reply_parameters,&valueForm_reply_parameters);
        list_addElement(localVarFormParameters,keyPairForm_reply_parameters);
    }

    // form parameters
    char *keyForm_reply_markup = NULL;
    post_send_message_request_reply_markup_t * valueForm_reply_markup = 0;
    keyValuePair_t *keyPairForm_reply_markup = 0;
    if (reply_markup != NULL)
    {
        keyForm_reply_markup = strdup("reply_markup");
        valueForm_reply_markup = (reply_markup);
        keyPairForm_reply_markup = keyValuePair_create(keyForm_reply_markup,&valueForm_reply_markup);
        list_addElement(localVarFormParameters,keyPairForm_reply_markup);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_send_message_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_send_message_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_business_connection_id) {
        free(keyForm_business_connection_id);
        keyForm_business_connection_id = NULL;
    }
    if (valueForm_business_connection_id) {
        free(valueForm_business_connection_id);
        valueForm_business_connection_id = NULL;
    }
    free(keyPairForm_business_connection_id);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_message_thread_id) {
        free(keyForm_message_thread_id);
        keyForm_message_thread_id = NULL;
    }
    free(keyPairForm_message_thread_id);
    if (keyForm_video) {
        free(keyForm_video);
        keyForm_video = NULL;
    }
    free(keyPairForm_video);
    if (keyForm_duration) {
        free(keyForm_duration);
        keyForm_duration = NULL;
    }
    free(keyPairForm_duration);
    if (keyForm_width) {
        free(keyForm_width);
        keyForm_width = NULL;
    }
    free(keyPairForm_width);
    if (keyForm_height) {
        free(keyForm_height);
        keyForm_height = NULL;
    }
    free(keyPairForm_height);
    if (keyForm_thumbnail) {
        free(keyForm_thumbnail);
        keyForm_thumbnail = NULL;
    }
    free(keyPairForm_thumbnail);
    if (keyForm_cover) {
        free(keyForm_cover);
        keyForm_cover = NULL;
    }
    free(keyPairForm_cover);
    if (keyForm_start_timestamp) {
        free(keyForm_start_timestamp);
        keyForm_start_timestamp = NULL;
    }
    free(keyPairForm_start_timestamp);
    if (keyForm_caption) {
        free(keyForm_caption);
        keyForm_caption = NULL;
    }
    if (valueForm_caption) {
        free(valueForm_caption);
        valueForm_caption = NULL;
    }
    free(keyPairForm_caption);
    if (keyForm_parse_mode) {
        free(keyForm_parse_mode);
        keyForm_parse_mode = NULL;
    }
    if (valueForm_parse_mode) {
        free(valueForm_parse_mode);
        valueForm_parse_mode = NULL;
    }
    free(keyPairForm_parse_mode);
    if (keyForm_caption_entities) {
        free(keyForm_caption_entities);
        keyForm_caption_entities = NULL;
    }
    free(keyPairForm_caption_entities);
    if (keyForm_show_caption_above_media) {
        free(keyForm_show_caption_above_media);
        keyForm_show_caption_above_media = NULL;
    }
    free(keyPairForm_show_caption_above_media);
    if (keyForm_has_spoiler) {
        free(keyForm_has_spoiler);
        keyForm_has_spoiler = NULL;
    }
    free(keyPairForm_has_spoiler);
    if (keyForm_supports_streaming) {
        free(keyForm_supports_streaming);
        keyForm_supports_streaming = NULL;
    }
    free(keyPairForm_supports_streaming);
    if (keyForm_disable_notification) {
        free(keyForm_disable_notification);
        keyForm_disable_notification = NULL;
    }
    free(keyPairForm_disable_notification);
    if (keyForm_protect_content) {
        free(keyForm_protect_content);
        keyForm_protect_content = NULL;
    }
    free(keyPairForm_protect_content);
    if (keyForm_allow_paid_broadcast) {
        free(keyForm_allow_paid_broadcast);
        keyForm_allow_paid_broadcast = NULL;
    }
    free(keyPairForm_allow_paid_broadcast);
    if (keyForm_message_effect_id) {
        free(keyForm_message_effect_id);
        keyForm_message_effect_id = NULL;
    }
    if (valueForm_message_effect_id) {
        free(valueForm_message_effect_id);
        valueForm_message_effect_id = NULL;
    }
    free(keyPairForm_message_effect_id);
    if (keyForm_reply_parameters) {
        free(keyForm_reply_parameters);
        keyForm_reply_parameters = NULL;
    }
    free(keyPairForm_reply_parameters);
    if (keyForm_reply_markup) {
        free(keyForm_reply_markup);
        keyForm_reply_markup = NULL;
    }
    free(keyPairForm_reply_markup);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// sendVideoNote
//
// As of [v.4.0](https://telegram.org/blog/video-messages-and-telescope), Telegram clients support rounded square MPEG4 videos of up to 1 minute long. Use this method to send video messages. On success, the sent [Message](https://core.telegram.org/bots/api/#message) is returned.
//
post_send_message_200_response_t*
DefaultAPI_postSendVideoNote(apiClient_t *apiClient, post_send_message_request_chat_id_t *chat_id, post_send_video_note_request_video_note_t *video_note, char *business_connection_id, int *message_thread_id, int *duration, int *length, post_send_audio_request_thumbnail_t *thumbnail, int *disable_notification, int *protect_content, int *allow_paid_broadcast, char *message_effect_id, reply_parameters_t *reply_parameters, post_send_message_request_reply_markup_t *reply_markup)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/sendVideoNote");





    // form parameters
    char *keyForm_business_connection_id = NULL;
    char * valueForm_business_connection_id = 0;
    keyValuePair_t *keyPairForm_business_connection_id = 0;
    if (business_connection_id != NULL)
    {
        keyForm_business_connection_id = strdup("business_connection_id");
        valueForm_business_connection_id = strdup((business_connection_id));
        keyPairForm_business_connection_id = keyValuePair_create(keyForm_business_connection_id,valueForm_business_connection_id);
        list_addElement(localVarFormParameters,keyPairForm_business_connection_id);
    }

    // form parameters
    char *keyForm_chat_id = NULL;
    post_send_message_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_message_thread_id = NULL;
    int valueForm_message_thread_id = 0;
    keyValuePair_t *keyPairForm_message_thread_id = 0;
    if (message_thread_id != NULL)
    {
        keyForm_message_thread_id = strdup("message_thread_id");
        valueForm_message_thread_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_message_thread_id, MAX_NUMBER_LENGTH, "%d", *message_thread_id);
        keyPairForm_message_thread_id = keyValuePair_create(keyForm_message_thread_id,&valueForm_message_thread_id);
        list_addElement(localVarFormParameters,keyPairForm_message_thread_id);
    }

    // form parameters
    char *keyForm_video_note = NULL;
    post_send_video_note_request_video_note_t * valueForm_video_note = 0;
    keyValuePair_t *keyPairForm_video_note = 0;
    if (video_note != NULL)
    {
        keyForm_video_note = strdup("video_note");
        valueForm_video_note = (video_note);
        keyPairForm_video_note = keyValuePair_create(keyForm_video_note,&valueForm_video_note);
        list_addElement(localVarFormParameters,keyPairForm_video_note);
    }

    // form parameters
    char *keyForm_duration = NULL;
    int valueForm_duration = 0;
    keyValuePair_t *keyPairForm_duration = 0;
    if (duration != NULL)
    {
        keyForm_duration = strdup("duration");
        valueForm_duration = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_duration, MAX_NUMBER_LENGTH, "%d", *duration);
        keyPairForm_duration = keyValuePair_create(keyForm_duration,&valueForm_duration);
        list_addElement(localVarFormParameters,keyPairForm_duration);
    }

    // form parameters
    char *keyForm_length = NULL;
    int valueForm_length = 0;
    keyValuePair_t *keyPairForm_length = 0;
    if (length != NULL)
    {
        keyForm_length = strdup("length");
        valueForm_length = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_length, MAX_NUMBER_LENGTH, "%d", *length);
        keyPairForm_length = keyValuePair_create(keyForm_length,&valueForm_length);
        list_addElement(localVarFormParameters,keyPairForm_length);
    }

    // form parameters
    char *keyForm_thumbnail = NULL;
    post_send_audio_request_thumbnail_t * valueForm_thumbnail = 0;
    keyValuePair_t *keyPairForm_thumbnail = 0;
    if (thumbnail != NULL)
    {
        keyForm_thumbnail = strdup("thumbnail");
        valueForm_thumbnail = (thumbnail);
        keyPairForm_thumbnail = keyValuePair_create(keyForm_thumbnail,&valueForm_thumbnail);
        list_addElement(localVarFormParameters,keyPairForm_thumbnail);
    }

    // form parameters
    char *keyForm_disable_notification = NULL;
    char * valueForm_disable_notification = 0;
    keyValuePair_t *keyPairForm_disable_notification = 0;
    if (disable_notification != NULL)
    {
        keyForm_disable_notification = strdup("disable_notification");
        valueForm_disable_notification = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_disable_notification, MAX_NUMBER_LENGTH, "%d", *disable_notification);
        keyPairForm_disable_notification = keyValuePair_create(keyForm_disable_notification,valueForm_disable_notification);
        list_addElement(localVarFormParameters,keyPairForm_disable_notification);
    }

    // form parameters
    char *keyForm_protect_content = NULL;
    char * valueForm_protect_content = 0;
    keyValuePair_t *keyPairForm_protect_content = 0;
    if (protect_content != NULL)
    {
        keyForm_protect_content = strdup("protect_content");
        valueForm_protect_content = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_protect_content, MAX_NUMBER_LENGTH, "%d", *protect_content);
        keyPairForm_protect_content = keyValuePair_create(keyForm_protect_content,valueForm_protect_content);
        list_addElement(localVarFormParameters,keyPairForm_protect_content);
    }

    // form parameters
    char *keyForm_allow_paid_broadcast = NULL;
    char * valueForm_allow_paid_broadcast = 0;
    keyValuePair_t *keyPairForm_allow_paid_broadcast = 0;
    if (allow_paid_broadcast != NULL)
    {
        keyForm_allow_paid_broadcast = strdup("allow_paid_broadcast");
        valueForm_allow_paid_broadcast = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_allow_paid_broadcast, MAX_NUMBER_LENGTH, "%d", *allow_paid_broadcast);
        keyPairForm_allow_paid_broadcast = keyValuePair_create(keyForm_allow_paid_broadcast,valueForm_allow_paid_broadcast);
        list_addElement(localVarFormParameters,keyPairForm_allow_paid_broadcast);
    }

    // form parameters
    char *keyForm_message_effect_id = NULL;
    char * valueForm_message_effect_id = 0;
    keyValuePair_t *keyPairForm_message_effect_id = 0;
    if (message_effect_id != NULL)
    {
        keyForm_message_effect_id = strdup("message_effect_id");
        valueForm_message_effect_id = strdup((message_effect_id));
        keyPairForm_message_effect_id = keyValuePair_create(keyForm_message_effect_id,valueForm_message_effect_id);
        list_addElement(localVarFormParameters,keyPairForm_message_effect_id);
    }

    // form parameters
    char *keyForm_reply_parameters = NULL;
    reply_parameters_t * valueForm_reply_parameters = 0;
    keyValuePair_t *keyPairForm_reply_parameters = 0;
    if (reply_parameters != NULL)
    {
        keyForm_reply_parameters = strdup("reply_parameters");
        valueForm_reply_parameters = (reply_parameters);
        keyPairForm_reply_parameters = keyValuePair_create(keyForm_reply_parameters,&valueForm_reply_parameters);
        list_addElement(localVarFormParameters,keyPairForm_reply_parameters);
    }

    // form parameters
    char *keyForm_reply_markup = NULL;
    post_send_message_request_reply_markup_t * valueForm_reply_markup = 0;
    keyValuePair_t *keyPairForm_reply_markup = 0;
    if (reply_markup != NULL)
    {
        keyForm_reply_markup = strdup("reply_markup");
        valueForm_reply_markup = (reply_markup);
        keyPairForm_reply_markup = keyValuePair_create(keyForm_reply_markup,&valueForm_reply_markup);
        list_addElement(localVarFormParameters,keyPairForm_reply_markup);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_send_message_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_send_message_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_business_connection_id) {
        free(keyForm_business_connection_id);
        keyForm_business_connection_id = NULL;
    }
    if (valueForm_business_connection_id) {
        free(valueForm_business_connection_id);
        valueForm_business_connection_id = NULL;
    }
    free(keyPairForm_business_connection_id);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_message_thread_id) {
        free(keyForm_message_thread_id);
        keyForm_message_thread_id = NULL;
    }
    free(keyPairForm_message_thread_id);
    if (keyForm_video_note) {
        free(keyForm_video_note);
        keyForm_video_note = NULL;
    }
    free(keyPairForm_video_note);
    if (keyForm_duration) {
        free(keyForm_duration);
        keyForm_duration = NULL;
    }
    free(keyPairForm_duration);
    if (keyForm_length) {
        free(keyForm_length);
        keyForm_length = NULL;
    }
    free(keyPairForm_length);
    if (keyForm_thumbnail) {
        free(keyForm_thumbnail);
        keyForm_thumbnail = NULL;
    }
    free(keyPairForm_thumbnail);
    if (keyForm_disable_notification) {
        free(keyForm_disable_notification);
        keyForm_disable_notification = NULL;
    }
    free(keyPairForm_disable_notification);
    if (keyForm_protect_content) {
        free(keyForm_protect_content);
        keyForm_protect_content = NULL;
    }
    free(keyPairForm_protect_content);
    if (keyForm_allow_paid_broadcast) {
        free(keyForm_allow_paid_broadcast);
        keyForm_allow_paid_broadcast = NULL;
    }
    free(keyPairForm_allow_paid_broadcast);
    if (keyForm_message_effect_id) {
        free(keyForm_message_effect_id);
        keyForm_message_effect_id = NULL;
    }
    if (valueForm_message_effect_id) {
        free(valueForm_message_effect_id);
        valueForm_message_effect_id = NULL;
    }
    free(keyPairForm_message_effect_id);
    if (keyForm_reply_parameters) {
        free(keyForm_reply_parameters);
        keyForm_reply_parameters = NULL;
    }
    free(keyPairForm_reply_parameters);
    if (keyForm_reply_markup) {
        free(keyForm_reply_markup);
        keyForm_reply_markup = NULL;
    }
    free(keyPairForm_reply_markup);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// sendVoice
//
// Use this method to send audio files, if you want Telegram clients to display the file as a playable voice message. For this to work, your audio must be in an .OGG file encoded with OPUS, or in .MP3 format, or in .M4A format (other formats may be sent as [Audio](https://core.telegram.org/bots/api/#audio) or [Document](https://core.telegram.org/bots/api/#document)). On success, the sent [Message](https://core.telegram.org/bots/api/#message) is returned. Bots can currently send voice messages of up to 50 MB in size, this limit may be changed in the future.
//
post_send_message_200_response_t*
DefaultAPI_postSendVoice(apiClient_t *apiClient, post_send_message_request_chat_id_t *chat_id, post_send_voice_request_voice_t *voice, char *business_connection_id, int *message_thread_id, char *caption, char *parse_mode, list_t *caption_entities, int *duration, int *disable_notification, int *protect_content, int *allow_paid_broadcast, char *message_effect_id, reply_parameters_t *reply_parameters, post_send_message_request_reply_markup_t *reply_markup)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/sendVoice");





    // form parameters
    char *keyForm_business_connection_id = NULL;
    char * valueForm_business_connection_id = 0;
    keyValuePair_t *keyPairForm_business_connection_id = 0;
    if (business_connection_id != NULL)
    {
        keyForm_business_connection_id = strdup("business_connection_id");
        valueForm_business_connection_id = strdup((business_connection_id));
        keyPairForm_business_connection_id = keyValuePair_create(keyForm_business_connection_id,valueForm_business_connection_id);
        list_addElement(localVarFormParameters,keyPairForm_business_connection_id);
    }

    // form parameters
    char *keyForm_chat_id = NULL;
    post_send_message_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_message_thread_id = NULL;
    int valueForm_message_thread_id = 0;
    keyValuePair_t *keyPairForm_message_thread_id = 0;
    if (message_thread_id != NULL)
    {
        keyForm_message_thread_id = strdup("message_thread_id");
        valueForm_message_thread_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_message_thread_id, MAX_NUMBER_LENGTH, "%d", *message_thread_id);
        keyPairForm_message_thread_id = keyValuePair_create(keyForm_message_thread_id,&valueForm_message_thread_id);
        list_addElement(localVarFormParameters,keyPairForm_message_thread_id);
    }

    // form parameters
    char *keyForm_voice = NULL;
    post_send_voice_request_voice_t * valueForm_voice = 0;
    keyValuePair_t *keyPairForm_voice = 0;
    if (voice != NULL)
    {
        keyForm_voice = strdup("voice");
        valueForm_voice = (voice);
        keyPairForm_voice = keyValuePair_create(keyForm_voice,&valueForm_voice);
        list_addElement(localVarFormParameters,keyPairForm_voice);
    }

    // form parameters
    char *keyForm_caption = NULL;
    char * valueForm_caption = 0;
    keyValuePair_t *keyPairForm_caption = 0;
    if (caption != NULL)
    {
        keyForm_caption = strdup("caption");
        valueForm_caption = strdup((caption));
        keyPairForm_caption = keyValuePair_create(keyForm_caption,valueForm_caption);
        list_addElement(localVarFormParameters,keyPairForm_caption);
    }

    // form parameters
    char *keyForm_parse_mode = NULL;
    char * valueForm_parse_mode = 0;
    keyValuePair_t *keyPairForm_parse_mode = 0;
    if (parse_mode != NULL)
    {
        keyForm_parse_mode = strdup("parse_mode");
        valueForm_parse_mode = strdup((parse_mode));
        keyPairForm_parse_mode = keyValuePair_create(keyForm_parse_mode,valueForm_parse_mode);
        list_addElement(localVarFormParameters,keyPairForm_parse_mode);
    }

    // form parameters
    char *keyForm_caption_entities = NULL;
     valueForm_caption_entities = 0;
    keyValuePair_t *keyPairForm_caption_entities = 0;
    if (caption_entities != NULL)
    {
        keyForm_caption_entities = strdup("caption_entities");
        valueForm_caption_entities = (caption_entities);
        keyPairForm_caption_entities = keyValuePair_create(keyForm_caption_entities,&valueForm_caption_entities);
        list_addElement(localVarFormParameters,keyPairForm_caption_entities);
    }

    // form parameters
    char *keyForm_duration = NULL;
    int valueForm_duration = 0;
    keyValuePair_t *keyPairForm_duration = 0;
    if (duration != NULL)
    {
        keyForm_duration = strdup("duration");
        valueForm_duration = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_duration, MAX_NUMBER_LENGTH, "%d", *duration);
        keyPairForm_duration = keyValuePair_create(keyForm_duration,&valueForm_duration);
        list_addElement(localVarFormParameters,keyPairForm_duration);
    }

    // form parameters
    char *keyForm_disable_notification = NULL;
    char * valueForm_disable_notification = 0;
    keyValuePair_t *keyPairForm_disable_notification = 0;
    if (disable_notification != NULL)
    {
        keyForm_disable_notification = strdup("disable_notification");
        valueForm_disable_notification = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_disable_notification, MAX_NUMBER_LENGTH, "%d", *disable_notification);
        keyPairForm_disable_notification = keyValuePair_create(keyForm_disable_notification,valueForm_disable_notification);
        list_addElement(localVarFormParameters,keyPairForm_disable_notification);
    }

    // form parameters
    char *keyForm_protect_content = NULL;
    char * valueForm_protect_content = 0;
    keyValuePair_t *keyPairForm_protect_content = 0;
    if (protect_content != NULL)
    {
        keyForm_protect_content = strdup("protect_content");
        valueForm_protect_content = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_protect_content, MAX_NUMBER_LENGTH, "%d", *protect_content);
        keyPairForm_protect_content = keyValuePair_create(keyForm_protect_content,valueForm_protect_content);
        list_addElement(localVarFormParameters,keyPairForm_protect_content);
    }

    // form parameters
    char *keyForm_allow_paid_broadcast = NULL;
    char * valueForm_allow_paid_broadcast = 0;
    keyValuePair_t *keyPairForm_allow_paid_broadcast = 0;
    if (allow_paid_broadcast != NULL)
    {
        keyForm_allow_paid_broadcast = strdup("allow_paid_broadcast");
        valueForm_allow_paid_broadcast = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_allow_paid_broadcast, MAX_NUMBER_LENGTH, "%d", *allow_paid_broadcast);
        keyPairForm_allow_paid_broadcast = keyValuePair_create(keyForm_allow_paid_broadcast,valueForm_allow_paid_broadcast);
        list_addElement(localVarFormParameters,keyPairForm_allow_paid_broadcast);
    }

    // form parameters
    char *keyForm_message_effect_id = NULL;
    char * valueForm_message_effect_id = 0;
    keyValuePair_t *keyPairForm_message_effect_id = 0;
    if (message_effect_id != NULL)
    {
        keyForm_message_effect_id = strdup("message_effect_id");
        valueForm_message_effect_id = strdup((message_effect_id));
        keyPairForm_message_effect_id = keyValuePair_create(keyForm_message_effect_id,valueForm_message_effect_id);
        list_addElement(localVarFormParameters,keyPairForm_message_effect_id);
    }

    // form parameters
    char *keyForm_reply_parameters = NULL;
    reply_parameters_t * valueForm_reply_parameters = 0;
    keyValuePair_t *keyPairForm_reply_parameters = 0;
    if (reply_parameters != NULL)
    {
        keyForm_reply_parameters = strdup("reply_parameters");
        valueForm_reply_parameters = (reply_parameters);
        keyPairForm_reply_parameters = keyValuePair_create(keyForm_reply_parameters,&valueForm_reply_parameters);
        list_addElement(localVarFormParameters,keyPairForm_reply_parameters);
    }

    // form parameters
    char *keyForm_reply_markup = NULL;
    post_send_message_request_reply_markup_t * valueForm_reply_markup = 0;
    keyValuePair_t *keyPairForm_reply_markup = 0;
    if (reply_markup != NULL)
    {
        keyForm_reply_markup = strdup("reply_markup");
        valueForm_reply_markup = (reply_markup);
        keyPairForm_reply_markup = keyValuePair_create(keyForm_reply_markup,&valueForm_reply_markup);
        list_addElement(localVarFormParameters,keyPairForm_reply_markup);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_send_message_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_send_message_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_business_connection_id) {
        free(keyForm_business_connection_id);
        keyForm_business_connection_id = NULL;
    }
    if (valueForm_business_connection_id) {
        free(valueForm_business_connection_id);
        valueForm_business_connection_id = NULL;
    }
    free(keyPairForm_business_connection_id);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_message_thread_id) {
        free(keyForm_message_thread_id);
        keyForm_message_thread_id = NULL;
    }
    free(keyPairForm_message_thread_id);
    if (keyForm_voice) {
        free(keyForm_voice);
        keyForm_voice = NULL;
    }
    free(keyPairForm_voice);
    if (keyForm_caption) {
        free(keyForm_caption);
        keyForm_caption = NULL;
    }
    if (valueForm_caption) {
        free(valueForm_caption);
        valueForm_caption = NULL;
    }
    free(keyPairForm_caption);
    if (keyForm_parse_mode) {
        free(keyForm_parse_mode);
        keyForm_parse_mode = NULL;
    }
    if (valueForm_parse_mode) {
        free(valueForm_parse_mode);
        valueForm_parse_mode = NULL;
    }
    free(keyPairForm_parse_mode);
    if (keyForm_caption_entities) {
        free(keyForm_caption_entities);
        keyForm_caption_entities = NULL;
    }
    free(keyPairForm_caption_entities);
    if (keyForm_duration) {
        free(keyForm_duration);
        keyForm_duration = NULL;
    }
    free(keyPairForm_duration);
    if (keyForm_disable_notification) {
        free(keyForm_disable_notification);
        keyForm_disable_notification = NULL;
    }
    free(keyPairForm_disable_notification);
    if (keyForm_protect_content) {
        free(keyForm_protect_content);
        keyForm_protect_content = NULL;
    }
    free(keyPairForm_protect_content);
    if (keyForm_allow_paid_broadcast) {
        free(keyForm_allow_paid_broadcast);
        keyForm_allow_paid_broadcast = NULL;
    }
    free(keyPairForm_allow_paid_broadcast);
    if (keyForm_message_effect_id) {
        free(keyForm_message_effect_id);
        keyForm_message_effect_id = NULL;
    }
    if (valueForm_message_effect_id) {
        free(valueForm_message_effect_id);
        valueForm_message_effect_id = NULL;
    }
    free(keyPairForm_message_effect_id);
    if (keyForm_reply_parameters) {
        free(keyForm_reply_parameters);
        keyForm_reply_parameters = NULL;
    }
    free(keyPairForm_reply_parameters);
    if (keyForm_reply_markup) {
        free(keyForm_reply_markup);
        keyForm_reply_markup = NULL;
    }
    free(keyPairForm_reply_markup);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// setBusinessAccountBio
//
// Changes the bio of a managed business account. Requires the *can\\_change\\_bio* business bot right. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postSetBusinessAccountBio(apiClient_t *apiClient, char *business_connection_id, char *bio)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/setBusinessAccountBio");





    // form parameters
    char *keyForm_business_connection_id = NULL;
    char * valueForm_business_connection_id = 0;
    keyValuePair_t *keyPairForm_business_connection_id = 0;
    if (business_connection_id != NULL)
    {
        keyForm_business_connection_id = strdup("business_connection_id");
        valueForm_business_connection_id = strdup((business_connection_id));
        keyPairForm_business_connection_id = keyValuePair_create(keyForm_business_connection_id,valueForm_business_connection_id);
        list_addElement(localVarFormParameters,keyPairForm_business_connection_id);
    }

    // form parameters
    char *keyForm_bio = NULL;
    char * valueForm_bio = 0;
    keyValuePair_t *keyPairForm_bio = 0;
    if (bio != NULL)
    {
        keyForm_bio = strdup("bio");
        valueForm_bio = strdup((bio));
        keyPairForm_bio = keyValuePair_create(keyForm_bio,valueForm_bio);
        list_addElement(localVarFormParameters,keyPairForm_bio);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_business_connection_id) {
        free(keyForm_business_connection_id);
        keyForm_business_connection_id = NULL;
    }
    if (valueForm_business_connection_id) {
        free(valueForm_business_connection_id);
        valueForm_business_connection_id = NULL;
    }
    free(keyPairForm_business_connection_id);
    if (keyForm_bio) {
        free(keyForm_bio);
        keyForm_bio = NULL;
    }
    if (valueForm_bio) {
        free(valueForm_bio);
        valueForm_bio = NULL;
    }
    free(keyPairForm_bio);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// setBusinessAccountGiftSettings
//
// Changes the privacy settings pertaining to incoming gifts in a managed business account. Requires the *can\\_change\\_gift\\_settings* business bot right. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postSetBusinessAccountGiftSettings(apiClient_t *apiClient, char *business_connection_id, int *show_gift_button, accepted_gift_types_t *accepted_gift_types)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/setBusinessAccountGiftSettings");





    // form parameters
    char *keyForm_business_connection_id = NULL;
    char * valueForm_business_connection_id = 0;
    keyValuePair_t *keyPairForm_business_connection_id = 0;
    if (business_connection_id != NULL)
    {
        keyForm_business_connection_id = strdup("business_connection_id");
        valueForm_business_connection_id = strdup((business_connection_id));
        keyPairForm_business_connection_id = keyValuePair_create(keyForm_business_connection_id,valueForm_business_connection_id);
        list_addElement(localVarFormParameters,keyPairForm_business_connection_id);
    }

    // form parameters
    char *keyForm_show_gift_button = NULL;
    char * valueForm_show_gift_button = 0;
    keyValuePair_t *keyPairForm_show_gift_button = 0;
    if (show_gift_button != NULL)
    {
        keyForm_show_gift_button = strdup("show_gift_button");
        valueForm_show_gift_button = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_show_gift_button, MAX_NUMBER_LENGTH, "%d", *show_gift_button);
        keyPairForm_show_gift_button = keyValuePair_create(keyForm_show_gift_button,valueForm_show_gift_button);
        list_addElement(localVarFormParameters,keyPairForm_show_gift_button);
    }

    // form parameters
    char *keyForm_accepted_gift_types = NULL;
    accepted_gift_types_t * valueForm_accepted_gift_types = 0;
    keyValuePair_t *keyPairForm_accepted_gift_types = 0;
    if (accepted_gift_types != NULL)
    {
        keyForm_accepted_gift_types = strdup("accepted_gift_types");
        valueForm_accepted_gift_types = (accepted_gift_types);
        keyPairForm_accepted_gift_types = keyValuePair_create(keyForm_accepted_gift_types,&valueForm_accepted_gift_types);
        list_addElement(localVarFormParameters,keyPairForm_accepted_gift_types);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_business_connection_id) {
        free(keyForm_business_connection_id);
        keyForm_business_connection_id = NULL;
    }
    if (valueForm_business_connection_id) {
        free(valueForm_business_connection_id);
        valueForm_business_connection_id = NULL;
    }
    free(keyPairForm_business_connection_id);
    if (keyForm_show_gift_button) {
        free(keyForm_show_gift_button);
        keyForm_show_gift_button = NULL;
    }
    free(keyPairForm_show_gift_button);
    if (keyForm_accepted_gift_types) {
        free(keyForm_accepted_gift_types);
        keyForm_accepted_gift_types = NULL;
    }
    free(keyPairForm_accepted_gift_types);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// setBusinessAccountName
//
// Changes the first and last name of a managed business account. Requires the *can\\_change\\_name* business bot right. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postSetBusinessAccountName(apiClient_t *apiClient, char *business_connection_id, char *first_name, char *last_name)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/setBusinessAccountName");





    // form parameters
    char *keyForm_business_connection_id = NULL;
    char * valueForm_business_connection_id = 0;
    keyValuePair_t *keyPairForm_business_connection_id = 0;
    if (business_connection_id != NULL)
    {
        keyForm_business_connection_id = strdup("business_connection_id");
        valueForm_business_connection_id = strdup((business_connection_id));
        keyPairForm_business_connection_id = keyValuePair_create(keyForm_business_connection_id,valueForm_business_connection_id);
        list_addElement(localVarFormParameters,keyPairForm_business_connection_id);
    }

    // form parameters
    char *keyForm_first_name = NULL;
    char * valueForm_first_name = 0;
    keyValuePair_t *keyPairForm_first_name = 0;
    if (first_name != NULL)
    {
        keyForm_first_name = strdup("first_name");
        valueForm_first_name = strdup((first_name));
        keyPairForm_first_name = keyValuePair_create(keyForm_first_name,valueForm_first_name);
        list_addElement(localVarFormParameters,keyPairForm_first_name);
    }

    // form parameters
    char *keyForm_last_name = NULL;
    char * valueForm_last_name = 0;
    keyValuePair_t *keyPairForm_last_name = 0;
    if (last_name != NULL)
    {
        keyForm_last_name = strdup("last_name");
        valueForm_last_name = strdup((last_name));
        keyPairForm_last_name = keyValuePair_create(keyForm_last_name,valueForm_last_name);
        list_addElement(localVarFormParameters,keyPairForm_last_name);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_business_connection_id) {
        free(keyForm_business_connection_id);
        keyForm_business_connection_id = NULL;
    }
    if (valueForm_business_connection_id) {
        free(valueForm_business_connection_id);
        valueForm_business_connection_id = NULL;
    }
    free(keyPairForm_business_connection_id);
    if (keyForm_first_name) {
        free(keyForm_first_name);
        keyForm_first_name = NULL;
    }
    if (valueForm_first_name) {
        free(valueForm_first_name);
        valueForm_first_name = NULL;
    }
    free(keyPairForm_first_name);
    if (keyForm_last_name) {
        free(keyForm_last_name);
        keyForm_last_name = NULL;
    }
    if (valueForm_last_name) {
        free(valueForm_last_name);
        valueForm_last_name = NULL;
    }
    free(keyPairForm_last_name);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// setBusinessAccountProfilePhoto
//
// Changes the profile photo of a managed business account. Requires the *can\\_edit\\_profile\\_photo* business bot right. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postSetBusinessAccountProfilePhoto(apiClient_t *apiClient, char *business_connection_id, input_profile_photo_t *photo, int *is_public)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/setBusinessAccountProfilePhoto");





    // form parameters
    char *keyForm_business_connection_id = NULL;
    char * valueForm_business_connection_id = 0;
    keyValuePair_t *keyPairForm_business_connection_id = 0;
    if (business_connection_id != NULL)
    {
        keyForm_business_connection_id = strdup("business_connection_id");
        valueForm_business_connection_id = strdup((business_connection_id));
        keyPairForm_business_connection_id = keyValuePair_create(keyForm_business_connection_id,valueForm_business_connection_id);
        list_addElement(localVarFormParameters,keyPairForm_business_connection_id);
    }

    // form parameters
    char *keyForm_photo = NULL;
    input_profile_photo_t * valueForm_photo = 0;
    keyValuePair_t *keyPairForm_photo = 0;
    if (photo != NULL)
    {
        keyForm_photo = strdup("photo");
        valueForm_photo = (photo);
        keyPairForm_photo = keyValuePair_create(keyForm_photo,&valueForm_photo);
        list_addElement(localVarFormParameters,keyPairForm_photo);
    }

    // form parameters
    char *keyForm_is_public = NULL;
    char * valueForm_is_public = 0;
    keyValuePair_t *keyPairForm_is_public = 0;
    if (is_public != NULL)
    {
        keyForm_is_public = strdup("is_public");
        valueForm_is_public = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_is_public, MAX_NUMBER_LENGTH, "%d", *is_public);
        keyPairForm_is_public = keyValuePair_create(keyForm_is_public,valueForm_is_public);
        list_addElement(localVarFormParameters,keyPairForm_is_public);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_business_connection_id) {
        free(keyForm_business_connection_id);
        keyForm_business_connection_id = NULL;
    }
    if (valueForm_business_connection_id) {
        free(valueForm_business_connection_id);
        valueForm_business_connection_id = NULL;
    }
    free(keyPairForm_business_connection_id);
    if (keyForm_photo) {
        free(keyForm_photo);
        keyForm_photo = NULL;
    }
    free(keyPairForm_photo);
    if (keyForm_is_public) {
        free(keyForm_is_public);
        keyForm_is_public = NULL;
    }
    free(keyPairForm_is_public);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// setBusinessAccountUsername
//
// Changes the username of a managed business account. Requires the *can\\_change\\_username* business bot right. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postSetBusinessAccountUsername(apiClient_t *apiClient, char *business_connection_id, char *username)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/setBusinessAccountUsername");





    // form parameters
    char *keyForm_business_connection_id = NULL;
    char * valueForm_business_connection_id = 0;
    keyValuePair_t *keyPairForm_business_connection_id = 0;
    if (business_connection_id != NULL)
    {
        keyForm_business_connection_id = strdup("business_connection_id");
        valueForm_business_connection_id = strdup((business_connection_id));
        keyPairForm_business_connection_id = keyValuePair_create(keyForm_business_connection_id,valueForm_business_connection_id);
        list_addElement(localVarFormParameters,keyPairForm_business_connection_id);
    }

    // form parameters
    char *keyForm_username = NULL;
    char * valueForm_username = 0;
    keyValuePair_t *keyPairForm_username = 0;
    if (username != NULL)
    {
        keyForm_username = strdup("username");
        valueForm_username = strdup((username));
        keyPairForm_username = keyValuePair_create(keyForm_username,valueForm_username);
        list_addElement(localVarFormParameters,keyPairForm_username);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_business_connection_id) {
        free(keyForm_business_connection_id);
        keyForm_business_connection_id = NULL;
    }
    if (valueForm_business_connection_id) {
        free(valueForm_business_connection_id);
        valueForm_business_connection_id = NULL;
    }
    free(keyPairForm_business_connection_id);
    if (keyForm_username) {
        free(keyForm_username);
        keyForm_username = NULL;
    }
    if (valueForm_username) {
        free(valueForm_username);
        valueForm_username = NULL;
    }
    free(keyPairForm_username);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// setChatAdministratorCustomTitle
//
// Use this method to set a custom title for an administrator in a supergroup promoted by the bot. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postSetChatAdministratorCustomTitle(apiClient_t *apiClient, post_restrict_chat_member_request_chat_id_t *chat_id, int *user_id, char *custom_title)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/setChatAdministratorCustomTitle");





    // form parameters
    char *keyForm_chat_id = NULL;
    post_restrict_chat_member_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_user_id = NULL;
    int valueForm_user_id = 0;
    keyValuePair_t *keyPairForm_user_id = 0;
    if (user_id != NULL)
    {
        keyForm_user_id = strdup("user_id");
        valueForm_user_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_user_id, MAX_NUMBER_LENGTH, "%d", *user_id);
        keyPairForm_user_id = keyValuePair_create(keyForm_user_id,&valueForm_user_id);
        list_addElement(localVarFormParameters,keyPairForm_user_id);
    }

    // form parameters
    char *keyForm_custom_title = NULL;
    char * valueForm_custom_title = 0;
    keyValuePair_t *keyPairForm_custom_title = 0;
    if (custom_title != NULL)
    {
        keyForm_custom_title = strdup("custom_title");
        valueForm_custom_title = strdup((custom_title));
        keyPairForm_custom_title = keyValuePair_create(keyForm_custom_title,valueForm_custom_title);
        list_addElement(localVarFormParameters,keyPairForm_custom_title);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_user_id) {
        free(keyForm_user_id);
        keyForm_user_id = NULL;
    }
    free(keyPairForm_user_id);
    if (keyForm_custom_title) {
        free(keyForm_custom_title);
        keyForm_custom_title = NULL;
    }
    if (valueForm_custom_title) {
        free(valueForm_custom_title);
        valueForm_custom_title = NULL;
    }
    free(keyPairForm_custom_title);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// setChatDescription
//
// Use this method to change the description of a group, a supergroup or a channel. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postSetChatDescription(apiClient_t *apiClient, post_send_message_request_chat_id_t *chat_id, char *description)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/setChatDescription");





    // form parameters
    char *keyForm_chat_id = NULL;
    post_send_message_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_description = NULL;
    char * valueForm_description = 0;
    keyValuePair_t *keyPairForm_description = 0;
    if (description != NULL)
    {
        keyForm_description = strdup("description");
        valueForm_description = strdup((description));
        keyPairForm_description = keyValuePair_create(keyForm_description,valueForm_description);
        list_addElement(localVarFormParameters,keyPairForm_description);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_description) {
        free(keyForm_description);
        keyForm_description = NULL;
    }
    if (valueForm_description) {
        free(valueForm_description);
        valueForm_description = NULL;
    }
    free(keyPairForm_description);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// setChatMenuButton
//
// Use this method to change the bot's menu button in a private chat, or the default menu button. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postSetChatMenuButton(apiClient_t *apiClient, int *chat_id, menu_button_t *menu_button)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/setChatMenuButton");





    // form parameters
    char *keyForm_chat_id = NULL;
    int valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_chat_id, MAX_NUMBER_LENGTH, "%d", *chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_menu_button = NULL;
    menu_button_t * valueForm_menu_button = 0;
    keyValuePair_t *keyPairForm_menu_button = 0;
    if (menu_button != NULL)
    {
        keyForm_menu_button = strdup("menu_button");
        valueForm_menu_button = (menu_button);
        keyPairForm_menu_button = keyValuePair_create(keyForm_menu_button,&valueForm_menu_button);
        list_addElement(localVarFormParameters,keyPairForm_menu_button);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_menu_button) {
        free(keyForm_menu_button);
        keyForm_menu_button = NULL;
    }
    free(keyPairForm_menu_button);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// setChatPermissions
//
// Use this method to set default chat permissions for all members. The bot must be an administrator in the group or a supergroup for this to work and must have the *can\\_restrict\\_members* administrator rights. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postSetChatPermissions(apiClient_t *apiClient, post_restrict_chat_member_request_chat_id_t *chat_id, chat_permissions_t *permissions, int *use_independent_chat_permissions)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/setChatPermissions");





    // form parameters
    char *keyForm_chat_id = NULL;
    post_restrict_chat_member_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_permissions = NULL;
    chat_permissions_t * valueForm_permissions = 0;
    keyValuePair_t *keyPairForm_permissions = 0;
    if (permissions != NULL)
    {
        keyForm_permissions = strdup("permissions");
        valueForm_permissions = (permissions);
        keyPairForm_permissions = keyValuePair_create(keyForm_permissions,&valueForm_permissions);
        list_addElement(localVarFormParameters,keyPairForm_permissions);
    }

    // form parameters
    char *keyForm_use_independent_chat_permissions = NULL;
    char * valueForm_use_independent_chat_permissions = 0;
    keyValuePair_t *keyPairForm_use_independent_chat_permissions = 0;
    if (use_independent_chat_permissions != NULL)
    {
        keyForm_use_independent_chat_permissions = strdup("use_independent_chat_permissions");
        valueForm_use_independent_chat_permissions = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_use_independent_chat_permissions, MAX_NUMBER_LENGTH, "%d", *use_independent_chat_permissions);
        keyPairForm_use_independent_chat_permissions = keyValuePair_create(keyForm_use_independent_chat_permissions,valueForm_use_independent_chat_permissions);
        list_addElement(localVarFormParameters,keyPairForm_use_independent_chat_permissions);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_permissions) {
        free(keyForm_permissions);
        keyForm_permissions = NULL;
    }
    free(keyPairForm_permissions);
    if (keyForm_use_independent_chat_permissions) {
        free(keyForm_use_independent_chat_permissions);
        keyForm_use_independent_chat_permissions = NULL;
    }
    free(keyPairForm_use_independent_chat_permissions);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// setChatPhoto
//
// Use this method to set a new profile photo for the chat. Photos can't be changed for private chats. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postSetChatPhoto(apiClient_t *apiClient, post_send_message_request_chat_id_t *chat_id, photo)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/setChatPhoto");





    // form parameters
    char *keyForm_chat_id = NULL;
    post_send_message_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_photo = NULL;
     valueForm_photo = 0;
    keyValuePair_t *keyPairForm_photo = 0;
    if (photo != NULL)
    {
        keyForm_photo = strdup("photo");
        valueForm_photo = (photo);
        keyPairForm_photo = keyValuePair_create(keyForm_photo,&valueForm_photo);
        list_addElement(localVarFormParameters,keyPairForm_photo);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_photo) {
        free(keyForm_photo);
        keyForm_photo = NULL;
    }
    free(keyPairForm_photo);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// setChatStickerSet
//
// Use this method to set a new group sticker set for a supergroup. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Use the field *can\\_set\\_sticker\\_set* optionally returned in [getChat](https://core.telegram.org/bots/api/#getchat) requests to check if the bot can use this method. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postSetChatStickerSet(apiClient_t *apiClient, post_restrict_chat_member_request_chat_id_t *chat_id, char *sticker_set_name)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/setChatStickerSet");





    // form parameters
    char *keyForm_chat_id = NULL;
    post_restrict_chat_member_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_sticker_set_name = NULL;
    char * valueForm_sticker_set_name = 0;
    keyValuePair_t *keyPairForm_sticker_set_name = 0;
    if (sticker_set_name != NULL)
    {
        keyForm_sticker_set_name = strdup("sticker_set_name");
        valueForm_sticker_set_name = strdup((sticker_set_name));
        keyPairForm_sticker_set_name = keyValuePair_create(keyForm_sticker_set_name,valueForm_sticker_set_name);
        list_addElement(localVarFormParameters,keyPairForm_sticker_set_name);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_sticker_set_name) {
        free(keyForm_sticker_set_name);
        keyForm_sticker_set_name = NULL;
    }
    if (valueForm_sticker_set_name) {
        free(valueForm_sticker_set_name);
        valueForm_sticker_set_name = NULL;
    }
    free(keyPairForm_sticker_set_name);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// setChatTitle
//
// Use this method to change the title of a chat. Titles can't be changed for private chats. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postSetChatTitle(apiClient_t *apiClient, post_send_message_request_chat_id_t *chat_id, char *title)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/setChatTitle");





    // form parameters
    char *keyForm_chat_id = NULL;
    post_send_message_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_title = NULL;
    char * valueForm_title = 0;
    keyValuePair_t *keyPairForm_title = 0;
    if (title != NULL)
    {
        keyForm_title = strdup("title");
        valueForm_title = strdup((title));
        keyPairForm_title = keyValuePair_create(keyForm_title,valueForm_title);
        list_addElement(localVarFormParameters,keyPairForm_title);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_title) {
        free(keyForm_title);
        keyForm_title = NULL;
    }
    if (valueForm_title) {
        free(valueForm_title);
        valueForm_title = NULL;
    }
    free(keyPairForm_title);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// setCustomEmojiStickerSetThumbnail
//
// Use this method to set the thumbnail of a custom emoji sticker set. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postSetCustomEmojiStickerSetThumbnail(apiClient_t *apiClient, char *name, char *custom_emoji_id)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/setCustomEmojiStickerSetThumbnail");





    // form parameters
    char *keyForm_name = NULL;
    char * valueForm_name = 0;
    keyValuePair_t *keyPairForm_name = 0;
    if (name != NULL)
    {
        keyForm_name = strdup("name");
        valueForm_name = strdup((name));
        keyPairForm_name = keyValuePair_create(keyForm_name,valueForm_name);
        list_addElement(localVarFormParameters,keyPairForm_name);
    }

    // form parameters
    char *keyForm_custom_emoji_id = NULL;
    char * valueForm_custom_emoji_id = 0;
    keyValuePair_t *keyPairForm_custom_emoji_id = 0;
    if (custom_emoji_id != NULL)
    {
        keyForm_custom_emoji_id = strdup("custom_emoji_id");
        valueForm_custom_emoji_id = strdup((custom_emoji_id));
        keyPairForm_custom_emoji_id = keyValuePair_create(keyForm_custom_emoji_id,valueForm_custom_emoji_id);
        list_addElement(localVarFormParameters,keyPairForm_custom_emoji_id);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_name) {
        free(keyForm_name);
        keyForm_name = NULL;
    }
    if (valueForm_name) {
        free(valueForm_name);
        valueForm_name = NULL;
    }
    free(keyPairForm_name);
    if (keyForm_custom_emoji_id) {
        free(keyForm_custom_emoji_id);
        keyForm_custom_emoji_id = NULL;
    }
    if (valueForm_custom_emoji_id) {
        free(valueForm_custom_emoji_id);
        valueForm_custom_emoji_id = NULL;
    }
    free(keyPairForm_custom_emoji_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// setGameScore
//
// Use this method to set the score of the specified user in a game message. On success, if the message is not an inline message, the [Message](https://core.telegram.org/bots/api/#message) is returned, otherwise *True* is returned. Returns an error, if the new score is not greater than the user's current score in the chat and *force* is *False*.
//
post_edit_message_text_200_response_t*
DefaultAPI_postSetGameScore(apiClient_t *apiClient, int *user_id, int *score, int *force, int *disable_edit_message, int *chat_id, int *message_id, char *inline_message_id)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/setGameScore");





    // form parameters
    char *keyForm_user_id = NULL;
    int valueForm_user_id = 0;
    keyValuePair_t *keyPairForm_user_id = 0;
    if (user_id != NULL)
    {
        keyForm_user_id = strdup("user_id");
        valueForm_user_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_user_id, MAX_NUMBER_LENGTH, "%d", *user_id);
        keyPairForm_user_id = keyValuePair_create(keyForm_user_id,&valueForm_user_id);
        list_addElement(localVarFormParameters,keyPairForm_user_id);
    }

    // form parameters
    char *keyForm_score = NULL;
    int valueForm_score = 0;
    keyValuePair_t *keyPairForm_score = 0;
    if (score != NULL)
    {
        keyForm_score = strdup("score");
        valueForm_score = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_score, MAX_NUMBER_LENGTH, "%d", *score);
        keyPairForm_score = keyValuePair_create(keyForm_score,&valueForm_score);
        list_addElement(localVarFormParameters,keyPairForm_score);
    }

    // form parameters
    char *keyForm_force = NULL;
    char * valueForm_force = 0;
    keyValuePair_t *keyPairForm_force = 0;
    if (force != NULL)
    {
        keyForm_force = strdup("force");
        valueForm_force = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_force, MAX_NUMBER_LENGTH, "%d", *force);
        keyPairForm_force = keyValuePair_create(keyForm_force,valueForm_force);
        list_addElement(localVarFormParameters,keyPairForm_force);
    }

    // form parameters
    char *keyForm_disable_edit_message = NULL;
    char * valueForm_disable_edit_message = 0;
    keyValuePair_t *keyPairForm_disable_edit_message = 0;
    if (disable_edit_message != NULL)
    {
        keyForm_disable_edit_message = strdup("disable_edit_message");
        valueForm_disable_edit_message = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_disable_edit_message, MAX_NUMBER_LENGTH, "%d", *disable_edit_message);
        keyPairForm_disable_edit_message = keyValuePair_create(keyForm_disable_edit_message,valueForm_disable_edit_message);
        list_addElement(localVarFormParameters,keyPairForm_disable_edit_message);
    }

    // form parameters
    char *keyForm_chat_id = NULL;
    int valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_chat_id, MAX_NUMBER_LENGTH, "%d", *chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_message_id = NULL;
    int valueForm_message_id = 0;
    keyValuePair_t *keyPairForm_message_id = 0;
    if (message_id != NULL)
    {
        keyForm_message_id = strdup("message_id");
        valueForm_message_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_message_id, MAX_NUMBER_LENGTH, "%d", *message_id);
        keyPairForm_message_id = keyValuePair_create(keyForm_message_id,&valueForm_message_id);
        list_addElement(localVarFormParameters,keyPairForm_message_id);
    }

    // form parameters
    char *keyForm_inline_message_id = NULL;
    char * valueForm_inline_message_id = 0;
    keyValuePair_t *keyPairForm_inline_message_id = 0;
    if (inline_message_id != NULL)
    {
        keyForm_inline_message_id = strdup("inline_message_id");
        valueForm_inline_message_id = strdup((inline_message_id));
        keyPairForm_inline_message_id = keyValuePair_create(keyForm_inline_message_id,valueForm_inline_message_id);
        list_addElement(localVarFormParameters,keyPairForm_inline_message_id);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_edit_message_text_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_edit_message_text_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_user_id) {
        free(keyForm_user_id);
        keyForm_user_id = NULL;
    }
    free(keyPairForm_user_id);
    if (keyForm_score) {
        free(keyForm_score);
        keyForm_score = NULL;
    }
    free(keyPairForm_score);
    if (keyForm_force) {
        free(keyForm_force);
        keyForm_force = NULL;
    }
    free(keyPairForm_force);
    if (keyForm_disable_edit_message) {
        free(keyForm_disable_edit_message);
        keyForm_disable_edit_message = NULL;
    }
    free(keyPairForm_disable_edit_message);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_message_id) {
        free(keyForm_message_id);
        keyForm_message_id = NULL;
    }
    free(keyPairForm_message_id);
    if (keyForm_inline_message_id) {
        free(keyForm_inline_message_id);
        keyForm_inline_message_id = NULL;
    }
    if (valueForm_inline_message_id) {
        free(valueForm_inline_message_id);
        valueForm_inline_message_id = NULL;
    }
    free(keyPairForm_inline_message_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// setMessageReaction
//
// Use this method to change the chosen reactions on a message. Service messages of some types can't be reacted to. Automatically forwarded messages from a channel to its discussion group have the same available reactions as messages in the channel. Bots can't use paid reactions. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postSetMessageReaction(apiClient_t *apiClient, post_send_message_request_chat_id_t *chat_id, int *message_id, list_t *reaction, int *is_big)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/setMessageReaction");





    // form parameters
    char *keyForm_chat_id = NULL;
    post_send_message_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_message_id = NULL;
    int valueForm_message_id = 0;
    keyValuePair_t *keyPairForm_message_id = 0;
    if (message_id != NULL)
    {
        keyForm_message_id = strdup("message_id");
        valueForm_message_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_message_id, MAX_NUMBER_LENGTH, "%d", *message_id);
        keyPairForm_message_id = keyValuePair_create(keyForm_message_id,&valueForm_message_id);
        list_addElement(localVarFormParameters,keyPairForm_message_id);
    }

    // form parameters
    char *keyForm_reaction = NULL;
     valueForm_reaction = 0;
    keyValuePair_t *keyPairForm_reaction = 0;
    if (reaction != NULL)
    {
        keyForm_reaction = strdup("reaction");
        valueForm_reaction = (reaction);
        keyPairForm_reaction = keyValuePair_create(keyForm_reaction,&valueForm_reaction);
        list_addElement(localVarFormParameters,keyPairForm_reaction);
    }

    // form parameters
    char *keyForm_is_big = NULL;
    char * valueForm_is_big = 0;
    keyValuePair_t *keyPairForm_is_big = 0;
    if (is_big != NULL)
    {
        keyForm_is_big = strdup("is_big");
        valueForm_is_big = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_is_big, MAX_NUMBER_LENGTH, "%d", *is_big);
        keyPairForm_is_big = keyValuePair_create(keyForm_is_big,valueForm_is_big);
        list_addElement(localVarFormParameters,keyPairForm_is_big);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_message_id) {
        free(keyForm_message_id);
        keyForm_message_id = NULL;
    }
    free(keyPairForm_message_id);
    if (keyForm_reaction) {
        free(keyForm_reaction);
        keyForm_reaction = NULL;
    }
    free(keyPairForm_reaction);
    if (keyForm_is_big) {
        free(keyForm_is_big);
        keyForm_is_big = NULL;
    }
    free(keyPairForm_is_big);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// setMyCommands
//
// Use this method to change the list of the bot's commands. See [this manual](https://core.telegram.org/bots/features#commands) for more details about bot commands. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postSetMyCommands(apiClient_t *apiClient, list_t *commands, bot_command_scope_t *scope, char *language_code)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/setMyCommands");





    // form parameters
    char *keyForm_commands = NULL;
     valueForm_commands = 0;
    keyValuePair_t *keyPairForm_commands = 0;
    if (commands != NULL)
    {
        keyForm_commands = strdup("commands");
        valueForm_commands = (commands);
        keyPairForm_commands = keyValuePair_create(keyForm_commands,&valueForm_commands);
        list_addElement(localVarFormParameters,keyPairForm_commands);
    }

    // form parameters
    char *keyForm_scope = NULL;
    bot_command_scope_t * valueForm_scope = 0;
    keyValuePair_t *keyPairForm_scope = 0;
    if (scope != NULL)
    {
        keyForm_scope = strdup("scope");
        valueForm_scope = (scope);
        keyPairForm_scope = keyValuePair_create(keyForm_scope,&valueForm_scope);
        list_addElement(localVarFormParameters,keyPairForm_scope);
    }

    // form parameters
    char *keyForm_language_code = NULL;
    char * valueForm_language_code = 0;
    keyValuePair_t *keyPairForm_language_code = 0;
    if (language_code != NULL)
    {
        keyForm_language_code = strdup("language_code");
        valueForm_language_code = strdup((language_code));
        keyPairForm_language_code = keyValuePair_create(keyForm_language_code,valueForm_language_code);
        list_addElement(localVarFormParameters,keyPairForm_language_code);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_commands) {
        free(keyForm_commands);
        keyForm_commands = NULL;
    }
    free(keyPairForm_commands);
    if (keyForm_scope) {
        free(keyForm_scope);
        keyForm_scope = NULL;
    }
    free(keyPairForm_scope);
    if (keyForm_language_code) {
        free(keyForm_language_code);
        keyForm_language_code = NULL;
    }
    if (valueForm_language_code) {
        free(valueForm_language_code);
        valueForm_language_code = NULL;
    }
    free(keyPairForm_language_code);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// setMyDefaultAdministratorRights
//
// Use this method to change the default administrator rights requested by the bot when it's added as an administrator to groups or channels. These rights will be suggested to users, but they are free to modify the list before adding the bot. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postSetMyDefaultAdministratorRights(apiClient_t *apiClient, chat_administrator_rights_t *rights, int *for_channels)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/setMyDefaultAdministratorRights");





    // form parameters
    char *keyForm_rights = NULL;
    chat_administrator_rights_t * valueForm_rights = 0;
    keyValuePair_t *keyPairForm_rights = 0;
    if (rights != NULL)
    {
        keyForm_rights = strdup("rights");
        valueForm_rights = (rights);
        keyPairForm_rights = keyValuePair_create(keyForm_rights,&valueForm_rights);
        list_addElement(localVarFormParameters,keyPairForm_rights);
    }

    // form parameters
    char *keyForm_for_channels = NULL;
    char * valueForm_for_channels = 0;
    keyValuePair_t *keyPairForm_for_channels = 0;
    if (for_channels != NULL)
    {
        keyForm_for_channels = strdup("for_channels");
        valueForm_for_channels = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_for_channels, MAX_NUMBER_LENGTH, "%d", *for_channels);
        keyPairForm_for_channels = keyValuePair_create(keyForm_for_channels,valueForm_for_channels);
        list_addElement(localVarFormParameters,keyPairForm_for_channels);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_rights) {
        free(keyForm_rights);
        keyForm_rights = NULL;
    }
    free(keyPairForm_rights);
    if (keyForm_for_channels) {
        free(keyForm_for_channels);
        keyForm_for_channels = NULL;
    }
    free(keyPairForm_for_channels);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// setMyDescription
//
// Use this method to change the bot's description, which is shown in the chat with the bot if the chat is empty. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postSetMyDescription(apiClient_t *apiClient, char *description, char *language_code)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/setMyDescription");





    // form parameters
    char *keyForm_description = NULL;
    char * valueForm_description = 0;
    keyValuePair_t *keyPairForm_description = 0;
    if (description != NULL)
    {
        keyForm_description = strdup("description");
        valueForm_description = strdup((description));
        keyPairForm_description = keyValuePair_create(keyForm_description,valueForm_description);
        list_addElement(localVarFormParameters,keyPairForm_description);
    }

    // form parameters
    char *keyForm_language_code = NULL;
    char * valueForm_language_code = 0;
    keyValuePair_t *keyPairForm_language_code = 0;
    if (language_code != NULL)
    {
        keyForm_language_code = strdup("language_code");
        valueForm_language_code = strdup((language_code));
        keyPairForm_language_code = keyValuePair_create(keyForm_language_code,valueForm_language_code);
        list_addElement(localVarFormParameters,keyPairForm_language_code);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_description) {
        free(keyForm_description);
        keyForm_description = NULL;
    }
    if (valueForm_description) {
        free(valueForm_description);
        valueForm_description = NULL;
    }
    free(keyPairForm_description);
    if (keyForm_language_code) {
        free(keyForm_language_code);
        keyForm_language_code = NULL;
    }
    if (valueForm_language_code) {
        free(valueForm_language_code);
        valueForm_language_code = NULL;
    }
    free(keyPairForm_language_code);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// setMyName
//
// Use this method to change the bot's name. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postSetMyName(apiClient_t *apiClient, char *name, char *language_code)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/setMyName");





    // form parameters
    char *keyForm_name = NULL;
    char * valueForm_name = 0;
    keyValuePair_t *keyPairForm_name = 0;
    if (name != NULL)
    {
        keyForm_name = strdup("name");
        valueForm_name = strdup((name));
        keyPairForm_name = keyValuePair_create(keyForm_name,valueForm_name);
        list_addElement(localVarFormParameters,keyPairForm_name);
    }

    // form parameters
    char *keyForm_language_code = NULL;
    char * valueForm_language_code = 0;
    keyValuePair_t *keyPairForm_language_code = 0;
    if (language_code != NULL)
    {
        keyForm_language_code = strdup("language_code");
        valueForm_language_code = strdup((language_code));
        keyPairForm_language_code = keyValuePair_create(keyForm_language_code,valueForm_language_code);
        list_addElement(localVarFormParameters,keyPairForm_language_code);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_name) {
        free(keyForm_name);
        keyForm_name = NULL;
    }
    if (valueForm_name) {
        free(valueForm_name);
        valueForm_name = NULL;
    }
    free(keyPairForm_name);
    if (keyForm_language_code) {
        free(keyForm_language_code);
        keyForm_language_code = NULL;
    }
    if (valueForm_language_code) {
        free(valueForm_language_code);
        valueForm_language_code = NULL;
    }
    free(keyPairForm_language_code);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// setMyShortDescription
//
// Use this method to change the bot's short description, which is shown on the bot's profile page and is sent together with the link when users share the bot. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postSetMyShortDescription(apiClient_t *apiClient, char *short_description, char *language_code)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/setMyShortDescription");





    // form parameters
    char *keyForm_short_description = NULL;
    char * valueForm_short_description = 0;
    keyValuePair_t *keyPairForm_short_description = 0;
    if (short_description != NULL)
    {
        keyForm_short_description = strdup("short_description");
        valueForm_short_description = strdup((short_description));
        keyPairForm_short_description = keyValuePair_create(keyForm_short_description,valueForm_short_description);
        list_addElement(localVarFormParameters,keyPairForm_short_description);
    }

    // form parameters
    char *keyForm_language_code = NULL;
    char * valueForm_language_code = 0;
    keyValuePair_t *keyPairForm_language_code = 0;
    if (language_code != NULL)
    {
        keyForm_language_code = strdup("language_code");
        valueForm_language_code = strdup((language_code));
        keyPairForm_language_code = keyValuePair_create(keyForm_language_code,valueForm_language_code);
        list_addElement(localVarFormParameters,keyPairForm_language_code);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_short_description) {
        free(keyForm_short_description);
        keyForm_short_description = NULL;
    }
    if (valueForm_short_description) {
        free(valueForm_short_description);
        valueForm_short_description = NULL;
    }
    free(keyPairForm_short_description);
    if (keyForm_language_code) {
        free(keyForm_language_code);
        keyForm_language_code = NULL;
    }
    if (valueForm_language_code) {
        free(valueForm_language_code);
        valueForm_language_code = NULL;
    }
    free(keyPairForm_language_code);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// setPassportDataErrors
//
// Informs a user that some of the Telegram Passport elements they provided contains errors. The user will not be able to re-submit their Passport to you until the errors are fixed (the contents of the field for which you returned the error must change). Returns *True* on success.  Use this if the data submitted by the user doesn't satisfy the standards your service requires for any reason. For example, if a birthday date seems invalid, a submitted document is blurry, a scan shows evidence of tampering, etc. Supply some details in the error message to make sure the user knows how to correct the issues.
//
post_set_webhook_200_response_t*
DefaultAPI_postSetPassportDataErrors(apiClient_t *apiClient, int *user_id, list_t *errors)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/setPassportDataErrors");





    // form parameters
    char *keyForm_user_id = NULL;
    int valueForm_user_id = 0;
    keyValuePair_t *keyPairForm_user_id = 0;
    if (user_id != NULL)
    {
        keyForm_user_id = strdup("user_id");
        valueForm_user_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_user_id, MAX_NUMBER_LENGTH, "%d", *user_id);
        keyPairForm_user_id = keyValuePair_create(keyForm_user_id,&valueForm_user_id);
        list_addElement(localVarFormParameters,keyPairForm_user_id);
    }

    // form parameters
    char *keyForm_errors = NULL;
     valueForm_errors = 0;
    keyValuePair_t *keyPairForm_errors = 0;
    if (errors != NULL)
    {
        keyForm_errors = strdup("errors");
        valueForm_errors = (errors);
        keyPairForm_errors = keyValuePair_create(keyForm_errors,&valueForm_errors);
        list_addElement(localVarFormParameters,keyPairForm_errors);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_user_id) {
        free(keyForm_user_id);
        keyForm_user_id = NULL;
    }
    free(keyPairForm_user_id);
    if (keyForm_errors) {
        free(keyForm_errors);
        keyForm_errors = NULL;
    }
    free(keyPairForm_errors);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// setStickerEmojiList
//
// Use this method to change the list of emoji assigned to a regular or custom emoji sticker. The sticker must belong to a sticker set created by the bot. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postSetStickerEmojiList(apiClient_t *apiClient, char *sticker, list_t *emoji_list)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/setStickerEmojiList");





    // form parameters
    char *keyForm_sticker = NULL;
    char * valueForm_sticker = 0;
    keyValuePair_t *keyPairForm_sticker = 0;
    if (sticker != NULL)
    {
        keyForm_sticker = strdup("sticker");
        valueForm_sticker = strdup((sticker));
        keyPairForm_sticker = keyValuePair_create(keyForm_sticker,valueForm_sticker);
        list_addElement(localVarFormParameters,keyPairForm_sticker);
    }

    // form parameters
    char *keyForm_emoji_list = NULL;
     valueForm_emoji_list = 0;
    keyValuePair_t *keyPairForm_emoji_list = 0;
    if (emoji_list != NULL)
    {
        keyForm_emoji_list = strdup("emoji_list");
        valueForm_emoji_list = (emoji_list);
        keyPairForm_emoji_list = keyValuePair_create(keyForm_emoji_list,&valueForm_emoji_list);
        list_addElement(localVarFormParameters,keyPairForm_emoji_list);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_sticker) {
        free(keyForm_sticker);
        keyForm_sticker = NULL;
    }
    if (valueForm_sticker) {
        free(valueForm_sticker);
        valueForm_sticker = NULL;
    }
    free(keyPairForm_sticker);
    if (keyForm_emoji_list) {
        free(keyForm_emoji_list);
        keyForm_emoji_list = NULL;
    }
    free(keyPairForm_emoji_list);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// setStickerKeywords
//
// Use this method to change search keywords assigned to a regular or custom emoji sticker. The sticker must belong to a sticker set created by the bot. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postSetStickerKeywords(apiClient_t *apiClient, char *sticker, list_t *keywords)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/setStickerKeywords");





    // form parameters
    char *keyForm_sticker = NULL;
    char * valueForm_sticker = 0;
    keyValuePair_t *keyPairForm_sticker = 0;
    if (sticker != NULL)
    {
        keyForm_sticker = strdup("sticker");
        valueForm_sticker = strdup((sticker));
        keyPairForm_sticker = keyValuePair_create(keyForm_sticker,valueForm_sticker);
        list_addElement(localVarFormParameters,keyPairForm_sticker);
    }

    // form parameters
    char *keyForm_keywords = NULL;
     valueForm_keywords = 0;
    keyValuePair_t *keyPairForm_keywords = 0;
    if (keywords != NULL)
    {
        keyForm_keywords = strdup("keywords");
        valueForm_keywords = (keywords);
        keyPairForm_keywords = keyValuePair_create(keyForm_keywords,&valueForm_keywords);
        list_addElement(localVarFormParameters,keyPairForm_keywords);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_sticker) {
        free(keyForm_sticker);
        keyForm_sticker = NULL;
    }
    if (valueForm_sticker) {
        free(valueForm_sticker);
        valueForm_sticker = NULL;
    }
    free(keyPairForm_sticker);
    if (keyForm_keywords) {
        free(keyForm_keywords);
        keyForm_keywords = NULL;
    }
    free(keyPairForm_keywords);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// setStickerMaskPosition
//
// Use this method to change the [mask position](https://core.telegram.org/bots/api/#maskposition) of a mask sticker. The sticker must belong to a sticker set that was created by the bot. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postSetStickerMaskPosition(apiClient_t *apiClient, char *sticker, mask_position_t *mask_position)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/setStickerMaskPosition");





    // form parameters
    char *keyForm_sticker = NULL;
    char * valueForm_sticker = 0;
    keyValuePair_t *keyPairForm_sticker = 0;
    if (sticker != NULL)
    {
        keyForm_sticker = strdup("sticker");
        valueForm_sticker = strdup((sticker));
        keyPairForm_sticker = keyValuePair_create(keyForm_sticker,valueForm_sticker);
        list_addElement(localVarFormParameters,keyPairForm_sticker);
    }

    // form parameters
    char *keyForm_mask_position = NULL;
    mask_position_t * valueForm_mask_position = 0;
    keyValuePair_t *keyPairForm_mask_position = 0;
    if (mask_position != NULL)
    {
        keyForm_mask_position = strdup("mask_position");
        valueForm_mask_position = (mask_position);
        keyPairForm_mask_position = keyValuePair_create(keyForm_mask_position,&valueForm_mask_position);
        list_addElement(localVarFormParameters,keyPairForm_mask_position);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_sticker) {
        free(keyForm_sticker);
        keyForm_sticker = NULL;
    }
    if (valueForm_sticker) {
        free(valueForm_sticker);
        valueForm_sticker = NULL;
    }
    free(keyPairForm_sticker);
    if (keyForm_mask_position) {
        free(keyForm_mask_position);
        keyForm_mask_position = NULL;
    }
    free(keyPairForm_mask_position);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// setStickerPositionInSet
//
// Use this method to move a sticker in a set created by the bot to a specific position. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postSetStickerPositionInSet(apiClient_t *apiClient, char *sticker, int *position)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/setStickerPositionInSet");





    // form parameters
    char *keyForm_sticker = NULL;
    char * valueForm_sticker = 0;
    keyValuePair_t *keyPairForm_sticker = 0;
    if (sticker != NULL)
    {
        keyForm_sticker = strdup("sticker");
        valueForm_sticker = strdup((sticker));
        keyPairForm_sticker = keyValuePair_create(keyForm_sticker,valueForm_sticker);
        list_addElement(localVarFormParameters,keyPairForm_sticker);
    }

    // form parameters
    char *keyForm_position = NULL;
    int valueForm_position = 0;
    keyValuePair_t *keyPairForm_position = 0;
    if (position != NULL)
    {
        keyForm_position = strdup("position");
        valueForm_position = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_position, MAX_NUMBER_LENGTH, "%d", *position);
        keyPairForm_position = keyValuePair_create(keyForm_position,&valueForm_position);
        list_addElement(localVarFormParameters,keyPairForm_position);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_sticker) {
        free(keyForm_sticker);
        keyForm_sticker = NULL;
    }
    if (valueForm_sticker) {
        free(valueForm_sticker);
        valueForm_sticker = NULL;
    }
    free(keyPairForm_sticker);
    if (keyForm_position) {
        free(keyForm_position);
        keyForm_position = NULL;
    }
    free(keyPairForm_position);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// setStickerSetThumbnail
//
// Use this method to set the thumbnail of a regular or mask sticker set. The format of the thumbnail file must match the format of the stickers in the set. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postSetStickerSetThumbnail(apiClient_t *apiClient, char *name, int *user_id, telegram_bot_api_postSetStickerSetThumbnail_format_e format, post_set_sticker_set_thumbnail_request_thumbnail_t *thumbnail)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/setStickerSetThumbnail");





    // form parameters
    char *keyForm_name = NULL;
    char * valueForm_name = 0;
    keyValuePair_t *keyPairForm_name = 0;
    if (name != NULL)
    {
        keyForm_name = strdup("name");
        valueForm_name = strdup((name));
        keyPairForm_name = keyValuePair_create(keyForm_name,valueForm_name);
        list_addElement(localVarFormParameters,keyPairForm_name);
    }

    // form parameters
    char *keyForm_user_id = NULL;
    int valueForm_user_id = 0;
    keyValuePair_t *keyPairForm_user_id = 0;
    if (user_id != NULL)
    {
        keyForm_user_id = strdup("user_id");
        valueForm_user_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_user_id, MAX_NUMBER_LENGTH, "%d", *user_id);
        keyPairForm_user_id = keyValuePair_create(keyForm_user_id,&valueForm_user_id);
        list_addElement(localVarFormParameters,keyPairForm_user_id);
    }

    // form parameters
    char *keyForm_thumbnail = NULL;
    post_set_sticker_set_thumbnail_request_thumbnail_t * valueForm_thumbnail = 0;
    keyValuePair_t *keyPairForm_thumbnail = 0;
    if (thumbnail != NULL)
    {
        keyForm_thumbnail = strdup("thumbnail");
        valueForm_thumbnail = (thumbnail);
        keyPairForm_thumbnail = keyValuePair_create(keyForm_thumbnail,&valueForm_thumbnail);
        list_addElement(localVarFormParameters,keyPairForm_thumbnail);
    }

    // form parameters
    char *keyForm_format = NULL;
    telegram_bot_api_postSetStickerSetThumbnail_format_e valueForm_format = 0;
    keyValuePair_t *keyPairForm_format = 0;
    if (format != 0)
    {
        keyForm_format = strdup("format");
        valueForm_format = (format);
        keyPairForm_format = keyValuePair_create(keyForm_format,(void *)valueForm_format);
        list_addElement(localVarFormParameters,keyPairForm_format);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_name) {
        free(keyForm_name);
        keyForm_name = NULL;
    }
    if (valueForm_name) {
        free(valueForm_name);
        valueForm_name = NULL;
    }
    free(keyPairForm_name);
    if (keyForm_user_id) {
        free(keyForm_user_id);
        keyForm_user_id = NULL;
    }
    free(keyPairForm_user_id);
    if (keyForm_thumbnail) {
        free(keyForm_thumbnail);
        keyForm_thumbnail = NULL;
    }
    free(keyPairForm_thumbnail);
    if (keyForm_format) {
        free(keyForm_format);
        keyForm_format = NULL;
    }
    if (valueForm_format) {
        valueForm_format = 0;
    }
    free(keyPairForm_format);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// setStickerSetTitle
//
// Use this method to set the title of a created sticker set. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postSetStickerSetTitle(apiClient_t *apiClient, char *name, char *title)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/setStickerSetTitle");





    // form parameters
    char *keyForm_name = NULL;
    char * valueForm_name = 0;
    keyValuePair_t *keyPairForm_name = 0;
    if (name != NULL)
    {
        keyForm_name = strdup("name");
        valueForm_name = strdup((name));
        keyPairForm_name = keyValuePair_create(keyForm_name,valueForm_name);
        list_addElement(localVarFormParameters,keyPairForm_name);
    }

    // form parameters
    char *keyForm_title = NULL;
    char * valueForm_title = 0;
    keyValuePair_t *keyPairForm_title = 0;
    if (title != NULL)
    {
        keyForm_title = strdup("title");
        valueForm_title = strdup((title));
        keyPairForm_title = keyValuePair_create(keyForm_title,valueForm_title);
        list_addElement(localVarFormParameters,keyPairForm_title);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_name) {
        free(keyForm_name);
        keyForm_name = NULL;
    }
    if (valueForm_name) {
        free(valueForm_name);
        valueForm_name = NULL;
    }
    free(keyPairForm_name);
    if (keyForm_title) {
        free(keyForm_title);
        keyForm_title = NULL;
    }
    if (valueForm_title) {
        free(valueForm_title);
        valueForm_title = NULL;
    }
    free(keyPairForm_title);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// setUserEmojiStatus
//
// Changes the emoji status for a given user that previously allowed the bot to manage their emoji status via the Mini App method [requestEmojiStatusAccess](https://core.telegram.org/bots/webapps#initializing-mini-apps). Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postSetUserEmojiStatus(apiClient_t *apiClient, int *user_id, char *emoji_status_custom_emoji_id, int *emoji_status_expiration_date)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/setUserEmojiStatus");





    // form parameters
    char *keyForm_user_id = NULL;
    int valueForm_user_id = 0;
    keyValuePair_t *keyPairForm_user_id = 0;
    if (user_id != NULL)
    {
        keyForm_user_id = strdup("user_id");
        valueForm_user_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_user_id, MAX_NUMBER_LENGTH, "%d", *user_id);
        keyPairForm_user_id = keyValuePair_create(keyForm_user_id,&valueForm_user_id);
        list_addElement(localVarFormParameters,keyPairForm_user_id);
    }

    // form parameters
    char *keyForm_emoji_status_custom_emoji_id = NULL;
    char * valueForm_emoji_status_custom_emoji_id = 0;
    keyValuePair_t *keyPairForm_emoji_status_custom_emoji_id = 0;
    if (emoji_status_custom_emoji_id != NULL)
    {
        keyForm_emoji_status_custom_emoji_id = strdup("emoji_status_custom_emoji_id");
        valueForm_emoji_status_custom_emoji_id = strdup((emoji_status_custom_emoji_id));
        keyPairForm_emoji_status_custom_emoji_id = keyValuePair_create(keyForm_emoji_status_custom_emoji_id,valueForm_emoji_status_custom_emoji_id);
        list_addElement(localVarFormParameters,keyPairForm_emoji_status_custom_emoji_id);
    }

    // form parameters
    char *keyForm_emoji_status_expiration_date = NULL;
    int valueForm_emoji_status_expiration_date = 0;
    keyValuePair_t *keyPairForm_emoji_status_expiration_date = 0;
    if (emoji_status_expiration_date != NULL)
    {
        keyForm_emoji_status_expiration_date = strdup("emoji_status_expiration_date");
        valueForm_emoji_status_expiration_date = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_emoji_status_expiration_date, MAX_NUMBER_LENGTH, "%d", *emoji_status_expiration_date);
        keyPairForm_emoji_status_expiration_date = keyValuePair_create(keyForm_emoji_status_expiration_date,&valueForm_emoji_status_expiration_date);
        list_addElement(localVarFormParameters,keyPairForm_emoji_status_expiration_date);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_user_id) {
        free(keyForm_user_id);
        keyForm_user_id = NULL;
    }
    free(keyPairForm_user_id);
    if (keyForm_emoji_status_custom_emoji_id) {
        free(keyForm_emoji_status_custom_emoji_id);
        keyForm_emoji_status_custom_emoji_id = NULL;
    }
    if (valueForm_emoji_status_custom_emoji_id) {
        free(valueForm_emoji_status_custom_emoji_id);
        valueForm_emoji_status_custom_emoji_id = NULL;
    }
    free(keyPairForm_emoji_status_custom_emoji_id);
    if (keyForm_emoji_status_expiration_date) {
        free(keyForm_emoji_status_expiration_date);
        keyForm_emoji_status_expiration_date = NULL;
    }
    free(keyPairForm_emoji_status_expiration_date);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// setWebhook
//
// Use this method to specify a URL and receive incoming updates via an outgoing webhook. Whenever there is an update for the bot, we will send an HTTPS POST request to the specified URL, containing a JSON-serialized [Update](https://core.telegram.org/bots/api/#update). In case of an unsuccessful request (a request with response [HTTP status code](https://en.wikipedia.org/wiki/List_of_HTTP_status_codes) different from `2XY`), we will repeat the request and give up after a reasonable amount of attempts. Returns *True* on success.  If you'd like to make sure that the webhook was set by you, you can specify secret data in the parameter *secret\\_token*. If specified, the request will contain a header “X-Telegram-Bot-Api-Secret-Token” with the secret token as content.
//
post_set_webhook_200_response_t*
DefaultAPI_postSetWebhook(apiClient_t *apiClient, char *url, certificate, char *ip_address, int *max_connections, list_t *allowed_updates, int *drop_pending_updates, char *secret_token)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/setWebhook");





    // form parameters
    char *keyForm_url = NULL;
    char * valueForm_url = 0;
    keyValuePair_t *keyPairForm_url = 0;
    if (url != NULL)
    {
        keyForm_url = strdup("url");
        valueForm_url = strdup((url));
        keyPairForm_url = keyValuePair_create(keyForm_url,valueForm_url);
        list_addElement(localVarFormParameters,keyPairForm_url);
    }

    // form parameters
    char *keyForm_certificate = NULL;
     valueForm_certificate = 0;
    keyValuePair_t *keyPairForm_certificate = 0;
    if (certificate != NULL)
    {
        keyForm_certificate = strdup("certificate");
        valueForm_certificate = (certificate);
        keyPairForm_certificate = keyValuePair_create(keyForm_certificate,&valueForm_certificate);
        list_addElement(localVarFormParameters,keyPairForm_certificate);
    }

    // form parameters
    char *keyForm_ip_address = NULL;
    char * valueForm_ip_address = 0;
    keyValuePair_t *keyPairForm_ip_address = 0;
    if (ip_address != NULL)
    {
        keyForm_ip_address = strdup("ip_address");
        valueForm_ip_address = strdup((ip_address));
        keyPairForm_ip_address = keyValuePair_create(keyForm_ip_address,valueForm_ip_address);
        list_addElement(localVarFormParameters,keyPairForm_ip_address);
    }

    // form parameters
    char *keyForm_max_connections = NULL;
    int valueForm_max_connections = 0;
    keyValuePair_t *keyPairForm_max_connections = 0;
    if (max_connections != NULL)
    {
        keyForm_max_connections = strdup("max_connections");
        valueForm_max_connections = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_max_connections, MAX_NUMBER_LENGTH, "%d", *max_connections);
        keyPairForm_max_connections = keyValuePair_create(keyForm_max_connections,&valueForm_max_connections);
        list_addElement(localVarFormParameters,keyPairForm_max_connections);
    }

    // form parameters
    char *keyForm_allowed_updates = NULL;
     valueForm_allowed_updates = 0;
    keyValuePair_t *keyPairForm_allowed_updates = 0;
    if (allowed_updates != NULL)
    {
        keyForm_allowed_updates = strdup("allowed_updates");
        valueForm_allowed_updates = (allowed_updates);
        keyPairForm_allowed_updates = keyValuePair_create(keyForm_allowed_updates,&valueForm_allowed_updates);
        list_addElement(localVarFormParameters,keyPairForm_allowed_updates);
    }

    // form parameters
    char *keyForm_drop_pending_updates = NULL;
    char * valueForm_drop_pending_updates = 0;
    keyValuePair_t *keyPairForm_drop_pending_updates = 0;
    if (drop_pending_updates != NULL)
    {
        keyForm_drop_pending_updates = strdup("drop_pending_updates");
        valueForm_drop_pending_updates = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_drop_pending_updates, MAX_NUMBER_LENGTH, "%d", *drop_pending_updates);
        keyPairForm_drop_pending_updates = keyValuePair_create(keyForm_drop_pending_updates,valueForm_drop_pending_updates);
        list_addElement(localVarFormParameters,keyPairForm_drop_pending_updates);
    }

    // form parameters
    char *keyForm_secret_token = NULL;
    char * valueForm_secret_token = 0;
    keyValuePair_t *keyPairForm_secret_token = 0;
    if (secret_token != NULL)
    {
        keyForm_secret_token = strdup("secret_token");
        valueForm_secret_token = strdup((secret_token));
        keyPairForm_secret_token = keyValuePair_create(keyForm_secret_token,valueForm_secret_token);
        list_addElement(localVarFormParameters,keyPairForm_secret_token);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_url) {
        free(keyForm_url);
        keyForm_url = NULL;
    }
    if (valueForm_url) {
        free(valueForm_url);
        valueForm_url = NULL;
    }
    free(keyPairForm_url);
    if (keyForm_certificate) {
        free(keyForm_certificate);
        keyForm_certificate = NULL;
    }
    free(keyPairForm_certificate);
    if (keyForm_ip_address) {
        free(keyForm_ip_address);
        keyForm_ip_address = NULL;
    }
    if (valueForm_ip_address) {
        free(valueForm_ip_address);
        valueForm_ip_address = NULL;
    }
    free(keyPairForm_ip_address);
    if (keyForm_max_connections) {
        free(keyForm_max_connections);
        keyForm_max_connections = NULL;
    }
    free(keyPairForm_max_connections);
    if (keyForm_allowed_updates) {
        free(keyForm_allowed_updates);
        keyForm_allowed_updates = NULL;
    }
    free(keyPairForm_allowed_updates);
    if (keyForm_drop_pending_updates) {
        free(keyForm_drop_pending_updates);
        keyForm_drop_pending_updates = NULL;
    }
    free(keyPairForm_drop_pending_updates);
    if (keyForm_secret_token) {
        free(keyForm_secret_token);
        keyForm_secret_token = NULL;
    }
    if (valueForm_secret_token) {
        free(valueForm_secret_token);
        valueForm_secret_token = NULL;
    }
    free(keyPairForm_secret_token);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// stopMessageLiveLocation
//
// Use this method to stop updating a live location message before *live\\_period* expires. On success, if the message is not an inline message, the edited [Message](https://core.telegram.org/bots/api/#message) is returned, otherwise *True* is returned.
//
post_edit_message_text_200_response_t*
DefaultAPI_postStopMessageLiveLocation(apiClient_t *apiClient, char *business_connection_id, post_edit_message_text_request_chat_id_t *chat_id, int *message_id, char *inline_message_id, inline_keyboard_markup_t *reply_markup)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/stopMessageLiveLocation");





    // form parameters
    char *keyForm_business_connection_id = NULL;
    char * valueForm_business_connection_id = 0;
    keyValuePair_t *keyPairForm_business_connection_id = 0;
    if (business_connection_id != NULL)
    {
        keyForm_business_connection_id = strdup("business_connection_id");
        valueForm_business_connection_id = strdup((business_connection_id));
        keyPairForm_business_connection_id = keyValuePair_create(keyForm_business_connection_id,valueForm_business_connection_id);
        list_addElement(localVarFormParameters,keyPairForm_business_connection_id);
    }

    // form parameters
    char *keyForm_chat_id = NULL;
    post_edit_message_text_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_message_id = NULL;
    int valueForm_message_id = 0;
    keyValuePair_t *keyPairForm_message_id = 0;
    if (message_id != NULL)
    {
        keyForm_message_id = strdup("message_id");
        valueForm_message_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_message_id, MAX_NUMBER_LENGTH, "%d", *message_id);
        keyPairForm_message_id = keyValuePair_create(keyForm_message_id,&valueForm_message_id);
        list_addElement(localVarFormParameters,keyPairForm_message_id);
    }

    // form parameters
    char *keyForm_inline_message_id = NULL;
    char * valueForm_inline_message_id = 0;
    keyValuePair_t *keyPairForm_inline_message_id = 0;
    if (inline_message_id != NULL)
    {
        keyForm_inline_message_id = strdup("inline_message_id");
        valueForm_inline_message_id = strdup((inline_message_id));
        keyPairForm_inline_message_id = keyValuePair_create(keyForm_inline_message_id,valueForm_inline_message_id);
        list_addElement(localVarFormParameters,keyPairForm_inline_message_id);
    }

    // form parameters
    char *keyForm_reply_markup = NULL;
    inline_keyboard_markup_t * valueForm_reply_markup = 0;
    keyValuePair_t *keyPairForm_reply_markup = 0;
    if (reply_markup != NULL)
    {
        keyForm_reply_markup = strdup("reply_markup");
        valueForm_reply_markup = (reply_markup);
        keyPairForm_reply_markup = keyValuePair_create(keyForm_reply_markup,&valueForm_reply_markup);
        list_addElement(localVarFormParameters,keyPairForm_reply_markup);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_edit_message_text_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_edit_message_text_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_business_connection_id) {
        free(keyForm_business_connection_id);
        keyForm_business_connection_id = NULL;
    }
    if (valueForm_business_connection_id) {
        free(valueForm_business_connection_id);
        valueForm_business_connection_id = NULL;
    }
    free(keyPairForm_business_connection_id);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_message_id) {
        free(keyForm_message_id);
        keyForm_message_id = NULL;
    }
    free(keyPairForm_message_id);
    if (keyForm_inline_message_id) {
        free(keyForm_inline_message_id);
        keyForm_inline_message_id = NULL;
    }
    if (valueForm_inline_message_id) {
        free(valueForm_inline_message_id);
        valueForm_inline_message_id = NULL;
    }
    free(keyPairForm_inline_message_id);
    if (keyForm_reply_markup) {
        free(keyForm_reply_markup);
        keyForm_reply_markup = NULL;
    }
    free(keyPairForm_reply_markup);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// stopPoll
//
// Use this method to stop a poll which was sent by the bot. On success, the stopped [Poll](https://core.telegram.org/bots/api/#poll) is returned.
//
post_stop_poll_200_response_t*
DefaultAPI_postStopPoll(apiClient_t *apiClient, post_send_message_request_chat_id_t *chat_id, int *message_id, char *business_connection_id, inline_keyboard_markup_t *reply_markup)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/stopPoll");





    // form parameters
    char *keyForm_business_connection_id = NULL;
    char * valueForm_business_connection_id = 0;
    keyValuePair_t *keyPairForm_business_connection_id = 0;
    if (business_connection_id != NULL)
    {
        keyForm_business_connection_id = strdup("business_connection_id");
        valueForm_business_connection_id = strdup((business_connection_id));
        keyPairForm_business_connection_id = keyValuePair_create(keyForm_business_connection_id,valueForm_business_connection_id);
        list_addElement(localVarFormParameters,keyPairForm_business_connection_id);
    }

    // form parameters
    char *keyForm_chat_id = NULL;
    post_send_message_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_message_id = NULL;
    int valueForm_message_id = 0;
    keyValuePair_t *keyPairForm_message_id = 0;
    if (message_id != NULL)
    {
        keyForm_message_id = strdup("message_id");
        valueForm_message_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_message_id, MAX_NUMBER_LENGTH, "%d", *message_id);
        keyPairForm_message_id = keyValuePair_create(keyForm_message_id,&valueForm_message_id);
        list_addElement(localVarFormParameters,keyPairForm_message_id);
    }

    // form parameters
    char *keyForm_reply_markup = NULL;
    inline_keyboard_markup_t * valueForm_reply_markup = 0;
    keyValuePair_t *keyPairForm_reply_markup = 0;
    if (reply_markup != NULL)
    {
        keyForm_reply_markup = strdup("reply_markup");
        valueForm_reply_markup = (reply_markup);
        keyPairForm_reply_markup = keyValuePair_create(keyForm_reply_markup,&valueForm_reply_markup);
        list_addElement(localVarFormParameters,keyPairForm_reply_markup);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_stop_poll_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_stop_poll_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_business_connection_id) {
        free(keyForm_business_connection_id);
        keyForm_business_connection_id = NULL;
    }
    if (valueForm_business_connection_id) {
        free(valueForm_business_connection_id);
        valueForm_business_connection_id = NULL;
    }
    free(keyPairForm_business_connection_id);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_message_id) {
        free(keyForm_message_id);
        keyForm_message_id = NULL;
    }
    free(keyPairForm_message_id);
    if (keyForm_reply_markup) {
        free(keyForm_reply_markup);
        keyForm_reply_markup = NULL;
    }
    free(keyPairForm_reply_markup);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// transferBusinessAccountStars
//
// Transfers Telegram Stars from the business account balance to the bot's balance. Requires the *can\\_transfer\\_stars* business bot right. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postTransferBusinessAccountStars(apiClient_t *apiClient, char *business_connection_id, int *star_count)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/transferBusinessAccountStars");





    // form parameters
    char *keyForm_business_connection_id = NULL;
    char * valueForm_business_connection_id = 0;
    keyValuePair_t *keyPairForm_business_connection_id = 0;
    if (business_connection_id != NULL)
    {
        keyForm_business_connection_id = strdup("business_connection_id");
        valueForm_business_connection_id = strdup((business_connection_id));
        keyPairForm_business_connection_id = keyValuePair_create(keyForm_business_connection_id,valueForm_business_connection_id);
        list_addElement(localVarFormParameters,keyPairForm_business_connection_id);
    }

    // form parameters
    char *keyForm_star_count = NULL;
    int valueForm_star_count = 0;
    keyValuePair_t *keyPairForm_star_count = 0;
    if (star_count != NULL)
    {
        keyForm_star_count = strdup("star_count");
        valueForm_star_count = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_star_count, MAX_NUMBER_LENGTH, "%d", *star_count);
        keyPairForm_star_count = keyValuePair_create(keyForm_star_count,&valueForm_star_count);
        list_addElement(localVarFormParameters,keyPairForm_star_count);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_business_connection_id) {
        free(keyForm_business_connection_id);
        keyForm_business_connection_id = NULL;
    }
    if (valueForm_business_connection_id) {
        free(valueForm_business_connection_id);
        valueForm_business_connection_id = NULL;
    }
    free(keyPairForm_business_connection_id);
    if (keyForm_star_count) {
        free(keyForm_star_count);
        keyForm_star_count = NULL;
    }
    free(keyPairForm_star_count);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// transferGift
//
// Transfers an owned unique gift to another user. Requires the *can\\_transfer\\_and\\_upgrade\\_gifts* business bot right. Requires *can\\_transfer\\_stars* business bot right if the transfer is paid. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postTransferGift(apiClient_t *apiClient, char *business_connection_id, char *owned_gift_id, int *new_owner_chat_id, int *star_count)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/transferGift");





    // form parameters
    char *keyForm_business_connection_id = NULL;
    char * valueForm_business_connection_id = 0;
    keyValuePair_t *keyPairForm_business_connection_id = 0;
    if (business_connection_id != NULL)
    {
        keyForm_business_connection_id = strdup("business_connection_id");
        valueForm_business_connection_id = strdup((business_connection_id));
        keyPairForm_business_connection_id = keyValuePair_create(keyForm_business_connection_id,valueForm_business_connection_id);
        list_addElement(localVarFormParameters,keyPairForm_business_connection_id);
    }

    // form parameters
    char *keyForm_owned_gift_id = NULL;
    char * valueForm_owned_gift_id = 0;
    keyValuePair_t *keyPairForm_owned_gift_id = 0;
    if (owned_gift_id != NULL)
    {
        keyForm_owned_gift_id = strdup("owned_gift_id");
        valueForm_owned_gift_id = strdup((owned_gift_id));
        keyPairForm_owned_gift_id = keyValuePair_create(keyForm_owned_gift_id,valueForm_owned_gift_id);
        list_addElement(localVarFormParameters,keyPairForm_owned_gift_id);
    }

    // form parameters
    char *keyForm_new_owner_chat_id = NULL;
    int valueForm_new_owner_chat_id = 0;
    keyValuePair_t *keyPairForm_new_owner_chat_id = 0;
    if (new_owner_chat_id != NULL)
    {
        keyForm_new_owner_chat_id = strdup("new_owner_chat_id");
        valueForm_new_owner_chat_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_new_owner_chat_id, MAX_NUMBER_LENGTH, "%d", *new_owner_chat_id);
        keyPairForm_new_owner_chat_id = keyValuePair_create(keyForm_new_owner_chat_id,&valueForm_new_owner_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_new_owner_chat_id);
    }

    // form parameters
    char *keyForm_star_count = NULL;
    int valueForm_star_count = 0;
    keyValuePair_t *keyPairForm_star_count = 0;
    if (star_count != NULL)
    {
        keyForm_star_count = strdup("star_count");
        valueForm_star_count = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_star_count, MAX_NUMBER_LENGTH, "%d", *star_count);
        keyPairForm_star_count = keyValuePair_create(keyForm_star_count,&valueForm_star_count);
        list_addElement(localVarFormParameters,keyPairForm_star_count);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_business_connection_id) {
        free(keyForm_business_connection_id);
        keyForm_business_connection_id = NULL;
    }
    if (valueForm_business_connection_id) {
        free(valueForm_business_connection_id);
        valueForm_business_connection_id = NULL;
    }
    free(keyPairForm_business_connection_id);
    if (keyForm_owned_gift_id) {
        free(keyForm_owned_gift_id);
        keyForm_owned_gift_id = NULL;
    }
    if (valueForm_owned_gift_id) {
        free(valueForm_owned_gift_id);
        valueForm_owned_gift_id = NULL;
    }
    free(keyPairForm_owned_gift_id);
    if (keyForm_new_owner_chat_id) {
        free(keyForm_new_owner_chat_id);
        keyForm_new_owner_chat_id = NULL;
    }
    free(keyPairForm_new_owner_chat_id);
    if (keyForm_star_count) {
        free(keyForm_star_count);
        keyForm_star_count = NULL;
    }
    free(keyPairForm_star_count);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// unbanChatMember
//
// Use this method to unban a previously banned user in a supergroup or channel. The user will **not** return to the group or channel automatically, but will be able to join via link, etc. The bot must be an administrator for this to work. By default, this method guarantees that after the call the user is not a member of the chat, but will be able to join it. So if the user is a member of the chat they will also be **removed** from the chat. If you don't want this, use the parameter *only\\_if\\_banned*. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postUnbanChatMember(apiClient_t *apiClient, post_ban_chat_member_request_chat_id_t *chat_id, int *user_id, int *only_if_banned)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/unbanChatMember");





    // form parameters
    char *keyForm_chat_id = NULL;
    post_ban_chat_member_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_user_id = NULL;
    int valueForm_user_id = 0;
    keyValuePair_t *keyPairForm_user_id = 0;
    if (user_id != NULL)
    {
        keyForm_user_id = strdup("user_id");
        valueForm_user_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_user_id, MAX_NUMBER_LENGTH, "%d", *user_id);
        keyPairForm_user_id = keyValuePair_create(keyForm_user_id,&valueForm_user_id);
        list_addElement(localVarFormParameters,keyPairForm_user_id);
    }

    // form parameters
    char *keyForm_only_if_banned = NULL;
    char * valueForm_only_if_banned = 0;
    keyValuePair_t *keyPairForm_only_if_banned = 0;
    if (only_if_banned != NULL)
    {
        keyForm_only_if_banned = strdup("only_if_banned");
        valueForm_only_if_banned = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_only_if_banned, MAX_NUMBER_LENGTH, "%d", *only_if_banned);
        keyPairForm_only_if_banned = keyValuePair_create(keyForm_only_if_banned,valueForm_only_if_banned);
        list_addElement(localVarFormParameters,keyPairForm_only_if_banned);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_user_id) {
        free(keyForm_user_id);
        keyForm_user_id = NULL;
    }
    free(keyPairForm_user_id);
    if (keyForm_only_if_banned) {
        free(keyForm_only_if_banned);
        keyForm_only_if_banned = NULL;
    }
    free(keyPairForm_only_if_banned);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// unbanChatSenderChat
//
// Use this method to unban a previously banned channel chat in a supergroup or channel. The bot must be an administrator for this to work and must have the appropriate administrator rights. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postUnbanChatSenderChat(apiClient_t *apiClient, post_send_message_request_chat_id_t *chat_id, int *sender_chat_id)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/unbanChatSenderChat");





    // form parameters
    char *keyForm_chat_id = NULL;
    post_send_message_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_sender_chat_id = NULL;
    int valueForm_sender_chat_id = 0;
    keyValuePair_t *keyPairForm_sender_chat_id = 0;
    if (sender_chat_id != NULL)
    {
        keyForm_sender_chat_id = strdup("sender_chat_id");
        valueForm_sender_chat_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_sender_chat_id, MAX_NUMBER_LENGTH, "%d", *sender_chat_id);
        keyPairForm_sender_chat_id = keyValuePair_create(keyForm_sender_chat_id,&valueForm_sender_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_sender_chat_id);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_sender_chat_id) {
        free(keyForm_sender_chat_id);
        keyForm_sender_chat_id = NULL;
    }
    free(keyPairForm_sender_chat_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// unhideGeneralForumTopic
//
// Use this method to unhide the 'General' topic in a forum supergroup chat. The bot must be an administrator in the chat for this to work and must have the *can\\_manage\\_topics* administrator rights. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postUnhideGeneralForumTopic(apiClient_t *apiClient, post_restrict_chat_member_request_chat_id_t *chat_id)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/unhideGeneralForumTopic");





    // form parameters
    char *keyForm_chat_id = NULL;
    post_restrict_chat_member_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// unpinAllChatMessages
//
// Use this method to clear the list of pinned messages in a chat. If the chat is not a private chat, the bot must be an administrator in the chat for this to work and must have the 'can\\_pin\\_messages' administrator right in a supergroup or 'can\\_edit\\_messages' administrator right in a channel. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postUnpinAllChatMessages(apiClient_t *apiClient, post_send_message_request_chat_id_t *chat_id)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/unpinAllChatMessages");





    // form parameters
    char *keyForm_chat_id = NULL;
    post_send_message_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// unpinAllForumTopicMessages
//
// Use this method to clear the list of pinned messages in a forum topic. The bot must be an administrator in the chat for this to work and must have the *can\\_pin\\_messages* administrator right in the supergroup. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postUnpinAllForumTopicMessages(apiClient_t *apiClient, post_restrict_chat_member_request_chat_id_t *chat_id, int *message_thread_id)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/unpinAllForumTopicMessages");





    // form parameters
    char *keyForm_chat_id = NULL;
    post_restrict_chat_member_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_message_thread_id = NULL;
    int valueForm_message_thread_id = 0;
    keyValuePair_t *keyPairForm_message_thread_id = 0;
    if (message_thread_id != NULL)
    {
        keyForm_message_thread_id = strdup("message_thread_id");
        valueForm_message_thread_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_message_thread_id, MAX_NUMBER_LENGTH, "%d", *message_thread_id);
        keyPairForm_message_thread_id = keyValuePair_create(keyForm_message_thread_id,&valueForm_message_thread_id);
        list_addElement(localVarFormParameters,keyPairForm_message_thread_id);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_message_thread_id) {
        free(keyForm_message_thread_id);
        keyForm_message_thread_id = NULL;
    }
    free(keyPairForm_message_thread_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// unpinAllGeneralForumTopicMessages
//
// Use this method to clear the list of pinned messages in a General forum topic. The bot must be an administrator in the chat for this to work and must have the *can\\_pin\\_messages* administrator right in the supergroup. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postUnpinAllGeneralForumTopicMessages(apiClient_t *apiClient, post_restrict_chat_member_request_chat_id_t *chat_id)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/unpinAllGeneralForumTopicMessages");





    // form parameters
    char *keyForm_chat_id = NULL;
    post_restrict_chat_member_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// unpinChatMessage
//
// Use this method to remove a message from the list of pinned messages in a chat. If the chat is not a private chat, the bot must be an administrator in the chat for this to work and must have the 'can\\_pin\\_messages' administrator right in a supergroup or 'can\\_edit\\_messages' administrator right in a channel. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postUnpinChatMessage(apiClient_t *apiClient, post_send_message_request_chat_id_t *chat_id, char *business_connection_id, int *message_id)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/unpinChatMessage");





    // form parameters
    char *keyForm_business_connection_id = NULL;
    char * valueForm_business_connection_id = 0;
    keyValuePair_t *keyPairForm_business_connection_id = 0;
    if (business_connection_id != NULL)
    {
        keyForm_business_connection_id = strdup("business_connection_id");
        valueForm_business_connection_id = strdup((business_connection_id));
        keyPairForm_business_connection_id = keyValuePair_create(keyForm_business_connection_id,valueForm_business_connection_id);
        list_addElement(localVarFormParameters,keyPairForm_business_connection_id);
    }

    // form parameters
    char *keyForm_chat_id = NULL;
    post_send_message_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_message_id = NULL;
    int valueForm_message_id = 0;
    keyValuePair_t *keyPairForm_message_id = 0;
    if (message_id != NULL)
    {
        keyForm_message_id = strdup("message_id");
        valueForm_message_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_message_id, MAX_NUMBER_LENGTH, "%d", *message_id);
        keyPairForm_message_id = keyValuePair_create(keyForm_message_id,&valueForm_message_id);
        list_addElement(localVarFormParameters,keyPairForm_message_id);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_business_connection_id) {
        free(keyForm_business_connection_id);
        keyForm_business_connection_id = NULL;
    }
    if (valueForm_business_connection_id) {
        free(valueForm_business_connection_id);
        valueForm_business_connection_id = NULL;
    }
    free(keyPairForm_business_connection_id);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_message_id) {
        free(keyForm_message_id);
        keyForm_message_id = NULL;
    }
    free(keyPairForm_message_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// upgradeGift
//
// Upgrades a given regular gift to a unique gift. Requires the *can\\_transfer\\_and\\_upgrade\\_gifts* business bot right. Additionally requires the *can\\_transfer\\_stars* business bot right if the upgrade is paid. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postUpgradeGift(apiClient_t *apiClient, char *business_connection_id, char *owned_gift_id, int *keep_original_details, int *star_count)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/upgradeGift");





    // form parameters
    char *keyForm_business_connection_id = NULL;
    char * valueForm_business_connection_id = 0;
    keyValuePair_t *keyPairForm_business_connection_id = 0;
    if (business_connection_id != NULL)
    {
        keyForm_business_connection_id = strdup("business_connection_id");
        valueForm_business_connection_id = strdup((business_connection_id));
        keyPairForm_business_connection_id = keyValuePair_create(keyForm_business_connection_id,valueForm_business_connection_id);
        list_addElement(localVarFormParameters,keyPairForm_business_connection_id);
    }

    // form parameters
    char *keyForm_owned_gift_id = NULL;
    char * valueForm_owned_gift_id = 0;
    keyValuePair_t *keyPairForm_owned_gift_id = 0;
    if (owned_gift_id != NULL)
    {
        keyForm_owned_gift_id = strdup("owned_gift_id");
        valueForm_owned_gift_id = strdup((owned_gift_id));
        keyPairForm_owned_gift_id = keyValuePair_create(keyForm_owned_gift_id,valueForm_owned_gift_id);
        list_addElement(localVarFormParameters,keyPairForm_owned_gift_id);
    }

    // form parameters
    char *keyForm_keep_original_details = NULL;
    char * valueForm_keep_original_details = 0;
    keyValuePair_t *keyPairForm_keep_original_details = 0;
    if (keep_original_details != NULL)
    {
        keyForm_keep_original_details = strdup("keep_original_details");
        valueForm_keep_original_details = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_keep_original_details, MAX_NUMBER_LENGTH, "%d", *keep_original_details);
        keyPairForm_keep_original_details = keyValuePair_create(keyForm_keep_original_details,valueForm_keep_original_details);
        list_addElement(localVarFormParameters,keyPairForm_keep_original_details);
    }

    // form parameters
    char *keyForm_star_count = NULL;
    int valueForm_star_count = 0;
    keyValuePair_t *keyPairForm_star_count = 0;
    if (star_count != NULL)
    {
        keyForm_star_count = strdup("star_count");
        valueForm_star_count = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_star_count, MAX_NUMBER_LENGTH, "%d", *star_count);
        keyPairForm_star_count = keyValuePair_create(keyForm_star_count,&valueForm_star_count);
        list_addElement(localVarFormParameters,keyPairForm_star_count);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_business_connection_id) {
        free(keyForm_business_connection_id);
        keyForm_business_connection_id = NULL;
    }
    if (valueForm_business_connection_id) {
        free(valueForm_business_connection_id);
        valueForm_business_connection_id = NULL;
    }
    free(keyPairForm_business_connection_id);
    if (keyForm_owned_gift_id) {
        free(keyForm_owned_gift_id);
        keyForm_owned_gift_id = NULL;
    }
    if (valueForm_owned_gift_id) {
        free(valueForm_owned_gift_id);
        valueForm_owned_gift_id = NULL;
    }
    free(keyPairForm_owned_gift_id);
    if (keyForm_keep_original_details) {
        free(keyForm_keep_original_details);
        keyForm_keep_original_details = NULL;
    }
    free(keyPairForm_keep_original_details);
    if (keyForm_star_count) {
        free(keyForm_star_count);
        keyForm_star_count = NULL;
    }
    free(keyPairForm_star_count);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// uploadStickerFile
//
// Use this method to upload a file with a sticker for later use in the [createNewStickerSet](https://core.telegram.org/bots/api/#createnewstickerset), [addStickerToSet](https://core.telegram.org/bots/api/#addstickertoset), or [replaceStickerInSet](https://core.telegram.org/bots/api/#replacestickerinset) methods (the file can be used multiple times). Returns the uploaded [File](https://core.telegram.org/bots/api/#file) on success.
//
post_get_file_200_response_t*
DefaultAPI_postUploadStickerFile(apiClient_t *apiClient, int *user_id, sticker, telegram_bot_api_postUploadStickerFile_sticker_format_e sticker_format)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/uploadStickerFile");





    // form parameters
    char *keyForm_user_id = NULL;
    int valueForm_user_id = 0;
    keyValuePair_t *keyPairForm_user_id = 0;
    if (user_id != NULL)
    {
        keyForm_user_id = strdup("user_id");
        valueForm_user_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_user_id, MAX_NUMBER_LENGTH, "%d", *user_id);
        keyPairForm_user_id = keyValuePair_create(keyForm_user_id,&valueForm_user_id);
        list_addElement(localVarFormParameters,keyPairForm_user_id);
    }

    // form parameters
    char *keyForm_sticker = NULL;
     valueForm_sticker = 0;
    keyValuePair_t *keyPairForm_sticker = 0;
    if (sticker != NULL)
    {
        keyForm_sticker = strdup("sticker");
        valueForm_sticker = (sticker);
        keyPairForm_sticker = keyValuePair_create(keyForm_sticker,&valueForm_sticker);
        list_addElement(localVarFormParameters,keyPairForm_sticker);
    }

    // form parameters
    char *keyForm_sticker_format = NULL;
    telegram_bot_api_postUploadStickerFile_sticker_format_e valueForm_sticker_format = 0;
    keyValuePair_t *keyPairForm_sticker_format = 0;
    if (sticker_format != 0)
    {
        keyForm_sticker_format = strdup("sticker_format");
        valueForm_sticker_format = (sticker_format);
        keyPairForm_sticker_format = keyValuePair_create(keyForm_sticker_format,(void *)valueForm_sticker_format);
        list_addElement(localVarFormParameters,keyPairForm_sticker_format);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_get_file_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_get_file_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_user_id) {
        free(keyForm_user_id);
        keyForm_user_id = NULL;
    }
    free(keyPairForm_user_id);
    if (keyForm_sticker) {
        free(keyForm_sticker);
        keyForm_sticker = NULL;
    }
    free(keyPairForm_sticker);
    if (keyForm_sticker_format) {
        free(keyForm_sticker_format);
        keyForm_sticker_format = NULL;
    }
    if (valueForm_sticker_format) {
        valueForm_sticker_format = 0;
    }
    free(keyPairForm_sticker_format);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// verifyChat
//
// Verifies a chat [on behalf of the organization](https://telegram.org/verify#third-party-verification) which is represented by the bot. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postVerifyChat(apiClient_t *apiClient, post_send_message_request_chat_id_t *chat_id, char *custom_description)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/verifyChat");





    // form parameters
    char *keyForm_chat_id = NULL;
    post_send_message_request_chat_id_t * valueForm_chat_id = 0;
    keyValuePair_t *keyPairForm_chat_id = 0;
    if (chat_id != NULL)
    {
        keyForm_chat_id = strdup("chat_id");
        valueForm_chat_id = (chat_id);
        keyPairForm_chat_id = keyValuePair_create(keyForm_chat_id,&valueForm_chat_id);
        list_addElement(localVarFormParameters,keyPairForm_chat_id);
    }

    // form parameters
    char *keyForm_custom_description = NULL;
    char * valueForm_custom_description = 0;
    keyValuePair_t *keyPairForm_custom_description = 0;
    if (custom_description != NULL)
    {
        keyForm_custom_description = strdup("custom_description");
        valueForm_custom_description = strdup((custom_description));
        keyPairForm_custom_description = keyValuePair_create(keyForm_custom_description,valueForm_custom_description);
        list_addElement(localVarFormParameters,keyPairForm_custom_description);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_chat_id) {
        free(keyForm_chat_id);
        keyForm_chat_id = NULL;
    }
    free(keyPairForm_chat_id);
    if (keyForm_custom_description) {
        free(keyForm_custom_description);
        keyForm_custom_description = NULL;
    }
    if (valueForm_custom_description) {
        free(valueForm_custom_description);
        valueForm_custom_description = NULL;
    }
    free(keyPairForm_custom_description);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// verifyUser
//
// Verifies a user [on behalf of the organization](https://telegram.org/verify#third-party-verification) which is represented by the bot. Returns *True* on success.
//
post_set_webhook_200_response_t*
DefaultAPI_postVerifyUser(apiClient_t *apiClient, int *user_id, char *custom_description)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/verifyUser");





    // form parameters
    char *keyForm_user_id = NULL;
    int valueForm_user_id = 0;
    keyValuePair_t *keyPairForm_user_id = 0;
    if (user_id != NULL)
    {
        keyForm_user_id = strdup("user_id");
        valueForm_user_id = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_user_id, MAX_NUMBER_LENGTH, "%d", *user_id);
        keyPairForm_user_id = keyValuePair_create(keyForm_user_id,&valueForm_user_id);
        list_addElement(localVarFormParameters,keyPairForm_user_id);
    }

    // form parameters
    char *keyForm_custom_description = NULL;
    char * valueForm_custom_description = 0;
    keyValuePair_t *keyPairForm_custom_description = 0;
    if (custom_description != NULL)
    {
        keyForm_custom_description = strdup("custom_description");
        valueForm_custom_description = strdup((custom_description));
        keyPairForm_custom_description = keyValuePair_create(keyForm_custom_description,valueForm_custom_description);
        list_addElement(localVarFormParameters,keyPairForm_custom_description);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    list_addElement(localVarContentType,"multipart/form-data"); //consumes
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","");
    //}
    //nonprimitive not container
    post_set_webhook_200_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_set_webhook_200_response_parseFromJSON(DefaultAPIlocalVarJSON);
        cJSON_Delete(DefaultAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_user_id) {
        free(keyForm_user_id);
        keyForm_user_id = NULL;
    }
    free(keyPairForm_user_id);
    if (keyForm_custom_description) {
        free(keyForm_custom_description);
        keyForm_custom_description = NULL;
    }
    if (valueForm_custom_description) {
        free(valueForm_custom_description);
        valueForm_custom_description = NULL;
    }
    free(keyPairForm_custom_description);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

