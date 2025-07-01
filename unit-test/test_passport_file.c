#ifndef passport_file_TEST
#define passport_file_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define passport_file_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/passport_file.h"
passport_file_t* instantiate_passport_file(int include_optional);



passport_file_t* instantiate_passport_file(int include_optional) {
  passport_file_t* passport_file = NULL;
  if (include_optional) {
    passport_file = passport_file_create(
      "0",
      "0",
      56,
      56
    );
  } else {
    passport_file = passport_file_create(
      "0",
      "0",
      56,
      56
    );
  }

  return passport_file;
}


#ifdef passport_file_MAIN

void test_passport_file(int include_optional) {
    passport_file_t* passport_file_1 = instantiate_passport_file(include_optional);

	cJSON* jsonpassport_file_1 = passport_file_convertToJSON(passport_file_1);
	printf("passport_file :\n%s\n", cJSON_Print(jsonpassport_file_1));
	passport_file_t* passport_file_2 = passport_file_parseFromJSON(jsonpassport_file_1);
	cJSON* jsonpassport_file_2 = passport_file_convertToJSON(passport_file_2);
	printf("repeating passport_file:\n%s\n", cJSON_Print(jsonpassport_file_2));
}

int main() {
  test_passport_file(1);
  test_passport_file(0);

  printf("Hello world \n");
  return 0;
}

#endif // passport_file_MAIN
#endif // passport_file_TEST
