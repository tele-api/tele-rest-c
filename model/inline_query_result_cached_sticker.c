#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "inline_query_result_cached_sticker.h"



static inline_query_result_cached_sticker_t *inline_query_result_cached_sticker_create_internal(
    char *type,
    char *id,
    char *sticker_file_id,
    inline_keyboard_markup_t *reply_markup,
    input_message_content_t *input_message_content
    ) {
    inline_query_result_cached_sticker_t *inline_query_result_cached_sticker_local_var = malloc(sizeof(inline_query_result_cached_sticker_t));
    if (!inline_query_result_cached_sticker_local_var) {
        return NULL;
    }
    inline_query_result_cached_sticker_local_var->type = type;
    inline_query_result_cached_sticker_local_var->id = id;
    inline_query_result_cached_sticker_local_var->sticker_file_id = sticker_file_id;
    inline_query_result_cached_sticker_local_var->reply_markup = reply_markup;
    inline_query_result_cached_sticker_local_var->input_message_content = input_message_content;

    inline_query_result_cached_sticker_local_var->_library_owned = 1;
    return inline_query_result_cached_sticker_local_var;
}

__attribute__((deprecated)) inline_query_result_cached_sticker_t *inline_query_result_cached_sticker_create(
    char *type,
    char *id,
    char *sticker_file_id,
    inline_keyboard_markup_t *reply_markup,
    input_message_content_t *input_message_content
    ) {
    return inline_query_result_cached_sticker_create_internal (
        type,
        id,
        sticker_file_id,
        reply_markup,
        input_message_content
        );
}

void inline_query_result_cached_sticker_free(inline_query_result_cached_sticker_t *inline_query_result_cached_sticker) {
    if(NULL == inline_query_result_cached_sticker){
        return ;
    }
    if(inline_query_result_cached_sticker->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "inline_query_result_cached_sticker_free");
        return ;
    }
    listEntry_t *listEntry;
    if (inline_query_result_cached_sticker->type) {
        free(inline_query_result_cached_sticker->type);
        inline_query_result_cached_sticker->type = NULL;
    }
    if (inline_query_result_cached_sticker->id) {
        free(inline_query_result_cached_sticker->id);
        inline_query_result_cached_sticker->id = NULL;
    }
    if (inline_query_result_cached_sticker->sticker_file_id) {
        free(inline_query_result_cached_sticker->sticker_file_id);
        inline_query_result_cached_sticker->sticker_file_id = NULL;
    }
    if (inline_query_result_cached_sticker->reply_markup) {
        inline_keyboard_markup_free(inline_query_result_cached_sticker->reply_markup);
        inline_query_result_cached_sticker->reply_markup = NULL;
    }
    if (inline_query_result_cached_sticker->input_message_content) {
        input_message_content_free(inline_query_result_cached_sticker->input_message_content);
        inline_query_result_cached_sticker->input_message_content = NULL;
    }
    free(inline_query_result_cached_sticker);
}

cJSON *inline_query_result_cached_sticker_convertToJSON(inline_query_result_cached_sticker_t *inline_query_result_cached_sticker) {
    cJSON *item = cJSON_CreateObject();

    // inline_query_result_cached_sticker->type
    if (!inline_query_result_cached_sticker->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", inline_query_result_cached_sticker->type) == NULL) {
    goto fail; //String
    }


    // inline_query_result_cached_sticker->id
    if (!inline_query_result_cached_sticker->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", inline_query_result_cached_sticker->id) == NULL) {
    goto fail; //String
    }


    // inline_query_result_cached_sticker->sticker_file_id
    if (!inline_query_result_cached_sticker->sticker_file_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "sticker_file_id", inline_query_result_cached_sticker->sticker_file_id) == NULL) {
    goto fail; //String
    }


    // inline_query_result_cached_sticker->reply_markup
    if(inline_query_result_cached_sticker->reply_markup) {
    cJSON *reply_markup_local_JSON = inline_keyboard_markup_convertToJSON(inline_query_result_cached_sticker->reply_markup);
    if(reply_markup_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "reply_markup", reply_markup_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // inline_query_result_cached_sticker->input_message_content
    if(inline_query_result_cached_sticker->input_message_content) {
    cJSON *input_message_content_local_JSON = input_message_content_convertToJSON(inline_query_result_cached_sticker->input_message_content);
    if(input_message_content_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "input_message_content", input_message_content_local_JSON);
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

inline_query_result_cached_sticker_t *inline_query_result_cached_sticker_parseFromJSON(cJSON *inline_query_result_cached_stickerJSON){

    inline_query_result_cached_sticker_t *inline_query_result_cached_sticker_local_var = NULL;

    // define the local variable for inline_query_result_cached_sticker->reply_markup
    inline_keyboard_markup_t *reply_markup_local_nonprim = NULL;

    // define the local variable for inline_query_result_cached_sticker->input_message_content
    input_message_content_t *input_message_content_local_nonprim = NULL;

    // inline_query_result_cached_sticker->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(inline_query_result_cached_stickerJSON, "type");
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

    // inline_query_result_cached_sticker->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(inline_query_result_cached_stickerJSON, "id");
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

    // inline_query_result_cached_sticker->sticker_file_id
    cJSON *sticker_file_id = cJSON_GetObjectItemCaseSensitive(inline_query_result_cached_stickerJSON, "sticker_file_id");
    if (cJSON_IsNull(sticker_file_id)) {
        sticker_file_id = NULL;
    }
    if (!sticker_file_id) {
        goto end;
    }

    
    if(!cJSON_IsString(sticker_file_id))
    {
    goto end; //String
    }

    // inline_query_result_cached_sticker->reply_markup
    cJSON *reply_markup = cJSON_GetObjectItemCaseSensitive(inline_query_result_cached_stickerJSON, "reply_markup");
    if (cJSON_IsNull(reply_markup)) {
        reply_markup = NULL;
    }
    if (reply_markup) { 
    reply_markup_local_nonprim = inline_keyboard_markup_parseFromJSON(reply_markup); //nonprimitive
    }

    // inline_query_result_cached_sticker->input_message_content
    cJSON *input_message_content = cJSON_GetObjectItemCaseSensitive(inline_query_result_cached_stickerJSON, "input_message_content");
    if (cJSON_IsNull(input_message_content)) {
        input_message_content = NULL;
    }
    if (input_message_content) { 
    input_message_content_local_nonprim = input_message_content_parseFromJSON(input_message_content); //nonprimitive
    }


    inline_query_result_cached_sticker_local_var = inline_query_result_cached_sticker_create_internal (
        strdup(type->valuestring),
        strdup(id->valuestring),
        strdup(sticker_file_id->valuestring),
        reply_markup ? reply_markup_local_nonprim : NULL,
        input_message_content ? input_message_content_local_nonprim : NULL
        );

    return inline_query_result_cached_sticker_local_var;
end:
    if (reply_markup_local_nonprim) {
        inline_keyboard_markup_free(reply_markup_local_nonprim);
        reply_markup_local_nonprim = NULL;
    }
    if (input_message_content_local_nonprim) {
        input_message_content_free(input_message_content_local_nonprim);
        input_message_content_local_nonprim = NULL;
    }
    return NULL;

}
