#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "gifts.h"



static gifts_t *gifts_create_internal(
    list_t *gifts
    ) {
    gifts_t *gifts_local_var = malloc(sizeof(gifts_t));
    if (!gifts_local_var) {
        return NULL;
    }
    gifts_local_var->gifts = gifts;

    gifts_local_var->_library_owned = 1;
    return gifts_local_var;
}

__attribute__((deprecated)) gifts_t *gifts_create(
    list_t *gifts
    ) {
    return gifts_create_internal (
        gifts
        );
}

void gifts_free(gifts_t *gifts) {
    if(NULL == gifts){
        return ;
    }
    if(gifts->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "gifts_free");
        return ;
    }
    listEntry_t *listEntry;
    if (gifts->gifts) {
        list_ForEach(listEntry, gifts->gifts) {
            gift_free(listEntry->data);
        }
        list_freeList(gifts->gifts);
        gifts->gifts = NULL;
    }
    free(gifts);
}

cJSON *gifts_convertToJSON(gifts_t *gifts) {
    cJSON *item = cJSON_CreateObject();

    // gifts->gifts
    if (!gifts->gifts) {
        goto fail;
    }
    cJSON *gifts = cJSON_AddArrayToObject(item, "gifts");
    if(gifts == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *giftsListEntry;
    if (gifts->gifts) {
    list_ForEach(giftsListEntry, gifts->gifts) {
    cJSON *itemLocal = gift_convertToJSON(giftsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(gifts, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

gifts_t *gifts_parseFromJSON(cJSON *giftsJSON){

    gifts_t *gifts_local_var = NULL;

    // define the local list for gifts->gifts
    list_t *giftsList = NULL;

    // gifts->gifts
    cJSON *gifts = cJSON_GetObjectItemCaseSensitive(giftsJSON, "gifts");
    if (cJSON_IsNull(gifts)) {
        gifts = NULL;
    }
    if (!gifts) {
        goto end;
    }

    
    cJSON *gifts_local_nonprimitive = NULL;
    if(!cJSON_IsArray(gifts)){
        goto end; //nonprimitive container
    }

    giftsList = list_createList();

    cJSON_ArrayForEach(gifts_local_nonprimitive,gifts )
    {
        if(!cJSON_IsObject(gifts_local_nonprimitive)){
            goto end;
        }
        gift_t *giftsItem = gift_parseFromJSON(gifts_local_nonprimitive);

        list_addElement(giftsList, giftsItem);
    }


    gifts_local_var = gifts_create_internal (
        giftsList
        );

    return gifts_local_var;
end:
    if (giftsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, giftsList) {
            gift_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(giftsList);
        giftsList = NULL;
    }
    return NULL;

}
