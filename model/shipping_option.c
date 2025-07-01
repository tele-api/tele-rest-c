#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "shipping_option.h"



static shipping_option_t *shipping_option_create_internal(
    char *id,
    char *title,
    list_t *prices
    ) {
    shipping_option_t *shipping_option_local_var = malloc(sizeof(shipping_option_t));
    if (!shipping_option_local_var) {
        return NULL;
    }
    shipping_option_local_var->id = id;
    shipping_option_local_var->title = title;
    shipping_option_local_var->prices = prices;

    shipping_option_local_var->_library_owned = 1;
    return shipping_option_local_var;
}

__attribute__((deprecated)) shipping_option_t *shipping_option_create(
    char *id,
    char *title,
    list_t *prices
    ) {
    return shipping_option_create_internal (
        id,
        title,
        prices
        );
}

void shipping_option_free(shipping_option_t *shipping_option) {
    if(NULL == shipping_option){
        return ;
    }
    if(shipping_option->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "shipping_option_free");
        return ;
    }
    listEntry_t *listEntry;
    if (shipping_option->id) {
        free(shipping_option->id);
        shipping_option->id = NULL;
    }
    if (shipping_option->title) {
        free(shipping_option->title);
        shipping_option->title = NULL;
    }
    if (shipping_option->prices) {
        list_ForEach(listEntry, shipping_option->prices) {
            labeled_price_free(listEntry->data);
        }
        list_freeList(shipping_option->prices);
        shipping_option->prices = NULL;
    }
    free(shipping_option);
}

cJSON *shipping_option_convertToJSON(shipping_option_t *shipping_option) {
    cJSON *item = cJSON_CreateObject();

    // shipping_option->id
    if (!shipping_option->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", shipping_option->id) == NULL) {
    goto fail; //String
    }


    // shipping_option->title
    if (!shipping_option->title) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "title", shipping_option->title) == NULL) {
    goto fail; //String
    }


    // shipping_option->prices
    if (!shipping_option->prices) {
        goto fail;
    }
    cJSON *prices = cJSON_AddArrayToObject(item, "prices");
    if(prices == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *pricesListEntry;
    if (shipping_option->prices) {
    list_ForEach(pricesListEntry, shipping_option->prices) {
    cJSON *itemLocal = labeled_price_convertToJSON(pricesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(prices, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

shipping_option_t *shipping_option_parseFromJSON(cJSON *shipping_optionJSON){

    shipping_option_t *shipping_option_local_var = NULL;

    // define the local list for shipping_option->prices
    list_t *pricesList = NULL;

    // shipping_option->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(shipping_optionJSON, "id");
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

    // shipping_option->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(shipping_optionJSON, "title");
    if (cJSON_IsNull(title)) {
        title = NULL;
    }
    if (!title) {
        goto end;
    }

    
    if(!cJSON_IsString(title))
    {
    goto end; //String
    }

    // shipping_option->prices
    cJSON *prices = cJSON_GetObjectItemCaseSensitive(shipping_optionJSON, "prices");
    if (cJSON_IsNull(prices)) {
        prices = NULL;
    }
    if (!prices) {
        goto end;
    }

    
    cJSON *prices_local_nonprimitive = NULL;
    if(!cJSON_IsArray(prices)){
        goto end; //nonprimitive container
    }

    pricesList = list_createList();

    cJSON_ArrayForEach(prices_local_nonprimitive,prices )
    {
        if(!cJSON_IsObject(prices_local_nonprimitive)){
            goto end;
        }
        labeled_price_t *pricesItem = labeled_price_parseFromJSON(prices_local_nonprimitive);

        list_addElement(pricesList, pricesItem);
    }


    shipping_option_local_var = shipping_option_create_internal (
        strdup(id->valuestring),
        strdup(title->valuestring),
        pricesList
        );

    return shipping_option_local_var;
end:
    if (pricesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, pricesList) {
            labeled_price_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(pricesList);
        pricesList = NULL;
    }
    return NULL;

}
