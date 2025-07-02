/*
 * send_photo_response.h
 *
 * 
 */

#ifndef _send_photo_response_H_
#define _send_photo_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct send_photo_response_t send_photo_response_t;

#include "message.h"



typedef struct send_photo_response_t {
    int ok; //boolean
    struct message_t *result; //model

    int _library_owned; // Is the library responsible for freeing this object?
} send_photo_response_t;

__attribute__((deprecated)) send_photo_response_t *send_photo_response_create(
    int ok,
    message_t *result
);

void send_photo_response_free(send_photo_response_t *send_photo_response);

send_photo_response_t *send_photo_response_parseFromJSON(cJSON *send_photo_responseJSON);

cJSON *send_photo_response_convertToJSON(send_photo_response_t *send_photo_response);

#endif /* _send_photo_response_H_ */

