/*
 * export_chat_invite_link_response.h
 *
 * 
 */

#ifndef _export_chat_invite_link_response_H_
#define _export_chat_invite_link_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct export_chat_invite_link_response_t export_chat_invite_link_response_t;




typedef struct export_chat_invite_link_response_t {
    int ok; //boolean
    char *result; // string

    int _library_owned; // Is the library responsible for freeing this object?
} export_chat_invite_link_response_t;

__attribute__((deprecated)) export_chat_invite_link_response_t *export_chat_invite_link_response_create(
    int ok,
    char *result
);

void export_chat_invite_link_response_free(export_chat_invite_link_response_t *export_chat_invite_link_response);

export_chat_invite_link_response_t *export_chat_invite_link_response_parseFromJSON(cJSON *export_chat_invite_link_responseJSON);

cJSON *export_chat_invite_link_response_convertToJSON(export_chat_invite_link_response_t *export_chat_invite_link_response);

#endif /* _export_chat_invite_link_response_H_ */

