#ifndef business_bot_rights_TEST
#define business_bot_rights_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define business_bot_rights_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/business_bot_rights.h"
business_bot_rights_t* instantiate_business_bot_rights(int include_optional);



business_bot_rights_t* instantiate_business_bot_rights(int include_optional) {
  business_bot_rights_t* business_bot_rights = NULL;
  if (include_optional) {
    business_bot_rights = business_bot_rights_create(
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1
    );
  } else {
    business_bot_rights = business_bot_rights_create(
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1
    );
  }

  return business_bot_rights;
}


#ifdef business_bot_rights_MAIN

void test_business_bot_rights(int include_optional) {
    business_bot_rights_t* business_bot_rights_1 = instantiate_business_bot_rights(include_optional);

	cJSON* jsonbusiness_bot_rights_1 = business_bot_rights_convertToJSON(business_bot_rights_1);
	printf("business_bot_rights :\n%s\n", cJSON_Print(jsonbusiness_bot_rights_1));
	business_bot_rights_t* business_bot_rights_2 = business_bot_rights_parseFromJSON(jsonbusiness_bot_rights_1);
	cJSON* jsonbusiness_bot_rights_2 = business_bot_rights_convertToJSON(business_bot_rights_2);
	printf("repeating business_bot_rights:\n%s\n", cJSON_Print(jsonbusiness_bot_rights_2));
}

int main() {
  test_business_bot_rights(1);
  test_business_bot_rights(0);

  printf("Hello world \n");
  return 0;
}

#endif // business_bot_rights_MAIN
#endif // business_bot_rights_TEST
