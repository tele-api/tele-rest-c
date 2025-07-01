#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "inline_query_result_article.h"



static inline_query_result_article_t *inline_query_result_article_create_internal(
    char *type,
    char *id,
    char *title,
    input_message_content_t *input_message_content,
    inline_keyboard_markup_t *reply_markup,
    char *url,
    char *description,
    char *thumbnail_url,
    int thumbnail_width,
    int thumbnail_height
    ) {
    inline_query_result_article_t *inline_query_result_article_local_var = malloc(sizeof(inline_query_result_article_t));
    if (!inline_query_result_article_local_var) {
        return NULL;
    }
    inline_query_result_article_local_var->type = type;
    inline_query_result_article_local_var->id = id;
    inline_query_result_article_local_var->title = title;
    inline_query_result_article_local_var->input_message_content = input_message_content;
    inline_query_result_article_local_var->reply_markup = reply_markup;
    inline_query_result_article_local_var->url = url;
    inline_query_result_article_local_var->description = description;
    inline_query_result_article_local_var->thumbnail_url = thumbnail_url;
    inline_query_result_article_local_var->thumbnail_width = thumbnail_width;
    inline_query_result_article_local_var->thumbnail_height = thumbnail_height;

    inline_query_result_article_local_var->_library_owned = 1;
    return inline_query_result_article_local_var;
}

__attribute__((deprecated)) inline_query_result_article_t *inline_query_result_article_create(
    char *type,
    char *id,
    char *title,
    input_message_content_t *input_message_content,
    inline_keyboard_markup_t *reply_markup,
    char *url,
    char *description,
    char *thumbnail_url,
    int thumbnail_width,
    int thumbnail_height
    ) {
    return inline_query_result_article_create_internal (
        type,
        id,
        title,
        input_message_content,
        reply_markup,
        url,
        description,
        thumbnail_url,
        thumbnail_width,
        thumbnail_height
        );
}

void inline_query_result_article_free(inline_query_result_article_t *inline_query_result_article) {
    if(NULL == inline_query_result_article){
        return ;
    }
    if(inline_query_result_article->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "inline_query_result_article_free");
        return ;
    }
    listEntry_t *listEntry;
    if (inline_query_result_article->type) {
        free(inline_query_result_article->type);
        inline_query_result_article->type = NULL;
    }
    if (inline_query_result_article->id) {
        free(inline_query_result_article->id);
        inline_query_result_article->id = NULL;
    }
    if (inline_query_result_article->title) {
        free(inline_query_result_article->title);
        inline_query_result_article->title = NULL;
    }
    if (inline_query_result_article->input_message_content) {
        input_message_content_free(inline_query_result_article->input_message_content);
        inline_query_result_article->input_message_content = NULL;
    }
    if (inline_query_result_article->reply_markup) {
        inline_keyboard_markup_free(inline_query_result_article->reply_markup);
        inline_query_result_article->reply_markup = NULL;
    }
    if (inline_query_result_article->url) {
        free(inline_query_result_article->url);
        inline_query_result_article->url = NULL;
    }
    if (inline_query_result_article->description) {
        free(inline_query_result_article->description);
        inline_query_result_article->description = NULL;
    }
    if (inline_query_result_article->thumbnail_url) {
        free(inline_query_result_article->thumbnail_url);
        inline_query_result_article->thumbnail_url = NULL;
    }
    free(inline_query_result_article);
}

