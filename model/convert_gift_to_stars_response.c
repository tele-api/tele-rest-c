#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "convert_gift_to_stars_response.h"



static convert_gift_to_stars_response_t *convert_gift_to_stars_response_create_internal(
    int ok,
    int result
    ) {
    convert_gift_to_stars_response_t *convert_gift_to_stars_response_local_var = malloc(sizeof(convert_gift_to_stars_response_t));
    if (!convert_gift_to_stars_response_local_var) {
        return NULL;
    }
    convert_gift_to_stars_response_local_var->ok = ok;
    convert_gift_to_stars_response_local_var->result = result;

    convert_gift_to_stars_response_local_var->_library_owned = 1;
    return convert_gift_to_stars_response_local_var;
}

__attribute__((deprecated)) convert_gift_to_stars_response_t *convert_gift_to_stars_response_create(
    int ok,
    int result
    ) {
    return convert_gift_to_stars_response_create_internal (
        ok,
        result
        );
}

void convert_gift_to_stars_response_free(convert_gift_to_stars_response_t *convert_gift_to_stars_response) {
    if(NULL == convert_gift_to_stars_response){
        return ;
    }
    if(convert_gift_to_stars_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "convert_gift_to_stars_response_free");
        return ;
    }
    listEntry_t *listEntry;
    free(convert_gift_to_stars_response);
}

cJSON *convert_gift_to_stars_response_convertToJSON(convert_gift_to_stars_response_t *convert_gift_to_stars_response) {
    cJSON *item = cJSON_CreateObject();

    // convert_gift_to_stars_response->ok
    if (!convert_gift_to_stars_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", convert_gift_to_stars_response->ok) == NULL) {
    goto fail; //Bool
    }


    // convert_gift_to_stars_response->result
    if (!convert_gift_to_stars_response->result) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "result", convert_gift_to_stars_response->result) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

convert_gift_to_stars_response_t *convert_gift_to_stars_response_parseFromJSON(cJSON *convert_gift_to_stars_responseJSON){

    convert_gift_to_stars_response_t *convert_gift_to_stars_response_local_var = NULL;

    // convert_gift_to_stars_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(convert_gift_to_stars_responseJSON, "ok");
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

    // convert_gift_to_stars_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(convert_gift_to_stars_responseJSON, "result");
    if (cJSON_IsNull(result)) {
        result = NULL;
    }
    if (!result) {
        goto end;
    }

    
    if(!cJSON_IsBool(result))
    {
    goto end; //Bool
    }


    convert_gift_to_stars_response_local_var = convert_gift_to_stars_response_create_internal (
        ok->valueint,
        result->valueint
        );

    return convert_gift_to_stars_response_local_var;
end:
    return NULL;

}
