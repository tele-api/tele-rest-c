#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "poll.h"


char* poll_type_ToString(telegram_bot_api_poll_TYPE_e type) {
    char* typeArray[] =  { "NULL", "regular", "quiz" };
    return typeArray[type];
}

telegram_bot_api_poll_TYPE_e poll_type_FromString(char* type){
    int stringToReturn = 0;
    char *typeArray[] =  { "NULL", "regular", "quiz" };
    size_t sizeofArray = sizeof(typeArray) / sizeof(typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(type, typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static poll_t *poll_create_internal(
    char *id,
    char *question,
    list_t *options,
    int total_voter_count,
    int is_closed,
    int is_anonymous,
    telegram_bot_api_poll_TYPE_e type,
    int allows_multiple_answers,
    list_t *question_entities,
    int correct_option_id,
    char *explanation,
    list_t *explanation_entities,
    int open_period,
    int close_date
    ) {
    poll_t *poll_local_var = malloc(sizeof(poll_t));
    if (!poll_local_var) {
        return NULL;
    }
    poll_local_var->id = id;
    poll_local_var->question = question;
    poll_local_var->options = options;
    poll_local_var->total_voter_count = total_voter_count;
    poll_local_var->is_closed = is_closed;
    poll_local_var->is_anonymous = is_anonymous;
    poll_local_var->type = type;
    poll_local_var->allows_multiple_answers = allows_multiple_answers;
    poll_local_var->question_entities = question_entities;
    poll_local_var->correct_option_id = correct_option_id;
    poll_local_var->explanation = explanation;
    poll_local_var->explanation_entities = explanation_entities;
    poll_local_var->open_period = open_period;
    poll_local_var->close_date = close_date;

    poll_local_var->_library_owned = 1;
    return poll_local_var;
}

__attribute__((deprecated)) poll_t *poll_create(
    char *id,
    char *question,
    list_t *options,
    int total_voter_count,
    int is_closed,
    int is_anonymous,
    telegram_bot_api_poll_TYPE_e type,
    int allows_multiple_answers,
    list_t *question_entities,
    int correct_option_id,
    char *explanation,
    list_t *explanation_entities,
    int open_period,
    int close_date
    ) {
    return poll_create_internal (
        id,
        question,
        options,
        total_voter_count,
        is_closed,
        is_anonymous,
        type,
        allows_multiple_answers,
        question_entities,
        correct_option_id,
        explanation,
        explanation_entities,
        open_period,
        close_date
        );
}

void poll_free(poll_t *poll) {
    if(NULL == poll){
        return ;
    }
    if(poll->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "poll_free");
        return ;
    }
    listEntry_t *listEntry;
    if (poll->id) {
        free(poll->id);
        poll->id = NULL;
    }
    if (poll->question) {
        free(poll->question);
        poll->question = NULL;
    }
    if (poll->options) {
        list_ForEach(listEntry, poll->options) {
            poll_option_free(listEntry->data);
        }
        list_freeList(poll->options);
        poll->options = NULL;
    }
    if (poll->question_entities) {
        list_ForEach(listEntry, poll->question_entities) {
            message_entity_free(listEntry->data);
        }
        list_freeList(poll->question_entities);
        poll->question_entities = NULL;
    }
    if (poll->explanation) {
        free(poll->explanation);
        poll->explanation = NULL;
    }
    if (poll->explanation_entities) {
        list_ForEach(listEntry, poll->explanation_entities) {
            message_entity_free(listEntry->data);
        }
        list_freeList(poll->explanation_entities);
        poll->explanation_entities = NULL;
    }
    free(poll);
}

cJSON *poll_convertToJSON(poll_t *poll) {
    cJSON *item = cJSON_CreateObject();

    // poll->id
    if (!poll->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", poll->id) == NULL) {
    goto fail; //String
    }


    // poll->question
    if (!poll->question) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "question", poll->question) == NULL) {
    goto fail; //String
    }


    // poll->options
    if (!poll->options) {
        goto fail;
    }
    cJSON *options = cJSON_AddArrayToObject(item, "options");
    if(options == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *optionsListEntry;
    if (poll->options) {
    list_ForEach(optionsListEntry, poll->options) {
    cJSON *itemLocal = poll_option_convertToJSON(optionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(options, itemLocal);
    }
    }


    // poll->total_voter_count
    if (!poll->total_voter_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "total_voter_count", poll->total_voter_count) == NULL) {
    goto fail; //Numeric
    }


    // poll->is_closed
    if (!poll->is_closed) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "is_closed", poll->is_closed) == NULL) {
    goto fail; //Bool
    }


    // poll->is_anonymous
    if (!poll->is_anonymous) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "is_anonymous", poll->is_anonymous) == NULL) {
    goto fail; //Bool
    }


    // poll->type
    if (telegram_bot_api_poll_TYPE_NULL == poll->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", poll_type_ToString(poll->type)) == NULL)
    {
    goto fail; //Enum
    }


    // poll->allows_multiple_answers
    if (!poll->allows_multiple_answers) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "allows_multiple_answers", poll->allows_multiple_answers) == NULL) {
    goto fail; //Bool
    }


    // poll->question_entities
    if(poll->question_entities) {
    cJSON *question_entities = cJSON_AddArrayToObject(item, "question_entities");
    if(question_entities == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *question_entitiesListEntry;
    if (poll->question_entities) {
    list_ForEach(question_entitiesListEntry, poll->question_entities) {
    cJSON *itemLocal = message_entity_convertToJSON(question_entitiesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(question_entities, itemLocal);
    }
    }
    }


    // poll->correct_option_id
    if(poll->correct_option_id) {
    if(cJSON_AddNumberToObject(item, "correct_option_id", poll->correct_option_id) == NULL) {
    goto fail; //Numeric
    }
    }


    // poll->explanation
    if(poll->explanation) {
    if(cJSON_AddStringToObject(item, "explanation", poll->explanation) == NULL) {
    goto fail; //String
    }
    }


    // poll->explanation_entities
    if(poll->explanation_entities) {
    cJSON *explanation_entities = cJSON_AddArrayToObject(item, "explanation_entities");
    if(explanation_entities == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *explanation_entitiesListEntry;
    if (poll->explanation_entities) {
    list_ForEach(explanation_entitiesListEntry, poll->explanation_entities) {
    cJSON *itemLocal = message_entity_convertToJSON(explanation_entitiesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(explanation_entities, itemLocal);
    }
    }
    }


    // poll->open_period
    if(poll->open_period) {
    if(cJSON_AddNumberToObject(item, "open_period", poll->open_period) == NULL) {
    goto fail; //Numeric
    }
    }


    // poll->close_date
    if(poll->close_date) {
    if(cJSON_AddNumberToObject(item, "close_date", poll->close_date) == NULL) {
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

poll_t *poll_parseFromJSON(cJSON *pollJSON){

    poll_t *poll_local_var = NULL;

    // define the local list for poll->options
    list_t *optionsList = NULL;

    // define the local list for poll->question_entities
    list_t *question_entitiesList = NULL;

    // define the local list for poll->explanation_entities
    list_t *explanation_entitiesList = NULL;

    // poll->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(pollJSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (!id) {
        goto end;
    }

    
    if(!cJSON_IsString(id))
    {
    goto end; //String
    }

    // poll->question
    cJSON *question = cJSON_GetObjectItemCaseSensitive(pollJSON, "question");
    if (cJSON_IsNull(question)) {
        question = NULL;
    }
    if (!question) {
        goto end;
    }

    
    if(!cJSON_IsString(question))
    {
    goto end; //String
    }

    // poll->options
    cJSON *options = cJSON_GetObjectItemCaseSensitive(pollJSON, "options");
    if (cJSON_IsNull(options)) {
        options = NULL;
    }
    if (!options) {
        goto end;
    }

    
    cJSON *options_local_nonprimitive = NULL;
    if(!cJSON_IsArray(options)){
        goto end; //nonprimitive container
    }

    optionsList = list_createList();

    cJSON_ArrayForEach(options_local_nonprimitive,options )
    {
        if(!cJSON_IsObject(options_local_nonprimitive)){
            goto end;
        }
        poll_option_t *optionsItem = poll_option_parseFromJSON(options_local_nonprimitive);

        list_addElement(optionsList, optionsItem);
    }

    // poll->total_voter_count
    cJSON *total_voter_count = cJSON_GetObjectItemCaseSensitive(pollJSON, "total_voter_count");
    if (cJSON_IsNull(total_voter_count)) {
        total_voter_count = NULL;
    }
    if (!total_voter_count) {
        goto end;
    }

    
    if(!cJSON_IsNumber(total_voter_count))
    {
    goto end; //Numeric
    }

    // poll->is_closed
    cJSON *is_closed = cJSON_GetObjectItemCaseSensitive(pollJSON, "is_closed");
    if (cJSON_IsNull(is_closed)) {
        is_closed = NULL;
    }
    if (!is_closed) {
        goto end;
    }

    
    if(!cJSON_IsBool(is_closed))
    {
    goto end; //Bool
    }

    // poll->is_anonymous
    cJSON *is_anonymous = cJSON_GetObjectItemCaseSensitive(pollJSON, "is_anonymous");
    if (cJSON_IsNull(is_anonymous)) {
        is_anonymous = NULL;
    }
    if (!is_anonymous) {
        goto end;
    }

    
    if(!cJSON_IsBool(is_anonymous))
    {
    goto end; //Bool
    }

    // poll->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(pollJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    telegram_bot_api_poll_TYPE_e typeVariable;
    
    if(!cJSON_IsString(type))
    {
    goto end; //Enum
    }
    typeVariable = poll_type_FromString(type->valuestring);

    // poll->allows_multiple_answers
    cJSON *allows_multiple_answers = cJSON_GetObjectItemCaseSensitive(pollJSON, "allows_multiple_answers");
    if (cJSON_IsNull(allows_multiple_answers)) {
        allows_multiple_answers = NULL;
    }
    if (!allows_multiple_answers) {
        goto end;
    }

    
    if(!cJSON_IsBool(allows_multiple_answers))
    {
    goto end; //Bool
    }

    // poll->question_entities
    cJSON *question_entities = cJSON_GetObjectItemCaseSensitive(pollJSON, "question_entities");
    if (cJSON_IsNull(question_entities)) {
        question_entities = NULL;
    }
    if (question_entities) { 
    cJSON *question_entities_local_nonprimitive = NULL;
    if(!cJSON_IsArray(question_entities)){
        goto end; //nonprimitive container
    }

    question_entitiesList = list_createList();

    cJSON_ArrayForEach(question_entities_local_nonprimitive,question_entities )
    {
        if(!cJSON_IsObject(question_entities_local_nonprimitive)){
            goto end;
        }
        message_entity_t *question_entitiesItem = message_entity_parseFromJSON(question_entities_local_nonprimitive);

        list_addElement(question_entitiesList, question_entitiesItem);
    }
    }

    // poll->correct_option_id
    cJSON *correct_option_id = cJSON_GetObjectItemCaseSensitive(pollJSON, "correct_option_id");
    if (cJSON_IsNull(correct_option_id)) {
        correct_option_id = NULL;
    }
    if (correct_option_id) { 
    if(!cJSON_IsNumber(correct_option_id))
    {
    goto end; //Numeric
    }
    }

    // poll->explanation
    cJSON *explanation = cJSON_GetObjectItemCaseSensitive(pollJSON, "explanation");
    if (cJSON_IsNull(explanation)) {
        explanation = NULL;
    }
    if (explanation) { 
    if(!cJSON_IsString(explanation) && !cJSON_IsNull(explanation))
    {
    goto end; //String
    }
    }

    // poll->explanation_entities
    cJSON *explanation_entities = cJSON_GetObjectItemCaseSensitive(pollJSON, "explanation_entities");
    if (cJSON_IsNull(explanation_entities)) {
        explanation_entities = NULL;
    }
    if (explanation_entities) { 
    cJSON *explanation_entities_local_nonprimitive = NULL;
    if(!cJSON_IsArray(explanation_entities)){
        goto end; //nonprimitive container
    }

    explanation_entitiesList = list_createList();

    cJSON_ArrayForEach(explanation_entities_local_nonprimitive,explanation_entities )
    {
        if(!cJSON_IsObject(explanation_entities_local_nonprimitive)){
            goto end;
        }
        message_entity_t *explanation_entitiesItem = message_entity_parseFromJSON(explanation_entities_local_nonprimitive);

        list_addElement(explanation_entitiesList, explanation_entitiesItem);
    }
    }

    // poll->open_period
    cJSON *open_period = cJSON_GetObjectItemCaseSensitive(pollJSON, "open_period");
    if (cJSON_IsNull(open_period)) {
        open_period = NULL;
    }
    if (open_period) { 
    if(!cJSON_IsNumber(open_period))
    {
    goto end; //Numeric
    }
    }

    // poll->close_date
    cJSON *close_date = cJSON_GetObjectItemCaseSensitive(pollJSON, "close_date");
    if (cJSON_IsNull(close_date)) {
        close_date = NULL;
    }
    if (close_date) { 
    if(!cJSON_IsNumber(close_date))
    {
    goto end; //Numeric
    }
    }


    poll_local_var = poll_create_internal (
        strdup(id->valuestring),
        strdup(question->valuestring),
        optionsList,
        total_voter_count->valuedouble,
        is_closed->valueint,
        is_anonymous->valueint,
        typeVariable,
        allows_multiple_answers->valueint,
        question_entities ? question_entitiesList : NULL,
        correct_option_id ? correct_option_id->valuedouble : 0,
        explanation && !cJSON_IsNull(explanation) ? strdup(explanation->valuestring) : NULL,
        explanation_entities ? explanation_entitiesList : NULL,
        open_period ? open_period->valuedouble : 0,
        close_date ? close_date->valuedouble : 0
        );

    return poll_local_var;
end:
    if (optionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, optionsList) {
            poll_option_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(optionsList);
        optionsList = NULL;
    }
    if (question_entitiesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, question_entitiesList) {
            message_entity_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(question_entitiesList);
        question_entitiesList = NULL;
    }
    if (explanation_entitiesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, explanation_entitiesList) {
            message_entity_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(explanation_entitiesList);
        explanation_entitiesList = NULL;
    }
    return NULL;

}
