/*
 * inline_query_results_button.h
 *
 * This object represents a button to be shown above inline query results. You **must** use exactly one of the optional fields.
 */

#ifndef _inline_query_results_button_H_
#define _inline_query_results_button_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct inline_query_results_button_t inline_query_results_button_t;

#include "web_app_info.h"



typedef struct inline_query_results_button_t {
    char *text; // string
    struct web_app_info_t *web_app; //model
    char *start_parameter; // string

    int _library_owned; // Is the library responsible for freeing this object?
} inline_query_results_button_t;

__attribute__((deprecated)) inline_query_results_button_t *inline_query_results_button_create(
    char *text,
    web_app_info_t *web_app,
    char *start_parameter
);

void inline_query_results_button_free(inline_query_results_button_t *inline_query_results_button);

inline_query_results_button_t *inline_query_results_button_parseFromJSON(cJSON *inline_query_results_buttonJSON);

cJSON *inline_query_results_button_convertToJSON(inline_query_results_button_t *inline_query_results_button);

#endif /* _inline_query_results_button_H_ */

