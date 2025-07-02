/*
 * post_send_audio_request_thumbnail.h
 *
 * Thumbnail of the file sent; can be ignored if thumbnail generation for the file is supported server-side. The thumbnail should be in JPEG format and less than 200 kB in size. A thumbnail&#39;s width and height should not exceed 320. Ignored if the file is not uploaded using multipart/form-data. Thumbnails can&#39;t be reused and can be only uploaded as a new file, so you can pass “attach://\\&lt;file\\_attach\\_name\\&gt;” if the thumbnail was uploaded using multipart/form-data under \\&lt;file\\_attach\\_name\\&gt;. [More information on Sending Files »](https://core.telegram.org/bots/api/#sending-files)
 */

#ifndef _post_send_audio_request_thumbnail_H_
#define _post_send_audio_request_thumbnail_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_send_audio_request_thumbnail_t post_send_audio_request_thumbnail_t;




typedef struct post_send_audio_request_thumbnail_t {

    int _library_owned; // Is the library responsible for freeing this object?
} post_send_audio_request_thumbnail_t;

__attribute__((deprecated)) post_send_audio_request_thumbnail_t *post_send_audio_request_thumbnail_create(
);

void post_send_audio_request_thumbnail_free(post_send_audio_request_thumbnail_t *post_send_audio_request_thumbnail);

post_send_audio_request_thumbnail_t *post_send_audio_request_thumbnail_parseFromJSON(cJSON *post_send_audio_request_thumbnailJSON);

cJSON *post_send_audio_request_thumbnail_convertToJSON(post_send_audio_request_thumbnail_t *post_send_audio_request_thumbnail);

#endif /* _post_send_audio_request_thumbnail_H_ */

