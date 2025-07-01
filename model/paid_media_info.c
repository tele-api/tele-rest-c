#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "paid_media_info.h"



static paid_media_info_t *paid_media_info_create_internal(
    int star_count,
    list_t *paid_media
    ) {
    paid_media_info_t *paid_media_info_local_var = malloc(sizeof(paid_media_info_t));
    if (!paid_media_info_local_var) {
        return NULL;
    }
    paid_media_info_local_var->star_count = star_count;
    paid_media_info_local_var->paid_media = paid_media;

    paid_media_info_local_var->_library_owned = 1;
    return paid_media_info_local_var;
}

__attribute__((deprecated)) paid_media_info_t *paid_media_info_create(
    int star_count,
    list_t *paid_media
    ) {
    return paid_media_info_create_internal (
        star_count,
        paid_media
        );
}

void paid_media_info_free(paid_media_info_t *paid_media_info) {
    if(NULL == paid_media_info){
        return ;
    }
    if(paid_media_info->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "paid_media_info_free");
        return ;
    }
    listEntry_t *listEntry;
    if (paid_media_info->paid_media) {
        list_ForEach(listEntry, paid_media_info->paid_media) {
            paid_media_free(listEntry->data);
        }
        list_freeList(paid_media_info->paid_media);
        paid_media_info->paid_media = NULL;
    }
    free(paid_media_info);
}

cJSON *paid_media_info_convertToJSON(paid_media_info_t *paid_media_info) {
    cJSON *item = cJSON_CreateObject();

    // paid_media_info->star_count
    if (!paid_media_info->star_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "star_count", paid_media_info->star_count) == NULL) {
    goto fail; //Numeric
    }


    // paid_media_info->paid_media
    if (!paid_media_info->paid_media) {
        goto fail;
    }
    cJSON *paid_media = cJSON_AddArrayToObject(item, "paid_media");
    if(paid_media == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *paid_mediaListEntry;
    if (paid_media_info->paid_media) {
    list_ForEach(paid_mediaListEntry, paid_media_info->paid_media) {
    cJSON *itemLocal = paid_media_convertToJSON(paid_mediaListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(paid_media, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

paid_media_info_t *paid_media_info_parseFromJSON(cJSON *paid_media_infoJSON){

    paid_media_info_t *paid_media_info_local_var = NULL;

    // define the local list for paid_media_info->paid_media
    list_t *paid_mediaList = NULL;

    // paid_media_info->star_count
    cJSON *star_count = cJSON_GetObjectItemCaseSensitive(paid_media_infoJSON, "star_count");
    if (cJSON_IsNull(star_count)) {
        star_count = NULL;
    }
    if (!star_count) {
        goto end;
    }

    
    if(!cJSON_IsNumber(star_count))
    {
    goto end; //Numeric
    }

    // paid_media_info->paid_media
    cJSON *paid_media = cJSON_GetObjectItemCaseSensitive(paid_media_infoJSON, "paid_media");
    if (cJSON_IsNull(paid_media)) {
        paid_media = NULL;
    }
    if (!paid_media) {
        goto end;
    }

    
    cJSON *paid_media_local_nonprimitive = NULL;
    if(!cJSON_IsArray(paid_media)){
        goto end; //nonprimitive container
    }

    paid_mediaList = list_createList();

    cJSON_ArrayForEach(paid_media_local_nonprimitive,paid_media )
    {
        if(!cJSON_IsObject(paid_media_local_nonprimitive)){
            goto end;
        }
        paid_media_t *paid_mediaItem = paid_media_parseFromJSON(paid_media_local_nonprimitive);

        list_addElement(paid_mediaList, paid_mediaItem);
    }


    paid_media_info_local_var = paid_media_info_create_internal (
        star_count->valuedouble,
        paid_mediaList
        );

    return paid_media_info_local_var;
end:
    if (paid_mediaList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, paid_mediaList) {
            paid_media_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(paid_mediaList);
        paid_mediaList = NULL;
    }
    return NULL;

}
