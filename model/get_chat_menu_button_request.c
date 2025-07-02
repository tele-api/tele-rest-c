#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "get_chat_menu_button_request.h"



static get_chat_menu_button_request_t *get_chat_menu_button_request_create_internal(
    int chat_id
    ) {
    get_chat_menu_button_request_t *get_chat_menu_button_request_local_var = malloc(sizeof(get_chat_menu_button_request_t));
    if (!get_chat_menu_button_request_local_var) {
        return NULL;
    }
    get_chat_menu_button_request_local_var->chat_id = chat_id;

    get_chat_menu_button_request_local_var->_library_owned = 1;
    return get_chat_menu_button_request_local_var;
}

__attribute__((deprecated)) get_chat_menu_button_request_t *get_chat_menu_button_request_create(
    int chat_id
    ) {
    return get_chat_menu_button_request_create_internal (
        chat_id
        );
}

void get_chat_menu_button_request_free(get_chat_menu_button_request_t *get_chat_menu_button_request) {
    if(NULL == get_chat_menu_button_request){
        return ;
    }
    if(get_chat_menu_button_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "get_chat_menu_button_request_free");
        return ;
    }
    listEntry_t *listEntry;
    free(get_chat_menu_button_request);
}

cJSON *get_chat_menu_button_request_convertToJSON(get_chat_menu_button_request_t *get_chat_menu_button_request) {
    cJSON *item = cJSON_CreateObject();

    // get_chat_menu_button_request->chat_id
    if(get_chat_menu_button_request->chat_id) {
    if(cJSON_AddNumberToObject(item, "chat_id", get_chat_menu_button_request->chat_id) == NULL) {
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

get_chat_menu_button_request_t *get_chat_menu_button_request_parseFromJSON(cJSON *get_chat_menu_button_requestJSON){

    get_chat_menu_button_request_t *get_chat_menu_button_request_local_var = NULL;

    // get_chat_menu_button_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(get_chat_menu_button_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (chat_id) { 
    if(!cJSON_IsNumber(chat_id))
    {
    goto end; //Numeric
    }
    }


    get_chat_menu_button_request_local_var = get_chat_menu_button_request_create_internal (
        chat_id ? chat_id->valuedouble : 0
        );

    return get_chat_menu_button_request_local_var;
end:
    return NULL;

}
