/*
 * contact.h
 *
 * This object represents a phone contact.
 */

#ifndef _contact_H_
#define _contact_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct contact_t contact_t;




typedef struct contact_t {
    char *phone_number; // string
    char *first_name; // string
    char *last_name; // string
    int user_id; //numeric
    char *vcard; // string

    int _library_owned; // Is the library responsible for freeing this object?
} contact_t;

__attribute__((deprecated)) contact_t *contact_create(
    char *phone_number,
    char *first_name,
    char *last_name,
    int user_id,
    char *vcard
);

void contact_free(contact_t *contact);

contact_t *contact_parseFromJSON(cJSON *contactJSON);

cJSON *contact_convertToJSON(contact_t *contact);

#endif /* _contact_H_ */

