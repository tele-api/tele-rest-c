#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "star_transactions.h"



static star_transactions_t *star_transactions_create_internal(
    list_t *transactions
    ) {
    star_transactions_t *star_transactions_local_var = malloc(sizeof(star_transactions_t));
    if (!star_transactions_local_var) {
        return NULL;
    }
    star_transactions_local_var->transactions = transactions;

    star_transactions_local_var->_library_owned = 1;
    return star_transactions_local_var;
}

__attribute__((deprecated)) star_transactions_t *star_transactions_create(
    list_t *transactions
    ) {
    return star_transactions_create_internal (
        transactions
        );
}

void star_transactions_free(star_transactions_t *star_transactions) {
    if(NULL == star_transactions){
        return ;
    }
    if(star_transactions->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "star_transactions_free");
        return ;
    }
    listEntry_t *listEntry;
    if (star_transactions->transactions) {
        list_ForEach(listEntry, star_transactions->transactions) {
            star_transaction_free(listEntry->data);
        }
        list_freeList(star_transactions->transactions);
        star_transactions->transactions = NULL;
    }
    free(star_transactions);
}

cJSON *star_transactions_convertToJSON(star_transactions_t *star_transactions) {
    cJSON *item = cJSON_CreateObject();

    // star_transactions->transactions
    if (!star_transactions->transactions) {
        goto fail;
    }
    cJSON *transactions = cJSON_AddArrayToObject(item, "transactions");
    if(transactions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *transactionsListEntry;
    if (star_transactions->transactions) {
    list_ForEach(transactionsListEntry, star_transactions->transactions) {
    cJSON *itemLocal = star_transaction_convertToJSON(transactionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(transactions, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

star_transactions_t *star_transactions_parseFromJSON(cJSON *star_transactionsJSON){

    star_transactions_t *star_transactions_local_var = NULL;

    // define the local list for star_transactions->transactions
    list_t *transactionsList = NULL;

    // star_transactions->transactions
    cJSON *transactions = cJSON_GetObjectItemCaseSensitive(star_transactionsJSON, "transactions");
    if (cJSON_IsNull(transactions)) {
        transactions = NULL;
    }
    if (!transactions) {
        goto end;
    }

    
    cJSON *transactions_local_nonprimitive = NULL;
    if(!cJSON_IsArray(transactions)){
        goto end; //nonprimitive container
    }

    transactionsList = list_createList();

    cJSON_ArrayForEach(transactions_local_nonprimitive,transactions )
    {
        if(!cJSON_IsObject(transactions_local_nonprimitive)){
            goto end;
        }
        star_transaction_t *transactionsItem = star_transaction_parseFromJSON(transactions_local_nonprimitive);

        list_addElement(transactionsList, transactionsItem);
    }


    star_transactions_local_var = star_transactions_create_internal (
        transactionsList
        );

    return star_transactions_local_var;
end:
    if (transactionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, transactionsList) {
            star_transaction_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(transactionsList);
        transactionsList = NULL;
    }
    return NULL;

}
