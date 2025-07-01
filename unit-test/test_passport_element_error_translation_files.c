#ifndef passport_element_error_translation_files_TEST
#define passport_element_error_translation_files_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define passport_element_error_translation_files_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/passport_element_error_translation_files.h"
passport_element_error_translation_files_t* instantiate_passport_element_error_translation_files(int include_optional);



passport_element_error_translation_files_t* instantiate_passport_element_error_translation_files(int include_optional) {
  passport_element_error_translation_files_t* passport_element_error_translation_files = NULL;
  if (include_optional) {
    passport_element_error_translation_files = passport_element_error_translation_files_create(
      "translation_files",
      telegram_bot_api_passport_element_error_translation_files_TYPE_passport,
      list_createList(),
      "0"
    );
  } else {
    passport_element_error_translation_files = passport_element_error_translation_files_create(
      "translation_files",
      telegram_bot_api_passport_element_error_translation_files_TYPE_passport,
      list_createList(),
      "0"
    );
  }

  return passport_element_error_translation_files;
}


#ifdef passport_element_error_translation_files_MAIN

void test_passport_element_error_translation_files(int include_optional) {
    passport_element_error_translation_files_t* passport_element_error_translation_files_1 = instantiate_passport_element_error_translation_files(include_optional);

	cJSON* jsonpassport_element_error_translation_files_1 = passport_element_error_translation_files_convertToJSON(passport_element_error_translation_files_1);
	printf("passport_element_error_translation_files :\n%s\n", cJSON_Print(jsonpassport_element_error_translation_files_1));
	passport_element_error_translation_files_t* passport_element_error_translation_files_2 = passport_element_error_translation_files_parseFromJSON(jsonpassport_element_error_translation_files_1);
	cJSON* jsonpassport_element_error_translation_files_2 = passport_element_error_translation_files_convertToJSON(passport_element_error_translation_files_2);
	printf("repeating passport_element_error_translation_files:\n%s\n", cJSON_Print(jsonpassport_element_error_translation_files_2));
}

int main() {
  test_passport_element_error_translation_files(1);
  test_passport_element_error_translation_files(0);

  printf("Hello world \n");
  return 0;
}

#endif // passport_element_error_translation_files_MAIN
#endif // passport_element_error_translation_files_TEST
