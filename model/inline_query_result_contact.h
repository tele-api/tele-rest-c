/*
 * inline_query_result_contact.h
 *
 * Represents a contact with a phone number. By default, this contact will be sent by the user. Alternatively, you can use *input\\_message\\_content* to send a message with the specified content instead of the contact.
 */

#ifndef _inline_query_result_contact_H_
#define _inline_query_result_contact_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct inline_query_result_contact_t inline_query_result_contact_t;

#include "inline_keyboard_markup.h"
#include "input_message_content.h"



typedef struct inline_query_result_contact_t {
    char *type; // string
    char *id; // string
    char *phone_number; // string
    char *first_name; // string
    char *last_name; // string
    char *vcard; // string
    struct inline_keyboard_markup_t *reply_markup; //model
    struct input_message_content_t *input_message_content; //model
    char *thumbnail_url; // string
    int thumbnail_width; //numeric
    int thumbnail_height; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} inline_query_result_contact_t;

__attribute__((deprecated)) inline_query_result_contact_t *inline_query_result_contact_create(
    char *type,
    char *id,
    char *phone_number,
    char *first_name,
    char *last_name,
    char *vcard,
    inline_keyboard_markup_t *reply_markup,
    input_message_content_t *input_message_content,
    char *thumbnail_url,
    int thumbnail_width,
    int thumbnail_height
);

void inline_query_result_contact_free(inline_query_result_contact_t *inline_query_result_contact);

inline_query_result_contact_t *inline_query_result_contact_parseFromJSON(cJSON *inline_query_result_contactJSON);

cJSON *inline_query_result_contact_convertToJSON(inline_query_result_contact_t *inline_query_result_contact);

#endif /* _inline_query_result_contact_H_ */

