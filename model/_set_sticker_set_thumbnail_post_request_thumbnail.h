/*
 * _set_sticker_set_thumbnail_post_request_thumbnail.h
 *
 * A **.WEBP** or **.PNG** image with the thumbnail, must be up to 128 kilobytes in size and have a width and height of exactly 100px, or a **.TGS** animation with a thumbnail up to 32 kilobytes in size (see [https://core.telegram.org/stickers#animation-requirements](https://core.telegram.org/stickers#animation-requirements) for animated sticker technical requirements), or a **.WEBM** video with the thumbnail up to 32 kilobytes in size; see [https://core.telegram.org/stickers#video-requirements](https://core.telegram.org/stickers#video-requirements) for video sticker technical requirements. Pass a *file\\_id* as a String to send a file that already exists on the Telegram servers, pass an HTTP URL as a String for Telegram to get a file from the Internet, or upload a new one using multipart/form-data. [More information on Sending Files »](https://core.telegram.org/bots/api/#sending-files). Animated and video sticker set thumbnails can&#39;t be uploaded via HTTP URL. If omitted, then the thumbnail is dropped and the first sticker is used as the thumbnail.
 */

#ifndef __set_sticker_set_thumbnail_post_request_thumbnail_H_
#define __set_sticker_set_thumbnail_post_request_thumbnail_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _set_sticker_set_thumbnail_post_request_thumbnail_t _set_sticker_set_thumbnail_post_request_thumbnail_t;




typedef struct _set_sticker_set_thumbnail_post_request_thumbnail_t {

    int _library_owned; // Is the library responsible for freeing this object?
} _set_sticker_set_thumbnail_post_request_thumbnail_t;

__attribute__((deprecated)) _set_sticker_set_thumbnail_post_request_thumbnail_t *_set_sticker_set_thumbnail_post_request_thumbnail_create(
);

void _set_sticker_set_thumbnail_post_request_thumbnail_free(_set_sticker_set_thumbnail_post_request_thumbnail_t *_set_sticker_set_thumbnail_post_request_thumbnail);

_set_sticker_set_thumbnail_post_request_thumbnail_t *_set_sticker_set_thumbnail_post_request_thumbnail_parseFromJSON(cJSON *_set_sticker_set_thumbnail_post_request_thumbnailJSON);

cJSON *_set_sticker_set_thumbnail_post_request_thumbnail_convertToJSON(_set_sticker_set_thumbnail_post_request_thumbnail_t *_set_sticker_set_thumbnail_post_request_thumbnail);

#endif /* __set_sticker_set_thumbnail_post_request_thumbnail_H_ */

