#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "giveaway_winners.h"



static giveaway_winners_t *giveaway_winners_create_internal(
    chat_t *chat,
    int giveaway_message_id,
    int winners_selection_date,
    int winner_count,
    list_t *winners,
    int additional_chat_count,
    int prize_star_count,
    int premium_subscription_month_count,
    int unclaimed_prize_count,
    int only_new_members,
    int was_refunded,
    char *prize_description
    ) {
    giveaway_winners_t *giveaway_winners_local_var = malloc(sizeof(giveaway_winners_t));
    if (!giveaway_winners_local_var) {
        return NULL;
    }
    giveaway_winners_local_var->chat = chat;
    giveaway_winners_local_var->giveaway_message_id = giveaway_message_id;
    giveaway_winners_local_var->winners_selection_date = winners_selection_date;
    giveaway_winners_local_var->winner_count = winner_count;
    giveaway_winners_local_var->winners = winners;
    giveaway_winners_local_var->additional_chat_count = additional_chat_count;
    giveaway_winners_local_var->prize_star_count = prize_star_count;
    giveaway_winners_local_var->premium_subscription_month_count = premium_subscription_month_count;
    giveaway_winners_local_var->unclaimed_prize_count = unclaimed_prize_count;
    giveaway_winners_local_var->only_new_members = only_new_members;
    giveaway_winners_local_var->was_refunded = was_refunded;
    giveaway_winners_local_var->prize_description = prize_description;

    giveaway_winners_local_var->_library_owned = 1;
    return giveaway_winners_local_var;
}

__attribute__((deprecated)) giveaway_winners_t *giveaway_winners_create(
    chat_t *chat,
    int giveaway_message_id,
    int winners_selection_date,
    int winner_count,
    list_t *winners,
    int additional_chat_count,
    int prize_star_count,
    int premium_subscription_month_count,
    int unclaimed_prize_count,
    int only_new_members,
    int was_refunded,
    char *prize_description
    ) {
    return giveaway_winners_create_internal (
        chat,
        giveaway_message_id,
        winners_selection_date,
        winner_count,
        winners,
        additional_chat_count,
        prize_star_count,
        premium_subscription_month_count,
        unclaimed_prize_count,
        only_new_members,
        was_refunded,
        prize_description
        );
}

void giveaway_winners_free(giveaway_winners_t *giveaway_winners) {
    if(NULL == giveaway_winners){
        return ;
    }
    if(giveaway_winners->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "giveaway_winners_free");
        return ;
    }
    listEntry_t *listEntry;
    if (giveaway_winners->chat) {
        chat_free(giveaway_winners->chat);
        giveaway_winners->chat = NULL;
    }
    if (giveaway_winners->winners) {
        list_ForEach(listEntry, giveaway_winners->winners) {
            user_free(listEntry->data);
        }
        list_freeList(giveaway_winners->winners);
        giveaway_winners->winners = NULL;
    }
    if (giveaway_winners->prize_description) {
        free(giveaway_winners->prize_description);
        giveaway_winners->prize_description = NULL;
    }
    free(giveaway_winners);
}

