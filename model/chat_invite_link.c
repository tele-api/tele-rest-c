#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "chat_invite_link.h"



static chat_invite_link_t *chat_invite_link_create_internal(
    char *invite_link,
    user_t *creator,
    int creates_join_request,
    int is_primary,
    int is_revoked,
    char *name,
    int expire_date,
    int member_limit,
    int pending_join_request_count,
    int subscription_period,
    int subscription_price
    ) {
    chat_invite_link_t *chat_invite_link_local_var = malloc(sizeof(chat_invite_link_t));
    if (!chat_invite_link_local_var) {
        return NULL;
    }
    chat_invite_link_local_var->invite_link = invite_link;
    chat_invite_link_local_var->creator = creator;
    chat_invite_link_local_var->creates_join_request = creates_join_request;
    chat_invite_link_local_var->is_primary = is_primary;
    chat_invite_link_local_var->is_revoked = is_revoked;
    chat_invite_link_local_var->name = name;
    chat_invite_link_local_var->expire_date = expire_date;
    chat_invite_link_local_var->member_limit = member_limit;
    chat_invite_link_local_var->pending_join_request_count = pending_join_request_count;
    chat_invite_link_local_var->subscription_period = subscription_period;
    chat_invite_link_local_var->subscription_price = subscription_price;

    chat_invite_link_local_var->_library_owned = 1;
    return chat_invite_link_local_var;
}

__attribute__((deprecated)) chat_invite_link_t *chat_invite_link_create(
    char *invite_link,
    user_t *creator,
    int creates_join_request,
    int is_primary,
    int is_revoked,
    char *name,
    int expire_date,
    int member_limit,
    int pending_join_request_count,
    int subscription_period,
    int subscription_price
    ) {
    return chat_invite_link_create_internal (
        invite_link,
        creator,
        creates_join_request,
        is_primary,
        is_revoked,
        name,
        expire_date,
        member_limit,
        pending_join_request_count,
        subscription_period,
        subscription_price
        );
}

void chat_invite_link_free(chat_invite_link_t *chat_invite_link) {
    if(NULL == chat_invite_link){
        return ;
    }
    if(chat_invite_link->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "chat_invite_link_free");
        return ;
    }
    listEntry_t *listEntry;
    if (chat_invite_link->invite_link) {
        free(chat_invite_link->invite_link);
        chat_invite_link->invite_link = NULL;
    }
    if (chat_invite_link->creator) {
        user_free(chat_invite_link->creator);
        chat_invite_link->creator = NULL;
    }
    if (chat_invite_link->name) {
        free(chat_invite_link->name);
        chat_invite_link->name = NULL;
    }
    free(chat_invite_link);
}

