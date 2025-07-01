/*
 * text_quote.h
 *
 * This object contains information about the quoted part of a message that is replied to by the given message.
 */

#ifndef _text_quote_H_
#define _text_quote_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct text_quote_t text_quote_t;

#include "message_entity.h"



typedef struct text_quote_t {
    char *text; // string
    int position; //numeric
    list_t *entities; //nonprimitive container
    int is_manual; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} text_quote_t;

__attribute__((deprecated)) text_quote_t *text_quote_create(
    char *text,
    int position,
    list_t *entities,
    int is_manual
);

void text_quote_free(text_quote_t *text_quote);

text_quote_t *text_quote_parseFromJSON(cJSON *text_quoteJSON);

cJSON *text_quote_convertToJSON(text_quote_t *text_quote);

#endif /* _text_quote_H_ */

