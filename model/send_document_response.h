/*
 * send_document_response.h
 *
 * 
 */

#ifndef _send_document_response_H_
#define _send_document_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct send_document_response_t send_document_response_t;

#include "message.h"



typedef struct send_document_response_t {
    int ok; //boolean
    struct message_t *result; //model

    int _library_owned; // Is the library responsible for freeing this object?
} send_document_response_t;

__attribute__((deprecated)) send_document_response_t *send_document_response_create(
    int ok,
    message_t *result
);

void send_document_response_free(send_document_response_t *send_document_response);

send_document_response_t *send_document_response_parseFromJSON(cJSON *send_document_responseJSON);

cJSON *send_document_response_convertToJSON(send_document_response_t *send_document_response);

#endif /* _send_document_response_H_ */

