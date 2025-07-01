/*
 * inline_query_result_voice.h
 *
 * Represents a link to a voice recording in an .OGG container encoded with OPUS. By default, this voice recording will be sent by the user. Alternatively, you can use *input\\_message\\_content* to send a message with the specified content instead of the the voice message.
 */

#ifndef _inline_query_result_voice_H_
#define _inline_query_result_voice_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct inline_query_result_voice_t inline_query_result_voice_t;

#include "inline_keyboard_markup.h"
#include "input_message_content.h"
#include "message_entity.h"



typedef struct inline_query_result_voice_t {
    char *type; // string
    char *id; // string
    char *voice_url; // string
    char *title; // string
    char *caption; // string
    char *parse_mode; // string
    list_t *caption_entities; //nonprimitive container
    int voice_duration; //numeric
    struct inline_keyboard_markup_t *reply_markup; //model
    struct input_message_content_t *input_message_content; //model

    int _library_owned; // Is the library responsible for freeing this object?
} inline_query_result_voice_t;

__attribute__((deprecated)) inline_query_result_voice_t *inline_query_result_voice_create(
    char *type,
    char *id,
    char *voice_url,
    char *title,
    char *caption,
    char *parse_mode,
    list_t *caption_entities,
    int voice_duration,
    inline_keyboard_markup_t *reply_markup,
    input_message_content_t *input_message_content
);

void inline_query_result_voice_free(inline_query_result_voice_t *inline_query_result_voice);

inline_query_result_voice_t *inline_query_result_voice_parseFromJSON(cJSON *inline_query_result_voiceJSON);

cJSON *inline_query_result_voice_convertToJSON(inline_query_result_voice_t *inline_query_result_voice);

#endif /* _inline_query_result_voice_H_ */

