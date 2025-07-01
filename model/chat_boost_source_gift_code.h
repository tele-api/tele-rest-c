/*
 * chat_boost_source_gift_code.h
 *
 * The boost was obtained by the creation of Telegram Premium gift codes to boost a chat. Each such code boosts the chat 4 times for the duration of the corresponding Telegram Premium subscription.
 */

#ifndef _chat_boost_source_gift_code_H_
#define _chat_boost_source_gift_code_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct chat_boost_source_gift_code_t chat_boost_source_gift_code_t;

#include "user.h"



typedef struct chat_boost_source_gift_code_t {
    char *source; // string
    struct user_t *user; //model

    int _library_owned; // Is the library responsible for freeing this object?
} chat_boost_source_gift_code_t;

__attribute__((deprecated)) chat_boost_source_gift_code_t *chat_boost_source_gift_code_create(
    char *source,
    user_t *user
);

void chat_boost_source_gift_code_free(chat_boost_source_gift_code_t *chat_boost_source_gift_code);

chat_boost_source_gift_code_t *chat_boost_source_gift_code_parseFromJSON(cJSON *chat_boost_source_gift_codeJSON);

cJSON *chat_boost_source_gift_code_convertToJSON(chat_boost_source_gift_code_t *chat_boost_source_gift_code);

#endif /* _chat_boost_source_gift_code_H_ */

