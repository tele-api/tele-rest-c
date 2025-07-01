#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "forum_topic_edited.h"



static forum_topic_edited_t *forum_topic_edited_create_internal(
    char *name,
    char *icon_custom_emoji_id
    ) {
    forum_topic_edited_t *forum_topic_edited_local_var = malloc(sizeof(forum_topic_edited_t));
    if (!forum_topic_edited_local_var) {
        return NULL;
    }
    forum_topic_edited_local_var->name = name;
    forum_topic_edited_local_var->icon_custom_emoji_id = icon_custom_emoji_id;

    forum_topic_edited_local_var->_library_owned = 1;
    return forum_topic_edited_local_var;
}

__attribute__((deprecated)) forum_topic_edited_t *forum_topic_edited_create(
    char *name,
    char *icon_custom_emoji_id
    ) {
    return forum_topic_edited_create_internal (
        name,
        icon_custom_emoji_id
        );
}

void forum_topic_edited_free(forum_topic_edited_t *forum_topic_edited) {
    if(NULL == forum_topic_edited){
        return ;
    }
    if(forum_topic_edited->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "forum_topic_edited_free");
        return ;
    }
    listEntry_t *listEntry;
    if (forum_topic_edited->name) {
        free(forum_topic_edited->name);
        forum_topic_edited->name = NULL;
    }
    if (forum_topic_edited->icon_custom_emoji_id) {
        free(forum_topic_edited->icon_custom_emoji_id);
        forum_topic_edited->icon_custom_emoji_id = NULL;
    }
    free(forum_topic_edited);
}

cJSON *forum_topic_edited_convertToJSON(forum_topic_edited_t *forum_topic_edited) {
    cJSON *item = cJSON_CreateObject();

    // forum_topic_edited->name
    if(forum_topic_edited->name) {
    if(cJSON_AddStringToObject(item, "name", forum_topic_edited->name) == NULL) {
    goto fail; //String
    }
    }


    // forum_topic_edited->icon_custom_emoji_id
    if(forum_topic_edited->icon_custom_emoji_id) {
    if(cJSON_AddStringToObject(item, "icon_custom_emoji_id", forum_topic_edited->icon_custom_emoji_id) == NULL) {
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

forum_topic_edited_t *forum_topic_edited_parseFromJSON(cJSON *forum_topic_editedJSON){

    forum_topic_edited_t *forum_topic_edited_local_var = NULL;

    // forum_topic_edited->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(forum_topic_editedJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // forum_topic_edited->icon_custom_emoji_id
    cJSON *icon_custom_emoji_id = cJSON_GetObjectItemCaseSensitive(forum_topic_editedJSON, "icon_custom_emoji_id");
    if (cJSON_IsNull(icon_custom_emoji_id)) {
        icon_custom_emoji_id = NULL;
    }
    if (icon_custom_emoji_id) { 
    if(!cJSON_IsString(icon_custom_emoji_id) && !cJSON_IsNull(icon_custom_emoji_id))
    {
    goto end; //String
    }
    }


    forum_topic_edited_local_var = forum_topic_edited_create_internal (
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        icon_custom_emoji_id && !cJSON_IsNull(icon_custom_emoji_id) ? strdup(icon_custom_emoji_id->valuestring) : NULL
        );

    return forum_topic_edited_local_var;
end:
    return NULL;

}
