/*
 * inline_query_result_audio.h
 *
 * Represents a link to an MP3 audio file. By default, this audio file will be sent by the user. Alternatively, you can use *input\\_message\\_content* to send a message with the specified content instead of the audio.
 */

#ifndef _inline_query_result_audio_H_
#define _inline_query_result_audio_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct inline_query_result_audio_t inline_query_result_audio_t;

#include "inline_keyboard_markup.h"
#include "input_message_content.h"
#include "message_entity.h"



typedef struct inline_query_result_audio_t {
    char *type; // string
    char *id; // string
    char *audio_url; // string
    char *title; // string
    char *caption; // string
    char *parse_mode; // string
    list_t *caption_entities; //nonprimitive container
    char *performer; // string
    int audio_duration; //numeric
    struct inline_keyboard_markup_t *reply_markup; //model
    struct input_message_content_t *input_message_content; //model

    int _library_owned; // Is the library responsible for freeing this object?
} inline_query_result_audio_t;

__attribute__((deprecated)) inline_query_result_audio_t *inline_query_result_audio_create(
    char *type,
    char *id,
    char *audio_url,
    char *title,
    char *caption,
    char *parse_mode,
    list_t *caption_entities,
    char *performer,
    int audio_duration,
    inline_keyboard_markup_t *reply_markup,
    input_message_content_t *input_message_content
);

void inline_query_result_audio_free(inline_query_result_audio_t *inline_query_result_audio);

inline_query_result_audio_t *inline_query_result_audio_parseFromJSON(cJSON *inline_query_result_audioJSON);

cJSON *inline_query_result_audio_convertToJSON(inline_query_result_audio_t *inline_query_result_audio);

#endif /* _inline_query_result_audio_H_ */

