#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "giveaway_created.h"



static giveaway_created_t *giveaway_created_create_internal(
    int prize_star_count
    ) {
    giveaway_created_t *giveaway_created_local_var = malloc(sizeof(giveaway_created_t));
    if (!giveaway_created_local_var) {
        return NULL;
    }
    giveaway_created_local_var->prize_star_count = prize_star_count;

    giveaway_created_local_var->_library_owned = 1;
    return giveaway_created_local_var;
}

__attribute__((deprecated)) giveaway_created_t *giveaway_created_create(
    int prize_star_count
    ) {
    return giveaway_created_create_internal (
        prize_star_count
        );
}

void giveaway_created_free(giveaway_created_t *giveaway_created) {
    if(NULL == giveaway_created){
        return ;
    }
    if(giveaway_created->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "giveaway_created_free");
        return ;
    }
    listEntry_t *listEntry;
    free(giveaway_created);
}

cJSON *giveaway_created_convertToJSON(giveaway_created_t *giveaway_created) {
    cJSON *item = cJSON_CreateObject();

    // giveaway_created->prize_star_count
    if(giveaway_created->prize_star_count) {
    if(cJSON_AddNumberToObject(item, "prize_star_count", giveaway_created->prize_star_count) == NULL) {
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

giveaway_created_t *giveaway_created_parseFromJSON(cJSON *giveaway_createdJSON){

    giveaway_created_t *giveaway_created_local_var = NULL;

    // giveaway_created->prize_star_count
    cJSON *prize_star_count = cJSON_GetObjectItemCaseSensitive(giveaway_createdJSON, "prize_star_count");
    if (cJSON_IsNull(prize_star_count)) {
        prize_star_count = NULL;
    }
    if (prize_star_count) { 
    if(!cJSON_IsNumber(prize_star_count))
    {
    goto end; //Numeric
    }
    }


    giveaway_created_local_var = giveaway_created_create_internal (
        prize_star_count ? prize_star_count->valuedouble : 0
        );

    return giveaway_created_local_var;
end:
    return NULL;

}
