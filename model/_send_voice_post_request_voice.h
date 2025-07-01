/*
 * _send_voice_post_request_voice.h
 *
 * Audio file to send. Pass a file\\_id as String to send a file that exists on the Telegram servers (recommended), pass an HTTP URL as a String for Telegram to get a file from the Internet, or upload a new one using multipart/form-data. [More information on Sending Files »](https://core.telegram.org/bots/api/#sending-files)
 */

#ifndef __send_voice_post_request_voice_H_
#define __send_voice_post_request_voice_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _send_voice_post_request_voice_t _send_voice_post_request_voice_t;




typedef struct _send_voice_post_request_voice_t {

    int _library_owned; // Is the library responsible for freeing this object?
} _send_voice_post_request_voice_t;

__attribute__((deprecated)) _send_voice_post_request_voice_t *_send_voice_post_request_voice_create(
);

void _send_voice_post_request_voice_free(_send_voice_post_request_voice_t *_send_voice_post_request_voice);

_send_voice_post_request_voice_t *_send_voice_post_request_voice_parseFromJSON(cJSON *_send_voice_post_request_voiceJSON);

cJSON *_send_voice_post_request_voice_convertToJSON(_send_voice_post_request_voice_t *_send_voice_post_request_voice);

#endif /* __send_voice_post_request_voice_H_ */

