#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "unique_gift_backdrop.h"



static unique_gift_backdrop_t *unique_gift_backdrop_create_internal(
    char *name,
    unique_gift_backdrop_colors_t *colors,
    int rarity_per_mille
    ) {
    unique_gift_backdrop_t *unique_gift_backdrop_local_var = malloc(sizeof(unique_gift_backdrop_t));
    if (!unique_gift_backdrop_local_var) {
        return NULL;
    }
    unique_gift_backdrop_local_var->name = name;
    unique_gift_backdrop_local_var->colors = colors;
    unique_gift_backdrop_local_var->rarity_per_mille = rarity_per_mille;

    unique_gift_backdrop_local_var->_library_owned = 1;
    return unique_gift_backdrop_local_var;
}

__attribute__((deprecated)) unique_gift_backdrop_t *unique_gift_backdrop_create(
    char *name,
    unique_gift_backdrop_colors_t *colors,
    int rarity_per_mille
    ) {
    return unique_gift_backdrop_create_internal (
        name,
        colors,
        rarity_per_mille
        );
}

void unique_gift_backdrop_free(unique_gift_backdrop_t *unique_gift_backdrop) {
    if(NULL == unique_gift_backdrop){
        return ;
    }
    if(unique_gift_backdrop->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "unique_gift_backdrop_free");
        return ;
    }
    listEntry_t *listEntry;
    if (unique_gift_backdrop->name) {
        free(unique_gift_backdrop->name);
        unique_gift_backdrop->name = NULL;
    }
    if (unique_gift_backdrop->colors) {
        unique_gift_backdrop_colors_free(unique_gift_backdrop->colors);
        unique_gift_backdrop->colors = NULL;
    }
    free(unique_gift_backdrop);
}

cJSON *unique_gift_backdrop_convertToJSON(unique_gift_backdrop_t *unique_gift_backdrop) {
    cJSON *item = cJSON_CreateObject();

    // unique_gift_backdrop->name
    if (!unique_gift_backdrop->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", unique_gift_backdrop->name) == NULL) {
    goto fail; //String
    }


    // unique_gift_backdrop->colors
    if (!unique_gift_backdrop->colors) {
        goto fail;
    }
    cJSON *colors_local_JSON = unique_gift_backdrop_colors_convertToJSON(unique_gift_backdrop->colors);
    if(colors_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "colors", colors_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // unique_gift_backdrop->rarity_per_mille
    if (!unique_gift_backdrop->rarity_per_mille) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "rarity_per_mille", unique_gift_backdrop->rarity_per_mille) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

unique_gift_backdrop_t *unique_gift_backdrop_parseFromJSON(cJSON *unique_gift_backdropJSON){

    unique_gift_backdrop_t *unique_gift_backdrop_local_var = NULL;

    // define the local variable for unique_gift_backdrop->colors
    unique_gift_backdrop_colors_t *colors_local_nonprim = NULL;

    // unique_gift_backdrop->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(unique_gift_backdropJSON, "name");
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

    // unique_gift_backdrop->colors
    cJSON *colors = cJSON_GetObjectItemCaseSensitive(unique_gift_backdropJSON, "colors");
    if (cJSON_IsNull(colors)) {
        colors = NULL;
    }
    if (!colors) {
        goto end;
    }

    
    colors_local_nonprim = unique_gift_backdrop_colors_parseFromJSON(colors); //nonprimitive

    // unique_gift_backdrop->rarity_per_mille
    cJSON *rarity_per_mille = cJSON_GetObjectItemCaseSensitive(unique_gift_backdropJSON, "rarity_per_mille");
    if (cJSON_IsNull(rarity_per_mille)) {
        rarity_per_mille = NULL;
    }
    if (!rarity_per_mille) {
        goto end;
    }

    
    if(!cJSON_IsNumber(rarity_per_mille))
    {
    goto end; //Numeric
    }


    unique_gift_backdrop_local_var = unique_gift_backdrop_create_internal (
        strdup(name->valuestring),
        colors_local_nonprim,
        rarity_per_mille->valuedouble
        );

    return unique_gift_backdrop_local_var;
end:
    if (colors_local_nonprim) {
        unique_gift_backdrop_colors_free(colors_local_nonprim);
        colors_local_nonprim = NULL;
    }
    return NULL;

}
