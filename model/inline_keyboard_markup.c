#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "inline_keyboard_markup.h"



static inline_keyboard_markup_t *inline_keyboard_markup_create_internal(
    list_t *inline_keyboard
    ) {
    inline_keyboard_markup_t *inline_keyboard_markup_local_var = malloc(sizeof(inline_keyboard_markup_t));
    if (!inline_keyboard_markup_local_var) {
        return NULL;
    }
    inline_keyboard_markup_local_var->inline_keyboard = inline_keyboard;

    inline_keyboard_markup_local_var->_library_owned = 1;
    return inline_keyboard_markup_local_var;
}

__attribute__((deprecated)) inline_keyboard_markup_t *inline_keyboard_markup_create(
    list_t *inline_keyboard
    ) {
    return inline_keyboard_markup_create_internal (
        inline_keyboard
        );
}

void inline_keyboard_markup_free(inline_keyboard_markup_t *inline_keyboard_markup) {
    if(NULL == inline_keyboard_markup){
        return ;
    }
    if(inline_keyboard_markup->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "inline_keyboard_markup_free");
        return ;
    }
    listEntry_t *listEntry;
    if (inline_keyboard_markup->inline_keyboard) {
        list_ForEach(listEntry, inline_keyboard_markup->inline_keyboard) {
            free(listEntry->data);
        }
        list_freeList(inline_keyboard_markup->inline_keyboard);
        inline_keyboard_markup->inline_keyboard = NULL;
    }
    free(inline_keyboard_markup);
}

cJSON *inline_keyboard_markup_convertToJSON(inline_keyboard_markup_t *inline_keyboard_markup) {
    cJSON *item = cJSON_CreateObject();

    // inline_keyboard_markup->inline_keyboard
    if (!inline_keyboard_markup->inline_keyboard) {
        goto fail;
    }
    cJSON *inline_keyboard = cJSON_AddArrayToObject(item, "inline_keyboard");
    if(inline_keyboard == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *inline_keyboardListEntry;
    list_ForEach(inline_keyboardListEntry, inline_keyboard_markup->inline_keyboard) {
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

inline_keyboard_markup_t *inline_keyboard_markup_parseFromJSON(cJSON *inline_keyboard_markupJSON){

    inline_keyboard_markup_t *inline_keyboard_markup_local_var = NULL;

    // define the local list for inline_keyboard_markup->inline_keyboard
    list_t *inline_keyboardList = NULL;

    // inline_keyboard_markup->inline_keyboard
    cJSON *inline_keyboard = cJSON_GetObjectItemCaseSensitive(inline_keyboard_markupJSON, "inline_keyboard");
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


    inline_keyboard_markup_local_var = inline_keyboard_markup_create_internal (
        inline_keyboardList
        );

    return inline_keyboard_markup_local_var;
end:
    if (inline_keyboardList) {
        list_freeList(inline_keyboardList);
        inline_keyboardList = NULL;
    }
    return NULL;

}
