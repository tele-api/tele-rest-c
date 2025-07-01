#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "inline_query.h"


char* inline_query_chat_type_ToString(telegram_bot_api_inline_query_CHATTYPE_e chat_type) {
    char* chat_typeArray[] =  { "NULL", "sender", "private", "group", "supergroup", "channel" };
    return chat_typeArray[chat_type];
}

telegram_bot_api_inline_query_CHATTYPE_e inline_query_chat_type_FromString(char* chat_type){
    int stringToReturn = 0;
    char *chat_typeArray[] =  { "NULL", "sender", "private", "group", "supergroup", "channel" };
    size_t sizeofArray = sizeof(chat_typeArray) / sizeof(chat_typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(chat_type, chat_typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static inline_query_t *inline_query_create_internal(
    char *id,
    user_t *from,
    char *query,
    char *offset,
    telegram_bot_api_inline_query_CHATTYPE_e chat_type,
    location_t *location
    ) {
    inline_query_t *inline_query_local_var = malloc(sizeof(inline_query_t));
    if (!inline_query_local_var) {
        return NULL;
    }
    inline_query_local_var->id = id;
    inline_query_local_var->from = from;
    inline_query_local_var->query = query;
    inline_query_local_var->offset = offset;
    inline_query_local_var->chat_type = chat_type;
    inline_query_local_var->location = location;

    inline_query_local_var->_library_owned = 1;
    return inline_query_local_var;
}

__attribute__((deprecated)) inline_query_t *inline_query_create(
    char *id,
    user_t *from,
    char *query,
    char *offset,
    telegram_bot_api_inline_query_CHATTYPE_e chat_type,
    location_t *location
    ) {
    return inline_query_create_internal (
        id,
        from,
        query,
        offset,
        chat_type,
        location
        );
}

void inline_query_free(inline_query_t *inline_query) {
    if(NULL == inline_query){
        return ;
    }
    if(inline_query->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "inline_query_free");
        return ;
    }
    listEntry_t *listEntry;
    if (inline_query->id) {
        free(inline_query->id);
        inline_query->id = NULL;
    }
    if (inline_query->from) {
        user_free(inline_query->from);
        inline_query->from = NULL;
    }
    if (inline_query->query) {
        free(inline_query->query);
        inline_query->query = NULL;
    }
    if (inline_query->offset) {
        free(inline_query->offset);
        inline_query->offset = NULL;
    }
    if (inline_query->location) {
        location_free(inline_query->location);
        inline_query->location = NULL;
    }
    free(inline_query);
}

cJSON *inline_query_convertToJSON(inline_query_t *inline_query) {
    cJSON *item = cJSON_CreateObject();

    // inline_query->id
    if (!inline_query->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", inline_query->id) == NULL) {
    goto fail; //String
    }


    // inline_query->from
    if (!inline_query->from) {
        goto fail;
    }
    cJSON *from_local_JSON = user_convertToJSON(inline_query->from);
    if(from_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "from", from_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // inline_query->query
    if (!inline_query->query) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "query", inline_query->query) == NULL) {
    goto fail; //String
    }


    // inline_query->offset
    if (!inline_query->offset) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "offset", inline_query->offset) == NULL) {
    goto fail; //String
    }


    // inline_query->chat_type
    if(inline_query->chat_type != telegram_bot_api_inline_query_CHATTYPE_NULL) {
    if(cJSON_AddStringToObject(item, "chat_type", inline_query_chat_type_ToString(inline_query->chat_type)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // inline_query->location
    if(inline_query->location) {
    cJSON *location_local_JSON = location_convertToJSON(inline_query->location);
    if(location_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "location", location_local_JSON);
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

inline_query_t *inline_query_parseFromJSON(cJSON *inline_queryJSON){

    inline_query_t *inline_query_local_var = NULL;

    // define the local variable for inline_query->from
    user_t *from_local_nonprim = NULL;

    // define the local variable for inline_query->location
    location_t *location_local_nonprim = NULL;

    // inline_query->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(inline_queryJSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (!id) {
        goto end;
    }

    
    if(!cJSON_IsString(id))
    {
    goto end; //String
    }

    // inline_query->from
    cJSON *from = cJSON_GetObjectItemCaseSensitive(inline_queryJSON, "from");
    if (cJSON_IsNull(from)) {
        from = NULL;
    }
    if (!from) {
        goto end;
    }

    
    from_local_nonprim = user_parseFromJSON(from); //nonprimitive

    // inline_query->query
    cJSON *query = cJSON_GetObjectItemCaseSensitive(inline_queryJSON, "query");
    if (cJSON_IsNull(query)) {
        query = NULL;
    }
    if (!query) {
        goto end;
    }

    
    if(!cJSON_IsString(query))
    {
    goto end; //String
    }

    // inline_query->offset
    cJSON *offset = cJSON_GetObjectItemCaseSensitive(inline_queryJSON, "offset");
    if (cJSON_IsNull(offset)) {
        offset = NULL;
    }
    if (!offset) {
        goto end;
    }

    
    if(!cJSON_IsString(offset))
    {
    goto end; //String
    }

    // inline_query->chat_type
    cJSON *chat_type = cJSON_GetObjectItemCaseSensitive(inline_queryJSON, "chat_type");
    if (cJSON_IsNull(chat_type)) {
        chat_type = NULL;
    }
    telegram_bot_api_inline_query_CHATTYPE_e chat_typeVariable;
    if (chat_type) { 
    if(!cJSON_IsString(chat_type))
    {
    goto end; //Enum
    }
    chat_typeVariable = inline_query_chat_type_FromString(chat_type->valuestring);
    }

    // inline_query->location
    cJSON *location = cJSON_GetObjectItemCaseSensitive(inline_queryJSON, "location");
    if (cJSON_IsNull(location)) {
        location = NULL;
    }
    if (location) { 
    location_local_nonprim = location_parseFromJSON(location); //nonprimitive
    }


    inline_query_local_var = inline_query_create_internal (
        strdup(id->valuestring),
        from_local_nonprim,
        strdup(query->valuestring),
        strdup(offset->valuestring),
        chat_type ? chat_typeVariable : telegram_bot_api_inline_query_CHATTYPE_NULL,
        location ? location_local_nonprim : NULL
        );

    return inline_query_local_var;
end:
    if (from_local_nonprim) {
        user_free(from_local_nonprim);
        from_local_nonprim = NULL;
    }
    if (location_local_nonprim) {
        location_free(location_local_nonprim);
        location_local_nonprim = NULL;
    }
    return NULL;

}
