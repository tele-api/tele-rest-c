/*
 * link_preview_options.h
 *
 * Describes the options used for link preview generation.
 */

#ifndef _link_preview_options_H_
#define _link_preview_options_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct link_preview_options_t link_preview_options_t;




typedef struct link_preview_options_t {
    int is_disabled; //boolean
    char *url; // string
    int prefer_small_media; //boolean
    int prefer_large_media; //boolean
    int show_above_text; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} link_preview_options_t;

__attribute__((deprecated)) link_preview_options_t *link_preview_options_create(
    int is_disabled,
    char *url,
    int prefer_small_media,
    int prefer_large_media,
    int show_above_text
);

void link_preview_options_free(link_preview_options_t *link_preview_options);

link_preview_options_t *link_preview_options_parseFromJSON(cJSON *link_preview_optionsJSON);

cJSON *link_preview_options_convertToJSON(link_preview_options_t *link_preview_options);

#endif /* _link_preview_options_H_ */

