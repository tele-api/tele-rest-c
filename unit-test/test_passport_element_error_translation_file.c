#ifndef passport_element_error_translation_file_TEST
#define passport_element_error_translation_file_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define passport_element_error_translation_file_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/passport_element_error_translation_file.h"
passport_element_error_translation_file_t* instantiate_passport_element_error_translation_file(int include_optional);



passport_element_error_translation_file_t* instantiate_passport_element_error_translation_file(int include_optional) {
  passport_element_error_translation_file_t* passport_element_error_translation_file = NULL;
  if (include_optional) {
    passport_element_error_translation_file = passport_element_error_translation_file_create(
      "translation_file",
      telegram_bot_api_passport_element_error_translation_file_TYPE_passport,
      "0",
      "0"
    );
  } else {
    passport_element_error_translation_file = passport_element_error_translation_file_create(
      "translation_file",
      telegram_bot_api_passport_element_error_translation_file_TYPE_passport,
      "0",
      "0"
    );
  }

  return passport_element_error_translation_file;
}


#ifdef passport_element_error_translation_file_MAIN

void test_passport_element_error_translation_file(int include_optional) {
    passport_element_error_translation_file_t* passport_element_error_translation_file_1 = instantiate_passport_element_error_translation_file(include_optional);

	cJSON* jsonpassport_element_error_translation_file_1 = passport_element_error_translation_file_convertToJSON(passport_element_error_translation_file_1);
	printf("passport_element_error_translation_file :\n%s\n", cJSON_Print(jsonpassport_element_error_translation_file_1));
	passport_element_error_translation_file_t* passport_element_error_translation_file_2 = passport_element_error_translation_file_parseFromJSON(jsonpassport_element_error_translation_file_1);
	cJSON* jsonpassport_element_error_translation_file_2 = passport_element_error_translation_file_convertToJSON(passport_element_error_translation_file_2);
	printf("repeating passport_element_error_translation_file:\n%s\n", cJSON_Print(jsonpassport_element_error_translation_file_2));
}

int main() {
  test_passport_element_error_translation_file(1);
  test_passport_element_error_translation_file(0);

  printf("Hello world \n");
  return 0;
}

#endif // passport_element_error_translation_file_MAIN
#endif // passport_element_error_translation_file_TEST
