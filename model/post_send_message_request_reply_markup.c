#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_send_message_request_reply_markup.h"



static post_send_message_request_reply_markup_t *post_send_message_request_reply_markup_create_internal(
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
    post_send_message_request_reply_markup_t *post_send_message_request_reply_markup_local_var = malloc(sizeof(post_send_message_request_reply_markup_t));
    if (!post_send_message_request_reply_markup_local_var) {
        return NULL;
    }
    post_send_message_request_reply_markup_local_var->inline_keyboard = inline_keyboard;
    post_send_message_request_reply_markup_local_var->keyboard = keyboard;
    post_send_message_request_reply_markup_local_var->remove_keyboard = remove_keyboard;
    post_send_message_request_reply_markup_local_var->force_reply = force_reply;
    post_send_message_request_reply_markup_local_var->is_persistent = is_persistent;
    post_send_message_request_reply_markup_local_var->resize_keyboard = resize_keyboard;
    post_send_message_request_reply_markup_local_var->one_time_keyboard = one_time_keyboard;
    post_send_message_request_reply_markup_local_var->input_field_placeholder = input_field_placeholder;
    post_send_message_request_reply_markup_local_var->selective = selective;

    post_send_message_request_reply_markup_local_var->_library_owned = 1;
    return post_send_message_request_reply_markup_local_var;
}

