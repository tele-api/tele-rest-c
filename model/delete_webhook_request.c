#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "delete_webhook_request.h"



static delete_webhook_request_t *delete_webhook_request_create_internal(
    int drop_pending_updates
    ) {
    delete_webhook_request_t *delete_webhook_request_local_var = malloc(sizeof(delete_webhook_request_t));
    if (!delete_webhook_request_local_var) {
        return NULL;
    }
    delete_webhook_request_local_var->drop_pending_updates = drop_pending_updates;

    delete_webhook_request_local_var->_library_owned = 1;
    return delete_webhook_request_local_var;
}

__attribute__((deprecated)) delete_webhook_request_t *delete_webhook_request_create(
    int drop_pending_updates
    ) {
    return delete_webhook_request_create_internal (
        drop_pending_updates
        );
}

void delete_webhook_request_free(delete_webhook_request_t *delete_webhook_request) {
    if(NULL == delete_webhook_request){
        return ;
    }
    if(delete_webhook_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "delete_webhook_request_free");
        return ;
    }
    listEntry_t *listEntry;
    free(delete_webhook_request);
}

cJSON *delete_webhook_request_convertToJSON(delete_webhook_request_t *delete_webhook_request) {
    cJSON *item = cJSON_CreateObject();

    // delete_webhook_request->drop_pending_updates
    if(delete_webhook_request->drop_pending_updates) {
    if(cJSON_AddBoolToObject(item, "drop_pending_updates", delete_webhook_request->drop_pending_updates) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

delete_webhook_request_t *delete_webhook_request_parseFromJSON(cJSON *delete_webhook_requestJSON){

    delete_webhook_request_t *delete_webhook_request_local_var = NULL;

    // delete_webhook_request->drop_pending_updates
    cJSON *drop_pending_updates = cJSON_GetObjectItemCaseSensitive(delete_webhook_requestJSON, "drop_pending_updates");
    if (cJSON_IsNull(drop_pending_updates)) {
        drop_pending_updates = NULL;
    }
    if (drop_pending_updates) { 
    if(!cJSON_IsBool(drop_pending_updates))
    {
    goto end; //Bool
    }
    }


    delete_webhook_request_local_var = delete_webhook_request_create_internal (
        drop_pending_updates ? drop_pending_updates->valueint : 0
        );

    return delete_webhook_request_local_var;
end:
    return NULL;

}
