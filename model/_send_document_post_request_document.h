/*
 * _send_document_post_request_document.h
 *
 * File to send. Pass a file\\_id as String to send a file that exists on the Telegram servers (recommended), pass an HTTP URL as a String for Telegram to get a file from the Internet, or upload a new one using multipart/form-data. [More information on Sending Files »](https://core.telegram.org/bots/api/#sending-files)
 */

#ifndef __send_document_post_request_document_H_
#define __send_document_post_request_document_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _send_document_post_request_document_t _send_document_post_request_document_t;




typedef struct _send_document_post_request_document_t {

    int _library_owned; // Is the library responsible for freeing this object?
} _send_document_post_request_document_t;

__attribute__((deprecated)) _send_document_post_request_document_t *_send_document_post_request_document_create(
);

void _send_document_post_request_document_free(_send_document_post_request_document_t *_send_document_post_request_document);

_send_document_post_request_document_t *_send_document_post_request_document_parseFromJSON(cJSON *_send_document_post_request_documentJSON);

cJSON *_send_document_post_request_document_convertToJSON(_send_document_post_request_document_t *_send_document_post_request_document);

#endif /* __send_document_post_request_document_H_ */

