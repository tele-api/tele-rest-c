/*
 * message_auto_delete_timer_changed.h
 *
 * This object represents a service message about a change in auto-delete timer settings.
 */

#ifndef _message_auto_delete_timer_changed_H_
#define _message_auto_delete_timer_changed_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct message_auto_delete_timer_changed_t message_auto_delete_timer_changed_t;




typedef struct message_auto_delete_timer_changed_t {
    int message_auto_delete_time; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} message_auto_delete_timer_changed_t;

__attribute__((deprecated)) message_auto_delete_timer_changed_t *message_auto_delete_timer_changed_create(
    int message_auto_delete_time
);

void message_auto_delete_timer_changed_free(message_auto_delete_timer_changed_t *message_auto_delete_timer_changed);

message_auto_delete_timer_changed_t *message_auto_delete_timer_changed_parseFromJSON(cJSON *message_auto_delete_timer_changedJSON);

cJSON *message_auto_delete_timer_changed_convertToJSON(message_auto_delete_timer_changed_t *message_auto_delete_timer_changed);

#endif /* _message_auto_delete_timer_changed_H_ */

