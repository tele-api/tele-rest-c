#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "giveaway.h"



static giveaway_t *giveaway_create_internal(
    list_t *chats,
    int winners_selection_date,
    int winner_count,
    int only_new_members,
    int has_public_winners,
    char *prize_description,
    list_t *country_codes,
    int prize_star_count,
    int premium_subscription_month_count
    ) {
    giveaway_t *giveaway_local_var = malloc(sizeof(giveaway_t));
    if (!giveaway_local_var) {
        return NULL;
    }
    giveaway_local_var->chats = chats;
    giveaway_local_var->winners_selection_date = winners_selection_date;
    giveaway_local_var->winner_count = winner_count;
    giveaway_local_var->only_new_members = only_new_members;
    giveaway_local_var->has_public_winners = has_public_winners;
    giveaway_local_var->prize_description = prize_description;
    giveaway_local_var->country_codes = country_codes;
    giveaway_local_var->prize_star_count = prize_star_count;
    giveaway_local_var->premium_subscription_month_count = premium_subscription_month_count;

    giveaway_local_var->_library_owned = 1;
    return giveaway_local_var;
}

__attribute__((deprecated)) giveaway_t *giveaway_create(
    list_t *chats,
    int winners_selection_date,
    int winner_count,
    int only_new_members,
    int has_public_winners,
    char *prize_description,
    list_t *country_codes,
    int prize_star_count,
    int premium_subscription_month_count
    ) {
    return giveaway_create_internal (
        chats,
        winners_selection_date,
        winner_count,
        only_new_members,
        has_public_winners,
        prize_description,
        country_codes,
        prize_star_count,
        premium_subscription_month_count
        );
}

void giveaway_free(giveaway_t *giveaway) {
    if(NULL == giveaway){
        return ;
    }
    if(giveaway->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "giveaway_free");
        return ;
    }
    listEntry_t *listEntry;
    if (giveaway->chats) {
        list_ForEach(listEntry, giveaway->chats) {
            chat_free(listEntry->data);
        }
        list_freeList(giveaway->chats);
        giveaway->chats = NULL;
    }
    if (giveaway->prize_description) {
        free(giveaway->prize_description);
        giveaway->prize_description = NULL;
    }
    if (giveaway->country_codes) {
        list_ForEach(listEntry, giveaway->country_codes) {
            free(listEntry->data);
        }
        list_freeList(giveaway->country_codes);
        giveaway->country_codes = NULL;
    }
    free(giveaway);
}

