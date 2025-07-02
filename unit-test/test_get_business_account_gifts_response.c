#ifndef get_business_account_gifts_response_TEST
#define get_business_account_gifts_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define get_business_account_gifts_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/get_business_account_gifts_response.h"
get_business_account_gifts_response_t* instantiate_get_business_account_gifts_response(int include_optional);

#include "test_owned_gifts.c"


get_business_account_gifts_response_t* instantiate_get_business_account_gifts_response(int include_optional) {
  get_business_account_gifts_response_t* get_business_account_gifts_response = NULL;
  if (include_optional) {
    get_business_account_gifts_response = get_business_account_gifts_response_create(
      1,
       // false, not to have infinite recursion
      instantiate_owned_gifts(0)
    );
  } else {
    get_business_account_gifts_response = get_business_account_gifts_response_create(
      1,
      NULL
    );
  }

  return get_business_account_gifts_response;
}


#ifdef get_business_account_gifts_response_MAIN

void test_get_business_account_gifts_response(int include_optional) {
    get_business_account_gifts_response_t* get_business_account_gifts_response_1 = instantiate_get_business_account_gifts_response(include_optional);

	cJSON* jsonget_business_account_gifts_response_1 = get_business_account_gifts_response_convertToJSON(get_business_account_gifts_response_1);
	printf("get_business_account_gifts_response :\n%s\n", cJSON_Print(jsonget_business_account_gifts_response_1));
	get_business_account_gifts_response_t* get_business_account_gifts_response_2 = get_business_account_gifts_response_parseFromJSON(jsonget_business_account_gifts_response_1);
	cJSON* jsonget_business_account_gifts_response_2 = get_business_account_gifts_response_convertToJSON(get_business_account_gifts_response_2);
	printf("repeating get_business_account_gifts_response:\n%s\n", cJSON_Print(jsonget_business_account_gifts_response_2));
}

int main() {
  test_get_business_account_gifts_response(1);
  test_get_business_account_gifts_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // get_business_account_gifts_response_MAIN
#endif // get_business_account_gifts_response_TEST
