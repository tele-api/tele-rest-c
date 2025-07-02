/*
 * set_sticker_keywords_response.h
 *
 * 
 */

#ifndef _set_sticker_keywords_response_H_
#define _set_sticker_keywords_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct set_sticker_keywords_response_t set_sticker_keywords_response_t;




typedef struct set_sticker_keywords_response_t {
    int ok; //boolean
    int result; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} set_sticker_keywords_response_t;

__attribute__((deprecated)) set_sticker_keywords_response_t *set_sticker_keywords_response_create(
    int ok,
    int result
);

void set_sticker_keywords_response_free(set_sticker_keywords_response_t *set_sticker_keywords_response);

set_sticker_keywords_response_t *set_sticker_keywords_response_parseFromJSON(cJSON *set_sticker_keywords_responseJSON);

cJSON *set_sticker_keywords_response_convertToJSON(set_sticker_keywords_response_t *set_sticker_keywords_response);

#endif /* _set_sticker_keywords_response_H_ */

