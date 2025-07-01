#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "dice.h"



static dice_t *dice_create_internal(
    char *emoji,
    int value
    ) {
    dice_t *dice_local_var = malloc(sizeof(dice_t));
    if (!dice_local_var) {
        return NULL;
    }
    dice_local_var->emoji = emoji;
    dice_local_var->value = value;

    dice_local_var->_library_owned = 1;
    return dice_local_var;
}

__attribute__((deprecated)) dice_t *dice_create(
    char *emoji,
    int value
    ) {
    return dice_create_internal (
        emoji,
        value
        );
}

void dice_free(dice_t *dice) {
    if(NULL == dice){
        return ;
    }
    if(dice->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "dice_free");
        return ;
    }
    listEntry_t *listEntry;
    if (dice->emoji) {
        free(dice->emoji);
        dice->emoji = NULL;
    }
    free(dice);
}

cJSON *dice_convertToJSON(dice_t *dice) {
    cJSON *item = cJSON_CreateObject();

    // dice->emoji
    if (!dice->emoji) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "emoji", dice->emoji) == NULL) {
    goto fail; //String
    }


    // dice->value
    if (!dice->value) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "value", dice->value) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

dice_t *dice_parseFromJSON(cJSON *diceJSON){

    dice_t *dice_local_var = NULL;

    // dice->emoji
    cJSON *emoji = cJSON_GetObjectItemCaseSensitive(diceJSON, "emoji");
    if (cJSON_IsNull(emoji)) {
        emoji = NULL;
    }
    if (!emoji) {
        goto end;
    }

    
    if(!cJSON_IsString(emoji))
    {
    goto end; //String
    }

    // dice->value
    cJSON *value = cJSON_GetObjectItemCaseSensitive(diceJSON, "value");
    if (cJSON_IsNull(value)) {
        value = NULL;
    }
    if (!value) {
        goto end;
    }

    
    if(!cJSON_IsNumber(value))
    {
    goto end; //Numeric
    }


    dice_local_var = dice_create_internal (
        strdup(emoji->valuestring),
        value->valuedouble
        );

    return dice_local_var;
end:
    return NULL;

}
