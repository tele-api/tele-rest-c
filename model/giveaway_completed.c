#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "giveaway_completed.h"



static giveaway_completed_t *giveaway_completed_create_internal(
    int winner_count,
    int unclaimed_prize_count,
    message_t *giveaway_message,
    int is_star_giveaway
    ) {
    giveaway_completed_t *giveaway_completed_local_var = malloc(sizeof(giveaway_completed_t));
    if (!giveaway_completed_local_var) {
        return NULL;
    }
    giveaway_completed_local_var->winner_count = winner_count;
    giveaway_completed_local_var->unclaimed_prize_count = unclaimed_prize_count;
    giveaway_completed_local_var->giveaway_message = giveaway_message;
    giveaway_completed_local_var->is_star_giveaway = is_star_giveaway;

    giveaway_completed_local_var->_library_owned = 1;
    return giveaway_completed_local_var;
}

__attribute__((deprecated)) giveaway_completed_t *giveaway_completed_create(
    int winner_count,
    int unclaimed_prize_count,
    message_t *giveaway_message,
    int is_star_giveaway
    ) {
    return giveaway_completed_create_internal (
        winner_count,
        unclaimed_prize_count,
        giveaway_message,
        is_star_giveaway
        );
}

void giveaway_completed_free(giveaway_completed_t *giveaway_completed) {
    if(NULL == giveaway_completed){
        return ;
    }
    if(giveaway_completed->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "giveaway_completed_free");
        return ;
    }
    listEntry_t *listEntry;
    if (giveaway_completed->giveaway_message) {
        message_free(giveaway_completed->giveaway_message);
        giveaway_completed->giveaway_message = NULL;
    }
    free(giveaway_completed);
}

cJSON *giveaway_completed_convertToJSON(giveaway_completed_t *giveaway_completed) {
    cJSON *item = cJSON_CreateObject();

    // giveaway_completed->winner_count
    if (!giveaway_completed->winner_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "winner_count", giveaway_completed->winner_count) == NULL) {
    goto fail; //Numeric
    }


    // giveaway_completed->unclaimed_prize_count
    if(giveaway_completed->unclaimed_prize_count) {
    if(cJSON_AddNumberToObject(item, "unclaimed_prize_count", giveaway_completed->unclaimed_prize_count) == NULL) {
    goto fail; //Numeric
    }
    }


    // giveaway_completed->giveaway_message
    if(giveaway_completed->giveaway_message) {
    cJSON *giveaway_message_local_JSON = message_convertToJSON(giveaway_completed->giveaway_message);
    if(giveaway_message_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "giveaway_message", giveaway_message_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // giveaway_completed->is_star_giveaway
    if(giveaway_completed->is_star_giveaway) {
    if(cJSON_AddBoolToObject(item, "is_star_giveaway", giveaway_completed->is_star_giveaway) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

giveaway_completed_t *giveaway_completed_parseFromJSON(cJSON *giveaway_completedJSON){

    giveaway_completed_t *giveaway_completed_local_var = NULL;

    // define the local variable for giveaway_completed->giveaway_message
    message_t *giveaway_message_local_nonprim = NULL;

    // giveaway_completed->winner_count
    cJSON *winner_count = cJSON_GetObjectItemCaseSensitive(giveaway_completedJSON, "winner_count");
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

    // giveaway_completed->unclaimed_prize_count
    cJSON *unclaimed_prize_count = cJSON_GetObjectItemCaseSensitive(giveaway_completedJSON, "unclaimed_prize_count");
    if (cJSON_IsNull(unclaimed_prize_count)) {
        unclaimed_prize_count = NULL;
    }
    if (unclaimed_prize_count) { 
    if(!cJSON_IsNumber(unclaimed_prize_count))
    {
    goto end; //Numeric
    }
    }

    // giveaway_completed->giveaway_message
    cJSON *giveaway_message = cJSON_GetObjectItemCaseSensitive(giveaway_completedJSON, "giveaway_message");
    if (cJSON_IsNull(giveaway_message)) {
        giveaway_message = NULL;
    }
    if (giveaway_message) { 
    giveaway_message_local_nonprim = message_parseFromJSON(giveaway_message); //nonprimitive
    }

    // giveaway_completed->is_star_giveaway
    cJSON *is_star_giveaway = cJSON_GetObjectItemCaseSensitive(giveaway_completedJSON, "is_star_giveaway");
    if (cJSON_IsNull(is_star_giveaway)) {
        is_star_giveaway = NULL;
    }
    if (is_star_giveaway) { 
    if(!cJSON_IsBool(is_star_giveaway))
    {
    goto end; //Bool
    }
    }


    giveaway_completed_local_var = giveaway_completed_create_internal (
        winner_count->valuedouble,
        unclaimed_prize_count ? unclaimed_prize_count->valuedouble : 0,
        giveaway_message ? giveaway_message_local_nonprim : NULL,
        is_star_giveaway ? is_star_giveaway->valueint : 0
        );

    return giveaway_completed_local_var;
end:
    if (giveaway_message_local_nonprim) {
        message_free(giveaway_message_local_nonprim);
        giveaway_message_local_nonprim = NULL;
    }
    return NULL;

}
