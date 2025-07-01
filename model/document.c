#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "document.h"



static document_t *document_create_internal(
    char *file_id,
    char *file_unique_id,
    photo_size_t *thumbnail,
    char *file_name,
    char *mime_type,
    int file_size
    ) {
    document_t *document_local_var = malloc(sizeof(document_t));
    if (!document_local_var) {
        return NULL;
    }
    document_local_var->file_id = file_id;
    document_local_var->file_unique_id = file_unique_id;
    document_local_var->thumbnail = thumbnail;
    document_local_var->file_name = file_name;
    document_local_var->mime_type = mime_type;
    document_local_var->file_size = file_size;

    document_local_var->_library_owned = 1;
    return document_local_var;
}

__attribute__((deprecated)) document_t *document_create(
    char *file_id,
    char *file_unique_id,
    photo_size_t *thumbnail,
    char *file_name,
    char *mime_type,
    int file_size
    ) {
    return document_create_internal (
        file_id,
        file_unique_id,
        thumbnail,
        file_name,
        mime_type,
        file_size
        );
}

void document_free(document_t *document) {
    if(NULL == document){
        return ;
    }
    if(document->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "document_free");
        return ;
    }
    listEntry_t *listEntry;
    if (document->file_id) {
        free(document->file_id);
        document->file_id = NULL;
    }
    if (document->file_unique_id) {
        free(document->file_unique_id);
        document->file_unique_id = NULL;
    }
    if (document->thumbnail) {
        photo_size_free(document->thumbnail);
        document->thumbnail = NULL;
    }
    if (document->file_name) {
        free(document->file_name);
        document->file_name = NULL;
    }
    if (document->mime_type) {
        free(document->mime_type);
        document->mime_type = NULL;
    }
    free(document);
}

cJSON *document_convertToJSON(document_t *document) {
    cJSON *item = cJSON_CreateObject();

    // document->file_id
    if (!document->file_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "file_id", document->file_id) == NULL) {
    goto fail; //String
    }


    // document->file_unique_id
    if (!document->file_unique_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "file_unique_id", document->file_unique_id) == NULL) {
    goto fail; //String
    }


    // document->thumbnail
    if(document->thumbnail) {
    cJSON *thumbnail_local_JSON = photo_size_convertToJSON(document->thumbnail);
    if(thumbnail_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "thumbnail", thumbnail_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // document->file_name
    if(document->file_name) {
    if(cJSON_AddStringToObject(item, "file_name", document->file_name) == NULL) {
    goto fail; //String
    }
    }


    // document->mime_type
    if(document->mime_type) {
    if(cJSON_AddStringToObject(item, "mime_type", document->mime_type) == NULL) {
    goto fail; //String
    }
    }


    // document->file_size
    if(document->file_size) {
    if(cJSON_AddNumberToObject(item, "file_size", document->file_size) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

document_t *document_parseFromJSON(cJSON *documentJSON){

    document_t *document_local_var = NULL;

    // define the local variable for document->thumbnail
    photo_size_t *thumbnail_local_nonprim = NULL;

    // document->file_id
    cJSON *file_id = cJSON_GetObjectItemCaseSensitive(documentJSON, "file_id");
    if (cJSON_IsNull(file_id)) {
        file_id = NULL;
    }
    if (!file_id) {
        goto end;
    }

    
    if(!cJSON_IsString(file_id))
    {
    goto end; //String
    }

    // document->file_unique_id
    cJSON *file_unique_id = cJSON_GetObjectItemCaseSensitive(documentJSON, "file_unique_id");
    if (cJSON_IsNull(file_unique_id)) {
        file_unique_id = NULL;
    }
    if (!file_unique_id) {
        goto end;
    }

    
    if(!cJSON_IsString(file_unique_id))
    {
    goto end; //String
    }

    // document->thumbnail
    cJSON *thumbnail = cJSON_GetObjectItemCaseSensitive(documentJSON, "thumbnail");
    if (cJSON_IsNull(thumbnail)) {
        thumbnail = NULL;
    }
    if (thumbnail) { 
    thumbnail_local_nonprim = photo_size_parseFromJSON(thumbnail); //nonprimitive
    }

    // document->file_name
    cJSON *file_name = cJSON_GetObjectItemCaseSensitive(documentJSON, "file_name");
    if (cJSON_IsNull(file_name)) {
        file_name = NULL;
    }
    if (file_name) { 
    if(!cJSON_IsString(file_name) && !cJSON_IsNull(file_name))
    {
    goto end; //String
    }
    }

    // document->mime_type
    cJSON *mime_type = cJSON_GetObjectItemCaseSensitive(documentJSON, "mime_type");
    if (cJSON_IsNull(mime_type)) {
        mime_type = NULL;
    }
    if (mime_type) { 
    if(!cJSON_IsString(mime_type) && !cJSON_IsNull(mime_type))
    {
    goto end; //String
    }
    }

    // document->file_size
    cJSON *file_size = cJSON_GetObjectItemCaseSensitive(documentJSON, "file_size");
    if (cJSON_IsNull(file_size)) {
        file_size = NULL;
    }
    if (file_size) { 
    if(!cJSON_IsNumber(file_size))
    {
    goto end; //Numeric
    }
    }


    document_local_var = document_create_internal (
        strdup(file_id->valuestring),
        strdup(file_unique_id->valuestring),
        thumbnail ? thumbnail_local_nonprim : NULL,
        file_name && !cJSON_IsNull(file_name) ? strdup(file_name->valuestring) : NULL,
        mime_type && !cJSON_IsNull(mime_type) ? strdup(mime_type->valuestring) : NULL,
        file_size ? file_size->valuedouble : 0
        );

    return document_local_var;
end:
    if (thumbnail_local_nonprim) {
        photo_size_free(thumbnail_local_nonprim);
        thumbnail_local_nonprim = NULL;
    }
    return NULL;

}
