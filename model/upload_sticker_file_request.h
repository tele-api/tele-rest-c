/*
 * upload_sticker_file_request.h
 *
 * Request parameters for uploadStickerFile
 */

#ifndef _upload_sticker_file_request_H_
#define _upload_sticker_file_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct upload_sticker_file_request_t upload_sticker_file_request_t;

#include "any_type.h"

// Enum STICKERFORMAT for upload_sticker_file_request

typedef enum  { telegram_bot_api_upload_sticker_file_request_STICKERFORMAT_NULL = 0, telegram_bot_api_upload_sticker_file_request_STICKERFORMAT__static, telegram_bot_api_upload_sticker_file_request_STICKERFORMAT_animated, telegram_bot_api_upload_sticker_file_request_STICKERFORMAT_video } telegram_bot_api_upload_sticker_file_request_STICKERFORMAT_e;

char* upload_sticker_file_request_sticker_format_ToString(telegram_bot_api_upload_sticker_file_request_STICKERFORMAT_e sticker_format);

telegram_bot_api_upload_sticker_file_request_STICKERFORMAT_e upload_sticker_file_request_sticker_format_FromString(char* sticker_format);



typedef struct upload_sticker_file_request_t {
    int user_id; //numeric
    any_type_t *sticker; // custom
    telegram_bot_api_upload_sticker_file_request_STICKERFORMAT_e sticker_format; //enum

    int _library_owned; // Is the library responsible for freeing this object?
} upload_sticker_file_request_t;

__attribute__((deprecated)) upload_sticker_file_request_t *upload_sticker_file_request_create(
    int user_id,
    any_type_t *sticker,
    telegram_bot_api_upload_sticker_file_request_STICKERFORMAT_e sticker_format
);

void upload_sticker_file_request_free(upload_sticker_file_request_t *upload_sticker_file_request);

upload_sticker_file_request_t *upload_sticker_file_request_parseFromJSON(cJSON *upload_sticker_file_requestJSON);

cJSON *upload_sticker_file_request_convertToJSON(upload_sticker_file_request_t *upload_sticker_file_request);

#endif /* _upload_sticker_file_request_H_ */