cJSON *chat_invite_link_convertToJSON(chat_invite_link_t *chat_invite_link) {
    cJSON *item = cJSON_CreateObject();

    // chat_invite_link->invite_link
    if (!chat_invite_link->invite_link) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "invite_link", chat_invite_link->invite_link) == NULL) {
    goto fail; //String
    }


    // chat_invite_link->creator
    if (!chat_invite_link->creator) {
        goto fail;
    }
    cJSON *creator_local_JSON = user_convertToJSON(chat_invite_link->creator);
    if(creator_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "creator", creator_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // chat_invite_link->creates_join_request
    if (!chat_invite_link->creates_join_request) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "creates_join_request", chat_invite_link->creates_join_request) == NULL) {
    goto fail; //Bool
    }


    // chat_invite_link->is_primary
    if (!chat_invite_link->is_primary) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "is_primary", chat_invite_link->is_primary) == NULL) {
    goto fail; //Bool
    }


    // chat_invite_link->is_revoked
    if (!chat_invite_link->is_revoked) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "is_revoked", chat_invite_link->is_revoked) == NULL) {
    goto fail; //Bool
    }


    // chat_invite_link->name
    if(chat_invite_link->name) {
    if(cJSON_AddStringToObject(item, "name", chat_invite_link->name) == NULL) {
    goto fail; //String
    }
    }


    // chat_invite_link->expire_date
    if(chat_invite_link->expire_date) {
    if(cJSON_AddNumberToObject(item, "expire_date", chat_invite_link->expire_date) == NULL) {
    goto fail; //Numeric
    }
    }


    // chat_invite_link->member_limit
    if(chat_invite_link->member_limit) {
    if(cJSON_AddNumberToObject(item, "member_limit", chat_invite_link->member_limit) == NULL) {
    goto fail; //Numeric
    }
    }


    // chat_invite_link->pending_join_request_count
    if(chat_invite_link->pending_join_request_count) {
    if(cJSON_AddNumberToObject(item, "pending_join_request_count", chat_invite_link->pending_join_request_count) == NULL) {
    goto fail; //Numeric
    }
    }


    // chat_invite_link->subscription_period
    if(chat_invite_link->subscription_period) {
    if(cJSON_AddNumberToObject(item, "subscription_period", chat_invite_link->subscription_period) == NULL) {
    goto fail; //Numeric
    }
    }


    // chat_invite_link->subscription_price
    if(chat_invite_link->subscription_price) {
    if(cJSON_AddNumberToObject(item, "subscription_price", chat_invite_link->subscription_price) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

chat_invite_link_t *chat_invite_link_parseFromJSON(cJSON *chat_invite_linkJSON){

    chat_invite_link_t *chat_invite_link_local_var = NULL;

    // define the local variable for chat_invite_link->creator
    user_t *creator_local_nonprim = NULL;

    // chat_invite_link->invite_link
    cJSON *invite_link = cJSON_GetObjectItemCaseSensitive(chat_invite_linkJSON, "invite_link");
    if (cJSON_IsNull(invite_link)) {
        invite_link = NULL;
    }
    if (!invite_link) {
        goto end;
    }

    
    if(!cJSON_IsString(invite_link))
    {
    goto end; //String
    }

    // chat_invite_link->creator
    cJSON *creator = cJSON_GetObjectItemCaseSensitive(chat_invite_linkJSON, "creator");
    if (cJSON_IsNull(creator)) {
        creator = NULL;
    }
    if (!creator) {
        goto end;
    }

    
    creator_local_nonprim = user_parseFromJSON(creator); //nonprimitive

    // chat_invite_link->creates_join_request
    cJSON *creates_join_request = cJSON_GetObjectItemCaseSensitive(chat_invite_linkJSON, "creates_join_request");
    if (cJSON_IsNull(creates_join_request)) {
        creates_join_request = NULL;
    }
    if (!creates_join_request) {
        goto end;
    }

    
    if(!cJSON_IsBool(creates_join_request))
    {
    goto end; //Bool
    }

    // chat_invite_link->is_primary
    cJSON *is_primary = cJSON_GetObjectItemCaseSensitive(chat_invite_linkJSON, "is_primary");
    if (cJSON_IsNull(is_primary)) {
        is_primary = NULL;
    }
    if (!is_primary) {
        goto end;
    }

    
    if(!cJSON_IsBool(is_primary))
    {
    goto end; //Bool
    }

    // chat_invite_link->is_revoked
    cJSON *is_revoked = cJSON_GetObjectItemCaseSensitive(chat_invite_linkJSON, "is_revoked");
    if (cJSON_IsNull(is_revoked)) {
        is_revoked = NULL;
    }
    if (!is_revoked) {
        goto end;
    }

    
    if(!cJSON_IsBool(is_revoked))
    {
    goto end; //Bool
    }

    // chat_invite_link->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(chat_invite_linkJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // chat_invite_link->expire_date
    cJSON *expire_date = cJSON_GetObjectItemCaseSensitive(chat_invite_linkJSON, "expire_date");
    if (cJSON_IsNull(expire_date)) {
        expire_date = NULL;
    }
    if (expire_date) { 
    if(!cJSON_IsNumber(expire_date))
    {
    goto end; //Numeric
    }
    }

    // chat_invite_link->member_limit
    cJSON *member_limit = cJSON_GetObjectItemCaseSensitive(chat_invite_linkJSON, "member_limit");
    if (cJSON_IsNull(member_limit)) {
        member_limit = NULL;
    }
    if (member_limit) { 
    if(!cJSON_IsNumber(member_limit))
    {
    goto end; //Numeric
    }
    }

    // chat_invite_link->pending_join_request_count
    cJSON *pending_join_request_count = cJSON_GetObjectItemCaseSensitive(chat_invite_linkJSON, "pending_join_request_count");
    if (cJSON_IsNull(pending_join_request_count)) {
        pending_join_request_count = NULL;
    }
    if (pending_join_request_count) { 
    if(!cJSON_IsNumber(pending_join_request_count))
    {
    goto end; //Numeric
    }
    }

    // chat_invite_link->subscription_period
    cJSON *subscription_period = cJSON_GetObjectItemCaseSensitive(chat_invite_linkJSON, "subscription_period");
    if (cJSON_IsNull(subscription_period)) {
        subscription_period = NULL;
    }
    if (subscription_period) { 
    if(!cJSON_IsNumber(subscription_period))
    {
    goto end; //Numeric
    }
    }

    // chat_invite_link->subscription_price
    cJSON *subscription_price = cJSON_GetObjectItemCaseSensitive(chat_invite_linkJSON, "subscription_price");
    if (cJSON_IsNull(subscription_price)) {
        subscription_price = NULL;
    }
    if (subscription_price) { 
    if(!cJSON_IsNumber(subscription_price))
    {
    goto end; //Numeric
    }
    }


    chat_invite_link_local_var = chat_invite_link_create_internal (
        strdup(invite_link->valuestring),
        creator_local_nonprim,
        creates_join_request->valueint,
        is_primary->valueint,
        is_revoked->valueint,
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        expire_date ? expire_date->valuedouble : 0,
        member_limit ? member_limit->valuedouble : 0,
        pending_join_request_count ? pending_join_request_count->valuedouble : 0,
        subscription_period ? subscription_period->valuedouble : 0,
        subscription_price ? subscription_price->valuedouble : 0
        );

    return chat_invite_link_local_var;
end:
    if (creator_local_nonprim) {
        user_free(creator_local_nonprim);
        creator_local_nonprim = NULL;
    }
    return NULL;

}
