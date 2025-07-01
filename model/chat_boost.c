#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "chat_boost.h"



static chat_boost_t *chat_boost_create_internal(
    char *boost_id,
    int add_date,
    int expiration_date,
    chat_boost_source_t *source
    ) {
    chat_boost_t *chat_boost_local_var = malloc(sizeof(chat_boost_t));
    if (!chat_boost_local_var) {
        return NULL;
    }
    chat_boost_local_var->boost_id = boost_id;
    chat_boost_local_var->add_date = add_date;
    chat_boost_local_var->expiration_date = expiration_date;
    chat_boost_local_var->source = source;

    chat_boost_local_var->_library_owned = 1;
    return chat_boost_local_var;
}

__attribute__((deprecated)) chat_boost_t *chat_boost_create(
    char *boost_id,
    int add_date,
    int expiration_date,
    chat_boost_source_t *source
    ) {
    return chat_boost_create_internal (
        boost_id,
        add_date,
        expiration_date,
        source
        );
}

void chat_boost_free(chat_boost_t *chat_boost) {
    if(NULL == chat_boost){
        return ;
    }
    if(chat_boost->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "chat_boost_free");
        return ;
    }
    listEntry_t *listEntry;
    if (chat_boost->boost_id) {
        free(chat_boost->boost_id);
        chat_boost->boost_id = NULL;
    }
    if (chat_boost->source) {
        chat_boost_source_free(chat_boost->source);
        chat_boost->source = NULL;
    }
    free(chat_boost);
}

cJSON *chat_boost_convertToJSON(chat_boost_t *chat_boost) {
    cJSON *item = cJSON_CreateObject();

    // chat_boost->boost_id
    if (!chat_boost->boost_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "boost_id", chat_boost->boost_id) == NULL) {
    goto fail; //String
    }


    // chat_boost->add_date
    if (!chat_boost->add_date) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "add_date", chat_boost->add_date) == NULL) {
    goto fail; //Numeric
    }


    // chat_boost->expiration_date
    if (!chat_boost->expiration_date) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "expiration_date", chat_boost->expiration_date) == NULL) {
    goto fail; //Numeric
    }


    // chat_boost->source
    if (!chat_boost->source) {
        goto fail;
    }
    cJSON *source_local_JSON = chat_boost_source_convertToJSON(chat_boost->source);
    if(source_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "source", source_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

chat_boost_t *chat_boost_parseFromJSON(cJSON *chat_boostJSON){

    chat_boost_t *chat_boost_local_var = NULL;

    // define the local variable for chat_boost->source
    chat_boost_source_t *source_local_nonprim = NULL;

    // chat_boost->boost_id
    cJSON *boost_id = cJSON_GetObjectItemCaseSensitive(chat_boostJSON, "boost_id");
    if (cJSON_IsNull(boost_id)) {
        boost_id = NULL;
    }
    if (!boost_id) {
        goto end;
    }

    
    if(!cJSON_IsString(boost_id))
    {
    goto end; //String
    }

    // chat_boost->add_date
    cJSON *add_date = cJSON_GetObjectItemCaseSensitive(chat_boostJSON, "add_date");
    if (cJSON_IsNull(add_date)) {
        add_date = NULL;
    }
    if (!add_date) {
        goto end;
    }

    
    if(!cJSON_IsNumber(add_date))
    {
    goto end; //Numeric
    }

    // chat_boost->expiration_date
    cJSON *expiration_date = cJSON_GetObjectItemCaseSensitive(chat_boostJSON, "expiration_date");
    if (cJSON_IsNull(expiration_date)) {
        expiration_date = NULL;
    }
    if (!expiration_date) {
        goto end;
    }

    
    if(!cJSON_IsNumber(expiration_date))
    {
    goto end; //Numeric
    }

    // chat_boost->source
    cJSON *source = cJSON_GetObjectItemCaseSensitive(chat_boostJSON, "source");
    if (cJSON_IsNull(source)) {
        source = NULL;
    }
    if (!source) {
        goto end;
    }

    
    source_local_nonprim = chat_boost_source_parseFromJSON(source); //nonprimitive


    chat_boost_local_var = chat_boost_create_internal (
        strdup(boost_id->valuestring),
        add_date->valuedouble,
        expiration_date->valuedouble,
        source_local_nonprim
        );

    return chat_boost_local_var;
end:
    if (source_local_nonprim) {
        chat_boost_source_free(source_local_nonprim);
        source_local_nonprim = NULL;
    }
    return NULL;

}
