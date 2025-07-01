#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "unique_gift_backdrop_colors.h"



static unique_gift_backdrop_colors_t *unique_gift_backdrop_colors_create_internal(
    int center_color,
    int edge_color,
    int symbol_color,
    int text_color
    ) {
    unique_gift_backdrop_colors_t *unique_gift_backdrop_colors_local_var = malloc(sizeof(unique_gift_backdrop_colors_t));
    if (!unique_gift_backdrop_colors_local_var) {
        return NULL;
    }
    unique_gift_backdrop_colors_local_var->center_color = center_color;
    unique_gift_backdrop_colors_local_var->edge_color = edge_color;
    unique_gift_backdrop_colors_local_var->symbol_color = symbol_color;
    unique_gift_backdrop_colors_local_var->text_color = text_color;

    unique_gift_backdrop_colors_local_var->_library_owned = 1;
    return unique_gift_backdrop_colors_local_var;
}

__attribute__((deprecated)) unique_gift_backdrop_colors_t *unique_gift_backdrop_colors_create(
    int center_color,
    int edge_color,
    int symbol_color,
    int text_color
    ) {
    return unique_gift_backdrop_colors_create_internal (
        center_color,
        edge_color,
        symbol_color,
        text_color
        );
}

void unique_gift_backdrop_colors_free(unique_gift_backdrop_colors_t *unique_gift_backdrop_colors) {
    if(NULL == unique_gift_backdrop_colors){
        return ;
    }
    if(unique_gift_backdrop_colors->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "unique_gift_backdrop_colors_free");
        return ;
    }
    listEntry_t *listEntry;
    free(unique_gift_backdrop_colors);
}

cJSON *unique_gift_backdrop_colors_convertToJSON(unique_gift_backdrop_colors_t *unique_gift_backdrop_colors) {
    cJSON *item = cJSON_CreateObject();

    // unique_gift_backdrop_colors->center_color
    if (!unique_gift_backdrop_colors->center_color) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "center_color", unique_gift_backdrop_colors->center_color) == NULL) {
    goto fail; //Numeric
    }


    // unique_gift_backdrop_colors->edge_color
    if (!unique_gift_backdrop_colors->edge_color) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "edge_color", unique_gift_backdrop_colors->edge_color) == NULL) {
    goto fail; //Numeric
    }


    // unique_gift_backdrop_colors->symbol_color
    if (!unique_gift_backdrop_colors->symbol_color) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "symbol_color", unique_gift_backdrop_colors->symbol_color) == NULL) {
    goto fail; //Numeric
    }


    // unique_gift_backdrop_colors->text_color
    if (!unique_gift_backdrop_colors->text_color) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "text_color", unique_gift_backdrop_colors->text_color) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

unique_gift_backdrop_colors_t *unique_gift_backdrop_colors_parseFromJSON(cJSON *unique_gift_backdrop_colorsJSON){

    unique_gift_backdrop_colors_t *unique_gift_backdrop_colors_local_var = NULL;

    // unique_gift_backdrop_colors->center_color
    cJSON *center_color = cJSON_GetObjectItemCaseSensitive(unique_gift_backdrop_colorsJSON, "center_color");
    if (cJSON_IsNull(center_color)) {
        center_color = NULL;
    }
    if (!center_color) {
        goto end;
    }

    
    if(!cJSON_IsNumber(center_color))
    {
    goto end; //Numeric
    }

    // unique_gift_backdrop_colors->edge_color
    cJSON *edge_color = cJSON_GetObjectItemCaseSensitive(unique_gift_backdrop_colorsJSON, "edge_color");
    if (cJSON_IsNull(edge_color)) {
        edge_color = NULL;
    }
    if (!edge_color) {
        goto end;
    }

    
    if(!cJSON_IsNumber(edge_color))
    {
    goto end; //Numeric
    }

    // unique_gift_backdrop_colors->symbol_color
    cJSON *symbol_color = cJSON_GetObjectItemCaseSensitive(unique_gift_backdrop_colorsJSON, "symbol_color");
    if (cJSON_IsNull(symbol_color)) {
        symbol_color = NULL;
    }
    if (!symbol_color) {
        goto end;
    }

    
    if(!cJSON_IsNumber(symbol_color))
    {
    goto end; //Numeric
    }

    // unique_gift_backdrop_colors->text_color
    cJSON *text_color = cJSON_GetObjectItemCaseSensitive(unique_gift_backdrop_colorsJSON, "text_color");
    if (cJSON_IsNull(text_color)) {
        text_color = NULL;
    }
    if (!text_color) {
        goto end;
    }

    
    if(!cJSON_IsNumber(text_color))
    {
    goto end; //Numeric
    }


    unique_gift_backdrop_colors_local_var = unique_gift_backdrop_colors_create_internal (
        center_color->valuedouble,
        edge_color->valuedouble,
        symbol_color->valuedouble,
        text_color->valuedouble
        );

    return unique_gift_backdrop_colors_local_var;
end:
    return NULL;

}
