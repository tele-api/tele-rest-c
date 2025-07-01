#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "transaction_partner.h"


char* transaction_partner_transaction_type_ToString(telegram_bot_api_transaction_partner_TRANSACTIONTYPE_e transaction_type) {
    char* transaction_typeArray[] =  { "NULL", "invoice_payment", "paid_media_payment", "gift_purchase", "premium_purchase", "business_account_transfer" };
    return transaction_typeArray[transaction_type];
}

telegram_bot_api_transaction_partner_TRANSACTIONTYPE_e transaction_partner_transaction_type_FromString(char* transaction_type){
    int stringToReturn = 0;
    char *transaction_typeArray[] =  { "NULL", "invoice_payment", "paid_media_payment", "gift_purchase", "premium_purchase", "business_account_transfer" };
    size_t sizeofArray = sizeof(transaction_typeArray) / sizeof(transaction_typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(transaction_type, transaction_typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static transaction_partner_t *transaction_partner_create_internal(
    char *type,
    telegram_bot_api_transaction_partner_TRANSACTIONTYPE_e transaction_type,
    user_t *user,
    chat_t *chat,
    int commission_per_mille,
    int request_count,
    affiliate_info_t *affiliate,
    char *invoice_payload,
    int subscription_period,
    list_t *paid_media,
    char *paid_media_payload,
    gift_t *gift,
    int premium_subscription_duration,
    user_t *sponsor_user,
    revenue_withdrawal_state_t *withdrawal_state
    ) {
    transaction_partner_t *transaction_partner_local_var = malloc(sizeof(transaction_partner_t));
    if (!transaction_partner_local_var) {
        return NULL;
    }
    transaction_partner_local_var->type = type;
    transaction_partner_local_var->transaction_type = transaction_type;
    transaction_partner_local_var->user = user;
    transaction_partner_local_var->chat = chat;
    transaction_partner_local_var->commission_per_mille = commission_per_mille;
    transaction_partner_local_var->request_count = request_count;
    transaction_partner_local_var->affiliate = affiliate;
    transaction_partner_local_var->invoice_payload = invoice_payload;
    transaction_partner_local_var->subscription_period = subscription_period;
    transaction_partner_local_var->paid_media = paid_media;
    transaction_partner_local_var->paid_media_payload = paid_media_payload;
    transaction_partner_local_var->gift = gift;
    transaction_partner_local_var->premium_subscription_duration = premium_subscription_duration;
    transaction_partner_local_var->sponsor_user = sponsor_user;
    transaction_partner_local_var->withdrawal_state = withdrawal_state;

    transaction_partner_local_var->_library_owned = 1;
    return transaction_partner_local_var;
}

__attribute__((deprecated)) transaction_partner_t *transaction_partner_create(
    char *type,
    telegram_bot_api_transaction_partner_TRANSACTIONTYPE_e transaction_type,
    user_t *user,
    chat_t *chat,
    int commission_per_mille,
    int request_count,
    affiliate_info_t *affiliate,
    char *invoice_payload,
    int subscription_period,
    list_t *paid_media,
    char *paid_media_payload,
    gift_t *gift,
    int premium_subscription_duration,
    user_t *sponsor_user,
    revenue_withdrawal_state_t *withdrawal_state
    ) {
    return transaction_partner_create_internal (
        type,
        transaction_type,
        user,
        chat,
        commission_per_mille,
        request_count,
        affiliate,
        invoice_payload,
        subscription_period,
        paid_media,
        paid_media_payload,
        gift,
        premium_subscription_duration,
        sponsor_user,
        withdrawal_state
        );
}

void transaction_partner_free(transaction_partner_t *transaction_partner) {
    if(NULL == transaction_partner){
        return ;
    }
    if(transaction_partner->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "transaction_partner_free");
        return ;
    }
    listEntry_t *listEntry;
    if (transaction_partner->type) {
        free(transaction_partner->type);
        transaction_partner->type = NULL;
    }
    if (transaction_partner->user) {
        user_free(transaction_partner->user);
        transaction_partner->user = NULL;
    }
    if (transaction_partner->chat) {
        chat_free(transaction_partner->chat);
        transaction_partner->chat = NULL;
    }
    if (transaction_partner->affiliate) {
        affiliate_info_free(transaction_partner->affiliate);
        transaction_partner->affiliate = NULL;
    }
    if (transaction_partner->invoice_payload) {
        free(transaction_partner->invoice_payload);
        transaction_partner->invoice_payload = NULL;
    }
    if (transaction_partner->paid_media) {
        list_ForEach(listEntry, transaction_partner->paid_media) {
            paid_media_free(listEntry->data);
        }
        list_freeList(transaction_partner->paid_media);
        transaction_partner->paid_media = NULL;
    }
    if (transaction_partner->paid_media_payload) {
        free(transaction_partner->paid_media_payload);
        transaction_partner->paid_media_payload = NULL;
    }
    if (transaction_partner->gift) {
        gift_free(transaction_partner->gift);
        transaction_partner->gift = NULL;
    }
    if (transaction_partner->sponsor_user) {
        user_free(transaction_partner->sponsor_user);
        transaction_partner->sponsor_user = NULL;
    }
    if (transaction_partner->withdrawal_state) {
        revenue_withdrawal_state_free(transaction_partner->withdrawal_state);
        transaction_partner->withdrawal_state = NULL;
    }
    free(transaction_partner);
}

cJSON *transaction_partner_convertToJSON(transaction_partner_t *transaction_partner) {
    cJSON *item = cJSON_CreateObject();

    // transaction_partner->type
    if (!transaction_partner->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", transaction_partner->type) == NULL) {
    goto fail; //String
    }


    // transaction_partner->transaction_type
    if (telegram_bot_api_transaction_partner_TRANSACTIONTYPE_NULL == transaction_partner->transaction_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "transaction_type", transaction_partner_transaction_type_ToString(transaction_partner->transaction_type)) == NULL)
    {
    goto fail; //Enum
    }


    // transaction_partner->user
    if (!transaction_partner->user) {
        goto fail;
    }
    cJSON *user_local_JSON = user_convertToJSON(transaction_partner->user);
    if(user_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "user", user_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // transaction_partner->chat
    if (!transaction_partner->chat) {
        goto fail;
    }
    cJSON *chat_local_JSON = chat_convertToJSON(transaction_partner->chat);
    if(chat_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat", chat_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // transaction_partner->commission_per_mille
    if (!transaction_partner->commission_per_mille) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "commission_per_mille", transaction_partner->commission_per_mille) == NULL) {
    goto fail; //Numeric
    }


    // transaction_partner->request_count
    if (!transaction_partner->request_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "request_count", transaction_partner->request_count) == NULL) {
    goto fail; //Numeric
    }


    // transaction_partner->affiliate
    if(transaction_partner->affiliate) {
    cJSON *affiliate_local_JSON = affiliate_info_convertToJSON(transaction_partner->affiliate);
    if(affiliate_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "affiliate", affiliate_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // transaction_partner->invoice_payload
    if(transaction_partner->invoice_payload) {
    if(cJSON_AddStringToObject(item, "invoice_payload", transaction_partner->invoice_payload) == NULL) {
    goto fail; //String
    }
    }


    // transaction_partner->subscription_period
    if(transaction_partner->subscription_period) {
    if(cJSON_AddNumberToObject(item, "subscription_period", transaction_partner->subscription_period) == NULL) {
    goto fail; //Numeric
    }
    }


    // transaction_partner->paid_media
    if(transaction_partner->paid_media) {
    cJSON *paid_media = cJSON_AddArrayToObject(item, "paid_media");
    if(paid_media == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *paid_mediaListEntry;
    if (transaction_partner->paid_media) {
    list_ForEach(paid_mediaListEntry, transaction_partner->paid_media) {
    cJSON *itemLocal = paid_media_convertToJSON(paid_mediaListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(paid_media, itemLocal);
    }
    }
    }


    // transaction_partner->paid_media_payload
    if(transaction_partner->paid_media_payload) {
    if(cJSON_AddStringToObject(item, "paid_media_payload", transaction_partner->paid_media_payload) == NULL) {
    goto fail; //String
    }
    }


    // transaction_partner->gift
    if(transaction_partner->gift) {
    cJSON *gift_local_JSON = gift_convertToJSON(transaction_partner->gift);
    if(gift_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "gift", gift_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // transaction_partner->premium_subscription_duration
    if(transaction_partner->premium_subscription_duration) {
    if(cJSON_AddNumberToObject(item, "premium_subscription_duration", transaction_partner->premium_subscription_duration) == NULL) {
    goto fail; //Numeric
    }
    }


    // transaction_partner->sponsor_user
    if(transaction_partner->sponsor_user) {
    cJSON *sponsor_user_local_JSON = user_convertToJSON(transaction_partner->sponsor_user);
    if(sponsor_user_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "sponsor_user", sponsor_user_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // transaction_partner->withdrawal_state
    if(transaction_partner->withdrawal_state) {
    cJSON *withdrawal_state_local_JSON = revenue_withdrawal_state_convertToJSON(transaction_partner->withdrawal_state);
    if(withdrawal_state_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "withdrawal_state", withdrawal_state_local_JSON);
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

transaction_partner_t *transaction_partner_parseFromJSON(cJSON *transaction_partnerJSON){

    transaction_partner_t *transaction_partner_local_var = NULL;

    // define the local variable for transaction_partner->user
    user_t *user_local_nonprim = NULL;

    // define the local variable for transaction_partner->chat
    chat_t *chat_local_nonprim = NULL;

    // define the local variable for transaction_partner->affiliate
    affiliate_info_t *affiliate_local_nonprim = NULL;

    // define the local list for transaction_partner->paid_media
    list_t *paid_mediaList = NULL;

    // define the local variable for transaction_partner->gift
    gift_t *gift_local_nonprim = NULL;

    // define the local variable for transaction_partner->sponsor_user
    user_t *sponsor_user_local_nonprim = NULL;

    // define the local variable for transaction_partner->withdrawal_state
    revenue_withdrawal_state_t *withdrawal_state_local_nonprim = NULL;

    // transaction_partner->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(transaction_partnerJSON, "type");
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

    // transaction_partner->transaction_type
    cJSON *transaction_type = cJSON_GetObjectItemCaseSensitive(transaction_partnerJSON, "transaction_type");
    if (cJSON_IsNull(transaction_type)) {
        transaction_type = NULL;
    }
    if (!transaction_type) {
        goto end;
    }

    telegram_bot_api_transaction_partner_TRANSACTIONTYPE_e transaction_typeVariable;
    
    if(!cJSON_IsString(transaction_type))
    {
    goto end; //Enum
    }
    transaction_typeVariable = transaction_partner_transaction_type_FromString(transaction_type->valuestring);

    // transaction_partner->user
    cJSON *user = cJSON_GetObjectItemCaseSensitive(transaction_partnerJSON, "user");
    if (cJSON_IsNull(user)) {
        user = NULL;
    }
    if (!user) {
        goto end;
    }

    
    user_local_nonprim = user_parseFromJSON(user); //nonprimitive

    // transaction_partner->chat
    cJSON *chat = cJSON_GetObjectItemCaseSensitive(transaction_partnerJSON, "chat");
    if (cJSON_IsNull(chat)) {
        chat = NULL;
    }
    if (!chat) {
        goto end;
    }

    
    chat_local_nonprim = chat_parseFromJSON(chat); //nonprimitive

    // transaction_partner->commission_per_mille
    cJSON *commission_per_mille = cJSON_GetObjectItemCaseSensitive(transaction_partnerJSON, "commission_per_mille");
    if (cJSON_IsNull(commission_per_mille)) {
        commission_per_mille = NULL;
    }
    if (!commission_per_mille) {
        goto end;
    }

    
    if(!cJSON_IsNumber(commission_per_mille))
    {
    goto end; //Numeric
    }

    // transaction_partner->request_count
    cJSON *request_count = cJSON_GetObjectItemCaseSensitive(transaction_partnerJSON, "request_count");
    if (cJSON_IsNull(request_count)) {
        request_count = NULL;
    }
    if (!request_count) {
        goto end;
    }

    
    if(!cJSON_IsNumber(request_count))
    {
    goto end; //Numeric
    }

    // transaction_partner->affiliate
    cJSON *affiliate = cJSON_GetObjectItemCaseSensitive(transaction_partnerJSON, "affiliate");
    if (cJSON_IsNull(affiliate)) {
        affiliate = NULL;
    }
    if (affiliate) { 
    affiliate_local_nonprim = affiliate_info_parseFromJSON(affiliate); //nonprimitive
    }

    // transaction_partner->invoice_payload
    cJSON *invoice_payload = cJSON_GetObjectItemCaseSensitive(transaction_partnerJSON, "invoice_payload");
    if (cJSON_IsNull(invoice_payload)) {
        invoice_payload = NULL;
    }
    if (invoice_payload) { 
    if(!cJSON_IsString(invoice_payload) && !cJSON_IsNull(invoice_payload))
    {
    goto end; //String
    }
    }

    // transaction_partner->subscription_period
    cJSON *subscription_period = cJSON_GetObjectItemCaseSensitive(transaction_partnerJSON, "subscription_period");
    if (cJSON_IsNull(subscription_period)) {
        subscription_period = NULL;
    }
    if (subscription_period) { 
    if(!cJSON_IsNumber(subscription_period))
    {
    goto end; //Numeric
    }
    }

    // transaction_partner->paid_media
    cJSON *paid_media = cJSON_GetObjectItemCaseSensitive(transaction_partnerJSON, "paid_media");
    if (cJSON_IsNull(paid_media)) {
        paid_media = NULL;
    }
    if (paid_media) { 
    cJSON *paid_media_local_nonprimitive = NULL;
    if(!cJSON_IsArray(paid_media)){
        goto end; //nonprimitive container
    }

    paid_mediaList = list_createList();

    cJSON_ArrayForEach(paid_media_local_nonprimitive,paid_media )
    {
        if(!cJSON_IsObject(paid_media_local_nonprimitive)){
            goto end;
        }
        paid_media_t *paid_mediaItem = paid_media_parseFromJSON(paid_media_local_nonprimitive);

        list_addElement(paid_mediaList, paid_mediaItem);
    }
    }

    // transaction_partner->paid_media_payload
    cJSON *paid_media_payload = cJSON_GetObjectItemCaseSensitive(transaction_partnerJSON, "paid_media_payload");
    if (cJSON_IsNull(paid_media_payload)) {
        paid_media_payload = NULL;
    }
    if (paid_media_payload) { 
    if(!cJSON_IsString(paid_media_payload) && !cJSON_IsNull(paid_media_payload))
    {
    goto end; //String
    }
    }

    // transaction_partner->gift
    cJSON *gift = cJSON_GetObjectItemCaseSensitive(transaction_partnerJSON, "gift");
    if (cJSON_IsNull(gift)) {
        gift = NULL;
    }
    if (gift) { 
    gift_local_nonprim = gift_parseFromJSON(gift); //nonprimitive
    }

    // transaction_partner->premium_subscription_duration
    cJSON *premium_subscription_duration = cJSON_GetObjectItemCaseSensitive(transaction_partnerJSON, "premium_subscription_duration");
    if (cJSON_IsNull(premium_subscription_duration)) {
        premium_subscription_duration = NULL;
    }
    if (premium_subscription_duration) { 
    if(!cJSON_IsNumber(premium_subscription_duration))
    {
    goto end; //Numeric
    }
    }

    // transaction_partner->sponsor_user
    cJSON *sponsor_user = cJSON_GetObjectItemCaseSensitive(transaction_partnerJSON, "sponsor_user");
    if (cJSON_IsNull(sponsor_user)) {
        sponsor_user = NULL;
    }
    if (sponsor_user) { 
    sponsor_user_local_nonprim = user_parseFromJSON(sponsor_user); //nonprimitive
    }

    // transaction_partner->withdrawal_state
    cJSON *withdrawal_state = cJSON_GetObjectItemCaseSensitive(transaction_partnerJSON, "withdrawal_state");
    if (cJSON_IsNull(withdrawal_state)) {
        withdrawal_state = NULL;
    }
    if (withdrawal_state) { 
    withdrawal_state_local_nonprim = revenue_withdrawal_state_parseFromJSON(withdrawal_state); //nonprimitive
    }


    transaction_partner_local_var = transaction_partner_create_internal (
        strdup(type->valuestring),
        transaction_typeVariable,
        user_local_nonprim,
        chat_local_nonprim,
        commission_per_mille->valuedouble,
        request_count->valuedouble,
        affiliate ? affiliate_local_nonprim : NULL,
        invoice_payload && !cJSON_IsNull(invoice_payload) ? strdup(invoice_payload->valuestring) : NULL,
        subscription_period ? subscription_period->valuedouble : 0,
        paid_media ? paid_mediaList : NULL,
        paid_media_payload && !cJSON_IsNull(paid_media_payload) ? strdup(paid_media_payload->valuestring) : NULL,
        gift ? gift_local_nonprim : NULL,
        premium_subscription_duration ? premium_subscription_duration->valuedouble : 0,
        sponsor_user ? sponsor_user_local_nonprim : NULL,
        withdrawal_state ? withdrawal_state_local_nonprim : NULL
        );

    return transaction_partner_local_var;
end:
    if (user_local_nonprim) {
        user_free(user_local_nonprim);
        user_local_nonprim = NULL;
    }
    if (chat_local_nonprim) {
        chat_free(chat_local_nonprim);
        chat_local_nonprim = NULL;
    }
    if (affiliate_local_nonprim) {
        affiliate_info_free(affiliate_local_nonprim);
        affiliate_local_nonprim = NULL;
    }
    if (paid_mediaList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, paid_mediaList) {
            paid_media_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(paid_mediaList);
        paid_mediaList = NULL;
    }
    if (gift_local_nonprim) {
        gift_free(gift_local_nonprim);
        gift_local_nonprim = NULL;
    }
    if (sponsor_user_local_nonprim) {
        user_free(sponsor_user_local_nonprim);
        sponsor_user_local_nonprim = NULL;
    }
    if (withdrawal_state_local_nonprim) {
        revenue_withdrawal_state_free(withdrawal_state_local_nonprim);
        withdrawal_state_local_nonprim = NULL;
    }
    return NULL;

}