cJSON *inline_query_result_article_convertToJSON(inline_query_result_article_t *inline_query_result_article) {
    cJSON *item = cJSON_CreateObject();

    // inline_query_result_article->type
    if (!inline_query_result_article->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", inline_query_result_article->type) == NULL) {
    goto fail; //String
    }


    // inline_query_result_article->id
    if (!inline_query_result_article->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", inline_query_result_article->id) == NULL) {
    goto fail; //String
    }


    // inline_query_result_article->title
    if (!inline_query_result_article->title) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "title", inline_query_result_article->title) == NULL) {
    goto fail; //String
    }


    // inline_query_result_article->input_message_content
    if (!inline_query_result_article->input_message_content) {
        goto fail;
    }
    cJSON *input_message_content_local_JSON = input_message_content_convertToJSON(inline_query_result_article->input_message_content);
    if(input_message_content_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "input_message_content", input_message_content_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // inline_query_result_article->reply_markup
    if(inline_query_result_article->reply_markup) {
    cJSON *reply_markup_local_JSON = inline_keyboard_markup_convertToJSON(inline_query_result_article->reply_markup);
    if(reply_markup_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "reply_markup", reply_markup_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // inline_query_result_article->url
    if(inline_query_result_article->url) {
    if(cJSON_AddStringToObject(item, "url", inline_query_result_article->url) == NULL) {
    goto fail; //String
    }
    }


    // inline_query_result_article->description
    if(inline_query_result_article->description) {
    if(cJSON_AddStringToObject(item, "description", inline_query_result_article->description) == NULL) {
    goto fail; //String
    }
    }


    // inline_query_result_article->thumbnail_url
    if(inline_query_result_article->thumbnail_url) {
    if(cJSON_AddStringToObject(item, "thumbnail_url", inline_query_result_article->thumbnail_url) == NULL) {
    goto fail; //String
    }
    }


    // inline_query_result_article->thumbnail_width
    if(inline_query_result_article->thumbnail_width) {
    if(cJSON_AddNumberToObject(item, "thumbnail_width", inline_query_result_article->thumbnail_width) == NULL) {
    goto fail; //Numeric
    }
    }


    // inline_query_result_article->thumbnail_height
    if(inline_query_result_article->thumbnail_height) {
    if(cJSON_AddNumberToObject(item, "thumbnail_height", inline_query_result_article->thumbnail_height) == NULL) {
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

inline_query_result_article_t *inline_query_result_article_parseFromJSON(cJSON *inline_query_result_articleJSON){

    inline_query_result_article_t *inline_query_result_article_local_var = NULL;

    // define the local variable for inline_query_result_article->input_message_content
    input_message_content_t *input_message_content_local_nonprim = NULL;

    // define the local variable for inline_query_result_article->reply_markup
    inline_keyboard_markup_t *reply_markup_local_nonprim = NULL;

    // inline_query_result_article->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(inline_query_result_articleJSON, "type");
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

    // inline_query_result_article->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(inline_query_result_articleJSON, "id");
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

    // inline_query_result_article->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(inline_query_result_articleJSON, "title");
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

    // inline_query_result_article->input_message_content
    cJSON *input_message_content = cJSON_GetObjectItemCaseSensitive(inline_query_result_articleJSON, "input_message_content");
    if (cJSON_IsNull(input_message_content)) {
        input_message_content = NULL;
    }
    if (!input_message_content) {
        goto end;
    }

    
    input_message_content_local_nonprim = input_message_content_parseFromJSON(input_message_content); //nonprimitive

    // inline_query_result_article->reply_markup
    cJSON *reply_markup = cJSON_GetObjectItemCaseSensitive(inline_query_result_articleJSON, "reply_markup");
    if (cJSON_IsNull(reply_markup)) {
        reply_markup = NULL;
    }
    if (reply_markup) { 
    reply_markup_local_nonprim = inline_keyboard_markup_parseFromJSON(reply_markup); //nonprimitive
    }

    // inline_query_result_article->url
    cJSON *url = cJSON_GetObjectItemCaseSensitive(inline_query_result_articleJSON, "url");
    if (cJSON_IsNull(url)) {
        url = NULL;
    }
    if (url) { 
    if(!cJSON_IsString(url) && !cJSON_IsNull(url))
    {
    goto end; //String
    }
    }

    // inline_query_result_article->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(inline_query_result_articleJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (description) { 
    if(!cJSON_IsString(description) && !cJSON_IsNull(description))
    {
    goto end; //String
    }
    }

    // inline_query_result_article->thumbnail_url
    cJSON *thumbnail_url = cJSON_GetObjectItemCaseSensitive(inline_query_result_articleJSON, "thumbnail_url");
    if (cJSON_IsNull(thumbnail_url)) {
        thumbnail_url = NULL;
    }
    if (thumbnail_url) { 
    if(!cJSON_IsString(thumbnail_url) && !cJSON_IsNull(thumbnail_url))
    {
    goto end; //String
    }
    }

    // inline_query_result_article->thumbnail_width
    cJSON *thumbnail_width = cJSON_GetObjectItemCaseSensitive(inline_query_result_articleJSON, "thumbnail_width");
    if (cJSON_IsNull(thumbnail_width)) {
        thumbnail_width = NULL;
    }
    if (thumbnail_width) { 
    if(!cJSON_IsNumber(thumbnail_width))
    {
    goto end; //Numeric
    }
    }

    // inline_query_result_article->thumbnail_height
    cJSON *thumbnail_height = cJSON_GetObjectItemCaseSensitive(inline_query_result_articleJSON, "thumbnail_height");
    if (cJSON_IsNull(thumbnail_height)) {
        thumbnail_height = NULL;
    }
    if (thumbnail_height) { 
    if(!cJSON_IsNumber(thumbnail_height))
    {
    goto end; //Numeric
    }
    }


    inline_query_result_article_local_var = inline_query_result_article_create_internal (
        strdup(type->valuestring),
        strdup(id->valuestring),
        strdup(title->valuestring),
        input_message_content_local_nonprim,
        reply_markup ? reply_markup_local_nonprim : NULL,
        url && !cJSON_IsNull(url) ? strdup(url->valuestring) : NULL,
        description && !cJSON_IsNull(description) ? strdup(description->valuestring) : NULL,
        thumbnail_url && !cJSON_IsNull(thumbnail_url) ? strdup(thumbnail_url->valuestring) : NULL,
        thumbnail_width ? thumbnail_width->valuedouble : 0,
        thumbnail_height ? thumbnail_height->valuedouble : 0
        );

    return inline_query_result_article_local_var;
end:
    if (input_message_content_local_nonprim) {
        input_message_content_free(input_message_content_local_nonprim);
        input_message_content_local_nonprim = NULL;
    }
    if (reply_markup_local_nonprim) {
        inline_keyboard_markup_free(reply_markup_local_nonprim);
        reply_markup_local_nonprim = NULL;
    }
    return NULL;

}
