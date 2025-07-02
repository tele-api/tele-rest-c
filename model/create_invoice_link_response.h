/*
 * create_invoice_link_response.h
 *
 * 
 */

#ifndef _create_invoice_link_response_H_
#define _create_invoice_link_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct create_invoice_link_response_t create_invoice_link_response_t;




typedef struct create_invoice_link_response_t {
    int ok; //boolean
    char *result; // string

    int _library_owned; // Is the library responsible for freeing this object?
} create_invoice_link_response_t;

__attribute__((deprecated)) create_invoice_link_response_t *create_invoice_link_response_create(
    int ok,
    char *result
);

void create_invoice_link_response_free(create_invoice_link_response_t *create_invoice_link_response);

create_invoice_link_response_t *create_invoice_link_response_parseFromJSON(cJSON *create_invoice_link_responseJSON);

cJSON *create_invoice_link_response_convertToJSON(create_invoice_link_response_t *create_invoice_link_response);

#endif /* _create_invoice_link_response_H_ */

