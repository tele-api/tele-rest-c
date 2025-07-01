/*
 * _send_video_post_request_cover.h
 *
 * Cover for the video in the message. Pass a file\\_id to send a file that exists on the Telegram servers (recommended), pass an HTTP URL for Telegram to get a file from the Internet, or pass “attach://\\&lt;file\\_attach\\_name\\&gt;” to upload a new one using multipart/form-data under \\&lt;file\\_attach\\_name\\&gt; name. [More information on Sending Files »](https://core.telegram.org/bots/api/#sending-files)
 */

#ifndef __send_video_post_request_cover_H_
#define __send_video_post_request_cover_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _send_video_post_request_cover_t _send_video_post_request_cover_t;




typedef struct _send_video_post_request_cover_t {

    int _library_owned; // Is the library responsible for freeing this object?
} _send_video_post_request_cover_t;

__attribute__((deprecated)) _send_video_post_request_cover_t *_send_video_post_request_cover_create(
);

void _send_video_post_request_cover_free(_send_video_post_request_cover_t *_send_video_post_request_cover);

_send_video_post_request_cover_t *_send_video_post_request_cover_parseFromJSON(cJSON *_send_video_post_request_coverJSON);

cJSON *_send_video_post_request_cover_convertToJSON(_send_video_post_request_cover_t *_send_video_post_request_cover);

#endif /* __send_video_post_request_cover_H_ */

