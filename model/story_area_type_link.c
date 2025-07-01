#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "story_area_type_link.h"



static story_area_type_link_t *story_area_type_link_create_internal(
    char *type,
    char *url
    ) {
    story_area_type_link_t *story_area_type_link_local_var = malloc(sizeof(story_area_type_link_t));
    if (!story_area_type_link_local_var) {
        return NULL;
    }
    story_area_type_link_local_var->type = type;
    story_area_type_link_local_var->url = url;

    story_area_type_link_local_var->_library_owned = 1;
    return story_area_type_link_local_var;
}

__attribute__((deprecated)) story_area_type_link_t *story_area_type_link_create(
    char *type,
    char *url
    ) {
    return story_area_type_link_create_internal (
        type,
        url
        );
}

void story_area_type_link_free(story_area_type_link_t *story_area_type_link) {
    if(NULL == story_area_type_link){
        return ;
    }
    if(story_area_type_link->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "story_area_type_link_free");
        return ;
    }
    listEntry_t *listEntry;
    if (story_area_type_link->type) {
        free(story_area_type_link->type);
        story_area_type_link->type = NULL;
    }
    if (story_area_type_link->url) {
        free(story_area_type_link->url);
        story_area_type_link->url = NULL;
    }
    free(story_area_type_link);
}

cJSON *story_area_type_link_convertToJSON(story_area_type_link_t *story_area_type_link) {
    cJSON *item = cJSON_CreateObject();

    // story_area_type_link->type
    if (!story_area_type_link->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", story_area_type_link->type) == NULL) {
    goto fail; //String
    }


    // story_area_type_link->url
    if (!story_area_type_link->url) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "url", story_area_type_link->url) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

story_area_type_link_t *story_area_type_link_parseFromJSON(cJSON *story_area_type_linkJSON){

    story_area_type_link_t *story_area_type_link_local_var = NULL;

    // story_area_type_link->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(story_area_type_linkJSON, "type");
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

    // story_area_type_link->url
    cJSON *url = cJSON_GetObjectItemCaseSensitive(story_area_type_linkJSON, "url");
    if (cJSON_IsNull(url)) {
        url = NULL;
    }
    if (!url) {
        goto end;
    }

    
    if(!cJSON_IsString(url))
    {
    goto end; //String
    }


    story_area_type_link_local_var = story_area_type_link_create_internal (
        strdup(type->valuestring),
        strdup(url->valuestring)
        );

    return story_area_type_link_local_var;
end:
    return NULL;

}
