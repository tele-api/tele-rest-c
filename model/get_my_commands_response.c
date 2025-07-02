#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "get_my_commands_response.h"



static get_my_commands_response_t *get_my_commands_response_create_internal(
    int ok,
    list_t *result
    ) {
    get_my_commands_response_t *get_my_commands_response_local_var = malloc(sizeof(get_my_commands_response_t));
    if (!get_my_commands_response_local_var) {
        return NULL;
    }
    get_my_commands_response_local_var->ok = ok;
    get_my_commands_response_local_var->result = result;

    get_my_commands_response_local_var->_library_owned = 1;
    return get_my_commands_response_local_var;
}

__attribute__((deprecated)) get_my_commands_response_t *get_my_commands_response_create(
    int ok,
    list_t *result
    ) {
    return get_my_commands_response_create_internal (
        ok,
        result
        );
}

void get_my_commands_response_free(get_my_commands_response_t *get_my_commands_response) {
    if(NULL == get_my_commands_response){
        return ;
    }
    if(get_my_commands_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "get_my_commands_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (get_my_commands_response->result) {
        list_ForEach(listEntry, get_my_commands_response->result) {
            bot_command_free(listEntry->data);
        }
        list_freeList(get_my_commands_response->result);
        get_my_commands_response->result = NULL;
    }
    free(get_my_commands_response);
}

cJSON *get_my_commands_response_convertToJSON(get_my_commands_response_t *get_my_commands_response) {
    cJSON *item = cJSON_CreateObject();

    // get_my_commands_response->ok
    if (!get_my_commands_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", get_my_commands_response->ok) == NULL) {
    goto fail; //Bool
    }


    // get_my_commands_response->result
    if (!get_my_commands_response->result) {
        goto fail;
    }
    cJSON *result = cJSON_AddArrayToObject(item, "result");
    if(result == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *resultListEntry;
    if (get_my_commands_response->result) {
    list_ForEach(resultListEntry, get_my_commands_response->result) {
    cJSON *itemLocal = bot_command_convertToJSON(resultListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(result, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

get_my_commands_response_t *get_my_commands_response_parseFromJSON(cJSON *get_my_commands_responseJSON){

    get_my_commands_response_t *get_my_commands_response_local_var = NULL;

    // define the local list for get_my_commands_response->result
    list_t *resultList = NULL;

    // get_my_commands_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(get_my_commands_responseJSON, "ok");
    if (cJSON_IsNull(ok)) {
        ok = NULL;
    }
    if (!ok) {
        goto end;
    }

    
    if(!cJSON_IsBool(ok))
    {
    goto end; //Bool
    }

    // get_my_commands_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(get_my_commands_responseJSON, "result");
    if (cJSON_IsNull(result)) {
        result = NULL;
    }
    if (!result) {
        goto end;
    }

    
    cJSON *result_local_nonprimitive = NULL;
    if(!cJSON_IsArray(result)){
        goto end; //nonprimitive container
    }

    resultList = list_createList();

    cJSON_ArrayForEach(result_local_nonprimitive,result )
    {
        if(!cJSON_IsObject(result_local_nonprimitive)){
            goto end;
        }
        bot_command_t *resultItem = bot_command_parseFromJSON(result_local_nonprimitive);

        list_addElement(resultList, resultItem);
    }


    get_my_commands_response_local_var = get_my_commands_response_create_internal (
        ok->valueint,
        resultList
        );

    return get_my_commands_response_local_var;
end:
    if (resultList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, resultList) {
            bot_command_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(resultList);
        resultList = NULL;
    }
    return NULL;

}
