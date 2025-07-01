/*
 * inline_query_result_cached_document.h
 *
 * Represents a link to a file stored on the Telegram servers. By default, this file will be sent by the user with an optional caption. Alternatively, you can use *input\\_message\\_content* to send a message with the specified content instead of the file.
 */

#ifndef _inline_query_result_cached_document_H_
#define _inline_query_result_cached_document_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct inline_query_result_cached_document_t inline_query_result_cached_document_t;

#include "inline_keyboard_markup.h"
#include "input_message_content.h"
#include "message_entity.h"



typedef struct inline_query_result_cached_document_t {
    char *type; // string
    char *id; // string
    char *title; // string
    char *document_file_id; // string
    char *description; // string
    char *caption; // string
    char *parse_mode; // string
    list_t *caption_entities; //nonprimitive container
    struct inline_keyboard_markup_t *reply_markup; //model
    struct input_message_content_t *input_message_content; //model

    int _library_owned; // Is the library responsible for freeing this object?
} inline_query_result_cached_document_t;

__attribute__((deprecated)) inline_query_result_cached_document_t *inline_query_result_cached_document_create(
    char *type,
    char *id,
    char *title,
    char *document_file_id,
    char *description,
    char *caption,
    char *parse_mode,
    list_t *caption_entities,
    inline_keyboard_markup_t *reply_markup,
    input_message_content_t *input_message_content
);

void inline_query_result_cached_document_free(inline_query_result_cached_document_t *inline_query_result_cached_document);

inline_query_result_cached_document_t *inline_query_result_cached_document_parseFromJSON(cJSON *inline_query_result_cached_documentJSON);

cJSON *inline_query_result_cached_document_convertToJSON(inline_query_result_cached_document_t *inline_query_result_cached_document);

#endif /* _inline_query_result_cached_document_H_ */

