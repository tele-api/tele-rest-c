#ifndef passport_element_error_unspecified_TEST
#define passport_element_error_unspecified_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define passport_element_error_unspecified_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/passport_element_error_unspecified.h"
passport_element_error_unspecified_t* instantiate_passport_element_error_unspecified(int include_optional);



passport_element_error_unspecified_t* instantiate_passport_element_error_unspecified(int include_optional) {
  passport_element_error_unspecified_t* passport_element_error_unspecified = NULL;
  if (include_optional) {
    passport_element_error_unspecified = passport_element_error_unspecified_create(
      "unspecified",
      "0",
      "0",
      "0"
    );
  } else {
    passport_element_error_unspecified = passport_element_error_unspecified_create(
      "unspecified",
      "0",
      "0",
      "0"
    );
  }

  return passport_element_error_unspecified;
}


#ifdef passport_element_error_unspecified_MAIN

void test_passport_element_error_unspecified(int include_optional) {
    passport_element_error_unspecified_t* passport_element_error_unspecified_1 = instantiate_passport_element_error_unspecified(include_optional);

	cJSON* jsonpassport_element_error_unspecified_1 = passport_element_error_unspecified_convertToJSON(passport_element_error_unspecified_1);
	printf("passport_element_error_unspecified :\n%s\n", cJSON_Print(jsonpassport_element_error_unspecified_1));
	passport_element_error_unspecified_t* passport_element_error_unspecified_2 = passport_element_error_unspecified_parseFromJSON(jsonpassport_element_error_unspecified_1);
	cJSON* jsonpassport_element_error_unspecified_2 = passport_element_error_unspecified_convertToJSON(passport_element_error_unspecified_2);
	printf("repeating passport_element_error_unspecified:\n%s\n", cJSON_Print(jsonpassport_element_error_unspecified_2));
}

int main() {
  test_passport_element_error_unspecified(1);
  test_passport_element_error_unspecified(0);

  printf("Hello world \n");
  return 0;
}

#endif // passport_element_error_unspecified_MAIN
#endif // passport_element_error_unspecified_TEST
