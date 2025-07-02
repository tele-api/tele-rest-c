/*
 * edit_user_star_subscription_response.h
 *
 * 
 */

#ifndef _edit_user_star_subscription_response_H_
#define _edit_user_star_subscription_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct edit_user_star_subscription_response_t edit_user_star_subscription_response_t;




typedef struct edit_user_star_subscription_response_t {
    int ok; //boolean
    int result; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} edit_user_star_subscription_response_t;

__attribute__((deprecated)) edit_user_star_subscription_response_t *edit_user_star_subscription_response_create(
    int ok,
    int result
);

void edit_user_star_subscription_response_free(edit_user_star_subscription_response_t *edit_user_star_subscription_response);

edit_user_star_subscription_response_t *edit_user_star_subscription_response_parseFromJSON(cJSON *edit_user_star_subscription_responseJSON);

cJSON *edit_user_star_subscription_response_convertToJSON(edit_user_star_subscription_response_t *edit_user_star_subscription_response);

#endif /* _edit_user_star_subscription_response_H_ */

