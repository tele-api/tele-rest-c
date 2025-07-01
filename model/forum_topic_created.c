#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "forum_topic_created.h"



static forum_topic_created_t *forum_topic_created_create_internal(
    char *name,
    int icon_color,
    char *icon_custom_emoji_id
    ) {
    forum_topic_created_t *forum_topic_created_local_var = malloc(sizeof(forum_topic_created_t));
    if (!forum_topic_created_local_var) {
        return NULL;
    }
    forum_topic_created_local_var->name = name;
    forum_topic_created_local_var->icon_color = icon_color;
    forum_topic_created_local_var->icon_custom_emoji_id = icon_custom_emoji_id;

    forum_topic_created_local_var->_library_owned = 1;
    return forum_topic_created_local_var;
}

__attribute__((deprecated)) forum_topic_created_t *forum_topic_created_create(
    char *name,
    int icon_color,
    char *icon_custom_emoji_id
    ) {
    return forum_topic_created_create_internal (
        name,
        icon_color,
        icon_custom_emoji_id
        );
}

void forum_topic_created_free(forum_topic_created_t *forum_topic_created) {
    if(NULL == forum_topic_created){
        return ;
    }
    if(forum_topic_created->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "forum_topic_created_free");
        return ;
    }
    listEntry_t *listEntry;
    if (forum_topic_created->name) {
        free(forum_topic_created->name);
        forum_topic_created->name = NULL;
    }
    if (forum_topic_created->icon_custom_emoji_id) {
        free(forum_topic_created->icon_custom_emoji_id);
        forum_topic_created->icon_custom_emoji_id = NULL;
    }
    free(forum_topic_created);
}

cJSON *forum_topic_created_convertToJSON(forum_topic_created_t *forum_topic_created) {
    cJSON *item = cJSON_CreateObject();

    // forum_topic_created->name
    if (!forum_topic_created->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", forum_topic_created->name) == NULL) {
    goto fail; //String
    }


    // forum_topic_created->icon_color
    if (!forum_topic_created->icon_color) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "icon_color", forum_topic_created->icon_color) == NULL) {
    goto fail; //Numeric
    }


    // forum_topic_created->icon_custom_emoji_id
    if(forum_topic_created->icon_custom_emoji_id) {
    if(cJSON_AddStringToObject(item, "icon_custom_emoji_id", forum_topic_created->icon_custom_emoji_id) == NULL) {
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

forum_topic_created_t *forum_topic_created_parseFromJSON(cJSON *forum_topic_createdJSON){

    forum_topic_created_t *forum_topic_created_local_var = NULL;

    // forum_topic_created->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(forum_topic_createdJSON, "name");
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

    // forum_topic_created->icon_color
    cJSON *icon_color = cJSON_GetObjectItemCaseSensitive(forum_topic_createdJSON, "icon_color");
    if (cJSON_IsNull(icon_color)) {
        icon_color = NULL;
    }
    if (!icon_color) {
        goto end;
    }

    
    if(!cJSON_IsNumber(icon_color))
    {
    goto end; //Numeric
    }

    // forum_topic_created->icon_custom_emoji_id
    cJSON *icon_custom_emoji_id = cJSON_GetObjectItemCaseSensitive(forum_topic_createdJSON, "icon_custom_emoji_id");
    if (cJSON_IsNull(icon_custom_emoji_id)) {
        icon_custom_emoji_id = NULL;
    }
    if (icon_custom_emoji_id) { 
    if(!cJSON_IsString(icon_custom_emoji_id) && !cJSON_IsNull(icon_custom_emoji_id))
    {
    goto end; //String
    }
    }


    forum_topic_created_local_var = forum_topic_created_create_internal (
        strdup(name->valuestring),
        icon_color->valuedouble,
        icon_custom_emoji_id && !cJSON_IsNull(icon_custom_emoji_id) ? strdup(icon_custom_emoji_id->valuestring) : NULL
        );

    return forum_topic_created_local_var;
end:
    return NULL;

}
