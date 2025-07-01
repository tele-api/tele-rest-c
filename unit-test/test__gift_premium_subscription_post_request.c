#ifndef _gift_premium_subscription_post_request_TEST
#define _gift_premium_subscription_post_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _gift_premium_subscription_post_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_gift_premium_subscription_post_request.h"
_gift_premium_subscription_post_request_t* instantiate__gift_premium_subscription_post_request(int include_optional);



_gift_premium_subscription_post_request_t* instantiate__gift_premium_subscription_post_request(int include_optional) {
  _gift_premium_subscription_post_request_t* _gift_premium_subscription_post_request = NULL;
  if (include_optional) {
    _gift_premium_subscription_post_request = _gift_premium_subscription_post_request_create(
      56,
      telegram_bot_api__gift_premium_subscription_post_request_MONTHCOUNT_3,
      56,
      "0",
      "0",
      list_createList()
    );
  } else {
    _gift_premium_subscription_post_request = _gift_premium_subscription_post_request_create(
      56,
      telegram_bot_api__gift_premium_subscription_post_request_MONTHCOUNT_3,
      56,
      "0",
      "0",
      list_createList()
    );
  }

  return _gift_premium_subscription_post_request;
}


#ifdef _gift_premium_subscription_post_request_MAIN

void test__gift_premium_subscription_post_request(int include_optional) {
    _gift_premium_subscription_post_request_t* _gift_premium_subscription_post_request_1 = instantiate__gift_premium_subscription_post_request(include_optional);

	cJSON* json_gift_premium_subscription_post_request_1 = _gift_premium_subscription_post_request_convertToJSON(_gift_premium_subscription_post_request_1);
	printf("_gift_premium_subscription_post_request :\n%s\n", cJSON_Print(json_gift_premium_subscription_post_request_1));
	_gift_premium_subscription_post_request_t* _gift_premium_subscription_post_request_2 = _gift_premium_subscription_post_request_parseFromJSON(json_gift_premium_subscription_post_request_1);
	cJSON* json_gift_premium_subscription_post_request_2 = _gift_premium_subscription_post_request_convertToJSON(_gift_premium_subscription_post_request_2);
	printf("repeating _gift_premium_subscription_post_request:\n%s\n", cJSON_Print(json_gift_premium_subscription_post_request_2));
}

int main() {
  test__gift_premium_subscription_post_request(1);
  test__gift_premium_subscription_post_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // _gift_premium_subscription_post_request_MAIN
#endif // _gift_premium_subscription_post_request_TEST
