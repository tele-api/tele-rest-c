#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "order_info.h"



static order_info_t *order_info_create_internal(
    char *name,
    char *phone_number,
    char *email,
    shipping_address_t *shipping_address
    ) {
    order_info_t *order_info_local_var = malloc(sizeof(order_info_t));
    if (!order_info_local_var) {
        return NULL;
    }
    order_info_local_var->name = name;
    order_info_local_var->phone_number = phone_number;
    order_info_local_var->email = email;
    order_info_local_var->shipping_address = shipping_address;

    order_info_local_var->_library_owned = 1;
    return order_info_local_var;
}

__attribute__((deprecated)) order_info_t *order_info_create(
    char *name,
    char *phone_number,
    char *email,
    shipping_address_t *shipping_address
    ) {
    return order_info_create_internal (
        name,
        phone_number,
        email,
        shipping_address
        );
}

void order_info_free(order_info_t *order_info) {
    if(NULL == order_info){
        return ;
    }
    if(order_info->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "order_info_free");
        return ;
    }
    listEntry_t *listEntry;
    if (order_info->name) {
        free(order_info->name);
        order_info->name = NULL;
    }
    if (order_info->phone_number) {
        free(order_info->phone_number);
        order_info->phone_number = NULL;
    }
    if (order_info->email) {
        free(order_info->email);
        order_info->email = NULL;
    }
    if (order_info->shipping_address) {
        shipping_address_free(order_info->shipping_address);
        order_info->shipping_address = NULL;
    }
    free(order_info);
}

cJSON *order_info_convertToJSON(order_info_t *order_info) {
    cJSON *item = cJSON_CreateObject();

    // order_info->name
    if(order_info->name) {
    if(cJSON_AddStringToObject(item, "name", order_info->name) == NULL) {
    goto fail; //String
    }
    }


    // order_info->phone_number
    if(order_info->phone_number) {
    if(cJSON_AddStringToObject(item, "phone_number", order_info->phone_number) == NULL) {
    goto fail; //String
    }
    }


    // order_info->email
    if(order_info->email) {
    if(cJSON_AddStringToObject(item, "email", order_info->email) == NULL) {
    goto fail; //String
    }
    }


    // order_info->shipping_address
    if(order_info->shipping_address) {
    cJSON *shipping_address_local_JSON = shipping_address_convertToJSON(order_info->shipping_address);
    if(shipping_address_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "shipping_address", shipping_address_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

order_info_t *order_info_parseFromJSON(cJSON *order_infoJSON){

    order_info_t *order_info_local_var = NULL;

    // define the local variable for order_info->shipping_address
    shipping_address_t *shipping_address_local_nonprim = NULL;

    // order_info->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(order_infoJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // order_info->phone_number
    cJSON *phone_number = cJSON_GetObjectItemCaseSensitive(order_infoJSON, "phone_number");
    if (cJSON_IsNull(phone_number)) {
        phone_number = NULL;
    }
    if (phone_number) { 
    if(!cJSON_IsString(phone_number) && !cJSON_IsNull(phone_number))
    {
    goto end; //String
    }
    }

    // order_info->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(order_infoJSON, "email");
    if (cJSON_IsNull(email)) {
        email = NULL;
    }
    if (email) { 
    if(!cJSON_IsString(email) && !cJSON_IsNull(email))
    {
    goto end; //String
    }
    }

    // order_info->shipping_address
    cJSON *shipping_address = cJSON_GetObjectItemCaseSensitive(order_infoJSON, "shipping_address");
    if (cJSON_IsNull(shipping_address)) {
        shipping_address = NULL;
    }
    if (shipping_address) { 
    shipping_address_local_nonprim = shipping_address_parseFromJSON(shipping_address); //nonprimitive
    }


    order_info_local_var = order_info_create_internal (
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        phone_number && !cJSON_IsNull(phone_number) ? strdup(phone_number->valuestring) : NULL,
        email && !cJSON_IsNull(email) ? strdup(email->valuestring) : NULL,
        shipping_address ? shipping_address_local_nonprim : NULL
        );

    return order_info_local_var;
end:
    if (shipping_address_local_nonprim) {
        shipping_address_free(shipping_address_local_nonprim);
        shipping_address_local_nonprim = NULL;
    }
    return NULL;

}
