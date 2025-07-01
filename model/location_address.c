#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "location_address.h"



static location_address_t *location_address_create_internal(
    char *country_code,
    char *state,
    char *city,
    char *street
    ) {
    location_address_t *location_address_local_var = malloc(sizeof(location_address_t));
    if (!location_address_local_var) {
        return NULL;
    }
    location_address_local_var->country_code = country_code;
    location_address_local_var->state = state;
    location_address_local_var->city = city;
    location_address_local_var->street = street;

    location_address_local_var->_library_owned = 1;
    return location_address_local_var;
}

__attribute__((deprecated)) location_address_t *location_address_create(
    char *country_code,
    char *state,
    char *city,
    char *street
    ) {
    return location_address_create_internal (
        country_code,
        state,
        city,
        street
        );
}

void location_address_free(location_address_t *location_address) {
    if(NULL == location_address){
        return ;
    }
    if(location_address->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "location_address_free");
        return ;
    }
    listEntry_t *listEntry;
    if (location_address->country_code) {
        free(location_address->country_code);
        location_address->country_code = NULL;
    }
    if (location_address->state) {
        free(location_address->state);
        location_address->state = NULL;
    }
    if (location_address->city) {
        free(location_address->city);
        location_address->city = NULL;
    }
    if (location_address->street) {
        free(location_address->street);
        location_address->street = NULL;
    }
    free(location_address);
}

cJSON *location_address_convertToJSON(location_address_t *location_address) {
    cJSON *item = cJSON_CreateObject();

    // location_address->country_code
    if (!location_address->country_code) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "country_code", location_address->country_code) == NULL) {
    goto fail; //String
    }


    // location_address->state
    if(location_address->state) {
    if(cJSON_AddStringToObject(item, "state", location_address->state) == NULL) {
    goto fail; //String
    }
    }


    // location_address->city
    if(location_address->city) {
    if(cJSON_AddStringToObject(item, "city", location_address->city) == NULL) {
    goto fail; //String
    }
    }


    // location_address->street
    if(location_address->street) {
    if(cJSON_AddStringToObject(item, "street", location_address->street) == NULL) {
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

location_address_t *location_address_parseFromJSON(cJSON *location_addressJSON){

    location_address_t *location_address_local_var = NULL;

    // location_address->country_code
    cJSON *country_code = cJSON_GetObjectItemCaseSensitive(location_addressJSON, "country_code");
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

    // location_address->state
    cJSON *state = cJSON_GetObjectItemCaseSensitive(location_addressJSON, "state");
    if (cJSON_IsNull(state)) {
        state = NULL;
    }
    if (state) { 
    if(!cJSON_IsString(state) && !cJSON_IsNull(state))
    {
    goto end; //String
    }
    }

    // location_address->city
    cJSON *city = cJSON_GetObjectItemCaseSensitive(location_addressJSON, "city");
    if (cJSON_IsNull(city)) {
        city = NULL;
    }
    if (city) { 
    if(!cJSON_IsString(city) && !cJSON_IsNull(city))
    {
    goto end; //String
    }
    }

    // location_address->street
    cJSON *street = cJSON_GetObjectItemCaseSensitive(location_addressJSON, "street");
    if (cJSON_IsNull(street)) {
        street = NULL;
    }
    if (street) { 
    if(!cJSON_IsString(street) && !cJSON_IsNull(street))
    {
    goto end; //String
    }
    }


    location_address_local_var = location_address_create_internal (
        strdup(country_code->valuestring),
        state && !cJSON_IsNull(state) ? strdup(state->valuestring) : NULL,
        city && !cJSON_IsNull(city) ? strdup(city->valuestring) : NULL,
        street && !cJSON_IsNull(street) ? strdup(street->valuestring) : NULL
        );

    return location_address_local_var;
end:
    return NULL;

}
