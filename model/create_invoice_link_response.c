#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "create_invoice_link_response.h"



static create_invoice_link_response_t *create_invoice_link_response_create_internal(
    int ok,
    char *result
    ) {
    create_invoice_link_response_t *create_invoice_link_response_local_var = malloc(sizeof(create_invoice_link_response_t));
    if (!create_invoice_link_response_local_var) {
        return NULL;
    }
    create_invoice_link_response_local_var->ok = ok;
    create_invoice_link_response_local_var->result = result;

    create_invoice_link_response_local_var->_library_owned = 1;
    return create_invoice_link_response_local_var;
}

__attribute__((deprecated)) create_invoice_link_response_t *create_invoice_link_response_create(
    int ok,
    char *result
    ) {
    return create_invoice_link_response_create_internal (
        ok,
        result
        );
}

void create_invoice_link_response_free(create_invoice_link_response_t *create_invoice_link_response) {
    if(NULL == create_invoice_link_response){
        return ;
    }
    if(create_invoice_link_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "create_invoice_link_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (create_invoice_link_response->result) {
        free(create_invoice_link_response->result);
        create_invoice_link_response->result = NULL;
    }
    free(create_invoice_link_response);
}

cJSON *create_invoice_link_response_convertToJSON(create_invoice_link_response_t *create_invoice_link_response) {
    cJSON *item = cJSON_CreateObject();

    // create_invoice_link_response->ok
    if (!create_invoice_link_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", create_invoice_link_response->ok) == NULL) {
    goto fail; //Bool
    }


    // create_invoice_link_response->result
    if (!create_invoice_link_response->result) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "result", create_invoice_link_response->result) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

create_invoice_link_response_t *create_invoice_link_response_parseFromJSON(cJSON *create_invoice_link_responseJSON){

    create_invoice_link_response_t *create_invoice_link_response_local_var = NULL;

    // create_invoice_link_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(create_invoice_link_responseJSON, "ok");
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

    // create_invoice_link_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(create_invoice_link_responseJSON, "result");
    if (cJSON_IsNull(result)) {
        result = NULL;
    }
    if (!result) {
        goto end;
    }

    
    if(!cJSON_IsString(result))
    {
    goto end; //String
    }


    create_invoice_link_response_local_var = create_invoice_link_response_create_internal (
        ok->valueint,
        strdup(result->valuestring)
        );

    return create_invoice_link_response_local_var;
end:
    return NULL;

}
