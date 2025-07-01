#ifndef passport_element_error_selfie_TEST
#define passport_element_error_selfie_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define passport_element_error_selfie_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/passport_element_error_selfie.h"
passport_element_error_selfie_t* instantiate_passport_element_error_selfie(int include_optional);



passport_element_error_selfie_t* instantiate_passport_element_error_selfie(int include_optional) {
  passport_element_error_selfie_t* passport_element_error_selfie = NULL;
  if (include_optional) {
    passport_element_error_selfie = passport_element_error_selfie_create(
      "selfie",
      telegram_bot_api_passport_element_error_selfie_TYPE_passport,
      "0",
      "0"
    );
  } else {
    passport_element_error_selfie = passport_element_error_selfie_create(
      "selfie",
      telegram_bot_api_passport_element_error_selfie_TYPE_passport,
      "0",
      "0"
    );
  }

  return passport_element_error_selfie;
}


#ifdef passport_element_error_selfie_MAIN

void test_passport_element_error_selfie(int include_optional) {
    passport_element_error_selfie_t* passport_element_error_selfie_1 = instantiate_passport_element_error_selfie(include_optional);

	cJSON* jsonpassport_element_error_selfie_1 = passport_element_error_selfie_convertToJSON(passport_element_error_selfie_1);
	printf("passport_element_error_selfie :\n%s\n", cJSON_Print(jsonpassport_element_error_selfie_1));
	passport_element_error_selfie_t* passport_element_error_selfie_2 = passport_element_error_selfie_parseFromJSON(jsonpassport_element_error_selfie_1);
	cJSON* jsonpassport_element_error_selfie_2 = passport_element_error_selfie_convertToJSON(passport_element_error_selfie_2);
	printf("repeating passport_element_error_selfie:\n%s\n", cJSON_Print(jsonpassport_element_error_selfie_2));
}

int main() {
  test_passport_element_error_selfie(1);
  test_passport_element_error_selfie(0);

  printf("Hello world \n");
  return 0;
}

#endif // passport_element_error_selfie_MAIN
#endif // passport_element_error_selfie_TEST
