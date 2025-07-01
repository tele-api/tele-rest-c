#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "chosen_inline_result.h"



static chosen_inline_result_t *chosen_inline_result_create_internal(
    char *result_id,
    user_t *from,
    char *query,
    location_t *location,
    char *inline_message_id
    ) {
    chosen_inline_result_t *chosen_inline_result_local_var = malloc(sizeof(chosen_inline_result_t));
    if (!chosen_inline_result_local_var) {
        return NULL;
    }
    chosen_inline_result_local_var->result_id = result_id;
    chosen_inline_result_local_var->from = from;
    chosen_inline_result_local_var->query = query;
    chosen_inline_result_local_var->location = location;
    chosen_inline_result_local_var->inline_message_id = inline_message_id;

    chosen_inline_result_local_var->_library_owned = 1;
    return chosen_inline_result_local_var;
}

__attribute__((deprecated)) chosen_inline_result_t *chosen_inline_result_create(
    char *result_id,
    user_t *from,
    char *query,
    location_t *location,
    char *inline_message_id
    ) {
    return chosen_inline_result_create_internal (
        result_id,
        from,
        query,
        location,
        inline_message_id
        );
}

void chosen_inline_result_free(chosen_inline_result_t *chosen_inline_result) {
    if(NULL == chosen_inline_result){
        return ;
    }
    if(chosen_inline_result->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "chosen_inline_result_free");
        return ;
    }
    listEntry_t *listEntry;
    if (chosen_inline_result->result_id) {
        free(chosen_inline_result->result_id);
        chosen_inline_result->result_id = NULL;
    }
    if (chosen_inline_result->from) {
        user_free(chosen_inline_result->from);
        chosen_inline_result->from = NULL;
    }
    if (chosen_inline_result->query) {
        free(chosen_inline_result->query);
        chosen_inline_result->query = NULL;
    }
    if (chosen_inline_result->location) {
        location_free(chosen_inline_result->location);
        chosen_inline_result->location = NULL;
    }
    if (chosen_inline_result->inline_message_id) {
        free(chosen_inline_result->inline_message_id);
        chosen_inline_result->inline_message_id = NULL;
    }
    free(chosen_inline_result);
}

cJSON *chosen_inline_result_convertToJSON(chosen_inline_result_t *chosen_inline_result) {
    cJSON *item = cJSON_CreateObject();

    // chosen_inline_result->result_id
    if (!chosen_inline_result->result_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "result_id", chosen_inline_result->result_id) == NULL) {
    goto fail; //String
    }


    // chosen_inline_result->from
    if (!chosen_inline_result->from) {
        goto fail;
    }
    cJSON *from_local_JSON = user_convertToJSON(chosen_inline_result->from);
    if(from_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "from", from_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // chosen_inline_result->query
    if (!chosen_inline_result->query) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "query", chosen_inline_result->query) == NULL) {
    goto fail; //String
    }


    // chosen_inline_result->location
    if(chosen_inline_result->location) {
    cJSON *location_local_JSON = location_convertToJSON(chosen_inline_result->location);
    if(location_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "location", location_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // chosen_inline_result->inline_message_id
    if(chosen_inline_result->inline_message_id) {
    if(cJSON_AddStringToObject(item, "inline_message_id", chosen_inline_result->inline_message_id) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

chosen_inline_result_t *chosen_inline_result_parseFromJSON(cJSON *chosen_inline_resultJSON){

    chosen_inline_result_t *chosen_inline_result_local_var = NULL;

    // define the local variable for chosen_inline_result->from
    user_t *from_local_nonprim = NULL;

    // define the local variable for chosen_inline_result->location
    location_t *location_local_nonprim = NULL;

    // chosen_inline_result->result_id
    cJSON *result_id = cJSON_GetObjectItemCaseSensitive(chosen_inline_resultJSON, "result_id");
    if (cJSON_IsNull(result_id)) {
        result_id = NULL;
    }
    if (!result_id) {
        goto end;
    }

    
    if(!cJSON_IsString(result_id))
    {
    goto end; //String
    }

    // chosen_inline_result->from
    cJSON *from = cJSON_GetObjectItemCaseSensitive(chosen_inline_resultJSON, "from");
    if (cJSON_IsNull(from)) {
        from = NULL;
    }
    if (!from) {
        goto end;
    }

    
    from_local_nonprim = user_parseFromJSON(from); //nonprimitive

    // chosen_inline_result->query
    cJSON *query = cJSON_GetObjectItemCaseSensitive(chosen_inline_resultJSON, "query");
    if (cJSON_IsNull(query)) {
        query = NULL;
    }
    if (!query) {
        goto end;
    }

    
    if(!cJSON_IsString(query))
    {
    goto end; //String
    }

    // chosen_inline_result->location
    cJSON *location = cJSON_GetObjectItemCaseSensitive(chosen_inline_resultJSON, "location");
    if (cJSON_IsNull(location)) {
        location = NULL;
    }
    if (location) { 
    location_local_nonprim = location_parseFromJSON(location); //nonprimitive
    }

    // chosen_inline_result->inline_message_id
    cJSON *inline_message_id = cJSON_GetObjectItemCaseSensitive(chosen_inline_resultJSON, "inline_message_id");
    if (cJSON_IsNull(inline_message_id)) {
        inline_message_id = NULL;
    }
    if (inline_message_id) { 
    if(!cJSON_IsString(inline_message_id) && !cJSON_IsNull(inline_message_id))
    {
    goto end; //String
    }
    }


    chosen_inline_result_local_var = chosen_inline_result_create_internal (
        strdup(result_id->valuestring),
        from_local_nonprim,
        strdup(query->valuestring),
        location ? location_local_nonprim : NULL,
        inline_message_id && !cJSON_IsNull(inline_message_id) ? strdup(inline_message_id->valuestring) : NULL
        );

    return chosen_inline_result_local_var;
end:
    if (from_local_nonprim) {
        user_free(from_local_nonprim);
        from_local_nonprim = NULL;
    }
    if (location_local_nonprim) {
        location_free(location_local_nonprim);
        location_local_nonprim = NULL;
    }
    return NULL;

}
