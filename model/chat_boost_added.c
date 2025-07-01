#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "chat_boost_added.h"



static chat_boost_added_t *chat_boost_added_create_internal(
    int boost_count
    ) {
    chat_boost_added_t *chat_boost_added_local_var = malloc(sizeof(chat_boost_added_t));
    if (!chat_boost_added_local_var) {
        return NULL;
    }
    chat_boost_added_local_var->boost_count = boost_count;

    chat_boost_added_local_var->_library_owned = 1;
    return chat_boost_added_local_var;
}

__attribute__((deprecated)) chat_boost_added_t *chat_boost_added_create(
    int boost_count
    ) {
    return chat_boost_added_create_internal (
        boost_count
        );
}

void chat_boost_added_free(chat_boost_added_t *chat_boost_added) {
    if(NULL == chat_boost_added){
        return ;
    }
    if(chat_boost_added->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "chat_boost_added_free");
        return ;
    }
    listEntry_t *listEntry;
    free(chat_boost_added);
}

cJSON *chat_boost_added_convertToJSON(chat_boost_added_t *chat_boost_added) {
    cJSON *item = cJSON_CreateObject();

    // chat_boost_added->boost_count
    if (!chat_boost_added->boost_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "boost_count", chat_boost_added->boost_count) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

chat_boost_added_t *chat_boost_added_parseFromJSON(cJSON *chat_boost_addedJSON){

    chat_boost_added_t *chat_boost_added_local_var = NULL;

    // chat_boost_added->boost_count
    cJSON *boost_count = cJSON_GetObjectItemCaseSensitive(chat_boost_addedJSON, "boost_count");
    if (cJSON_IsNull(boost_count)) {
        boost_count = NULL;
    }
    if (!boost_count) {
        goto end;
    }

    
    if(!cJSON_IsNumber(boost_count))
    {
    goto end; //Numeric
    }


    chat_boost_added_local_var = chat_boost_added_create_internal (
        boost_count->valuedouble
        );

    return chat_boost_added_local_var;
end:
    return NULL;

}
