#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "transaction_partner_user.h"


char* transaction_partner_user_transaction_type_ToString(telegram_bot_api_transaction_partner_user_TRANSACTIONTYPE_e transaction_type) {
    char* transaction_typeArray[] =  { "NULL", "invoice_payment", "paid_media_payment", "gift_purchase", "premium_purchase", "business_account_transfer" };
    return transaction_typeArray[transaction_type];
}

telegram_bot_api_transaction_partner_user_TRANSACTIONTYPE_e transaction_partner_user_transaction_type_FromString(char* transaction_type){
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

static transaction_partner_user_t *transaction_partner_user_create_internal(
    char *type,
    telegram_bot_api_transaction_partner_user_TRANSACTIONTYPE_e transaction_type,
    user_t *user,
    affiliate_info_t *affiliate,
    char *invoice_payload,
    int subscription_period,
    list_t *paid_media,
    char *paid_media_payload,
    gift_t *gift,
    int premium_subscription_duration
    ) {
    transaction_partner_user_t *transaction_partner_user_local_var = malloc(sizeof(transaction_partner_user_t));
    if (!transaction_partner_user_local_var) {
        return NULL;
    }
    transaction_partner_user_local_var->type = type;
    transaction_partner_user_local_var->transaction_type = transaction_type;
    transaction_partner_user_local_var->user = user;
    transaction_partner_user_local_var->affiliate = affiliate;
    transaction_partner_user_local_var->invoice_payload = invoice_payload;
    transaction_partner_user_local_var->subscription_period = subscription_period;
    transaction_partner_user_local_var->paid_media = paid_media;
    transaction_partner_user_local_var->paid_media_payload = paid_media_payload;
    transaction_partner_user_local_var->gift = gift;
    transaction_partner_user_local_var->premium_subscription_duration = premium_subscription_duration;

    transaction_partner_user_local_var->_library_owned = 1;
    return transaction_partner_user_local_var;
}

__attribute__((deprecated)) transaction_partner_user_t *transaction_partner_user_create(
    char *type,
    telegram_bot_api_transaction_partner_user_TRANSACTIONTYPE_e transaction_type,
    user_t *user,
    affiliate_info_t *affiliate,
    char *invoice_payload,
    int subscription_period,
    list_t *paid_media,
    char *paid_media_payload,
    gift_t *gift,
    int premium_subscription_duration
    ) {
    return transaction_partner_user_create_internal (
        type,
        transaction_type,
        user,
        affiliate,
        invoice_payload,
        subscription_period,
        paid_media,
        paid_media_payload,
        gift,
        premium_subscription_duration
        );
}

void transaction_partner_user_free(transaction_partner_user_t *transaction_partner_user) {
    if(NULL == transaction_partner_user){
        return ;
    }
    if(transaction_partner_user->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "transaction_partner_user_free");
        return ;
    }
    listEntry_t *listEntry;
    if (transaction_partner_user->type) {
        free(transaction_partner_user->type);
        transaction_partner_user->type = NULL;
    }
    if (transaction_partner_user->user) {
        user_free(transaction_partner_user->user);
        transaction_partner_user->user = NULL;
    }
    if (transaction_partner_user->affiliate) {
        affiliate_info_free(transaction_partner_user->affiliate);
        transaction_partner_user->affiliate = NULL;
    }
    if (transaction_partner_user->invoice_payload) {
        free(transaction_partner_user->invoice_payload);
        transaction_partner_user->invoice_payload = NULL;
    }
    if (transaction_partner_user->paid_media) {
        list_ForEach(listEntry, transaction_partner_user->paid_media) {
            paid_media_free(listEntry->data);
        }
        list_freeList(transaction_partner_user->paid_media);
        transaction_partner_user->paid_media = NULL;
    }
    if (transaction_partner_user->paid_media_payload) {
        free(transaction_partner_user->paid_media_payload);
        transaction_partner_user->paid_media_payload = NULL;
    }
    if (transaction_partner_user->gift) {
        gift_free(transaction_partner_user->gift);
        transaction_partner_user->gift = NULL;
    }
    free(transaction_partner_user);
}

