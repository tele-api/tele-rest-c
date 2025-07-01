#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "video_note.h"



static video_note_t *video_note_create_internal(
    char *file_id,
    char *file_unique_id,
    int length,
    int duration,
    photo_size_t *thumbnail,
    int file_size
    ) {
    video_note_t *video_note_local_var = malloc(sizeof(video_note_t));
    if (!video_note_local_var) {
        return NULL;
    }
    video_note_local_var->file_id = file_id;
    video_note_local_var->file_unique_id = file_unique_id;
    video_note_local_var->length = length;
    video_note_local_var->duration = duration;
    video_note_local_var->thumbnail = thumbnail;
    video_note_local_var->file_size = file_size;

    video_note_local_var->_library_owned = 1;
    return video_note_local_var;
}

__attribute__((deprecated)) video_note_t *video_note_create(
    char *file_id,
    char *file_unique_id,
    int length,
    int duration,
    photo_size_t *thumbnail,
    int file_size
    ) {
    return video_note_create_internal (
        file_id,
        file_unique_id,
        length,
        duration,
        thumbnail,
        file_size
        );
}

void video_note_free(video_note_t *video_note) {
    if(NULL == video_note){
        return ;
    }
    if(video_note->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "video_note_free");
        return ;
    }
    listEntry_t *listEntry;
    if (video_note->file_id) {
        free(video_note->file_id);
        video_note->file_id = NULL;
    }
    if (video_note->file_unique_id) {
        free(video_note->file_unique_id);
        video_note->file_unique_id = NULL;
    }
    if (video_note->thumbnail) {
        photo_size_free(video_note->thumbnail);
        video_note->thumbnail = NULL;
    }
    free(video_note);
}

cJSON *video_note_convertToJSON(video_note_t *video_note) {
    cJSON *item = cJSON_CreateObject();

    // video_note->file_id
    if (!video_note->file_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "file_id", video_note->file_id) == NULL) {
    goto fail; //String
    }


    // video_note->file_unique_id
    if (!video_note->file_unique_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "file_unique_id", video_note->file_unique_id) == NULL) {
    goto fail; //String
    }


    // video_note->length
    if (!video_note->length) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "length", video_note->length) == NULL) {
    goto fail; //Numeric
    }


    // video_note->duration
    if (!video_note->duration) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "duration", video_note->duration) == NULL) {
    goto fail; //Numeric
    }


    // video_note->thumbnail
    if(video_note->thumbnail) {
    cJSON *thumbnail_local_JSON = photo_size_convertToJSON(video_note->thumbnail);
    if(thumbnail_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "thumbnail", thumbnail_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // video_note->file_size
    if(video_note->file_size) {
    if(cJSON_AddNumberToObject(item, "file_size", video_note->file_size) == NULL) {
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

video_note_t *video_note_parseFromJSON(cJSON *video_noteJSON){

    video_note_t *video_note_local_var = NULL;

    // define the local variable for video_note->thumbnail
    photo_size_t *thumbnail_local_nonprim = NULL;

    // video_note->file_id
    cJSON *file_id = cJSON_GetObjectItemCaseSensitive(video_noteJSON, "file_id");
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

    // video_note->file_unique_id
    cJSON *file_unique_id = cJSON_GetObjectItemCaseSensitive(video_noteJSON, "file_unique_id");
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

    // video_note->length
    cJSON *length = cJSON_GetObjectItemCaseSensitive(video_noteJSON, "length");
    if (cJSON_IsNull(length)) {
        length = NULL;
    }
    if (!length) {
        goto end;
    }

    
    if(!cJSON_IsNumber(length))
    {
    goto end; //Numeric
    }

    // video_note->duration
    cJSON *duration = cJSON_GetObjectItemCaseSensitive(video_noteJSON, "duration");
    if (cJSON_IsNull(duration)) {
        duration = NULL;
    }
    if (!duration) {
        goto end;
    }

    
    if(!cJSON_IsNumber(duration))
    {
    goto end; //Numeric
    }

    // video_note->thumbnail
    cJSON *thumbnail = cJSON_GetObjectItemCaseSensitive(video_noteJSON, "thumbnail");
    if (cJSON_IsNull(thumbnail)) {
        thumbnail = NULL;
    }
    if (thumbnail) { 
    thumbnail_local_nonprim = photo_size_parseFromJSON(thumbnail); //nonprimitive
    }

    // video_note->file_size
    cJSON *file_size = cJSON_GetObjectItemCaseSensitive(video_noteJSON, "file_size");
    if (cJSON_IsNull(file_size)) {
        file_size = NULL;
    }
    if (file_size) { 
    if(!cJSON_IsNumber(file_size))
    {
    goto end; //Numeric
    }
    }


    video_note_local_var = video_note_create_internal (
        strdup(file_id->valuestring),
        strdup(file_unique_id->valuestring),
        length->valuedouble,
        duration->valuedouble,
        thumbnail ? thumbnail_local_nonprim : NULL,
        file_size ? file_size->valuedouble : 0
        );

    return video_note_local_var;
end:
    if (thumbnail_local_nonprim) {
        photo_size_free(thumbnail_local_nonprim);
        thumbnail_local_nonprim = NULL;
    }
    return NULL;

}
