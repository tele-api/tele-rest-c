#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "revenue_withdrawal_state_succeeded.h"



static revenue_withdrawal_state_succeeded_t *revenue_withdrawal_state_succeeded_create_internal(
    char *type,
    int date,
    char *url
    ) {
    revenue_withdrawal_state_succeeded_t *revenue_withdrawal_state_succeeded_local_var = malloc(sizeof(revenue_withdrawal_state_succeeded_t));
    if (!revenue_withdrawal_state_succeeded_local_var) {
        return NULL;
    }
    revenue_withdrawal_state_succeeded_local_var->type = type;
    revenue_withdrawal_state_succeeded_local_var->date = date;
    revenue_withdrawal_state_succeeded_local_var->url = url;

    revenue_withdrawal_state_succeeded_local_var->_library_owned = 1;
    return revenue_withdrawal_state_succeeded_local_var;
}

__attribute__((deprecated)) revenue_withdrawal_state_succeeded_t *revenue_withdrawal_state_succeeded_create(
    char *type,
    int date,
    char *url
    ) {
    return revenue_withdrawal_state_succeeded_create_internal (
        type,
        date,
        url
        );
}

void revenue_withdrawal_state_succeeded_free(revenue_withdrawal_state_succeeded_t *revenue_withdrawal_state_succeeded) {
    if(NULL == revenue_withdrawal_state_succeeded){
        return ;
    }
    if(revenue_withdrawal_state_succeeded->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "revenue_withdrawal_state_succeeded_free");
        return ;
    }
    listEntry_t *listEntry;
    if (revenue_withdrawal_state_succeeded->type) {
        free(revenue_withdrawal_state_succeeded->type);
        revenue_withdrawal_state_succeeded->type = NULL;
    }
    if (revenue_withdrawal_state_succeeded->url) {
        free(revenue_withdrawal_state_succeeded->url);
        revenue_withdrawal_state_succeeded->url = NULL;
    }
    free(revenue_withdrawal_state_succeeded);
}

cJSON *revenue_withdrawal_state_succeeded_convertToJSON(revenue_withdrawal_state_succeeded_t *revenue_withdrawal_state_succeeded) {
    cJSON *item = cJSON_CreateObject();

    // revenue_withdrawal_state_succeeded->type
    if (!revenue_withdrawal_state_succeeded->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", revenue_withdrawal_state_succeeded->type) == NULL) {
    goto fail; //String
    }


    // revenue_withdrawal_state_succeeded->date
    if (!revenue_withdrawal_state_succeeded->date) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "date", revenue_withdrawal_state_succeeded->date) == NULL) {
    goto fail; //Numeric
    }


    // revenue_withdrawal_state_succeeded->url
    if (!revenue_withdrawal_state_succeeded->url) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "url", revenue_withdrawal_state_succeeded->url) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

revenue_withdrawal_state_succeeded_t *revenue_withdrawal_state_succeeded_parseFromJSON(cJSON *revenue_withdrawal_state_succeededJSON){

    revenue_withdrawal_state_succeeded_t *revenue_withdrawal_state_succeeded_local_var = NULL;

    // revenue_withdrawal_state_succeeded->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(revenue_withdrawal_state_succeededJSON, "type");
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

    // revenue_withdrawal_state_succeeded->date
    cJSON *date = cJSON_GetObjectItemCaseSensitive(revenue_withdrawal_state_succeededJSON, "date");
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

    // revenue_withdrawal_state_succeeded->url
    cJSON *url = cJSON_GetObjectItemCaseSensitive(revenue_withdrawal_state_succeededJSON, "url");
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


    revenue_withdrawal_state_succeeded_local_var = revenue_withdrawal_state_succeeded_create_internal (
        strdup(type->valuestring),
        date->valuedouble,
        strdup(url->valuestring)
        );

    return revenue_withdrawal_state_succeeded_local_var;
end:
    return NULL;

}