cJSON *giveaway_winners_convertToJSON(giveaway_winners_t *giveaway_winners) {
    cJSON *item = cJSON_CreateObject();

    // giveaway_winners->chat
    if (!giveaway_winners->chat) {
        goto fail;
    }
    cJSON *chat_local_JSON = chat_convertToJSON(giveaway_winners->chat);
    if(chat_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat", chat_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // giveaway_winners->giveaway_message_id
    if (!giveaway_winners->giveaway_message_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "giveaway_message_id", giveaway_winners->giveaway_message_id) == NULL) {
    goto fail; //Numeric
    }


    // giveaway_winners->winners_selection_date
    if (!giveaway_winners->winners_selection_date) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "winners_selection_date", giveaway_winners->winners_selection_date) == NULL) {
    goto fail; //Numeric
    }


    // giveaway_winners->winner_count
    if (!giveaway_winners->winner_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "winner_count", giveaway_winners->winner_count) == NULL) {
    goto fail; //Numeric
    }


    // giveaway_winners->winners
    if (!giveaway_winners->winners) {
        goto fail;
    }
    cJSON *winners = cJSON_AddArrayToObject(item, "winners");
    if(winners == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *winnersListEntry;
    if (giveaway_winners->winners) {
    list_ForEach(winnersListEntry, giveaway_winners->winners) {
    cJSON *itemLocal = user_convertToJSON(winnersListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(winners, itemLocal);
    }
    }


    // giveaway_winners->additional_chat_count
    if(giveaway_winners->additional_chat_count) {
    if(cJSON_AddNumberToObject(item, "additional_chat_count", giveaway_winners->additional_chat_count) == NULL) {
    goto fail; //Numeric
    }
    }


    // giveaway_winners->prize_star_count
    if(giveaway_winners->prize_star_count) {
    if(cJSON_AddNumberToObject(item, "prize_star_count", giveaway_winners->prize_star_count) == NULL) {
    goto fail; //Numeric
    }
    }


    // giveaway_winners->premium_subscription_month_count
    if(giveaway_winners->premium_subscription_month_count) {
    if(cJSON_AddNumberToObject(item, "premium_subscription_month_count", giveaway_winners->premium_subscription_month_count) == NULL) {
    goto fail; //Numeric
    }
    }


    // giveaway_winners->unclaimed_prize_count
    if(giveaway_winners->unclaimed_prize_count) {
    if(cJSON_AddNumberToObject(item, "unclaimed_prize_count", giveaway_winners->unclaimed_prize_count) == NULL) {
    goto fail; //Numeric
    }
    }


    // giveaway_winners->only_new_members
    if(giveaway_winners->only_new_members) {
    if(cJSON_AddBoolToObject(item, "only_new_members", giveaway_winners->only_new_members) == NULL) {
    goto fail; //Bool
    }
    }


    // giveaway_winners->was_refunded
    if(giveaway_winners->was_refunded) {
    if(cJSON_AddBoolToObject(item, "was_refunded", giveaway_winners->was_refunded) == NULL) {
    goto fail; //Bool
    }
    }


    // giveaway_winners->prize_description
    if(giveaway_winners->prize_description) {
    if(cJSON_AddStringToObject(item, "prize_description", giveaway_winners->prize_description) == NULL) {
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

giveaway_winners_t *giveaway_winners_parseFromJSON(cJSON *giveaway_winnersJSON){

    giveaway_winners_t *giveaway_winners_local_var = NULL;

    // define the local variable for giveaway_winners->chat
    chat_t *chat_local_nonprim = NULL;

    // define the local list for giveaway_winners->winners
    list_t *winnersList = NULL;

    // giveaway_winners->chat
    cJSON *chat = cJSON_GetObjectItemCaseSensitive(giveaway_winnersJSON, "chat");
    if (cJSON_IsNull(chat)) {
        chat = NULL;
    }
    if (!chat) {
        goto end;
    }

    
    chat_local_nonprim = chat_parseFromJSON(chat); //nonprimitive

    // giveaway_winners->giveaway_message_id
    cJSON *giveaway_message_id = cJSON_GetObjectItemCaseSensitive(giveaway_winnersJSON, "giveaway_message_id");
    if (cJSON_IsNull(giveaway_message_id)) {
        giveaway_message_id = NULL;
    }
    if (!giveaway_message_id) {
        goto end;
    }

    
    if(!cJSON_IsNumber(giveaway_message_id))
    {
    goto end; //Numeric
    }

    // giveaway_winners->winners_selection_date
    cJSON *winners_selection_date = cJSON_GetObjectItemCaseSensitive(giveaway_winnersJSON, "winners_selection_date");
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

    // giveaway_winners->winner_count
    cJSON *winner_count = cJSON_GetObjectItemCaseSensitive(giveaway_winnersJSON, "winner_count");
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

    // giveaway_winners->winners
    cJSON *winners = cJSON_GetObjectItemCaseSensitive(giveaway_winnersJSON, "winners");
    if (cJSON_IsNull(winners)) {
        winners = NULL;
    }
    if (!winners) {
        goto end;
    }

    
    cJSON *winners_local_nonprimitive = NULL;
    if(!cJSON_IsArray(winners)){
        goto end; //nonprimitive container
    }

    winnersList = list_createList();

    cJSON_ArrayForEach(winners_local_nonprimitive,winners )
    {
        if(!cJSON_IsObject(winners_local_nonprimitive)){
            goto end;
        }
        user_t *winnersItem = user_parseFromJSON(winners_local_nonprimitive);

        list_addElement(winnersList, winnersItem);
    }

    // giveaway_winners->additional_chat_count
    cJSON *additional_chat_count = cJSON_GetObjectItemCaseSensitive(giveaway_winnersJSON, "additional_chat_count");
    if (cJSON_IsNull(additional_chat_count)) {
        additional_chat_count = NULL;
    }
    if (additional_chat_count) { 
    if(!cJSON_IsNumber(additional_chat_count))
    {
    goto end; //Numeric
    }
    }

    // giveaway_winners->prize_star_count
    cJSON *prize_star_count = cJSON_GetObjectItemCaseSensitive(giveaway_winnersJSON, "prize_star_count");
    if (cJSON_IsNull(prize_star_count)) {
        prize_star_count = NULL;
    }
    if (prize_star_count) { 
    if(!cJSON_IsNumber(prize_star_count))
    {
    goto end; //Numeric
    }
    }

    // giveaway_winners->premium_subscription_month_count
    cJSON *premium_subscription_month_count = cJSON_GetObjectItemCaseSensitive(giveaway_winnersJSON, "premium_subscription_month_count");
    if (cJSON_IsNull(premium_subscription_month_count)) {
        premium_subscription_month_count = NULL;
    }
    if (premium_subscription_month_count) { 
    if(!cJSON_IsNumber(premium_subscription_month_count))
    {
    goto end; //Numeric
    }
    }

    // giveaway_winners->unclaimed_prize_count
    cJSON *unclaimed_prize_count = cJSON_GetObjectItemCaseSensitive(giveaway_winnersJSON, "unclaimed_prize_count");
    if (cJSON_IsNull(unclaimed_prize_count)) {
        unclaimed_prize_count = NULL;
    }
    if (unclaimed_prize_count) { 
    if(!cJSON_IsNumber(unclaimed_prize_count))
    {
    goto end; //Numeric
    }
    }

    // giveaway_winners->only_new_members
    cJSON *only_new_members = cJSON_GetObjectItemCaseSensitive(giveaway_winnersJSON, "only_new_members");
    if (cJSON_IsNull(only_new_members)) {
        only_new_members = NULL;
    }
    if (only_new_members) { 
    if(!cJSON_IsBool(only_new_members))
    {
    goto end; //Bool
    }
    }

    // giveaway_winners->was_refunded
    cJSON *was_refunded = cJSON_GetObjectItemCaseSensitive(giveaway_winnersJSON, "was_refunded");
    if (cJSON_IsNull(was_refunded)) {
        was_refunded = NULL;
    }
    if (was_refunded) { 
    if(!cJSON_IsBool(was_refunded))
    {
    goto end; //Bool
    }
    }

    // giveaway_winners->prize_description
    cJSON *prize_description = cJSON_GetObjectItemCaseSensitive(giveaway_winnersJSON, "prize_description");
    if (cJSON_IsNull(prize_description)) {
        prize_description = NULL;
    }
    if (prize_description) { 
    if(!cJSON_IsString(prize_description) && !cJSON_IsNull(prize_description))
    {
    goto end; //String
    }
    }


    giveaway_winners_local_var = giveaway_winners_create_internal (
        chat_local_nonprim,
        giveaway_message_id->valuedouble,
        winners_selection_date->valuedouble,
        winner_count->valuedouble,
        winnersList,
        additional_chat_count ? additional_chat_count->valuedouble : 0,
        prize_star_count ? prize_star_count->valuedouble : 0,
        premium_subscription_month_count ? premium_subscription_month_count->valuedouble : 0,
        unclaimed_prize_count ? unclaimed_prize_count->valuedouble : 0,
        only_new_members ? only_new_members->valueint : 0,
        was_refunded ? was_refunded->valueint : 0,
        prize_description && !cJSON_IsNull(prize_description) ? strdup(prize_description->valuestring) : NULL
        );

    return giveaway_winners_local_var;
end:
    if (chat_local_nonprim) {
        chat_free(chat_local_nonprim);
        chat_local_nonprim = NULL;
    }
    if (winnersList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, winnersList) {
            user_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(winnersList);
        winnersList = NULL;
    }
    return NULL;

}
