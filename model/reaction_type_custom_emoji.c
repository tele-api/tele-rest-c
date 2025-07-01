#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "reaction_type_custom_emoji.h"



static reaction_type_custom_emoji_t *reaction_type_custom_emoji_create_internal(
    char *type,
    char *custom_emoji_id
    ) {
    reaction_type_custom_emoji_t *reaction_type_custom_emoji_local_var = malloc(sizeof(reaction_type_custom_emoji_t));
    if (!reaction_type_custom_emoji_local_var) {
        return NULL;
    }
    reaction_type_custom_emoji_local_var->type = type;
    reaction_type_custom_emoji_local_var->custom_emoji_id = custom_emoji_id;

    reaction_type_custom_emoji_local_var->_library_owned = 1;
    return reaction_type_custom_emoji_local_var;
}

__attribute__((deprecated)) reaction_type_custom_emoji_t *reaction_type_custom_emoji_create(
    char *type,
    char *custom_emoji_id
    ) {
    return reaction_type_custom_emoji_create_internal (
        type,
        custom_emoji_id
        );
}

void reaction_type_custom_emoji_free(reaction_type_custom_emoji_t *reaction_type_custom_emoji) {
    if(NULL == reaction_type_custom_emoji){
        return ;
    }
    if(reaction_type_custom_emoji->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "reaction_type_custom_emoji_free");
        return ;
    }
    listEntry_t *listEntry;
    if (reaction_type_custom_emoji->type) {
        free(reaction_type_custom_emoji->type);
        reaction_type_custom_emoji->type = NULL;
    }
    if (reaction_type_custom_emoji->custom_emoji_id) {
        free(reaction_type_custom_emoji->custom_emoji_id);
        reaction_type_custom_emoji->custom_emoji_id = NULL;
    }
    free(reaction_type_custom_emoji);
}

cJSON *reaction_type_custom_emoji_convertToJSON(reaction_type_custom_emoji_t *reaction_type_custom_emoji) {
    cJSON *item = cJSON_CreateObject();

    // reaction_type_custom_emoji->type
    if (!reaction_type_custom_emoji->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", reaction_type_custom_emoji->type) == NULL) {
    goto fail; //String
    }


    // reaction_type_custom_emoji->custom_emoji_id
    if (!reaction_type_custom_emoji->custom_emoji_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "custom_emoji_id", reaction_type_custom_emoji->custom_emoji_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

reaction_type_custom_emoji_t *reaction_type_custom_emoji_parseFromJSON(cJSON *reaction_type_custom_emojiJSON){

    reaction_type_custom_emoji_t *reaction_type_custom_emoji_local_var = NULL;

    // reaction_type_custom_emoji->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(reaction_type_custom_emojiJSON, "type");
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

    // reaction_type_custom_emoji->custom_emoji_id
    cJSON *custom_emoji_id = cJSON_GetObjectItemCaseSensitive(reaction_type_custom_emojiJSON, "custom_emoji_id");
    if (cJSON_IsNull(custom_emoji_id)) {
        custom_emoji_id = NULL;
    }
    if (!custom_emoji_id) {
        goto end;
    }

    
    if(!cJSON_IsString(custom_emoji_id))
    {
    goto end; //String
    }


    reaction_type_custom_emoji_local_var = reaction_type_custom_emoji_create_internal (
        strdup(type->valuestring),
        strdup(custom_emoji_id->valuestring)
        );

    return reaction_type_custom_emoji_local_var;
end:
    return NULL;

}
