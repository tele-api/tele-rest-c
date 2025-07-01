#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "chat_boost_source_giveaway.h"



static chat_boost_source_giveaway_t *chat_boost_source_giveaway_create_internal(
    char *source,
    int giveaway_message_id,
    user_t *user,
    int prize_star_count,
    int is_unclaimed
    ) {
    chat_boost_source_giveaway_t *chat_boost_source_giveaway_local_var = malloc(sizeof(chat_boost_source_giveaway_t));
    if (!chat_boost_source_giveaway_local_var) {
        return NULL;
    }
    chat_boost_source_giveaway_local_var->source = source;
    chat_boost_source_giveaway_local_var->giveaway_message_id = giveaway_message_id;
    chat_boost_source_giveaway_local_var->user = user;
    chat_boost_source_giveaway_local_var->prize_star_count = prize_star_count;
    chat_boost_source_giveaway_local_var->is_unclaimed = is_unclaimed;

    chat_boost_source_giveaway_local_var->_library_owned = 1;
    return chat_boost_source_giveaway_local_var;
}

__attribute__((deprecated)) chat_boost_source_giveaway_t *chat_boost_source_giveaway_create(
    char *source,
    int giveaway_message_id,
    user_t *user,
    int prize_star_count,
    int is_unclaimed
    ) {
    return chat_boost_source_giveaway_create_internal (
        source,
        giveaway_message_id,
        user,
        prize_star_count,
        is_unclaimed
        );
}

void chat_boost_source_giveaway_free(chat_boost_source_giveaway_t *chat_boost_source_giveaway) {
    if(NULL == chat_boost_source_giveaway){
        return ;
    }
    if(chat_boost_source_giveaway->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "chat_boost_source_giveaway_free");
        return ;
    }
    listEntry_t *listEntry;
    if (chat_boost_source_giveaway->source) {
        free(chat_boost_source_giveaway->source);
        chat_boost_source_giveaway->source = NULL;
    }
    if (chat_boost_source_giveaway->user) {
        user_free(chat_boost_source_giveaway->user);
        chat_boost_source_giveaway->user = NULL;
    }
    free(chat_boost_source_giveaway);
}

cJSON *chat_boost_source_giveaway_convertToJSON(chat_boost_source_giveaway_t *chat_boost_source_giveaway) {
    cJSON *item = cJSON_CreateObject();

    // chat_boost_source_giveaway->source
    if (!chat_boost_source_giveaway->source) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "source", chat_boost_source_giveaway->source) == NULL) {
    goto fail; //String
    }


    // chat_boost_source_giveaway->giveaway_message_id
    if (!chat_boost_source_giveaway->giveaway_message_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "giveaway_message_id", chat_boost_source_giveaway->giveaway_message_id) == NULL) {
    goto fail; //Numeric
    }


    // chat_boost_source_giveaway->user
    if(chat_boost_source_giveaway->user) {
    cJSON *user_local_JSON = user_convertToJSON(chat_boost_source_giveaway->user);
    if(user_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "user", user_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // chat_boost_source_giveaway->prize_star_count
    if(chat_boost_source_giveaway->prize_star_count) {
    if(cJSON_AddNumberToObject(item, "prize_star_count", chat_boost_source_giveaway->prize_star_count) == NULL) {
    goto fail; //Numeric
    }
    }


    // chat_boost_source_giveaway->is_unclaimed
    if(chat_boost_source_giveaway->is_unclaimed) {
    if(cJSON_AddBoolToObject(item, "is_unclaimed", chat_boost_source_giveaway->is_unclaimed) == NULL) {
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

chat_boost_source_giveaway_t *chat_boost_source_giveaway_parseFromJSON(cJSON *chat_boost_source_giveawayJSON){

    chat_boost_source_giveaway_t *chat_boost_source_giveaway_local_var = NULL;

    // define the local variable for chat_boost_source_giveaway->user
    user_t *user_local_nonprim = NULL;

    // chat_boost_source_giveaway->source
    cJSON *source = cJSON_GetObjectItemCaseSensitive(chat_boost_source_giveawayJSON, "source");
    if (cJSON_IsNull(source)) {
        source = NULL;
    }
    if (!source) {
        goto end;
    }

    
    if(!cJSON_IsString(source))
    {
    goto end; //String
    }

    // chat_boost_source_giveaway->giveaway_message_id
    cJSON *giveaway_message_id = cJSON_GetObjectItemCaseSensitive(chat_boost_source_giveawayJSON, "giveaway_message_id");
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

    // chat_boost_source_giveaway->user
    cJSON *user = cJSON_GetObjectItemCaseSensitive(chat_boost_source_giveawayJSON, "user");
    if (cJSON_IsNull(user)) {
        user = NULL;
    }
    if (user) { 
    user_local_nonprim = user_parseFromJSON(user); //nonprimitive
    }

    // chat_boost_source_giveaway->prize_star_count
    cJSON *prize_star_count = cJSON_GetObjectItemCaseSensitive(chat_boost_source_giveawayJSON, "prize_star_count");
    if (cJSON_IsNull(prize_star_count)) {
        prize_star_count = NULL;
    }
    if (prize_star_count) { 
    if(!cJSON_IsNumber(prize_star_count))
    {
    goto end; //Numeric
    }
    }

    // chat_boost_source_giveaway->is_unclaimed
    cJSON *is_unclaimed = cJSON_GetObjectItemCaseSensitive(chat_boost_source_giveawayJSON, "is_unclaimed");
    if (cJSON_IsNull(is_unclaimed)) {
        is_unclaimed = NULL;
    }
    if (is_unclaimed) { 
    if(!cJSON_IsBool(is_unclaimed))
    {
    goto end; //Bool
    }
    }


    chat_boost_source_giveaway_local_var = chat_boost_source_giveaway_create_internal (
        strdup(source->valuestring),
        giveaway_message_id->valuedouble,
        user ? user_local_nonprim : NULL,
        prize_star_count ? prize_star_count->valuedouble : 0,
        is_unclaimed ? is_unclaimed->valueint : 0
        );

    return chat_boost_source_giveaway_local_var;
end:
    if (user_local_nonprim) {
        user_free(user_local_nonprim);
        user_local_nonprim = NULL;
    }
    return NULL;

}
