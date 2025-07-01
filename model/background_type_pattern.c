#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "background_type_pattern.h"



static background_type_pattern_t *background_type_pattern_create_internal(
    char *type,
    document_t *document,
    background_fill_t *fill,
    int intensity,
    int is_inverted,
    int is_moving
    ) {
    background_type_pattern_t *background_type_pattern_local_var = malloc(sizeof(background_type_pattern_t));
    if (!background_type_pattern_local_var) {
        return NULL;
    }
    background_type_pattern_local_var->type = type;
    background_type_pattern_local_var->document = document;
    background_type_pattern_local_var->fill = fill;
    background_type_pattern_local_var->intensity = intensity;
    background_type_pattern_local_var->is_inverted = is_inverted;
    background_type_pattern_local_var->is_moving = is_moving;

    background_type_pattern_local_var->_library_owned = 1;
    return background_type_pattern_local_var;
}

__attribute__((deprecated)) background_type_pattern_t *background_type_pattern_create(
    char *type,
    document_t *document,
    background_fill_t *fill,
    int intensity,
    int is_inverted,
    int is_moving
    ) {
    return background_type_pattern_create_internal (
        type,
        document,
        fill,
        intensity,
        is_inverted,
        is_moving
        );
}

void background_type_pattern_free(background_type_pattern_t *background_type_pattern) {
    if(NULL == background_type_pattern){
        return ;
    }
    if(background_type_pattern->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "background_type_pattern_free");
        return ;
    }
    listEntry_t *listEntry;
    if (background_type_pattern->type) {
        free(background_type_pattern->type);
        background_type_pattern->type = NULL;
    }
    if (background_type_pattern->document) {
        document_free(background_type_pattern->document);
        background_type_pattern->document = NULL;
    }
    if (background_type_pattern->fill) {
        background_fill_free(background_type_pattern->fill);
        background_type_pattern->fill = NULL;
    }
    free(background_type_pattern);
}

cJSON *background_type_pattern_convertToJSON(background_type_pattern_t *background_type_pattern) {
    cJSON *item = cJSON_CreateObject();

    // background_type_pattern->type
    if (!background_type_pattern->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", background_type_pattern->type) == NULL) {
    goto fail; //String
    }


    // background_type_pattern->document
    if (!background_type_pattern->document) {
        goto fail;
    }
    cJSON *document_local_JSON = document_convertToJSON(background_type_pattern->document);
    if(document_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "document", document_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // background_type_pattern->fill
    if (!background_type_pattern->fill) {
        goto fail;
    }
    cJSON *fill_local_JSON = background_fill_convertToJSON(background_type_pattern->fill);
    if(fill_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "fill", fill_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // background_type_pattern->intensity
    if (!background_type_pattern->intensity) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "intensity", background_type_pattern->intensity) == NULL) {
    goto fail; //Numeric
    }


    // background_type_pattern->is_inverted
    if(background_type_pattern->is_inverted) {
    if(cJSON_AddBoolToObject(item, "is_inverted", background_type_pattern->is_inverted) == NULL) {
    goto fail; //Bool
    }
    }


    // background_type_pattern->is_moving
    if(background_type_pattern->is_moving) {
    if(cJSON_AddBoolToObject(item, "is_moving", background_type_pattern->is_moving) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

background_type_pattern_t *background_type_pattern_parseFromJSON(cJSON *background_type_patternJSON){

    background_type_pattern_t *background_type_pattern_local_var = NULL;

    // define the local variable for background_type_pattern->document
    document_t *document_local_nonprim = NULL;

    // define the local variable for background_type_pattern->fill
    background_fill_t *fill_local_nonprim = NULL;

    // background_type_pattern->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(background_type_patternJSON, "type");
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

    // background_type_pattern->document
    cJSON *document = cJSON_GetObjectItemCaseSensitive(background_type_patternJSON, "document");
    if (cJSON_IsNull(document)) {
        document = NULL;
    }
    if (!document) {
        goto end;
    }

    
    document_local_nonprim = document_parseFromJSON(document); //nonprimitive

    // background_type_pattern->fill
    cJSON *fill = cJSON_GetObjectItemCaseSensitive(background_type_patternJSON, "fill");
    if (cJSON_IsNull(fill)) {
        fill = NULL;
    }
    if (!fill) {
        goto end;
    }

    
    fill_local_nonprim = background_fill_parseFromJSON(fill); //nonprimitive

    // background_type_pattern->intensity
    cJSON *intensity = cJSON_GetObjectItemCaseSensitive(background_type_patternJSON, "intensity");
    if (cJSON_IsNull(intensity)) {
        intensity = NULL;
    }
    if (!intensity) {
        goto end;
    }

    
    if(!cJSON_IsNumber(intensity))
    {
    goto end; //Numeric
    }

    // background_type_pattern->is_inverted
    cJSON *is_inverted = cJSON_GetObjectItemCaseSensitive(background_type_patternJSON, "is_inverted");
    if (cJSON_IsNull(is_inverted)) {
        is_inverted = NULL;
    }
    if (is_inverted) { 
    if(!cJSON_IsBool(is_inverted))
    {
    goto end; //Bool
    }
    }

    // background_type_pattern->is_moving
    cJSON *is_moving = cJSON_GetObjectItemCaseSensitive(background_type_patternJSON, "is_moving");
    if (cJSON_IsNull(is_moving)) {
        is_moving = NULL;
    }
    if (is_moving) { 
    if(!cJSON_IsBool(is_moving))
    {
    goto end; //Bool
    }
    }


    background_type_pattern_local_var = background_type_pattern_create_internal (
        strdup(type->valuestring),
        document_local_nonprim,
        fill_local_nonprim,
        intensity->valuedouble,
        is_inverted ? is_inverted->valueint : 0,
        is_moving ? is_moving->valueint : 0
        );

    return background_type_pattern_local_var;
end:
    if (document_local_nonprim) {
        document_free(document_local_nonprim);
        document_local_nonprim = NULL;
    }
    if (fill_local_nonprim) {
        background_fill_free(fill_local_nonprim);
        fill_local_nonprim = NULL;
    }
    return NULL;

}
