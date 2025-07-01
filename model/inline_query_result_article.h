/*
 * inline_query_result_article.h
 *
 * Represents a link to an article or web page.
 */

#ifndef _inline_query_result_article_H_
#define _inline_query_result_article_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct inline_query_result_article_t inline_query_result_article_t;

#include "inline_keyboard_markup.h"
#include "input_message_content.h"



typedef struct inline_query_result_article_t {
    char *type; // string
    char *id; // string
    char *title; // string
    struct input_message_content_t *input_message_content; //model
    struct inline_keyboard_markup_t *reply_markup; //model
    char *url; // string
    char *description; // string
    char *thumbnail_url; // string
    int thumbnail_width; //numeric
    int thumbnail_height; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} inline_query_result_article_t;

__attribute__((deprecated)) inline_query_result_article_t *inline_query_result_article_create(
    char *type,
    char *id,
    char *title,
    input_message_content_t *input_message_content,
    inline_keyboard_markup_t *reply_markup,
    char *url,
    char *description,
    char *thumbnail_url,
    int thumbnail_width,
    int thumbnail_height
);

void inline_query_result_article_free(inline_query_result_article_t *inline_query_result_article);

inline_query_result_article_t *inline_query_result_article_parseFromJSON(cJSON *inline_query_result_articleJSON);

cJSON *inline_query_result_article_convertToJSON(inline_query_result_article_t *inline_query_result_article);

#endif /* _inline_query_result_article_H_ */

