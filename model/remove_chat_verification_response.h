/*
 * remove_chat_verification_response.h
 *
 * 
 */

#ifndef _remove_chat_verification_response_H_
#define _remove_chat_verification_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct remove_chat_verification_response_t remove_chat_verification_response_t;




typedef struct remove_chat_verification_response_t {
    int ok; //boolean
    int result; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} remove_chat_verification_response_t;

__attribute__((deprecated)) remove_chat_verification_response_t *remove_chat_verification_response_create(
    int ok,
    int result
);

void remove_chat_verification_response_free(remove_chat_verification_response_t *remove_chat_verification_response);

remove_chat_verification_response_t *remove_chat_verification_response_parseFromJSON(cJSON *remove_chat_verification_responseJSON);

cJSON *remove_chat_verification_response_convertToJSON(remove_chat_verification_response_t *remove_chat_verification_response);

#endif /* _remove_chat_verification_response_H_ */

