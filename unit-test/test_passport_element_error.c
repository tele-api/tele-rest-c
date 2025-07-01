#ifndef passport_element_error_TEST
#define passport_element_error_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define passport_element_error_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/passport_element_error.h"
passport_element_error_t* instantiate_passport_element_error(int include_optional);



passport_element_error_t* instantiate_passport_element_error(int include_optional) {
  passport_element_error_t* passport_element_error = NULL;
  if (include_optional) {
    passport_element_error = passport_element_error_create(
      "unspecified",
      "0",
      "0",
      "0",
      "0",
      "0",
      list_createList(),
      "0"
    );
  } else {
    passport_element_error = passport_element_error_create(
      "unspecified",
      "0",
      "0",
      "0",
      "0",
      "0",
      list_createList(),
      "0"
    );
  }

  return passport_element_error;
}


#ifdef passport_element_error_MAIN

void test_passport_element_error(int include_optional) {
    passport_element_error_t* passport_element_error_1 = instantiate_passport_element_error(include_optional);

	cJSON* jsonpassport_element_error_1 = passport_element_error_convertToJSON(passport_element_error_1);
	printf("passport_element_error :\n%s\n", cJSON_Print(jsonpassport_element_error_1));
	passport_element_error_t* passport_element_error_2 = passport_element_error_parseFromJSON(jsonpassport_element_error_1);
	cJSON* jsonpassport_element_error_2 = passport_element_error_convertToJSON(passport_element_error_2);
	printf("repeating passport_element_error:\n%s\n", cJSON_Print(jsonpassport_element_error_2));
}

int main() {
  test_passport_element_error(1);
  test_passport_element_error(0);

  printf("Hello world \n");
  return 0;
}

#endif // passport_element_error_MAIN
#endif // passport_element_error_TEST
