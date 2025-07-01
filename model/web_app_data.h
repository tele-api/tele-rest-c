/*
 * web_app_data.h
 *
 * Describes data sent from a [Web App](https://core.telegram.org/bots/webapps) to the bot.
 */

#ifndef _web_app_data_H_
#define _web_app_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct web_app_data_t web_app_data_t;




typedef struct web_app_data_t {
    char *data; // string
    char *button_text; // string

    int _library_owned; // Is the library responsible for freeing this object?
} web_app_data_t;

__attribute__((deprecated)) web_app_data_t *web_app_data_create(
    char *data,
    char *button_text
);

void web_app_data_free(web_app_data_t *web_app_data);

web_app_data_t *web_app_data_parseFromJSON(cJSON *web_app_dataJSON);

cJSON *web_app_data_convertToJSON(web_app_data_t *web_app_data);

#endif /* _web_app_data_H_ */

