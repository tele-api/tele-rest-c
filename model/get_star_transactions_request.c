#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "get_star_transactions_request.h"



static get_star_transactions_request_t *get_star_transactions_request_create_internal(
    int offset,
    int limit
    ) {
    get_star_transactions_request_t *get_star_transactions_request_local_var = malloc(sizeof(get_star_transactions_request_t));
    if (!get_star_transactions_request_local_var) {
        return NULL;
    }
    get_star_transactions_request_local_var->offset = offset;
    get_star_transactions_request_local_var->limit = limit;

    get_star_transactions_request_local_var->_library_owned = 1;
    return get_star_transactions_request_local_var;
}

__attribute__((deprecated)) get_star_transactions_request_t *get_star_transactions_request_create(
    int offset,
    int limit
    ) {
    return get_star_transactions_request_create_internal (
        offset,
        limit
        );
}

void get_star_transactions_request_free(get_star_transactions_request_t *get_star_transactions_request) {
    if(NULL == get_star_transactions_request){
        return ;
    }
    if(get_star_transactions_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "get_star_transactions_request_free");
        return ;
    }
    listEntry_t *listEntry;
    free(get_star_transactions_request);
}

cJSON *get_star_transactions_request_convertToJSON(get_star_transactions_request_t *get_star_transactions_request) {
    cJSON *item = cJSON_CreateObject();

    // get_star_transactions_request->offset
    if(get_star_transactions_request->offset) {
    if(cJSON_AddNumberToObject(item, "offset", get_star_transactions_request->offset) == NULL) {
    goto fail; //Numeric
    }
    }


    // get_star_transactions_request->limit
    if(get_star_transactions_request->limit) {
    if(cJSON_AddNumberToObject(item, "limit", get_star_transactions_request->limit) == NULL) {
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

get_star_transactions_request_t *get_star_transactions_request_parseFromJSON(cJSON *get_star_transactions_requestJSON){

    get_star_transactions_request_t *get_star_transactions_request_local_var = NULL;

    // get_star_transactions_request->offset
    cJSON *offset = cJSON_GetObjectItemCaseSensitive(get_star_transactions_requestJSON, "offset");
    if (cJSON_IsNull(offset)) {
        offset = NULL;
    }
    if (offset) { 
    if(!cJSON_IsNumber(offset))
    {
    goto end; //Numeric
    }
    }

    // get_star_transactions_request->limit
    cJSON *limit = cJSON_GetObjectItemCaseSensitive(get_star_transactions_requestJSON, "limit");
    if (cJSON_IsNull(limit)) {
        limit = NULL;
    }
    if (limit) { 
    if(!cJSON_IsNumber(limit))
    {
    goto end; //Numeric
    }
    }


    get_star_transactions_request_local_var = get_star_transactions_request_create_internal (
        offset ? offset->valuedouble : 0,
        limit ? limit->valuedouble : 0
        );

    return get_star_transactions_request_local_var;
end:
    return NULL;

}
