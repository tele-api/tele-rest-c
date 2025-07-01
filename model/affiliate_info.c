#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "affiliate_info.h"



static affiliate_info_t *affiliate_info_create_internal(
    int commission_per_mille,
    int amount,
    user_t *affiliate_user,
    chat_t *affiliate_chat,
    int nanostar_amount
    ) {
    affiliate_info_t *affiliate_info_local_var = malloc(sizeof(affiliate_info_t));
    if (!affiliate_info_local_var) {
        return NULL;
    }
    affiliate_info_local_var->commission_per_mille = commission_per_mille;
    affiliate_info_local_var->amount = amount;
    affiliate_info_local_var->affiliate_user = affiliate_user;
    affiliate_info_local_var->affiliate_chat = affiliate_chat;
    affiliate_info_local_var->nanostar_amount = nanostar_amount;

    affiliate_info_local_var->_library_owned = 1;
    return affiliate_info_local_var;
}

__attribute__((deprecated)) affiliate_info_t *affiliate_info_create(
    int commission_per_mille,
    int amount,
    user_t *affiliate_user,
    chat_t *affiliate_chat,
    int nanostar_amount
    ) {
    return affiliate_info_create_internal (
        commission_per_mille,
        amount,
        affiliate_user,
        affiliate_chat,
        nanostar_amount
        );
}

void affiliate_info_free(affiliate_info_t *affiliate_info) {
    if(NULL == affiliate_info){
        return ;
    }
    if(affiliate_info->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "affiliate_info_free");
        return ;
    }
    listEntry_t *listEntry;
    if (affiliate_info->affiliate_user) {
        user_free(affiliate_info->affiliate_user);
        affiliate_info->affiliate_user = NULL;
    }
    if (affiliate_info->affiliate_chat) {
        chat_free(affiliate_info->affiliate_chat);
        affiliate_info->affiliate_chat = NULL;
    }
    free(affiliate_info);
}

cJSON *affiliate_info_convertToJSON(affiliate_info_t *affiliate_info) {
    cJSON *item = cJSON_CreateObject();

    // affiliate_info->commission_per_mille
    if (!affiliate_info->commission_per_mille) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "commission_per_mille", affiliate_info->commission_per_mille) == NULL) {
    goto fail; //Numeric
    }


    // affiliate_info->amount
    if (!affiliate_info->amount) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "amount", affiliate_info->amount) == NULL) {
    goto fail; //Numeric
    }


    // affiliate_info->affiliate_user
    if(affiliate_info->affiliate_user) {
    cJSON *affiliate_user_local_JSON = user_convertToJSON(affiliate_info->affiliate_user);
    if(affiliate_user_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "affiliate_user", affiliate_user_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // affiliate_info->affiliate_chat
    if(affiliate_info->affiliate_chat) {
    cJSON *affiliate_chat_local_JSON = chat_convertToJSON(affiliate_info->affiliate_chat);
    if(affiliate_chat_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "affiliate_chat", affiliate_chat_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // affiliate_info->nanostar_amount
    if(affiliate_info->nanostar_amount) {
    if(cJSON_AddNumberToObject(item, "nanostar_amount", affiliate_info->nanostar_amount) == NULL) {
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

affiliate_info_t *affiliate_info_parseFromJSON(cJSON *affiliate_infoJSON){

    affiliate_info_t *affiliate_info_local_var = NULL;

    // define the local variable for affiliate_info->affiliate_user
    user_t *affiliate_user_local_nonprim = NULL;

    // define the local variable for affiliate_info->affiliate_chat
    chat_t *affiliate_chat_local_nonprim = NULL;

    // affiliate_info->commission_per_mille
    cJSON *commission_per_mille = cJSON_GetObjectItemCaseSensitive(affiliate_infoJSON, "commission_per_mille");
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

    // affiliate_info->amount
    cJSON *amount = cJSON_GetObjectItemCaseSensitive(affiliate_infoJSON, "amount");
    if (cJSON_IsNull(amount)) {
        amount = NULL;
    }
    if (!amount) {
        goto end;
    }

    
    if(!cJSON_IsNumber(amount))
    {
    goto end; //Numeric
    }

    // affiliate_info->affiliate_user
    cJSON *affiliate_user = cJSON_GetObjectItemCaseSensitive(affiliate_infoJSON, "affiliate_user");
    if (cJSON_IsNull(affiliate_user)) {
        affiliate_user = NULL;
    }
    if (affiliate_user) { 
    affiliate_user_local_nonprim = user_parseFromJSON(affiliate_user); //nonprimitive
    }

    // affiliate_info->affiliate_chat
    cJSON *affiliate_chat = cJSON_GetObjectItemCaseSensitive(affiliate_infoJSON, "affiliate_chat");
    if (cJSON_IsNull(affiliate_chat)) {
        affiliate_chat = NULL;
    }
    if (affiliate_chat) { 
    affiliate_chat_local_nonprim = chat_parseFromJSON(affiliate_chat); //nonprimitive
    }

    // affiliate_info->nanostar_amount
    cJSON *nanostar_amount = cJSON_GetObjectItemCaseSensitive(affiliate_infoJSON, "nanostar_amount");
    if (cJSON_IsNull(nanostar_amount)) {
        nanostar_amount = NULL;
    }
    if (nanostar_amount) { 
    if(!cJSON_IsNumber(nanostar_amount))
    {
    goto end; //Numeric
    }
    }


    affiliate_info_local_var = affiliate_info_create_internal (
        commission_per_mille->valuedouble,
        amount->valuedouble,
        affiliate_user ? affiliate_user_local_nonprim : NULL,
        affiliate_chat ? affiliate_chat_local_nonprim : NULL,
        nanostar_amount ? nanostar_amount->valuedouble : 0
        );

    return affiliate_info_local_var;
end:
    if (affiliate_user_local_nonprim) {
        user_free(affiliate_user_local_nonprim);
        affiliate_user_local_nonprim = NULL;
    }
    if (affiliate_chat_local_nonprim) {
        chat_free(affiliate_chat_local_nonprim);
        affiliate_chat_local_nonprim = NULL;
    }
    return NULL;

}
