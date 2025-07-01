#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "link_preview_options.h"



static link_preview_options_t *link_preview_options_create_internal(
    int is_disabled,
    char *url,
    int prefer_small_media,
    int prefer_large_media,
    int show_above_text
    ) {
    link_preview_options_t *link_preview_options_local_var = malloc(sizeof(link_preview_options_t));
    if (!link_preview_options_local_var) {
        return NULL;
    }
    link_preview_options_local_var->is_disabled = is_disabled;
    link_preview_options_local_var->url = url;
    link_preview_options_local_var->prefer_small_media = prefer_small_media;
    link_preview_options_local_var->prefer_large_media = prefer_large_media;
    link_preview_options_local_var->show_above_text = show_above_text;

    link_preview_options_local_var->_library_owned = 1;
    return link_preview_options_local_var;
}

__attribute__((deprecated)) link_preview_options_t *link_preview_options_create(
    int is_disabled,
    char *url,
    int prefer_small_media,
    int prefer_large_media,
    int show_above_text
    ) {
    return link_preview_options_create_internal (
        is_disabled,
        url,
        prefer_small_media,
        prefer_large_media,
        show_above_text
        );
}

void link_preview_options_free(link_preview_options_t *link_preview_options) {
    if(NULL == link_preview_options){
        return ;
    }
    if(link_preview_options->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "link_preview_options_free");
        return ;
    }
    listEntry_t *listEntry;
    if (link_preview_options->url) {
        free(link_preview_options->url);
        link_preview_options->url = NULL;
    }
    free(link_preview_options);
}

cJSON *link_preview_options_convertToJSON(link_preview_options_t *link_preview_options) {
    cJSON *item = cJSON_CreateObject();

    // link_preview_options->is_disabled
    if(link_preview_options->is_disabled) {
    if(cJSON_AddBoolToObject(item, "is_disabled", link_preview_options->is_disabled) == NULL) {
    goto fail; //Bool
    }
    }


    // link_preview_options->url
    if(link_preview_options->url) {
    if(cJSON_AddStringToObject(item, "url", link_preview_options->url) == NULL) {
    goto fail; //String
    }
    }


    // link_preview_options->prefer_small_media
    if(link_preview_options->prefer_small_media) {
    if(cJSON_AddBoolToObject(item, "prefer_small_media", link_preview_options->prefer_small_media) == NULL) {
    goto fail; //Bool
    }
    }


    // link_preview_options->prefer_large_media
    if(link_preview_options->prefer_large_media) {
    if(cJSON_AddBoolToObject(item, "prefer_large_media", link_preview_options->prefer_large_media) == NULL) {
    goto fail; //Bool
    }
    }


    // link_preview_options->show_above_text
    if(link_preview_options->show_above_text) {
    if(cJSON_AddBoolToObject(item, "show_above_text", link_preview_options->show_above_text) == NULL) {
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

link_preview_options_t *link_preview_options_parseFromJSON(cJSON *link_preview_optionsJSON){

    link_preview_options_t *link_preview_options_local_var = NULL;

    // link_preview_options->is_disabled
    cJSON *is_disabled = cJSON_GetObjectItemCaseSensitive(link_preview_optionsJSON, "is_disabled");
    if (cJSON_IsNull(is_disabled)) {
        is_disabled = NULL;
    }
    if (is_disabled) { 
    if(!cJSON_IsBool(is_disabled))
    {
    goto end; //Bool
    }
    }

    // link_preview_options->url
    cJSON *url = cJSON_GetObjectItemCaseSensitive(link_preview_optionsJSON, "url");
    if (cJSON_IsNull(url)) {
        url = NULL;
    }
    if (url) { 
    if(!cJSON_IsString(url) && !cJSON_IsNull(url))
    {
    goto end; //String
    }
    }

    // link_preview_options->prefer_small_media
    cJSON *prefer_small_media = cJSON_GetObjectItemCaseSensitive(link_preview_optionsJSON, "prefer_small_media");
    if (cJSON_IsNull(prefer_small_media)) {
        prefer_small_media = NULL;
    }
    if (prefer_small_media) { 
    if(!cJSON_IsBool(prefer_small_media))
    {
    goto end; //Bool
    }
    }

    // link_preview_options->prefer_large_media
    cJSON *prefer_large_media = cJSON_GetObjectItemCaseSensitive(link_preview_optionsJSON, "prefer_large_media");
    if (cJSON_IsNull(prefer_large_media)) {
        prefer_large_media = NULL;
    }
    if (prefer_large_media) { 
    if(!cJSON_IsBool(prefer_large_media))
    {
    goto end; //Bool
    }
    }

    // link_preview_options->show_above_text
    cJSON *show_above_text = cJSON_GetObjectItemCaseSensitive(link_preview_optionsJSON, "show_above_text");
    if (cJSON_IsNull(show_above_text)) {
        show_above_text = NULL;
    }
    if (show_above_text) { 
    if(!cJSON_IsBool(show_above_text))
    {
    goto end; //Bool
    }
    }


    link_preview_options_local_var = link_preview_options_create_internal (
        is_disabled ? is_disabled->valueint : 0,
        url && !cJSON_IsNull(url) ? strdup(url->valuestring) : NULL,
        prefer_small_media ? prefer_small_media->valueint : 0,
        prefer_large_media ? prefer_large_media->valueint : 0,
        show_above_text ? show_above_text->valueint : 0
        );

    return link_preview_options_local_var;
end:
    return NULL;

}
