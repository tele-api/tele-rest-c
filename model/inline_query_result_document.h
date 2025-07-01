/*
 * inline_query_result_document.h
 *
 * Represents a link to a file. By default, this file will be sent by the user with an optional caption. Alternatively, you can use *input\\_message\\_content* to send a message with the specified content instead of the file. Currently, only **.PDF** and **.ZIP** files can be sent using this method.
 */

#ifndef _inline_query_result_document_H_
#define _inline_query_result_document_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct inline_query_result_document_t inline_query_result_document_t;

#include "inline_keyboard_markup.h"
#include "input_message_content.h"
#include "message_entity.h"

// Enum MIMETYPE for inline_query_result_document

typedef enum  { telegram_bot_api_inline_query_result_document_MIMETYPE_NULL = 0, telegram_bot_api_inline_query_result_document_MIMETYPE_application/pdf, telegram_bot_api_inline_query_result_document_MIMETYPE_application/zip } telegram_bot_api_inline_query_result_document_MIMETYPE_e;

char* inline_query_result_document_mime_type_ToString(telegram_bot_api_inline_query_result_document_MIMETYPE_e mime_type);

telegram_bot_api_inline_query_result_document_MIMETYPE_e inline_query_result_document_mime_type_FromString(char* mime_type);



typedef struct inline_query_result_document_t {
    char *type; // string
    char *id; // string
    char *title; // string
    char *document_url; // string
    telegram_bot_api_inline_query_result_document_MIMETYPE_e mime_type; //enum
    char *caption; // string
    char *parse_mode; // string
    list_t *caption_entities; //nonprimitive container
    char *description; // string
    struct inline_keyboard_markup_t *reply_markup; //model
    struct input_message_content_t *input_message_content; //model
    char *thumbnail_url; // string
    int thumbnail_width; //numeric
    int thumbnail_height; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} inline_query_result_document_t;

__attribute__((deprecated)) inline_query_result_document_t *inline_query_result_document_create(
    char *type,
    char *id,
    char *title,
    char *document_url,
    telegram_bot_api_inline_query_result_document_MIMETYPE_e mime_type,
    char *caption,
    char *parse_mode,
    list_t *caption_entities,
    char *description,
    inline_keyboard_markup_t *reply_markup,
    input_message_content_t *input_message_content,
    char *thumbnail_url,
    int thumbnail_width,
    int thumbnail_height
);

void inline_query_result_document_free(inline_query_result_document_t *inline_query_result_document);

inline_query_result_document_t *inline_query_result_document_parseFromJSON(cJSON *inline_query_result_documentJSON);

cJSON *inline_query_result_document_convertToJSON(inline_query_result_document_t *inline_query_result_document);

#endif /* _inline_query_result_document_H_ */

