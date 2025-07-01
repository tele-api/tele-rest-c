#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "paid_message_price_changed.h"



static paid_message_price_changed_t *paid_message_price_changed_create_internal(
    int paid_message_star_count
    ) {
    paid_message_price_changed_t *paid_message_price_changed_local_var = malloc(sizeof(paid_message_price_changed_t));
    if (!paid_message_price_changed_local_var) {
        return NULL;
    }
    paid_message_price_changed_local_var->paid_message_star_count = paid_message_star_count;

    paid_message_price_changed_local_var->_library_owned = 1;
    return paid_message_price_changed_local_var;
}

__attribute__((deprecated)) paid_message_price_changed_t *paid_message_price_changed_create(
    int paid_message_star_count
    ) {
    return paid_message_price_changed_create_internal (
        paid_message_star_count
        );
}

void paid_message_price_changed_free(paid_message_price_changed_t *paid_message_price_changed) {
    if(NULL == paid_message_price_changed){
        return ;
    }
    if(paid_message_price_changed->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "paid_message_price_changed_free");
        return ;
    }
    listEntry_t *listEntry;
    free(paid_message_price_changed);
}

cJSON *paid_message_price_changed_convertToJSON(paid_message_price_changed_t *paid_message_price_changed) {
    cJSON *item = cJSON_CreateObject();

    // paid_message_price_changed->paid_message_star_count
    if (!paid_message_price_changed->paid_message_star_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "paid_message_star_count", paid_message_price_changed->paid_message_star_count) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

paid_message_price_changed_t *paid_message_price_changed_parseFromJSON(cJSON *paid_message_price_changedJSON){

    paid_message_price_changed_t *paid_message_price_changed_local_var = NULL;

    // paid_message_price_changed->paid_message_star_count
    cJSON *paid_message_star_count = cJSON_GetObjectItemCaseSensitive(paid_message_price_changedJSON, "paid_message_star_count");
    if (cJSON_IsNull(paid_message_star_count)) {
        paid_message_star_count = NULL;
    }
    if (!paid_message_star_count) {
        goto end;
    }

    
    if(!cJSON_IsNumber(paid_message_star_count))
    {
    goto end; //Numeric
    }


    paid_message_price_changed_local_var = paid_message_price_changed_create_internal (
        paid_message_star_count->valuedouble
        );

    return paid_message_price_changed_local_var;
end:
    return NULL;

}
