/*
 * delete_sticker_from_set_request.h
 *
 * Request parameters for deleteStickerFromSet
 */

#ifndef _delete_sticker_from_set_request_H_
#define _delete_sticker_from_set_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct delete_sticker_from_set_request_t delete_sticker_from_set_request_t;




typedef struct delete_sticker_from_set_request_t {
    char *sticker; // string

    int _library_owned; // Is the library responsible for freeing this object?
} delete_sticker_from_set_request_t;

__attribute__((deprecated)) delete_sticker_from_set_request_t *delete_sticker_from_set_request_create(
    char *sticker
);

void delete_sticker_from_set_request_free(delete_sticker_from_set_request_t *delete_sticker_from_set_request);

delete_sticker_from_set_request_t *delete_sticker_from_set_request_parseFromJSON(cJSON *delete_sticker_from_set_requestJSON);

cJSON *delete_sticker_from_set_request_convertToJSON(delete_sticker_from_set_request_t *delete_sticker_from_set_request);

#endif /* _delete_sticker_from_set_request_H_ */

