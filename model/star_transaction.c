#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "star_transaction.h"



static star_transaction_t *star_transaction_create_internal(
    char *id,
    int amount,
    int date,
    int nanostar_amount,
    transaction_partner_t *source,
    transaction_partner_t *receiver
    ) {
    star_transaction_t *star_transaction_local_var = malloc(sizeof(star_transaction_t));
    if (!star_transaction_local_var) {
        return NULL;
    }
    star_transaction_local_var->id = id;
    star_transaction_local_var->amount = amount;
    star_transaction_local_var->date = date;
    star_transaction_local_var->nanostar_amount = nanostar_amount;
    star_transaction_local_var->source = source;
    star_transaction_local_var->receiver = receiver;

    star_transaction_local_var->_library_owned = 1;
    return star_transaction_local_var;
}

__attribute__((deprecated)) star_transaction_t *star_transaction_create(
    char *id,
    int amount,
    int date,
    int nanostar_amount,
    transaction_partner_t *source,
    transaction_partner_t *receiver
    ) {
    return star_transaction_create_internal (
        id,
        amount,
        date,
        nanostar_amount,
        source,
        receiver
        );
}

void star_transaction_free(star_transaction_t *star_transaction) {
    if(NULL == star_transaction){
        return ;
    }
    if(star_transaction->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "star_transaction_free");
        return ;
    }
    listEntry_t *listEntry;
    if (star_transaction->id) {
        free(star_transaction->id);
        star_transaction->id = NULL;
    }
    if (star_transaction->source) {
        transaction_partner_free(star_transaction->source);
        star_transaction->source = NULL;
    }
    if (star_transaction->receiver) {
        transaction_partner_free(star_transaction->receiver);
        star_transaction->receiver = NULL;
    }
    free(star_transaction);
}

cJSON *star_transaction_convertToJSON(star_transaction_t *star_transaction) {
    cJSON *item = cJSON_CreateObject();

    // star_transaction->id
    if (!star_transaction->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", star_transaction->id) == NULL) {
    goto fail; //String
    }


    // star_transaction->amount
    if (!star_transaction->amount) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "amount", star_transaction->amount) == NULL) {
    goto fail; //Numeric
    }


    // star_transaction->date
    if (!star_transaction->date) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "date", star_transaction->date) == NULL) {
    goto fail; //Numeric
    }


    // star_transaction->nanostar_amount
    if(star_transaction->nanostar_amount) {
    if(cJSON_AddNumberToObject(item, "nanostar_amount", star_transaction->nanostar_amount) == NULL) {
    goto fail; //Numeric
    }
    }


    // star_transaction->source
    if(star_transaction->source) {
    cJSON *source_local_JSON = transaction_partner_convertToJSON(star_transaction->source);
    if(source_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "source", source_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // star_transaction->receiver
    if(star_transaction->receiver) {
    cJSON *receiver_local_JSON = transaction_partner_convertToJSON(star_transaction->receiver);
    if(receiver_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "receiver", receiver_local_JSON);
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

star_transaction_t *star_transaction_parseFromJSON(cJSON *star_transactionJSON){

    star_transaction_t *star_transaction_local_var = NULL;

    // define the local variable for star_transaction->source
    transaction_partner_t *source_local_nonprim = NULL;

    // define the local variable for star_transaction->receiver
    transaction_partner_t *receiver_local_nonprim = NULL;

    // star_transaction->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(star_transactionJSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (!id) {
        goto end;
    }

    
    if(!cJSON_IsString(id))
    {
    goto end; //String
    }

    // star_transaction->amount
    cJSON *amount = cJSON_GetObjectItemCaseSensitive(star_transactionJSON, "amount");
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

    // star_transaction->date
    cJSON *date = cJSON_GetObjectItemCaseSensitive(star_transactionJSON, "date");
    if (cJSON_IsNull(date)) {
        date = NULL;
    }
    if (!date) {
        goto end;
    }

    
    if(!cJSON_IsNumber(date))
    {
    goto end; //Numeric
    }

    // star_transaction->nanostar_amount
    cJSON *nanostar_amount = cJSON_GetObjectItemCaseSensitive(star_transactionJSON, "nanostar_amount");
    if (cJSON_IsNull(nanostar_amount)) {
        nanostar_amount = NULL;
    }
    if (nanostar_amount) { 
    if(!cJSON_IsNumber(nanostar_amount))
    {
    goto end; //Numeric
    }
    }

    // star_transaction->source
    cJSON *source = cJSON_GetObjectItemCaseSensitive(star_transactionJSON, "source");
    if (cJSON_IsNull(source)) {
        source = NULL;
    }
    if (source) { 
    source_local_nonprim = transaction_partner_parseFromJSON(source); //nonprimitive
    }

    // star_transaction->receiver
    cJSON *receiver = cJSON_GetObjectItemCaseSensitive(star_transactionJSON, "receiver");
    if (cJSON_IsNull(receiver)) {
        receiver = NULL;
    }
    if (receiver) { 
    receiver_local_nonprim = transaction_partner_parseFromJSON(receiver); //nonprimitive
    }


    star_transaction_local_var = star_transaction_create_internal (
        strdup(id->valuestring),
        amount->valuedouble,
        date->valuedouble,
        nanostar_amount ? nanostar_amount->valuedouble : 0,
        source ? source_local_nonprim : NULL,
        receiver ? receiver_local_nonprim : NULL
        );

    return star_transaction_local_var;
end:
    if (source_local_nonprim) {
        transaction_partner_free(source_local_nonprim);
        source_local_nonprim = NULL;
    }
    if (receiver_local_nonprim) {
        transaction_partner_free(receiver_local_nonprim);
        receiver_local_nonprim = NULL;
    }
    return NULL;

}
