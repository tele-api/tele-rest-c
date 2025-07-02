/*
 * post_set_chat_administrator_custom_title_request.h
 *
 * 
 */

#ifndef _post_set_chat_administrator_custom_title_request_H_
#define _post_set_chat_administrator_custom_title_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_set_chat_administrator_custom_title_request_t post_set_chat_administrator_custom_title_request_t;

#include "post_restrict_chat_member_request_chat_id.h"



typedef struct post_set_chat_administrator_custom_title_request_t {
    struct post_restrict_chat_member_request_chat_id_t *chat_id; //model
    int user_id; //numeric
    char *custom_title; // string

    int _library_owned; // Is the library responsible for freeing this object?
} post_set_chat_administrator_custom_title_request_t;

__attribute__((deprecated)) post_set_chat_administrator_custom_title_request_t *post_set_chat_administrator_custom_title_request_create(
    post_restrict_chat_member_request_chat_id_t *chat_id,
    int user_id,
    char *custom_title
);

void post_set_chat_administrator_custom_title_request_free(post_set_chat_administrator_custom_title_request_t *post_set_chat_administrator_custom_title_request);

post_set_chat_administrator_custom_title_request_t *post_set_chat_administrator_custom_title_request_parseFromJSON(cJSON *post_set_chat_administrator_custom_title_requestJSON);

cJSON *post_set_chat_administrator_custom_title_request_convertToJSON(post_set_chat_administrator_custom_title_request_t *post_set_chat_administrator_custom_title_request);

#endif /* _post_set_chat_administrator_custom_title_request_H_ */

