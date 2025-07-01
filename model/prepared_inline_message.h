/*
 * prepared_inline_message.h
 *
 * Describes an inline message to be sent by a user of a Mini App.
 */

#ifndef _prepared_inline_message_H_
#define _prepared_inline_message_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct prepared_inline_message_t prepared_inline_message_t;




typedef struct prepared_inline_message_t {
    char *id; // string
    int expiration_date; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} prepared_inline_message_t;

__attribute__((deprecated)) prepared_inline_message_t *prepared_inline_message_create(
    char *id,
    int expiration_date
);

void prepared_inline_message_free(prepared_inline_message_t *prepared_inline_message);

prepared_inline_message_t *prepared_inline_message_parseFromJSON(cJSON *prepared_inline_messageJSON);

cJSON *prepared_inline_message_convertToJSON(prepared_inline_message_t *prepared_inline_message);

#endif /* _prepared_inline_message_H_ */

