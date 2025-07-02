/*
 * set_user_emoji_status_request.h
 *
 * Request parameters for setUserEmojiStatus
 */

#ifndef _set_user_emoji_status_request_H_
#define _set_user_emoji_status_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct set_user_emoji_status_request_t set_user_emoji_status_request_t;




typedef struct set_user_emoji_status_request_t {
    int user_id; //numeric
    char *emoji_status_custom_emoji_id; // string
    int emoji_status_expiration_date; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} set_user_emoji_status_request_t;

__attribute__((deprecated)) set_user_emoji_status_request_t *set_user_emoji_status_request_create(
    int user_id,
    char *emoji_status_custom_emoji_id,
    int emoji_status_expiration_date
);

void set_user_emoji_status_request_free(set_user_emoji_status_request_t *set_user_emoji_status_request);

set_user_emoji_status_request_t *set_user_emoji_status_request_parseFromJSON(cJSON *set_user_emoji_status_requestJSON);

cJSON *set_user_emoji_status_request_convertToJSON(set_user_emoji_status_request_t *set_user_emoji_status_request);

#endif /* _set_user_emoji_status_request_H_ */

