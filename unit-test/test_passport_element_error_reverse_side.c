#ifndef passport_element_error_reverse_side_TEST
#define passport_element_error_reverse_side_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define passport_element_error_reverse_side_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/passport_element_error_reverse_side.h"
passport_element_error_reverse_side_t* instantiate_passport_element_error_reverse_side(int include_optional);



passport_element_error_reverse_side_t* instantiate_passport_element_error_reverse_side(int include_optional) {
  passport_element_error_reverse_side_t* passport_element_error_reverse_side = NULL;
  if (include_optional) {
    passport_element_error_reverse_side = passport_element_error_reverse_side_create(
      "reverse_side",
      telegram_bot_api_passport_element_error_reverse_side_TYPE_driver_license,
      "0",
      "0"
    );
  } else {
    passport_element_error_reverse_side = passport_element_error_reverse_side_create(
      "reverse_side",
      telegram_bot_api_passport_element_error_reverse_side_TYPE_driver_license,
      "0",
      "0"
    );
  }

  return passport_element_error_reverse_side;
}


#ifdef passport_element_error_reverse_side_MAIN

void test_passport_element_error_reverse_side(int include_optional) {
    passport_element_error_reverse_side_t* passport_element_error_reverse_side_1 = instantiate_passport_element_error_reverse_side(include_optional);

	cJSON* jsonpassport_element_error_reverse_side_1 = passport_element_error_reverse_side_convertToJSON(passport_element_error_reverse_side_1);
	printf("passport_element_error_reverse_side :\n%s\n", cJSON_Print(jsonpassport_element_error_reverse_side_1));
	passport_element_error_reverse_side_t* passport_element_error_reverse_side_2 = passport_element_error_reverse_side_parseFromJSON(jsonpassport_element_error_reverse_side_1);
	cJSON* jsonpassport_element_error_reverse_side_2 = passport_element_error_reverse_side_convertToJSON(passport_element_error_reverse_side_2);
	printf("repeating passport_element_error_reverse_side:\n%s\n", cJSON_Print(jsonpassport_element_error_reverse_side_2));
}

int main() {
  test_passport_element_error_reverse_side(1);
  test_passport_element_error_reverse_side(0);

  printf("Hello world \n");
  return 0;
}

#endif // passport_element_error_reverse_side_MAIN
#endif // passport_element_error_reverse_side_TEST
