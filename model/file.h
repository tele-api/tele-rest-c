/*
 * file.h
 *
 * This object represents a file ready to be downloaded. The file can be downloaded via the link &#x60;https://api.telegram.org/file/bot&lt;token&gt;/&lt;file_path&gt;&#x60;. It is guaranteed that the link will be valid for at least 1 hour. When the link expires, a new one can be requested by calling [getFile](https://core.telegram.org/bots/api/#getfile).  The maximum file size to download is 20 MB
 */

#ifndef _file_H_
#define _file_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct file_t file_t;




typedef struct file_t {
    char *file_id; // string
    char *file_unique_id; // string
    int file_size; //numeric
    char *file_path; // string

    int _library_owned; // Is the library responsible for freeing this object?
} file_t;

__attribute__((deprecated)) file_t *file_create(
    char *file_id,
    char *file_unique_id,
    int file_size,
    char *file_path
);

void file_free(file_t *file);

file_t *file_parseFromJSON(cJSON *fileJSON);

cJSON *file_convertToJSON(file_t *file);

#endif /* _file_H_ */

