#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "bot_short_description.h"



static bot_short_description_t *bot_short_description_create_internal(
    char *short_description
    ) {
    bot_short_description_t *bot_short_description_local_var = malloc(sizeof(bot_short_description_t));
    if (!bot_short_description_local_var) {
        return NULL;
    }
    bot_short_description_local_var->short_description = short_description;

    bot_short_description_local_var->_library_owned = 1;
    return bot_short_description_local_var;
}

__attribute__((deprecated)) bot_short_description_t *bot_short_description_create(
    char *short_description
    ) {
    return bot_short_description_create_internal (
        short_description
        );
}

void bot_short_description_free(bot_short_description_t *bot_short_description) {
    if(NULL == bot_short_description){
        return ;
    }
    if(bot_short_description->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "bot_short_description_free");
        return ;
    }
    listEntry_t *listEntry;
    if (bot_short_description->short_description) {
        free(bot_short_description->short_description);
        bot_short_description->short_description = NULL;
    }
    free(bot_short_description);
}

cJSON *bot_short_description_convertToJSON(bot_short_description_t *bot_short_description) {
    cJSON *item = cJSON_CreateObject();

    // bot_short_description->short_description
    if (!bot_short_description->short_description) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "short_description", bot_short_description->short_description) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

bot_short_description_t *bot_short_description_parseFromJSON(cJSON *bot_short_descriptionJSON){

    bot_short_description_t *bot_short_description_local_var = NULL;

    // bot_short_description->short_description
    cJSON *short_description = cJSON_GetObjectItemCaseSensitive(bot_short_descriptionJSON, "short_description");
    if (cJSON_IsNull(short_description)) {
        short_description = NULL;
    }
    if (!short_description) {
        goto end;
    }

    
    if(!cJSON_IsString(short_description))
    {
    goto end; //String
    }


    bot_short_description_local_var = bot_short_description_create_internal (
        strdup(short_description->valuestring)
        );

    return bot_short_description_local_var;
end:
    return NULL;

}
