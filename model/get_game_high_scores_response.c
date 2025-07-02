#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "get_game_high_scores_response.h"



static get_game_high_scores_response_t *get_game_high_scores_response_create_internal(
    int ok,
    list_t *result
    ) {
    get_game_high_scores_response_t *get_game_high_scores_response_local_var = malloc(sizeof(get_game_high_scores_response_t));
    if (!get_game_high_scores_response_local_var) {
        return NULL;
    }
    get_game_high_scores_response_local_var->ok = ok;
    get_game_high_scores_response_local_var->result = result;

    get_game_high_scores_response_local_var->_library_owned = 1;
    return get_game_high_scores_response_local_var;
}

__attribute__((deprecated)) get_game_high_scores_response_t *get_game_high_scores_response_create(
    int ok,
    list_t *result
    ) {
    return get_game_high_scores_response_create_internal (
        ok,
        result
        );
}

void get_game_high_scores_response_free(get_game_high_scores_response_t *get_game_high_scores_response) {
    if(NULL == get_game_high_scores_response){
        return ;
    }
    if(get_game_high_scores_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "get_game_high_scores_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (get_game_high_scores_response->result) {
        list_ForEach(listEntry, get_game_high_scores_response->result) {
            game_high_score_free(listEntry->data);
        }
        list_freeList(get_game_high_scores_response->result);
        get_game_high_scores_response->result = NULL;
    }
    free(get_game_high_scores_response);
}

cJSON *get_game_high_scores_response_convertToJSON(get_game_high_scores_response_t *get_game_high_scores_response) {
    cJSON *item = cJSON_CreateObject();

    // get_game_high_scores_response->ok
    if (!get_game_high_scores_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", get_game_high_scores_response->ok) == NULL) {
    goto fail; //Bool
    }


    // get_game_high_scores_response->result
    if (!get_game_high_scores_response->result) {
        goto fail;
    }
    cJSON *result = cJSON_AddArrayToObject(item, "result");
    if(result == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *resultListEntry;
    if (get_game_high_scores_response->result) {
    list_ForEach(resultListEntry, get_game_high_scores_response->result) {
    cJSON *itemLocal = game_high_score_convertToJSON(resultListEntry->data);
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

get_game_high_scores_response_t *get_game_high_scores_response_parseFromJSON(cJSON *get_game_high_scores_responseJSON){

    get_game_high_scores_response_t *get_game_high_scores_response_local_var = NULL;

    // define the local list for get_game_high_scores_response->result
    list_t *resultList = NULL;

    // get_game_high_scores_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(get_game_high_scores_responseJSON, "ok");
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

    // get_game_high_scores_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(get_game_high_scores_responseJSON, "result");
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
        game_high_score_t *resultItem = game_high_score_parseFromJSON(result_local_nonprimitive);

        list_addElement(resultList, resultItem);
    }


    get_game_high_scores_response_local_var = get_game_high_scores_response_create_internal (
        ok->valueint,
        resultList
        );

    return get_game_high_scores_response_local_var;
end:
    if (resultList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, resultList) {
            game_high_score_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(resultList);
        resultList = NULL;
    }
    return NULL;

}
