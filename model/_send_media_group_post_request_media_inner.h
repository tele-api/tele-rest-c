/*
 * _send_media_group_post_request_media_inner.h
 *
 * 
 */

#ifndef __send_media_group_post_request_media_inner_H_
#define __send_media_group_post_request_media_inner_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _send_media_group_post_request_media_inner_t _send_media_group_post_request_media_inner_t;

#include "input_media_audio.h"
#include "input_media_document.h"
#include "input_media_photo.h"
#include "input_media_video.h"
#include "message_entity.h"



typedef struct _send_media_group_post_request_media_inner_t {
    char *type; // string
    char *media; // string
    char *thumbnail; // string
    char *caption; // string
    char *parse_mode; // string
    list_t *caption_entities; //nonprimitive container
    int duration; //numeric
    char *performer; // string
    char *title; // string
    int disable_content_type_detection; //boolean
    int show_caption_above_media; //boolean
    int has_spoiler; //boolean
    char *cover; // string
    int start_timestamp; //numeric
    int width; //numeric
    int height; //numeric
    int supports_streaming; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} _send_media_group_post_request_media_inner_t;

__attribute__((deprecated)) _send_media_group_post_request_media_inner_t *_send_media_group_post_request_media_inner_create(
    char *type,
    char *media,
    char *thumbnail,
    char *caption,
    char *parse_mode,
    list_t *caption_entities,
    int duration,
    char *performer,
    char *title,
    int disable_content_type_detection,
    int show_caption_above_media,
    int has_spoiler,
    char *cover,
    int start_timestamp,
    int width,
    int height,
    int supports_streaming
);

void _send_media_group_post_request_media_inner_free(_send_media_group_post_request_media_inner_t *_send_media_group_post_request_media_inner);

_send_media_group_post_request_media_inner_t *_send_media_group_post_request_media_inner_parseFromJSON(cJSON *_send_media_group_post_request_media_innerJSON);

cJSON *_send_media_group_post_request_media_inner_convertToJSON(_send_media_group_post_request_media_inner_t *_send_media_group_post_request_media_inner);

#endif /* __send_media_group_post_request_media_inner_H_ */

