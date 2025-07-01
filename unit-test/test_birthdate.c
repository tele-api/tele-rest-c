#ifndef birthdate_TEST
#define birthdate_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define birthdate_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/birthdate.h"
birthdate_t* instantiate_birthdate(int include_optional);



birthdate_t* instantiate_birthdate(int include_optional) {
  birthdate_t* birthdate = NULL;
  if (include_optional) {
    birthdate = birthdate_create(
      56,
      56,
      56
    );
  } else {
    birthdate = birthdate_create(
      56,
      56,
      56
    );
  }

  return birthdate;
}


#ifdef birthdate_MAIN

void test_birthdate(int include_optional) {
    birthdate_t* birthdate_1 = instantiate_birthdate(include_optional);

	cJSON* jsonbirthdate_1 = birthdate_convertToJSON(birthdate_1);
	printf("birthdate :\n%s\n", cJSON_Print(jsonbirthdate_1));
	birthdate_t* birthdate_2 = birthdate_parseFromJSON(jsonbirthdate_1);
	cJSON* jsonbirthdate_2 = birthdate_convertToJSON(birthdate_2);
	printf("repeating birthdate:\n%s\n", cJSON_Print(jsonbirthdate_2));
}

int main() {
  test_birthdate(1);
  test_birthdate(0);

  printf("Hello world \n");
  return 0;
}

#endif // birthdate_MAIN
#endif // birthdate_TEST
