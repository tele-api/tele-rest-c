#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_get_star_transactions_request.h"



static post_get_star_transactions_request_t *post_get_star_transactions_request_create_internal(
    int offset,
    int limit
    ) {
    post_get_star_transactions_request_t *post_get_star_transactions_request_local_var = malloc(sizeof(post_get_star_transactions_request_t));
    if (!post_get_star_transactions_request_local_var) {
        return NULL;
    }
    post_get_star_transactions_request_local_var->offset = offset;
    post_get_star_transactions_request_local_var->limit = limit;

    post_get_star_transactions_request_local_var->_library_owned = 1;
    return post_get_star_transactions_request_local_var;
}

__attribute__((deprecated)) post_get_star_transactions_request_t *post_get_star_transactions_request_create(
    int offset,
    int limit
    ) {
    return post_get_star_transactions_request_create_internal (
        offset,
        limit
        );
}

void post_get_star_transactions_request_free(post_get_star_transactions_request_t *post_get_star_transactions_request) {
    if(NULL == post_get_star_transactions_request){
        return ;
    }
    if(post_get_star_transactions_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_get_star_transactions_request_free");
        return ;
    }
    listEntry_t *listEntry;
    free(post_get_star_transactions_request);
}

cJSON *post_get_star_transactions_request_convertToJSON(post_get_star_transactions_request_t *post_get_star_transactions_request) {
    cJSON *item = cJSON_CreateObject();

    // post_get_star_transactions_request->offset
    if(post_get_star_transactions_request->offset) {
    if(cJSON_AddNumberToObject(item, "offset", post_get_star_transactions_request->offset) == NULL) {
    goto fail; //Numeric
    }
    }


    // post_get_star_transactions_request->limit
    if(post_get_star_transactions_request->limit) {
    if(cJSON_AddNumberToObject(item, "limit", post_get_star_transactions_request->limit) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

post_get_star_transactions_request_t *post_get_star_transactions_request_parseFromJSON(cJSON *post_get_star_transactions_requestJSON){

    post_get_star_transactions_request_t *post_get_star_transactions_request_local_var = NULL;

    // post_get_star_transactions_request->offset
    cJSON *offset = cJSON_GetObjectItemCaseSensitive(post_get_star_transactions_requestJSON, "offset");
    if (cJSON_IsNull(offset)) {
        offset = NULL;
    }
    if (offset) { 
    if(!cJSON_IsNumber(offset))
    {
    goto end; //Numeric
    }
    }

    // post_get_star_transactions_request->limit
    cJSON *limit = cJSON_GetObjectItemCaseSensitive(post_get_star_transactions_requestJSON, "limit");
    if (cJSON_IsNull(limit)) {
        limit = NULL;
    }
    if (limit) { 
    if(!cJSON_IsNumber(limit))
    {
    goto end; //Numeric
    }
    }


    post_get_star_transactions_request_local_var = post_get_star_transactions_request_create_internal (
        offset ? offset->valuedouble : 0,
        limit ? limit->valuedouble : 0
        );

    return post_get_star_transactions_request_local_var;
end:
    return NULL;

}
