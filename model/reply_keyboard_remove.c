#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "reply_keyboard_remove.h"



static reply_keyboard_remove_t *reply_keyboard_remove_create_internal(
    int remove_keyboard,
    int selective
    ) {
    reply_keyboard_remove_t *reply_keyboard_remove_local_var = malloc(sizeof(reply_keyboard_remove_t));
    if (!reply_keyboard_remove_local_var) {
        return NULL;
    }
    reply_keyboard_remove_local_var->remove_keyboard = remove_keyboard;
    reply_keyboard_remove_local_var->selective = selective;

    reply_keyboard_remove_local_var->_library_owned = 1;
    return reply_keyboard_remove_local_var;
}

__attribute__((deprecated)) reply_keyboard_remove_t *reply_keyboard_remove_create(
    int remove_keyboard,
    int selective
    ) {
    return reply_keyboard_remove_create_internal (
        remove_keyboard,
        selective
        );
}

void reply_keyboard_remove_free(reply_keyboard_remove_t *reply_keyboard_remove) {
    if(NULL == reply_keyboard_remove){
        return ;
    }
    if(reply_keyboard_remove->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "reply_keyboard_remove_free");
        return ;
    }
    listEntry_t *listEntry;
    free(reply_keyboard_remove);
}

cJSON *reply_keyboard_remove_convertToJSON(reply_keyboard_remove_t *reply_keyboard_remove) {
    cJSON *item = cJSON_CreateObject();

    // reply_keyboard_remove->remove_keyboard
    if (!reply_keyboard_remove->remove_keyboard) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "remove_keyboard", reply_keyboard_remove->remove_keyboard) == NULL) {
    goto fail; //Bool
    }


    // reply_keyboard_remove->selective
    if(reply_keyboard_remove->selective) {
    if(cJSON_AddBoolToObject(item, "selective", reply_keyboard_remove->selective) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

reply_keyboard_remove_t *reply_keyboard_remove_parseFromJSON(cJSON *reply_keyboard_removeJSON){

    reply_keyboard_remove_t *reply_keyboard_remove_local_var = NULL;

    // reply_keyboard_remove->remove_keyboard
    cJSON *remove_keyboard = cJSON_GetObjectItemCaseSensitive(reply_keyboard_removeJSON, "remove_keyboard");
    if (cJSON_IsNull(remove_keyboard)) {
        remove_keyboard = NULL;
    }
    if (!remove_keyboard) {
        goto end;
    }

    
    if(!cJSON_IsBool(remove_keyboard))
    {
    goto end; //Bool
    }

    // reply_keyboard_remove->selective
    cJSON *selective = cJSON_GetObjectItemCaseSensitive(reply_keyboard_removeJSON, "selective");
    if (cJSON_IsNull(selective)) {
        selective = NULL;
    }
    if (selective) { 
    if(!cJSON_IsBool(selective))
    {
    goto end; //Bool
    }
    }


    reply_keyboard_remove_local_var = reply_keyboard_remove_create_internal (
        remove_keyboard->valueint,
        selective ? selective->valueint : 0
        );

    return reply_keyboard_remove_local_var;
end:
    return NULL;

}
