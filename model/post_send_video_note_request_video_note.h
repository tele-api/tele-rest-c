/*
 * post_send_video_note_request_video_note.h
 *
 * Video note to send. Pass a file\\_id as String to send a video note that exists on the Telegram servers (recommended) or upload a new video using multipart/form-data. [More information on Sending Files »](https://core.telegram.org/bots/api/#sending-files). Sending video notes by a URL is currently unsupported
 */

#ifndef _post_send_video_note_request_video_note_H_
#define _post_send_video_note_request_video_note_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_send_video_note_request_video_note_t post_send_video_note_request_video_note_t;




typedef struct post_send_video_note_request_video_note_t {

    int _library_owned; // Is the library responsible for freeing this object?
} post_send_video_note_request_video_note_t;

__attribute__((deprecated)) post_send_video_note_request_video_note_t *post_send_video_note_request_video_note_create(
);

void post_send_video_note_request_video_note_free(post_send_video_note_request_video_note_t *post_send_video_note_request_video_note);

post_send_video_note_request_video_note_t *post_send_video_note_request_video_note_parseFromJSON(cJSON *post_send_video_note_request_video_noteJSON);

cJSON *post_send_video_note_request_video_note_convertToJSON(post_send_video_note_request_video_note_t *post_send_video_note_request_video_note);

#endif /* _post_send_video_note_request_video_note_H_ */

