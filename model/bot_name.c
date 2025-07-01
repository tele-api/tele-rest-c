#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "bot_name.h"



static bot_name_t *bot_name_create_internal(
    char *name
    ) {
    bot_name_t *bot_name_local_var = malloc(sizeof(bot_name_t));
    if (!bot_name_local_var) {
        return NULL;
    }
    bot_name_local_var->name = name;

    bot_name_local_var->_library_owned = 1;
    return bot_name_local_var;
}

__attribute__((deprecated)) bot_name_t *bot_name_create(
    char *name
    ) {
    return bot_name_create_internal (
        name
        );
}

void bot_name_free(bot_name_t *bot_name) {
    if(NULL == bot_name){
        return ;
    }
    if(bot_name->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "bot_name_free");
        return ;
    }
    listEntry_t *listEntry;
    if (bot_name->name) {
        free(bot_name->name);
        bot_name->name = NULL;
    }
    free(bot_name);
}

cJSON *bot_name_convertToJSON(bot_name_t *bot_name) {
    cJSON *item = cJSON_CreateObject();

    // bot_name->name
    if (!bot_name->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", bot_name->name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

bot_name_t *bot_name_parseFromJSON(cJSON *bot_nameJSON){

    bot_name_t *bot_name_local_var = NULL;

    // bot_name->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(bot_nameJSON, "name");
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


    bot_name_local_var = bot_name_create_internal (
        strdup(name->valuestring)
        );

    return bot_name_local_var;
end:
    return NULL;

}
