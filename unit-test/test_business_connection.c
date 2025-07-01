#ifndef business_connection_TEST
#define business_connection_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define business_connection_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/business_connection.h"
business_connection_t* instantiate_business_connection(int include_optional);

#include "test_user.c"
#include "test_business_bot_rights.c"


business_connection_t* instantiate_business_connection(int include_optional) {
  business_connection_t* business_connection = NULL;
  if (include_optional) {
    business_connection = business_connection_create(
      "0",
       // false, not to have infinite recursion
      instantiate_user(0),
      56,
      56,
      1,
       // false, not to have infinite recursion
      instantiate_business_bot_rights(0)
    );
  } else {
    business_connection = business_connection_create(
      "0",
      NULL,
      56,
      56,
      1,
      NULL
    );
  }

  return business_connection;
}


#ifdef business_connection_MAIN

void test_business_connection(int include_optional) {
    business_connection_t* business_connection_1 = instantiate_business_connection(include_optional);

	cJSON* jsonbusiness_connection_1 = business_connection_convertToJSON(business_connection_1);
	printf("business_connection :\n%s\n", cJSON_Print(jsonbusiness_connection_1));
	business_connection_t* business_connection_2 = business_connection_parseFromJSON(jsonbusiness_connection_1);
	cJSON* jsonbusiness_connection_2 = business_connection_convertToJSON(business_connection_2);
	printf("repeating business_connection:\n%s\n", cJSON_Print(jsonbusiness_connection_2));
}

int main() {
  test_business_connection(1);
  test_business_connection(0);

  printf("Hello world \n");
  return 0;
}

#endif // business_connection_MAIN
#endif // business_connection_TEST
