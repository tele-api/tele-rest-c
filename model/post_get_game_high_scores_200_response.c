#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_get_game_high_scores_200_response.h"



static post_get_game_high_scores_200_response_t *post_get_game_high_scores_200_response_create_internal(
    int ok,
    list_t *result
    ) {
    post_get_game_high_scores_200_response_t *post_get_game_high_scores_200_response_local_var = malloc(sizeof(post_get_game_high_scores_200_response_t));
    if (!post_get_game_high_scores_200_response_local_var) {
        return NULL;
    }
    post_get_game_high_scores_200_response_local_var->ok = ok;
    post_get_game_high_scores_200_response_local_var->result = result;

    post_get_game_high_scores_200_response_local_var->_library_owned = 1;
    return post_get_game_high_scores_200_response_local_var;
}

__attribute__((deprecated)) post_get_game_high_scores_200_response_t *post_get_game_high_scores_200_response_create(
    int ok,
    list_t *result
    ) {
    return post_get_game_high_scores_200_response_create_internal (
        ok,
        result
        );
}

void post_get_game_high_scores_200_response_free(post_get_game_high_scores_200_response_t *post_get_game_high_scores_200_response) {
    if(NULL == post_get_game_high_scores_200_response){
        return ;
    }
    if(post_get_game_high_scores_200_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_get_game_high_scores_200_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_get_game_high_scores_200_response->result) {
        list_ForEach(listEntry, post_get_game_high_scores_200_response->result) {
            game_high_score_free(listEntry->data);
        }
        list_freeList(post_get_game_high_scores_200_response->result);
        post_get_game_high_scores_200_response->result = NULL;
    }
    free(post_get_game_high_scores_200_response);
}

cJSON *post_get_game_high_scores_200_response_convertToJSON(post_get_game_high_scores_200_response_t *post_get_game_high_scores_200_response) {
    cJSON *item = cJSON_CreateObject();

    // post_get_game_high_scores_200_response->ok
    if (!post_get_game_high_scores_200_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", post_get_game_high_scores_200_response->ok) == NULL) {
    goto fail; //Bool
    }


    // post_get_game_high_scores_200_response->result
    if (!post_get_game_high_scores_200_response->result) {
        goto fail;
    }
    cJSON *result = cJSON_AddArrayToObject(item, "result");
    if(result == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *resultListEntry;
    if (post_get_game_high_scores_200_response->result) {
    list_ForEach(resultListEntry, post_get_game_high_scores_200_response->result) {
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

post_get_game_high_scores_200_response_t *post_get_game_high_scores_200_response_parseFromJSON(cJSON *post_get_game_high_scores_200_responseJSON){

    post_get_game_high_scores_200_response_t *post_get_game_high_scores_200_response_local_var = NULL;

    // define the local list for post_get_game_high_scores_200_response->result
    list_t *resultList = NULL;

    // post_get_game_high_scores_200_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(post_get_game_high_scores_200_responseJSON, "ok");
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

    // post_get_game_high_scores_200_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(post_get_game_high_scores_200_responseJSON, "result");
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


    post_get_game_high_scores_200_response_local_var = post_get_game_high_scores_200_response_create_internal (
        ok->valueint,
        resultList
        );

    return post_get_game_high_scores_200_response_local_var;
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
