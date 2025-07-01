#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "reaction_type.h"


char* reaction_type_emoji_ToString(telegram_bot_api_reaction_type_EMOJI_e emoji) {
    char* emojiArray[] =  { "NULL", "❤", "👍", "👎", "🔥", "🥰", "👏", "😁", "🤔", "🤯", "😱", "🤬", "😢", "🎉", "🤩", "🤮", "💩", "🙏", "👌", "🕊", "🤡", "🥱", "🥴", "😍", "🐳", "❤‍🔥", "🌚", "🌭", "💯", "🤣", "⚡", "🍌", "🏆", "💔", "🤨", "😐", "🍓", "🍾", "💋", "🖕", "😈", "😴", "😭", "🤓", "👻", "👨‍💻", "👀", "🎃", "🙈", "😇", "😨", "🤝", "✍", "🤗", "🫡", "🎅", "🎄", "☃", "💅", "🤪", "🗿", "🆒", "💘", "🙉", "🦄", "😘", "💊", "🙊", "😎", "👾", "🤷‍♂", "🤷", "🤷‍♀", "😡" };
    return emojiArray[emoji];
}

telegram_bot_api_reaction_type_EMOJI_e reaction_type_emoji_FromString(char* emoji){
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

static reaction_type_t *reaction_type_create_internal(
    char *type,
    telegram_bot_api_reaction_type_EMOJI_e emoji,
    char *custom_emoji_id
    ) {
    reaction_type_t *reaction_type_local_var = malloc(sizeof(reaction_type_t));
    if (!reaction_type_local_var) {
        return NULL;
    }
    reaction_type_local_var->type = type;
    reaction_type_local_var->emoji = emoji;
    reaction_type_local_var->custom_emoji_id = custom_emoji_id;

    reaction_type_local_var->_library_owned = 1;
    return reaction_type_local_var;
}

__attribute__((deprecated)) reaction_type_t *reaction_type_create(
    char *type,
    telegram_bot_api_reaction_type_EMOJI_e emoji,
    char *custom_emoji_id
    ) {
    return reaction_type_create_internal (
        type,
        emoji,
        custom_emoji_id
        );
}

void reaction_type_free(reaction_type_t *reaction_type) {
    if(NULL == reaction_type){
        return ;
    }
    if(reaction_type->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "reaction_type_free");
        return ;
    }
    listEntry_t *listEntry;
    if (reaction_type->type) {
        free(reaction_type->type);
        reaction_type->type = NULL;
    }
    if (reaction_type->custom_emoji_id) {
        free(reaction_type->custom_emoji_id);
        reaction_type->custom_emoji_id = NULL;
    }
    free(reaction_type);
}

cJSON *reaction_type_convertToJSON(reaction_type_t *reaction_type) {
    cJSON *item = cJSON_CreateObject();

    // reaction_type->type
    if (!reaction_type->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", reaction_type->type) == NULL) {
    goto fail; //String
    }


    // reaction_type->emoji
    if (telegram_bot_api_reaction_type_EMOJI_NULL == reaction_type->emoji) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "emoji", reaction_type_emoji_ToString(reaction_type->emoji)) == NULL)
    {
    goto fail; //Enum
    }


    // reaction_type->custom_emoji_id
    if (!reaction_type->custom_emoji_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "custom_emoji_id", reaction_type->custom_emoji_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

reaction_type_t *reaction_type_parseFromJSON(cJSON *reaction_typeJSON){

    reaction_type_t *reaction_type_local_var = NULL;

    // reaction_type->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(reaction_typeJSON, "type");
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

    // reaction_type->emoji
    cJSON *emoji = cJSON_GetObjectItemCaseSensitive(reaction_typeJSON, "emoji");
    if (cJSON_IsNull(emoji)) {
        emoji = NULL;
    }
    if (!emoji) {
        goto end;
    }

    telegram_bot_api_reaction_type_EMOJI_e emojiVariable;
    
    if(!cJSON_IsString(emoji))
    {
    goto end; //Enum
    }
    emojiVariable = reaction_type_emoji_FromString(emoji->valuestring);

    // reaction_type->custom_emoji_id
    cJSON *custom_emoji_id = cJSON_GetObjectItemCaseSensitive(reaction_typeJSON, "custom_emoji_id");
    if (cJSON_IsNull(custom_emoji_id)) {
        custom_emoji_id = NULL;
    }
    if (!custom_emoji_id) {
        goto end;
    }

    
    if(!cJSON_IsString(custom_emoji_id))
    {
    goto end; //String
    }


    reaction_type_local_var = reaction_type_create_internal (
        strdup(type->valuestring),
        emojiVariable,
        strdup(custom_emoji_id->valuestring)
        );

    return reaction_type_local_var;
end:
    return NULL;

}
