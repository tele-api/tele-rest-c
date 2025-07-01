#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "reaction_type_paid.h"



static reaction_type_paid_t *reaction_type_paid_create_internal(
    char *type
    ) {
    reaction_type_paid_t *reaction_type_paid_local_var = malloc(sizeof(reaction_type_paid_t));
    if (!reaction_type_paid_local_var) {
        return NULL;
    }
    reaction_type_paid_local_var->type = type;

    reaction_type_paid_local_var->_library_owned = 1;
    return reaction_type_paid_local_var;
}

__attribute__((deprecated)) reaction_type_paid_t *reaction_type_paid_create(
    char *type
    ) {
    return reaction_type_paid_create_internal (
        type
        );
}

void reaction_type_paid_free(reaction_type_paid_t *reaction_type_paid) {
    if(NULL == reaction_type_paid){
        return ;
    }
    if(reaction_type_paid->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "reaction_type_paid_free");
        return ;
    }
    listEntry_t *listEntry;
    if (reaction_type_paid->type) {
        free(reaction_type_paid->type);
        reaction_type_paid->type = NULL;
    }
    free(reaction_type_paid);
}

cJSON *reaction_type_paid_convertToJSON(reaction_type_paid_t *reaction_type_paid) {
    cJSON *item = cJSON_CreateObject();

    // reaction_type_paid->type
    if (!reaction_type_paid->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", reaction_type_paid->type) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

reaction_type_paid_t *reaction_type_paid_parseFromJSON(cJSON *reaction_type_paidJSON){

    reaction_type_paid_t *reaction_type_paid_local_var = NULL;

    // reaction_type_paid->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(reaction_type_paidJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }


    reaction_type_paid_local_var = reaction_type_paid_create_internal (
        strdup(type->valuestring)
        );

    return reaction_type_paid_local_var;
end:
    return NULL;

}
