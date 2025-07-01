#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "proximity_alert_triggered.h"



static proximity_alert_triggered_t *proximity_alert_triggered_create_internal(
    user_t *traveler,
    user_t *watcher,
    int distance
    ) {
    proximity_alert_triggered_t *proximity_alert_triggered_local_var = malloc(sizeof(proximity_alert_triggered_t));
    if (!proximity_alert_triggered_local_var) {
        return NULL;
    }
    proximity_alert_triggered_local_var->traveler = traveler;
    proximity_alert_triggered_local_var->watcher = watcher;
    proximity_alert_triggered_local_var->distance = distance;

    proximity_alert_triggered_local_var->_library_owned = 1;
    return proximity_alert_triggered_local_var;
}

__attribute__((deprecated)) proximity_alert_triggered_t *proximity_alert_triggered_create(
    user_t *traveler,
    user_t *watcher,
    int distance
    ) {
    return proximity_alert_triggered_create_internal (
        traveler,
        watcher,
        distance
        );
}

void proximity_alert_triggered_free(proximity_alert_triggered_t *proximity_alert_triggered) {
    if(NULL == proximity_alert_triggered){
        return ;
    }
    if(proximity_alert_triggered->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "proximity_alert_triggered_free");
        return ;
    }
    listEntry_t *listEntry;
    if (proximity_alert_triggered->traveler) {
        user_free(proximity_alert_triggered->traveler);
        proximity_alert_triggered->traveler = NULL;
    }
    if (proximity_alert_triggered->watcher) {
        user_free(proximity_alert_triggered->watcher);
        proximity_alert_triggered->watcher = NULL;
    }
    free(proximity_alert_triggered);
}

cJSON *proximity_alert_triggered_convertToJSON(proximity_alert_triggered_t *proximity_alert_triggered) {
    cJSON *item = cJSON_CreateObject();

    // proximity_alert_triggered->traveler
    if (!proximity_alert_triggered->traveler) {
        goto fail;
    }
    cJSON *traveler_local_JSON = user_convertToJSON(proximity_alert_triggered->traveler);
    if(traveler_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "traveler", traveler_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // proximity_alert_triggered->watcher
    if (!proximity_alert_triggered->watcher) {
        goto fail;
    }
    cJSON *watcher_local_JSON = user_convertToJSON(proximity_alert_triggered->watcher);
    if(watcher_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "watcher", watcher_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // proximity_alert_triggered->distance
    if (!proximity_alert_triggered->distance) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "distance", proximity_alert_triggered->distance) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

proximity_alert_triggered_t *proximity_alert_triggered_parseFromJSON(cJSON *proximity_alert_triggeredJSON){

    proximity_alert_triggered_t *proximity_alert_triggered_local_var = NULL;

    // define the local variable for proximity_alert_triggered->traveler
    user_t *traveler_local_nonprim = NULL;

    // define the local variable for proximity_alert_triggered->watcher
    user_t *watcher_local_nonprim = NULL;

    // proximity_alert_triggered->traveler
    cJSON *traveler = cJSON_GetObjectItemCaseSensitive(proximity_alert_triggeredJSON, "traveler");
    if (cJSON_IsNull(traveler)) {
        traveler = NULL;
    }
    if (!traveler) {
        goto end;
    }

    
    traveler_local_nonprim = user_parseFromJSON(traveler); //nonprimitive

    // proximity_alert_triggered->watcher
    cJSON *watcher = cJSON_GetObjectItemCaseSensitive(proximity_alert_triggeredJSON, "watcher");
    if (cJSON_IsNull(watcher)) {
        watcher = NULL;
    }
    if (!watcher) {
        goto end;
    }

    
    watcher_local_nonprim = user_parseFromJSON(watcher); //nonprimitive

    // proximity_alert_triggered->distance
    cJSON *distance = cJSON_GetObjectItemCaseSensitive(proximity_alert_triggeredJSON, "distance");
    if (cJSON_IsNull(distance)) {
        distance = NULL;
    }
    if (!distance) {
        goto end;
    }

    
    if(!cJSON_IsNumber(distance))
    {
    goto end; //Numeric
    }


    proximity_alert_triggered_local_var = proximity_alert_triggered_create_internal (
        traveler_local_nonprim,
        watcher_local_nonprim,
        distance->valuedouble
        );

    return proximity_alert_triggered_local_var;
end:
    if (traveler_local_nonprim) {
        user_free(traveler_local_nonprim);
        traveler_local_nonprim = NULL;
    }
    if (watcher_local_nonprim) {
        user_free(watcher_local_nonprim);
        watcher_local_nonprim = NULL;
    }
    return NULL;

}
