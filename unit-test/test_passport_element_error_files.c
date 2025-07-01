#ifndef passport_element_error_files_TEST
#define passport_element_error_files_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define passport_element_error_files_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/passport_element_error_files.h"
passport_element_error_files_t* instantiate_passport_element_error_files(int include_optional);



passport_element_error_files_t* instantiate_passport_element_error_files(int include_optional) {
  passport_element_error_files_t* passport_element_error_files = NULL;
  if (include_optional) {
    passport_element_error_files = passport_element_error_files_create(
      "files",
      telegram_bot_api_passport_element_error_files_TYPE_utility_bill,
      list_createList(),
      "0"
    );
  } else {
    passport_element_error_files = passport_element_error_files_create(
      "files",
      telegram_bot_api_passport_element_error_files_TYPE_utility_bill,
      list_createList(),
      "0"
    );
  }

  return passport_element_error_files;
}


#ifdef passport_element_error_files_MAIN

void test_passport_element_error_files(int include_optional) {
    passport_element_error_files_t* passport_element_error_files_1 = instantiate_passport_element_error_files(include_optional);

	cJSON* jsonpassport_element_error_files_1 = passport_element_error_files_convertToJSON(passport_element_error_files_1);
	printf("passport_element_error_files :\n%s\n", cJSON_Print(jsonpassport_element_error_files_1));
	passport_element_error_files_t* passport_element_error_files_2 = passport_element_error_files_parseFromJSON(jsonpassport_element_error_files_1);
	cJSON* jsonpassport_element_error_files_2 = passport_element_error_files_convertToJSON(passport_element_error_files_2);
	printf("repeating passport_element_error_files:\n%s\n", cJSON_Print(jsonpassport_element_error_files_2));
}

int main() {
  test_passport_element_error_files(1);
  test_passport_element_error_files(0);

  printf("Hello world \n");
  return 0;
}

#endif // passport_element_error_files_MAIN
#endif // passport_element_error_files_TEST
