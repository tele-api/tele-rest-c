/*
 * post_set_user_emoji_status_request.h
 *
 * 
 */

#ifndef _post_set_user_emoji_status_request_H_
#define _post_set_user_emoji_status_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_set_user_emoji_status_request_t post_set_user_emoji_status_request_t;




typedef struct post_set_user_emoji_status_request_t {
    int user_id; //numeric
    char *emoji_status_custom_emoji_id; // string
    int emoji_status_expiration_date; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} post_set_user_emoji_status_request_t;

__attribute__((deprecated)) post_set_user_emoji_status_request_t *post_set_user_emoji_status_request_create(
    int user_id,
    char *emoji_status_custom_emoji_id,
    int emoji_status_expiration_date
);

void post_set_user_emoji_status_request_free(post_set_user_emoji_status_request_t *post_set_user_emoji_status_request);

post_set_user_emoji_status_request_t *post_set_user_emoji_status_request_parseFromJSON(cJSON *post_set_user_emoji_status_requestJSON);

cJSON *post_set_user_emoji_status_request_convertToJSON(post_set_user_emoji_status_request_t *post_set_user_emoji_status_request);

#endif /* _post_set_user_emoji_status_request_H_ */

