/*
 * paid_media_info.h
 *
 * Describes the paid media added to a message.
 */

#ifndef _paid_media_info_H_
#define _paid_media_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct paid_media_info_t paid_media_info_t;

#include "paid_media.h"



typedef struct paid_media_info_t {
    int star_count; //numeric
    list_t *paid_media; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} paid_media_info_t;

__attribute__((deprecated)) paid_media_info_t *paid_media_info_create(
    int star_count,
    list_t *paid_media
);

void paid_media_info_free(paid_media_info_t *paid_media_info);

paid_media_info_t *paid_media_info_parseFromJSON(cJSON *paid_media_infoJSON);

cJSON *paid_media_info_convertToJSON(paid_media_info_t *paid_media_info);

#endif /* _paid_media_info_H_ */

