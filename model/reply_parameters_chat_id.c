#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "reply_parameters_chat_id.h"



static reply_parameters_chat_id_t *reply_parameters_chat_id_create_internal(
    ) {
    reply_parameters_chat_id_t *reply_parameters_chat_id_local_var = malloc(sizeof(reply_parameters_chat_id_t));
    if (!reply_parameters_chat_id_local_var) {
        return NULL;
    }

    reply_parameters_chat_id_local_var->_library_owned = 1;
    return reply_parameters_chat_id_local_var;
}

__attribute__((deprecated)) reply_parameters_chat_id_t *reply_parameters_chat_id_create(
    ) {
    return reply_parameters_chat_id_create_internal (
        );
}

void reply_parameters_chat_id_free(reply_parameters_chat_id_t *reply_parameters_chat_id) {
    if(NULL == reply_parameters_chat_id){
        return ;
    }
    if(reply_parameters_chat_id->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "reply_parameters_chat_id_free");
        return ;
    }
    listEntry_t *listEntry;
    free(reply_parameters_chat_id);
}

cJSON *reply_parameters_chat_id_convertToJSON(reply_parameters_chat_id_t *reply_parameters_chat_id) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

reply_parameters_chat_id_t *reply_parameters_chat_id_parseFromJSON(cJSON *reply_parameters_chat_idJSON){

    reply_parameters_chat_id_t *reply_parameters_chat_id_local_var = NULL;


    reply_parameters_chat_id_local_var = reply_parameters_chat_id_create_internal (
        );

    return reply_parameters_chat_id_local_var;
end:
    return NULL;

}
