/*
 * chat_photo.h
 *
 * This object represents a chat photo.
 */

#ifndef _chat_photo_H_
#define _chat_photo_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct chat_photo_t chat_photo_t;




typedef struct chat_photo_t {
    char *small_file_id; // string
    char *small_file_unique_id; // string
    char *big_file_id; // string
    char *big_file_unique_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} chat_photo_t;

__attribute__((deprecated)) chat_photo_t *chat_photo_create(
    char *small_file_id,
    char *small_file_unique_id,
    char *big_file_id,
    char *big_file_unique_id
);

void chat_photo_free(chat_photo_t *chat_photo);

chat_photo_t *chat_photo_parseFromJSON(cJSON *chat_photoJSON);

cJSON *chat_photo_convertToJSON(chat_photo_t *chat_photo);

#endif /* _chat_photo_H_ */

