#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "reaction_count.h"



static reaction_count_t *reaction_count_create_internal(
    reaction_type_t *type,
    int total_count
    ) {
    reaction_count_t *reaction_count_local_var = malloc(sizeof(reaction_count_t));
    if (!reaction_count_local_var) {
        return NULL;
    }
    reaction_count_local_var->type = type;
    reaction_count_local_var->total_count = total_count;

    reaction_count_local_var->_library_owned = 1;
    return reaction_count_local_var;
}

__attribute__((deprecated)) reaction_count_t *reaction_count_create(
    reaction_type_t *type,
    int total_count
    ) {
    return reaction_count_create_internal (
        type,
        total_count
        );
}

void reaction_count_free(reaction_count_t *reaction_count) {
    if(NULL == reaction_count){
        return ;
    }
    if(reaction_count->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "reaction_count_free");
        return ;
    }
    listEntry_t *listEntry;
    if (reaction_count->type) {
        reaction_type_free(reaction_count->type);
        reaction_count->type = NULL;
    }
    free(reaction_count);
}

cJSON *reaction_count_convertToJSON(reaction_count_t *reaction_count) {
    cJSON *item = cJSON_CreateObject();

    // reaction_count->type
    if (!reaction_count->type) {
        goto fail;
    }
    cJSON *type_local_JSON = reaction_type_convertToJSON(reaction_count->type);
    if(type_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "type", type_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // reaction_count->total_count
    if (!reaction_count->total_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "total_count", reaction_count->total_count) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

reaction_count_t *reaction_count_parseFromJSON(cJSON *reaction_countJSON){

    reaction_count_t *reaction_count_local_var = NULL;

    // define the local variable for reaction_count->type
    reaction_type_t *type_local_nonprim = NULL;

    // reaction_count->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(reaction_countJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    
    type_local_nonprim = reaction_type_parseFromJSON(type); //nonprimitive

    // reaction_count->total_count
    cJSON *total_count = cJSON_GetObjectItemCaseSensitive(reaction_countJSON, "total_count");
    if (cJSON_IsNull(total_count)) {
        total_count = NULL;
    }
    if (!total_count) {
        goto end;
    }

    
    if(!cJSON_IsNumber(total_count))
    {
    goto end; //Numeric
    }


    reaction_count_local_var = reaction_count_create_internal (
        type_local_nonprim,
        total_count->valuedouble
        );

    return reaction_count_local_var;
end:
    if (type_local_nonprim) {
        reaction_type_free(type_local_nonprim);
        type_local_nonprim = NULL;
    }
    return NULL;

}
