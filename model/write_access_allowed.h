/*
 * write_access_allowed.h
 *
 * This object represents a service message about a user allowing a bot to write messages after adding it to the attachment menu, launching a Web App from a link, or accepting an explicit request from a Web App sent by the method [requestWriteAccess](https://core.telegram.org/bots/webapps#initializing-mini-apps).
 */

#ifndef _write_access_allowed_H_
#define _write_access_allowed_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct write_access_allowed_t write_access_allowed_t;




typedef struct write_access_allowed_t {
    int from_request; //boolean
    char *web_app_name; // string
    int from_attachment_menu; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} write_access_allowed_t;

__attribute__((deprecated)) write_access_allowed_t *write_access_allowed_create(
    int from_request,
    char *web_app_name,
    int from_attachment_menu
);

void write_access_allowed_free(write_access_allowed_t *write_access_allowed);

write_access_allowed_t *write_access_allowed_parseFromJSON(cJSON *write_access_allowedJSON);

cJSON *write_access_allowed_convertToJSON(write_access_allowed_t *write_access_allowed);

#endif /* _write_access_allowed_H_ */

