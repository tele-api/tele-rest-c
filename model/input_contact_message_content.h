/*
 * input_contact_message_content.h
 *
 * Represents the [content](https://core.telegram.org/bots/api/#inputmessagecontent) of a contact message to be sent as the result of an inline query.
 */

#ifndef _input_contact_message_content_H_
#define _input_contact_message_content_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct input_contact_message_content_t input_contact_message_content_t;




typedef struct input_contact_message_content_t {
    char *phone_number; // string
    char *first_name; // string
    char *last_name; // string
    char *vcard; // string

    int _library_owned; // Is the library responsible for freeing this object?
} input_contact_message_content_t;

__attribute__((deprecated)) input_contact_message_content_t *input_contact_message_content_create(
    char *phone_number,
    char *first_name,
    char *last_name,
    char *vcard
);

void input_contact_message_content_free(input_contact_message_content_t *input_contact_message_content);

input_contact_message_content_t *input_contact_message_content_parseFromJSON(cJSON *input_contact_message_contentJSON);

cJSON *input_contact_message_content_convertToJSON(input_contact_message_content_t *input_contact_message_content);

#endif /* _input_contact_message_content_H_ */

