#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "video_chat_ended.h"



static video_chat_ended_t *video_chat_ended_create_internal(
    int duration
    ) {
    video_chat_ended_t *video_chat_ended_local_var = malloc(sizeof(video_chat_ended_t));
    if (!video_chat_ended_local_var) {
        return NULL;
    }
    video_chat_ended_local_var->duration = duration;

    video_chat_ended_local_var->_library_owned = 1;
    return video_chat_ended_local_var;
}

__attribute__((deprecated)) video_chat_ended_t *video_chat_ended_create(
    int duration
    ) {
    return video_chat_ended_create_internal (
        duration
        );
}

void video_chat_ended_free(video_chat_ended_t *video_chat_ended) {
    if(NULL == video_chat_ended){
        return ;
    }
    if(video_chat_ended->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "video_chat_ended_free");
        return ;
    }
    listEntry_t *listEntry;
    free(video_chat_ended);
}

cJSON *video_chat_ended_convertToJSON(video_chat_ended_t *video_chat_ended) {
    cJSON *item = cJSON_CreateObject();

    // video_chat_ended->duration
    if (!video_chat_ended->duration) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "duration", video_chat_ended->duration) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

video_chat_ended_t *video_chat_ended_parseFromJSON(cJSON *video_chat_endedJSON){

    video_chat_ended_t *video_chat_ended_local_var = NULL;

    // video_chat_ended->duration
    cJSON *duration = cJSON_GetObjectItemCaseSensitive(video_chat_endedJSON, "duration");
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


    video_chat_ended_local_var = video_chat_ended_create_internal (
        duration->valuedouble
        );

    return video_chat_ended_local_var;
end:
    return NULL;

}
