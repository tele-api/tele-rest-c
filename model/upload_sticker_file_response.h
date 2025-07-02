/*
 * upload_sticker_file_response.h
 *
 * 
 */

#ifndef _upload_sticker_file_response_H_
#define _upload_sticker_file_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct upload_sticker_file_response_t upload_sticker_file_response_t;

#include "file.h"



typedef struct upload_sticker_file_response_t {
    int ok; //boolean
    struct binary_t*_t *result; //model

    int _library_owned; // Is the library responsible for freeing this object?
} upload_sticker_file_response_t;

__attribute__((deprecated)) upload_sticker_file_response_t *upload_sticker_file_response_create(
    int ok,
    binary_t*_t *result
);

void upload_sticker_file_response_free(upload_sticker_file_response_t *upload_sticker_file_response);

upload_sticker_file_response_t *upload_sticker_file_response_parseFromJSON(cJSON *upload_sticker_file_responseJSON);

cJSON *upload_sticker_file_response_convertToJSON(upload_sticker_file_response_t *upload_sticker_file_response);

#endif /* _upload_sticker_file_response_H_ */

