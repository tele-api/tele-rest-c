/*
 * bot_command_scope.h
 *
 * This object represents the scope to which bot commands are applied. Currently, the following 7 scopes are supported:  * [BotCommandScopeDefault](https://core.telegram.org/bots/api/#botcommandscopedefault) * [BotCommandScopeAllPrivateChats](https://core.telegram.org/bots/api/#botcommandscopeallprivatechats) * [BotCommandScopeAllGroupChats](https://core.telegram.org/bots/api/#botcommandscopeallgroupchats) * [BotCommandScopeAllChatAdministrators](https://core.telegram.org/bots/api/#botcommandscopeallchatadministrators) * [BotCommandScopeChat](https://core.telegram.org/bots/api/#botcommandscopechat) * [BotCommandScopeChatAdministrators](https://core.telegram.org/bots/api/#botcommandscopechatadministrators) * [BotCommandScopeChatMember](https://core.telegram.org/bots/api/#botcommandscopechatmember)
 */

#ifndef _bot_command_scope_H_
#define _bot_command_scope_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct bot_command_scope_t bot_command_scope_t;

#include "bot_command_scope_all_chat_administrators.h"
#include "bot_command_scope_all_group_chats.h"
#include "bot_command_scope_all_private_chats.h"
#include "bot_command_scope_chat.h"
#include "bot_command_scope_chat_administrators.h"
#include "bot_command_scope_chat_chat_id.h"
#include "bot_command_scope_chat_member.h"
#include "bot_command_scope_default.h"



typedef struct bot_command_scope_t {
    char *type; // string
    struct bot_command_scope_chat_chat_id_t *chat_id; //model
    int user_id; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} bot_command_scope_t;

__attribute__((deprecated)) bot_command_scope_t *bot_command_scope_create(
    char *type,
    bot_command_scope_chat_chat_id_t *chat_id,
    int user_id
);

void bot_command_scope_free(bot_command_scope_t *bot_command_scope);

bot_command_scope_t *bot_command_scope_parseFromJSON(cJSON *bot_command_scopeJSON);

cJSON *bot_command_scope_convertToJSON(bot_command_scope_t *bot_command_scope);

#endif /* _bot_command_scope_H_ */

