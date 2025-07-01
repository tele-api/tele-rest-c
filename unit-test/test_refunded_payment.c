#ifndef refunded_payment_TEST
#define refunded_payment_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define refunded_payment_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/refunded_payment.h"
refunded_payment_t* instantiate_refunded_payment(int include_optional);



refunded_payment_t* instantiate_refunded_payment(int include_optional) {
  refunded_payment_t* refunded_payment = NULL;
  if (include_optional) {
    refunded_payment = refunded_payment_create(
      "XTR",
      56,
      "0",
      "0",
      "0"
    );
  } else {
    refunded_payment = refunded_payment_create(
      "XTR",
      56,
      "0",
      "0",
      "0"
    );
  }

  return refunded_payment;
}


#ifdef refunded_payment_MAIN

void test_refunded_payment(int include_optional) {
    refunded_payment_t* refunded_payment_1 = instantiate_refunded_payment(include_optional);

	cJSON* jsonrefunded_payment_1 = refunded_payment_convertToJSON(refunded_payment_1);
	printf("refunded_payment :\n%s\n", cJSON_Print(jsonrefunded_payment_1));
	refunded_payment_t* refunded_payment_2 = refunded_payment_parseFromJSON(jsonrefunded_payment_1);
	cJSON* jsonrefunded_payment_2 = refunded_payment_convertToJSON(refunded_payment_2);
	printf("repeating refunded_payment:\n%s\n", cJSON_Print(jsonrefunded_payment_2));
}

int main() {
  test_refunded_payment(1);
  test_refunded_payment(0);

  printf("Hello world \n");
  return 0;
}

#endif // refunded_payment_MAIN
#endif // refunded_payment_TEST
