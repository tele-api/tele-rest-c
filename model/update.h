/*
 * update.h
 *
 * This [object](https://core.telegram.org/bots/api/#available-types) represents an incoming update.   At most **one** of the optional parameters can be present in any given update.
 */

#ifndef _update_H_
#define _update_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct update_t update_t;

#include "business_connection.h"
#include "business_messages_deleted.h"
#include "callback_query.h"
#include "chat_boost_removed.h"
#include "chat_boost_updated.h"
#include "chat_join_request.h"
#include "chat_member_updated.h"
#include "chosen_inline_result.h"
#include "inline_query.h"
#include "message.h"
#include "message_reaction_count_updated.h"
#include "message_reaction_updated.h"
#include "paid_media_purchased.h"
#include "poll.h"
#include "poll_answer.h"
#include "pre_checkout_query.h"
#include "shipping_query.h"



typedef struct update_t {
    int update_id; //numeric
    struct message_t *message; //model
    struct message_t *edited_message; //model
    struct message_t *channel_post; //model
    struct message_t *edited_channel_post; //model
    struct business_connection_t *business_connection; //model
    struct message_t *business_message; //model
    struct message_t *edited_business_message; //model
    struct business_messages_deleted_t *deleted_business_messages; //model
    struct message_reaction_updated_t *message_reaction; //model
    struct message_reaction_count_updated_t *message_reaction_count; //model
    struct inline_query_t *inline_query; //model
    struct chosen_inline_result_t *chosen_inline_result; //model
    struct callback_query_t *callback_query; //model
    struct shipping_query_t *shipping_query; //model
    struct pre_checkout_query_t *pre_checkout_query; //model
    struct paid_media_purchased_t *purchased_paid_media; //model
    struct poll_t *poll; //model
    struct poll_answer_t *poll_answer; //model
    struct chat_member_updated_t *my_chat_member; //model
    struct chat_member_updated_t *chat_member; //model
    struct chat_join_request_t *chat_join_request; //model
    struct chat_boost_updated_t *chat_boost; //model
    struct chat_boost_removed_t *removed_chat_boost; //model

    int _library_owned; // Is the library responsible for freeing this object?
} update_t;

__attribute__((deprecated)) update_t *update_create(
    int update_id,
    message_t *message,
    message_t *edited_message,
    message_t *channel_post,
    message_t *edited_channel_post,
    business_connection_t *business_connection,
    message_t *business_message,
    message_t *edited_business_message,
    business_messages_deleted_t *deleted_business_messages,
    message_reaction_updated_t *message_reaction,
    message_reaction_count_updated_t *message_reaction_count,
    inline_query_t *inline_query,
    chosen_inline_result_t *chosen_inline_result,
    callback_query_t *callback_query,
    shipping_query_t *shipping_query,
    pre_checkout_query_t *pre_checkout_query,
    paid_media_purchased_t *purchased_paid_media,
    poll_t *poll,
    poll_answer_t *poll_answer,
    chat_member_updated_t *my_chat_member,
    chat_member_updated_t *chat_member,
    chat_join_request_t *chat_join_request,
    chat_boost_updated_t *chat_boost,
    chat_boost_removed_t *removed_chat_boost
);

void update_free(update_t *update);

update_t *update_parseFromJSON(cJSON *updateJSON);

cJSON *update_convertToJSON(update_t *update);

#endif /* _update_H_ */

