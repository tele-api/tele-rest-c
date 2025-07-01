/*
 * copy_text_button.h
 *
 * This object represents an inline keyboard button that copies specified text to the clipboard.
 */

#ifndef _copy_text_button_H_
#define _copy_text_button_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct copy_text_button_t copy_text_button_t;




typedef struct copy_text_button_t {
    char *text; // string

    int _library_owned; // Is the library responsible for freeing this object?
} copy_text_button_t;

__attribute__((deprecated)) copy_text_button_t *copy_text_button_create(
    char *text
);

void copy_text_button_free(copy_text_button_t *copy_text_button);

copy_text_button_t *copy_text_button_parseFromJSON(cJSON *copy_text_buttonJSON);

cJSON *copy_text_button_convertToJSON(copy_text_button_t *copy_text_button);

#endif /* _copy_text_button_H_ */

