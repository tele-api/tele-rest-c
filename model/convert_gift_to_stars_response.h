/*
 * convert_gift_to_stars_response.h
 *
 * 
 */

#ifndef _convert_gift_to_stars_response_H_
#define _convert_gift_to_stars_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct convert_gift_to_stars_response_t convert_gift_to_stars_response_t;




typedef struct convert_gift_to_stars_response_t {
    int ok; //boolean
    int result; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} convert_gift_to_stars_response_t;

__attribute__((deprecated)) convert_gift_to_stars_response_t *convert_gift_to_stars_response_create(
    int ok,
    int result
);

void convert_gift_to_stars_response_free(convert_gift_to_stars_response_t *convert_gift_to_stars_response);

convert_gift_to_stars_response_t *convert_gift_to_stars_response_parseFromJSON(cJSON *convert_gift_to_stars_responseJSON);

cJSON *convert_gift_to_stars_response_convertToJSON(convert_gift_to_stars_response_t *convert_gift_to_stars_response);

#endif /* _convert_gift_to_stars_response_H_ */

