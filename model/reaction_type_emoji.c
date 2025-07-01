#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "reaction_type_emoji.h"


char* reaction_type_emoji_emoji_ToString(telegram_bot_api_reaction_type_emoji_EMOJI_e emoji) {
    char* emojiArray[] =  { "NULL", "❤", "👍", "👎", "🔥", "🥰", "👏", "😁", "🤔", "🤯", "😱", "🤬", "😢", "🎉", "🤩", "🤮", "💩", "🙏", "👌", "🕊", "🤡", "🥱", "🥴", "😍", "🐳", "❤‍🔥", "🌚", "🌭", "💯", "🤣", "⚡", "🍌", "🏆", "💔", "🤨", "😐", "🍓", "🍾", "💋", "🖕", "😈", "😴", "😭", "🤓", "👻", "👨‍💻", "👀", "🎃", "🙈", "😇", "😨", "🤝", "✍", "🤗", "🫡", "🎅", "🎄", "☃", "💅", "🤪", "🗿", "🆒", "💘", "🙉", "🦄", "😘", "💊", "🙊", "😎", "👾", "🤷‍♂", "🤷", "🤷‍♀", "😡" };
    return emojiArray[emoji];
}

telegram_bot_api_reaction_type_emoji_EMOJI_e reaction_type_emoji_emoji_FromString(char* emoji){
    int stringToReturn = 0;
    char *emojiArray[] =  { "NULL", "❤", "👍", "👎", "🔥", "🥰", "👏", "😁", "🤔", "🤯", "😱", "🤬", "😢", "🎉", "🤩", "🤮", "💩", "🙏", "👌", "🕊", "🤡", "🥱", "🥴", "😍", "🐳", "❤‍🔥", "🌚", "🌭", "💯", "🤣", "⚡", "🍌", "🏆", "💔", "🤨", "😐", "🍓", "🍾", "💋", "🖕", "😈", "😴", "😭", "🤓", "👻", "👨‍💻", "👀", "🎃", "🙈", "😇", "😨", "🤝", "✍", "🤗", "🫡", "🎅", "🎄", "☃", "💅", "🤪", "🗿", "🆒", "💘", "🙉", "🦄", "😘", "💊", "🙊", "😎", "👾", "🤷‍♂", "🤷", "🤷‍♀", "😡" };
    size_t sizeofArray = sizeof(emojiArray) / sizeof(emojiArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(emoji, emojiArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static reaction_type_emoji_t *reaction_type_emoji_create_internal(
    char *type,
    telegram_bot_api_reaction_type_emoji_EMOJI_e emoji
    ) {
    reaction_type_emoji_t *reaction_type_emoji_local_var = malloc(sizeof(reaction_type_emoji_t));
    if (!reaction_type_emoji_local_var) {
        return NULL;
    }
    reaction_type_emoji_local_var->type = type;
    reaction_type_emoji_local_var->emoji = emoji;

    reaction_type_emoji_local_var->_library_owned = 1;
    return reaction_type_emoji_local_var;
}

__attribute__((deprecated)) reaction_type_emoji_t *reaction_type_emoji_create(
    char *type,
    telegram_bot_api_reaction_type_emoji_EMOJI_e emoji
    ) {
    return reaction_type_emoji_create_internal (
        type,
        emoji
        );
}

void reaction_type_emoji_free(reaction_type_emoji_t *reaction_type_emoji) {
    if(NULL == reaction_type_emoji){
        return ;
    }
    if(reaction_type_emoji->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "reaction_type_emoji_free");
        return ;
    }
    listEntry_t *listEntry;
    if (reaction_type_emoji->type) {
        free(reaction_type_emoji->type);
        reaction_type_emoji->type = NULL;
    }
    free(reaction_type_emoji);
}

cJSON *reaction_type_emoji_convertToJSON(reaction_type_emoji_t *reaction_type_emoji) {
    cJSON *item = cJSON_CreateObject();

    // reaction_type_emoji->type
    if (!reaction_type_emoji->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", reaction_type_emoji->type) == NULL) {
    goto fail; //String
    }


    // reaction_type_emoji->emoji
    if (telegram_bot_api_reaction_type_emoji_EMOJI_NULL == reaction_type_emoji->emoji) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "emoji", reaction_type_emoji_emoji_ToString(reaction_type_emoji->emoji)) == NULL)
    {
    goto fail; //Enum
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

reaction_type_emoji_t *reaction_type_emoji_parseFromJSON(cJSON *reaction_type_emojiJSON){

    reaction_type_emoji_t *reaction_type_emoji_local_var = NULL;

    // reaction_type_emoji->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(reaction_type_emojiJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }

    // reaction_type_emoji->emoji
    cJSON *emoji = cJSON_GetObjectItemCaseSensitive(reaction_type_emojiJSON, "emoji");
    if (cJSON_IsNull(emoji)) {
        emoji = NULL;
    }
    if (!emoji) {
        goto end;
    }

    telegram_bot_api_reaction_type_emoji_EMOJI_e emojiVariable;
    
    if(!cJSON_IsString(emoji))
    {
    goto end; //Enum
    }
    emojiVariable = reaction_type_emoji_emoji_FromString(emoji->valuestring);


    reaction_type_emoji_local_var = reaction_type_emoji_create_internal (
        strdup(type->valuestring),
        emojiVariable
        );

    return reaction_type_emoji_local_var;
end:
    return NULL;

}
