/*
 * reaction_type_emoji.h
 *
 * The reaction is based on an emoji.
 */

#ifndef _reaction_type_emoji_H_
#define _reaction_type_emoji_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct reaction_type_emoji_t reaction_type_emoji_t;


// Enum EMOJI for reaction_type_emoji

typedef enum  { telegram_bot_api_reaction_type_emoji_EMOJI_NULL = 0, telegram_bot_api_reaction_type_emoji_EMOJI_❤, telegram_bot_api_reaction_type_emoji_EMOJI_👍, telegram_bot_api_reaction_type_emoji_EMOJI_👎, telegram_bot_api_reaction_type_emoji_EMOJI_🔥, telegram_bot_api_reaction_type_emoji_EMOJI_🥰, telegram_bot_api_reaction_type_emoji_EMOJI_👏, telegram_bot_api_reaction_type_emoji_EMOJI_😁, telegram_bot_api_reaction_type_emoji_EMOJI_🤔, telegram_bot_api_reaction_type_emoji_EMOJI_🤯, telegram_bot_api_reaction_type_emoji_EMOJI_😱, telegram_bot_api_reaction_type_emoji_EMOJI_🤬, telegram_bot_api_reaction_type_emoji_EMOJI_😢, telegram_bot_api_reaction_type_emoji_EMOJI_🎉, telegram_bot_api_reaction_type_emoji_EMOJI_🤩, telegram_bot_api_reaction_type_emoji_EMOJI_🤮, telegram_bot_api_reaction_type_emoji_EMOJI_💩, telegram_bot_api_reaction_type_emoji_EMOJI_🙏, telegram_bot_api_reaction_type_emoji_EMOJI_👌, telegram_bot_api_reaction_type_emoji_EMOJI_🕊, telegram_bot_api_reaction_type_emoji_EMOJI_🤡, telegram_bot_api_reaction_type_emoji_EMOJI_🥱, telegram_bot_api_reaction_type_emoji_EMOJI_🥴, telegram_bot_api_reaction_type_emoji_EMOJI_😍, telegram_bot_api_reaction_type_emoji_EMOJI_🐳, telegram_bot_api_reaction_type_emoji_EMOJI_❤‍🔥, telegram_bot_api_reaction_type_emoji_EMOJI_🌚, telegram_bot_api_reaction_type_emoji_EMOJI_🌭, telegram_bot_api_reaction_type_emoji_EMOJI_💯, telegram_bot_api_reaction_type_emoji_EMOJI_🤣, telegram_bot_api_reaction_type_emoji_EMOJI_⚡, telegram_bot_api_reaction_type_emoji_EMOJI_🍌, telegram_bot_api_reaction_type_emoji_EMOJI_🏆, telegram_bot_api_reaction_type_emoji_EMOJI_💔, telegram_bot_api_reaction_type_emoji_EMOJI_🤨, telegram_bot_api_reaction_type_emoji_EMOJI_😐, telegram_bot_api_reaction_type_emoji_EMOJI_🍓, telegram_bot_api_reaction_type_emoji_EMOJI_🍾, telegram_bot_api_reaction_type_emoji_EMOJI_💋, telegram_bot_api_reaction_type_emoji_EMOJI_🖕, telegram_bot_api_reaction_type_emoji_EMOJI_😈, telegram_bot_api_reaction_type_emoji_EMOJI_😴, telegram_bot_api_reaction_type_emoji_EMOJI_😭, telegram_bot_api_reaction_type_emoji_EMOJI_🤓, telegram_bot_api_reaction_type_emoji_EMOJI_👻, telegram_bot_api_reaction_type_emoji_EMOJI_👨‍💻, telegram_bot_api_reaction_type_emoji_EMOJI_👀, telegram_bot_api_reaction_type_emoji_EMOJI_🎃, telegram_bot_api_reaction_type_emoji_EMOJI_🙈, telegram_bot_api_reaction_type_emoji_EMOJI_😇, telegram_bot_api_reaction_type_emoji_EMOJI_😨, telegram_bot_api_reaction_type_emoji_EMOJI_🤝, telegram_bot_api_reaction_type_emoji_EMOJI_✍, telegram_bot_api_reaction_type_emoji_EMOJI_🤗, telegram_bot_api_reaction_type_emoji_EMOJI_🫡, telegram_bot_api_reaction_type_emoji_EMOJI_🎅, telegram_bot_api_reaction_type_emoji_EMOJI_🎄, telegram_bot_api_reaction_type_emoji_EMOJI_☃, telegram_bot_api_reaction_type_emoji_EMOJI_💅, telegram_bot_api_reaction_type_emoji_EMOJI_🤪, telegram_bot_api_reaction_type_emoji_EMOJI_🗿, telegram_bot_api_reaction_type_emoji_EMOJI_🆒, telegram_bot_api_reaction_type_emoji_EMOJI_💘, telegram_bot_api_reaction_type_emoji_EMOJI_🙉, telegram_bot_api_reaction_type_emoji_EMOJI_🦄, telegram_bot_api_reaction_type_emoji_EMOJI_😘, telegram_bot_api_reaction_type_emoji_EMOJI_💊, telegram_bot_api_reaction_type_emoji_EMOJI_🙊, telegram_bot_api_reaction_type_emoji_EMOJI_😎, telegram_bot_api_reaction_type_emoji_EMOJI_👾, telegram_bot_api_reaction_type_emoji_EMOJI_🤷‍♂, telegram_bot_api_reaction_type_emoji_EMOJI_🤷, telegram_bot_api_reaction_type_emoji_EMOJI_🤷‍♀, telegram_bot_api_reaction_type_emoji_EMOJI_😡 } telegram_bot_api_reaction_type_emoji_EMOJI_e;

char* reaction_type_emoji_emoji_ToString(telegram_bot_api_reaction_type_emoji_EMOJI_e emoji);

telegram_bot_api_reaction_type_emoji_EMOJI_e reaction_type_emoji_emoji_FromString(char* emoji);



typedef struct reaction_type_emoji_t {
    char *type; // string
    telegram_bot_api_reaction_type_emoji_EMOJI_e emoji; //enum

    int _library_owned; // Is the library responsible for freeing this object?
} reaction_type_emoji_t;

__attribute__((deprecated)) reaction_type_emoji_t *reaction_type_emoji_create(
    char *type,
    telegram_bot_api_reaction_type_emoji_EMOJI_e emoji
);

void reaction_type_emoji_free(reaction_type_emoji_t *reaction_type_emoji);

reaction_type_emoji_t *reaction_type_emoji_parseFromJSON(cJSON *reaction_type_emojiJSON);

cJSON *reaction_type_emoji_convertToJSON(reaction_type_emoji_t *reaction_type_emoji);

#endif /* _reaction_type_emoji_H_ */

