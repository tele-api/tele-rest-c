#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "business_opening_hours.h"



static business_opening_hours_t *business_opening_hours_create_internal(
    char *time_zone_name,
    list_t *opening_hours
    ) {
    business_opening_hours_t *business_opening_hours_local_var = malloc(sizeof(business_opening_hours_t));
    if (!business_opening_hours_local_var) {
        return NULL;
    }
    business_opening_hours_local_var->time_zone_name = time_zone_name;
    business_opening_hours_local_var->opening_hours = opening_hours;

    business_opening_hours_local_var->_library_owned = 1;
    return business_opening_hours_local_var;
}

__attribute__((deprecated)) business_opening_hours_t *business_opening_hours_create(
    char *time_zone_name,
    list_t *opening_hours
    ) {
    return business_opening_hours_create_internal (
        time_zone_name,
        opening_hours
        );
}

void business_opening_hours_free(business_opening_hours_t *business_opening_hours) {
    if(NULL == business_opening_hours){
        return ;
    }
    if(business_opening_hours->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "business_opening_hours_free");
        return ;
    }
    listEntry_t *listEntry;
    if (business_opening_hours->time_zone_name) {
        free(business_opening_hours->time_zone_name);
        business_opening_hours->time_zone_name = NULL;
    }
    if (business_opening_hours->opening_hours) {
        list_ForEach(listEntry, business_opening_hours->opening_hours) {
            business_opening_hours_interval_free(listEntry->data);
        }
        list_freeList(business_opening_hours->opening_hours);
        business_opening_hours->opening_hours = NULL;
    }
    free(business_opening_hours);
}

cJSON *business_opening_hours_convertToJSON(business_opening_hours_t *business_opening_hours) {
    cJSON *item = cJSON_CreateObject();

    // business_opening_hours->time_zone_name
    if (!business_opening_hours->time_zone_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "time_zone_name", business_opening_hours->time_zone_name) == NULL) {
    goto fail; //String
    }


    // business_opening_hours->opening_hours
    if (!business_opening_hours->opening_hours) {
        goto fail;
    }
    cJSON *opening_hours = cJSON_AddArrayToObject(item, "opening_hours");
    if(opening_hours == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *opening_hoursListEntry;
    if (business_opening_hours->opening_hours) {
    list_ForEach(opening_hoursListEntry, business_opening_hours->opening_hours) {
    cJSON *itemLocal = business_opening_hours_interval_convertToJSON(opening_hoursListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(opening_hours, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

business_opening_hours_t *business_opening_hours_parseFromJSON(cJSON *business_opening_hoursJSON){

    business_opening_hours_t *business_opening_hours_local_var = NULL;

    // define the local list for business_opening_hours->opening_hours
    list_t *opening_hoursList = NULL;

    // business_opening_hours->time_zone_name
    cJSON *time_zone_name = cJSON_GetObjectItemCaseSensitive(business_opening_hoursJSON, "time_zone_name");
    if (cJSON_IsNull(time_zone_name)) {
        time_zone_name = NULL;
    }
    if (!time_zone_name) {
        goto end;
    }

    
    if(!cJSON_IsString(time_zone_name))
    {
    goto end; //String
    }

    // business_opening_hours->opening_hours
    cJSON *opening_hours = cJSON_GetObjectItemCaseSensitive(business_opening_hoursJSON, "opening_hours");
    if (cJSON_IsNull(opening_hours)) {
        opening_hours = NULL;
    }
    if (!opening_hours) {
        goto end;
    }

    
    cJSON *opening_hours_local_nonprimitive = NULL;
    if(!cJSON_IsArray(opening_hours)){
        goto end; //nonprimitive container
    }

    opening_hoursList = list_createList();

    cJSON_ArrayForEach(opening_hours_local_nonprimitive,opening_hours )
    {
        if(!cJSON_IsObject(opening_hours_local_nonprimitive)){
            goto end;
        }
        business_opening_hours_interval_t *opening_hoursItem = business_opening_hours_interval_parseFromJSON(opening_hours_local_nonprimitive);

        list_addElement(opening_hoursList, opening_hoursItem);
    }


    business_opening_hours_local_var = business_opening_hours_create_internal (
        strdup(time_zone_name->valuestring),
        opening_hoursList
        );

    return business_opening_hours_local_var;
end:
    if (opening_hoursList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, opening_hoursList) {
            business_opening_hours_interval_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(opening_hoursList);
        opening_hoursList = NULL;
    }
    return NULL;

}
