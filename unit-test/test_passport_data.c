#ifndef passport_data_TEST
#define passport_data_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define passport_data_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/passport_data.h"
passport_data_t* instantiate_passport_data(int include_optional);

#include "test_encrypted_credentials.c"


passport_data_t* instantiate_passport_data(int include_optional) {
  passport_data_t* passport_data = NULL;
  if (include_optional) {
    passport_data = passport_data_create(
      list_createList(),
       // false, not to have infinite recursion
      instantiate_encrypted_credentials(0)
    );
  } else {
    passport_data = passport_data_create(
      list_createList(),
      NULL
    );
  }

  return passport_data;
}


#ifdef passport_data_MAIN

void test_passport_data(int include_optional) {
    passport_data_t* passport_data_1 = instantiate_passport_data(include_optional);

	cJSON* jsonpassport_data_1 = passport_data_convertToJSON(passport_data_1);
	printf("passport_data :\n%s\n", cJSON_Print(jsonpassport_data_1));
	passport_data_t* passport_data_2 = passport_data_parseFromJSON(jsonpassport_data_1);
	cJSON* jsonpassport_data_2 = passport_data_convertToJSON(passport_data_2);
	printf("repeating passport_data:\n%s\n", cJSON_Print(jsonpassport_data_2));
}

int main() {
  test_passport_data(1);
  test_passport_data(0);

  printf("Hello world \n");
  return 0;
}

#endif // passport_data_MAIN
#endif // passport_data_TEST
