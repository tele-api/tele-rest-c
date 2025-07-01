#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "message_auto_delete_timer_changed.h"



static message_auto_delete_timer_changed_t *message_auto_delete_timer_changed_create_internal(
    int message_auto_delete_time
    ) {
    message_auto_delete_timer_changed_t *message_auto_delete_timer_changed_local_var = malloc(sizeof(message_auto_delete_timer_changed_t));
    if (!message_auto_delete_timer_changed_local_var) {
        return NULL;
    }
    message_auto_delete_timer_changed_local_var->message_auto_delete_time = message_auto_delete_time;

    message_auto_delete_timer_changed_local_var->_library_owned = 1;
    return message_auto_delete_timer_changed_local_var;
}

__attribute__((deprecated)) message_auto_delete_timer_changed_t *message_auto_delete_timer_changed_create(
    int message_auto_delete_time
    ) {
    return message_auto_delete_timer_changed_create_internal (
        message_auto_delete_time
        );
}

void message_auto_delete_timer_changed_free(message_auto_delete_timer_changed_t *message_auto_delete_timer_changed) {
    if(NULL == message_auto_delete_timer_changed){
        return ;
    }
    if(message_auto_delete_timer_changed->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "message_auto_delete_timer_changed_free");
        return ;
    }
    listEntry_t *listEntry;
    free(message_auto_delete_timer_changed);
}

cJSON *message_auto_delete_timer_changed_convertToJSON(message_auto_delete_timer_changed_t *message_auto_delete_timer_changed) {
    cJSON *item = cJSON_CreateObject();

    // message_auto_delete_timer_changed->message_auto_delete_time
    if (!message_auto_delete_timer_changed->message_auto_delete_time) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "message_auto_delete_time", message_auto_delete_timer_changed->message_auto_delete_time) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

message_auto_delete_timer_changed_t *message_auto_delete_timer_changed_parseFromJSON(cJSON *message_auto_delete_timer_changedJSON){

    message_auto_delete_timer_changed_t *message_auto_delete_timer_changed_local_var = NULL;

    // message_auto_delete_timer_changed->message_auto_delete_time
    cJSON *message_auto_delete_time = cJSON_GetObjectItemCaseSensitive(message_auto_delete_timer_changedJSON, "message_auto_delete_time");
    if (cJSON_IsNull(message_auto_delete_time)) {
        message_auto_delete_time = NULL;
    }
    if (!message_auto_delete_time) {
        goto end;
    }

    
    if(!cJSON_IsNumber(message_auto_delete_time))
    {
    goto end; //Numeric
    }


    message_auto_delete_timer_changed_local_var = message_auto_delete_timer_changed_create_internal (
        message_auto_delete_time->valuedouble
        );

    return message_auto_delete_timer_changed_local_var;
end:
    return NULL;

}
