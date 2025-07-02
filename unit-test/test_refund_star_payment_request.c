#ifndef refund_star_payment_request_TEST
#define refund_star_payment_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define refund_star_payment_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/refund_star_payment_request.h"
refund_star_payment_request_t* instantiate_refund_star_payment_request(int include_optional);



refund_star_payment_request_t* instantiate_refund_star_payment_request(int include_optional) {
  refund_star_payment_request_t* refund_star_payment_request = NULL;
  if (include_optional) {
    refund_star_payment_request = refund_star_payment_request_create(
      56,
      "0"
    );
  } else {
    refund_star_payment_request = refund_star_payment_request_create(
      56,
      "0"
    );
  }

  return refund_star_payment_request;
}


#ifdef refund_star_payment_request_MAIN

void test_refund_star_payment_request(int include_optional) {
    refund_star_payment_request_t* refund_star_payment_request_1 = instantiate_refund_star_payment_request(include_optional);

	cJSON* jsonrefund_star_payment_request_1 = refund_star_payment_request_convertToJSON(refund_star_payment_request_1);
	printf("refund_star_payment_request :\n%s\n", cJSON_Print(jsonrefund_star_payment_request_1));
	refund_star_payment_request_t* refund_star_payment_request_2 = refund_star_payment_request_parseFromJSON(jsonrefund_star_payment_request_1);
	cJSON* jsonrefund_star_payment_request_2 = refund_star_payment_request_convertToJSON(refund_star_payment_request_2);
	printf("repeating refund_star_payment_request:\n%s\n", cJSON_Print(jsonrefund_star_payment_request_2));
}

int main() {
  test_refund_star_payment_request(1);
  test_refund_star_payment_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // refund_star_payment_request_MAIN
#endif // refund_star_payment_request_TEST
