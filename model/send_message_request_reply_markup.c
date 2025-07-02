#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "send_message_request_reply_markup.h"



static send_message_request_reply_markup_t *send_message_request_reply_markup_create_internal(
    list_t *inline_keyboard,
    list_t *keyboard,
    int remove_keyboard,
    int force_reply,
    int is_persistent,
    int resize_keyboard,
    int one_time_keyboard,
    char *input_field_placeholder,
    int selective
    ) {
    send_message_request_reply_markup_t *send_message_request_reply_markup_local_var = malloc(sizeof(send_message_request_reply_markup_t));
    if (!send_message_request_reply_markup_local_var) {
        return NULL;
    }
    send_message_request_reply_markup_local_var->inline_keyboard = inline_keyboard;
    send_message_request_reply_markup_local_var->keyboard = keyboard;
    send_message_request_reply_markup_local_var->remove_keyboard = remove_keyboard;
    send_message_request_reply_markup_local_var->force_reply = force_reply;
    send_message_request_reply_markup_local_var->is_persistent = is_persistent;
    send_message_request_reply_markup_local_var->resize_keyboard = resize_keyboard;
    send_message_request_reply_markup_local_var->one_time_keyboard = one_time_keyboard;
    send_message_request_reply_markup_local_var->input_field_placeholder = input_field_placeholder;
    send_message_request_reply_markup_local_var->selective = selective;

    send_message_request_reply_markup_local_var->_library_owned = 1;
    return send_message_request_reply_markup_local_var;
}

__attribute__((deprecated)) send_message_request_reply_markup_t *send_message_request_reply_markup_create(
    list_t *inline_keyboard,
    list_t *keyboard,
    int remove_keyboard,
    int force_reply,
    int is_persistent,
    int resize_keyboard,
    int one_time_keyboard,
    char *input_field_placeholder,
    int selective
    ) {
    return send_message_request_reply_markup_create_internal (
        inline_keyboard,
        keyboard,
        remove_keyboard,
        force_reply,
        is_persistent,
        resize_keyboard,
        one_time_keyboard,
        input_field_placeholder,
        selective
        );
}

void send_message_request_reply_markup_free(send_message_request_reply_markup_t *send_message_request_reply_markup) {
    if(NULL == send_message_request_reply_markup){
        return ;
    }
    if(send_message_request_reply_markup->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "send_message_request_reply_markup_free");
        return ;
    }
    listEntry_t *listEntry;
    if (send_message_request_reply_markup->inline_keyboard) {
        list_ForEach(listEntry, send_message_request_reply_markup->inline_keyboard) {
            free(listEntry->data);
        }
        list_freeList(send_message_request_reply_markup->inline_keyboard);
        send_message_request_reply_markup->inline_keyboard = NULL;
    }
    if (send_message_request_reply_markup->keyboard) {
        list_ForEach(listEntry, send_message_request_reply_markup->keyboard) {
            free(listEntry->data);
        }
        list_freeList(send_message_request_reply_markup->keyboard);
        send_message_request_reply_markup->keyboard = NULL;
    }
    if (send_message_request_reply_markup->input_field_placeholder) {
        free(send_message_request_reply_markup->input_field_placeholder);
        send_message_request_reply_markup->input_field_placeholder = NULL;
    }
    free(send_message_request_reply_markup);
}

