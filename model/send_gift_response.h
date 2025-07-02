/*
 * send_gift_response.h
 *
 * 
 */

#ifndef _send_gift_response_H_
#define _send_gift_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct send_gift_response_t send_gift_response_t;




typedef struct send_gift_response_t {
    int ok; //boolean
    int result; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} send_gift_response_t;

__attribute__((deprecated)) send_gift_response_t *send_gift_response_create(
    int ok,
    int result
);

void send_gift_response_free(send_gift_response_t *send_gift_response);

send_gift_response_t *send_gift_response_parseFromJSON(cJSON *send_gift_responseJSON);

cJSON *send_gift_response_convertToJSON(send_gift_response_t *send_gift_response);

#endif /* _send_gift_response_H_ */

