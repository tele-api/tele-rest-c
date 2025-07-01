/*
 * _send_sticker_post_request_sticker.h
 *
 * Sticker to send. Pass a file\\_id as String to send a file that exists on the Telegram servers (recommended), pass an HTTP URL as a String for Telegram to get a .WEBP sticker from the Internet, or upload a new .WEBP, .TGS, or .WEBM sticker using multipart/form-data. [More information on Sending Files »](https://core.telegram.org/bots/api/#sending-files). Video and animated stickers can&#39;t be sent via an HTTP URL.
 */

#ifndef __send_sticker_post_request_sticker_H_
#define __send_sticker_post_request_sticker_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _send_sticker_post_request_sticker_t _send_sticker_post_request_sticker_t;




typedef struct _send_sticker_post_request_sticker_t {

    int _library_owned; // Is the library responsible for freeing this object?
} _send_sticker_post_request_sticker_t;

__attribute__((deprecated)) _send_sticker_post_request_sticker_t *_send_sticker_post_request_sticker_create(
);

void _send_sticker_post_request_sticker_free(_send_sticker_post_request_sticker_t *_send_sticker_post_request_sticker);

_send_sticker_post_request_sticker_t *_send_sticker_post_request_sticker_parseFromJSON(cJSON *_send_sticker_post_request_stickerJSON);

cJSON *_send_sticker_post_request_sticker_convertToJSON(_send_sticker_post_request_sticker_t *_send_sticker_post_request_sticker);

#endif /* __send_sticker_post_request_sticker_H_ */

