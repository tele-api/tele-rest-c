#ifndef business_opening_hours_interval_TEST
#define business_opening_hours_interval_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define business_opening_hours_interval_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/business_opening_hours_interval.h"
business_opening_hours_interval_t* instantiate_business_opening_hours_interval(int include_optional);



business_opening_hours_interval_t* instantiate_business_opening_hours_interval(int include_optional) {
  business_opening_hours_interval_t* business_opening_hours_interval = NULL;
  if (include_optional) {
    business_opening_hours_interval = business_opening_hours_interval_create(
      56,
      56
    );
  } else {
    business_opening_hours_interval = business_opening_hours_interval_create(
      56,
      56
    );
  }

  return business_opening_hours_interval;
}


#ifdef business_opening_hours_interval_MAIN

void test_business_opening_hours_interval(int include_optional) {
    business_opening_hours_interval_t* business_opening_hours_interval_1 = instantiate_business_opening_hours_interval(include_optional);

	cJSON* jsonbusiness_opening_hours_interval_1 = business_opening_hours_interval_convertToJSON(business_opening_hours_interval_1);
	printf("business_opening_hours_interval :\n%s\n", cJSON_Print(jsonbusiness_opening_hours_interval_1));
	business_opening_hours_interval_t* business_opening_hours_interval_2 = business_opening_hours_interval_parseFromJSON(jsonbusiness_opening_hours_interval_1);
	cJSON* jsonbusiness_opening_hours_interval_2 = business_opening_hours_interval_convertToJSON(business_opening_hours_interval_2);
	printf("repeating business_opening_hours_interval:\n%s\n", cJSON_Print(jsonbusiness_opening_hours_interval_2));
}

int main() {
  test_business_opening_hours_interval(1);
  test_business_opening_hours_interval(0);

  printf("Hello world \n");
  return 0;
}

#endif // business_opening_hours_interval_MAIN
#endif // business_opening_hours_interval_TEST
