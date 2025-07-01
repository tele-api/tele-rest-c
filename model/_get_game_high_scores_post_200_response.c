#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_get_game_high_scores_post_200_response.h"



static _get_game_high_scores_post_200_response_t *_get_game_high_scores_post_200_response_create_internal(
    int ok,
    list_t *result
    ) {
    _get_game_high_scores_post_200_response_t *_get_game_high_scores_post_200_response_local_var = malloc(sizeof(_get_game_high_scores_post_200_response_t));
    if (!_get_game_high_scores_post_200_response_local_var) {
        return NULL;
    }
    _get_game_high_scores_post_200_response_local_var->ok = ok;
    _get_game_high_scores_post_200_response_local_var->result = result;

    _get_game_high_scores_post_200_response_local_var->_library_owned = 1;
    return _get_game_high_scores_post_200_response_local_var;
}

__attribute__((deprecated)) _get_game_high_scores_post_200_response_t *_get_game_high_scores_post_200_response_create(
    int ok,
    list_t *result
    ) {
    return _get_game_high_scores_post_200_response_create_internal (
        ok,
        result
        );
}

void _get_game_high_scores_post_200_response_free(_get_game_high_scores_post_200_response_t *_get_game_high_scores_post_200_response) {
    if(NULL == _get_game_high_scores_post_200_response){
        return ;
    }
    if(_get_game_high_scores_post_200_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_get_game_high_scores_post_200_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_get_game_high_scores_post_200_response->result) {
        list_ForEach(listEntry, _get_game_high_scores_post_200_response->result) {
            game_high_score_free(listEntry->data);
        }
        list_freeList(_get_game_high_scores_post_200_response->result);
        _get_game_high_scores_post_200_response->result = NULL;
    }
    free(_get_game_high_scores_post_200_response);
}

cJSON *_get_game_high_scores_post_200_response_convertToJSON(_get_game_high_scores_post_200_response_t *_get_game_high_scores_post_200_response) {
    cJSON *item = cJSON_CreateObject();

    // _get_game_high_scores_post_200_response->ok
    if (!_get_game_high_scores_post_200_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", _get_game_high_scores_post_200_response->ok) == NULL) {
    goto fail; //Bool
    }


    // _get_game_high_scores_post_200_response->result
    if (!_get_game_high_scores_post_200_response->result) {
        goto fail;
    }
    cJSON *result = cJSON_AddArrayToObject(item, "result");
    if(result == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *resultListEntry;
    if (_get_game_high_scores_post_200_response->result) {
    list_ForEach(resultListEntry, _get_game_high_scores_post_200_response->result) {
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

_get_game_high_scores_post_200_response_t *_get_game_high_scores_post_200_response_parseFromJSON(cJSON *_get_game_high_scores_post_200_responseJSON){

    _get_game_high_scores_post_200_response_t *_get_game_high_scores_post_200_response_local_var = NULL;

    // define the local list for _get_game_high_scores_post_200_response->result
    list_t *resultList = NULL;

    // _get_game_high_scores_post_200_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(_get_game_high_scores_post_200_responseJSON, "ok");
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

    // _get_game_high_scores_post_200_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(_get_game_high_scores_post_200_responseJSON, "result");
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


    _get_game_high_scores_post_200_response_local_var = _get_game_high_scores_post_200_response_create_internal (
        ok->valueint,
        resultList
        );

    return _get_game_high_scores_post_200_response_local_var;
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
