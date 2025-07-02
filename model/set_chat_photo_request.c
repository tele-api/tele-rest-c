#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "set_chat_photo_request.h"



static set_chat_photo_request_t *set_chat_photo_request_create_internal(
    send_message_request_chat_id_t *chat_id,
    any_type_t *photo
    ) {
    set_chat_photo_request_t *set_chat_photo_request_local_var = malloc(sizeof(set_chat_photo_request_t));
    if (!set_chat_photo_request_local_var) {
        return NULL;
    }
    set_chat_photo_request_local_var->chat_id = chat_id;
    set_chat_photo_request_local_var->photo = photo;

    set_chat_photo_request_local_var->_library_owned = 1;
    return set_chat_photo_request_local_var;
}

__attribute__((deprecated)) set_chat_photo_request_t *set_chat_photo_request_create(
    send_message_request_chat_id_t *chat_id,
    any_type_t *photo
    ) {
    return set_chat_photo_request_create_internal (
        chat_id,
        photo
        );
}

void set_chat_photo_request_free(set_chat_photo_request_t *set_chat_photo_request) {
    if(NULL == set_chat_photo_request){
        return ;
    }
    if(set_chat_photo_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "set_chat_photo_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (set_chat_photo_request->chat_id) {
        send_message_request_chat_id_free(set_chat_photo_request->chat_id);
        set_chat_photo_request->chat_id = NULL;
    }
    if (set_chat_photo_request->photo) {
        _free(set_chat_photo_request->photo);
        set_chat_photo_request->photo = NULL;
    }
    free(set_chat_photo_request);
}

cJSON *set_chat_photo_request_convertToJSON(set_chat_photo_request_t *set_chat_photo_request) {
    cJSON *item = cJSON_CreateObject();

    // set_chat_photo_request->chat_id
    if (!set_chat_photo_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = send_message_request_chat_id_convertToJSON(set_chat_photo_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // set_chat_photo_request->photo
    if (!set_chat_photo_request->photo) {
        goto fail;
    }
    cJSON *photo_local_JSON = _convertToJSON(set_chat_photo_request->photo);
    if(photo_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "photo", photo_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

set_chat_photo_request_t *set_chat_photo_request_parseFromJSON(cJSON *set_chat_photo_requestJSON){

    set_chat_photo_request_t *set_chat_photo_request_local_var = NULL;

    // define the local variable for set_chat_photo_request->chat_id
    send_message_request_chat_id_t *chat_id_local_nonprim = NULL;

    // define the local variable for set_chat_photo_request->photo
    _t *photo_local_nonprim = NULL;

    // set_chat_photo_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(set_chat_photo_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = send_message_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // set_chat_photo_request->photo
    cJSON *photo = cJSON_GetObjectItemCaseSensitive(set_chat_photo_requestJSON, "photo");
    if (cJSON_IsNull(photo)) {
        photo = NULL;
    }
    if (!photo) {
        goto end;
    }

    
    photo_local_nonprim = _parseFromJSON(photo); //custom


    set_chat_photo_request_local_var = set_chat_photo_request_create_internal (
        chat_id_local_nonprim,
        photo_local_nonprim
        );

    return set_chat_photo_request_local_var;
end:
    if (chat_id_local_nonprim) {
        send_message_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    if (photo_local_nonprim) {
        _free(photo_local_nonprim);
        photo_local_nonprim = NULL;
    }
    return NULL;

}
