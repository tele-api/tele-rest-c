/*
 * keyboard_button_request_chat.h
 *
 * This object defines the criteria used to request a suitable chat. Information about the selected chat will be shared with the bot when the corresponding button is pressed. The bot will be granted requested rights in the chat if appropriate. [More about requesting chats »](https://core.telegram.org/bots/features#chat-and-user-selection).
 */

#ifndef _keyboard_button_request_chat_H_
#define _keyboard_button_request_chat_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct keyboard_button_request_chat_t keyboard_button_request_chat_t;

#include "chat_administrator_rights.h"



typedef struct keyboard_button_request_chat_t {
    int request_id; //numeric
    int chat_is_channel; //boolean
    int chat_is_forum; //boolean
    int chat_has_username; //boolean
    int chat_is_created; //boolean
    struct chat_administrator_rights_t *user_administrator_rights; //model
    struct chat_administrator_rights_t *bot_administrator_rights; //model
    int bot_is_member; //boolean
    int request_title; //boolean
    int request_username; //boolean
    int request_photo; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} keyboard_button_request_chat_t;

__attribute__((deprecated)) keyboard_button_request_chat_t *keyboard_button_request_chat_create(
    int request_id,
    int chat_is_channel,
    int chat_is_forum,
    int chat_has_username,
    int chat_is_created,
    chat_administrator_rights_t *user_administrator_rights,
    chat_administrator_rights_t *bot_administrator_rights,
    int bot_is_member,
    int request_title,
    int request_username,
    int request_photo
);

void keyboard_button_request_chat_free(keyboard_button_request_chat_t *keyboard_button_request_chat);

keyboard_button_request_chat_t *keyboard_button_request_chat_parseFromJSON(cJSON *keyboard_button_request_chatJSON);

cJSON *keyboard_button_request_chat_convertToJSON(keyboard_button_request_chat_t *keyboard_button_request_chat);

#endif /* _keyboard_button_request_chat_H_ */

