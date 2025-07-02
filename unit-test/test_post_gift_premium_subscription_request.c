#ifndef post_gift_premium_subscription_request_TEST
#define post_gift_premium_subscription_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define post_gift_premium_subscription_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/post_gift_premium_subscription_request.h"
post_gift_premium_subscription_request_t* instantiate_post_gift_premium_subscription_request(int include_optional);



post_gift_premium_subscription_request_t* instantiate_post_gift_premium_subscription_request(int include_optional) {
  post_gift_premium_subscription_request_t* post_gift_premium_subscription_request = NULL;
  if (include_optional) {
    post_gift_premium_subscription_request = post_gift_premium_subscription_request_create(
      56,
      telegram_bot_api_post_gift_premium_subscription_request_MONTHCOUNT_3,
      56,
      "0",
      "0",
      list_createList()
    );
  } else {
    post_gift_premium_subscription_request = post_gift_premium_subscription_request_create(
      56,
      telegram_bot_api_post_gift_premium_subscription_request_MONTHCOUNT_3,
      56,
      "0",
      "0",
      list_createList()
    );
  }

  return post_gift_premium_subscription_request;
}


#ifdef post_gift_premium_subscription_request_MAIN

void test_post_gift_premium_subscription_request(int include_optional) {
    post_gift_premium_subscription_request_t* post_gift_premium_subscription_request_1 = instantiate_post_gift_premium_subscription_request(include_optional);

	cJSON* jsonpost_gift_premium_subscription_request_1 = post_gift_premium_subscription_request_convertToJSON(post_gift_premium_subscription_request_1);
	printf("post_gift_premium_subscription_request :\n%s\n", cJSON_Print(jsonpost_gift_premium_subscription_request_1));
	post_gift_premium_subscription_request_t* post_gift_premium_subscription_request_2 = post_gift_premium_subscription_request_parseFromJSON(jsonpost_gift_premium_subscription_request_1);
	cJSON* jsonpost_gift_premium_subscription_request_2 = post_gift_premium_subscription_request_convertToJSON(post_gift_premium_subscription_request_2);
	printf("repeating post_gift_premium_subscription_request:\n%s\n", cJSON_Print(jsonpost_gift_premium_subscription_request_2));
}

int main() {
  test_post_gift_premium_subscription_request(1);
  test_post_gift_premium_subscription_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // post_gift_premium_subscription_request_MAIN
#endif // post_gift_premium_subscription_request_TEST
