/*
 * get_my_default_administrator_rights_response.h
 *
 * 
 */

#ifndef _get_my_default_administrator_rights_response_H_
#define _get_my_default_administrator_rights_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct get_my_default_administrator_rights_response_t get_my_default_administrator_rights_response_t;

#include "chat_administrator_rights.h"



typedef struct get_my_default_administrator_rights_response_t {
    int ok; //boolean
    struct chat_administrator_rights_t *result; //model

    int _library_owned; // Is the library responsible for freeing this object?
} get_my_default_administrator_rights_response_t;

__attribute__((deprecated)) get_my_default_administrator_rights_response_t *get_my_default_administrator_rights_response_create(
    int ok,
    chat_administrator_rights_t *result
);

void get_my_default_administrator_rights_response_free(get_my_default_administrator_rights_response_t *get_my_default_administrator_rights_response);

get_my_default_administrator_rights_response_t *get_my_default_administrator_rights_response_parseFromJSON(cJSON *get_my_default_administrator_rights_responseJSON);

cJSON *get_my_default_administrator_rights_response_convertToJSON(get_my_default_administrator_rights_response_t *get_my_default_administrator_rights_response);

#endif /* _get_my_default_administrator_rights_response_H_ */

