/*
 * user.h
 *
 * This object represents a Telegram user or bot.
 */

#ifndef _user_H_
#define _user_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct user_t user_t;




typedef struct user_t {
    int id; //numeric
    int is_bot; //boolean
    char *first_name; // string
    char *last_name; // string
    char *username; // string
    char *language_code; // string
    int is_premium; //boolean
    int added_to_attachment_menu; //boolean
    int can_join_groups; //boolean
    int can_read_all_group_messages; //boolean
    int supports_inline_queries; //boolean
    int can_connect_to_business; //boolean
    int has_main_web_app; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} user_t;

__attribute__((deprecated)) user_t *user_create(
    int id,
    int is_bot,
    char *first_name,
    char *last_name,
    char *username,
    char *language_code,
    int is_premium,
    int added_to_attachment_menu,
    int can_join_groups,
    int can_read_all_group_messages,
    int supports_inline_queries,
    int can_connect_to_business,
    int has_main_web_app
);

void user_free(user_t *user);

user_t *user_parseFromJSON(cJSON *userJSON);

cJSON *user_convertToJSON(user_t *user);

#endif /* _user_H_ */

