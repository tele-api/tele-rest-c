/*
 * post_export_chat_invite_link_200_response.h
 *
 * 
 */

#ifndef _post_export_chat_invite_link_200_response_H_
#define _post_export_chat_invite_link_200_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_export_chat_invite_link_200_response_t post_export_chat_invite_link_200_response_t;




typedef struct post_export_chat_invite_link_200_response_t {
    int ok; //boolean
    char *result; // string

    int _library_owned; // Is the library responsible for freeing this object?
} post_export_chat_invite_link_200_response_t;

__attribute__((deprecated)) post_export_chat_invite_link_200_response_t *post_export_chat_invite_link_200_response_create(
    int ok,
    char *result
);

void post_export_chat_invite_link_200_response_free(post_export_chat_invite_link_200_response_t *post_export_chat_invite_link_200_response);

post_export_chat_invite_link_200_response_t *post_export_chat_invite_link_200_response_parseFromJSON(cJSON *post_export_chat_invite_link_200_responseJSON);

cJSON *post_export_chat_invite_link_200_response_convertToJSON(post_export_chat_invite_link_200_response_t *post_export_chat_invite_link_200_response);

#endif /* _post_export_chat_invite_link_200_response_H_ */

