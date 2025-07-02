/*
 * post_send_video_request_video.h
 *
 * Video to send. Pass a file\\_id as String to send a video that exists on the Telegram servers (recommended), pass an HTTP URL as a String for Telegram to get a video from the Internet, or upload a new video using multipart/form-data. [More information on Sending Files »](https://core.telegram.org/bots/api/#sending-files)
 */

#ifndef _post_send_video_request_video_H_
#define _post_send_video_request_video_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_send_video_request_video_t post_send_video_request_video_t;




typedef struct post_send_video_request_video_t {

    int _library_owned; // Is the library responsible for freeing this object?
} post_send_video_request_video_t;

__attribute__((deprecated)) post_send_video_request_video_t *post_send_video_request_video_create(
);

void post_send_video_request_video_free(post_send_video_request_video_t *post_send_video_request_video);

post_send_video_request_video_t *post_send_video_request_video_parseFromJSON(cJSON *post_send_video_request_videoJSON);

cJSON *post_send_video_request_video_convertToJSON(post_send_video_request_video_t *post_send_video_request_video);

#endif /* _post_send_video_request_video_H_ */

