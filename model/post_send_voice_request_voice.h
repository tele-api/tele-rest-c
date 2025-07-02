/*
 * post_send_voice_request_voice.h
 *
 * Audio file to send. Pass a file\\_id as String to send a file that exists on the Telegram servers (recommended), pass an HTTP URL as a String for Telegram to get a file from the Internet, or upload a new one using multipart/form-data. [More information on Sending Files »](https://core.telegram.org/bots/api/#sending-files)
 */

#ifndef _post_send_voice_request_voice_H_
#define _post_send_voice_request_voice_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_send_voice_request_voice_t post_send_voice_request_voice_t;




typedef struct post_send_voice_request_voice_t {

    int _library_owned; // Is the library responsible for freeing this object?
} post_send_voice_request_voice_t;

__attribute__((deprecated)) post_send_voice_request_voice_t *post_send_voice_request_voice_create(
);

void post_send_voice_request_voice_free(post_send_voice_request_voice_t *post_send_voice_request_voice);

post_send_voice_request_voice_t *post_send_voice_request_voice_parseFromJSON(cJSON *post_send_voice_request_voiceJSON);

cJSON *post_send_voice_request_voice_convertToJSON(post_send_voice_request_voice_t *post_send_voice_request_voice);

#endif /* _post_send_voice_request_voice_H_ */

