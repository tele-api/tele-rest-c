#ifndef refund_star_payment_response_TEST
#define refund_star_payment_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define refund_star_payment_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/refund_star_payment_response.h"
refund_star_payment_response_t* instantiate_refund_star_payment_response(int include_optional);



refund_star_payment_response_t* instantiate_refund_star_payment_response(int include_optional) {
  refund_star_payment_response_t* refund_star_payment_response = NULL;
  if (include_optional) {
    refund_star_payment_response = refund_star_payment_response_create(
      1,
      1
    );
  } else {
    refund_star_payment_response = refund_star_payment_response_create(
      1,
      1
    );
  }

  return refund_star_payment_response;
}


#ifdef refund_star_payment_response_MAIN

void test_refund_star_payment_response(int include_optional) {
    refund_star_payment_response_t* refund_star_payment_response_1 = instantiate_refund_star_payment_response(include_optional);

	cJSON* jsonrefund_star_payment_response_1 = refund_star_payment_response_convertToJSON(refund_star_payment_response_1);
	printf("refund_star_payment_response :\n%s\n", cJSON_Print(jsonrefund_star_payment_response_1));
	refund_star_payment_response_t* refund_star_payment_response_2 = refund_star_payment_response_parseFromJSON(jsonrefund_star_payment_response_1);
	cJSON* jsonrefund_star_payment_response_2 = refund_star_payment_response_convertToJSON(refund_star_payment_response_2);
	printf("repeating refund_star_payment_response:\n%s\n", cJSON_Print(jsonrefund_star_payment_response_2));
}

int main() {
  test_refund_star_payment_response(1);
  test_refund_star_payment_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // refund_star_payment_response_MAIN
#endif // refund_star_payment_response_TEST
