#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "unique_gift.h"



static unique_gift_t *unique_gift_create_internal(
    char *base_name,
    char *name,
    int number,
    unique_gift_model_t *model,
    unique_gift_symbol_t *symbol,
    unique_gift_backdrop_t *backdrop
    ) {
    unique_gift_t *unique_gift_local_var = malloc(sizeof(unique_gift_t));
    if (!unique_gift_local_var) {
        return NULL;
    }
    unique_gift_local_var->base_name = base_name;
    unique_gift_local_var->name = name;
    unique_gift_local_var->number = number;
    unique_gift_local_var->model = model;
    unique_gift_local_var->symbol = symbol;
    unique_gift_local_var->backdrop = backdrop;

    unique_gift_local_var->_library_owned = 1;
    return unique_gift_local_var;
}

__attribute__((deprecated)) unique_gift_t *unique_gift_create(
    char *base_name,
    char *name,
    int number,
    unique_gift_model_t *model,
    unique_gift_symbol_t *symbol,
    unique_gift_backdrop_t *backdrop
    ) {
    return unique_gift_create_internal (
        base_name,
        name,
        number,
        model,
        symbol,
        backdrop
        );
}

void unique_gift_free(unique_gift_t *unique_gift) {
    if(NULL == unique_gift){
        return ;
    }
    if(unique_gift->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "unique_gift_free");
        return ;
    }
    listEntry_t *listEntry;
    if (unique_gift->base_name) {
        free(unique_gift->base_name);
        unique_gift->base_name = NULL;
    }
    if (unique_gift->name) {
        free(unique_gift->name);
        unique_gift->name = NULL;
    }
    if (unique_gift->model) {
        unique_gift_model_free(unique_gift->model);
        unique_gift->model = NULL;
    }
    if (unique_gift->symbol) {
        unique_gift_symbol_free(unique_gift->symbol);
        unique_gift->symbol = NULL;
    }
    if (unique_gift->backdrop) {
        unique_gift_backdrop_free(unique_gift->backdrop);
        unique_gift->backdrop = NULL;
    }
    free(unique_gift);
}

cJSON *unique_gift_convertToJSON(unique_gift_t *unique_gift) {
    cJSON *item = cJSON_CreateObject();

    // unique_gift->base_name
    if (!unique_gift->base_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "base_name", unique_gift->base_name) == NULL) {
    goto fail; //String
    }


    // unique_gift->name
    if (!unique_gift->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", unique_gift->name) == NULL) {
    goto fail; //String
    }


    // unique_gift->number
    if (!unique_gift->number) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "number", unique_gift->number) == NULL) {
    goto fail; //Numeric
    }


    // unique_gift->model
    if (!unique_gift->model) {
        goto fail;
    }
    cJSON *model_local_JSON = unique_gift_model_convertToJSON(unique_gift->model);
    if(model_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "model", model_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // unique_gift->symbol
    if (!unique_gift->symbol) {
        goto fail;
    }
    cJSON *symbol_local_JSON = unique_gift_symbol_convertToJSON(unique_gift->symbol);
    if(symbol_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "symbol", symbol_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // unique_gift->backdrop
    if (!unique_gift->backdrop) {
        goto fail;
    }
    cJSON *backdrop_local_JSON = unique_gift_backdrop_convertToJSON(unique_gift->backdrop);
    if(backdrop_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "backdrop", backdrop_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

unique_gift_t *unique_gift_parseFromJSON(cJSON *unique_giftJSON){

    unique_gift_t *unique_gift_local_var = NULL;

    // define the local variable for unique_gift->model
    unique_gift_model_t *model_local_nonprim = NULL;

    // define the local variable for unique_gift->symbol
    unique_gift_symbol_t *symbol_local_nonprim = NULL;

    // define the local variable for unique_gift->backdrop
    unique_gift_backdrop_t *backdrop_local_nonprim = NULL;

    // unique_gift->base_name
    cJSON *base_name = cJSON_GetObjectItemCaseSensitive(unique_giftJSON, "base_name");
    if (cJSON_IsNull(base_name)) {
        base_name = NULL;
    }
    if (!base_name) {
        goto end;
    }

    
    if(!cJSON_IsString(base_name))
    {
    goto end; //String
    }

    // unique_gift->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(unique_giftJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // unique_gift->number
    cJSON *number = cJSON_GetObjectItemCaseSensitive(unique_giftJSON, "number");
    if (cJSON_IsNull(number)) {
        number = NULL;
    }
    if (!number) {
        goto end;
    }

    
    if(!cJSON_IsNumber(number))
    {
    goto end; //Numeric
    }

    // unique_gift->model
    cJSON *model = cJSON_GetObjectItemCaseSensitive(unique_giftJSON, "model");
    if (cJSON_IsNull(model)) {
        model = NULL;
    }
    if (!model) {
        goto end;
    }

    
    model_local_nonprim = unique_gift_model_parseFromJSON(model); //nonprimitive

    // unique_gift->symbol
    cJSON *symbol = cJSON_GetObjectItemCaseSensitive(unique_giftJSON, "symbol");
    if (cJSON_IsNull(symbol)) {
        symbol = NULL;
    }
    if (!symbol) {
        goto end;
    }

    
    symbol_local_nonprim = unique_gift_symbol_parseFromJSON(symbol); //nonprimitive

    // unique_gift->backdrop
    cJSON *backdrop = cJSON_GetObjectItemCaseSensitive(unique_giftJSON, "backdrop");
    if (cJSON_IsNull(backdrop)) {
        backdrop = NULL;
    }
    if (!backdrop) {
        goto end;
    }

    
    backdrop_local_nonprim = unique_gift_backdrop_parseFromJSON(backdrop); //nonprimitive


    unique_gift_local_var = unique_gift_create_internal (
        strdup(base_name->valuestring),
        strdup(name->valuestring),
        number->valuedouble,
        model_local_nonprim,
        symbol_local_nonprim,
        backdrop_local_nonprim
        );

    return unique_gift_local_var;
end:
    if (model_local_nonprim) {
        unique_gift_model_free(model_local_nonprim);
        model_local_nonprim = NULL;
    }
    if (symbol_local_nonprim) {
        unique_gift_symbol_free(symbol_local_nonprim);
        symbol_local_nonprim = NULL;
    }
    if (backdrop_local_nonprim) {
        unique_gift_backdrop_free(backdrop_local_nonprim);
        backdrop_local_nonprim = NULL;
    }
    return NULL;

}
