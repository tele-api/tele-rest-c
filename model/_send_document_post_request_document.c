#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_send_document_post_request_document.h"



static _send_document_post_request_document_t *_send_document_post_request_document_create_internal(
    ) {
    _send_document_post_request_document_t *_send_document_post_request_document_local_var = malloc(sizeof(_send_document_post_request_document_t));
    if (!_send_document_post_request_document_local_var) {
        return NULL;
    }

    _send_document_post_request_document_local_var->_library_owned = 1;
    return _send_document_post_request_document_local_var;
}

__attribute__((deprecated)) _send_document_post_request_document_t *_send_document_post_request_document_create(
    ) {
    return _send_document_post_request_document_create_internal (
        );
}

void _send_document_post_request_document_free(_send_document_post_request_document_t *_send_document_post_request_document) {
    if(NULL == _send_document_post_request_document){
        return ;
    }
    if(_send_document_post_request_document->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_send_document_post_request_document_free");
        return ;
    }
    listEntry_t *listEntry;
    free(_send_document_post_request_document);
}

cJSON *_send_document_post_request_document_convertToJSON(_send_document_post_request_document_t *_send_document_post_request_document) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

_send_document_post_request_document_t *_send_document_post_request_document_parseFromJSON(cJSON *_send_document_post_request_documentJSON){

    _send_document_post_request_document_t *_send_document_post_request_document_local_var = NULL;


    _send_document_post_request_document_local_var = _send_document_post_request_document_create_internal (
        );

    return _send_document_post_request_document_local_var;
end:
    return NULL;

}