__attribute__((deprecated)) post_send_message_request_reply_markup_t *post_send_message_request_reply_markup_create(
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
    return post_send_message_request_reply_markup_create_internal (
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

void post_send_message_request_reply_markup_free(post_send_message_request_reply_markup_t *post_send_message_request_reply_markup) {
    if(NULL == post_send_message_request_reply_markup){
        return ;
    }
    if(post_send_message_request_reply_markup->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_send_message_request_reply_markup_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_send_message_request_reply_markup->inline_keyboard) {
        list_ForEach(listEntry, post_send_message_request_reply_markup->inline_keyboard) {
            free(listEntry->data);
        }
        list_freeList(post_send_message_request_reply_markup->inline_keyboard);
        post_send_message_request_reply_markup->inline_keyboard = NULL;
    }
    if (post_send_message_request_reply_markup->keyboard) {
        list_ForEach(listEntry, post_send_message_request_reply_markup->keyboard) {
            free(listEntry->data);
        }
        list_freeList(post_send_message_request_reply_markup->keyboard);
        post_send_message_request_reply_markup->keyboard = NULL;
    }
    if (post_send_message_request_reply_markup->input_field_placeholder) {
        free(post_send_message_request_reply_markup->input_field_placeholder);
        post_send_message_request_reply_markup->input_field_placeholder = NULL;
    }
    free(post_send_message_request_reply_markup);
}

cJSON *post_send_message_request_reply_markup_convertToJSON(post_send_message_request_reply_markup_t *post_send_message_request_reply_markup) {
    cJSON *item = cJSON_CreateObject();

    // post_send_message_request_reply_markup->inline_keyboard
    if (!post_send_message_request_reply_markup->inline_keyboard) {
        goto fail;
    }
    cJSON *inline_keyboard = cJSON_AddArrayToObject(item, "inline_keyboard");
    if(inline_keyboard == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *inline_keyboardListEntry;
    list_ForEach(inline_keyboardListEntry, post_send_message_request_reply_markup->inline_keyboard) {
    }


    // post_send_message_request_reply_markup->keyboard
    if (!post_send_message_request_reply_markup->keyboard) {
        goto fail;
    }
    cJSON *keyboard = cJSON_AddArrayToObject(item, "keyboard");
    if(keyboard == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *keyboardListEntry;
    list_ForEach(keyboardListEntry, post_send_message_request_reply_markup->keyboard) {
    }


    // post_send_message_request_reply_markup->remove_keyboard
    if (!post_send_message_request_reply_markup->remove_keyboard) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "remove_keyboard", post_send_message_request_reply_markup->remove_keyboard) == NULL) {
    goto fail; //Bool
    }


    // post_send_message_request_reply_markup->force_reply
    if (!post_send_message_request_reply_markup->force_reply) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "force_reply", post_send_message_request_reply_markup->force_reply) == NULL) {
    goto fail; //Bool
    }


    // post_send_message_request_reply_markup->is_persistent
    if(post_send_message_request_reply_markup->is_persistent) {
    if(cJSON_AddBoolToObject(item, "is_persistent", post_send_message_request_reply_markup->is_persistent) == NULL) {
    goto fail; //Bool
    }
    }


    // post_send_message_request_reply_markup->resize_keyboard
    if(post_send_message_request_reply_markup->resize_keyboard) {
    if(cJSON_AddBoolToObject(item, "resize_keyboard", post_send_message_request_reply_markup->resize_keyboard) == NULL) {
    goto fail; //Bool
    }
    }


    // post_send_message_request_reply_markup->one_time_keyboard
    if(post_send_message_request_reply_markup->one_time_keyboard) {
    if(cJSON_AddBoolToObject(item, "one_time_keyboard", post_send_message_request_reply_markup->one_time_keyboard) == NULL) {
    goto fail; //Bool
    }
    }


    // post_send_message_request_reply_markup->input_field_placeholder
    if(post_send_message_request_reply_markup->input_field_placeholder) {
    if(cJSON_AddStringToObject(item, "input_field_placeholder", post_send_message_request_reply_markup->input_field_placeholder) == NULL) {
    goto fail; //String
    }
    }


    // post_send_message_request_reply_markup->selective
    if(post_send_message_request_reply_markup->selective) {
    if(cJSON_AddBoolToObject(item, "selective", post_send_message_request_reply_markup->selective) == NULL) {
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

post_send_message_request_reply_markup_t *post_send_message_request_reply_markup_parseFromJSON(cJSON *post_send_message_request_reply_markupJSON){

    post_send_message_request_reply_markup_t *post_send_message_request_reply_markup_local_var = NULL;

    // define the local list for post_send_message_request_reply_markup->inline_keyboard
    list_t *inline_keyboardList = NULL;

    // define the local list for post_send_message_request_reply_markup->keyboard
    list_t *keyboardList = NULL;

    // post_send_message_request_reply_markup->inline_keyboard
    cJSON *inline_keyboard = cJSON_GetObjectItemCaseSensitive(post_send_message_request_reply_markupJSON, "inline_keyboard");
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

    // post_send_message_request_reply_markup->keyboard
    cJSON *keyboard = cJSON_GetObjectItemCaseSensitive(post_send_message_request_reply_markupJSON, "keyboard");
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

    // post_send_message_request_reply_markup->remove_keyboard
    cJSON *remove_keyboard = cJSON_GetObjectItemCaseSensitive(post_send_message_request_reply_markupJSON, "remove_keyboard");
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

    // post_send_message_request_reply_markup->force_reply
    cJSON *force_reply = cJSON_GetObjectItemCaseSensitive(post_send_message_request_reply_markupJSON, "force_reply");
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

    // post_send_message_request_reply_markup->is_persistent
    cJSON *is_persistent = cJSON_GetObjectItemCaseSensitive(post_send_message_request_reply_markupJSON, "is_persistent");
    if (cJSON_IsNull(is_persistent)) {
        is_persistent = NULL;
    }
    if (is_persistent) { 
    if(!cJSON_IsBool(is_persistent))
    {
    goto end; //Bool
    }
    }

    // post_send_message_request_reply_markup->resize_keyboard
    cJSON *resize_keyboard = cJSON_GetObjectItemCaseSensitive(post_send_message_request_reply_markupJSON, "resize_keyboard");
    if (cJSON_IsNull(resize_keyboard)) {
        resize_keyboard = NULL;
    }
    if (resize_keyboard) { 
    if(!cJSON_IsBool(resize_keyboard))
    {
    goto end; //Bool
    }
    }

    // post_send_message_request_reply_markup->one_time_keyboard
    cJSON *one_time_keyboard = cJSON_GetObjectItemCaseSensitive(post_send_message_request_reply_markupJSON, "one_time_keyboard");
    if (cJSON_IsNull(one_time_keyboard)) {
        one_time_keyboard = NULL;
    }
    if (one_time_keyboard) { 
    if(!cJSON_IsBool(one_time_keyboard))
    {
    goto end; //Bool
    }
    }

    // post_send_message_request_reply_markup->input_field_placeholder
    cJSON *input_field_placeholder = cJSON_GetObjectItemCaseSensitive(post_send_message_request_reply_markupJSON, "input_field_placeholder");
    if (cJSON_IsNull(input_field_placeholder)) {
        input_field_placeholder = NULL;
    }
    if (input_field_placeholder) { 
    if(!cJSON_IsString(input_field_placeholder) && !cJSON_IsNull(input_field_placeholder))
    {
    goto end; //String
    }
    }

    // post_send_message_request_reply_markup->selective
    cJSON *selective = cJSON_GetObjectItemCaseSensitive(post_send_message_request_reply_markupJSON, "selective");
    if (cJSON_IsNull(selective)) {
        selective = NULL;
    }
    if (selective) { 
    if(!cJSON_IsBool(selective))
    {
    goto end; //Bool
    }
    }


    post_send_message_request_reply_markup_local_var = post_send_message_request_reply_markup_create_internal (
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

    return post_send_message_request_reply_markup_local_var;
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
