/*
 * post_story_request.h
 *
 * Request parameters for postStory
 */

#ifndef _post_story_request_H_
#define _post_story_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_story_request_t post_story_request_t;

#include "input_story_content.h"
#include "message_entity.h"
#include "story_area.h"

// Enum ACTIVEPERIOD for post_story_request

typedef enum  { telegram_bot_api_post_story_request_ACTIVEPERIOD_NULL = 0, telegram_bot_api_post_story_request_ACTIVEPERIOD__86400 } telegram_bot_api_post_story_request_ACTIVEPERIOD_e;

char* post_story_request_active_period_ToString(telegram_bot_api_post_story_request_ACTIVEPERIOD_e active_period);

telegram_bot_api_post_story_request_ACTIVEPERIOD_e post_story_request_active_period_FromString(char* active_period);



typedef struct post_story_request_t {
    char *business_connection_id; // string
    struct input_story_content_t *content; //model
    int active_period; //numeric
    char *caption; // string
    char *parse_mode; // string
    list_t *caption_entities; //nonprimitive container
    list_t *areas; //nonprimitive container
    int post_to_chat_page; //boolean
    int protect_content; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} post_story_request_t;

__attribute__((deprecated)) post_story_request_t *post_story_request_create(
    char *business_connection_id,
    input_story_content_t *content,
    int active_period,
    char *caption,
    char *parse_mode,
    list_t *caption_entities,
    list_t *areas,
    int post_to_chat_page,
    int protect_content
);

void post_story_request_free(post_story_request_t *post_story_request);

post_story_request_t *post_story_request_parseFromJSON(cJSON *post_story_requestJSON);

cJSON *post_story_request_convertToJSON(post_story_request_t *post_story_request);

#endif /* _post_story_request_H_ */

