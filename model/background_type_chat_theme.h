/*
 * background_type_chat_theme.h
 *
 * The background is taken directly from a built-in chat theme.
 */

#ifndef _background_type_chat_theme_H_
#define _background_type_chat_theme_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct background_type_chat_theme_t background_type_chat_theme_t;




typedef struct background_type_chat_theme_t {
    char *type; // string
    char *theme_name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} background_type_chat_theme_t;

__attribute__((deprecated)) background_type_chat_theme_t *background_type_chat_theme_create(
    char *type,
    char *theme_name
);

void background_type_chat_theme_free(background_type_chat_theme_t *background_type_chat_theme);

background_type_chat_theme_t *background_type_chat_theme_parseFromJSON(cJSON *background_type_chat_themeJSON);

cJSON *background_type_chat_theme_convertToJSON(background_type_chat_theme_t *background_type_chat_theme);

#endif /* _background_type_chat_theme_H_ */