cJSON *transaction_partner_user_convertToJSON(transaction_partner_user_t *transaction_partner_user) {
    cJSON *item = cJSON_CreateObject();

    // transaction_partner_user->type
    if (!transaction_partner_user->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", transaction_partner_user->type) == NULL) {
    goto fail; //String
    }


    // transaction_partner_user->transaction_type
    if (telegram_bot_api_transaction_partner_user_TRANSACTIONTYPE_NULL == transaction_partner_user->transaction_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "transaction_type", transaction_partner_user_transaction_type_ToString(transaction_partner_user->transaction_type)) == NULL)
    {
    goto fail; //Enum
    }


    // transaction_partner_user->user
    if (!transaction_partner_user->user) {
        goto fail;
    }
    cJSON *user_local_JSON = user_convertToJSON(transaction_partner_user->user);
    if(user_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "user", user_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // transaction_partner_user->affiliate
    if(transaction_partner_user->affiliate) {
    cJSON *affiliate_local_JSON = affiliate_info_convertToJSON(transaction_partner_user->affiliate);
    if(affiliate_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "affiliate", affiliate_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // transaction_partner_user->invoice_payload
    if(transaction_partner_user->invoice_payload) {
    if(cJSON_AddStringToObject(item, "invoice_payload", transaction_partner_user->invoice_payload) == NULL) {
    goto fail; //String
    }
    }


    // transaction_partner_user->subscription_period
    if(transaction_partner_user->subscription_period) {
    if(cJSON_AddNumberToObject(item, "subscription_period", transaction_partner_user->subscription_period) == NULL) {
    goto fail; //Numeric
    }
    }


    // transaction_partner_user->paid_media
    if(transaction_partner_user->paid_media) {
    cJSON *paid_media = cJSON_AddArrayToObject(item, "paid_media");
    if(paid_media == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *paid_mediaListEntry;
    if (transaction_partner_user->paid_media) {
    list_ForEach(paid_mediaListEntry, transaction_partner_user->paid_media) {
    cJSON *itemLocal = paid_media_convertToJSON(paid_mediaListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(paid_media, itemLocal);
    }
    }
    }


    // transaction_partner_user->paid_media_payload
    if(transaction_partner_user->paid_media_payload) {
    if(cJSON_AddStringToObject(item, "paid_media_payload", transaction_partner_user->paid_media_payload) == NULL) {
    goto fail; //String
    }
    }


    // transaction_partner_user->gift
    if(transaction_partner_user->gift) {
    cJSON *gift_local_JSON = gift_convertToJSON(transaction_partner_user->gift);
    if(gift_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "gift", gift_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // transaction_partner_user->premium_subscription_duration
    if(transaction_partner_user->premium_subscription_duration) {
    if(cJSON_AddNumberToObject(item, "premium_subscription_duration", transaction_partner_user->premium_subscription_duration) == NULL) {
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

transaction_partner_user_t *transaction_partner_user_parseFromJSON(cJSON *transaction_partner_userJSON){

    transaction_partner_user_t *transaction_partner_user_local_var = NULL;

    // define the local variable for transaction_partner_user->user
    user_t *user_local_nonprim = NULL;

    // define the local variable for transaction_partner_user->affiliate
    affiliate_info_t *affiliate_local_nonprim = NULL;

    // define the local list for transaction_partner_user->paid_media
    list_t *paid_mediaList = NULL;

    // define the local variable for transaction_partner_user->gift
    gift_t *gift_local_nonprim = NULL;

    // transaction_partner_user->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(transaction_partner_userJSON, "type");
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

    // transaction_partner_user->transaction_type
    cJSON *transaction_type = cJSON_GetObjectItemCaseSensitive(transaction_partner_userJSON, "transaction_type");
    if (cJSON_IsNull(transaction_type)) {
        transaction_type = NULL;
    }
    if (!transaction_type) {
        goto end;
    }

    telegram_bot_api_transaction_partner_user_TRANSACTIONTYPE_e transaction_typeVariable;
    
    if(!cJSON_IsString(transaction_type))
    {
    goto end; //Enum
    }
    transaction_typeVariable = transaction_partner_user_transaction_type_FromString(transaction_type->valuestring);

    // transaction_partner_user->user
    cJSON *user = cJSON_GetObjectItemCaseSensitive(transaction_partner_userJSON, "user");
    if (cJSON_IsNull(user)) {
        user = NULL;
    }
    if (!user) {
        goto end;
    }

    
    user_local_nonprim = user_parseFromJSON(user); //nonprimitive

    // transaction_partner_user->affiliate
    cJSON *affiliate = cJSON_GetObjectItemCaseSensitive(transaction_partner_userJSON, "affiliate");
    if (cJSON_IsNull(affiliate)) {
        affiliate = NULL;
    }
    if (affiliate) { 
    affiliate_local_nonprim = affiliate_info_parseFromJSON(affiliate); //nonprimitive
    }

    // transaction_partner_user->invoice_payload
    cJSON *invoice_payload = cJSON_GetObjectItemCaseSensitive(transaction_partner_userJSON, "invoice_payload");
    if (cJSON_IsNull(invoice_payload)) {
        invoice_payload = NULL;
    }
    if (invoice_payload) { 
    if(!cJSON_IsString(invoice_payload) && !cJSON_IsNull(invoice_payload))
    {
    goto end; //String
    }
    }

    // transaction_partner_user->subscription_period
    cJSON *subscription_period = cJSON_GetObjectItemCaseSensitive(transaction_partner_userJSON, "subscription_period");
    if (cJSON_IsNull(subscription_period)) {
        subscription_period = NULL;
    }
    if (subscription_period) { 
    if(!cJSON_IsNumber(subscription_period))
    {
    goto end; //Numeric
    }
    }

    // transaction_partner_user->paid_media
    cJSON *paid_media = cJSON_GetObjectItemCaseSensitive(transaction_partner_userJSON, "paid_media");
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

    // transaction_partner_user->paid_media_payload
    cJSON *paid_media_payload = cJSON_GetObjectItemCaseSensitive(transaction_partner_userJSON, "paid_media_payload");
    if (cJSON_IsNull(paid_media_payload)) {
        paid_media_payload = NULL;
    }
    if (paid_media_payload) { 
    if(!cJSON_IsString(paid_media_payload) && !cJSON_IsNull(paid_media_payload))
    {
    goto end; //String
    }
    }

    // transaction_partner_user->gift
    cJSON *gift = cJSON_GetObjectItemCaseSensitive(transaction_partner_userJSON, "gift");
    if (cJSON_IsNull(gift)) {
        gift = NULL;
    }
    if (gift) { 
    gift_local_nonprim = gift_parseFromJSON(gift); //nonprimitive
    }

    // transaction_partner_user->premium_subscription_duration
    cJSON *premium_subscription_duration = cJSON_GetObjectItemCaseSensitive(transaction_partner_userJSON, "premium_subscription_duration");
    if (cJSON_IsNull(premium_subscription_duration)) {
        premium_subscription_duration = NULL;
    }
    if (premium_subscription_duration) { 
    if(!cJSON_IsNumber(premium_subscription_duration))
    {
    goto end; //Numeric
    }
    }


    transaction_partner_user_local_var = transaction_partner_user_create_internal (
        strdup(type->valuestring),
        transaction_typeVariable,
        user_local_nonprim,
        affiliate ? affiliate_local_nonprim : NULL,
        invoice_payload && !cJSON_IsNull(invoice_payload) ? strdup(invoice_payload->valuestring) : NULL,
        subscription_period ? subscription_period->valuedouble : 0,
        paid_media ? paid_mediaList : NULL,
        paid_media_payload && !cJSON_IsNull(paid_media_payload) ? strdup(paid_media_payload->valuestring) : NULL,
        gift ? gift_local_nonprim : NULL,
        premium_subscription_duration ? premium_subscription_duration->valuedouble : 0
        );

    return transaction_partner_user_local_var;
end:
    if (user_local_nonprim) {
        user_free(user_local_nonprim);
        user_local_nonprim = NULL;
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
    return NULL;

}