cJSON *giveaway_convertToJSON(giveaway_t *giveaway) {
    cJSON *item = cJSON_CreateObject();

    // giveaway->chats
    if (!giveaway->chats) {
        goto fail;
    }
    cJSON *chats = cJSON_AddArrayToObject(item, "chats");
    if(chats == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *chatsListEntry;
    if (giveaway->chats) {
    list_ForEach(chatsListEntry, giveaway->chats) {
    cJSON *itemLocal = chat_convertToJSON(chatsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(chats, itemLocal);
    }
    }


    // giveaway->winners_selection_date
    if (!giveaway->winners_selection_date) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "winners_selection_date", giveaway->winners_selection_date) == NULL) {
    goto fail; //Numeric
    }


    // giveaway->winner_count
    if (!giveaway->winner_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "winner_count", giveaway->winner_count) == NULL) {
    goto fail; //Numeric
    }


    // giveaway->only_new_members
    if(giveaway->only_new_members) {
    if(cJSON_AddBoolToObject(item, "only_new_members", giveaway->only_new_members) == NULL) {
    goto fail; //Bool
    }
    }


    // giveaway->has_public_winners
    if(giveaway->has_public_winners) {
    if(cJSON_AddBoolToObject(item, "has_public_winners", giveaway->has_public_winners) == NULL) {
    goto fail; //Bool
    }
    }


    // giveaway->prize_description
    if(giveaway->prize_description) {
    if(cJSON_AddStringToObject(item, "prize_description", giveaway->prize_description) == NULL) {
    goto fail; //String
    }
    }


    // giveaway->country_codes
    if(giveaway->country_codes) {
    cJSON *country_codes = cJSON_AddArrayToObject(item, "country_codes");
    if(country_codes == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *country_codesListEntry;
    list_ForEach(country_codesListEntry, giveaway->country_codes) {
    if(cJSON_AddStringToObject(country_codes, "", country_codesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // giveaway->prize_star_count
    if(giveaway->prize_star_count) {
    if(cJSON_AddNumberToObject(item, "prize_star_count", giveaway->prize_star_count) == NULL) {
    goto fail; //Numeric
    }
    }


    // giveaway->premium_subscription_month_count
    if(giveaway->premium_subscription_month_count) {
    if(cJSON_AddNumberToObject(item, "premium_subscription_month_count", giveaway->premium_subscription_month_count) == NULL) {
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

giveaway_t *giveaway_parseFromJSON(cJSON *giveawayJSON){

    giveaway_t *giveaway_local_var = NULL;

    // define the local list for giveaway->chats
    list_t *chatsList = NULL;

    // define the local list for giveaway->country_codes
    list_t *country_codesList = NULL;

    // giveaway->chats
    cJSON *chats = cJSON_GetObjectItemCaseSensitive(giveawayJSON, "chats");
    if (cJSON_IsNull(chats)) {
        chats = NULL;
    }
    if (!chats) {
        goto end;
    }

    
    cJSON *chats_local_nonprimitive = NULL;
    if(!cJSON_IsArray(chats)){
        goto end; //nonprimitive container
    }

    chatsList = list_createList();

    cJSON_ArrayForEach(chats_local_nonprimitive,chats )
    {
        if(!cJSON_IsObject(chats_local_nonprimitive)){
            goto end;
        }
        chat_t *chatsItem = chat_parseFromJSON(chats_local_nonprimitive);

        list_addElement(chatsList, chatsItem);
    }

    // giveaway->winners_selection_date
    cJSON *winners_selection_date = cJSON_GetObjectItemCaseSensitive(giveawayJSON, "winners_selection_date");
    if (cJSON_IsNull(winners_selection_date)) {
        winners_selection_date = NULL;
    }
    if (!winners_selection_date) {
        goto end;
    }

    
    if(!cJSON_IsNumber(winners_selection_date))
    {
    goto end; //Numeric
    }

    // giveaway->winner_count
    cJSON *winner_count = cJSON_GetObjectItemCaseSensitive(giveawayJSON, "winner_count");
    if (cJSON_IsNull(winner_count)) {
        winner_count = NULL;
    }
    if (!winner_count) {
        goto end;
    }

    
    if(!cJSON_IsNumber(winner_count))
    {
    goto end; //Numeric
    }

    // giveaway->only_new_members
    cJSON *only_new_members = cJSON_GetObjectItemCaseSensitive(giveawayJSON, "only_new_members");
    if (cJSON_IsNull(only_new_members)) {
        only_new_members = NULL;
    }
    if (only_new_members) { 
    if(!cJSON_IsBool(only_new_members))
    {
    goto end; //Bool
    }
    }

    // giveaway->has_public_winners
    cJSON *has_public_winners = cJSON_GetObjectItemCaseSensitive(giveawayJSON, "has_public_winners");
    if (cJSON_IsNull(has_public_winners)) {
        has_public_winners = NULL;
    }
    if (has_public_winners) { 
    if(!cJSON_IsBool(has_public_winners))
    {
    goto end; //Bool
    }
    }

    // giveaway->prize_description
    cJSON *prize_description = cJSON_GetObjectItemCaseSensitive(giveawayJSON, "prize_description");
    if (cJSON_IsNull(prize_description)) {
        prize_description = NULL;
    }
    if (prize_description) { 
    if(!cJSON_IsString(prize_description) && !cJSON_IsNull(prize_description))
    {
    goto end; //String
    }
    }

    // giveaway->country_codes
    cJSON *country_codes = cJSON_GetObjectItemCaseSensitive(giveawayJSON, "country_codes");
    if (cJSON_IsNull(country_codes)) {
        country_codes = NULL;
    }
    if (country_codes) { 
    cJSON *country_codes_local = NULL;
    if(!cJSON_IsArray(country_codes)) {
        goto end;//primitive container
    }
    country_codesList = list_createList();

    cJSON_ArrayForEach(country_codes_local, country_codes)
    {
        if(!cJSON_IsString(country_codes_local))
        {
            goto end;
        }
        list_addElement(country_codesList , strdup(country_codes_local->valuestring));
    }
    }

    // giveaway->prize_star_count
    cJSON *prize_star_count = cJSON_GetObjectItemCaseSensitive(giveawayJSON, "prize_star_count");
    if (cJSON_IsNull(prize_star_count)) {
        prize_star_count = NULL;
    }
    if (prize_star_count) { 
    if(!cJSON_IsNumber(prize_star_count))
    {
    goto end; //Numeric
    }
    }

    // giveaway->premium_subscription_month_count
    cJSON *premium_subscription_month_count = cJSON_GetObjectItemCaseSensitive(giveawayJSON, "premium_subscription_month_count");
    if (cJSON_IsNull(premium_subscription_month_count)) {
        premium_subscription_month_count = NULL;
    }
    if (premium_subscription_month_count) { 
    if(!cJSON_IsNumber(premium_subscription_month_count))
    {
    goto end; //Numeric
    }
    }


    giveaway_local_var = giveaway_create_internal (
        chatsList,
        winners_selection_date->valuedouble,
        winner_count->valuedouble,
        only_new_members ? only_new_members->valueint : 0,
        has_public_winners ? has_public_winners->valueint : 0,
        prize_description && !cJSON_IsNull(prize_description) ? strdup(prize_description->valuestring) : NULL,
        country_codes ? country_codesList : NULL,
        prize_star_count ? prize_star_count->valuedouble : 0,
        premium_subscription_month_count ? premium_subscription_month_count->valuedouble : 0
        );

    return giveaway_local_var;
end:
    if (chatsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, chatsList) {
            chat_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(chatsList);
        chatsList = NULL;
    }
    if (country_codesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, country_codesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(country_codesList);
        country_codesList = NULL;
    }
    return NULL;

}
