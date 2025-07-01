/*
 * business_connection.h
 *
 * Describes the connection of the bot with a business account.
 */

#ifndef _business_connection_H_
#define _business_connection_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct business_connection_t business_connection_t;

#include "business_bot_rights.h"
#include "user.h"



typedef struct business_connection_t {
    char *id; // string
    struct user_t *user; //model
    int user_chat_id; //numeric
    int date; //numeric
    int is_enabled; //boolean
    struct business_bot_rights_t *rights; //model

    int _library_owned; // Is the library responsible for freeing this object?
} business_connection_t;

__attribute__((deprecated)) business_connection_t *business_connection_create(
    char *id,
    user_t *user,
    int user_chat_id,
    int date,
    int is_enabled,
    business_bot_rights_t *rights
);

void business_connection_free(business_connection_t *business_connection);

business_connection_t *business_connection_parseFromJSON(cJSON *business_connectionJSON);

cJSON *business_connection_convertToJSON(business_connection_t *business_connection);

#endif /* _business_connection_H_ */

