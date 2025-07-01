#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "owned_gifts.h"



static owned_gifts_t *owned_gifts_create_internal(
    int total_count,
    list_t *gifts,
    char *next_offset
    ) {
    owned_gifts_t *owned_gifts_local_var = malloc(sizeof(owned_gifts_t));
    if (!owned_gifts_local_var) {
        return NULL;
    }
    owned_gifts_local_var->total_count = total_count;
    owned_gifts_local_var->gifts = gifts;
    owned_gifts_local_var->next_offset = next_offset;

    owned_gifts_local_var->_library_owned = 1;
    return owned_gifts_local_var;
}

__attribute__((deprecated)) owned_gifts_t *owned_gifts_create(
    int total_count,
    list_t *gifts,
    char *next_offset
    ) {
    return owned_gifts_create_internal (
        total_count,
        gifts,
        next_offset
        );
}

void owned_gifts_free(owned_gifts_t *owned_gifts) {
    if(NULL == owned_gifts){
        return ;
    }
    if(owned_gifts->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "owned_gifts_free");
        return ;
    }
    listEntry_t *listEntry;
    if (owned_gifts->gifts) {
        list_ForEach(listEntry, owned_gifts->gifts) {
            owned_gift_free(listEntry->data);
        }
        list_freeList(owned_gifts->gifts);
        owned_gifts->gifts = NULL;
    }
    if (owned_gifts->next_offset) {
        free(owned_gifts->next_offset);
        owned_gifts->next_offset = NULL;
    }
    free(owned_gifts);
}

cJSON *owned_gifts_convertToJSON(owned_gifts_t *owned_gifts) {
    cJSON *item = cJSON_CreateObject();

    // owned_gifts->total_count
    if (!owned_gifts->total_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "total_count", owned_gifts->total_count) == NULL) {
    goto fail; //Numeric
    }


    // owned_gifts->gifts
    if (!owned_gifts->gifts) {
        goto fail;
    }
    cJSON *gifts = cJSON_AddArrayToObject(item, "gifts");
    if(gifts == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *giftsListEntry;
    if (owned_gifts->gifts) {
    list_ForEach(giftsListEntry, owned_gifts->gifts) {
    cJSON *itemLocal = owned_gift_convertToJSON(giftsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(gifts, itemLocal);
    }
    }


    // owned_gifts->next_offset
    if(owned_gifts->next_offset) {
    if(cJSON_AddStringToObject(item, "next_offset", owned_gifts->next_offset) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

owned_gifts_t *owned_gifts_parseFromJSON(cJSON *owned_giftsJSON){

    owned_gifts_t *owned_gifts_local_var = NULL;

    // define the local list for owned_gifts->gifts
    list_t *giftsList = NULL;

    // owned_gifts->total_count
    cJSON *total_count = cJSON_GetObjectItemCaseSensitive(owned_giftsJSON, "total_count");
    if (cJSON_IsNull(total_count)) {
        total_count = NULL;
    }
    if (!total_count) {
        goto end;
    }

    
    if(!cJSON_IsNumber(total_count))
    {
    goto end; //Numeric
    }

    // owned_gifts->gifts
    cJSON *gifts = cJSON_GetObjectItemCaseSensitive(owned_giftsJSON, "gifts");
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
        owned_gift_t *giftsItem = owned_gift_parseFromJSON(gifts_local_nonprimitive);

        list_addElement(giftsList, giftsItem);
    }

    // owned_gifts->next_offset
    cJSON *next_offset = cJSON_GetObjectItemCaseSensitive(owned_giftsJSON, "next_offset");
    if (cJSON_IsNull(next_offset)) {
        next_offset = NULL;
    }
    if (next_offset) { 
    if(!cJSON_IsString(next_offset) && !cJSON_IsNull(next_offset))
    {
    goto end; //String
    }
    }


    owned_gifts_local_var = owned_gifts_create_internal (
        total_count->valuedouble,
        giftsList,
        next_offset && !cJSON_IsNull(next_offset) ? strdup(next_offset->valuestring) : NULL
        );

    return owned_gifts_local_var;
end:
    if (giftsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, giftsList) {
            owned_gift_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(giftsList);
        giftsList = NULL;
    }
    return NULL;

}
