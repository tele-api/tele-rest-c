/*
 * sent_web_app_message.h
 *
 * Describes an inline message sent by a [Web App](https://core.telegram.org/bots/webapps) on behalf of a user.
 */

#ifndef _sent_web_app_message_H_
#define _sent_web_app_message_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct sent_web_app_message_t sent_web_app_message_t;




typedef struct sent_web_app_message_t {
    char *inline_message_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} sent_web_app_message_t;

__attribute__((deprecated)) sent_web_app_message_t *sent_web_app_message_create(
    char *inline_message_id
);

void sent_web_app_message_free(sent_web_app_message_t *sent_web_app_message);

sent_web_app_message_t *sent_web_app_message_parseFromJSON(cJSON *sent_web_app_messageJSON);

cJSON *sent_web_app_message_convertToJSON(sent_web_app_message_t *sent_web_app_message);

#endif /* _sent_web_app_message_H_ */

