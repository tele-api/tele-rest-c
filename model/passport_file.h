/*
 * passport_file.h
 *
 * This object represents a file uploaded to Telegram Passport. Currently all Telegram Passport files are in JPEG format when decrypted and don&#39;t exceed 10MB.
 */

#ifndef _passport_file_H_
#define _passport_file_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct passport_file_t passport_file_t;




typedef struct passport_file_t {
    char *file_id; // string
    char *file_unique_id; // string
    int file_size; //numeric
    int file_date; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} passport_file_t;

__attribute__((deprecated)) passport_file_t *passport_file_create(
    char *file_id,
    char *file_unique_id,
    int file_size,
    int file_date
);

void passport_file_free(passport_file_t *passport_file);

passport_file_t *passport_file_parseFromJSON(cJSON *passport_fileJSON);

cJSON *passport_file_convertToJSON(passport_file_t *passport_file);

#endif /* _passport_file_H_ */

