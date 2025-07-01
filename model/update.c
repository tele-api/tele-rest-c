#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "update.h"



static update_t *update_create_internal(
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
    ) {
    update_t *update_local_var = malloc(sizeof(update_t));
    if (!update_local_var) {
        return NULL;
    }
    update_local_var->update_id = update_id;
    update_local_var->message = message;
    update_local_var->edited_message = edited_message;
    update_local_var->channel_post = channel_post;
    update_local_var->edited_channel_post = edited_channel_post;
    update_local_var->business_connection = business_connection;
    update_local_var->business_message = business_message;
    update_local_var->edited_business_message = edited_business_message;
    update_local_var->deleted_business_messages = deleted_business_messages;
    update_local_var->message_reaction = message_reaction;
    update_local_var->message_reaction_count = message_reaction_count;
    update_local_var->inline_query = inline_query;
    update_local_var->chosen_inline_result = chosen_inline_result;
    update_local_var->callback_query = callback_query;
    update_local_var->shipping_query = shipping_query;
    update_local_var->pre_checkout_query = pre_checkout_query;
    update_local_var->purchased_paid_media = purchased_paid_media;
    update_local_var->poll = poll;
    update_local_var->poll_answer = poll_answer;
    update_local_var->my_chat_member = my_chat_member;
    update_local_var->chat_member = chat_member;
    update_local_var->chat_join_request = chat_join_request;
    update_local_var->chat_boost = chat_boost;
    update_local_var->removed_chat_boost = removed_chat_boost;

    update_local_var->_library_owned = 1;
    return update_local_var;
}

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
    ) {
    return update_create_internal (
        update_id,
        message,
        edited_message,
        channel_post,
        edited_channel_post,
        business_connection,
        business_message,
        edited_business_message,
        deleted_business_messages,
        message_reaction,
        message_reaction_count,
        inline_query,
        chosen_inline_result,
        callback_query,
        shipping_query,
        pre_checkout_query,
        purchased_paid_media,
        poll,
        poll_answer,
        my_chat_member,
        chat_member,
        chat_join_request,
        chat_boost,
        removed_chat_boost
        );
}

void update_free(update_t *update) {
    if(NULL == update){
        return ;
    }
    if(update->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "update_free");
        return ;
    }
    listEntry_t *listEntry;
    if (update->message) {
        message_free(update->message);
        update->message = NULL;
    }
    if (update->edited_message) {
        message_free(update->edited_message);
        update->edited_message = NULL;
    }
    if (update->channel_post) {
        message_free(update->channel_post);
        update->channel_post = NULL;
    }
    if (update->edited_channel_post) {
        message_free(update->edited_channel_post);
        update->edited_channel_post = NULL;
    }
    if (update->business_connection) {
        business_connection_free(update->business_connection);
        update->business_connection = NULL;
    }
    if (update->business_message) {
        message_free(update->business_message);
        update->business_message = NULL;
    }
    if (update->edited_business_message) {
        message_free(update->edited_business_message);
        update->edited_business_message = NULL;
    }
    if (update->deleted_business_messages) {
        business_messages_deleted_free(update->deleted_business_messages);
        update->deleted_business_messages = NULL;
    }
    if (update->message_reaction) {
        message_reaction_updated_free(update->message_reaction);
        update->message_reaction = NULL;
    }
    if (update->message_reaction_count) {
        message_reaction_count_updated_free(update->message_reaction_count);
        update->message_reaction_count = NULL;
    }
    if (update->inline_query) {
        inline_query_free(update->inline_query);
        update->inline_query = NULL;
    }
    if (update->chosen_inline_result) {
        chosen_inline_result_free(update->chosen_inline_result);
        update->chosen_inline_result = NULL;
    }
    if (update->callback_query) {
        callback_query_free(update->callback_query);
        update->callback_query = NULL;
    }
    if (update->shipping_query) {
        shipping_query_free(update->shipping_query);
        update->shipping_query = NULL;
    }
    if (update->pre_checkout_query) {
        pre_checkout_query_free(update->pre_checkout_query);
        update->pre_checkout_query = NULL;
    }
    if (update->purchased_paid_media) {
        paid_media_purchased_free(update->purchased_paid_media);
        update->purchased_paid_media = NULL;
    }
    if (update->poll) {
        poll_free(update->poll);
        update->poll = NULL;
    }
    if (update->poll_answer) {
        poll_answer_free(update->poll_answer);
        update->poll_answer = NULL;
    }
    if (update->my_chat_member) {
        chat_member_updated_free(update->my_chat_member);
        update->my_chat_member = NULL;
    }
    if (update->chat_member) {
        chat_member_updated_free(update->chat_member);
        update->chat_member = NULL;
    }
    if (update->chat_join_request) {
        chat_join_request_free(update->chat_join_request);
        update->chat_join_request = NULL;
    }
    if (update->chat_boost) {
        chat_boost_updated_free(update->chat_boost);
        update->chat_boost = NULL;
    }
    if (update->removed_chat_boost) {
        chat_boost_removed_free(update->removed_chat_boost);
        update->removed_chat_boost = NULL;
    }
    free(update);
}

