/*
 * _create_chat_invite_link_post_200_response.h
 *
 * 
 */

#ifndef __create_chat_invite_link_post_200_response_H_
#define __create_chat_invite_link_post_200_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _create_chat_invite_link_post_200_response_t _create_chat_invite_link_post_200_response_t;

#include "chat_invite_link.h"



typedef struct _create_chat_invite_link_post_200_response_t {
    int ok; //boolean
    struct chat_invite_link_t *result; //model

    int _library_owned; // Is the library responsible for freeing this object?
} _create_chat_invite_link_post_200_response_t;

__attribute__((deprecated)) _create_chat_invite_link_post_200_response_t *_create_chat_invite_link_post_200_response_create(
    int ok,
    chat_invite_link_t *result
);

void _create_chat_invite_link_post_200_response_free(_create_chat_invite_link_post_200_response_t *_create_chat_invite_link_post_200_response);

_create_chat_invite_link_post_200_response_t *_create_chat_invite_link_post_200_response_parseFromJSON(cJSON *_create_chat_invite_link_post_200_responseJSON);

cJSON *_create_chat_invite_link_post_200_response_convertToJSON(_create_chat_invite_link_post_200_response_t *_create_chat_invite_link_post_200_response);

#endif /* __create_chat_invite_link_post_200_response_H_ */

