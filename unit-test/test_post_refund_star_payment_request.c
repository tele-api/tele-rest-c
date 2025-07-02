#ifndef post_refund_star_payment_request_TEST
#define post_refund_star_payment_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define post_refund_star_payment_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/post_refund_star_payment_request.h"
post_refund_star_payment_request_t* instantiate_post_refund_star_payment_request(int include_optional);



post_refund_star_payment_request_t* instantiate_post_refund_star_payment_request(int include_optional) {
  post_refund_star_payment_request_t* post_refund_star_payment_request = NULL;
  if (include_optional) {
    post_refund_star_payment_request = post_refund_star_payment_request_create(
      56,
      "0"
    );
  } else {
    post_refund_star_payment_request = post_refund_star_payment_request_create(
      56,
      "0"
    );
  }

  return post_refund_star_payment_request;
}


#ifdef post_refund_star_payment_request_MAIN

void test_post_refund_star_payment_request(int include_optional) {
    post_refund_star_payment_request_t* post_refund_star_payment_request_1 = instantiate_post_refund_star_payment_request(include_optional);

	cJSON* jsonpost_refund_star_payment_request_1 = post_refund_star_payment_request_convertToJSON(post_refund_star_payment_request_1);
	printf("post_refund_star_payment_request :\n%s\n", cJSON_Print(jsonpost_refund_star_payment_request_1));
	post_refund_star_payment_request_t* post_refund_star_payment_request_2 = post_refund_star_payment_request_parseFromJSON(jsonpost_refund_star_payment_request_1);
	cJSON* jsonpost_refund_star_payment_request_2 = post_refund_star_payment_request_convertToJSON(post_refund_star_payment_request_2);
	printf("repeating post_refund_star_payment_request:\n%s\n", cJSON_Print(jsonpost_refund_star_payment_request_2));
}

int main() {
  test_post_refund_star_payment_request(1);
  test_post_refund_star_payment_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // post_refund_star_payment_request_MAIN
#endif // post_refund_star_payment_request_TEST
