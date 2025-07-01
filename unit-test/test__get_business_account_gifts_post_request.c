#ifndef _get_business_account_gifts_post_request_TEST
#define _get_business_account_gifts_post_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _get_business_account_gifts_post_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_get_business_account_gifts_post_request.h"
_get_business_account_gifts_post_request_t* instantiate__get_business_account_gifts_post_request(int include_optional);



_get_business_account_gifts_post_request_t* instantiate__get_business_account_gifts_post_request(int include_optional) {
  _get_business_account_gifts_post_request_t* _get_business_account_gifts_post_request = NULL;
  if (include_optional) {
    _get_business_account_gifts_post_request = _get_business_account_gifts_post_request_create(
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
    _get_business_account_gifts_post_request = _get_business_account_gifts_post_request_create(
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

  return _get_business_account_gifts_post_request;
}


#ifdef _get_business_account_gifts_post_request_MAIN

void test__get_business_account_gifts_post_request(int include_optional) {
    _get_business_account_gifts_post_request_t* _get_business_account_gifts_post_request_1 = instantiate__get_business_account_gifts_post_request(include_optional);

	cJSON* json_get_business_account_gifts_post_request_1 = _get_business_account_gifts_post_request_convertToJSON(_get_business_account_gifts_post_request_1);
	printf("_get_business_account_gifts_post_request :\n%s\n", cJSON_Print(json_get_business_account_gifts_post_request_1));
	_get_business_account_gifts_post_request_t* _get_business_account_gifts_post_request_2 = _get_business_account_gifts_post_request_parseFromJSON(json_get_business_account_gifts_post_request_1);
	cJSON* json_get_business_account_gifts_post_request_2 = _get_business_account_gifts_post_request_convertToJSON(_get_business_account_gifts_post_request_2);
	printf("repeating _get_business_account_gifts_post_request:\n%s\n", cJSON_Print(json_get_business_account_gifts_post_request_2));
}

int main() {
  test__get_business_account_gifts_post_request(1);
  test__get_business_account_gifts_post_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // _get_business_account_gifts_post_request_MAIN
#endif // _get_business_account_gifts_post_request_TEST
