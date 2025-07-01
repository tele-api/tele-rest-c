/*
 * passport_element_error.h
 *
 * This object represents an error in the Telegram Passport element which was submitted that should be resolved by the user. It should be one of:  * [PassportElementErrorDataField](https://core.telegram.org/bots/api/#passportelementerrordatafield) * [PassportElementErrorFrontSide](https://core.telegram.org/bots/api/#passportelementerrorfrontside) * [PassportElementErrorReverseSide](https://core.telegram.org/bots/api/#passportelementerrorreverseside) * [PassportElementErrorSelfie](https://core.telegram.org/bots/api/#passportelementerrorselfie) * [PassportElementErrorFile](https://core.telegram.org/bots/api/#passportelementerrorfile) * [PassportElementErrorFiles](https://core.telegram.org/bots/api/#passportelementerrorfiles) * [PassportElementErrorTranslationFile](https://core.telegram.org/bots/api/#passportelementerrortranslationfile) * [PassportElementErrorTranslationFiles](https://core.telegram.org/bots/api/#passportelementerrortranslationfiles) * [PassportElementErrorUnspecified](https://core.telegram.org/bots/api/#passportelementerrorunspecified)
 */

#ifndef _passport_element_error_H_
#define _passport_element_error_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct passport_element_error_t passport_element_error_t;

#include "passport_element_error_data_field.h"
#include "passport_element_error_file.h"
#include "passport_element_error_files.h"
#include "passport_element_error_front_side.h"
#include "passport_element_error_reverse_side.h"
#include "passport_element_error_selfie.h"
#include "passport_element_error_translation_file.h"
#include "passport_element_error_translation_files.h"
#include "passport_element_error_unspecified.h"



typedef struct passport_element_error_t {
    char *source; // string
    char *type; // string
    char *field_name; // string
    char *data_hash; // string
    char *message; // string
    char *file_hash; // string
    list_t *file_hashes; //primitive container
    char *element_hash; // string

    int _library_owned; // Is the library responsible for freeing this object?
} passport_element_error_t;

__attribute__((deprecated)) passport_element_error_t *passport_element_error_create(
    char *source,
    char *type,
    char *field_name,
    char *data_hash,
    char *message,
    char *file_hash,
    list_t *file_hashes,
    char *element_hash
);

void passport_element_error_free(passport_element_error_t *passport_element_error);

passport_element_error_t *passport_element_error_parseFromJSON(cJSON *passport_element_errorJSON);

cJSON *passport_element_error_convertToJSON(passport_element_error_t *passport_element_error);

#endif /* _passport_element_error_H_ */

