/*
 * _set_chat_sticker_set_post_request.h
 *
 * 
 */

#ifndef __set_chat_sticker_set_post_request_H_
#define __set_chat_sticker_set_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _set_chat_sticker_set_post_request_t _set_chat_sticker_set_post_request_t;

#include "_restrict_chat_member_post_request_chat_id.h"



typedef struct _set_chat_sticker_set_post_request_t {
    struct _restrict_chat_member_post_request_chat_id_t *chat_id; //model
    char *sticker_set_name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} _set_chat_sticker_set_post_request_t;

__attribute__((deprecated)) _set_chat_sticker_set_post_request_t *_set_chat_sticker_set_post_request_create(
    _restrict_chat_member_post_request_chat_id_t *chat_id,
    char *sticker_set_name
);

void _set_chat_sticker_set_post_request_free(_set_chat_sticker_set_post_request_t *_set_chat_sticker_set_post_request);

_set_chat_sticker_set_post_request_t *_set_chat_sticker_set_post_request_parseFromJSON(cJSON *_set_chat_sticker_set_post_requestJSON);

cJSON *_set_chat_sticker_set_post_request_convertToJSON(_set_chat_sticker_set_post_request_t *_set_chat_sticker_set_post_request);

#endif /* __set_chat_sticker_set_post_request_H_ */

