#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "video_chat_scheduled.h"



static video_chat_scheduled_t *video_chat_scheduled_create_internal(
    int start_date
    ) {
    video_chat_scheduled_t *video_chat_scheduled_local_var = malloc(sizeof(video_chat_scheduled_t));
    if (!video_chat_scheduled_local_var) {
        return NULL;
    }
    video_chat_scheduled_local_var->start_date = start_date;

    video_chat_scheduled_local_var->_library_owned = 1;
    return video_chat_scheduled_local_var;
}

__attribute__((deprecated)) video_chat_scheduled_t *video_chat_scheduled_create(
    int start_date
    ) {
    return video_chat_scheduled_create_internal (
        start_date
        );
}

void video_chat_scheduled_free(video_chat_scheduled_t *video_chat_scheduled) {
    if(NULL == video_chat_scheduled){
        return ;
    }
    if(video_chat_scheduled->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "video_chat_scheduled_free");
        return ;
    }
    listEntry_t *listEntry;
    free(video_chat_scheduled);
}

cJSON *video_chat_scheduled_convertToJSON(video_chat_scheduled_t *video_chat_scheduled) {
    cJSON *item = cJSON_CreateObject();

    // video_chat_scheduled->start_date
    if (!video_chat_scheduled->start_date) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "start_date", video_chat_scheduled->start_date) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

video_chat_scheduled_t *video_chat_scheduled_parseFromJSON(cJSON *video_chat_scheduledJSON){

    video_chat_scheduled_t *video_chat_scheduled_local_var = NULL;

    // video_chat_scheduled->start_date
    cJSON *start_date = cJSON_GetObjectItemCaseSensitive(video_chat_scheduledJSON, "start_date");
    if (cJSON_IsNull(start_date)) {
        start_date = NULL;
    }
    if (!start_date) {
        goto end;
    }

    
    if(!cJSON_IsNumber(start_date))
    {
    goto end; //Numeric
    }


    video_chat_scheduled_local_var = video_chat_scheduled_create_internal (
        start_date->valuedouble
        );

    return video_chat_scheduled_local_var;
end:
    return NULL;

}
