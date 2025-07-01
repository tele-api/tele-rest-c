#ifndef business_opening_hours_TEST
#define business_opening_hours_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define business_opening_hours_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/business_opening_hours.h"
business_opening_hours_t* instantiate_business_opening_hours(int include_optional);



business_opening_hours_t* instantiate_business_opening_hours(int include_optional) {
  business_opening_hours_t* business_opening_hours = NULL;
  if (include_optional) {
    business_opening_hours = business_opening_hours_create(
      "0",
      list_createList()
    );
  } else {
    business_opening_hours = business_opening_hours_create(
      "0",
      list_createList()
    );
  }

  return business_opening_hours;
}


#ifdef business_opening_hours_MAIN

void test_business_opening_hours(int include_optional) {
    business_opening_hours_t* business_opening_hours_1 = instantiate_business_opening_hours(include_optional);

	cJSON* jsonbusiness_opening_hours_1 = business_opening_hours_convertToJSON(business_opening_hours_1);
	printf("business_opening_hours :\n%s\n", cJSON_Print(jsonbusiness_opening_hours_1));
	business_opening_hours_t* business_opening_hours_2 = business_opening_hours_parseFromJSON(jsonbusiness_opening_hours_1);
	cJSON* jsonbusiness_opening_hours_2 = business_opening_hours_convertToJSON(business_opening_hours_2);
	printf("repeating business_opening_hours:\n%s\n", cJSON_Print(jsonbusiness_opening_hours_2));
}

int main() {
  test_business_opening_hours(1);
  test_business_opening_hours(0);

  printf("Hello world \n");
  return 0;
}

#endif // business_opening_hours_MAIN
#endif // business_opening_hours_TEST
