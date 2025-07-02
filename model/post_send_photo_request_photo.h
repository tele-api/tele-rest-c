/*
 * post_send_photo_request_photo.h
 *
 * Photo to send. Pass a file\\_id as String to send a photo that exists on the Telegram servers (recommended), pass an HTTP URL as a String for Telegram to get a photo from the Internet, or upload a new photo using multipart/form-data. The photo must be at most 10 MB in size. The photo&#39;s width and height must not exceed 10000 in total. Width and height ratio must be at most 20. [More information on Sending Files »](https://core.telegram.org/bots/api/#sending-files)
 */

#ifndef _post_send_photo_request_photo_H_
#define _post_send_photo_request_photo_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_send_photo_request_photo_t post_send_photo_request_photo_t;




typedef struct post_send_photo_request_photo_t {

    int _library_owned; // Is the library responsible for freeing this object?
} post_send_photo_request_photo_t;

__attribute__((deprecated)) post_send_photo_request_photo_t *post_send_photo_request_photo_create(
);

void post_send_photo_request_photo_free(post_send_photo_request_photo_t *post_send_photo_request_photo);

post_send_photo_request_photo_t *post_send_photo_request_photo_parseFromJSON(cJSON *post_send_photo_request_photoJSON);

cJSON *post_send_photo_request_photo_convertToJSON(post_send_photo_request_photo_t *post_send_photo_request_photo);

#endif /* _post_send_photo_request_photo_H_ */

