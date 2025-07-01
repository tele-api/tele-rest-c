/*
 * transaction_partner_chat.h
 *
 * Describes a transaction with a chat.
 */

#ifndef _transaction_partner_chat_H_
#define _transaction_partner_chat_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct transaction_partner_chat_t transaction_partner_chat_t;

#include "chat.h"
#include "gift.h"



typedef struct transaction_partner_chat_t {
    char *type; // string
    struct chat_t *chat; //model
    struct gift_t *gift; //model

    int _library_owned; // Is the library responsible for freeing this object?
} transaction_partner_chat_t;

__attribute__((deprecated)) transaction_partner_chat_t *transaction_partner_chat_create(
    char *type,
    chat_t *chat,
    gift_t *gift
);

void transaction_partner_chat_free(transaction_partner_chat_t *transaction_partner_chat);

transaction_partner_chat_t *transaction_partner_chat_parseFromJSON(cJSON *transaction_partner_chatJSON);

cJSON *transaction_partner_chat_convertToJSON(transaction_partner_chat_t *transaction_partner_chat);

#endif /* _transaction_partner_chat_H_ */

