#ifndef get_business_account_gifts_request_TEST
#define get_business_account_gifts_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define get_business_account_gifts_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/get_business_account_gifts_request.h"
get_business_account_gifts_request_t* instantiate_get_business_account_gifts_request(int include_optional);



get_business_account_gifts_request_t* instantiate_get_business_account_gifts_request(int include_optional) {
  get_business_account_gifts_request_t* get_business_account_gifts_request = NULL;
  if (include_optional) {
    get_business_account_gifts_request = get_business_account_gifts_request_create(
      "0",
      1,
      1,
      1,
      1,
      1,
      1,
      "0",
      56
    );
  } else {
    get_business_account_gifts_request = get_business_account_gifts_request_create(
      "0",
      1,
      1,
      1,
      1,
      1,
      1,
      "0",
      56
    );
  }

  return get_business_account_gifts_request;
}


#ifdef get_business_account_gifts_request_MAIN

void test_get_business_account_gifts_request(int include_optional) {
    get_business_account_gifts_request_t* get_business_account_gifts_request_1 = instantiate_get_business_account_gifts_request(include_optional);

	cJSON* jsonget_business_account_gifts_request_1 = get_business_account_gifts_request_convertToJSON(get_business_account_gifts_request_1);
	printf("get_business_account_gifts_request :\n%s\n", cJSON_Print(jsonget_business_account_gifts_request_1));
	get_business_account_gifts_request_t* get_business_account_gifts_request_2 = get_business_account_gifts_request_parseFromJSON(jsonget_business_account_gifts_request_1);
	cJSON* jsonget_business_account_gifts_request_2 = get_business_account_gifts_request_convertToJSON(get_business_account_gifts_request_2);
	printf("repeating get_business_account_gifts_request:\n%s\n", cJSON_Print(jsonget_business_account_gifts_request_2));
}

int main() {
  test_get_business_account_gifts_request(1);
  test_get_business_account_gifts_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // get_business_account_gifts_request_MAIN
#endif // get_business_account_gifts_request_TEST
