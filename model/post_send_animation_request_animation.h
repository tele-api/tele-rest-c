/*
 * post_send_animation_request_animation.h
 *
 * Animation to send. Pass a file\\_id as String to send an animation that exists on the Telegram servers (recommended), pass an HTTP URL as a String for Telegram to get an animation from the Internet, or upload a new animation using multipart/form-data. [More information on Sending Files »](https://core.telegram.org/bots/api/#sending-files)
 */

#ifndef _post_send_animation_request_animation_H_
#define _post_send_animation_request_animation_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_send_animation_request_animation_t post_send_animation_request_animation_t;




typedef struct post_send_animation_request_animation_t {

    int _library_owned; // Is the library responsible for freeing this object?
} post_send_animation_request_animation_t;

__attribute__((deprecated)) post_send_animation_request_animation_t *post_send_animation_request_animation_create(
);

void post_send_animation_request_animation_free(post_send_animation_request_animation_t *post_send_animation_request_animation);

post_send_animation_request_animation_t *post_send_animation_request_animation_parseFromJSON(cJSON *post_send_animation_request_animationJSON);

cJSON *post_send_animation_request_animation_convertToJSON(post_send_animation_request_animation_t *post_send_animation_request_animation);

#endif /* _post_send_animation_request_animation_H_ */

