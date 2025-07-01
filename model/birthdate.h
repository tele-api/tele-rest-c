/*
 * birthdate.h
 *
 * Describes the birthdate of a user.
 */

#ifndef _birthdate_H_
#define _birthdate_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct birthdate_t birthdate_t;




typedef struct birthdate_t {
    int day; //numeric
    int month; //numeric
    int year; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} birthdate_t;

__attribute__((deprecated)) birthdate_t *birthdate_create(
    int day,
    int month,
    int year
);

void birthdate_free(birthdate_t *birthdate);

birthdate_t *birthdate_parseFromJSON(cJSON *birthdateJSON);

cJSON *birthdate_convertToJSON(birthdate_t *birthdate);

#endif /* _birthdate_H_ */

