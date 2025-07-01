#ifndef business_intro_TEST
#define business_intro_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define business_intro_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/business_intro.h"
business_intro_t* instantiate_business_intro(int include_optional);

#include "test_sticker.c"


business_intro_t* instantiate_business_intro(int include_optional) {
  business_intro_t* business_intro = NULL;
  if (include_optional) {
    business_intro = business_intro_create(
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_sticker(0)
    );
  } else {
    business_intro = business_intro_create(
      "0",
      "0",
      NULL
    );
  }

  return business_intro;
}


#ifdef business_intro_MAIN

void test_business_intro(int include_optional) {
    business_intro_t* business_intro_1 = instantiate_business_intro(include_optional);

	cJSON* jsonbusiness_intro_1 = business_intro_convertToJSON(business_intro_1);
	printf("business_intro :\n%s\n", cJSON_Print(jsonbusiness_intro_1));
	business_intro_t* business_intro_2 = business_intro_parseFromJSON(jsonbusiness_intro_1);
	cJSON* jsonbusiness_intro_2 = business_intro_convertToJSON(business_intro_2);
	printf("repeating business_intro:\n%s\n", cJSON_Print(jsonbusiness_intro_2));
}

int main() {
  test_business_intro(1);
  test_business_intro(0);

  printf("Hello world \n");
  return 0;
}

#endif // business_intro_MAIN
#endif // business_intro_TEST
