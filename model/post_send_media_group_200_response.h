/*
 * post_send_media_group_200_response.h
 *
 * 
 */

#ifndef _post_send_media_group_200_response_H_
#define _post_send_media_group_200_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_send_media_group_200_response_t post_send_media_group_200_response_t;

#include "message.h"



typedef struct post_send_media_group_200_response_t {
    int ok; //boolean
    list_t *result; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} post_send_media_group_200_response_t;

__attribute__((deprecated)) post_send_media_group_200_response_t *post_send_media_group_200_response_create(
    int ok,
    list_t *result
);

void post_send_media_group_200_response_free(post_send_media_group_200_response_t *post_send_media_group_200_response);

post_send_media_group_200_response_t *post_send_media_group_200_response_parseFromJSON(cJSON *post_send_media_group_200_responseJSON);

cJSON *post_send_media_group_200_response_convertToJSON(post_send_media_group_200_response_t *post_send_media_group_200_response);

#endif /* _post_send_media_group_200_response_H_ */

