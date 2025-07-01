#ifndef revenue_withdrawal_state_failed_TEST
#define revenue_withdrawal_state_failed_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define revenue_withdrawal_state_failed_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/revenue_withdrawal_state_failed.h"
revenue_withdrawal_state_failed_t* instantiate_revenue_withdrawal_state_failed(int include_optional);



revenue_withdrawal_state_failed_t* instantiate_revenue_withdrawal_state_failed(int include_optional) {
  revenue_withdrawal_state_failed_t* revenue_withdrawal_state_failed = NULL;
  if (include_optional) {
    revenue_withdrawal_state_failed = revenue_withdrawal_state_failed_create(
      "failed"
    );
  } else {
    revenue_withdrawal_state_failed = revenue_withdrawal_state_failed_create(
      "failed"
    );
  }

  return revenue_withdrawal_state_failed;
}


#ifdef revenue_withdrawal_state_failed_MAIN

void test_revenue_withdrawal_state_failed(int include_optional) {
    revenue_withdrawal_state_failed_t* revenue_withdrawal_state_failed_1 = instantiate_revenue_withdrawal_state_failed(include_optional);

	cJSON* jsonrevenue_withdrawal_state_failed_1 = revenue_withdrawal_state_failed_convertToJSON(revenue_withdrawal_state_failed_1);
	printf("revenue_withdrawal_state_failed :\n%s\n", cJSON_Print(jsonrevenue_withdrawal_state_failed_1));
	revenue_withdrawal_state_failed_t* revenue_withdrawal_state_failed_2 = revenue_withdrawal_state_failed_parseFromJSON(jsonrevenue_withdrawal_state_failed_1);
	cJSON* jsonrevenue_withdrawal_state_failed_2 = revenue_withdrawal_state_failed_convertToJSON(revenue_withdrawal_state_failed_2);
	printf("repeating revenue_withdrawal_state_failed:\n%s\n", cJSON_Print(jsonrevenue_withdrawal_state_failed_2));
}

int main() {
  test_revenue_withdrawal_state_failed(1);
  test_revenue_withdrawal_state_failed(0);

  printf("Hello world \n");
  return 0;
}

#endif // revenue_withdrawal_state_failed_MAIN
#endif // revenue_withdrawal_state_failed_TEST
