#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "story.h"



static story_t *story_create_internal(
    chat_t *chat,
    int id
    ) {
    story_t *story_local_var = malloc(sizeof(story_t));
    if (!story_local_var) {
        return NULL;
    }
    story_local_var->chat = chat;
    story_local_var->id = id;

    story_local_var->_library_owned = 1;
    return story_local_var;
}

__attribute__((deprecated)) story_t *story_create(
    chat_t *chat,
    int id
    ) {
    return story_create_internal (
        chat,
        id
        );
}

void story_free(story_t *story) {
    if(NULL == story){
        return ;
    }
    if(story->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "story_free");
        return ;
    }
    listEntry_t *listEntry;
    if (story->chat) {
        chat_free(story->chat);
        story->chat = NULL;
    }
    free(story);
}

cJSON *story_convertToJSON(story_t *story) {
    cJSON *item = cJSON_CreateObject();

    // story->chat
    if (!story->chat) {
        goto fail;
    }
    cJSON *chat_local_JSON = chat_convertToJSON(story->chat);
    if(chat_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat", chat_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // story->id
    if (!story->id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "id", story->id) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

story_t *story_parseFromJSON(cJSON *storyJSON){

    story_t *story_local_var = NULL;

    // define the local variable for story->chat
    chat_t *chat_local_nonprim = NULL;

    // story->chat
    cJSON *chat = cJSON_GetObjectItemCaseSensitive(storyJSON, "chat");
    if (cJSON_IsNull(chat)) {
        chat = NULL;
    }
    if (!chat) {
        goto end;
    }

    
    chat_local_nonprim = chat_parseFromJSON(chat); //nonprimitive

    // story->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(storyJSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (!id) {
        goto end;
    }

    
    if(!cJSON_IsNumber(id))
    {
    goto end; //Numeric
    }


    story_local_var = story_create_internal (
        chat_local_nonprim,
        id->valuedouble
        );

    return story_local_var;
end:
    if (chat_local_nonprim) {
        chat_free(chat_local_nonprim);
        chat_local_nonprim = NULL;
    }
    return NULL;

}
