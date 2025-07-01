#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "game.h"



static game_t *game_create_internal(
    char *title,
    char *description,
    list_t *photo,
    char *text,
    list_t *text_entities,
    animation_t *animation
    ) {
    game_t *game_local_var = malloc(sizeof(game_t));
    if (!game_local_var) {
        return NULL;
    }
    game_local_var->title = title;
    game_local_var->description = description;
    game_local_var->photo = photo;
    game_local_var->text = text;
    game_local_var->text_entities = text_entities;
    game_local_var->animation = animation;

    game_local_var->_library_owned = 1;
    return game_local_var;
}

__attribute__((deprecated)) game_t *game_create(
    char *title,
    char *description,
    list_t *photo,
    char *text,
    list_t *text_entities,
    animation_t *animation
    ) {
    return game_create_internal (
        title,
        description,
        photo,
        text,
        text_entities,
        animation
        );
}

void game_free(game_t *game) {
    if(NULL == game){
        return ;
    }
    if(game->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "game_free");
        return ;
    }
    listEntry_t *listEntry;
    if (game->title) {
        free(game->title);
        game->title = NULL;
    }
    if (game->description) {
        free(game->description);
        game->description = NULL;
    }
    if (game->photo) {
        list_ForEach(listEntry, game->photo) {
            photo_size_free(listEntry->data);
        }
        list_freeList(game->photo);
        game->photo = NULL;
    }
    if (game->text) {
        free(game->text);
        game->text = NULL;
    }
    if (game->text_entities) {
        list_ForEach(listEntry, game->text_entities) {
            message_entity_free(listEntry->data);
        }
        list_freeList(game->text_entities);
        game->text_entities = NULL;
    }
    if (game->animation) {
        animation_free(game->animation);
        game->animation = NULL;
    }
    free(game);
}

cJSON *game_convertToJSON(game_t *game) {
    cJSON *item = cJSON_CreateObject();

    // game->title
    if (!game->title) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "title", game->title) == NULL) {
    goto fail; //String
    }


    // game->description
    if (!game->description) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "description", game->description) == NULL) {
    goto fail; //String
    }


    // game->photo
    if (!game->photo) {
        goto fail;
    }
    cJSON *photo = cJSON_AddArrayToObject(item, "photo");
    if(photo == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *photoListEntry;
    if (game->photo) {
    list_ForEach(photoListEntry, game->photo) {
    cJSON *itemLocal = photo_size_convertToJSON(photoListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(photo, itemLocal);
    }
    }


    // game->text
    if(game->text) {
    if(cJSON_AddStringToObject(item, "text", game->text) == NULL) {
    goto fail; //String
    }
    }


    // game->text_entities
    if(game->text_entities) {
    cJSON *text_entities = cJSON_AddArrayToObject(item, "text_entities");
    if(text_entities == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *text_entitiesListEntry;
    if (game->text_entities) {
    list_ForEach(text_entitiesListEntry, game->text_entities) {
    cJSON *itemLocal = message_entity_convertToJSON(text_entitiesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(text_entities, itemLocal);
    }
    }
    }


    // game->animation
    if(game->animation) {
    cJSON *animation_local_JSON = animation_convertToJSON(game->animation);
    if(animation_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "animation", animation_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

game_t *game_parseFromJSON(cJSON *gameJSON){

    game_t *game_local_var = NULL;

    // define the local list for game->photo
    list_t *photoList = NULL;

    // define the local list for game->text_entities
    list_t *text_entitiesList = NULL;

    // define the local variable for game->animation
    animation_t *animation_local_nonprim = NULL;

    // game->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(gameJSON, "title");
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

    // game->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(gameJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (!description) {
        goto end;
    }

    
    if(!cJSON_IsString(description))
    {
    goto end; //String
    }

    // game->photo
    cJSON *photo = cJSON_GetObjectItemCaseSensitive(gameJSON, "photo");
    if (cJSON_IsNull(photo)) {
        photo = NULL;
    }
    if (!photo) {
        goto end;
    }

    
    cJSON *photo_local_nonprimitive = NULL;
    if(!cJSON_IsArray(photo)){
        goto end; //nonprimitive container
    }

    photoList = list_createList();

    cJSON_ArrayForEach(photo_local_nonprimitive,photo )
    {
        if(!cJSON_IsObject(photo_local_nonprimitive)){
            goto end;
        }
        photo_size_t *photoItem = photo_size_parseFromJSON(photo_local_nonprimitive);

        list_addElement(photoList, photoItem);
    }

    // game->text
    cJSON *text = cJSON_GetObjectItemCaseSensitive(gameJSON, "text");
    if (cJSON_IsNull(text)) {
        text = NULL;
    }
    if (text) { 
    if(!cJSON_IsString(text) && !cJSON_IsNull(text))
    {
    goto end; //String
    }
    }

    // game->text_entities
    cJSON *text_entities = cJSON_GetObjectItemCaseSensitive(gameJSON, "text_entities");
    if (cJSON_IsNull(text_entities)) {
        text_entities = NULL;
    }
    if (text_entities) { 
    cJSON *text_entities_local_nonprimitive = NULL;
    if(!cJSON_IsArray(text_entities)){
        goto end; //nonprimitive container
    }

    text_entitiesList = list_createList();

    cJSON_ArrayForEach(text_entities_local_nonprimitive,text_entities )
    {
        if(!cJSON_IsObject(text_entities_local_nonprimitive)){
            goto end;
        }
        message_entity_t *text_entitiesItem = message_entity_parseFromJSON(text_entities_local_nonprimitive);

        list_addElement(text_entitiesList, text_entitiesItem);
    }
    }

    // game->animation
    cJSON *animation = cJSON_GetObjectItemCaseSensitive(gameJSON, "animation");
    if (cJSON_IsNull(animation)) {
        animation = NULL;
    }
    if (animation) { 
    animation_local_nonprim = animation_parseFromJSON(animation); //nonprimitive
    }


    game_local_var = game_create_internal (
        strdup(title->valuestring),
        strdup(description->valuestring),
        photoList,
        text && !cJSON_IsNull(text) ? strdup(text->valuestring) : NULL,
        text_entities ? text_entitiesList : NULL,
        animation ? animation_local_nonprim : NULL
        );

    return game_local_var;
end:
    if (photoList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, photoList) {
            photo_size_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(photoList);
        photoList = NULL;
    }
    if (text_entitiesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, text_entitiesList) {
            message_entity_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(text_entitiesList);
        text_entitiesList = NULL;
    }
    if (animation_local_nonprim) {
        animation_free(animation_local_nonprim);
        animation_local_nonprim = NULL;
    }
    return NULL;

}
