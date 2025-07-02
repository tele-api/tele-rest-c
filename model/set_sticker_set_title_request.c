#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "set_sticker_set_title_request.h"



static set_sticker_set_title_request_t *set_sticker_set_title_request_create_internal(
    char *name,
    char *title
    ) {
    set_sticker_set_title_request_t *set_sticker_set_title_request_local_var = malloc(sizeof(set_sticker_set_title_request_t));
    if (!set_sticker_set_title_request_local_var) {
        return NULL;
    }
    set_sticker_set_title_request_local_var->name = name;
    set_sticker_set_title_request_local_var->title = title;

    set_sticker_set_title_request_local_var->_library_owned = 1;
    return set_sticker_set_title_request_local_var;
}

__attribute__((deprecated)) set_sticker_set_title_request_t *set_sticker_set_title_request_create(
    char *name,
    char *title
    ) {
    return set_sticker_set_title_request_create_internal (
        name,
        title
        );
}

void set_sticker_set_title_request_free(set_sticker_set_title_request_t *set_sticker_set_title_request) {
    if(NULL == set_sticker_set_title_request){
        return ;
    }
    if(set_sticker_set_title_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "set_sticker_set_title_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (set_sticker_set_title_request->name) {
        free(set_sticker_set_title_request->name);
        set_sticker_set_title_request->name = NULL;
    }
    if (set_sticker_set_title_request->title) {
        free(set_sticker_set_title_request->title);
        set_sticker_set_title_request->title = NULL;
    }
    free(set_sticker_set_title_request);
}

cJSON *set_sticker_set_title_request_convertToJSON(set_sticker_set_title_request_t *set_sticker_set_title_request) {
    cJSON *item = cJSON_CreateObject();

    // set_sticker_set_title_request->name
    if (!set_sticker_set_title_request->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", set_sticker_set_title_request->name) == NULL) {
    goto fail; //String
    }


    // set_sticker_set_title_request->title
    if (!set_sticker_set_title_request->title) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "title", set_sticker_set_title_request->title) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

set_sticker_set_title_request_t *set_sticker_set_title_request_parseFromJSON(cJSON *set_sticker_set_title_requestJSON){

    set_sticker_set_title_request_t *set_sticker_set_title_request_local_var = NULL;

    // set_sticker_set_title_request->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(set_sticker_set_title_requestJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // set_sticker_set_title_request->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(set_sticker_set_title_requestJSON, "title");
    if (cJSON_IsNull(title)) {
        title = NULL;
    }
    if (!title) {
        goto end;
    }

    
    if(!cJSON_IsString(title))
    {
    goto end; //String
    }


    set_sticker_set_title_request_local_var = set_sticker_set_title_request_create_internal (
        strdup(name->valuestring),
        strdup(title->valuestring)
        );

    return set_sticker_set_title_request_local_var;
end:
    return NULL;

}
