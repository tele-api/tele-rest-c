#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "bot_description.h"



static bot_description_t *bot_description_create_internal(
    char *description
    ) {
    bot_description_t *bot_description_local_var = malloc(sizeof(bot_description_t));
    if (!bot_description_local_var) {
        return NULL;
    }
    bot_description_local_var->description = description;

    bot_description_local_var->_library_owned = 1;
    return bot_description_local_var;
}

__attribute__((deprecated)) bot_description_t *bot_description_create(
    char *description
    ) {
    return bot_description_create_internal (
        description
        );
}

void bot_description_free(bot_description_t *bot_description) {
    if(NULL == bot_description){
        return ;
    }
    if(bot_description->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "bot_description_free");
        return ;
    }
    listEntry_t *listEntry;
    if (bot_description->description) {
        free(bot_description->description);
        bot_description->description = NULL;
    }
    free(bot_description);
}

cJSON *bot_description_convertToJSON(bot_description_t *bot_description) {
    cJSON *item = cJSON_CreateObject();

    // bot_description->description
    if (!bot_description->description) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "description", bot_description->description) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

bot_description_t *bot_description_parseFromJSON(cJSON *bot_descriptionJSON){

    bot_description_t *bot_description_local_var = NULL;

    // bot_description->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(bot_descriptionJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (!description) {
        goto end;
    }

    
    if(!cJSON_IsString(description))
    {
    goto end; //String
    }


    bot_description_local_var = bot_description_create_internal (
        strdup(description->valuestring)
        );

    return bot_description_local_var;
end:
    return NULL;

}
