#ifndef gift_premium_subscription_response_TEST
#define gift_premium_subscription_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define gift_premium_subscription_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/gift_premium_subscription_response.h"
gift_premium_subscription_response_t* instantiate_gift_premium_subscription_response(int include_optional);



gift_premium_subscription_response_t* instantiate_gift_premium_subscription_response(int include_optional) {
  gift_premium_subscription_response_t* gift_premium_subscription_response = NULL;
  if (include_optional) {
    gift_premium_subscription_response = gift_premium_subscription_response_create(
      1,
      1
    );
  } else {
    gift_premium_subscription_response = gift_premium_subscription_response_create(
      1,
      1
    );
  }

  return gift_premium_subscription_response;
}


#ifdef gift_premium_subscription_response_MAIN

void test_gift_premium_subscription_response(int include_optional) {
    gift_premium_subscription_response_t* gift_premium_subscription_response_1 = instantiate_gift_premium_subscription_response(include_optional);

	cJSON* jsongift_premium_subscription_response_1 = gift_premium_subscription_response_convertToJSON(gift_premium_subscription_response_1);
	printf("gift_premium_subscription_response :\n%s\n", cJSON_Print(jsongift_premium_subscription_response_1));
	gift_premium_subscription_response_t* gift_premium_subscription_response_2 = gift_premium_subscription_response_parseFromJSON(jsongift_premium_subscription_response_1);
	cJSON* jsongift_premium_subscription_response_2 = gift_premium_subscription_response_convertToJSON(gift_premium_subscription_response_2);
	printf("repeating gift_premium_subscription_response:\n%s\n", cJSON_Print(jsongift_premium_subscription_response_2));
}

int main() {
  test_gift_premium_subscription_response(1);
  test_gift_premium_subscription_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // gift_premium_subscription_response_MAIN
#endif // gift_premium_subscription_response_TEST
