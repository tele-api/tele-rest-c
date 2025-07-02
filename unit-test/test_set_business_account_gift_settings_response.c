#ifndef set_business_account_gift_settings_response_TEST
#define set_business_account_gift_settings_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define set_business_account_gift_settings_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/set_business_account_gift_settings_response.h"
set_business_account_gift_settings_response_t* instantiate_set_business_account_gift_settings_response(int include_optional);



set_business_account_gift_settings_response_t* instantiate_set_business_account_gift_settings_response(int include_optional) {
  set_business_account_gift_settings_response_t* set_business_account_gift_settings_response = NULL;
  if (include_optional) {
    set_business_account_gift_settings_response = set_business_account_gift_settings_response_create(
      1,
      1
    );
  } else {
    set_business_account_gift_settings_response = set_business_account_gift_settings_response_create(
      1,
      1
    );
  }

  return set_business_account_gift_settings_response;
}


#ifdef set_business_account_gift_settings_response_MAIN

void test_set_business_account_gift_settings_response(int include_optional) {
    set_business_account_gift_settings_response_t* set_business_account_gift_settings_response_1 = instantiate_set_business_account_gift_settings_response(include_optional);

	cJSON* jsonset_business_account_gift_settings_response_1 = set_business_account_gift_settings_response_convertToJSON(set_business_account_gift_settings_response_1);
	printf("set_business_account_gift_settings_response :\n%s\n", cJSON_Print(jsonset_business_account_gift_settings_response_1));
	set_business_account_gift_settings_response_t* set_business_account_gift_settings_response_2 = set_business_account_gift_settings_response_parseFromJSON(jsonset_business_account_gift_settings_response_1);
	cJSON* jsonset_business_account_gift_settings_response_2 = set_business_account_gift_settings_response_convertToJSON(set_business_account_gift_settings_response_2);
	printf("repeating set_business_account_gift_settings_response:\n%s\n", cJSON_Print(jsonset_business_account_gift_settings_response_2));
}

int main() {
  test_set_business_account_gift_settings_response(1);
  test_set_business_account_gift_settings_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // set_business_account_gift_settings_response_MAIN
#endif // set_business_account_gift_settings_response_TEST
