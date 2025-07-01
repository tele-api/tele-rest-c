#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "voice.h"



static voice_t *voice_create_internal(
    char *file_id,
    char *file_unique_id,
    int duration,
    char *mime_type,
    int file_size
    ) {
    voice_t *voice_local_var = malloc(sizeof(voice_t));
    if (!voice_local_var) {
        return NULL;
    }
    voice_local_var->file_id = file_id;
    voice_local_var->file_unique_id = file_unique_id;
    voice_local_var->duration = duration;
    voice_local_var->mime_type = mime_type;
    voice_local_var->file_size = file_size;

    voice_local_var->_library_owned = 1;
    return voice_local_var;
}

__attribute__((deprecated)) voice_t *voice_create(
    char *file_id,
    char *file_unique_id,
    int duration,
    char *mime_type,
    int file_size
    ) {
    return voice_create_internal (
        file_id,
        file_unique_id,
        duration,
        mime_type,
        file_size
        );
}

void voice_free(voice_t *voice) {
    if(NULL == voice){
        return ;
    }
    if(voice->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "voice_free");
        return ;
    }
    listEntry_t *listEntry;
    if (voice->file_id) {
        free(voice->file_id);
        voice->file_id = NULL;
    }
    if (voice->file_unique_id) {
        free(voice->file_unique_id);
        voice->file_unique_id = NULL;
    }
    if (voice->mime_type) {
        free(voice->mime_type);
        voice->mime_type = NULL;
    }
    free(voice);
}

cJSON *voice_convertToJSON(voice_t *voice) {
    cJSON *item = cJSON_CreateObject();

    // voice->file_id
    if (!voice->file_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "file_id", voice->file_id) == NULL) {
    goto fail; //String
    }


    // voice->file_unique_id
    if (!voice->file_unique_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "file_unique_id", voice->file_unique_id) == NULL) {
    goto fail; //String
    }


    // voice->duration
    if (!voice->duration) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "duration", voice->duration) == NULL) {
    goto fail; //Numeric
    }


    // voice->mime_type
    if(voice->mime_type) {
    if(cJSON_AddStringToObject(item, "mime_type", voice->mime_type) == NULL) {
    goto fail; //String
    }
    }


    // voice->file_size
    if(voice->file_size) {
    if(cJSON_AddNumberToObject(item, "file_size", voice->file_size) == NULL) {
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

voice_t *voice_parseFromJSON(cJSON *voiceJSON){

    voice_t *voice_local_var = NULL;

    // voice->file_id
    cJSON *file_id = cJSON_GetObjectItemCaseSensitive(voiceJSON, "file_id");
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

    // voice->file_unique_id
    cJSON *file_unique_id = cJSON_GetObjectItemCaseSensitive(voiceJSON, "file_unique_id");
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

    // voice->duration
    cJSON *duration = cJSON_GetObjectItemCaseSensitive(voiceJSON, "duration");
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

    // voice->mime_type
    cJSON *mime_type = cJSON_GetObjectItemCaseSensitive(voiceJSON, "mime_type");
    if (cJSON_IsNull(mime_type)) {
        mime_type = NULL;
    }
    if (mime_type) { 
    if(!cJSON_IsString(mime_type) && !cJSON_IsNull(mime_type))
    {
    goto end; //String
    }
    }

    // voice->file_size
    cJSON *file_size = cJSON_GetObjectItemCaseSensitive(voiceJSON, "file_size");
    if (cJSON_IsNull(file_size)) {
        file_size = NULL;
    }
    if (file_size) { 
    if(!cJSON_IsNumber(file_size))
    {
    goto end; //Numeric
    }
    }


    voice_local_var = voice_create_internal (
        strdup(file_id->valuestring),
        strdup(file_unique_id->valuestring),
        duration->valuedouble,
        mime_type && !cJSON_IsNull(mime_type) ? strdup(mime_type->valuestring) : NULL,
        file_size ? file_size->valuedouble : 0
        );

    return voice_local_var;
end:
    return NULL;

}
