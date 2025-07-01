#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "transaction_partner_chat.h"



static transaction_partner_chat_t *transaction_partner_chat_create_internal(
    char *type,
    chat_t *chat,
    gift_t *gift
    ) {
    transaction_partner_chat_t *transaction_partner_chat_local_var = malloc(sizeof(transaction_partner_chat_t));
    if (!transaction_partner_chat_local_var) {
        return NULL;
    }
    transaction_partner_chat_local_var->type = type;
    transaction_partner_chat_local_var->chat = chat;
    transaction_partner_chat_local_var->gift = gift;

    transaction_partner_chat_local_var->_library_owned = 1;
    return transaction_partner_chat_local_var;
}

__attribute__((deprecated)) transaction_partner_chat_t *transaction_partner_chat_create(
    char *type,
    chat_t *chat,
    gift_t *gift
    ) {
    return transaction_partner_chat_create_internal (
        type,
        chat,
        gift
        );
}

void transaction_partner_chat_free(transaction_partner_chat_t *transaction_partner_chat) {
    if(NULL == transaction_partner_chat){
        return ;
    }
    if(transaction_partner_chat->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "transaction_partner_chat_free");
        return ;
    }
    listEntry_t *listEntry;
    if (transaction_partner_chat->type) {
        free(transaction_partner_chat->type);
        transaction_partner_chat->type = NULL;
    }
    if (transaction_partner_chat->chat) {
        chat_free(transaction_partner_chat->chat);
        transaction_partner_chat->chat = NULL;
    }
    if (transaction_partner_chat->gift) {
        gift_free(transaction_partner_chat->gift);
        transaction_partner_chat->gift = NULL;
    }
    free(transaction_partner_chat);
}

cJSON *transaction_partner_chat_convertToJSON(transaction_partner_chat_t *transaction_partner_chat) {
    cJSON *item = cJSON_CreateObject();

    // transaction_partner_chat->type
    if (!transaction_partner_chat->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", transaction_partner_chat->type) == NULL) {
    goto fail; //String
    }


    // transaction_partner_chat->chat
    if (!transaction_partner_chat->chat) {
        goto fail;
    }
    cJSON *chat_local_JSON = chat_convertToJSON(transaction_partner_chat->chat);
    if(chat_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat", chat_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // transaction_partner_chat->gift
    if(transaction_partner_chat->gift) {
    cJSON *gift_local_JSON = gift_convertToJSON(transaction_partner_chat->gift);
    if(gift_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "gift", gift_local_JSON);
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

transaction_partner_chat_t *transaction_partner_chat_parseFromJSON(cJSON *transaction_partner_chatJSON){

    transaction_partner_chat_t *transaction_partner_chat_local_var = NULL;

    // define the local variable for transaction_partner_chat->chat
    chat_t *chat_local_nonprim = NULL;

    // define the local variable for transaction_partner_chat->gift
    gift_t *gift_local_nonprim = NULL;

    // transaction_partner_chat->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(transaction_partner_chatJSON, "type");
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

    // transaction_partner_chat->chat
    cJSON *chat = cJSON_GetObjectItemCaseSensitive(transaction_partner_chatJSON, "chat");
    if (cJSON_IsNull(chat)) {
        chat = NULL;
    }
    if (!chat) {
        goto end;
    }

    
    chat_local_nonprim = chat_parseFromJSON(chat); //nonprimitive

    // transaction_partner_chat->gift
    cJSON *gift = cJSON_GetObjectItemCaseSensitive(transaction_partner_chatJSON, "gift");
    if (cJSON_IsNull(gift)) {
        gift = NULL;
    }
    if (gift) { 
    gift_local_nonprim = gift_parseFromJSON(gift); //nonprimitive
    }


    transaction_partner_chat_local_var = transaction_partner_chat_create_internal (
        strdup(type->valuestring),
        chat_local_nonprim,
        gift ? gift_local_nonprim : NULL
        );

    return transaction_partner_chat_local_var;
end:
    if (chat_local_nonprim) {
        chat_free(chat_local_nonprim);
        chat_local_nonprim = NULL;
    }
    if (gift_local_nonprim) {
        gift_free(gift_local_nonprim);
        gift_local_nonprim = NULL;
    }
    return NULL;

}
