#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_delete_webhook_request.h"



static post_delete_webhook_request_t *post_delete_webhook_request_create_internal(
    int drop_pending_updates
    ) {
    post_delete_webhook_request_t *post_delete_webhook_request_local_var = malloc(sizeof(post_delete_webhook_request_t));
    if (!post_delete_webhook_request_local_var) {
        return NULL;
    }
    post_delete_webhook_request_local_var->drop_pending_updates = drop_pending_updates;

    post_delete_webhook_request_local_var->_library_owned = 1;
    return post_delete_webhook_request_local_var;
}

__attribute__((deprecated)) post_delete_webhook_request_t *post_delete_webhook_request_create(
    int drop_pending_updates
    ) {
    return post_delete_webhook_request_create_internal (
        drop_pending_updates
        );
}

void post_delete_webhook_request_free(post_delete_webhook_request_t *post_delete_webhook_request) {
    if(NULL == post_delete_webhook_request){
        return ;
    }
    if(post_delete_webhook_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_delete_webhook_request_free");
        return ;
    }
    listEntry_t *listEntry;
    free(post_delete_webhook_request);
}

cJSON *post_delete_webhook_request_convertToJSON(post_delete_webhook_request_t *post_delete_webhook_request) {
    cJSON *item = cJSON_CreateObject();

    // post_delete_webhook_request->drop_pending_updates
    if(post_delete_webhook_request->drop_pending_updates) {
    if(cJSON_AddBoolToObject(item, "drop_pending_updates", post_delete_webhook_request->drop_pending_updates) == NULL) {
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

post_delete_webhook_request_t *post_delete_webhook_request_parseFromJSON(cJSON *post_delete_webhook_requestJSON){

    post_delete_webhook_request_t *post_delete_webhook_request_local_var = NULL;

    // post_delete_webhook_request->drop_pending_updates
    cJSON *drop_pending_updates = cJSON_GetObjectItemCaseSensitive(post_delete_webhook_requestJSON, "drop_pending_updates");
    if (cJSON_IsNull(drop_pending_updates)) {
        drop_pending_updates = NULL;
    }
    if (drop_pending_updates) { 
    if(!cJSON_IsBool(drop_pending_updates))
    {
    goto end; //Bool
    }
    }


    post_delete_webhook_request_local_var = post_delete_webhook_request_create_internal (
        drop_pending_updates ? drop_pending_updates->valueint : 0
        );

    return post_delete_webhook_request_local_var;
end:
    return NULL;

}
