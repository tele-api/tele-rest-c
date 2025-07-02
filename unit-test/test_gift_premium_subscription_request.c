#ifndef gift_premium_subscription_request_TEST
#define gift_premium_subscription_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define gift_premium_subscription_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/gift_premium_subscription_request.h"
gift_premium_subscription_request_t* instantiate_gift_premium_subscription_request(int include_optional);



gift_premium_subscription_request_t* instantiate_gift_premium_subscription_request(int include_optional) {
  gift_premium_subscription_request_t* gift_premium_subscription_request = NULL;
  if (include_optional) {
    gift_premium_subscription_request = gift_premium_subscription_request_create(
      56,
      telegram_bot_api_gift_premium_subscription_request_MONTHCOUNT_3,
      56,
      "0",
      "0",
      list_createList()
    );
  } else {
    gift_premium_subscription_request = gift_premium_subscription_request_create(
      56,
      telegram_bot_api_gift_premium_subscription_request_MONTHCOUNT_3,
      56,
      "0",
      "0",
      list_createList()
    );
  }

  return gift_premium_subscription_request;
}


#ifdef gift_premium_subscription_request_MAIN

void test_gift_premium_subscription_request(int include_optional) {
    gift_premium_subscription_request_t* gift_premium_subscription_request_1 = instantiate_gift_premium_subscription_request(include_optional);

	cJSON* jsongift_premium_subscription_request_1 = gift_premium_subscription_request_convertToJSON(gift_premium_subscription_request_1);
	printf("gift_premium_subscription_request :\n%s\n", cJSON_Print(jsongift_premium_subscription_request_1));
	gift_premium_subscription_request_t* gift_premium_subscription_request_2 = gift_premium_subscription_request_parseFromJSON(jsongift_premium_subscription_request_1);
	cJSON* jsongift_premium_subscription_request_2 = gift_premium_subscription_request_convertToJSON(gift_premium_subscription_request_2);
	printf("repeating gift_premium_subscription_request:\n%s\n", cJSON_Print(jsongift_premium_subscription_request_2));
}

int main() {
  test_gift_premium_subscription_request(1);
  test_gift_premium_subscription_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // gift_premium_subscription_request_MAIN
#endif // gift_premium_subscription_request_TEST
