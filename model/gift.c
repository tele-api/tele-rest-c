#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "gift.h"



static gift_t *gift_create_internal(
    char *id,
    sticker_t *sticker,
    int star_count,
    int upgrade_star_count,
    int total_count,
    int remaining_count
    ) {
    gift_t *gift_local_var = malloc(sizeof(gift_t));
    if (!gift_local_var) {
        return NULL;
    }
    gift_local_var->id = id;
    gift_local_var->sticker = sticker;
    gift_local_var->star_count = star_count;
    gift_local_var->upgrade_star_count = upgrade_star_count;
    gift_local_var->total_count = total_count;
    gift_local_var->remaining_count = remaining_count;

    gift_local_var->_library_owned = 1;
    return gift_local_var;
}

__attribute__((deprecated)) gift_t *gift_create(
    char *id,
    sticker_t *sticker,
    int star_count,
    int upgrade_star_count,
    int total_count,
    int remaining_count
    ) {
    return gift_create_internal (
        id,
        sticker,
        star_count,
        upgrade_star_count,
        total_count,
        remaining_count
        );
}

void gift_free(gift_t *gift) {
    if(NULL == gift){
        return ;
    }
    if(gift->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "gift_free");
        return ;
    }
    listEntry_t *listEntry;
    if (gift->id) {
        free(gift->id);
        gift->id = NULL;
    }
    if (gift->sticker) {
        sticker_free(gift->sticker);
        gift->sticker = NULL;
    }
    free(gift);
}

cJSON *gift_convertToJSON(gift_t *gift) {
    cJSON *item = cJSON_CreateObject();

    // gift->id
    if (!gift->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", gift->id) == NULL) {
    goto fail; //String
    }


    // gift->sticker
    if (!gift->sticker) {
        goto fail;
    }
    cJSON *sticker_local_JSON = sticker_convertToJSON(gift->sticker);
    if(sticker_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "sticker", sticker_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // gift->star_count
    if (!gift->star_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "star_count", gift->star_count) == NULL) {
    goto fail; //Numeric
    }


    // gift->upgrade_star_count
    if(gift->upgrade_star_count) {
    if(cJSON_AddNumberToObject(item, "upgrade_star_count", gift->upgrade_star_count) == NULL) {
    goto fail; //Numeric
    }
    }


    // gift->total_count
    if(gift->total_count) {
    if(cJSON_AddNumberToObject(item, "total_count", gift->total_count) == NULL) {
    goto fail; //Numeric
    }
    }


    // gift->remaining_count
    if(gift->remaining_count) {
    if(cJSON_AddNumberToObject(item, "remaining_count", gift->remaining_count) == NULL) {
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

gift_t *gift_parseFromJSON(cJSON *giftJSON){

    gift_t *gift_local_var = NULL;

    // define the local variable for gift->sticker
    sticker_t *sticker_local_nonprim = NULL;

    // gift->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(giftJSON, "id");
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

    // gift->sticker
    cJSON *sticker = cJSON_GetObjectItemCaseSensitive(giftJSON, "sticker");
    if (cJSON_IsNull(sticker)) {
        sticker = NULL;
    }
    if (!sticker) {
        goto end;
    }

    
    sticker_local_nonprim = sticker_parseFromJSON(sticker); //nonprimitive

    // gift->star_count
    cJSON *star_count = cJSON_GetObjectItemCaseSensitive(giftJSON, "star_count");
    if (cJSON_IsNull(star_count)) {
        star_count = NULL;
    }
    if (!star_count) {
        goto end;
    }

    
    if(!cJSON_IsNumber(star_count))
    {
    goto end; //Numeric
    }

    // gift->upgrade_star_count
    cJSON *upgrade_star_count = cJSON_GetObjectItemCaseSensitive(giftJSON, "upgrade_star_count");
    if (cJSON_IsNull(upgrade_star_count)) {
        upgrade_star_count = NULL;
    }
    if (upgrade_star_count) { 
    if(!cJSON_IsNumber(upgrade_star_count))
    {
    goto end; //Numeric
    }
    }

    // gift->total_count
    cJSON *total_count = cJSON_GetObjectItemCaseSensitive(giftJSON, "total_count");
    if (cJSON_IsNull(total_count)) {
        total_count = NULL;
    }
    if (total_count) { 
    if(!cJSON_IsNumber(total_count))
    {
    goto end; //Numeric
    }
    }

    // gift->remaining_count
    cJSON *remaining_count = cJSON_GetObjectItemCaseSensitive(giftJSON, "remaining_count");
    if (cJSON_IsNull(remaining_count)) {
        remaining_count = NULL;
    }
    if (remaining_count) { 
    if(!cJSON_IsNumber(remaining_count))
    {
    goto end; //Numeric
    }
    }


    gift_local_var = gift_create_internal (
        strdup(id->valuestring),
        sticker_local_nonprim,
        star_count->valuedouble,
        upgrade_star_count ? upgrade_star_count->valuedouble : 0,
        total_count ? total_count->valuedouble : 0,
        remaining_count ? remaining_count->valuedouble : 0
        );

    return gift_local_var;
end:
    if (sticker_local_nonprim) {
        sticker_free(sticker_local_nonprim);
        sticker_local_nonprim = NULL;
    }
    return NULL;

}
