/*
 * upgrade_gift_response.h
 *
 * 
 */

#ifndef _upgrade_gift_response_H_
#define _upgrade_gift_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct upgrade_gift_response_t upgrade_gift_response_t;




typedef struct upgrade_gift_response_t {
    int ok; //boolean
    int result; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} upgrade_gift_response_t;

__attribute__((deprecated)) upgrade_gift_response_t *upgrade_gift_response_create(
    int ok,
    int result
);

void upgrade_gift_response_free(upgrade_gift_response_t *upgrade_gift_response);

upgrade_gift_response_t *upgrade_gift_response_parseFromJSON(cJSON *upgrade_gift_responseJSON);

cJSON *upgrade_gift_response_convertToJSON(upgrade_gift_response_t *upgrade_gift_response);

#endif /* _upgrade_gift_response_H_ */

