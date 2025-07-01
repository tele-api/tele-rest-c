/*
 * reply_keyboard_remove.h
 *
 * Upon receiving a message with this object, Telegram clients will remove the current custom keyboard and display the default letter-keyboard. By default, custom keyboards are displayed until a new keyboard is sent by a bot. An exception is made for one-time keyboards that are hidden immediately after the user presses a button (see [ReplyKeyboardMarkup](https://core.telegram.org/bots/api/#replykeyboardmarkup)). Not supported in channels and for messages sent on behalf of a Telegram Business account.
 */

#ifndef _reply_keyboard_remove_H_
#define _reply_keyboard_remove_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct reply_keyboard_remove_t reply_keyboard_remove_t;




typedef struct reply_keyboard_remove_t {
    int remove_keyboard; //boolean
    int selective; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} reply_keyboard_remove_t;

__attribute__((deprecated)) reply_keyboard_remove_t *reply_keyboard_remove_create(
    int remove_keyboard,
    int selective
);

void reply_keyboard_remove_free(reply_keyboard_remove_t *reply_keyboard_remove);

reply_keyboard_remove_t *reply_keyboard_remove_parseFromJSON(cJSON *reply_keyboard_removeJSON);

cJSON *reply_keyboard_remove_convertToJSON(reply_keyboard_remove_t *reply_keyboard_remove);

#endif /* _reply_keyboard_remove_H_ */

