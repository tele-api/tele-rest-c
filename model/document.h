/*
 * document.h
 *
 * This object represents a general file (as opposed to [photos](https://core.telegram.org/bots/api/#photosize), [voice messages](https://core.telegram.org/bots/api/#voice) and [audio files](https://core.telegram.org/bots/api/#audio)).
 */

#ifndef _document_H_
#define _document_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct document_t document_t;

#include "photo_size.h"



typedef struct document_t {
    char *file_id; // string
    char *file_unique_id; // string
    struct photo_size_t *thumbnail; //model
    char *file_name; // string
    char *mime_type; // string
    int file_size; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} document_t;

__attribute__((deprecated)) document_t *document_create(
    char *file_id,
    char *file_unique_id,
    photo_size_t *thumbnail,
    char *file_name,
    char *mime_type,
    int file_size
);

void document_free(document_t *document);

document_t *document_parseFromJSON(cJSON *documentJSON);

cJSON *document_convertToJSON(document_t *document);

#endif /* _document_H_ */

