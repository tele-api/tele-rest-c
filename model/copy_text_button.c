#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "copy_text_button.h"



static copy_text_button_t *copy_text_button_create_internal(
    char *text
    ) {
    copy_text_button_t *copy_text_button_local_var = malloc(sizeof(copy_text_button_t));
    if (!copy_text_button_local_var) {
        return NULL;
    }
    copy_text_button_local_var->text = text;

    copy_text_button_local_var->_library_owned = 1;
    return copy_text_button_local_var;
}

__attribute__((deprecated)) copy_text_button_t *copy_text_button_create(
    char *text
    ) {
    return copy_text_button_create_internal (
        text
        );
}

void copy_text_button_free(copy_text_button_t *copy_text_button) {
    if(NULL == copy_text_button){
        return ;
    }
    if(copy_text_button->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "copy_text_button_free");
        return ;
    }
    listEntry_t *listEntry;
    if (copy_text_button->text) {
        free(copy_text_button->text);
        copy_text_button->text = NULL;
    }
    free(copy_text_button);
}

cJSON *copy_text_button_convertToJSON(copy_text_button_t *copy_text_button) {
    cJSON *item = cJSON_CreateObject();

    // copy_text_button->text
    if (!copy_text_button->text) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "text", copy_text_button->text) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

copy_text_button_t *copy_text_button_parseFromJSON(cJSON *copy_text_buttonJSON){

    copy_text_button_t *copy_text_button_local_var = NULL;

    // copy_text_button->text
    cJSON *text = cJSON_GetObjectItemCaseSensitive(copy_text_buttonJSON, "text");
    if (cJSON_IsNull(text)) {
        text = NULL;
    }
    if (!text) {
        goto end;
    }

    
    if(!cJSON_IsString(text))
    {
    goto end; //String
    }


    copy_text_button_local_var = copy_text_button_create_internal (
        strdup(text->valuestring)
        );

    return copy_text_button_local_var;
end:
    return NULL;

}
