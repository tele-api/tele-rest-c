/*
 * reaction_type.h
 *
 * This object describes the type of a reaction. Currently, it can be one of  * [ReactionTypeEmoji](https://core.telegram.org/bots/api/#reactiontypeemoji) * [ReactionTypeCustomEmoji](https://core.telegram.org/bots/api/#reactiontypecustomemoji) * [ReactionTypePaid](https://core.telegram.org/bots/api/#reactiontypepaid)
 */

#ifndef _reaction_type_H_
#define _reaction_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct reaction_type_t reaction_type_t;

#include "reaction_type_custom_emoji.h"
#include "reaction_type_emoji.h"
#include "reaction_type_paid.h"

// Enum EMOJI for reaction_type

typedef enum  { telegram_bot_api_reaction_type_EMOJI_NULL = 0, telegram_bot_api_reaction_type_EMOJI_❤, telegram_bot_api_reaction_type_EMOJI_👍, telegram_bot_api_reaction_type_EMOJI_👎, telegram_bot_api_reaction_type_EMOJI_🔥, telegram_bot_api_reaction_type_EMOJI_🥰, telegram_bot_api_reaction_type_EMOJI_👏, telegram_bot_api_reaction_type_EMOJI_😁, telegram_bot_api_reaction_type_EMOJI_🤔, telegram_bot_api_reaction_type_EMOJI_🤯, telegram_bot_api_reaction_type_EMOJI_😱, telegram_bot_api_reaction_type_EMOJI_🤬, telegram_bot_api_reaction_type_EMOJI_😢, telegram_bot_api_reaction_type_EMOJI_🎉, telegram_bot_api_reaction_type_EMOJI_🤩, telegram_bot_api_reaction_type_EMOJI_🤮, telegram_bot_api_reaction_type_EMOJI_💩, telegram_bot_api_reaction_type_EMOJI_🙏, telegram_bot_api_reaction_type_EMOJI_👌, telegram_bot_api_reaction_type_EMOJI_🕊, telegram_bot_api_reaction_type_EMOJI_🤡, telegram_bot_api_reaction_type_EMOJI_🥱, telegram_bot_api_reaction_type_EMOJI_🥴, telegram_bot_api_reaction_type_EMOJI_😍, telegram_bot_api_reaction_type_EMOJI_🐳, telegram_bot_api_reaction_type_EMOJI_❤‍🔥, telegram_bot_api_reaction_type_EMOJI_🌚, telegram_bot_api_reaction_type_EMOJI_🌭, telegram_bot_api_reaction_type_EMOJI_💯, telegram_bot_api_reaction_type_EMOJI_🤣, telegram_bot_api_reaction_type_EMOJI_⚡, telegram_bot_api_reaction_type_EMOJI_🍌, telegram_bot_api_reaction_type_EMOJI_🏆, telegram_bot_api_reaction_type_EMOJI_💔, telegram_bot_api_reaction_type_EMOJI_🤨, telegram_bot_api_reaction_type_EMOJI_😐, telegram_bot_api_reaction_type_EMOJI_🍓, telegram_bot_api_reaction_type_EMOJI_🍾, telegram_bot_api_reaction_type_EMOJI_💋, telegram_bot_api_reaction_type_EMOJI_🖕, telegram_bot_api_reaction_type_EMOJI_😈, telegram_bot_api_reaction_type_EMOJI_😴, telegram_bot_api_reaction_type_EMOJI_😭, telegram_bot_api_reaction_type_EMOJI_🤓, telegram_bot_api_reaction_type_EMOJI_👻, telegram_bot_api_reaction_type_EMOJI_👨‍💻, telegram_bot_api_reaction_type_EMOJI_👀, telegram_bot_api_reaction_type_EMOJI_🎃, telegram_bot_api_reaction_type_EMOJI_🙈, telegram_bot_api_reaction_type_EMOJI_😇, telegram_bot_api_reaction_type_EMOJI_😨, telegram_bot_api_reaction_type_EMOJI_🤝, telegram_bot_api_reaction_type_EMOJI_✍, telegram_bot_api_reaction_type_EMOJI_🤗, telegram_bot_api_reaction_type_EMOJI_🫡, telegram_bot_api_reaction_type_EMOJI_🎅, telegram_bot_api_reaction_type_EMOJI_🎄, telegram_bot_api_reaction_type_EMOJI_☃, telegram_bot_api_reaction_type_EMOJI_💅, telegram_bot_api_reaction_type_EMOJI_🤪, telegram_bot_api_reaction_type_EMOJI_🗿, telegram_bot_api_reaction_type_EMOJI_🆒, telegram_bot_api_reaction_type_EMOJI_💘, telegram_bot_api_reaction_type_EMOJI_🙉, telegram_bot_api_reaction_type_EMOJI_🦄, telegram_bot_api_reaction_type_EMOJI_😘, telegram_bot_api_reaction_type_EMOJI_💊, telegram_bot_api_reaction_type_EMOJI_🙊, telegram_bot_api_reaction_type_EMOJI_😎, telegram_bot_api_reaction_type_EMOJI_👾, telegram_bot_api_reaction_type_EMOJI_🤷‍♂, telegram_bot_api_reaction_type_EMOJI_🤷, telegram_bot_api_reaction_type_EMOJI_🤷‍♀, telegram_bot_api_reaction_type_EMOJI_😡 } telegram_bot_api_reaction_type_EMOJI_e;

char* reaction_type_emoji_ToString(telegram_bot_api_reaction_type_EMOJI_e emoji);

telegram_bot_api_reaction_type_EMOJI_e reaction_type_emoji_FromString(char* emoji);



typedef struct reaction_type_t {
    char *type; // string
    telegram_bot_api_reaction_type_EMOJI_e emoji; //enum
    char *custom_emoji_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} reaction_type_t;

__attribute__((deprecated)) reaction_type_t *reaction_type_create(
    char *type,
    telegram_bot_api_reaction_type_EMOJI_e emoji,
    char *custom_emoji_id
);

void reaction_type_free(reaction_type_t *reaction_type);

reaction_type_t *reaction_type_parseFromJSON(cJSON *reaction_typeJSON);

cJSON *reaction_type_convertToJSON(reaction_type_t *reaction_type);

#endif /* _reaction_type_H_ */

