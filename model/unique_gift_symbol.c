#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "unique_gift_symbol.h"



static unique_gift_symbol_t *unique_gift_symbol_create_internal(
    char *name,
    sticker_t *sticker,
    int rarity_per_mille
    ) {
    unique_gift_symbol_t *unique_gift_symbol_local_var = malloc(sizeof(unique_gift_symbol_t));
    if (!unique_gift_symbol_local_var) {
        return NULL;
    }
    unique_gift_symbol_local_var->name = name;
    unique_gift_symbol_local_var->sticker = sticker;
    unique_gift_symbol_local_var->rarity_per_mille = rarity_per_mille;

    unique_gift_symbol_local_var->_library_owned = 1;
    return unique_gift_symbol_local_var;
}

__attribute__((deprecated)) unique_gift_symbol_t *unique_gift_symbol_create(
    char *name,
    sticker_t *sticker,
    int rarity_per_mille
    ) {
    return unique_gift_symbol_create_internal (
        name,
        sticker,
        rarity_per_mille
        );
}

void unique_gift_symbol_free(unique_gift_symbol_t *unique_gift_symbol) {
    if(NULL == unique_gift_symbol){
        return ;
    }
    if(unique_gift_symbol->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "unique_gift_symbol_free");
        return ;
    }
    listEntry_t *listEntry;
    if (unique_gift_symbol->name) {
        free(unique_gift_symbol->name);
        unique_gift_symbol->name = NULL;
    }
    if (unique_gift_symbol->sticker) {
        sticker_free(unique_gift_symbol->sticker);
        unique_gift_symbol->sticker = NULL;
    }
    free(unique_gift_symbol);
}

cJSON *unique_gift_symbol_convertToJSON(unique_gift_symbol_t *unique_gift_symbol) {
    cJSON *item = cJSON_CreateObject();

    // unique_gift_symbol->name
    if (!unique_gift_symbol->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", unique_gift_symbol->name) == NULL) {
    goto fail; //String
    }


    // unique_gift_symbol->sticker
    if (!unique_gift_symbol->sticker) {
        goto fail;
    }
    cJSON *sticker_local_JSON = sticker_convertToJSON(unique_gift_symbol->sticker);
    if(sticker_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "sticker", sticker_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // unique_gift_symbol->rarity_per_mille
    if (!unique_gift_symbol->rarity_per_mille) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "rarity_per_mille", unique_gift_symbol->rarity_per_mille) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

unique_gift_symbol_t *unique_gift_symbol_parseFromJSON(cJSON *unique_gift_symbolJSON){

    unique_gift_symbol_t *unique_gift_symbol_local_var = NULL;

    // define the local variable for unique_gift_symbol->sticker
    sticker_t *sticker_local_nonprim = NULL;

    // unique_gift_symbol->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(unique_gift_symbolJSON, "name");
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

    // unique_gift_symbol->sticker
    cJSON *sticker = cJSON_GetObjectItemCaseSensitive(unique_gift_symbolJSON, "sticker");
    if (cJSON_IsNull(sticker)) {
        sticker = NULL;
    }
    if (!sticker) {
        goto end;
    }

    
    sticker_local_nonprim = sticker_parseFromJSON(sticker); //nonprimitive

    // unique_gift_symbol->rarity_per_mille
    cJSON *rarity_per_mille = cJSON_GetObjectItemCaseSensitive(unique_gift_symbolJSON, "rarity_per_mille");
    if (cJSON_IsNull(rarity_per_mille)) {
        rarity_per_mille = NULL;
    }
    if (!rarity_per_mille) {
        goto end;
    }

    
    if(!cJSON_IsNumber(rarity_per_mille))
    {
    goto end; //Numeric
    }


    unique_gift_symbol_local_var = unique_gift_symbol_create_internal (
        strdup(name->valuestring),
        sticker_local_nonprim,
        rarity_per_mille->valuedouble
        );

    return unique_gift_symbol_local_var;
end:
    if (sticker_local_nonprim) {
        sticker_free(sticker_local_nonprim);
        sticker_local_nonprim = NULL;
    }
    return NULL;

}
