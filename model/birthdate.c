#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "birthdate.h"



static birthdate_t *birthdate_create_internal(
    int day,
    int month,
    int year
    ) {
    birthdate_t *birthdate_local_var = malloc(sizeof(birthdate_t));
    if (!birthdate_local_var) {
        return NULL;
    }
    birthdate_local_var->day = day;
    birthdate_local_var->month = month;
    birthdate_local_var->year = year;

    birthdate_local_var->_library_owned = 1;
    return birthdate_local_var;
}

__attribute__((deprecated)) birthdate_t *birthdate_create(
    int day,
    int month,
    int year
    ) {
    return birthdate_create_internal (
        day,
        month,
        year
        );
}

void birthdate_free(birthdate_t *birthdate) {
    if(NULL == birthdate){
        return ;
    }
    if(birthdate->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "birthdate_free");
        return ;
    }
    listEntry_t *listEntry;
    free(birthdate);
}

cJSON *birthdate_convertToJSON(birthdate_t *birthdate) {
    cJSON *item = cJSON_CreateObject();

    // birthdate->day
    if (!birthdate->day) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "day", birthdate->day) == NULL) {
    goto fail; //Numeric
    }


    // birthdate->month
    if (!birthdate->month) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "month", birthdate->month) == NULL) {
    goto fail; //Numeric
    }


    // birthdate->year
    if(birthdate->year) {
    if(cJSON_AddNumberToObject(item, "year", birthdate->year) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

birthdate_t *birthdate_parseFromJSON(cJSON *birthdateJSON){

    birthdate_t *birthdate_local_var = NULL;

    // birthdate->day
    cJSON *day = cJSON_GetObjectItemCaseSensitive(birthdateJSON, "day");
    if (cJSON_IsNull(day)) {
        day = NULL;
    }
    if (!day) {
        goto end;
    }

    
    if(!cJSON_IsNumber(day))
    {
    goto end; //Numeric
    }

    // birthdate->month
    cJSON *month = cJSON_GetObjectItemCaseSensitive(birthdateJSON, "month");
    if (cJSON_IsNull(month)) {
        month = NULL;
    }
    if (!month) {
        goto end;
    }

    
    if(!cJSON_IsNumber(month))
    {
    goto end; //Numeric
    }

    // birthdate->year
    cJSON *year = cJSON_GetObjectItemCaseSensitive(birthdateJSON, "year");
    if (cJSON_IsNull(year)) {
        year = NULL;
    }
    if (year) { 
    if(!cJSON_IsNumber(year))
    {
    goto end; //Numeric
    }
    }


    birthdate_local_var = birthdate_create_internal (
        day->valuedouble,
        month->valuedouble,
        year ? year->valuedouble : 0
        );

    return birthdate_local_var;
end:
    return NULL;

}
