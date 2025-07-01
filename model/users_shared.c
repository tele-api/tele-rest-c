#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "users_shared.h"



static users_shared_t *users_shared_create_internal(
    int request_id,
    list_t *users
    ) {
    users_shared_t *users_shared_local_var = malloc(sizeof(users_shared_t));
    if (!users_shared_local_var) {
        return NULL;
    }
    users_shared_local_var->request_id = request_id;
    users_shared_local_var->users = users;

    users_shared_local_var->_library_owned = 1;
    return users_shared_local_var;
}

__attribute__((deprecated)) users_shared_t *users_shared_create(
    int request_id,
    list_t *users
    ) {
    return users_shared_create_internal (
        request_id,
        users
        );
}

void users_shared_free(users_shared_t *users_shared) {
    if(NULL == users_shared){
        return ;
    }
    if(users_shared->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "users_shared_free");
        return ;
    }
    listEntry_t *listEntry;
    if (users_shared->users) {
        list_ForEach(listEntry, users_shared->users) {
            shared_user_free(listEntry->data);
        }
        list_freeList(users_shared->users);
        users_shared->users = NULL;
    }
    free(users_shared);
}

cJSON *users_shared_convertToJSON(users_shared_t *users_shared) {
    cJSON *item = cJSON_CreateObject();

    // users_shared->request_id
    if (!users_shared->request_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "request_id", users_shared->request_id) == NULL) {
    goto fail; //Numeric
    }


    // users_shared->users
    if (!users_shared->users) {
        goto fail;
    }
    cJSON *users = cJSON_AddArrayToObject(item, "users");
    if(users == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *usersListEntry;
    if (users_shared->users) {
    list_ForEach(usersListEntry, users_shared->users) {
    cJSON *itemLocal = shared_user_convertToJSON(usersListEntry->data);
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

users_shared_t *users_shared_parseFromJSON(cJSON *users_sharedJSON){

    users_shared_t *users_shared_local_var = NULL;

    // define the local list for users_shared->users
    list_t *usersList = NULL;

    // users_shared->request_id
    cJSON *request_id = cJSON_GetObjectItemCaseSensitive(users_sharedJSON, "request_id");
    if (cJSON_IsNull(request_id)) {
        request_id = NULL;
    }
    if (!request_id) {
        goto end;
    }

    
    if(!cJSON_IsNumber(request_id))
    {
    goto end; //Numeric
    }

    // users_shared->users
    cJSON *users = cJSON_GetObjectItemCaseSensitive(users_sharedJSON, "users");
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
        shared_user_t *usersItem = shared_user_parseFromJSON(users_local_nonprimitive);

        list_addElement(usersList, usersItem);
    }


    users_shared_local_var = users_shared_create_internal (
        request_id->valuedouble,
        usersList
        );

    return users_shared_local_var;
end:
    if (usersList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, usersList) {
            shared_user_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(usersList);
        usersList = NULL;
    }
    return NULL;

}
