#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "shipping_address.h"



static shipping_address_t *shipping_address_create_internal(
    char *country_code,
    char *state,
    char *city,
    char *street_line1,
    char *street_line2,
    char *post_code
    ) {
    shipping_address_t *shipping_address_local_var = malloc(sizeof(shipping_address_t));
    if (!shipping_address_local_var) {
        return NULL;
    }
    shipping_address_local_var->country_code = country_code;
    shipping_address_local_var->state = state;
    shipping_address_local_var->city = city;
    shipping_address_local_var->street_line1 = street_line1;
    shipping_address_local_var->street_line2 = street_line2;
    shipping_address_local_var->post_code = post_code;

    shipping_address_local_var->_library_owned = 1;
    return shipping_address_local_var;
}

__attribute__((deprecated)) shipping_address_t *shipping_address_create(
    char *country_code,
    char *state,
    char *city,
    char *street_line1,
    char *street_line2,
    char *post_code
    ) {
    return shipping_address_create_internal (
        country_code,
        state,
        city,
        street_line1,
        street_line2,
        post_code
        );
}

void shipping_address_free(shipping_address_t *shipping_address) {
    if(NULL == shipping_address){
        return ;
    }
    if(shipping_address->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "shipping_address_free");
        return ;
    }
    listEntry_t *listEntry;
    if (shipping_address->country_code) {
        free(shipping_address->country_code);
        shipping_address->country_code = NULL;
    }
    if (shipping_address->state) {
        free(shipping_address->state);
        shipping_address->state = NULL;
    }
    if (shipping_address->city) {
        free(shipping_address->city);
        shipping_address->city = NULL;
    }
    if (shipping_address->street_line1) {
        free(shipping_address->street_line1);
        shipping_address->street_line1 = NULL;
    }
    if (shipping_address->street_line2) {
        free(shipping_address->street_line2);
        shipping_address->street_line2 = NULL;
    }
    if (shipping_address->post_code) {
        free(shipping_address->post_code);
        shipping_address->post_code = NULL;
    }
    free(shipping_address);
}

cJSON *shipping_address_convertToJSON(shipping_address_t *shipping_address) {
    cJSON *item = cJSON_CreateObject();

    // shipping_address->country_code
    if (!shipping_address->country_code) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "country_code", shipping_address->country_code) == NULL) {
    goto fail; //String
    }


    // shipping_address->state
    if (!shipping_address->state) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "state", shipping_address->state) == NULL) {
    goto fail; //String
    }


    // shipping_address->city
    if (!shipping_address->city) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "city", shipping_address->city) == NULL) {
    goto fail; //String
    }


    // shipping_address->street_line1
    if (!shipping_address->street_line1) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "street_line1", shipping_address->street_line1) == NULL) {
    goto fail; //String
    }


    // shipping_address->street_line2
    if (!shipping_address->street_line2) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "street_line2", shipping_address->street_line2) == NULL) {
    goto fail; //String
    }


    // shipping_address->post_code
    if (!shipping_address->post_code) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "post_code", shipping_address->post_code) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

shipping_address_t *shipping_address_parseFromJSON(cJSON *shipping_addressJSON){

    shipping_address_t *shipping_address_local_var = NULL;

    // shipping_address->country_code
    cJSON *country_code = cJSON_GetObjectItemCaseSensitive(shipping_addressJSON, "country_code");
    if (cJSON_IsNull(country_code)) {
        country_code = NULL;
    }
    if (!country_code) {
        goto end;
    }

    
    if(!cJSON_IsString(country_code))
    {
    goto end; //String
    }

    // shipping_address->state
    cJSON *state = cJSON_GetObjectItemCaseSensitive(shipping_addressJSON, "state");
    if (cJSON_IsNull(state)) {
        state = NULL;
    }
    if (!state) {
        goto end;
    }

    
    if(!cJSON_IsString(state))
    {
    goto end; //String
    }

    // shipping_address->city
    cJSON *city = cJSON_GetObjectItemCaseSensitive(shipping_addressJSON, "city");
    if (cJSON_IsNull(city)) {
        city = NULL;
    }
    if (!city) {
        goto end;
    }

    
    if(!cJSON_IsString(city))
    {
    goto end; //String
    }

    // shipping_address->street_line1
    cJSON *street_line1 = cJSON_GetObjectItemCaseSensitive(shipping_addressJSON, "street_line1");
    if (cJSON_IsNull(street_line1)) {
        street_line1 = NULL;
    }
    if (!street_line1) {
        goto end;
    }

    
    if(!cJSON_IsString(street_line1))
    {
    goto end; //String
    }

    // shipping_address->street_line2
    cJSON *street_line2 = cJSON_GetObjectItemCaseSensitive(shipping_addressJSON, "street_line2");
    if (cJSON_IsNull(street_line2)) {
        street_line2 = NULL;
    }
    if (!street_line2) {
        goto end;
    }

    
    if(!cJSON_IsString(street_line2))
    {
    goto end; //String
    }

    // shipping_address->post_code
    cJSON *post_code = cJSON_GetObjectItemCaseSensitive(shipping_addressJSON, "post_code");
    if (cJSON_IsNull(post_code)) {
        post_code = NULL;
    }
    if (!post_code) {
        goto end;
    }

    
    if(!cJSON_IsString(post_code))
    {
    goto end; //String
    }


    shipping_address_local_var = shipping_address_create_internal (
        strdup(country_code->valuestring),
        strdup(state->valuestring),
        strdup(city->valuestring),
        strdup(street_line1->valuestring),
        strdup(street_line2->valuestring),
        strdup(post_code->valuestring)
        );

    return shipping_address_local_var;
end:
    return NULL;

}
