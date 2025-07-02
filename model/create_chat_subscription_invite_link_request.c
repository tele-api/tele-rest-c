#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "create_chat_subscription_invite_link_request.h"



static create_chat_subscription_invite_link_request_t *create_chat_subscription_invite_link_request_create_internal(
    create_chat_subscription_invite_link_request_chat_id_t *chat_id,
    int subscription_period,
    int subscription_price,
    char *name
    ) {
    create_chat_subscription_invite_link_request_t *create_chat_subscription_invite_link_request_local_var = malloc(sizeof(create_chat_subscription_invite_link_request_t));
    if (!create_chat_subscription_invite_link_request_local_var) {
        return NULL;
    }
    create_chat_subscription_invite_link_request_local_var->chat_id = chat_id;
    create_chat_subscription_invite_link_request_local_var->subscription_period = subscription_period;
    create_chat_subscription_invite_link_request_local_var->subscription_price = subscription_price;
    create_chat_subscription_invite_link_request_local_var->name = name;

    create_chat_subscription_invite_link_request_local_var->_library_owned = 1;
    return create_chat_subscription_invite_link_request_local_var;
}

__attribute__((deprecated)) create_chat_subscription_invite_link_request_t *create_chat_subscription_invite_link_request_create(
    create_chat_subscription_invite_link_request_chat_id_t *chat_id,
    int subscription_period,
    int subscription_price,
    char *name
    ) {
    return create_chat_subscription_invite_link_request_create_internal (
        chat_id,
        subscription_period,
        subscription_price,
        name
        );
}

void create_chat_subscription_invite_link_request_free(create_chat_subscription_invite_link_request_t *create_chat_subscription_invite_link_request) {
    if(NULL == create_chat_subscription_invite_link_request){
        return ;
    }
    if(create_chat_subscription_invite_link_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "create_chat_subscription_invite_link_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (create_chat_subscription_invite_link_request->chat_id) {
        create_chat_subscription_invite_link_request_chat_id_free(create_chat_subscription_invite_link_request->chat_id);
        create_chat_subscription_invite_link_request->chat_id = NULL;
    }
    if (create_chat_subscription_invite_link_request->name) {
        free(create_chat_subscription_invite_link_request->name);
        create_chat_subscription_invite_link_request->name = NULL;
    }
    free(create_chat_subscription_invite_link_request);
}

cJSON *create_chat_subscription_invite_link_request_convertToJSON(create_chat_subscription_invite_link_request_t *create_chat_subscription_invite_link_request) {
    cJSON *item = cJSON_CreateObject();

    // create_chat_subscription_invite_link_request->chat_id
    if (!create_chat_subscription_invite_link_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = create_chat_subscription_invite_link_request_chat_id_convertToJSON(create_chat_subscription_invite_link_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // create_chat_subscription_invite_link_request->subscription_period
    if (!create_chat_subscription_invite_link_request->subscription_period) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "subscription_period", create_chat_subscription_invite_link_request->subscription_period) == NULL) {
    goto fail; //Numeric
    }


    // create_chat_subscription_invite_link_request->subscription_price
    if (!create_chat_subscription_invite_link_request->subscription_price) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "subscription_price", create_chat_subscription_invite_link_request->subscription_price) == NULL) {
    goto fail; //Numeric
    }


    // create_chat_subscription_invite_link_request->name
    if(create_chat_subscription_invite_link_request->name) {
    if(cJSON_AddStringToObject(item, "name", create_chat_subscription_invite_link_request->name) == NULL) {
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

create_chat_subscription_invite_link_request_t *create_chat_subscription_invite_link_request_parseFromJSON(cJSON *create_chat_subscription_invite_link_requestJSON){

    create_chat_subscription_invite_link_request_t *create_chat_subscription_invite_link_request_local_var = NULL;

    // define the local variable for create_chat_subscription_invite_link_request->chat_id
    create_chat_subscription_invite_link_request_chat_id_t *chat_id_local_nonprim = NULL;

    // create_chat_subscription_invite_link_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(create_chat_subscription_invite_link_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = create_chat_subscription_invite_link_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // create_chat_subscription_invite_link_request->subscription_period
    cJSON *subscription_period = cJSON_GetObjectItemCaseSensitive(create_chat_subscription_invite_link_requestJSON, "subscription_period");
    if (cJSON_IsNull(subscription_period)) {
        subscription_period = NULL;
    }
    if (!subscription_period) {
        goto end;
    }

    
    if(!cJSON_IsNumber(subscription_period))
    {
    goto end; //Numeric
    }

    // create_chat_subscription_invite_link_request->subscription_price
    cJSON *subscription_price = cJSON_GetObjectItemCaseSensitive(create_chat_subscription_invite_link_requestJSON, "subscription_price");
    if (cJSON_IsNull(subscription_price)) {
        subscription_price = NULL;
    }
    if (!subscription_price) {
        goto end;
    }

    
    if(!cJSON_IsNumber(subscription_price))
    {
    goto end; //Numeric
    }

    // create_chat_subscription_invite_link_request->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(create_chat_subscription_invite_link_requestJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }


    create_chat_subscription_invite_link_request_local_var = create_chat_subscription_invite_link_request_create_internal (
        chat_id_local_nonprim,
        subscription_period->valuedouble,
        subscription_price->valuedouble,
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL
        );

    return create_chat_subscription_invite_link_request_local_var;
end:
    if (chat_id_local_nonprim) {
        create_chat_subscription_invite_link_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
