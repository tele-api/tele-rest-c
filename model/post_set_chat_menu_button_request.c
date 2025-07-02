#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_set_chat_menu_button_request.h"



static post_set_chat_menu_button_request_t *post_set_chat_menu_button_request_create_internal(
    int chat_id,
    menu_button_t *menu_button
    ) {
    post_set_chat_menu_button_request_t *post_set_chat_menu_button_request_local_var = malloc(sizeof(post_set_chat_menu_button_request_t));
    if (!post_set_chat_menu_button_request_local_var) {
        return NULL;
    }
    post_set_chat_menu_button_request_local_var->chat_id = chat_id;
    post_set_chat_menu_button_request_local_var->menu_button = menu_button;

    post_set_chat_menu_button_request_local_var->_library_owned = 1;
    return post_set_chat_menu_button_request_local_var;
}

__attribute__((deprecated)) post_set_chat_menu_button_request_t *post_set_chat_menu_button_request_create(
    int chat_id,
    menu_button_t *menu_button
    ) {
    return post_set_chat_menu_button_request_create_internal (
        chat_id,
        menu_button
        );
}

void post_set_chat_menu_button_request_free(post_set_chat_menu_button_request_t *post_set_chat_menu_button_request) {
    if(NULL == post_set_chat_menu_button_request){
        return ;
    }
    if(post_set_chat_menu_button_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_set_chat_menu_button_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_set_chat_menu_button_request->menu_button) {
        menu_button_free(post_set_chat_menu_button_request->menu_button);
        post_set_chat_menu_button_request->menu_button = NULL;
    }
    free(post_set_chat_menu_button_request);
}

cJSON *post_set_chat_menu_button_request_convertToJSON(post_set_chat_menu_button_request_t *post_set_chat_menu_button_request) {
    cJSON *item = cJSON_CreateObject();

    // post_set_chat_menu_button_request->chat_id
    if(post_set_chat_menu_button_request->chat_id) {
    if(cJSON_AddNumberToObject(item, "chat_id", post_set_chat_menu_button_request->chat_id) == NULL) {
    goto fail; //Numeric
    }
    }


    // post_set_chat_menu_button_request->menu_button
    if(post_set_chat_menu_button_request->menu_button) {
    cJSON *menu_button_local_JSON = menu_button_convertToJSON(post_set_chat_menu_button_request->menu_button);
    if(menu_button_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "menu_button", menu_button_local_JSON);
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

post_set_chat_menu_button_request_t *post_set_chat_menu_button_request_parseFromJSON(cJSON *post_set_chat_menu_button_requestJSON){

    post_set_chat_menu_button_request_t *post_set_chat_menu_button_request_local_var = NULL;

    // define the local variable for post_set_chat_menu_button_request->menu_button
    menu_button_t *menu_button_local_nonprim = NULL;

    // post_set_chat_menu_button_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(post_set_chat_menu_button_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (chat_id) { 
    if(!cJSON_IsNumber(chat_id))
    {
    goto end; //Numeric
    }
    }

    // post_set_chat_menu_button_request->menu_button
    cJSON *menu_button = cJSON_GetObjectItemCaseSensitive(post_set_chat_menu_button_requestJSON, "menu_button");
    if (cJSON_IsNull(menu_button)) {
        menu_button = NULL;
    }
    if (menu_button) { 
    menu_button_local_nonprim = menu_button_parseFromJSON(menu_button); //nonprimitive
    }


    post_set_chat_menu_button_request_local_var = post_set_chat_menu_button_request_create_internal (
        chat_id ? chat_id->valuedouble : 0,
        menu_button ? menu_button_local_nonprim : NULL
        );

    return post_set_chat_menu_button_request_local_var;
end:
    if (menu_button_local_nonprim) {
        menu_button_free(menu_button_local_nonprim);
        menu_button_local_nonprim = NULL;
    }
    return NULL;

}
