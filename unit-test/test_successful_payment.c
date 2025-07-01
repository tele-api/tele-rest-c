#ifndef successful_payment_TEST
#define successful_payment_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define successful_payment_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/successful_payment.h"
successful_payment_t* instantiate_successful_payment(int include_optional);

#include "test_order_info.c"


successful_payment_t* instantiate_successful_payment(int include_optional) {
  successful_payment_t* successful_payment = NULL;
  if (include_optional) {
    successful_payment = successful_payment_create(
      "0",
      56,
      "0",
      "0",
      "0",
      56,
      1,
      1,
      "0",
       // false, not to have infinite recursion
      instantiate_order_info(0)
    );
  } else {
    successful_payment = successful_payment_create(
      "0",
      56,
      "0",
      "0",
      "0",
      56,
      1,
      1,
      "0",
      NULL
    );
  }

  return successful_payment;
}


#ifdef successful_payment_MAIN

void test_successful_payment(int include_optional) {
    successful_payment_t* successful_payment_1 = instantiate_successful_payment(include_optional);

	cJSON* jsonsuccessful_payment_1 = successful_payment_convertToJSON(successful_payment_1);
	printf("successful_payment :\n%s\n", cJSON_Print(jsonsuccessful_payment_1));
	successful_payment_t* successful_payment_2 = successful_payment_parseFromJSON(jsonsuccessful_payment_1);
	cJSON* jsonsuccessful_payment_2 = successful_payment_convertToJSON(successful_payment_2);
	printf("repeating successful_payment:\n%s\n", cJSON_Print(jsonsuccessful_payment_2));
}

int main() {
  test_successful_payment(1);
  test_successful_payment(0);

  printf("Hello world \n");
  return 0;
}

#endif // successful_payment_MAIN
#endif // successful_payment_TEST
