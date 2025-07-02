/*
 * send_dice_response.h
 *
 * 
 */

#ifndef _send_dice_response_H_
#define _send_dice_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct send_dice_response_t send_dice_response_t;

#include "message.h"



typedef struct send_dice_response_t {
    int ok; //boolean
    struct message_t *result; //model

    int _library_owned; // Is the library responsible for freeing this object?
} send_dice_response_t;

__attribute__((deprecated)) send_dice_response_t *send_dice_response_create(
    int ok,
    message_t *result
);

void send_dice_response_free(send_dice_response_t *send_dice_response);

send_dice_response_t *send_dice_response_parseFromJSON(cJSON *send_dice_responseJSON);

cJSON *send_dice_response_convertToJSON(send_dice_response_t *send_dice_response);

#endif /* _send_dice_response_H_ */

