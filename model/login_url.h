/*
 * login_url.h
 *
 * This object represents a parameter of the inline keyboard button used to automatically authorize a user. Serves as a great replacement for the [Telegram Login Widget](https://core.telegram.org/widgets/login) when the user is coming from Telegram. All the user needs to do is tap/click a button and confirm that they want to log in:  Telegram apps support these buttons as of [version 5.7](https://telegram.org/blog/privacy-discussions-web-bots#meet-seamless-web-bots).  Sample bot: [@discussbot](https://t.me/discussbot)
 */

#ifndef _login_url_H_
#define _login_url_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct login_url_t login_url_t;




typedef struct login_url_t {
    char *url; // string
    char *forward_text; // string
    char *bot_username; // string
    int request_write_access; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} login_url_t;

__attribute__((deprecated)) login_url_t *login_url_create(
    char *url,
    char *forward_text,
    char *bot_username,
    int request_write_access
);

void login_url_free(login_url_t *login_url);

login_url_t *login_url_parseFromJSON(cJSON *login_urlJSON);

cJSON *login_url_convertToJSON(login_url_t *login_url);

#endif /* _login_url_H_ */

