#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "business_intro.h"



static business_intro_t *business_intro_create_internal(
    char *title,
    char *message,
    sticker_t *sticker
    ) {
    business_intro_t *business_intro_local_var = malloc(sizeof(business_intro_t));
    if (!business_intro_local_var) {
        return NULL;
    }
    business_intro_local_var->title = title;
    business_intro_local_var->message = message;
    business_intro_local_var->sticker = sticker;

    business_intro_local_var->_library_owned = 1;
    return business_intro_local_var;
}

__attribute__((deprecated)) business_intro_t *business_intro_create(
    char *title,
    char *message,
    sticker_t *sticker
    ) {
    return business_intro_create_internal (
        title,
        message,
        sticker
        );
}

void business_intro_free(business_intro_t *business_intro) {
    if(NULL == business_intro){
        return ;
    }
    if(business_intro->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "business_intro_free");
        return ;
    }
    listEntry_t *listEntry;
    if (business_intro->title) {
        free(business_intro->title);
        business_intro->title = NULL;
    }
    if (business_intro->message) {
        free(business_intro->message);
        business_intro->message = NULL;
    }
    if (business_intro->sticker) {
        sticker_free(business_intro->sticker);
        business_intro->sticker = NULL;
    }
    free(business_intro);
}

cJSON *business_intro_convertToJSON(business_intro_t *business_intro) {
    cJSON *item = cJSON_CreateObject();

    // business_intro->title
    if(business_intro->title) {
    if(cJSON_AddStringToObject(item, "title", business_intro->title) == NULL) {
    goto fail; //String
    }
    }


    // business_intro->message
    if(business_intro->message) {
    if(cJSON_AddStringToObject(item, "message", business_intro->message) == NULL) {
    goto fail; //String
    }
    }


    // business_intro->sticker
    if(business_intro->sticker) {
    cJSON *sticker_local_JSON = sticker_convertToJSON(business_intro->sticker);
    if(sticker_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "sticker", sticker_local_JSON);
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

business_intro_t *business_intro_parseFromJSON(cJSON *business_introJSON){

    business_intro_t *business_intro_local_var = NULL;

    // define the local variable for business_intro->sticker
    sticker_t *sticker_local_nonprim = NULL;

    // business_intro->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(business_introJSON, "title");
    if (cJSON_IsNull(title)) {
        title = NULL;
    }
    if (title) { 
    if(!cJSON_IsString(title) && !cJSON_IsNull(title))
    {
    goto end; //String
    }
    }

    // business_intro->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(business_introJSON, "message");
    if (cJSON_IsNull(message)) {
        message = NULL;
    }
    if (message) { 
    if(!cJSON_IsString(message) && !cJSON_IsNull(message))
    {
    goto end; //String
    }
    }

    // business_intro->sticker
    cJSON *sticker = cJSON_GetObjectItemCaseSensitive(business_introJSON, "sticker");
    if (cJSON_IsNull(sticker)) {
        sticker = NULL;
    }
    if (sticker) { 
    sticker_local_nonprim = sticker_parseFromJSON(sticker); //nonprimitive
    }


    business_intro_local_var = business_intro_create_internal (
        title && !cJSON_IsNull(title) ? strdup(title->valuestring) : NULL,
        message && !cJSON_IsNull(message) ? strdup(message->valuestring) : NULL,
        sticker ? sticker_local_nonprim : NULL
        );

    return business_intro_local_var;
end:
    if (sticker_local_nonprim) {
        sticker_free(sticker_local_nonprim);
        sticker_local_nonprim = NULL;
    }
    return NULL;

}
