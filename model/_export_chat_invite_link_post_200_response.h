/*
 * _export_chat_invite_link_post_200_response.h
 *
 * 
 */

#ifndef __export_chat_invite_link_post_200_response_H_
#define __export_chat_invite_link_post_200_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _export_chat_invite_link_post_200_response_t _export_chat_invite_link_post_200_response_t;




typedef struct _export_chat_invite_link_post_200_response_t {
    int ok; //boolean
    char *result; // string

    int _library_owned; // Is the library responsible for freeing this object?
} _export_chat_invite_link_post_200_response_t;

__attribute__((deprecated)) _export_chat_invite_link_post_200_response_t *_export_chat_invite_link_post_200_response_create(
    int ok,
    char *result
);

void _export_chat_invite_link_post_200_response_free(_export_chat_invite_link_post_200_response_t *_export_chat_invite_link_post_200_response);

_export_chat_invite_link_post_200_response_t *_export_chat_invite_link_post_200_response_parseFromJSON(cJSON *_export_chat_invite_link_post_200_responseJSON);

cJSON *_export_chat_invite_link_post_200_response_convertToJSON(_export_chat_invite_link_post_200_response_t *_export_chat_invite_link_post_200_response);

#endif /* __export_chat_invite_link_post_200_response_H_ */