cJSON *update_convertToJSON(update_t *update) {
    cJSON *item = cJSON_CreateObject();

    // update->update_id
    if (!update->update_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "update_id", update->update_id) == NULL) {
    goto fail; //Numeric
    }


    // update->message
    if(update->message) {
    cJSON *message_local_JSON = message_convertToJSON(update->message);
    if(message_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "message", message_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // update->edited_message
    if(update->edited_message) {
    cJSON *edited_message_local_JSON = message_convertToJSON(update->edited_message);
    if(edited_message_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "edited_message", edited_message_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // update->channel_post
    if(update->channel_post) {
    cJSON *channel_post_local_JSON = message_convertToJSON(update->channel_post);
    if(channel_post_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "channel_post", channel_post_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // update->edited_channel_post
    if(update->edited_channel_post) {
    cJSON *edited_channel_post_local_JSON = message_convertToJSON(update->edited_channel_post);
    if(edited_channel_post_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "edited_channel_post", edited_channel_post_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // update->business_connection
    if(update->business_connection) {
    cJSON *business_connection_local_JSON = business_connection_convertToJSON(update->business_connection);
    if(business_connection_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "business_connection", business_connection_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // update->business_message
    if(update->business_message) {
    cJSON *business_message_local_JSON = message_convertToJSON(update->business_message);
    if(business_message_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "business_message", business_message_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // update->edited_business_message
    if(update->edited_business_message) {
    cJSON *edited_business_message_local_JSON = message_convertToJSON(update->edited_business_message);
    if(edited_business_message_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "edited_business_message", edited_business_message_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // update->deleted_business_messages
    if(update->deleted_business_messages) {
    cJSON *deleted_business_messages_local_JSON = business_messages_deleted_convertToJSON(update->deleted_business_messages);
    if(deleted_business_messages_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "deleted_business_messages", deleted_business_messages_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // update->message_reaction
    if(update->message_reaction) {
    cJSON *message_reaction_local_JSON = message_reaction_updated_convertToJSON(update->message_reaction);
    if(message_reaction_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "message_reaction", message_reaction_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // update->message_reaction_count
    if(update->message_reaction_count) {
    cJSON *message_reaction_count_local_JSON = message_reaction_count_updated_convertToJSON(update->message_reaction_count);
    if(message_reaction_count_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "message_reaction_count", message_reaction_count_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // update->inline_query
    if(update->inline_query) {
    cJSON *inline_query_local_JSON = inline_query_convertToJSON(update->inline_query);
    if(inline_query_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "inline_query", inline_query_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // update->chosen_inline_result
    if(update->chosen_inline_result) {
    cJSON *chosen_inline_result_local_JSON = chosen_inline_result_convertToJSON(update->chosen_inline_result);
    if(chosen_inline_result_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chosen_inline_result", chosen_inline_result_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // update->callback_query
    if(update->callback_query) {
    cJSON *callback_query_local_JSON = callback_query_convertToJSON(update->callback_query);
    if(callback_query_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "callback_query", callback_query_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // update->shipping_query
    if(update->shipping_query) {
    cJSON *shipping_query_local_JSON = shipping_query_convertToJSON(update->shipping_query);
    if(shipping_query_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "shipping_query", shipping_query_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // update->pre_checkout_query
    if(update->pre_checkout_query) {
    cJSON *pre_checkout_query_local_JSON = pre_checkout_query_convertToJSON(update->pre_checkout_query);
    if(pre_checkout_query_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "pre_checkout_query", pre_checkout_query_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // update->purchased_paid_media
    if(update->purchased_paid_media) {
    cJSON *purchased_paid_media_local_JSON = paid_media_purchased_convertToJSON(update->purchased_paid_media);
    if(purchased_paid_media_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "purchased_paid_media", purchased_paid_media_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // update->poll
    if(update->poll) {
    cJSON *poll_local_JSON = poll_convertToJSON(update->poll);
    if(poll_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "poll", poll_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // update->poll_answer
    if(update->poll_answer) {
    cJSON *poll_answer_local_JSON = poll_answer_convertToJSON(update->poll_answer);
    if(poll_answer_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "poll_answer", poll_answer_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // update->my_chat_member
    if(update->my_chat_member) {
    cJSON *my_chat_member_local_JSON = chat_member_updated_convertToJSON(update->my_chat_member);
    if(my_chat_member_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "my_chat_member", my_chat_member_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // update->chat_member
    if(update->chat_member) {
    cJSON *chat_member_local_JSON = chat_member_updated_convertToJSON(update->chat_member);
    if(chat_member_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_member", chat_member_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // update->chat_join_request
    if(update->chat_join_request) {
    cJSON *chat_join_request_local_JSON = chat_join_request_convertToJSON(update->chat_join_request);
    if(chat_join_request_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_join_request", chat_join_request_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // update->chat_boost
    if(update->chat_boost) {
    cJSON *chat_boost_local_JSON = chat_boost_updated_convertToJSON(update->chat_boost);
    if(chat_boost_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_boost", chat_boost_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // update->removed_chat_boost
    if(update->removed_chat_boost) {
    cJSON *removed_chat_boost_local_JSON = chat_boost_removed_convertToJSON(update->removed_chat_boost);
    if(removed_chat_boost_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "removed_chat_boost", removed_chat_boost_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

update_t *update_parseFromJSON(cJSON *updateJSON){

    update_t *update_local_var = NULL;

    // define the local variable for update->message
    message_t *message_local_nonprim = NULL;

    // define the local variable for update->edited_message
    message_t *edited_message_local_nonprim = NULL;

    // define the local variable for update->channel_post
    message_t *channel_post_local_nonprim = NULL;

    // define the local variable for update->edited_channel_post
    message_t *edited_channel_post_local_nonprim = NULL;

    // define the local variable for update->business_connection
    business_connection_t *business_connection_local_nonprim = NULL;

    // define the local variable for update->business_message
    message_t *business_message_local_nonprim = NULL;

    // define the local variable for update->edited_business_message
    message_t *edited_business_message_local_nonprim = NULL;

    // define the local variable for update->deleted_business_messages
    business_messages_deleted_t *deleted_business_messages_local_nonprim = NULL;

    // define the local variable for update->message_reaction
    message_reaction_updated_t *message_reaction_local_nonprim = NULL;

    // define the local variable for update->message_reaction_count
    message_reaction_count_updated_t *message_reaction_count_local_nonprim = NULL;

    // define the local variable for update->inline_query
    inline_query_t *inline_query_local_nonprim = NULL;

    // define the local variable for update->chosen_inline_result
    chosen_inline_result_t *chosen_inline_result_local_nonprim = NULL;

    // define the local variable for update->callback_query
    callback_query_t *callback_query_local_nonprim = NULL;

    // define the local variable for update->shipping_query
    shipping_query_t *shipping_query_local_nonprim = NULL;

    // define the local variable for update->pre_checkout_query
    pre_checkout_query_t *pre_checkout_query_local_nonprim = NULL;

    // define the local variable for update->purchased_paid_media
    paid_media_purchased_t *purchased_paid_media_local_nonprim = NULL;

    // define the local variable for update->poll
    poll_t *poll_local_nonprim = NULL;

    // define the local variable for update->poll_answer
    poll_answer_t *poll_answer_local_nonprim = NULL;

    // define the local variable for update->my_chat_member
    chat_member_updated_t *my_chat_member_local_nonprim = NULL;

    // define the local variable for update->chat_member
    chat_member_updated_t *chat_member_local_nonprim = NULL;

    // define the local variable for update->chat_join_request
    chat_join_request_t *chat_join_request_local_nonprim = NULL;

    // define the local variable for update->chat_boost
    chat_boost_updated_t *chat_boost_local_nonprim = NULL;

    // define the local variable for update->removed_chat_boost
    chat_boost_removed_t *removed_chat_boost_local_nonprim = NULL;

    // update->update_id
    cJSON *update_id = cJSON_GetObjectItemCaseSensitive(updateJSON, "update_id");
    if (cJSON_IsNull(update_id)) {
        update_id = NULL;
    }
    if (!update_id) {
        goto end;
    }

    
    if(!cJSON_IsNumber(update_id))
    {
    goto end; //Numeric
    }

    // update->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(updateJSON, "message");
    if (cJSON_IsNull(message)) {
        message = NULL;
    }
    if (message) { 
    message_local_nonprim = message_parseFromJSON(message); //nonprimitive
    }

    // update->edited_message
    cJSON *edited_message = cJSON_GetObjectItemCaseSensitive(updateJSON, "edited_message");
    if (cJSON_IsNull(edited_message)) {
        edited_message = NULL;
    }
    if (edited_message) { 
    edited_message_local_nonprim = message_parseFromJSON(edited_message); //nonprimitive
    }

    // update->channel_post
    cJSON *channel_post = cJSON_GetObjectItemCaseSensitive(updateJSON, "channel_post");
    if (cJSON_IsNull(channel_post)) {
        channel_post = NULL;
    }
    if (channel_post) { 
    channel_post_local_nonprim = message_parseFromJSON(channel_post); //nonprimitive
    }

    // update->edited_channel_post
    cJSON *edited_channel_post = cJSON_GetObjectItemCaseSensitive(updateJSON, "edited_channel_post");
    if (cJSON_IsNull(edited_channel_post)) {
        edited_channel_post = NULL;
    }
    if (edited_channel_post) { 
    edited_channel_post_local_nonprim = message_parseFromJSON(edited_channel_post); //nonprimitive
    }

    // update->business_connection
    cJSON *business_connection = cJSON_GetObjectItemCaseSensitive(updateJSON, "business_connection");
    if (cJSON_IsNull(business_connection)) {
        business_connection = NULL;
    }
    if (business_connection) { 
    business_connection_local_nonprim = business_connection_parseFromJSON(business_connection); //nonprimitive
    }

    // update->business_message
    cJSON *business_message = cJSON_GetObjectItemCaseSensitive(updateJSON, "business_message");
    if (cJSON_IsNull(business_message)) {
        business_message = NULL;
    }
    if (business_message) { 
    business_message_local_nonprim = message_parseFromJSON(business_message); //nonprimitive
    }

    // update->edited_business_message
    cJSON *edited_business_message = cJSON_GetObjectItemCaseSensitive(updateJSON, "edited_business_message");
    if (cJSON_IsNull(edited_business_message)) {
        edited_business_message = NULL;
    }
    if (edited_business_message) { 
    edited_business_message_local_nonprim = message_parseFromJSON(edited_business_message); //nonprimitive
    }

    // update->deleted_business_messages
    cJSON *deleted_business_messages = cJSON_GetObjectItemCaseSensitive(updateJSON, "deleted_business_messages");
    if (cJSON_IsNull(deleted_business_messages)) {
        deleted_business_messages = NULL;
    }
    if (deleted_business_messages) { 
    deleted_business_messages_local_nonprim = business_messages_deleted_parseFromJSON(deleted_business_messages); //nonprimitive
    }

    // update->message_reaction
    cJSON *message_reaction = cJSON_GetObjectItemCaseSensitive(updateJSON, "message_reaction");
    if (cJSON_IsNull(message_reaction)) {
        message_reaction = NULL;
    }
    if (message_reaction) { 
    message_reaction_local_nonprim = message_reaction_updated_parseFromJSON(message_reaction); //nonprimitive
    }

    // update->message_reaction_count
    cJSON *message_reaction_count = cJSON_GetObjectItemCaseSensitive(updateJSON, "message_reaction_count");
    if (cJSON_IsNull(message_reaction_count)) {
        message_reaction_count = NULL;
    }
    if (message_reaction_count) { 
    message_reaction_count_local_nonprim = message_reaction_count_updated_parseFromJSON(message_reaction_count); //nonprimitive
    }

    // update->inline_query
    cJSON *inline_query = cJSON_GetObjectItemCaseSensitive(updateJSON, "inline_query");
    if (cJSON_IsNull(inline_query)) {
        inline_query = NULL;
    }
    if (inline_query) { 
    inline_query_local_nonprim = inline_query_parseFromJSON(inline_query); //nonprimitive
    }

    // update->chosen_inline_result
    cJSON *chosen_inline_result = cJSON_GetObjectItemCaseSensitive(updateJSON, "chosen_inline_result");
    if (cJSON_IsNull(chosen_inline_result)) {
        chosen_inline_result = NULL;
    }
    if (chosen_inline_result) { 
    chosen_inline_result_local_nonprim = chosen_inline_result_parseFromJSON(chosen_inline_result); //nonprimitive
    }

    // update->callback_query
    cJSON *callback_query = cJSON_GetObjectItemCaseSensitive(updateJSON, "callback_query");
    if (cJSON_IsNull(callback_query)) {
        callback_query = NULL;
    }
    if (callback_query) { 
    callback_query_local_nonprim = callback_query_parseFromJSON(callback_query); //nonprimitive
    }

    // update->shipping_query
    cJSON *shipping_query = cJSON_GetObjectItemCaseSensitive(updateJSON, "shipping_query");
    if (cJSON_IsNull(shipping_query)) {
        shipping_query = NULL;
    }
    if (shipping_query) { 
    shipping_query_local_nonprim = shipping_query_parseFromJSON(shipping_query); //nonprimitive
    }

    // update->pre_checkout_query
    cJSON *pre_checkout_query = cJSON_GetObjectItemCaseSensitive(updateJSON, "pre_checkout_query");
    if (cJSON_IsNull(pre_checkout_query)) {
        pre_checkout_query = NULL;
    }
    if (pre_checkout_query) { 
    pre_checkout_query_local_nonprim = pre_checkout_query_parseFromJSON(pre_checkout_query); //nonprimitive
    }

    // update->purchased_paid_media
    cJSON *purchased_paid_media = cJSON_GetObjectItemCaseSensitive(updateJSON, "purchased_paid_media");
    if (cJSON_IsNull(purchased_paid_media)) {
        purchased_paid_media = NULL;
    }
    if (purchased_paid_media) { 
    purchased_paid_media_local_nonprim = paid_media_purchased_parseFromJSON(purchased_paid_media); //nonprimitive
    }

    // update->poll
    cJSON *poll = cJSON_GetObjectItemCaseSensitive(updateJSON, "poll");
    if (cJSON_IsNull(poll)) {
        poll = NULL;
    }
    if (poll) { 
    poll_local_nonprim = poll_parseFromJSON(poll); //nonprimitive
    }

    // update->poll_answer
    cJSON *poll_answer = cJSON_GetObjectItemCaseSensitive(updateJSON, "poll_answer");
    if (cJSON_IsNull(poll_answer)) {
        poll_answer = NULL;
    }
    if (poll_answer) { 
    poll_answer_local_nonprim = poll_answer_parseFromJSON(poll_answer); //nonprimitive
    }

    // update->my_chat_member
    cJSON *my_chat_member = cJSON_GetObjectItemCaseSensitive(updateJSON, "my_chat_member");
    if (cJSON_IsNull(my_chat_member)) {
        my_chat_member = NULL;
    }
    if (my_chat_member) { 
    my_chat_member_local_nonprim = chat_member_updated_parseFromJSON(my_chat_member); //nonprimitive
    }

    // update->chat_member
    cJSON *chat_member = cJSON_GetObjectItemCaseSensitive(updateJSON, "chat_member");
    if (cJSON_IsNull(chat_member)) {
        chat_member = NULL;
    }
    if (chat_member) { 
    chat_member_local_nonprim = chat_member_updated_parseFromJSON(chat_member); //nonprimitive
    }

    // update->chat_join_request
    cJSON *chat_join_request = cJSON_GetObjectItemCaseSensitive(updateJSON, "chat_join_request");
    if (cJSON_IsNull(chat_join_request)) {
        chat_join_request = NULL;
    }
    if (chat_join_request) { 
    chat_join_request_local_nonprim = chat_join_request_parseFromJSON(chat_join_request); //nonprimitive
    }

    // update->chat_boost
    cJSON *chat_boost = cJSON_GetObjectItemCaseSensitive(updateJSON, "chat_boost");
    if (cJSON_IsNull(chat_boost)) {
        chat_boost = NULL;
    }
    if (chat_boost) { 
    chat_boost_local_nonprim = chat_boost_updated_parseFromJSON(chat_boost); //nonprimitive
    }

    // update->removed_chat_boost
    cJSON *removed_chat_boost = cJSON_GetObjectItemCaseSensitive(updateJSON, "removed_chat_boost");
    if (cJSON_IsNull(removed_chat_boost)) {
        removed_chat_boost = NULL;
    }
    if (removed_chat_boost) { 
    removed_chat_boost_local_nonprim = chat_boost_removed_parseFromJSON(removed_chat_boost); //nonprimitive
    }


    update_local_var = update_create_internal (
        update_id->valuedouble,
        message ? message_local_nonprim : NULL,
        edited_message ? edited_message_local_nonprim : NULL,
        channel_post ? channel_post_local_nonprim : NULL,
        edited_channel_post ? edited_channel_post_local_nonprim : NULL,
        business_connection ? business_connection_local_nonprim : NULL,
        business_message ? business_message_local_nonprim : NULL,
        edited_business_message ? edited_business_message_local_nonprim : NULL,
        deleted_business_messages ? deleted_business_messages_local_nonprim : NULL,
        message_reaction ? message_reaction_local_nonprim : NULL,
        message_reaction_count ? message_reaction_count_local_nonprim : NULL,
        inline_query ? inline_query_local_nonprim : NULL,
        chosen_inline_result ? chosen_inline_result_local_nonprim : NULL,
        callback_query ? callback_query_local_nonprim : NULL,
        shipping_query ? shipping_query_local_nonprim : NULL,
        pre_checkout_query ? pre_checkout_query_local_nonprim : NULL,
        purchased_paid_media ? purchased_paid_media_local_nonprim : NULL,
        poll ? poll_local_nonprim : NULL,
        poll_answer ? poll_answer_local_nonprim : NULL,
        my_chat_member ? my_chat_member_local_nonprim : NULL,
        chat_member ? chat_member_local_nonprim : NULL,
        chat_join_request ? chat_join_request_local_nonprim : NULL,
        chat_boost ? chat_boost_local_nonprim : NULL,
        removed_chat_boost ? removed_chat_boost_local_nonprim : NULL
        );

    return update_local_var;
end:
    if (message_local_nonprim) {
        message_free(message_local_nonprim);
        message_local_nonprim = NULL;
    }
    if (edited_message_local_nonprim) {
        message_free(edited_message_local_nonprim);
        edited_message_local_nonprim = NULL;
    }
    if (channel_post_local_nonprim) {
        message_free(channel_post_local_nonprim);
        channel_post_local_nonprim = NULL;
    }
    if (edited_channel_post_local_nonprim) {
        message_free(edited_channel_post_local_nonprim);
        edited_channel_post_local_nonprim = NULL;
    }
    if (business_connection_local_nonprim) {
        business_connection_free(business_connection_local_nonprim);
        business_connection_local_nonprim = NULL;
    }
    if (business_message_local_nonprim) {
        message_free(business_message_local_nonprim);
        business_message_local_nonprim = NULL;
    }
    if (edited_business_message_local_nonprim) {
        message_free(edited_business_message_local_nonprim);
        edited_business_message_local_nonprim = NULL;
    }
    if (deleted_business_messages_local_nonprim) {
        business_messages_deleted_free(deleted_business_messages_local_nonprim);
        deleted_business_messages_local_nonprim = NULL;
    }
    if (message_reaction_local_nonprim) {
        message_reaction_updated_free(message_reaction_local_nonprim);
        message_reaction_local_nonprim = NULL;
    }
    if (message_reaction_count_local_nonprim) {
        message_reaction_count_updated_free(message_reaction_count_local_nonprim);
        message_reaction_count_local_nonprim = NULL;
    }
    if (inline_query_local_nonprim) {
        inline_query_free(inline_query_local_nonprim);
        inline_query_local_nonprim = NULL;
    }
    if (chosen_inline_result_local_nonprim) {
        chosen_inline_result_free(chosen_inline_result_local_nonprim);
        chosen_inline_result_local_nonprim = NULL;
    }
    if (callback_query_local_nonprim) {
        callback_query_free(callback_query_local_nonprim);
        callback_query_local_nonprim = NULL;
    }
    if (shipping_query_local_nonprim) {
        shipping_query_free(shipping_query_local_nonprim);
        shipping_query_local_nonprim = NULL;
    }
    if (pre_checkout_query_local_nonprim) {
        pre_checkout_query_free(pre_checkout_query_local_nonprim);
        pre_checkout_query_local_nonprim = NULL;
    }
    if (purchased_paid_media_local_nonprim) {
        paid_media_purchased_free(purchased_paid_media_local_nonprim);
        purchased_paid_media_local_nonprim = NULL;
    }
    if (poll_local_nonprim) {
        poll_free(poll_local_nonprim);
        poll_local_nonprim = NULL;
    }
    if (poll_answer_local_nonprim) {
        poll_answer_free(poll_answer_local_nonprim);
        poll_answer_local_nonprim = NULL;
    }
    if (my_chat_member_local_nonprim) {
        chat_member_updated_free(my_chat_member_local_nonprim);
        my_chat_member_local_nonprim = NULL;
    }
    if (chat_member_local_nonprim) {
        chat_member_updated_free(chat_member_local_nonprim);
        chat_member_local_nonprim = NULL;
    }
    if (chat_join_request_local_nonprim) {
        chat_join_request_free(chat_join_request_local_nonprim);
        chat_join_request_local_nonprim = NULL;
    }
    if (chat_boost_local_nonprim) {
        chat_boost_updated_free(chat_boost_local_nonprim);
        chat_boost_local_nonprim = NULL;
    }
    if (removed_chat_boost_local_nonprim) {
        chat_boost_removed_free(removed_chat_boost_local_nonprim);
        removed_chat_boost_local_nonprim = NULL;
    }
    return NULL;

}
