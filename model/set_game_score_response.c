#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "set_game_score_response.h"



static set_game_score_response_t *set_game_score_response_create_internal(
    int ok,
    edit_message_text_response_result_t *result
    ) {
    set_game_score_response_t *set_game_score_response_local_var = malloc(sizeof(set_game_score_response_t));
    if (!set_game_score_response_local_var) {
        return NULL;
    }
    set_game_score_response_local_var->ok = ok;
    set_game_score_response_local_var->result = result;

    set_game_score_response_local_var->_library_owned = 1;
    return set_game_score_response_local_var;
}

__attribute__((deprecated)) set_game_score_response_t *set_game_score_response_create(
    int ok,
    edit_message_text_response_result_t *result
    ) {
    return set_game_score_response_create_internal (
        ok,
        result
        );
}

void set_game_score_response_free(set_game_score_response_t *set_game_score_response) {
    if(NULL == set_game_score_response){
        return ;
    }
    if(set_game_score_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "set_game_score_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (set_game_score_response->result) {
        edit_message_text_response_result_free(set_game_score_response->result);
        set_game_score_response->result = NULL;
    }
    free(set_game_score_response);
}

cJSON *set_game_score_response_convertToJSON(set_game_score_response_t *set_game_score_response) {
    cJSON *item = cJSON_CreateObject();

    // set_game_score_response->ok
    if (!set_game_score_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", set_game_score_response->ok) == NULL) {
    goto fail; //Bool
    }


    // set_game_score_response->result
    if (!set_game_score_response->result) {
        goto fail;
    }
    cJSON *result_local_JSON = edit_message_text_response_result_convertToJSON(set_game_score_response->result);
    if(result_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "result", result_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

set_game_score_response_t *set_game_score_response_parseFromJSON(cJSON *set_game_score_responseJSON){

    set_game_score_response_t *set_game_score_response_local_var = NULL;

    // define the local variable for set_game_score_response->result
    edit_message_text_response_result_t *result_local_nonprim = NULL;

    // set_game_score_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(set_game_score_responseJSON, "ok");
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

    // set_game_score_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(set_game_score_responseJSON, "result");
    if (cJSON_IsNull(result)) {
        result = NULL;
    }
    if (!result) {
        goto end;
    }

    
    result_local_nonprim = edit_message_text_response_result_parseFromJSON(result); //nonprimitive


    set_game_score_response_local_var = set_game_score_response_create_internal (
        ok->valueint,
        result_local_nonprim
        );

    return set_game_score_response_local_var;
end:
    if (result_local_nonprim) {
        edit_message_text_response_result_free(result_local_nonprim);
        result_local_nonprim = NULL;
    }
    return NULL;

}
