/*
 * poll_answer.h
 *
 * This object represents an answer of a user in a non-anonymous poll.
 */

#ifndef _poll_answer_H_
#define _poll_answer_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct poll_answer_t poll_answer_t;

#include "chat.h"
#include "user.h"



typedef struct poll_answer_t {
    char *poll_id; // string
    list_t *option_ids; //primitive container
    struct chat_t *voter_chat; //model
    struct user_t *user; //model

    int _library_owned; // Is the library responsible for freeing this object?
} poll_answer_t;

__attribute__((deprecated)) poll_answer_t *poll_answer_create(
    char *poll_id,
    list_t *option_ids,
    chat_t *voter_chat,
    user_t *user
);

void poll_answer_free(poll_answer_t *poll_answer);

poll_answer_t *poll_answer_parseFromJSON(cJSON *poll_answerJSON);

cJSON *poll_answer_convertToJSON(poll_answer_t *poll_answer);

#endif /* _poll_answer_H_ */

