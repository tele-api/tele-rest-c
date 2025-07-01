/*
 * invoice.h
 *
 * This object contains basic information about an invoice.
 */

#ifndef _invoice_H_
#define _invoice_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct invoice_t invoice_t;




typedef struct invoice_t {
    char *title; // string
    char *description; // string
    char *start_parameter; // string
    char *currency; // string
    int total_amount; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} invoice_t;

__attribute__((deprecated)) invoice_t *invoice_create(
    char *title,
    char *description,
    char *start_parameter,
    char *currency,
    int total_amount
);

void invoice_free(invoice_t *invoice);

invoice_t *invoice_parseFromJSON(cJSON *invoiceJSON);

cJSON *invoice_convertToJSON(invoice_t *invoice);

#endif /* _invoice_H_ */

