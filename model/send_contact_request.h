/*
 * send_contact_request.h
 *
 * Request parameters for sendContact
 */

#ifndef _send_contact_request_H_
#define _send_contact_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct send_contact_request_t send_contact_request_t;

#include "reply_parameters.h"
#include "send_message_request_chat_id.h"
#include "send_message_request_reply_markup.h"



typedef struct send_contact_request_t {
    struct send_message_request_chat_id_t *chat_id; //model
    char *phone_number; // string
    char *first_name; // string
    char *business_connection_id; // string
    int message_thread_id; //numeric
    char *last_name; // string
    char *vcard; // string
    int disable_notification; //boolean
    int protect_content; //boolean
    int allow_paid_broadcast; //boolean
    char *message_effect_id; // string
    struct reply_parameters_t *reply_parameters; //model
    struct send_message_request_reply_markup_t *reply_markup; //model

    int _library_owned; // Is the library responsible for freeing this object?
} send_contact_request_t;

__attribute__((deprecated)) send_contact_request_t *send_contact_request_create(
    send_message_request_chat_id_t *chat_id,
    char *phone_number,
    char *first_name,
    char *business_connection_id,
    int message_thread_id,
    char *last_name,
    char *vcard,
    int disable_notification,
    int protect_content,
    int allow_paid_broadcast,
    char *message_effect_id,
    reply_parameters_t *reply_parameters,
    send_message_request_reply_markup_t *reply_markup
);

void send_contact_request_free(send_contact_request_t *send_contact_request);

send_contact_request_t *send_contact_request_parseFromJSON(cJSON *send_contact_requestJSON);

cJSON *send_contact_request_convertToJSON(send_contact_request_t *send_contact_request);

#endif /* _send_contact_request_H_ */

