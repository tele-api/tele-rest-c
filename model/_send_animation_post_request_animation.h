/*
 * _send_animation_post_request_animation.h
 *
 * Animation to send. Pass a file\\_id as String to send an animation that exists on the Telegram servers (recommended), pass an HTTP URL as a String for Telegram to get an animation from the Internet, or upload a new animation using multipart/form-data. [More information on Sending Files »](https://core.telegram.org/bots/api/#sending-files)
 */

#ifndef __send_animation_post_request_animation_H_
#define __send_animation_post_request_animation_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _send_animation_post_request_animation_t _send_animation_post_request_animation_t;




typedef struct _send_animation_post_request_animation_t {

    int _library_owned; // Is the library responsible for freeing this object?
} _send_animation_post_request_animation_t;

__attribute__((deprecated)) _send_animation_post_request_animation_t *_send_animation_post_request_animation_create(
);

void _send_animation_post_request_animation_free(_send_animation_post_request_animation_t *_send_animation_post_request_animation);

_send_animation_post_request_animation_t *_send_animation_post_request_animation_parseFromJSON(cJSON *_send_animation_post_request_animationJSON);

cJSON *_send_animation_post_request_animation_convertToJSON(_send_animation_post_request_animation_t *_send_animation_post_request_animation);

#endif /* __send_animation_post_request_animation_H_ */

