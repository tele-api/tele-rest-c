#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_delete_webhook_post_request.h"



static _delete_webhook_post_request_t *_delete_webhook_post_request_create_internal(
    int drop_pending_updates
    ) {
    _delete_webhook_post_request_t *_delete_webhook_post_request_local_var = malloc(sizeof(_delete_webhook_post_request_t));
    if (!_delete_webhook_post_request_local_var) {
        return NULL;
    }
    _delete_webhook_post_request_local_var->drop_pending_updates = drop_pending_updates;

    _delete_webhook_post_request_local_var->_library_owned = 1;
    return _delete_webhook_post_request_local_var;
}

__attribute__((deprecated)) _delete_webhook_post_request_t *_delete_webhook_post_request_create(
    int drop_pending_updates
    ) {
    return _delete_webhook_post_request_create_internal (
        drop_pending_updates
        );
}

void _delete_webhook_post_request_free(_delete_webhook_post_request_t *_delete_webhook_post_request) {
    if(NULL == _delete_webhook_post_request){
        return ;
    }
    if(_delete_webhook_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_delete_webhook_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    free(_delete_webhook_post_request);
}

cJSON *_delete_webhook_post_request_convertToJSON(_delete_webhook_post_request_t *_delete_webhook_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _delete_webhook_post_request->drop_pending_updates
    if(_delete_webhook_post_request->drop_pending_updates) {
    if(cJSON_AddBoolToObject(item, "drop_pending_updates", _delete_webhook_post_request->drop_pending_updates) == NULL) {
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

_delete_webhook_post_request_t *_delete_webhook_post_request_parseFromJSON(cJSON *_delete_webhook_post_requestJSON){

    _delete_webhook_post_request_t *_delete_webhook_post_request_local_var = NULL;

    // _delete_webhook_post_request->drop_pending_updates
    cJSON *drop_pending_updates = cJSON_GetObjectItemCaseSensitive(_delete_webhook_post_requestJSON, "drop_pending_updates");
    if (cJSON_IsNull(drop_pending_updates)) {
        drop_pending_updates = NULL;
    }
    if (drop_pending_updates) { 
    if(!cJSON_IsBool(drop_pending_updates))
    {
    goto end; //Bool
    }
    }


    _delete_webhook_post_request_local_var = _delete_webhook_post_request_create_internal (
        drop_pending_updates ? drop_pending_updates->valueint : 0
        );

    return _delete_webhook_post_request_local_var;
end:
    return NULL;

}
