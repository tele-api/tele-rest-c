#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "star_amount.h"



static star_amount_t *star_amount_create_internal(
    int amount,
    int nanostar_amount
    ) {
    star_amount_t *star_amount_local_var = malloc(sizeof(star_amount_t));
    if (!star_amount_local_var) {
        return NULL;
    }
    star_amount_local_var->amount = amount;
    star_amount_local_var->nanostar_amount = nanostar_amount;

    star_amount_local_var->_library_owned = 1;
    return star_amount_local_var;
}

__attribute__((deprecated)) star_amount_t *star_amount_create(
    int amount,
    int nanostar_amount
    ) {
    return star_amount_create_internal (
        amount,
        nanostar_amount
        );
}

void star_amount_free(star_amount_t *star_amount) {
    if(NULL == star_amount){
        return ;
    }
    if(star_amount->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "star_amount_free");
        return ;
    }
    listEntry_t *listEntry;
    free(star_amount);
}

cJSON *star_amount_convertToJSON(star_amount_t *star_amount) {
    cJSON *item = cJSON_CreateObject();

    // star_amount->amount
    if (!star_amount->amount) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "amount", star_amount->amount) == NULL) {
    goto fail; //Numeric
    }


    // star_amount->nanostar_amount
    if(star_amount->nanostar_amount) {
    if(cJSON_AddNumberToObject(item, "nanostar_amount", star_amount->nanostar_amount) == NULL) {
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

star_amount_t *star_amount_parseFromJSON(cJSON *star_amountJSON){

    star_amount_t *star_amount_local_var = NULL;

    // star_amount->amount
    cJSON *amount = cJSON_GetObjectItemCaseSensitive(star_amountJSON, "amount");
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

    // star_amount->nanostar_amount
    cJSON *nanostar_amount = cJSON_GetObjectItemCaseSensitive(star_amountJSON, "nanostar_amount");
    if (cJSON_IsNull(nanostar_amount)) {
        nanostar_amount = NULL;
    }
    if (nanostar_amount) { 
    if(!cJSON_IsNumber(nanostar_amount))
    {
    goto end; //Numeric
    }
    }


    star_amount_local_var = star_amount_create_internal (
        amount->valuedouble,
        nanostar_amount ? nanostar_amount->valuedouble : 0
        );

    return star_amount_local_var;
end:
    return NULL;

}
