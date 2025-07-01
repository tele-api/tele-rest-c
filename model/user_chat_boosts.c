#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "user_chat_boosts.h"



static user_chat_boosts_t *user_chat_boosts_create_internal(
    list_t *boosts
    ) {
    user_chat_boosts_t *user_chat_boosts_local_var = malloc(sizeof(user_chat_boosts_t));
    if (!user_chat_boosts_local_var) {
        return NULL;
    }
    user_chat_boosts_local_var->boosts = boosts;

    user_chat_boosts_local_var->_library_owned = 1;
    return user_chat_boosts_local_var;
}

__attribute__((deprecated)) user_chat_boosts_t *user_chat_boosts_create(
    list_t *boosts
    ) {
    return user_chat_boosts_create_internal (
        boosts
        );
}

void user_chat_boosts_free(user_chat_boosts_t *user_chat_boosts) {
    if(NULL == user_chat_boosts){
        return ;
    }
    if(user_chat_boosts->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "user_chat_boosts_free");
        return ;
    }
    listEntry_t *listEntry;
    if (user_chat_boosts->boosts) {
        list_ForEach(listEntry, user_chat_boosts->boosts) {
            chat_boost_free(listEntry->data);
        }
        list_freeList(user_chat_boosts->boosts);
        user_chat_boosts->boosts = NULL;
    }
    free(user_chat_boosts);
}

cJSON *user_chat_boosts_convertToJSON(user_chat_boosts_t *user_chat_boosts) {
    cJSON *item = cJSON_CreateObject();

    // user_chat_boosts->boosts
    if (!user_chat_boosts->boosts) {
        goto fail;
    }
    cJSON *boosts = cJSON_AddArrayToObject(item, "boosts");
    if(boosts == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *boostsListEntry;
    if (user_chat_boosts->boosts) {
    list_ForEach(boostsListEntry, user_chat_boosts->boosts) {
    cJSON *itemLocal = chat_boost_convertToJSON(boostsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(boosts, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

user_chat_boosts_t *user_chat_boosts_parseFromJSON(cJSON *user_chat_boostsJSON){

    user_chat_boosts_t *user_chat_boosts_local_var = NULL;

    // define the local list for user_chat_boosts->boosts
    list_t *boostsList = NULL;

    // user_chat_boosts->boosts
    cJSON *boosts = cJSON_GetObjectItemCaseSensitive(user_chat_boostsJSON, "boosts");
    if (cJSON_IsNull(boosts)) {
        boosts = NULL;
    }
    if (!boosts) {
        goto end;
    }

    
    cJSON *boosts_local_nonprimitive = NULL;
    if(!cJSON_IsArray(boosts)){
        goto end; //nonprimitive container
    }

    boostsList = list_createList();

    cJSON_ArrayForEach(boosts_local_nonprimitive,boosts )
    {
        if(!cJSON_IsObject(boosts_local_nonprimitive)){
            goto end;
        }
        chat_boost_t *boostsItem = chat_boost_parseFromJSON(boosts_local_nonprimitive);

        list_addElement(boostsList, boostsItem);
    }


    user_chat_boosts_local_var = user_chat_boosts_create_internal (
        boostsList
        );

    return user_chat_boosts_local_var;
end:
    if (boostsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, boostsList) {
            chat_boost_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(boostsList);
        boostsList = NULL;
    }
    return NULL;

}
