#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "message_id.h"



static message_id_t *message_id_create_internal(
    int message_id
    ) {
    message_id_t *message_id_local_var = malloc(sizeof(message_id_t));
    if (!message_id_local_var) {
        return NULL;
    }
    message_id_local_var->message_id = message_id;

    message_id_local_var->_library_owned = 1;
    return message_id_local_var;
}

__attribute__((deprecated)) message_id_t *message_id_create(
    int message_id
    ) {
    return message_id_create_internal (
        message_id
        );
}

void message_id_free(message_id_t *message_id) {
    if(NULL == message_id){
        return ;
    }
    if(message_id->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "message_id_free");
        return ;
    }
    listEntry_t *listEntry;
    free(message_id);
}

cJSON *message_id_convertToJSON(message_id_t *message_id) {
    cJSON *item = cJSON_CreateObject();

    // message_id->message_id
    if (!message_id->message_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "message_id", message_id->message_id) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

message_id_t *message_id_parseFromJSON(cJSON *message_idJSON){

    message_id_t *message_id_local_var = NULL;

    // message_id->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(message_idJSON, "message_id");
    if (cJSON_IsNull(message_id)) {
        message_id = NULL;
    }
    if (!message_id) {
        goto end;
    }

    
    if(!cJSON_IsNumber(message_id))
    {
    goto end; //Numeric
    }


    message_id_local_var = message_id_create_internal (
        message_id->valuedouble
        );

    return message_id_local_var;
end:
    return NULL;

}
