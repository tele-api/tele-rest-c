/*
 * accepted_gift_types.h
 *
 * This object describes the types of gifts that can be gifted to a user or a chat.
 */

#ifndef _accepted_gift_types_H_
#define _accepted_gift_types_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct accepted_gift_types_t accepted_gift_types_t;




typedef struct accepted_gift_types_t {
    int unlimited_gifts; //boolean
    int limited_gifts; //boolean
    int unique_gifts; //boolean
    int premium_subscription; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} accepted_gift_types_t;

__attribute__((deprecated)) accepted_gift_types_t *accepted_gift_types_create(
    int unlimited_gifts,
    int limited_gifts,
    int unique_gifts,
    int premium_subscription
);

void accepted_gift_types_free(accepted_gift_types_t *accepted_gift_types);

accepted_gift_types_t *accepted_gift_types_parseFromJSON(cJSON *accepted_gift_typesJSON);

cJSON *accepted_gift_types_convertToJSON(accepted_gift_types_t *accepted_gift_types);

#endif /* _accepted_gift_types_H_ */

