/*
 * post_create_chat_invite_link_200_response.h
 *
 * 
 */

#ifndef _post_create_chat_invite_link_200_response_H_
#define _post_create_chat_invite_link_200_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_create_chat_invite_link_200_response_t post_create_chat_invite_link_200_response_t;

#include "chat_invite_link.h"



typedef struct post_create_chat_invite_link_200_response_t {
    int ok; //boolean
    struct chat_invite_link_t *result; //model

    int _library_owned; // Is the library responsible for freeing this object?
} post_create_chat_invite_link_200_response_t;

__attribute__((deprecated)) post_create_chat_invite_link_200_response_t *post_create_chat_invite_link_200_response_create(
    int ok,
    chat_invite_link_t *result
);

void post_create_chat_invite_link_200_response_free(post_create_chat_invite_link_200_response_t *post_create_chat_invite_link_200_response);

post_create_chat_invite_link_200_response_t *post_create_chat_invite_link_200_response_parseFromJSON(cJSON *post_create_chat_invite_link_200_responseJSON);

cJSON *post_create_chat_invite_link_200_response_convertToJSON(post_create_chat_invite_link_200_response_t *post_create_chat_invite_link_200_response);

#endif /* _post_create_chat_invite_link_200_response_H_ */

