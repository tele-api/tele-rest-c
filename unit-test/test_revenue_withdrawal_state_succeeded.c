#ifndef revenue_withdrawal_state_succeeded_TEST
#define revenue_withdrawal_state_succeeded_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define revenue_withdrawal_state_succeeded_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/revenue_withdrawal_state_succeeded.h"
revenue_withdrawal_state_succeeded_t* instantiate_revenue_withdrawal_state_succeeded(int include_optional);



revenue_withdrawal_state_succeeded_t* instantiate_revenue_withdrawal_state_succeeded(int include_optional) {
  revenue_withdrawal_state_succeeded_t* revenue_withdrawal_state_succeeded = NULL;
  if (include_optional) {
    revenue_withdrawal_state_succeeded = revenue_withdrawal_state_succeeded_create(
      "succeeded",
      56,
      "0"
    );
  } else {
    revenue_withdrawal_state_succeeded = revenue_withdrawal_state_succeeded_create(
      "succeeded",
      56,
      "0"
    );
  }

  return revenue_withdrawal_state_succeeded;
}


#ifdef revenue_withdrawal_state_succeeded_MAIN

void test_revenue_withdrawal_state_succeeded(int include_optional) {
    revenue_withdrawal_state_succeeded_t* revenue_withdrawal_state_succeeded_1 = instantiate_revenue_withdrawal_state_succeeded(include_optional);

	cJSON* jsonrevenue_withdrawal_state_succeeded_1 = revenue_withdrawal_state_succeeded_convertToJSON(revenue_withdrawal_state_succeeded_1);
	printf("revenue_withdrawal_state_succeeded :\n%s\n", cJSON_Print(jsonrevenue_withdrawal_state_succeeded_1));
	revenue_withdrawal_state_succeeded_t* revenue_withdrawal_state_succeeded_2 = revenue_withdrawal_state_succeeded_parseFromJSON(jsonrevenue_withdrawal_state_succeeded_1);
	cJSON* jsonrevenue_withdrawal_state_succeeded_2 = revenue_withdrawal_state_succeeded_convertToJSON(revenue_withdrawal_state_succeeded_2);
	printf("repeating revenue_withdrawal_state_succeeded:\n%s\n", cJSON_Print(jsonrevenue_withdrawal_state_succeeded_2));
}

int main() {
  test_revenue_withdrawal_state_succeeded(1);
  test_revenue_withdrawal_state_succeeded(0);

  printf("Hello world \n");
  return 0;
}

#endif // revenue_withdrawal_state_succeeded_MAIN
#endif // revenue_withdrawal_state_succeeded_TEST
