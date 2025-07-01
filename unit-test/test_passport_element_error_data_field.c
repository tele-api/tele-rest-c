#ifndef passport_element_error_data_field_TEST
#define passport_element_error_data_field_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define passport_element_error_data_field_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/passport_element_error_data_field.h"
passport_element_error_data_field_t* instantiate_passport_element_error_data_field(int include_optional);



passport_element_error_data_field_t* instantiate_passport_element_error_data_field(int include_optional) {
  passport_element_error_data_field_t* passport_element_error_data_field = NULL;
  if (include_optional) {
    passport_element_error_data_field = passport_element_error_data_field_create(
      "data",
      telegram_bot_api_passport_element_error_data_field_TYPE_personal_details,
      "0",
      "0",
      "0"
    );
  } else {
    passport_element_error_data_field = passport_element_error_data_field_create(
      "data",
      telegram_bot_api_passport_element_error_data_field_TYPE_personal_details,
      "0",
      "0",
      "0"
    );
  }

  return passport_element_error_data_field;
}


#ifdef passport_element_error_data_field_MAIN

void test_passport_element_error_data_field(int include_optional) {
    passport_element_error_data_field_t* passport_element_error_data_field_1 = instantiate_passport_element_error_data_field(include_optional);

	cJSON* jsonpassport_element_error_data_field_1 = passport_element_error_data_field_convertToJSON(passport_element_error_data_field_1);
	printf("passport_element_error_data_field :\n%s\n", cJSON_Print(jsonpassport_element_error_data_field_1));
	passport_element_error_data_field_t* passport_element_error_data_field_2 = passport_element_error_data_field_parseFromJSON(jsonpassport_element_error_data_field_1);
	cJSON* jsonpassport_element_error_data_field_2 = passport_element_error_data_field_convertToJSON(passport_element_error_data_field_2);
	printf("repeating passport_element_error_data_field:\n%s\n", cJSON_Print(jsonpassport_element_error_data_field_2));
}

int main() {
  test_passport_element_error_data_field(1);
  test_passport_element_error_data_field(0);

  printf("Hello world \n");
  return 0;
}

#endif // passport_element_error_data_field_MAIN
#endif // passport_element_error_data_field_TEST
