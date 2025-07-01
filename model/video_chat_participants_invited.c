#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "video_chat_participants_invited.h"



static video_chat_participants_invited_t *video_chat_participants_invited_create_internal(
    list_t *users
    ) {
    video_chat_participants_invited_t *video_chat_participants_invited_local_var = malloc(sizeof(video_chat_participants_invited_t));
    if (!video_chat_participants_invited_local_var) {
        return NULL;
    }
    video_chat_participants_invited_local_var->users = users;

    video_chat_participants_invited_local_var->_library_owned = 1;
    return video_chat_participants_invited_local_var;
}

__attribute__((deprecated)) video_chat_participants_invited_t *video_chat_participants_invited_create(
    list_t *users
    ) {
    return video_chat_participants_invited_create_internal (
        users
        );
}

void video_chat_participants_invited_free(video_chat_participants_invited_t *video_chat_participants_invited) {
    if(NULL == video_chat_participants_invited){
        return ;
    }
    if(video_chat_participants_invited->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "video_chat_participants_invited_free");
        return ;
    }
    listEntry_t *listEntry;
    if (video_chat_participants_invited->users) {
        list_ForEach(listEntry, video_chat_participants_invited->users) {
            user_free(listEntry->data);
        }
        list_freeList(video_chat_participants_invited->users);
        video_chat_participants_invited->users = NULL;
    }
    free(video_chat_participants_invited);
}

cJSON *video_chat_participants_invited_convertToJSON(video_chat_participants_invited_t *video_chat_participants_invited) {
    cJSON *item = cJSON_CreateObject();

    // video_chat_participants_invited->users
    if (!video_chat_participants_invited->users) {
        goto fail;
    }
    cJSON *users = cJSON_AddArrayToObject(item, "users");
    if(users == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *usersListEntry;
    if (video_chat_participants_invited->users) {
    list_ForEach(usersListEntry, video_chat_participants_invited->users) {
    cJSON *itemLocal = user_convertToJSON(usersListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(users, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

video_chat_participants_invited_t *video_chat_participants_invited_parseFromJSON(cJSON *video_chat_participants_invitedJSON){

    video_chat_participants_invited_t *video_chat_participants_invited_local_var = NULL;

    // define the local list for video_chat_participants_invited->users
    list_t *usersList = NULL;

    // video_chat_participants_invited->users
    cJSON *users = cJSON_GetObjectItemCaseSensitive(video_chat_participants_invitedJSON, "users");
    if (cJSON_IsNull(users)) {
        users = NULL;
    }
    if (!users) {
        goto end;
    }

    
    cJSON *users_local_nonprimitive = NULL;
    if(!cJSON_IsArray(users)){
        goto end; //nonprimitive container
    }

    usersList = list_createList();

    cJSON_ArrayForEach(users_local_nonprimitive,users )
    {
        if(!cJSON_IsObject(users_local_nonprimitive)){
            goto end;
        }
        user_t *usersItem = user_parseFromJSON(users_local_nonprimitive);

        list_addElement(usersList, usersItem);
    }


    video_chat_participants_invited_local_var = video_chat_participants_invited_create_internal (
        usersList
        );

    return video_chat_participants_invited_local_var;
end:
    if (usersList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, usersList) {
            user_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(usersList);
        usersList = NULL;
    }
    return NULL;

}
