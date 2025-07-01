/*
 * input_media_document.h
 *
 * Represents a general file to be sent.
 */

#ifndef _input_media_document_H_
#define _input_media_document_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct input_media_document_t input_media_document_t;

#include "message_entity.h"



typedef struct input_media_document_t {
    char *type; // string
    char *media; // string
    char *thumbnail; // string
    char *caption; // string
    char *parse_mode; // string
    list_t *caption_entities; //nonprimitive container
    int disable_content_type_detection; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} input_media_document_t;

__attribute__((deprecated)) input_media_document_t *input_media_document_create(
    char *type,
    char *media,
    char *thumbnail,
    char *caption,
    char *parse_mode,
    list_t *caption_entities,
    int disable_content_type_detection
);

void input_media_document_free(input_media_document_t *input_media_document);

input_media_document_t *input_media_document_parseFromJSON(cJSON *input_media_documentJSON);

cJSON *input_media_document_convertToJSON(input_media_document_t *input_media_document);

#endif /* _input_media_document_H_ */

