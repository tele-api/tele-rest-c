#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_create_chat_subscription_invite_link_request.h"



static post_create_chat_subscription_invite_link_request_t *post_create_chat_subscription_invite_link_request_create_internal(
    post_create_chat_subscription_invite_link_request_chat_id_t *chat_id,
    int subscription_period,
    int subscription_price,
    char *name
    ) {
    post_create_chat_subscription_invite_link_request_t *post_create_chat_subscription_invite_link_request_local_var = malloc(sizeof(post_create_chat_subscription_invite_link_request_t));
    if (!post_create_chat_subscription_invite_link_request_local_var) {
        return NULL;
    }
    post_create_chat_subscription_invite_link_request_local_var->chat_id = chat_id;
    post_create_chat_subscription_invite_link_request_local_var->subscription_period = subscription_period;
    post_create_chat_subscription_invite_link_request_local_var->subscription_price = subscription_price;
    post_create_chat_subscription_invite_link_request_local_var->name = name;

    post_create_chat_subscription_invite_link_request_local_var->_library_owned = 1;
    return post_create_chat_subscription_invite_link_request_local_var;
}

__attribute__((deprecated)) post_create_chat_subscription_invite_link_request_t *post_create_chat_subscription_invite_link_request_create(
    post_create_chat_subscription_invite_link_request_chat_id_t *chat_id,
    int subscription_period,
    int subscription_price,
    char *name
    ) {
    return post_create_chat_subscription_invite_link_request_create_internal (
        chat_id,
        subscription_period,
        subscription_price,
        name
        );
}

void post_create_chat_subscription_invite_link_request_free(post_create_chat_subscription_invite_link_request_t *post_create_chat_subscription_invite_link_request) {
    if(NULL == post_create_chat_subscription_invite_link_request){
        return ;
    }
    if(post_create_chat_subscription_invite_link_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_create_chat_subscription_invite_link_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_create_chat_subscription_invite_link_request->chat_id) {
        post_create_chat_subscription_invite_link_request_chat_id_free(post_create_chat_subscription_invite_link_request->chat_id);
        post_create_chat_subscription_invite_link_request->chat_id = NULL;
    }
    if (post_create_chat_subscription_invite_link_request->name) {
        free(post_create_chat_subscription_invite_link_request->name);
        post_create_chat_subscription_invite_link_request->name = NULL;
    }
    free(post_create_chat_subscription_invite_link_request);
}

cJSON *post_create_chat_subscription_invite_link_request_convertToJSON(post_create_chat_subscription_invite_link_request_t *post_create_chat_subscription_invite_link_request) {
    cJSON *item = cJSON_CreateObject();

    // post_create_chat_subscription_invite_link_request->chat_id
    if (!post_create_chat_subscription_invite_link_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = post_create_chat_subscription_invite_link_request_chat_id_convertToJSON(post_create_chat_subscription_invite_link_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // post_create_chat_subscription_invite_link_request->subscription_period
    if (!post_create_chat_subscription_invite_link_request->subscription_period) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "subscription_period", post_create_chat_subscription_invite_link_request->subscription_period) == NULL) {
    goto fail; //Numeric
    }


    // post_create_chat_subscription_invite_link_request->subscription_price
    if (!post_create_chat_subscription_invite_link_request->subscription_price) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "subscription_price", post_create_chat_subscription_invite_link_request->subscription_price) == NULL) {
    goto fail; //Numeric
    }


    // post_create_chat_subscription_invite_link_request->name
    if(post_create_chat_subscription_invite_link_request->name) {
    if(cJSON_AddStringToObject(item, "name", post_create_chat_subscription_invite_link_request->name) == NULL) {
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

post_create_chat_subscription_invite_link_request_t *post_create_chat_subscription_invite_link_request_parseFromJSON(cJSON *post_create_chat_subscription_invite_link_requestJSON){

    post_create_chat_subscription_invite_link_request_t *post_create_chat_subscription_invite_link_request_local_var = NULL;

    // define the local variable for post_create_chat_subscription_invite_link_request->chat_id
    post_create_chat_subscription_invite_link_request_chat_id_t *chat_id_local_nonprim = NULL;

    // post_create_chat_subscription_invite_link_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(post_create_chat_subscription_invite_link_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = post_create_chat_subscription_invite_link_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // post_create_chat_subscription_invite_link_request->subscription_period
    cJSON *subscription_period = cJSON_GetObjectItemCaseSensitive(post_create_chat_subscription_invite_link_requestJSON, "subscription_period");
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

    // post_create_chat_subscription_invite_link_request->subscription_price
    cJSON *subscription_price = cJSON_GetObjectItemCaseSensitive(post_create_chat_subscription_invite_link_requestJSON, "subscription_price");
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

    // post_create_chat_subscription_invite_link_request->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(post_create_chat_subscription_invite_link_requestJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }


    post_create_chat_subscription_invite_link_request_local_var = post_create_chat_subscription_invite_link_request_create_internal (
        chat_id_local_nonprim,
        subscription_period->valuedouble,
        subscription_price->valuedouble,
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL
        );

    return post_create_chat_subscription_invite_link_request_local_var;
end:
    if (chat_id_local_nonprim) {
        post_create_chat_subscription_invite_link_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
