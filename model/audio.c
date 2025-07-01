#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "audio.h"



static audio_t *audio_create_internal(
    char *file_id,
    char *file_unique_id,
    int duration,
    char *performer,
    char *title,
    char *file_name,
    char *mime_type,
    int file_size,
    photo_size_t *thumbnail
    ) {
    audio_t *audio_local_var = malloc(sizeof(audio_t));
    if (!audio_local_var) {
        return NULL;
    }
    audio_local_var->file_id = file_id;
    audio_local_var->file_unique_id = file_unique_id;
    audio_local_var->duration = duration;
    audio_local_var->performer = performer;
    audio_local_var->title = title;
    audio_local_var->file_name = file_name;
    audio_local_var->mime_type = mime_type;
    audio_local_var->file_size = file_size;
    audio_local_var->thumbnail = thumbnail;

    audio_local_var->_library_owned = 1;
    return audio_local_var;
}

__attribute__((deprecated)) audio_t *audio_create(
    char *file_id,
    char *file_unique_id,
    int duration,
    char *performer,
    char *title,
    char *file_name,
    char *mime_type,
    int file_size,
    photo_size_t *thumbnail
    ) {
    return audio_create_internal (
        file_id,
        file_unique_id,
        duration,
        performer,
        title,
        file_name,
        mime_type,
        file_size,
        thumbnail
        );
}

void audio_free(audio_t *audio) {
    if(NULL == audio){
        return ;
    }
    if(audio->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "audio_free");
        return ;
    }
    listEntry_t *listEntry;
    if (audio->file_id) {
        free(audio->file_id);
        audio->file_id = NULL;
    }
    if (audio->file_unique_id) {
        free(audio->file_unique_id);
        audio->file_unique_id = NULL;
    }
    if (audio->performer) {
        free(audio->performer);
        audio->performer = NULL;
    }
    if (audio->title) {
        free(audio->title);
        audio->title = NULL;
    }
    if (audio->file_name) {
        free(audio->file_name);
        audio->file_name = NULL;
    }
    if (audio->mime_type) {
        free(audio->mime_type);
        audio->mime_type = NULL;
    }
    if (audio->thumbnail) {
        photo_size_free(audio->thumbnail);
        audio->thumbnail = NULL;
    }
    free(audio);
}

cJSON *audio_convertToJSON(audio_t *audio) {
    cJSON *item = cJSON_CreateObject();

    // audio->file_id
    if (!audio->file_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "file_id", audio->file_id) == NULL) {
    goto fail; //String
    }


    // audio->file_unique_id
    if (!audio->file_unique_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "file_unique_id", audio->file_unique_id) == NULL) {
    goto fail; //String
    }


    // audio->duration
    if (!audio->duration) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "duration", audio->duration) == NULL) {
    goto fail; //Numeric
    }


    // audio->performer
    if(audio->performer) {
    if(cJSON_AddStringToObject(item, "performer", audio->performer) == NULL) {
    goto fail; //String
    }
    }


    // audio->title
    if(audio->title) {
    if(cJSON_AddStringToObject(item, "title", audio->title) == NULL) {
    goto fail; //String
    }
    }


    // audio->file_name
    if(audio->file_name) {
    if(cJSON_AddStringToObject(item, "file_name", audio->file_name) == NULL) {
    goto fail; //String
    }
    }


    // audio->mime_type
    if(audio->mime_type) {
    if(cJSON_AddStringToObject(item, "mime_type", audio->mime_type) == NULL) {
    goto fail; //String
    }
    }


    // audio->file_size
    if(audio->file_size) {
    if(cJSON_AddNumberToObject(item, "file_size", audio->file_size) == NULL) {
    goto fail; //Numeric
    }
    }


    // audio->thumbnail
    if(audio->thumbnail) {
    cJSON *thumbnail_local_JSON = photo_size_convertToJSON(audio->thumbnail);
    if(thumbnail_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "thumbnail", thumbnail_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

audio_t *audio_parseFromJSON(cJSON *audioJSON){

    audio_t *audio_local_var = NULL;

    // define the local variable for audio->thumbnail
    photo_size_t *thumbnail_local_nonprim = NULL;

    // audio->file_id
    cJSON *file_id = cJSON_GetObjectItemCaseSensitive(audioJSON, "file_id");
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

    // audio->file_unique_id
    cJSON *file_unique_id = cJSON_GetObjectItemCaseSensitive(audioJSON, "file_unique_id");
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

    // audio->duration
    cJSON *duration = cJSON_GetObjectItemCaseSensitive(audioJSON, "duration");
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

    // audio->performer
    cJSON *performer = cJSON_GetObjectItemCaseSensitive(audioJSON, "performer");
    if (cJSON_IsNull(performer)) {
        performer = NULL;
    }
    if (performer) { 
    if(!cJSON_IsString(performer) && !cJSON_IsNull(performer))
    {
    goto end; //String
    }
    }

    // audio->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(audioJSON, "title");
    if (cJSON_IsNull(title)) {
        title = NULL;
    }
    if (title) { 
    if(!cJSON_IsString(title) && !cJSON_IsNull(title))
    {
    goto end; //String
    }
    }

    // audio->file_name
    cJSON *file_name = cJSON_GetObjectItemCaseSensitive(audioJSON, "file_name");
    if (cJSON_IsNull(file_name)) {
        file_name = NULL;
    }
    if (file_name) { 
    if(!cJSON_IsString(file_name) && !cJSON_IsNull(file_name))
    {
    goto end; //String
    }
    }

    // audio->mime_type
    cJSON *mime_type = cJSON_GetObjectItemCaseSensitive(audioJSON, "mime_type");
    if (cJSON_IsNull(mime_type)) {
        mime_type = NULL;
    }
    if (mime_type) { 
    if(!cJSON_IsString(mime_type) && !cJSON_IsNull(mime_type))
    {
    goto end; //String
    }
    }

    // audio->file_size
    cJSON *file_size = cJSON_GetObjectItemCaseSensitive(audioJSON, "file_size");
    if (cJSON_IsNull(file_size)) {
        file_size = NULL;
    }
    if (file_size) { 
    if(!cJSON_IsNumber(file_size))
    {
    goto end; //Numeric
    }
    }

    // audio->thumbnail
    cJSON *thumbnail = cJSON_GetObjectItemCaseSensitive(audioJSON, "thumbnail");
    if (cJSON_IsNull(thumbnail)) {
        thumbnail = NULL;
    }
    if (thumbnail) { 
    thumbnail_local_nonprim = photo_size_parseFromJSON(thumbnail); //nonprimitive
    }


    audio_local_var = audio_create_internal (
        strdup(file_id->valuestring),
        strdup(file_unique_id->valuestring),
        duration->valuedouble,
        performer && !cJSON_IsNull(performer) ? strdup(performer->valuestring) : NULL,
        title && !cJSON_IsNull(title) ? strdup(title->valuestring) : NULL,
        file_name && !cJSON_IsNull(file_name) ? strdup(file_name->valuestring) : NULL,
        mime_type && !cJSON_IsNull(mime_type) ? strdup(mime_type->valuestring) : NULL,
        file_size ? file_size->valuedouble : 0,
        thumbnail ? thumbnail_local_nonprim : NULL
        );

    return audio_local_var;
end:
    if (thumbnail_local_nonprim) {
        photo_size_free(thumbnail_local_nonprim);
        thumbnail_local_nonprim = NULL;
    }
    return NULL;

}
