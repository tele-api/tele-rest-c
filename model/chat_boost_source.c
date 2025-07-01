#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "chat_boost_source.h"



static chat_boost_source_t *chat_boost_source_create_internal(
    char *source,
    user_t *user,
    int giveaway_message_id,
    int prize_star_count,
    int is_unclaimed
    ) {
    chat_boost_source_t *chat_boost_source_local_var = malloc(sizeof(chat_boost_source_t));
    if (!chat_boost_source_local_var) {
        return NULL;
    }
    chat_boost_source_local_var->source = source;
    chat_boost_source_local_var->user = user;
    chat_boost_source_local_var->giveaway_message_id = giveaway_message_id;
    chat_boost_source_local_var->prize_star_count = prize_star_count;
    chat_boost_source_local_var->is_unclaimed = is_unclaimed;

    chat_boost_source_local_var->_library_owned = 1;
    return chat_boost_source_local_var;
}

__attribute__((deprecated)) chat_boost_source_t *chat_boost_source_create(
    char *source,
    user_t *user,
    int giveaway_message_id,
    int prize_star_count,
    int is_unclaimed
    ) {
    return chat_boost_source_create_internal (
        source,
        user,
        giveaway_message_id,
        prize_star_count,
        is_unclaimed
        );
}

void chat_boost_source_free(chat_boost_source_t *chat_boost_source) {
    if(NULL == chat_boost_source){
        return ;
    }
    if(chat_boost_source->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "chat_boost_source_free");
        return ;
    }
    listEntry_t *listEntry;
    if (chat_boost_source->source) {
        free(chat_boost_source->source);
        chat_boost_source->source = NULL;
    }
    if (chat_boost_source->user) {
        user_free(chat_boost_source->user);
        chat_boost_source->user = NULL;
    }
    free(chat_boost_source);
}

cJSON *chat_boost_source_convertToJSON(chat_boost_source_t *chat_boost_source) {
    cJSON *item = cJSON_CreateObject();

    // chat_boost_source->source
    if (!chat_boost_source->source) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "source", chat_boost_source->source) == NULL) {
    goto fail; //String
    }


    // chat_boost_source->user
    if (!chat_boost_source->user) {
        goto fail;
    }
    cJSON *user_local_JSON = user_convertToJSON(chat_boost_source->user);
    if(user_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "user", user_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // chat_boost_source->giveaway_message_id
    if (!chat_boost_source->giveaway_message_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "giveaway_message_id", chat_boost_source->giveaway_message_id) == NULL) {
    goto fail; //Numeric
    }


    // chat_boost_source->prize_star_count
    if(chat_boost_source->prize_star_count) {
    if(cJSON_AddNumberToObject(item, "prize_star_count", chat_boost_source->prize_star_count) == NULL) {
    goto fail; //Numeric
    }
    }


    // chat_boost_source->is_unclaimed
    if(chat_boost_source->is_unclaimed) {
    if(cJSON_AddBoolToObject(item, "is_unclaimed", chat_boost_source->is_unclaimed) == NULL) {
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

chat_boost_source_t *chat_boost_source_parseFromJSON(cJSON *chat_boost_sourceJSON){

    chat_boost_source_t *chat_boost_source_local_var = NULL;

    // define the local variable for chat_boost_source->user
    user_t *user_local_nonprim = NULL;

    // chat_boost_source->source
    cJSON *source = cJSON_GetObjectItemCaseSensitive(chat_boost_sourceJSON, "source");
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

    // chat_boost_source->user
    cJSON *user = cJSON_GetObjectItemCaseSensitive(chat_boost_sourceJSON, "user");
    if (cJSON_IsNull(user)) {
        user = NULL;
    }
    if (!user) {
        goto end;
    }

    
    user_local_nonprim = user_parseFromJSON(user); //nonprimitive

    // chat_boost_source->giveaway_message_id
    cJSON *giveaway_message_id = cJSON_GetObjectItemCaseSensitive(chat_boost_sourceJSON, "giveaway_message_id");
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

    // chat_boost_source->prize_star_count
    cJSON *prize_star_count = cJSON_GetObjectItemCaseSensitive(chat_boost_sourceJSON, "prize_star_count");
    if (cJSON_IsNull(prize_star_count)) {
        prize_star_count = NULL;
    }
    if (prize_star_count) { 
    if(!cJSON_IsNumber(prize_star_count))
    {
    goto end; //Numeric
    }
    }

    // chat_boost_source->is_unclaimed
    cJSON *is_unclaimed = cJSON_GetObjectItemCaseSensitive(chat_boost_sourceJSON, "is_unclaimed");
    if (cJSON_IsNull(is_unclaimed)) {
        is_unclaimed = NULL;
    }
    if (is_unclaimed) { 
    if(!cJSON_IsBool(is_unclaimed))
    {
    goto end; //Bool
    }
    }


    chat_boost_source_local_var = chat_boost_source_create_internal (
        strdup(source->valuestring),
        user_local_nonprim,
        giveaway_message_id->valuedouble,
        prize_star_count ? prize_star_count->valuedouble : 0,
        is_unclaimed ? is_unclaimed->valueint : 0
        );

    return chat_boost_source_local_var;
end:
    if (user_local_nonprim) {
        user_free(user_local_nonprim);
        user_local_nonprim = NULL;
    }
    return NULL;

}
