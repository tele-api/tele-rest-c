/*
 * _send_audio_post_request_audio.h
 *
 * Audio file to send. Pass a file\\_id as String to send an audio file that exists on the Telegram servers (recommended), pass an HTTP URL as a String for Telegram to get an audio file from the Internet, or upload a new one using multipart/form-data. [More information on Sending Files »](https://core.telegram.org/bots/api/#sending-files)
 */

#ifndef __send_audio_post_request_audio_H_
#define __send_audio_post_request_audio_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _send_audio_post_request_audio_t _send_audio_post_request_audio_t;




typedef struct _send_audio_post_request_audio_t {

    int _library_owned; // Is the library responsible for freeing this object?
} _send_audio_post_request_audio_t;

__attribute__((deprecated)) _send_audio_post_request_audio_t *_send_audio_post_request_audio_create(
);

void _send_audio_post_request_audio_free(_send_audio_post_request_audio_t *_send_audio_post_request_audio);

_send_audio_post_request_audio_t *_send_audio_post_request_audio_parseFromJSON(cJSON *_send_audio_post_request_audioJSON);

cJSON *_send_audio_post_request_audio_convertToJSON(_send_audio_post_request_audio_t *_send_audio_post_request_audio);

#endif /* __send_audio_post_request_audio_H_ */

