#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "reply_keyboard_markup.h"



static reply_keyboard_markup_t *reply_keyboard_markup_create_internal(
    list_t *keyboard,
    int is_persistent,
    int resize_keyboard,
    int one_time_keyboard,
    char *input_field_placeholder,
    int selective
    ) {
    reply_keyboard_markup_t *reply_keyboard_markup_local_var = malloc(sizeof(reply_keyboard_markup_t));
    if (!reply_keyboard_markup_local_var) {
        return NULL;
    }
    reply_keyboard_markup_local_var->keyboard = keyboard;
    reply_keyboard_markup_local_var->is_persistent = is_persistent;
    reply_keyboard_markup_local_var->resize_keyboard = resize_keyboard;
    reply_keyboard_markup_local_var->one_time_keyboard = one_time_keyboard;
    reply_keyboard_markup_local_var->input_field_placeholder = input_field_placeholder;
    reply_keyboard_markup_local_var->selective = selective;

    reply_keyboard_markup_local_var->_library_owned = 1;
    return reply_keyboard_markup_local_var;
}

__attribute__((deprecated)) reply_keyboard_markup_t *reply_keyboard_markup_create(
    list_t *keyboard,
    int is_persistent,
    int resize_keyboard,
    int one_time_keyboard,
    char *input_field_placeholder,
    int selective
    ) {
    return reply_keyboard_markup_create_internal (
        keyboard,
        is_persistent,
        resize_keyboard,
        one_time_keyboard,
        input_field_placeholder,
        selective
        );
}

void reply_keyboard_markup_free(reply_keyboard_markup_t *reply_keyboard_markup) {
    if(NULL == reply_keyboard_markup){
        return ;
    }
    if(reply_keyboard_markup->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "reply_keyboard_markup_free");
        return ;
    }
    listEntry_t *listEntry;
    if (reply_keyboard_markup->keyboard) {
        list_ForEach(listEntry, reply_keyboard_markup->keyboard) {
            free(listEntry->data);
        }
        list_freeList(reply_keyboard_markup->keyboard);
        reply_keyboard_markup->keyboard = NULL;
    }
    if (reply_keyboard_markup->input_field_placeholder) {
        free(reply_keyboard_markup->input_field_placeholder);
        reply_keyboard_markup->input_field_placeholder = NULL;
    }
    free(reply_keyboard_markup);
}

cJSON *reply_keyboard_markup_convertToJSON(reply_keyboard_markup_t *reply_keyboard_markup) {
    cJSON *item = cJSON_CreateObject();

    // reply_keyboard_markup->keyboard
    if (!reply_keyboard_markup->keyboard) {
        goto fail;
    }
    cJSON *keyboard = cJSON_AddArrayToObject(item, "keyboard");
    if(keyboard == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *keyboardListEntry;
    list_ForEach(keyboardListEntry, reply_keyboard_markup->keyboard) {
    }


    // reply_keyboard_markup->is_persistent
    if(reply_keyboard_markup->is_persistent) {
    if(cJSON_AddBoolToObject(item, "is_persistent", reply_keyboard_markup->is_persistent) == NULL) {
    goto fail; //Bool
    }
    }


    // reply_keyboard_markup->resize_keyboard
    if(reply_keyboard_markup->resize_keyboard) {
    if(cJSON_AddBoolToObject(item, "resize_keyboard", reply_keyboard_markup->resize_keyboard) == NULL) {
    goto fail; //Bool
    }
    }


    // reply_keyboard_markup->one_time_keyboard
    if(reply_keyboard_markup->one_time_keyboard) {
    if(cJSON_AddBoolToObject(item, "one_time_keyboard", reply_keyboard_markup->one_time_keyboard) == NULL) {
    goto fail; //Bool
    }
    }


    // reply_keyboard_markup->input_field_placeholder
    if(reply_keyboard_markup->input_field_placeholder) {
    if(cJSON_AddStringToObject(item, "input_field_placeholder", reply_keyboard_markup->input_field_placeholder) == NULL) {
    goto fail; //String
    }
    }


    // reply_keyboard_markup->selective
    if(reply_keyboard_markup->selective) {
    if(cJSON_AddBoolToObject(item, "selective", reply_keyboard_markup->selective) == NULL) {
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

reply_keyboard_markup_t *reply_keyboard_markup_parseFromJSON(cJSON *reply_keyboard_markupJSON){

    reply_keyboard_markup_t *reply_keyboard_markup_local_var = NULL;

    // define the local list for reply_keyboard_markup->keyboard
    list_t *keyboardList = NULL;

    // reply_keyboard_markup->keyboard
    cJSON *keyboard = cJSON_GetObjectItemCaseSensitive(reply_keyboard_markupJSON, "keyboard");
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

    // reply_keyboard_markup->is_persistent
    cJSON *is_persistent = cJSON_GetObjectItemCaseSensitive(reply_keyboard_markupJSON, "is_persistent");
    if (cJSON_IsNull(is_persistent)) {
        is_persistent = NULL;
    }
    if (is_persistent) { 
    if(!cJSON_IsBool(is_persistent))
    {
    goto end; //Bool
    }
    }

    // reply_keyboard_markup->resize_keyboard
    cJSON *resize_keyboard = cJSON_GetObjectItemCaseSensitive(reply_keyboard_markupJSON, "resize_keyboard");
    if (cJSON_IsNull(resize_keyboard)) {
        resize_keyboard = NULL;
    }
    if (resize_keyboard) { 
    if(!cJSON_IsBool(resize_keyboard))
    {
    goto end; //Bool
    }
    }

    // reply_keyboard_markup->one_time_keyboard
    cJSON *one_time_keyboard = cJSON_GetObjectItemCaseSensitive(reply_keyboard_markupJSON, "one_time_keyboard");
    if (cJSON_IsNull(one_time_keyboard)) {
        one_time_keyboard = NULL;
    }
    if (one_time_keyboard) { 
    if(!cJSON_IsBool(one_time_keyboard))
    {
    goto end; //Bool
    }
    }

    // reply_keyboard_markup->input_field_placeholder
    cJSON *input_field_placeholder = cJSON_GetObjectItemCaseSensitive(reply_keyboard_markupJSON, "input_field_placeholder");
    if (cJSON_IsNull(input_field_placeholder)) {
        input_field_placeholder = NULL;
    }
    if (input_field_placeholder) { 
    if(!cJSON_IsString(input_field_placeholder) && !cJSON_IsNull(input_field_placeholder))
    {
    goto end; //String
    }
    }

    // reply_keyboard_markup->selective
    cJSON *selective = cJSON_GetObjectItemCaseSensitive(reply_keyboard_markupJSON, "selective");
    if (cJSON_IsNull(selective)) {
        selective = NULL;
    }
    if (selective) { 
    if(!cJSON_IsBool(selective))
    {
    goto end; //Bool
    }
    }


    reply_keyboard_markup_local_var = reply_keyboard_markup_create_internal (
        keyboardList,
        is_persistent ? is_persistent->valueint : 0,
        resize_keyboard ? resize_keyboard->valueint : 0,
        one_time_keyboard ? one_time_keyboard->valueint : 0,
        input_field_placeholder && !cJSON_IsNull(input_field_placeholder) ? strdup(input_field_placeholder->valuestring) : NULL,
        selective ? selective->valueint : 0
        );

    return reply_keyboard_markup_local_var;
end:
    if (keyboardList) {
        list_freeList(keyboardList);
        keyboardList = NULL;
    }
    return NULL;

}
