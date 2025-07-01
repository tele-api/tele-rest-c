/*
 * _send_video_post_request_video.h
 *
 * Video to send. Pass a file\\_id as String to send a video that exists on the Telegram servers (recommended), pass an HTTP URL as a String for Telegram to get a video from the Internet, or upload a new video using multipart/form-data. [More information on Sending Files »](https://core.telegram.org/bots/api/#sending-files)
 */

#ifndef __send_video_post_request_video_H_
#define __send_video_post_request_video_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _send_video_post_request_video_t _send_video_post_request_video_t;




typedef struct _send_video_post_request_video_t {

    int _library_owned; // Is the library responsible for freeing this object?
} _send_video_post_request_video_t;

__attribute__((deprecated)) _send_video_post_request_video_t *_send_video_post_request_video_create(
);

void _send_video_post_request_video_free(_send_video_post_request_video_t *_send_video_post_request_video);

_send_video_post_request_video_t *_send_video_post_request_video_parseFromJSON(cJSON *_send_video_post_request_videoJSON);

cJSON *_send_video_post_request_video_convertToJSON(_send_video_post_request_video_t *_send_video_post_request_video);

#endif /* __send_video_post_request_video_H_ */

