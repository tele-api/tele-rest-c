/*
 * input_text_message_content.h
 *
 * Represents the [content](https://core.telegram.org/bots/api/#inputmessagecontent) of a text message to be sent as the result of an inline query.
 */

#ifndef _input_text_message_content_H_
#define _input_text_message_content_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct input_text_message_content_t input_text_message_content_t;

#include "link_preview_options.h"
#include "message_entity.h"



typedef struct input_text_message_content_t {
    char *message_text; // string
    char *parse_mode; // string
    list_t *entities; //nonprimitive container
    struct link_preview_options_t *link_preview_options; //model

    int _library_owned; // Is the library responsible for freeing this object?
} input_text_message_content_t;

__attribute__((deprecated)) input_text_message_content_t *input_text_message_content_create(
    char *message_text,
    char *parse_mode,
    list_t *entities,
    link_preview_options_t *link_preview_options
);

void input_text_message_content_free(input_text_message_content_t *input_text_message_content);

input_text_message_content_t *input_text_message_content_parseFromJSON(cJSON *input_text_message_contentJSON);

cJSON *input_text_message_content_convertToJSON(input_text_message_content_t *input_text_message_content);

#endif /* _input_text_message_content_H_ */

