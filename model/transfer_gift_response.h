/*
 * transfer_gift_response.h
 *
 * 
 */

#ifndef _transfer_gift_response_H_
#define _transfer_gift_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct transfer_gift_response_t transfer_gift_response_t;




typedef struct transfer_gift_response_t {
    int ok; //boolean
    int result; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} transfer_gift_response_t;

__attribute__((deprecated)) transfer_gift_response_t *transfer_gift_response_create(
    int ok,
    int result
);

void transfer_gift_response_free(transfer_gift_response_t *transfer_gift_response);

transfer_gift_response_t *transfer_gift_response_parseFromJSON(cJSON *transfer_gift_responseJSON);

cJSON *transfer_gift_response_convertToJSON(transfer_gift_response_t *transfer_gift_response);

#endif /* _transfer_gift_response_H_ */

