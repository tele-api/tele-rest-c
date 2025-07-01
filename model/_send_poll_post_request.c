#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_send_poll_post_request.h"


char* _send_poll_post_request_type_ToString(telegram_bot_api__send_poll_post_request_TYPE_e type) {
    char* typeArray[] =  { "NULL", "quiz", "regular" };
    return typeArray[type];
}

telegram_bot_api__send_poll_post_request_TYPE_e _send_poll_post_request_type_FromString(char* type){
    int stringToReturn = 0;
    char *typeArray[] =  { "NULL", "quiz", "regular" };
    size_t sizeofArray = sizeof(typeArray) / sizeof(typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(type, typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static _send_poll_post_request_t *_send_poll_post_request_create_internal(
    _send_message_post_request_chat_id_t *chat_id,
    char *question,
    list_t *options,
    char *business_connection_id,
    int message_thread_id,
    char *question_parse_mode,
    list_t *question_entities,
    int is_anonymous,
    telegram_bot_api__send_poll_post_request_TYPE_e type,
    int allows_multiple_answers,
    int correct_option_id,
    char *explanation,
    char *explanation_parse_mode,
    list_t *explanation_entities,
    int open_period,
    int close_date,
    int is_closed,
    int disable_notification,
    int protect_content,
    int allow_paid_broadcast,
    char *message_effect_id,
    reply_parameters_t *reply_parameters,
    _send_message_post_request_reply_markup_t *reply_markup
    ) {
    _send_poll_post_request_t *_send_poll_post_request_local_var = malloc(sizeof(_send_poll_post_request_t));
    if (!_send_poll_post_request_local_var) {
        return NULL;
    }
    _send_poll_post_request_local_var->chat_id = chat_id;
    _send_poll_post_request_local_var->question = question;
    _send_poll_post_request_local_var->options = options;
    _send_poll_post_request_local_var->business_connection_id = business_connection_id;
    _send_poll_post_request_local_var->message_thread_id = message_thread_id;
    _send_poll_post_request_local_var->question_parse_mode = question_parse_mode;
    _send_poll_post_request_local_var->question_entities = question_entities;
    _send_poll_post_request_local_var->is_anonymous = is_anonymous;
    _send_poll_post_request_local_var->type = type;
    _send_poll_post_request_local_var->allows_multiple_answers = allows_multiple_answers;
    _send_poll_post_request_local_var->correct_option_id = correct_option_id;
    _send_poll_post_request_local_var->explanation = explanation;
    _send_poll_post_request_local_var->explanation_parse_mode = explanation_parse_mode;
    _send_poll_post_request_local_var->explanation_entities = explanation_entities;
    _send_poll_post_request_local_var->open_period = open_period;
    _send_poll_post_request_local_var->close_date = close_date;
    _send_poll_post_request_local_var->is_closed = is_closed;
    _send_poll_post_request_local_var->disable_notification = disable_notification;
    _send_poll_post_request_local_var->protect_content = protect_content;
    _send_poll_post_request_local_var->allow_paid_broadcast = allow_paid_broadcast;
    _send_poll_post_request_local_var->message_effect_id = message_effect_id;
    _send_poll_post_request_local_var->reply_parameters = reply_parameters;
    _send_poll_post_request_local_var->reply_markup = reply_markup;

    _send_poll_post_request_local_var->_library_owned = 1;
    return _send_poll_post_request_local_var;
}

__attribute__((deprecated)) _send_poll_post_request_t *_send_poll_post_request_create(
    _send_message_post_request_chat_id_t *chat_id,
    char *question,
    list_t *options,
    char *business_connection_id,
    int message_thread_id,
    char *question_parse_mode,
    list_t *question_entities,
    int is_anonymous,
    telegram_bot_api__send_poll_post_request_TYPE_e type,
    int allows_multiple_answers,
    int correct_option_id,
    char *explanation,
    char *explanation_parse_mode,
    list_t *explanation_entities,
    int open_period,
    int close_date,
    int is_closed,
    int disable_notification,
    int protect_content,
    int allow_paid_broadcast,
    char *message_effect_id,
    reply_parameters_t *reply_parameters,
    _send_message_post_request_reply_markup_t *reply_markup
    ) {
    return _send_poll_post_request_create_internal (
        chat_id,
        question,
        options,
        business_connection_id,
        message_thread_id,
        question_parse_mode,
        question_entities,
        is_anonymous,
        type,
        allows_multiple_answers,
        correct_option_id,
        explanation,
        explanation_parse_mode,
        explanation_entities,
        open_period,
        close_date,
        is_closed,
        disable_notification,
        protect_content,
        allow_paid_broadcast,
        message_effect_id,
        reply_parameters,
        reply_markup
        );
}

void _send_poll_post_request_free(_send_poll_post_request_t *_send_poll_post_request) {
    if(NULL == _send_poll_post_request){
        return ;
    }
    if(_send_poll_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_send_poll_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_send_poll_post_request->chat_id) {
        _send_message_post_request_chat_id_free(_send_poll_post_request->chat_id);
        _send_poll_post_request->chat_id = NULL;
    }
    if (_send_poll_post_request->question) {
        free(_send_poll_post_request->question);
        _send_poll_post_request->question = NULL;
    }
    if (_send_poll_post_request->options) {
        list_ForEach(listEntry, _send_poll_post_request->options) {
            input_poll_option_free(listEntry->data);
        }
        list_freeList(_send_poll_post_request->options);
        _send_poll_post_request->options = NULL;
    }
    if (_send_poll_post_request->business_connection_id) {
        free(_send_poll_post_request->business_connection_id);
        _send_poll_post_request->business_connection_id = NULL;
    }
    if (_send_poll_post_request->question_parse_mode) {
        free(_send_poll_post_request->question_parse_mode);
        _send_poll_post_request->question_parse_mode = NULL;
    }
    if (_send_poll_post_request->question_entities) {
        list_ForEach(listEntry, _send_poll_post_request->question_entities) {
            message_entity_free(listEntry->data);
        }
        list_freeList(_send_poll_post_request->question_entities);
        _send_poll_post_request->question_entities = NULL;
    }
    if (_send_poll_post_request->explanation) {
        free(_send_poll_post_request->explanation);
        _send_poll_post_request->explanation = NULL;
    }
    if (_send_poll_post_request->explanation_parse_mode) {
        free(_send_poll_post_request->explanation_parse_mode);
        _send_poll_post_request->explanation_parse_mode = NULL;
    }
    if (_send_poll_post_request->explanation_entities) {
        list_ForEach(listEntry, _send_poll_post_request->explanation_entities) {
            message_entity_free(listEntry->data);
        }
        list_freeList(_send_poll_post_request->explanation_entities);
        _send_poll_post_request->explanation_entities = NULL;
    }
    if (_send_poll_post_request->message_effect_id) {
        free(_send_poll_post_request->message_effect_id);
        _send_poll_post_request->message_effect_id = NULL;
    }
    if (_send_poll_post_request->reply_parameters) {
        reply_parameters_free(_send_poll_post_request->reply_parameters);
        _send_poll_post_request->reply_parameters = NULL;
    }
    if (_send_poll_post_request->reply_markup) {
        _send_message_post_request_reply_markup_free(_send_poll_post_request->reply_markup);
        _send_poll_post_request->reply_markup = NULL;
    }
    free(_send_poll_post_request);
}

cJSON *_send_poll_post_request_convertToJSON(_send_poll_post_request_t *_send_poll_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _send_poll_post_request->chat_id
    if (!_send_poll_post_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = _send_message_post_request_chat_id_convertToJSON(_send_poll_post_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // _send_poll_post_request->question
    if (!_send_poll_post_request->question) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "question", _send_poll_post_request->question) == NULL) {
    goto fail; //String
    }


    // _send_poll_post_request->options
    if (!_send_poll_post_request->options) {
        goto fail;
    }
    cJSON *options = cJSON_AddArrayToObject(item, "options");
    if(options == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *optionsListEntry;
    if (_send_poll_post_request->options) {
    list_ForEach(optionsListEntry, _send_poll_post_request->options) {
    cJSON *itemLocal = input_poll_option_convertToJSON(optionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(options, itemLocal);
    }
    }


    // _send_poll_post_request->business_connection_id
    if(_send_poll_post_request->business_connection_id) {
    if(cJSON_AddStringToObject(item, "business_connection_id", _send_poll_post_request->business_connection_id) == NULL) {
    goto fail; //String
    }
    }


    // _send_poll_post_request->message_thread_id
    if(_send_poll_post_request->message_thread_id) {
    if(cJSON_AddNumberToObject(item, "message_thread_id", _send_poll_post_request->message_thread_id) == NULL) {
    goto fail; //Numeric
    }
    }


    // _send_poll_post_request->question_parse_mode
    if(_send_poll_post_request->question_parse_mode) {
    if(cJSON_AddStringToObject(item, "question_parse_mode", _send_poll_post_request->question_parse_mode) == NULL) {
    goto fail; //String
    }
    }


    // _send_poll_post_request->question_entities
    if(_send_poll_post_request->question_entities) {
    cJSON *question_entities = cJSON_AddArrayToObject(item, "question_entities");
    if(question_entities == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *question_entitiesListEntry;
    if (_send_poll_post_request->question_entities) {
    list_ForEach(question_entitiesListEntry, _send_poll_post_request->question_entities) {
    cJSON *itemLocal = message_entity_convertToJSON(question_entitiesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(question_entities, itemLocal);
    }
    }
    }


    // _send_poll_post_request->is_anonymous
    if(_send_poll_post_request->is_anonymous) {
    if(cJSON_AddBoolToObject(item, "is_anonymous", _send_poll_post_request->is_anonymous) == NULL) {
    goto fail; //Bool
    }
    }


    // _send_poll_post_request->type
    if(_send_poll_post_request->type != telegram_bot_api__send_poll_post_request_TYPE_NULL) {
    if(cJSON_AddStringToObject(item, "type", _send_poll_post_request_type_ToString(_send_poll_post_request->type)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // _send_poll_post_request->allows_multiple_answers
    if(_send_poll_post_request->allows_multiple_answers) {
    if(cJSON_AddBoolToObject(item, "allows_multiple_answers", _send_poll_post_request->allows_multiple_answers) == NULL) {
    goto fail; //Bool
    }
    }


    // _send_poll_post_request->correct_option_id
    if(_send_poll_post_request->correct_option_id) {
    if(cJSON_AddNumberToObject(item, "correct_option_id", _send_poll_post_request->correct_option_id) == NULL) {
    goto fail; //Numeric
    }
    }


    // _send_poll_post_request->explanation
    if(_send_poll_post_request->explanation) {
    if(cJSON_AddStringToObject(item, "explanation", _send_poll_post_request->explanation) == NULL) {
    goto fail; //String
    }
    }


    // _send_poll_post_request->explanation_parse_mode
    if(_send_poll_post_request->explanation_parse_mode) {
    if(cJSON_AddStringToObject(item, "explanation_parse_mode", _send_poll_post_request->explanation_parse_mode) == NULL) {
    goto fail; //String
    }
    }


    // _send_poll_post_request->explanation_entities
    if(_send_poll_post_request->explanation_entities) {
    cJSON *explanation_entities = cJSON_AddArrayToObject(item, "explanation_entities");
    if(explanation_entities == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *explanation_entitiesListEntry;
    if (_send_poll_post_request->explanation_entities) {
    list_ForEach(explanation_entitiesListEntry, _send_poll_post_request->explanation_entities) {
    cJSON *itemLocal = message_entity_convertToJSON(explanation_entitiesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(explanation_entities, itemLocal);
    }
    }
    }


    // _send_poll_post_request->open_period
    if(_send_poll_post_request->open_period) {
    if(cJSON_AddNumberToObject(item, "open_period", _send_poll_post_request->open_period) == NULL) {
    goto fail; //Numeric
    }
    }


    // _send_poll_post_request->close_date
    if(_send_poll_post_request->close_date) {
    if(cJSON_AddNumberToObject(item, "close_date", _send_poll_post_request->close_date) == NULL) {
    goto fail; //Numeric
    }
    }


    // _send_poll_post_request->is_closed
    if(_send_poll_post_request->is_closed) {
    if(cJSON_AddBoolToObject(item, "is_closed", _send_poll_post_request->is_closed) == NULL) {
    goto fail; //Bool
    }
    }


    // _send_poll_post_request->disable_notification
    if(_send_poll_post_request->disable_notification) {
    if(cJSON_AddBoolToObject(item, "disable_notification", _send_poll_post_request->disable_notification) == NULL) {
    goto fail; //Bool
    }
    }


    // _send_poll_post_request->protect_content
    if(_send_poll_post_request->protect_content) {
    if(cJSON_AddBoolToObject(item, "protect_content", _send_poll_post_request->protect_content) == NULL) {
    goto fail; //Bool
    }
    }


    // _send_poll_post_request->allow_paid_broadcast
    if(_send_poll_post_request->allow_paid_broadcast) {
    if(cJSON_AddBoolToObject(item, "allow_paid_broadcast", _send_poll_post_request->allow_paid_broadcast) == NULL) {
    goto fail; //Bool
    }
    }


    // _send_poll_post_request->message_effect_id
    if(_send_poll_post_request->message_effect_id) {
    if(cJSON_AddStringToObject(item, "message_effect_id", _send_poll_post_request->message_effect_id) == NULL) {
    goto fail; //String
    }
    }


    // _send_poll_post_request->reply_parameters
    if(_send_poll_post_request->reply_parameters) {
    cJSON *reply_parameters_local_JSON = reply_parameters_convertToJSON(_send_poll_post_request->reply_parameters);
    if(reply_parameters_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "reply_parameters", reply_parameters_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // _send_poll_post_request->reply_markup
    if(_send_poll_post_request->reply_markup) {
    cJSON *reply_markup_local_JSON = _send_message_post_request_reply_markup_convertToJSON(_send_poll_post_request->reply_markup);
    if(reply_markup_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "reply_markup", reply_markup_local_JSON);
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

_send_poll_post_request_t *_send_poll_post_request_parseFromJSON(cJSON *_send_poll_post_requestJSON){

    _send_poll_post_request_t *_send_poll_post_request_local_var = NULL;

    // define the local variable for _send_poll_post_request->chat_id
    _send_message_post_request_chat_id_t *chat_id_local_nonprim = NULL;

    // define the local list for _send_poll_post_request->options
    list_t *optionsList = NULL;

    // define the local list for _send_poll_post_request->question_entities
    list_t *question_entitiesList = NULL;

    // define the local list for _send_poll_post_request->explanation_entities
    list_t *explanation_entitiesList = NULL;

    // define the local variable for _send_poll_post_request->reply_parameters
    reply_parameters_t *reply_parameters_local_nonprim = NULL;

    // define the local variable for _send_poll_post_request->reply_markup
    _send_message_post_request_reply_markup_t *reply_markup_local_nonprim = NULL;

    // _send_poll_post_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(_send_poll_post_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = _send_message_post_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // _send_poll_post_request->question
    cJSON *question = cJSON_GetObjectItemCaseSensitive(_send_poll_post_requestJSON, "question");
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

    // _send_poll_post_request->options
    cJSON *options = cJSON_GetObjectItemCaseSensitive(_send_poll_post_requestJSON, "options");
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
        input_poll_option_t *optionsItem = input_poll_option_parseFromJSON(options_local_nonprimitive);

        list_addElement(optionsList, optionsItem);
    }

    // _send_poll_post_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(_send_poll_post_requestJSON, "business_connection_id");
    if (cJSON_IsNull(business_connection_id)) {
        business_connection_id = NULL;
    }
    if (business_connection_id) { 
    if(!cJSON_IsString(business_connection_id) && !cJSON_IsNull(business_connection_id))
    {
    goto end; //String
    }
    }

    // _send_poll_post_request->message_thread_id
    cJSON *message_thread_id = cJSON_GetObjectItemCaseSensitive(_send_poll_post_requestJSON, "message_thread_id");
    if (cJSON_IsNull(message_thread_id)) {
        message_thread_id = NULL;
    }
    if (message_thread_id) { 
    if(!cJSON_IsNumber(message_thread_id))
    {
    goto end; //Numeric
    }
    }

    // _send_poll_post_request->question_parse_mode
    cJSON *question_parse_mode = cJSON_GetObjectItemCaseSensitive(_send_poll_post_requestJSON, "question_parse_mode");
    if (cJSON_IsNull(question_parse_mode)) {
        question_parse_mode = NULL;
    }
    if (question_parse_mode) { 
    if(!cJSON_IsString(question_parse_mode) && !cJSON_IsNull(question_parse_mode))
    {
    goto end; //String
    }
    }

    // _send_poll_post_request->question_entities
    cJSON *question_entities = cJSON_GetObjectItemCaseSensitive(_send_poll_post_requestJSON, "question_entities");
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

    // _send_poll_post_request->is_anonymous
    cJSON *is_anonymous = cJSON_GetObjectItemCaseSensitive(_send_poll_post_requestJSON, "is_anonymous");
    if (cJSON_IsNull(is_anonymous)) {
        is_anonymous = NULL;
    }
    if (is_anonymous) { 
    if(!cJSON_IsBool(is_anonymous))
    {
    goto end; //Bool
    }
    }

    // _send_poll_post_request->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(_send_poll_post_requestJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    telegram_bot_api__send_poll_post_request_TYPE_e typeVariable;
    if (type) { 
    if(!cJSON_IsString(type))
    {
    goto end; //Enum
    }
    typeVariable = _send_poll_post_request_type_FromString(type->valuestring);
    }

    // _send_poll_post_request->allows_multiple_answers
    cJSON *allows_multiple_answers = cJSON_GetObjectItemCaseSensitive(_send_poll_post_requestJSON, "allows_multiple_answers");
    if (cJSON_IsNull(allows_multiple_answers)) {
        allows_multiple_answers = NULL;
    }
    if (allows_multiple_answers) { 
    if(!cJSON_IsBool(allows_multiple_answers))
    {
    goto end; //Bool
    }
    }

    // _send_poll_post_request->correct_option_id
    cJSON *correct_option_id = cJSON_GetObjectItemCaseSensitive(_send_poll_post_requestJSON, "correct_option_id");
    if (cJSON_IsNull(correct_option_id)) {
        correct_option_id = NULL;
    }
    if (correct_option_id) { 
    if(!cJSON_IsNumber(correct_option_id))
    {
    goto end; //Numeric
    }
    }

    // _send_poll_post_request->explanation
    cJSON *explanation = cJSON_GetObjectItemCaseSensitive(_send_poll_post_requestJSON, "explanation");
    if (cJSON_IsNull(explanation)) {
        explanation = NULL;
    }
    if (explanation) { 
    if(!cJSON_IsString(explanation) && !cJSON_IsNull(explanation))
    {
    goto end; //String
    }
    }

    // _send_poll_post_request->explanation_parse_mode
    cJSON *explanation_parse_mode = cJSON_GetObjectItemCaseSensitive(_send_poll_post_requestJSON, "explanation_parse_mode");
    if (cJSON_IsNull(explanation_parse_mode)) {
        explanation_parse_mode = NULL;
    }
    if (explanation_parse_mode) { 
    if(!cJSON_IsString(explanation_parse_mode) && !cJSON_IsNull(explanation_parse_mode))
    {
    goto end; //String
    }
    }

    // _send_poll_post_request->explanation_entities
    cJSON *explanation_entities = cJSON_GetObjectItemCaseSensitive(_send_poll_post_requestJSON, "explanation_entities");
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

    // _send_poll_post_request->open_period
    cJSON *open_period = cJSON_GetObjectItemCaseSensitive(_send_poll_post_requestJSON, "open_period");
    if (cJSON_IsNull(open_period)) {
        open_period = NULL;
    }
    if (open_period) { 
    if(!cJSON_IsNumber(open_period))
    {
    goto end; //Numeric
    }
    }

    // _send_poll_post_request->close_date
    cJSON *close_date = cJSON_GetObjectItemCaseSensitive(_send_poll_post_requestJSON, "close_date");
    if (cJSON_IsNull(close_date)) {
        close_date = NULL;
    }
    if (close_date) { 
    if(!cJSON_IsNumber(close_date))
    {
    goto end; //Numeric
    }
    }

    // _send_poll_post_request->is_closed
    cJSON *is_closed = cJSON_GetObjectItemCaseSensitive(_send_poll_post_requestJSON, "is_closed");
    if (cJSON_IsNull(is_closed)) {
        is_closed = NULL;
    }
    if (is_closed) { 
    if(!cJSON_IsBool(is_closed))
    {
    goto end; //Bool
    }
    }

    // _send_poll_post_request->disable_notification
    cJSON *disable_notification = cJSON_GetObjectItemCaseSensitive(_send_poll_post_requestJSON, "disable_notification");
    if (cJSON_IsNull(disable_notification)) {
        disable_notification = NULL;
    }
    if (disable_notification) { 
    if(!cJSON_IsBool(disable_notification))
    {
    goto end; //Bool
    }
    }

    // _send_poll_post_request->protect_content
    cJSON *protect_content = cJSON_GetObjectItemCaseSensitive(_send_poll_post_requestJSON, "protect_content");
    if (cJSON_IsNull(protect_content)) {
        protect_content = NULL;
    }
    if (protect_content) { 
    if(!cJSON_IsBool(protect_content))
    {
    goto end; //Bool
    }
    }

    // _send_poll_post_request->allow_paid_broadcast
    cJSON *allow_paid_broadcast = cJSON_GetObjectItemCaseSensitive(_send_poll_post_requestJSON, "allow_paid_broadcast");
    if (cJSON_IsNull(allow_paid_broadcast)) {
        allow_paid_broadcast = NULL;
    }
    if (allow_paid_broadcast) { 
    if(!cJSON_IsBool(allow_paid_broadcast))
    {
    goto end; //Bool
    }
    }

    // _send_poll_post_request->message_effect_id
    cJSON *message_effect_id = cJSON_GetObjectItemCaseSensitive(_send_poll_post_requestJSON, "message_effect_id");
    if (cJSON_IsNull(message_effect_id)) {
        message_effect_id = NULL;
    }
    if (message_effect_id) { 
    if(!cJSON_IsString(message_effect_id) && !cJSON_IsNull(message_effect_id))
    {
    goto end; //String
    }
    }

    // _send_poll_post_request->reply_parameters
    cJSON *reply_parameters = cJSON_GetObjectItemCaseSensitive(_send_poll_post_requestJSON, "reply_parameters");
    if (cJSON_IsNull(reply_parameters)) {
        reply_parameters = NULL;
    }
    if (reply_parameters) { 
    reply_parameters_local_nonprim = reply_parameters_parseFromJSON(reply_parameters); //nonprimitive
    }

    // _send_poll_post_request->reply_markup
    cJSON *reply_markup = cJSON_GetObjectItemCaseSensitive(_send_poll_post_requestJSON, "reply_markup");
    if (cJSON_IsNull(reply_markup)) {
        reply_markup = NULL;
    }
    if (reply_markup) { 
    reply_markup_local_nonprim = _send_message_post_request_reply_markup_parseFromJSON(reply_markup); //nonprimitive
    }


    _send_poll_post_request_local_var = _send_poll_post_request_create_internal (
        chat_id_local_nonprim,
        strdup(question->valuestring),
        optionsList,
        business_connection_id && !cJSON_IsNull(business_connection_id) ? strdup(business_connection_id->valuestring) : NULL,
        message_thread_id ? message_thread_id->valuedouble : 0,
        question_parse_mode && !cJSON_IsNull(question_parse_mode) ? strdup(question_parse_mode->valuestring) : NULL,
        question_entities ? question_entitiesList : NULL,
        is_anonymous ? is_anonymous->valueint : 0,
        type ? typeVariable : telegram_bot_api__send_poll_post_request_TYPE_NULL,
        allows_multiple_answers ? allows_multiple_answers->valueint : 0,
        correct_option_id ? correct_option_id->valuedouble : 0,
        explanation && !cJSON_IsNull(explanation) ? strdup(explanation->valuestring) : NULL,
        explanation_parse_mode && !cJSON_IsNull(explanation_parse_mode) ? strdup(explanation_parse_mode->valuestring) : NULL,
        explanation_entities ? explanation_entitiesList : NULL,
        open_period ? open_period->valuedouble : 0,
        close_date ? close_date->valuedouble : 0,
        is_closed ? is_closed->valueint : 0,
        disable_notification ? disable_notification->valueint : 0,
        protect_content ? protect_content->valueint : 0,
        allow_paid_broadcast ? allow_paid_broadcast->valueint : 0,
        message_effect_id && !cJSON_IsNull(message_effect_id) ? strdup(message_effect_id->valuestring) : NULL,
        reply_parameters ? reply_parameters_local_nonprim : NULL,
        reply_markup ? reply_markup_local_nonprim : NULL
        );

    return _send_poll_post_request_local_var;
end:
    if (chat_id_local_nonprim) {
        _send_message_post_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    if (optionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, optionsList) {
            input_poll_option_free(listEntry->data);
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
    if (reply_parameters_local_nonprim) {
        reply_parameters_free(reply_parameters_local_nonprim);
        reply_parameters_local_nonprim = NULL;
    }
    if (reply_markup_local_nonprim) {
        _send_message_post_request_reply_markup_free(reply_markup_local_nonprim);
        reply_markup_local_nonprim = NULL;
    }
    return NULL;

}
