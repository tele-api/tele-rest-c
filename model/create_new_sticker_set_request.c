#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "create_new_sticker_set_request.h"


char* create_new_sticker_set_request_sticker_type_ToString(telegram_bot_api_create_new_sticker_set_request_STICKERTYPE_e sticker_type) {
    char* sticker_typeArray[] =  { "NULL", "mask", "custom_emoji" };
    return sticker_typeArray[sticker_type];
}

telegram_bot_api_create_new_sticker_set_request_STICKERTYPE_e create_new_sticker_set_request_sticker_type_FromString(char* sticker_type){
    int stringToReturn = 0;
    char *sticker_typeArray[] =  { "NULL", "mask", "custom_emoji" };
    size_t sizeofArray = sizeof(sticker_typeArray) / sizeof(sticker_typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(sticker_type, sticker_typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static create_new_sticker_set_request_t *create_new_sticker_set_request_create_internal(
    int user_id,
    char *name,
    char *title,
    list_t *stickers,
    telegram_bot_api_create_new_sticker_set_request_STICKERTYPE_e sticker_type,
    int needs_repainting
    ) {
    create_new_sticker_set_request_t *create_new_sticker_set_request_local_var = malloc(sizeof(create_new_sticker_set_request_t));
    if (!create_new_sticker_set_request_local_var) {
        return NULL;
    }
    create_new_sticker_set_request_local_var->user_id = user_id;
    create_new_sticker_set_request_local_var->name = name;
    create_new_sticker_set_request_local_var->title = title;
    create_new_sticker_set_request_local_var->stickers = stickers;
    create_new_sticker_set_request_local_var->sticker_type = sticker_type;
    create_new_sticker_set_request_local_var->needs_repainting = needs_repainting;

    create_new_sticker_set_request_local_var->_library_owned = 1;
    return create_new_sticker_set_request_local_var;
}

__attribute__((deprecated)) create_new_sticker_set_request_t *create_new_sticker_set_request_create(
    int user_id,
    char *name,
    char *title,
    list_t *stickers,
    telegram_bot_api_create_new_sticker_set_request_STICKERTYPE_e sticker_type,
    int needs_repainting
    ) {
    return create_new_sticker_set_request_create_internal (
        user_id,
        name,
        title,
        stickers,
        sticker_type,
        needs_repainting
        );
}

void create_new_sticker_set_request_free(create_new_sticker_set_request_t *create_new_sticker_set_request) {
    if(NULL == create_new_sticker_set_request){
        return ;
    }
    if(create_new_sticker_set_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "create_new_sticker_set_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (create_new_sticker_set_request->name) {
        free(create_new_sticker_set_request->name);
        create_new_sticker_set_request->name = NULL;
    }
    if (create_new_sticker_set_request->title) {
        free(create_new_sticker_set_request->title);
        create_new_sticker_set_request->title = NULL;
    }
    if (create_new_sticker_set_request->stickers) {
        list_ForEach(listEntry, create_new_sticker_set_request->stickers) {
            input_sticker_free(listEntry->data);
        }
        list_freeList(create_new_sticker_set_request->stickers);
        create_new_sticker_set_request->stickers = NULL;
    }
    free(create_new_sticker_set_request);
}

cJSON *create_new_sticker_set_request_convertToJSON(create_new_sticker_set_request_t *create_new_sticker_set_request) {
    cJSON *item = cJSON_CreateObject();

    // create_new_sticker_set_request->user_id
    if (!create_new_sticker_set_request->user_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "user_id", create_new_sticker_set_request->user_id) == NULL) {
    goto fail; //Numeric
    }


    // create_new_sticker_set_request->name
    if (!create_new_sticker_set_request->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", create_new_sticker_set_request->name) == NULL) {
    goto fail; //String
    }


    // create_new_sticker_set_request->title
    if (!create_new_sticker_set_request->title) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "title", create_new_sticker_set_request->title) == NULL) {
    goto fail; //String
    }


    // create_new_sticker_set_request->stickers
    if (!create_new_sticker_set_request->stickers) {
        goto fail;
    }
    cJSON *stickers = cJSON_AddArrayToObject(item, "stickers");
    if(stickers == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *stickersListEntry;
    if (create_new_sticker_set_request->stickers) {
    list_ForEach(stickersListEntry, create_new_sticker_set_request->stickers) {
    cJSON *itemLocal = input_sticker_convertToJSON(stickersListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(stickers, itemLocal);
    }
    }


    // create_new_sticker_set_request->sticker_type
    if(create_new_sticker_set_request->sticker_type != telegram_bot_api_create_new_sticker_set_request_STICKERTYPE_NULL) {
    if(cJSON_AddStringToObject(item, "sticker_type", create_new_sticker_set_request_sticker_type_ToString(create_new_sticker_set_request->sticker_type)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // create_new_sticker_set_request->needs_repainting
    if(create_new_sticker_set_request->needs_repainting) {
    if(cJSON_AddBoolToObject(item, "needs_repainting", create_new_sticker_set_request->needs_repainting) == NULL) {
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

create_new_sticker_set_request_t *create_new_sticker_set_request_parseFromJSON(cJSON *create_new_sticker_set_requestJSON){

    create_new_sticker_set_request_t *create_new_sticker_set_request_local_var = NULL;

    // define the local list for create_new_sticker_set_request->stickers
    list_t *stickersList = NULL;

    // create_new_sticker_set_request->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(create_new_sticker_set_requestJSON, "user_id");
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

    // create_new_sticker_set_request->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(create_new_sticker_set_requestJSON, "name");
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

    // create_new_sticker_set_request->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(create_new_sticker_set_requestJSON, "title");
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

    // create_new_sticker_set_request->stickers
    cJSON *stickers = cJSON_GetObjectItemCaseSensitive(create_new_sticker_set_requestJSON, "stickers");
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
        input_sticker_t *stickersItem = input_sticker_parseFromJSON(stickers_local_nonprimitive);

        list_addElement(stickersList, stickersItem);
    }

    // create_new_sticker_set_request->sticker_type
    cJSON *sticker_type = cJSON_GetObjectItemCaseSensitive(create_new_sticker_set_requestJSON, "sticker_type");
    if (cJSON_IsNull(sticker_type)) {
        sticker_type = NULL;
    }
    telegram_bot_api_create_new_sticker_set_request_STICKERTYPE_e sticker_typeVariable;
    if (sticker_type) { 
    if(!cJSON_IsString(sticker_type))
    {
    goto end; //Enum
    }
    sticker_typeVariable = create_new_sticker_set_request_sticker_type_FromString(sticker_type->valuestring);
    }

    // create_new_sticker_set_request->needs_repainting
    cJSON *needs_repainting = cJSON_GetObjectItemCaseSensitive(create_new_sticker_set_requestJSON, "needs_repainting");
    if (cJSON_IsNull(needs_repainting)) {
        needs_repainting = NULL;
    }
    if (needs_repainting) { 
    if(!cJSON_IsBool(needs_repainting))
    {
    goto end; //Bool
    }
    }


    create_new_sticker_set_request_local_var = create_new_sticker_set_request_create_internal (
        user_id->valuedouble,
        strdup(name->valuestring),
        strdup(title->valuestring),
        stickersList,
        sticker_type ? sticker_typeVariable : telegram_bot_api_create_new_sticker_set_request_STICKERTYPE_NULL,
        needs_repainting ? needs_repainting->valueint : 0
        );

    return create_new_sticker_set_request_local_var;
end:
    if (stickersList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, stickersList) {
            input_sticker_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(stickersList);
        stickersList = NULL;
    }
    return NULL;

}
