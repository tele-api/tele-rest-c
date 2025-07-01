#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "business_opening_hours_interval.h"



static business_opening_hours_interval_t *business_opening_hours_interval_create_internal(
    int opening_minute,
    int closing_minute
    ) {
    business_opening_hours_interval_t *business_opening_hours_interval_local_var = malloc(sizeof(business_opening_hours_interval_t));
    if (!business_opening_hours_interval_local_var) {
        return NULL;
    }
    business_opening_hours_interval_local_var->opening_minute = opening_minute;
    business_opening_hours_interval_local_var->closing_minute = closing_minute;

    business_opening_hours_interval_local_var->_library_owned = 1;
    return business_opening_hours_interval_local_var;
}

__attribute__((deprecated)) business_opening_hours_interval_t *business_opening_hours_interval_create(
    int opening_minute,
    int closing_minute
    ) {
    return business_opening_hours_interval_create_internal (
        opening_minute,
        closing_minute
        );
}

void business_opening_hours_interval_free(business_opening_hours_interval_t *business_opening_hours_interval) {
    if(NULL == business_opening_hours_interval){
        return ;
    }
    if(business_opening_hours_interval->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "business_opening_hours_interval_free");
        return ;
    }
    listEntry_t *listEntry;
    free(business_opening_hours_interval);
}

cJSON *business_opening_hours_interval_convertToJSON(business_opening_hours_interval_t *business_opening_hours_interval) {
    cJSON *item = cJSON_CreateObject();

    // business_opening_hours_interval->opening_minute
    if (!business_opening_hours_interval->opening_minute) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "opening_minute", business_opening_hours_interval->opening_minute) == NULL) {
    goto fail; //Numeric
    }


    // business_opening_hours_interval->closing_minute
    if (!business_opening_hours_interval->closing_minute) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "closing_minute", business_opening_hours_interval->closing_minute) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

business_opening_hours_interval_t *business_opening_hours_interval_parseFromJSON(cJSON *business_opening_hours_intervalJSON){

    business_opening_hours_interval_t *business_opening_hours_interval_local_var = NULL;

    // business_opening_hours_interval->opening_minute
    cJSON *opening_minute = cJSON_GetObjectItemCaseSensitive(business_opening_hours_intervalJSON, "opening_minute");
    if (cJSON_IsNull(opening_minute)) {
        opening_minute = NULL;
    }
    if (!opening_minute) {
        goto end;
    }

    
    if(!cJSON_IsNumber(opening_minute))
    {
    goto end; //Numeric
    }

    // business_opening_hours_interval->closing_minute
    cJSON *closing_minute = cJSON_GetObjectItemCaseSensitive(business_opening_hours_intervalJSON, "closing_minute");
    if (cJSON_IsNull(closing_minute)) {
        closing_minute = NULL;
    }
    if (!closing_minute) {
        goto end;
    }

    
    if(!cJSON_IsNumber(closing_minute))
    {
    goto end; //Numeric
    }


    business_opening_hours_interval_local_var = business_opening_hours_interval_create_internal (
        opening_minute->valuedouble,
        closing_minute->valuedouble
        );

    return business_opening_hours_interval_local_var;
end:
    return NULL;

}
