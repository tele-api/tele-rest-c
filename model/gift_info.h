/*
 * gift_info.h
 *
 * Describes a service message about a regular gift that was sent or received.
 */

#ifndef _gift_info_H_
#define _gift_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct gift_info_t gift_info_t;

#include "gift.h"
#include "message_entity.h"



typedef struct gift_info_t {
    struct gift_t *gift; //model
    char *owned_gift_id; // string
    int convert_star_count; //numeric
    int prepaid_upgrade_star_count; //numeric
    int can_be_upgraded; //boolean
    char *text; // string
    list_t *entities; //nonprimitive container
    int is_private; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} gift_info_t;

__attribute__((deprecated)) gift_info_t *gift_info_create(
    gift_t *gift,
    char *owned_gift_id,
    int convert_star_count,
    int prepaid_upgrade_star_count,
    int can_be_upgraded,
    char *text,
    list_t *entities,
    int is_private
);

void gift_info_free(gift_info_t *gift_info);

gift_info_t *gift_info_parseFromJSON(cJSON *gift_infoJSON);

cJSON *gift_info_convertToJSON(gift_info_t *gift_info);

#endif /* _gift_info_H_ */

