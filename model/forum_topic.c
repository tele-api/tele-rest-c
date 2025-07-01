#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "forum_topic.h"



static forum_topic_t *forum_topic_create_internal(
    int message_thread_id,
    char *name,
    int icon_color,
    char *icon_custom_emoji_id
    ) {
    forum_topic_t *forum_topic_local_var = malloc(sizeof(forum_topic_t));
    if (!forum_topic_local_var) {
        return NULL;
    }
    forum_topic_local_var->message_thread_id = message_thread_id;
    forum_topic_local_var->name = name;
    forum_topic_local_var->icon_color = icon_color;
    forum_topic_local_var->icon_custom_emoji_id = icon_custom_emoji_id;

    forum_topic_local_var->_library_owned = 1;
    return forum_topic_local_var;
}

__attribute__((deprecated)) forum_topic_t *forum_topic_create(
    int message_thread_id,
    char *name,
    int icon_color,
    char *icon_custom_emoji_id
    ) {
    return forum_topic_create_internal (
        message_thread_id,
        name,
        icon_color,
        icon_custom_emoji_id
        );
}

void forum_topic_free(forum_topic_t *forum_topic) {
    if(NULL == forum_topic){
        return ;
    }
    if(forum_topic->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "forum_topic_free");
        return ;
    }
    listEntry_t *listEntry;
    if (forum_topic->name) {
        free(forum_topic->name);
        forum_topic->name = NULL;
    }
    if (forum_topic->icon_custom_emoji_id) {
        free(forum_topic->icon_custom_emoji_id);
        forum_topic->icon_custom_emoji_id = NULL;
    }
    free(forum_topic);
}

cJSON *forum_topic_convertToJSON(forum_topic_t *forum_topic) {
    cJSON *item = cJSON_CreateObject();

    // forum_topic->message_thread_id
    if (!forum_topic->message_thread_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "message_thread_id", forum_topic->message_thread_id) == NULL) {
    goto fail; //Numeric
    }


    // forum_topic->name
    if (!forum_topic->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", forum_topic->name) == NULL) {
    goto fail; //String
    }


    // forum_topic->icon_color
    if (!forum_topic->icon_color) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "icon_color", forum_topic->icon_color) == NULL) {
    goto fail; //Numeric
    }


    // forum_topic->icon_custom_emoji_id
    if(forum_topic->icon_custom_emoji_id) {
    if(cJSON_AddStringToObject(item, "icon_custom_emoji_id", forum_topic->icon_custom_emoji_id) == NULL) {
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

forum_topic_t *forum_topic_parseFromJSON(cJSON *forum_topicJSON){

    forum_topic_t *forum_topic_local_var = NULL;

    // forum_topic->message_thread_id
    cJSON *message_thread_id = cJSON_GetObjectItemCaseSensitive(forum_topicJSON, "message_thread_id");
    if (cJSON_IsNull(message_thread_id)) {
        message_thread_id = NULL;
    }
    if (!message_thread_id) {
        goto end;
    }

    
    if(!cJSON_IsNumber(message_thread_id))
    {
    goto end; //Numeric
    }

    // forum_topic->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(forum_topicJSON, "name");
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

    // forum_topic->icon_color
    cJSON *icon_color = cJSON_GetObjectItemCaseSensitive(forum_topicJSON, "icon_color");
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

    // forum_topic->icon_custom_emoji_id
    cJSON *icon_custom_emoji_id = cJSON_GetObjectItemCaseSensitive(forum_topicJSON, "icon_custom_emoji_id");
    if (cJSON_IsNull(icon_custom_emoji_id)) {
        icon_custom_emoji_id = NULL;
    }
    if (icon_custom_emoji_id) { 
    if(!cJSON_IsString(icon_custom_emoji_id) && !cJSON_IsNull(icon_custom_emoji_id))
    {
    goto end; //String
    }
    }


    forum_topic_local_var = forum_topic_create_internal (
        message_thread_id->valuedouble,
        strdup(name->valuestring),
        icon_color->valuedouble,
        icon_custom_emoji_id && !cJSON_IsNull(icon_custom_emoji_id) ? strdup(icon_custom_emoji_id->valuestring) : NULL
        );

    return forum_topic_local_var;
end:
    return NULL;

}
