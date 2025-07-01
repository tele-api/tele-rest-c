/*
 * _send_video_note_post_request_video_note.h
 *
 * Video note to send. Pass a file\\_id as String to send a video note that exists on the Telegram servers (recommended) or upload a new video using multipart/form-data. [More information on Sending Files »](https://core.telegram.org/bots/api/#sending-files). Sending video notes by a URL is currently unsupported
 */

#ifndef __send_video_note_post_request_video_note_H_
#define __send_video_note_post_request_video_note_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _send_video_note_post_request_video_note_t _send_video_note_post_request_video_note_t;




typedef struct _send_video_note_post_request_video_note_t {

    int _library_owned; // Is the library responsible for freeing this object?
} _send_video_note_post_request_video_note_t;

__attribute__((deprecated)) _send_video_note_post_request_video_note_t *_send_video_note_post_request_video_note_create(
);

void _send_video_note_post_request_video_note_free(_send_video_note_post_request_video_note_t *_send_video_note_post_request_video_note);

_send_video_note_post_request_video_note_t *_send_video_note_post_request_video_note_parseFromJSON(cJSON *_send_video_note_post_request_video_noteJSON);

cJSON *_send_video_note_post_request_video_note_convertToJSON(_send_video_note_post_request_video_note_t *_send_video_note_post_request_video_note);

#endif /* __send_video_note_post_request_video_note_H_ */

