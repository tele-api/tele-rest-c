/*
 * post_send_document_request_document.h
 *
 * File to send. Pass a file\\_id as String to send a file that exists on the Telegram servers (recommended), pass an HTTP URL as a String for Telegram to get a file from the Internet, or upload a new one using multipart/form-data. [More information on Sending Files »](https://core.telegram.org/bots/api/#sending-files)
 */

#ifndef _post_send_document_request_document_H_
#define _post_send_document_request_document_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_send_document_request_document_t post_send_document_request_document_t;




typedef struct post_send_document_request_document_t {

    int _library_owned; // Is the library responsible for freeing this object?
} post_send_document_request_document_t;

__attribute__((deprecated)) post_send_document_request_document_t *post_send_document_request_document_create(
);

void post_send_document_request_document_free(post_send_document_request_document_t *post_send_document_request_document);

post_send_document_request_document_t *post_send_document_request_document_parseFromJSON(cJSON *post_send_document_request_documentJSON);

cJSON *post_send_document_request_document_convertToJSON(post_send_document_request_document_t *post_send_document_request_document);

#endif /* _post_send_document_request_document_H_ */

