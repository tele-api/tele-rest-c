#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "response_parameters.h"



static response_parameters_t *response_parameters_create_internal(
    int migrate_to_chat_id,
    int retry_after
    ) {
    response_parameters_t *response_parameters_local_var = malloc(sizeof(response_parameters_t));
    if (!response_parameters_local_var) {
        return NULL;
    }
    response_parameters_local_var->migrate_to_chat_id = migrate_to_chat_id;
    response_parameters_local_var->retry_after = retry_after;

    response_parameters_local_var->_library_owned = 1;
    return response_parameters_local_var;
}

__attribute__((deprecated)) response_parameters_t *response_parameters_create(
    int migrate_to_chat_id,
    int retry_after
    ) {
    return response_parameters_create_internal (
        migrate_to_chat_id,
        retry_after
        );
}

void response_parameters_free(response_parameters_t *response_parameters) {
    if(NULL == response_parameters){
        return ;
    }
    if(response_parameters->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "response_parameters_free");
        return ;
    }
    listEntry_t *listEntry;
    free(response_parameters);
}

cJSON *response_parameters_convertToJSON(response_parameters_t *response_parameters) {
    cJSON *item = cJSON_CreateObject();

    // response_parameters->migrate_to_chat_id
    if(response_parameters->migrate_to_chat_id) {
    if(cJSON_AddNumberToObject(item, "migrate_to_chat_id", response_parameters->migrate_to_chat_id) == NULL) {
    goto fail; //Numeric
    }
    }


    // response_parameters->retry_after
    if(response_parameters->retry_after) {
    if(cJSON_AddNumberToObject(item, "retry_after", response_parameters->retry_after) == NULL) {
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

response_parameters_t *response_parameters_parseFromJSON(cJSON *response_parametersJSON){

    response_parameters_t *response_parameters_local_var = NULL;

    // response_parameters->migrate_to_chat_id
    cJSON *migrate_to_chat_id = cJSON_GetObjectItemCaseSensitive(response_parametersJSON, "migrate_to_chat_id");
    if (cJSON_IsNull(migrate_to_chat_id)) {
        migrate_to_chat_id = NULL;
    }
    if (migrate_to_chat_id) { 
    if(!cJSON_IsNumber(migrate_to_chat_id))
    {
    goto end; //Numeric
    }
    }

    // response_parameters->retry_after
    cJSON *retry_after = cJSON_GetObjectItemCaseSensitive(response_parametersJSON, "retry_after");
    if (cJSON_IsNull(retry_after)) {
        retry_after = NULL;
    }
    if (retry_after) { 
    if(!cJSON_IsNumber(retry_after))
    {
    goto end; //Numeric
    }
    }


    response_parameters_local_var = response_parameters_create_internal (
        migrate_to_chat_id ? migrate_to_chat_id->valuedouble : 0,
        retry_after ? retry_after->valuedouble : 0
        );

    return response_parameters_local_var;
end:
    return NULL;

}
