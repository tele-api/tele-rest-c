#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "business_connection.h"



static business_connection_t *business_connection_create_internal(
    char *id,
    user_t *user,
    int user_chat_id,
    int date,
    int is_enabled,
    business_bot_rights_t *rights
    ) {
    business_connection_t *business_connection_local_var = malloc(sizeof(business_connection_t));
    if (!business_connection_local_var) {
        return NULL;
    }
    business_connection_local_var->id = id;
    business_connection_local_var->user = user;
    business_connection_local_var->user_chat_id = user_chat_id;
    business_connection_local_var->date = date;
    business_connection_local_var->is_enabled = is_enabled;
    business_connection_local_var->rights = rights;

    business_connection_local_var->_library_owned = 1;
    return business_connection_local_var;
}

__attribute__((deprecated)) business_connection_t *business_connection_create(
    char *id,
    user_t *user,
    int user_chat_id,
    int date,
    int is_enabled,
    business_bot_rights_t *rights
    ) {
    return business_connection_create_internal (
        id,
        user,
        user_chat_id,
        date,
        is_enabled,
        rights
        );
}

void business_connection_free(business_connection_t *business_connection) {
    if(NULL == business_connection){
        return ;
    }
    if(business_connection->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "business_connection_free");
        return ;
    }
    listEntry_t *listEntry;
    if (business_connection->id) {
        free(business_connection->id);
        business_connection->id = NULL;
    }
    if (business_connection->user) {
        user_free(business_connection->user);
        business_connection->user = NULL;
    }
    if (business_connection->rights) {
        business_bot_rights_free(business_connection->rights);
        business_connection->rights = NULL;
    }
    free(business_connection);
}

cJSON *business_connection_convertToJSON(business_connection_t *business_connection) {
    cJSON *item = cJSON_CreateObject();

    // business_connection->id
    if (!business_connection->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", business_connection->id) == NULL) {
    goto fail; //String
    }


    // business_connection->user
    if (!business_connection->user) {
        goto fail;
    }
    cJSON *user_local_JSON = user_convertToJSON(business_connection->user);
    if(user_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "user", user_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // business_connection->user_chat_id
    if (!business_connection->user_chat_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "user_chat_id", business_connection->user_chat_id) == NULL) {
    goto fail; //Numeric
    }


    // business_connection->date
    if (!business_connection->date) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "date", business_connection->date) == NULL) {
    goto fail; //Numeric
    }


    // business_connection->is_enabled
    if (!business_connection->is_enabled) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "is_enabled", business_connection->is_enabled) == NULL) {
    goto fail; //Bool
    }


    // business_connection->rights
    if(business_connection->rights) {
    cJSON *rights_local_JSON = business_bot_rights_convertToJSON(business_connection->rights);
    if(rights_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "rights", rights_local_JSON);
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

business_connection_t *business_connection_parseFromJSON(cJSON *business_connectionJSON){

    business_connection_t *business_connection_local_var = NULL;

    // define the local variable for business_connection->user
    user_t *user_local_nonprim = NULL;

    // define the local variable for business_connection->rights
    business_bot_rights_t *rights_local_nonprim = NULL;

    // business_connection->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(business_connectionJSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (!id) {
        goto end;
    }

    
    if(!cJSON_IsString(id))
    {
    goto end; //String
    }

    // business_connection->user
    cJSON *user = cJSON_GetObjectItemCaseSensitive(business_connectionJSON, "user");
    if (cJSON_IsNull(user)) {
        user = NULL;
    }
    if (!user) {
        goto end;
    }

    
    user_local_nonprim = user_parseFromJSON(user); //nonprimitive

    // business_connection->user_chat_id
    cJSON *user_chat_id = cJSON_GetObjectItemCaseSensitive(business_connectionJSON, "user_chat_id");
    if (cJSON_IsNull(user_chat_id)) {
        user_chat_id = NULL;
    }
    if (!user_chat_id) {
        goto end;
    }

    
    if(!cJSON_IsNumber(user_chat_id))
    {
    goto end; //Numeric
    }

    // business_connection->date
    cJSON *date = cJSON_GetObjectItemCaseSensitive(business_connectionJSON, "date");
    if (cJSON_IsNull(date)) {
        date = NULL;
    }
    if (!date) {
        goto end;
    }

    
    if(!cJSON_IsNumber(date))
    {
    goto end; //Numeric
    }

    // business_connection->is_enabled
    cJSON *is_enabled = cJSON_GetObjectItemCaseSensitive(business_connectionJSON, "is_enabled");
    if (cJSON_IsNull(is_enabled)) {
        is_enabled = NULL;
    }
    if (!is_enabled) {
        goto end;
    }

    
    if(!cJSON_IsBool(is_enabled))
    {
    goto end; //Bool
    }

    // business_connection->rights
    cJSON *rights = cJSON_GetObjectItemCaseSensitive(business_connectionJSON, "rights");
    if (cJSON_IsNull(rights)) {
        rights = NULL;
    }
    if (rights) { 
    rights_local_nonprim = business_bot_rights_parseFromJSON(rights); //nonprimitive
    }


    business_connection_local_var = business_connection_create_internal (
        strdup(id->valuestring),
        user_local_nonprim,
        user_chat_id->valuedouble,
        date->valuedouble,
        is_enabled->valueint,
        rights ? rights_local_nonprim : NULL
        );

    return business_connection_local_var;
end:
    if (user_local_nonprim) {
        user_free(user_local_nonprim);
        user_local_nonprim = NULL;
    }
    if (rights_local_nonprim) {
        business_bot_rights_free(rights_local_nonprim);
        rights_local_nonprim = NULL;
    }
    return NULL;

}
