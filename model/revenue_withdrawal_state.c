#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "revenue_withdrawal_state.h"



static revenue_withdrawal_state_t *revenue_withdrawal_state_create_internal(
    char *type,
    int date,
    char *url
    ) {
    revenue_withdrawal_state_t *revenue_withdrawal_state_local_var = malloc(sizeof(revenue_withdrawal_state_t));
    if (!revenue_withdrawal_state_local_var) {
        return NULL;
    }
    revenue_withdrawal_state_local_var->type = type;
    revenue_withdrawal_state_local_var->date = date;
    revenue_withdrawal_state_local_var->url = url;

    revenue_withdrawal_state_local_var->_library_owned = 1;
    return revenue_withdrawal_state_local_var;
}

__attribute__((deprecated)) revenue_withdrawal_state_t *revenue_withdrawal_state_create(
    char *type,
    int date,
    char *url
    ) {
    return revenue_withdrawal_state_create_internal (
        type,
        date,
        url
        );
}

void revenue_withdrawal_state_free(revenue_withdrawal_state_t *revenue_withdrawal_state) {
    if(NULL == revenue_withdrawal_state){
        return ;
    }
    if(revenue_withdrawal_state->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "revenue_withdrawal_state_free");
        return ;
    }
    listEntry_t *listEntry;
    if (revenue_withdrawal_state->type) {
        free(revenue_withdrawal_state->type);
        revenue_withdrawal_state->type = NULL;
    }
    if (revenue_withdrawal_state->url) {
        free(revenue_withdrawal_state->url);
        revenue_withdrawal_state->url = NULL;
    }
    free(revenue_withdrawal_state);
}

cJSON *revenue_withdrawal_state_convertToJSON(revenue_withdrawal_state_t *revenue_withdrawal_state) {
    cJSON *item = cJSON_CreateObject();

    // revenue_withdrawal_state->type
    if (!revenue_withdrawal_state->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", revenue_withdrawal_state->type) == NULL) {
    goto fail; //String
    }


    // revenue_withdrawal_state->date
    if (!revenue_withdrawal_state->date) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "date", revenue_withdrawal_state->date) == NULL) {
    goto fail; //Numeric
    }


    // revenue_withdrawal_state->url
    if (!revenue_withdrawal_state->url) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "url", revenue_withdrawal_state->url) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

revenue_withdrawal_state_t *revenue_withdrawal_state_parseFromJSON(cJSON *revenue_withdrawal_stateJSON){

    revenue_withdrawal_state_t *revenue_withdrawal_state_local_var = NULL;

    // revenue_withdrawal_state->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(revenue_withdrawal_stateJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }

    // revenue_withdrawal_state->date
    cJSON *date = cJSON_GetObjectItemCaseSensitive(revenue_withdrawal_stateJSON, "date");
    if (cJSON_IsNull(date)) {
        date = NULL;
    }
    if (!date) {
        goto end;
    }

    
    if(!cJSON_IsNumber(date))
    {
    goto end; //Numeric
    }

    // revenue_withdrawal_state->url
    cJSON *url = cJSON_GetObjectItemCaseSensitive(revenue_withdrawal_stateJSON, "url");
    if (cJSON_IsNull(url)) {
        url = NULL;
    }
    if (!url) {
        goto end;
    }

    
    if(!cJSON_IsString(url))
    {
    goto end; //String
    }


    revenue_withdrawal_state_local_var = revenue_withdrawal_state_create_internal (
        strdup(type->valuestring),
        date->valuedouble,
        strdup(url->valuestring)
        );

    return revenue_withdrawal_state_local_var;
end:
    return NULL;

}
