#ifndef business_location_TEST
#define business_location_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define business_location_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/business_location.h"
business_location_t* instantiate_business_location(int include_optional);

#include "test_location.c"


business_location_t* instantiate_business_location(int include_optional) {
  business_location_t* business_location = NULL;
  if (include_optional) {
    business_location = business_location_create(
      "0",
       // false, not to have infinite recursion
      instantiate_location(0)
    );
  } else {
    business_location = business_location_create(
      "0",
      NULL
    );
  }

  return business_location;
}


#ifdef business_location_MAIN

void test_business_location(int include_optional) {
    business_location_t* business_location_1 = instantiate_business_location(include_optional);

	cJSON* jsonbusiness_location_1 = business_location_convertToJSON(business_location_1);
	printf("business_location :\n%s\n", cJSON_Print(jsonbusiness_location_1));
	business_location_t* business_location_2 = business_location_parseFromJSON(jsonbusiness_location_1);
	cJSON* jsonbusiness_location_2 = business_location_convertToJSON(business_location_2);
	printf("repeating business_location:\n%s\n", cJSON_Print(jsonbusiness_location_2));
}

int main() {
  test_business_location(1);
  test_business_location(0);

  printf("Hello world \n");
  return 0;
}

#endif // business_location_MAIN
#endif // business_location_TEST