cJSON *send_message_request_reply_markup_convertToJSON(send_message_request_reply_markup_t *send_message_request_reply_markup) {
    cJSON *item = cJSON_CreateObject();

    // send_message_request_reply_markup->inline_keyboard
    if (!send_message_request_reply_markup->inline_keyboard) {
        goto fail;
    }
    cJSON *inline_keyboard = cJSON_AddArrayToObject(item, "inline_keyboard");
    if(inline_keyboard == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *inline_keyboardListEntry;
    list_ForEach(inline_keyboardListEntry, send_message_request_reply_markup->inline_keyboard) {
    }


    // send_message_request_reply_markup->keyboard
    if (!send_message_request_reply_markup->keyboard) {
        goto fail;
    }
    cJSON *keyboard = cJSON_AddArrayToObject(item, "keyboard");
    if(keyboard == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *keyboardListEntry;
    list_ForEach(keyboardListEntry, send_message_request_reply_markup->keyboard) {
    }


    // send_message_request_reply_markup->remove_keyboard
    if (!send_message_request_reply_markup->remove_keyboard) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "remove_keyboard", send_message_request_reply_markup->remove_keyboard) == NULL) {
    goto fail; //Bool
    }


    // send_message_request_reply_markup->force_reply
    if (!send_message_request_reply_markup->force_reply) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "force_reply", send_message_request_reply_markup->force_reply) == NULL) {
    goto fail; //Bool
    }


    // send_message_request_reply_markup->is_persistent
    if(send_message_request_reply_markup->is_persistent) {
    if(cJSON_AddBoolToObject(item, "is_persistent", send_message_request_reply_markup->is_persistent) == NULL) {
    goto fail; //Bool
    }
    }


    // send_message_request_reply_markup->resize_keyboard
    if(send_message_request_reply_markup->resize_keyboard) {
    if(cJSON_AddBoolToObject(item, "resize_keyboard", send_message_request_reply_markup->resize_keyboard) == NULL) {
    goto fail; //Bool
    }
    }


    // send_message_request_reply_markup->one_time_keyboard
    if(send_message_request_reply_markup->one_time_keyboard) {
    if(cJSON_AddBoolToObject(item, "one_time_keyboard", send_message_request_reply_markup->one_time_keyboard) == NULL) {
    goto fail; //Bool
    }
    }


    // send_message_request_reply_markup->input_field_placeholder
    if(send_message_request_reply_markup->input_field_placeholder) {
    if(cJSON_AddStringToObject(item, "input_field_placeholder", send_message_request_reply_markup->input_field_placeholder) == NULL) {
    goto fail; //String
    }
    }


    // send_message_request_reply_markup->selective
    if(send_message_request_reply_markup->selective) {
    if(cJSON_AddBoolToObject(item, "selective", send_message_request_reply_markup->selective) == NULL) {
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

send_message_request_reply_markup_t *send_message_request_reply_markup_parseFromJSON(cJSON *send_message_request_reply_markupJSON){

    send_message_request_reply_markup_t *send_message_request_reply_markup_local_var = NULL;

    // define the local list for send_message_request_reply_markup->inline_keyboard
    list_t *inline_keyboardList = NULL;

    // define the local list for send_message_request_reply_markup->keyboard
    list_t *keyboardList = NULL;

    // send_message_request_reply_markup->inline_keyboard
    cJSON *inline_keyboard = cJSON_GetObjectItemCaseSensitive(send_message_request_reply_markupJSON, "inline_keyboard");
    if (cJSON_IsNull(inline_keyboard)) {
        inline_keyboard = NULL;
    }
    if (!inline_keyboard) {
        goto end;
    }

    
    cJSON *inline_keyboard_local = NULL;
    if(!cJSON_IsArray(inline_keyboard)) {
        goto end;//primitive container
    }
    inline_keyboardList = list_createList();

    cJSON_ArrayForEach(inline_keyboard_local, inline_keyboard)
    {
    }

    // send_message_request_reply_markup->keyboard
    cJSON *keyboard = cJSON_GetObjectItemCaseSensitive(send_message_request_reply_markupJSON, "keyboard");
    if (cJSON_IsNull(keyboard)) {
        keyboard = NULL;
    }
    if (!keyboard) {
        goto end;
    }

    
    cJSON *keyboard_local = NULL;
    if(!cJSON_IsArray(keyboard)) {
        goto end;//primitive container
    }
    keyboardList = list_createList();

    cJSON_ArrayForEach(keyboard_local, keyboard)
    {
    }

    // send_message_request_reply_markup->remove_keyboard
    cJSON *remove_keyboard = cJSON_GetObjectItemCaseSensitive(send_message_request_reply_markupJSON, "remove_keyboard");
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

    // send_message_request_reply_markup->force_reply
    cJSON *force_reply = cJSON_GetObjectItemCaseSensitive(send_message_request_reply_markupJSON, "force_reply");
    if (cJSON_IsNull(force_reply)) {
        force_reply = NULL;
    }
    if (!force_reply) {
        goto end;
    }

    
    if(!cJSON_IsBool(force_reply))
    {
    goto end; //Bool
    }

    // send_message_request_reply_markup->is_persistent
    cJSON *is_persistent = cJSON_GetObjectItemCaseSensitive(send_message_request_reply_markupJSON, "is_persistent");
    if (cJSON_IsNull(is_persistent)) {
        is_persistent = NULL;
    }
    if (is_persistent) { 
    if(!cJSON_IsBool(is_persistent))
    {
    goto end; //Bool
    }
    }

    // send_message_request_reply_markup->resize_keyboard
    cJSON *resize_keyboard = cJSON_GetObjectItemCaseSensitive(send_message_request_reply_markupJSON, "resize_keyboard");
    if (cJSON_IsNull(resize_keyboard)) {
        resize_keyboard = NULL;
    }
    if (resize_keyboard) { 
    if(!cJSON_IsBool(resize_keyboard))
    {
    goto end; //Bool
    }
    }

    // send_message_request_reply_markup->one_time_keyboard
    cJSON *one_time_keyboard = cJSON_GetObjectItemCaseSensitive(send_message_request_reply_markupJSON, "one_time_keyboard");
    if (cJSON_IsNull(one_time_keyboard)) {
        one_time_keyboard = NULL;
    }
    if (one_time_keyboard) { 
    if(!cJSON_IsBool(one_time_keyboard))
    {
    goto end; //Bool
    }
    }

    // send_message_request_reply_markup->input_field_placeholder
    cJSON *input_field_placeholder = cJSON_GetObjectItemCaseSensitive(send_message_request_reply_markupJSON, "input_field_placeholder");
    if (cJSON_IsNull(input_field_placeholder)) {
        input_field_placeholder = NULL;
    }
    if (input_field_placeholder) { 
    if(!cJSON_IsString(input_field_placeholder) && !cJSON_IsNull(input_field_placeholder))
    {
    goto end; //String
    }
    }

    // send_message_request_reply_markup->selective
    cJSON *selective = cJSON_GetObjectItemCaseSensitive(send_message_request_reply_markupJSON, "selective");
    if (cJSON_IsNull(selective)) {
        selective = NULL;
    }
    if (selective) { 
    if(!cJSON_IsBool(selective))
    {
    goto end; //Bool
    }
    }


    send_message_request_reply_markup_local_var = send_message_request_reply_markup_create_internal (
        inline_keyboardList,
        keyboardList,
        remove_keyboard->valueint,
        force_reply->valueint,
        is_persistent ? is_persistent->valueint : 0,
        resize_keyboard ? resize_keyboard->valueint : 0,
        one_time_keyboard ? one_time_keyboard->valueint : 0,
        input_field_placeholder && !cJSON_IsNull(input_field_placeholder) ? strdup(input_field_placeholder->valuestring) : NULL,
        selective ? selective->valueint : 0
        );

    return send_message_request_reply_markup_local_var;
end:
    if (inline_keyboardList) {
        list_freeList(inline_keyboardList);
        inline_keyboardList = NULL;
    }
    if (keyboardList) {
        list_freeList(keyboardList);
        keyboardList = NULL;
    }
    return NULL;

}
