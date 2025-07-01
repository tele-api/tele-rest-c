#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "story_area_type_unique_gift.h"



static story_area_type_unique_gift_t *story_area_type_unique_gift_create_internal(
    char *type,
    char *name
    ) {
    story_area_type_unique_gift_t *story_area_type_unique_gift_local_var = malloc(sizeof(story_area_type_unique_gift_t));
    if (!story_area_type_unique_gift_local_var) {
        return NULL;
    }
    story_area_type_unique_gift_local_var->type = type;
    story_area_type_unique_gift_local_var->name = name;

    story_area_type_unique_gift_local_var->_library_owned = 1;
    return story_area_type_unique_gift_local_var;
}

__attribute__((deprecated)) story_area_type_unique_gift_t *story_area_type_unique_gift_create(
    char *type,
    char *name
    ) {
    return story_area_type_unique_gift_create_internal (
        type,
        name
        );
}

void story_area_type_unique_gift_free(story_area_type_unique_gift_t *story_area_type_unique_gift) {
    if(NULL == story_area_type_unique_gift){
        return ;
    }
    if(story_area_type_unique_gift->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "story_area_type_unique_gift_free");
        return ;
    }
    listEntry_t *listEntry;
    if (story_area_type_unique_gift->type) {
        free(story_area_type_unique_gift->type);
        story_area_type_unique_gift->type = NULL;
    }
    if (story_area_type_unique_gift->name) {
        free(story_area_type_unique_gift->name);
        story_area_type_unique_gift->name = NULL;
    }
    free(story_area_type_unique_gift);
}

cJSON *story_area_type_unique_gift_convertToJSON(story_area_type_unique_gift_t *story_area_type_unique_gift) {
    cJSON *item = cJSON_CreateObject();

    // story_area_type_unique_gift->type
    if (!story_area_type_unique_gift->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", story_area_type_unique_gift->type) == NULL) {
    goto fail; //String
    }


    // story_area_type_unique_gift->name
    if (!story_area_type_unique_gift->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", story_area_type_unique_gift->name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

story_area_type_unique_gift_t *story_area_type_unique_gift_parseFromJSON(cJSON *story_area_type_unique_giftJSON){

    story_area_type_unique_gift_t *story_area_type_unique_gift_local_var = NULL;

    // story_area_type_unique_gift->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(story_area_type_unique_giftJSON, "type");
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

    // story_area_type_unique_gift->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(story_area_type_unique_giftJSON, "name");
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


    story_area_type_unique_gift_local_var = story_area_type_unique_gift_create_internal (
        strdup(type->valuestring),
        strdup(name->valuestring)
        );

    return story_area_type_unique_gift_local_var;
end:
    return NULL;

}
