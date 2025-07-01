#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "story_area_type_suggested_reaction.h"



static story_area_type_suggested_reaction_t *story_area_type_suggested_reaction_create_internal(
    char *type,
    reaction_type_t *reaction_type,
    int is_dark,
    int is_flipped
    ) {
    story_area_type_suggested_reaction_t *story_area_type_suggested_reaction_local_var = malloc(sizeof(story_area_type_suggested_reaction_t));
    if (!story_area_type_suggested_reaction_local_var) {
        return NULL;
    }
    story_area_type_suggested_reaction_local_var->type = type;
    story_area_type_suggested_reaction_local_var->reaction_type = reaction_type;
    story_area_type_suggested_reaction_local_var->is_dark = is_dark;
    story_area_type_suggested_reaction_local_var->is_flipped = is_flipped;

    story_area_type_suggested_reaction_local_var->_library_owned = 1;
    return story_area_type_suggested_reaction_local_var;
}

__attribute__((deprecated)) story_area_type_suggested_reaction_t *story_area_type_suggested_reaction_create(
    char *type,
    reaction_type_t *reaction_type,
    int is_dark,
    int is_flipped
    ) {
    return story_area_type_suggested_reaction_create_internal (
        type,
        reaction_type,
        is_dark,
        is_flipped
        );
}

void story_area_type_suggested_reaction_free(story_area_type_suggested_reaction_t *story_area_type_suggested_reaction) {
    if(NULL == story_area_type_suggested_reaction){
        return ;
    }
    if(story_area_type_suggested_reaction->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "story_area_type_suggested_reaction_free");
        return ;
    }
    listEntry_t *listEntry;
    if (story_area_type_suggested_reaction->type) {
        free(story_area_type_suggested_reaction->type);
        story_area_type_suggested_reaction->type = NULL;
    }
    if (story_area_type_suggested_reaction->reaction_type) {
        reaction_type_free(story_area_type_suggested_reaction->reaction_type);
        story_area_type_suggested_reaction->reaction_type = NULL;
    }
    free(story_area_type_suggested_reaction);
}

cJSON *story_area_type_suggested_reaction_convertToJSON(story_area_type_suggested_reaction_t *story_area_type_suggested_reaction) {
    cJSON *item = cJSON_CreateObject();

    // story_area_type_suggested_reaction->type
    if (!story_area_type_suggested_reaction->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", story_area_type_suggested_reaction->type) == NULL) {
    goto fail; //String
    }


    // story_area_type_suggested_reaction->reaction_type
    if (!story_area_type_suggested_reaction->reaction_type) {
        goto fail;
    }
    cJSON *reaction_type_local_JSON = reaction_type_convertToJSON(story_area_type_suggested_reaction->reaction_type);
    if(reaction_type_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "reaction_type", reaction_type_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // story_area_type_suggested_reaction->is_dark
    if(story_area_type_suggested_reaction->is_dark) {
    if(cJSON_AddBoolToObject(item, "is_dark", story_area_type_suggested_reaction->is_dark) == NULL) {
    goto fail; //Bool
    }
    }


    // story_area_type_suggested_reaction->is_flipped
    if(story_area_type_suggested_reaction->is_flipped) {
    if(cJSON_AddBoolToObject(item, "is_flipped", story_area_type_suggested_reaction->is_flipped) == NULL) {
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

story_area_type_suggested_reaction_t *story_area_type_suggested_reaction_parseFromJSON(cJSON *story_area_type_suggested_reactionJSON){

    story_area_type_suggested_reaction_t *story_area_type_suggested_reaction_local_var = NULL;

    // define the local variable for story_area_type_suggested_reaction->reaction_type
    reaction_type_t *reaction_type_local_nonprim = NULL;

    // story_area_type_suggested_reaction->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(story_area_type_suggested_reactionJSON, "type");
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

    // story_area_type_suggested_reaction->reaction_type
    cJSON *reaction_type = cJSON_GetObjectItemCaseSensitive(story_area_type_suggested_reactionJSON, "reaction_type");
    if (cJSON_IsNull(reaction_type)) {
        reaction_type = NULL;
    }
    if (!reaction_type) {
        goto end;
    }

    
    reaction_type_local_nonprim = reaction_type_parseFromJSON(reaction_type); //nonprimitive

    // story_area_type_suggested_reaction->is_dark
    cJSON *is_dark = cJSON_GetObjectItemCaseSensitive(story_area_type_suggested_reactionJSON, "is_dark");
    if (cJSON_IsNull(is_dark)) {
        is_dark = NULL;
    }
    if (is_dark) { 
    if(!cJSON_IsBool(is_dark))
    {
    goto end; //Bool
    }
    }

    // story_area_type_suggested_reaction->is_flipped
    cJSON *is_flipped = cJSON_GetObjectItemCaseSensitive(story_area_type_suggested_reactionJSON, "is_flipped");
    if (cJSON_IsNull(is_flipped)) {
        is_flipped = NULL;
    }
    if (is_flipped) { 
    if(!cJSON_IsBool(is_flipped))
    {
    goto end; //Bool
    }
    }


    story_area_type_suggested_reaction_local_var = story_area_type_suggested_reaction_create_internal (
        strdup(type->valuestring),
        reaction_type_local_nonprim,
        is_dark ? is_dark->valueint : 0,
        is_flipped ? is_flipped->valueint : 0
        );

    return story_area_type_suggested_reaction_local_var;
end:
    if (reaction_type_local_nonprim) {
        reaction_type_free(reaction_type_local_nonprim);
        reaction_type_local_nonprim = NULL;
    }
    return NULL;

}
