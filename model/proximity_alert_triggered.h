/*
 * proximity_alert_triggered.h
 *
 * This object represents the content of a service message, sent whenever a user in the chat triggers a proximity alert set by another user.
 */

#ifndef _proximity_alert_triggered_H_
#define _proximity_alert_triggered_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct proximity_alert_triggered_t proximity_alert_triggered_t;

#include "user.h"



typedef struct proximity_alert_triggered_t {
    struct user_t *traveler; //model
    struct user_t *watcher; //model
    int distance; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} proximity_alert_triggered_t;

__attribute__((deprecated)) proximity_alert_triggered_t *proximity_alert_triggered_create(
    user_t *traveler,
    user_t *watcher,
    int distance
);

void proximity_alert_triggered_free(proximity_alert_triggered_t *proximity_alert_triggered);

proximity_alert_triggered_t *proximity_alert_triggered_parseFromJSON(cJSON *proximity_alert_triggeredJSON);

cJSON *proximity_alert_triggered_convertToJSON(proximity_alert_triggered_t *proximity_alert_triggered);

#endif /* _proximity_alert_triggered_H_ */

