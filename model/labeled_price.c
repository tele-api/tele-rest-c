#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "labeled_price.h"



static labeled_price_t *labeled_price_create_internal(
    char *label,
    int amount
    ) {
    labeled_price_t *labeled_price_local_var = malloc(sizeof(labeled_price_t));
    if (!labeled_price_local_var) {
        return NULL;
    }
    labeled_price_local_var->label = label;
    labeled_price_local_var->amount = amount;

    labeled_price_local_var->_library_owned = 1;
    return labeled_price_local_var;
}

__attribute__((deprecated)) labeled_price_t *labeled_price_create(
    char *label,
    int amount
    ) {
    return labeled_price_create_internal (
        label,
        amount
        );
}

void labeled_price_free(labeled_price_t *labeled_price) {
    if(NULL == labeled_price){
        return ;
    }
    if(labeled_price->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "labeled_price_free");
        return ;
    }
    listEntry_t *listEntry;
    if (labeled_price->label) {
        free(labeled_price->label);
        labeled_price->label = NULL;
    }
    free(labeled_price);
}

cJSON *labeled_price_convertToJSON(labeled_price_t *labeled_price) {
    cJSON *item = cJSON_CreateObject();

    // labeled_price->label
    if (!labeled_price->label) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "label", labeled_price->label) == NULL) {
    goto fail; //String
    }


    // labeled_price->amount
    if (!labeled_price->amount) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "amount", labeled_price->amount) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

labeled_price_t *labeled_price_parseFromJSON(cJSON *labeled_priceJSON){

    labeled_price_t *labeled_price_local_var = NULL;

    // labeled_price->label
    cJSON *label = cJSON_GetObjectItemCaseSensitive(labeled_priceJSON, "label");
    if (cJSON_IsNull(label)) {
        label = NULL;
    }
    if (!label) {
        goto end;
    }

    
    if(!cJSON_IsString(label))
    {
    goto end; //String
    }

    // labeled_price->amount
    cJSON *amount = cJSON_GetObjectItemCaseSensitive(labeled_priceJSON, "amount");
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


    labeled_price_local_var = labeled_price_create_internal (
        strdup(label->valuestring),
        amount->valuedouble
        );

    return labeled_price_local_var;
end:
    return NULL;

}
