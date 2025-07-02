/*
 * post_send_audio_request_audio.h
 *
 * Audio file to send. Pass a file\\_id as String to send an audio file that exists on the Telegram servers (recommended), pass an HTTP URL as a String for Telegram to get an audio file from the Internet, or upload a new one using multipart/form-data. [More information on Sending Files »](https://core.telegram.org/bots/api/#sending-files)
 */

#ifndef _post_send_audio_request_audio_H_
#define _post_send_audio_request_audio_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_send_audio_request_audio_t post_send_audio_request_audio_t;




typedef struct post_send_audio_request_audio_t {

    int _library_owned; // Is the library responsible for freeing this object?
} post_send_audio_request_audio_t;

__attribute__((deprecated)) post_send_audio_request_audio_t *post_send_audio_request_audio_create(
);

void post_send_audio_request_audio_free(post_send_audio_request_audio_t *post_send_audio_request_audio);

post_send_audio_request_audio_t *post_send_audio_request_audio_parseFromJSON(cJSON *post_send_audio_request_audioJSON);

cJSON *post_send_audio_request_audio_convertToJSON(post_send_audio_request_audio_t *post_send_audio_request_audio);

#endif /* _post_send_audio_request_audio_H_ */

