#ifndef revenue_withdrawal_state_TEST
#define revenue_withdrawal_state_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define revenue_withdrawal_state_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/revenue_withdrawal_state.h"
revenue_withdrawal_state_t* instantiate_revenue_withdrawal_state(int include_optional);



revenue_withdrawal_state_t* instantiate_revenue_withdrawal_state(int include_optional) {
  revenue_withdrawal_state_t* revenue_withdrawal_state = NULL;
  if (include_optional) {
    revenue_withdrawal_state = revenue_withdrawal_state_create(
      "failed",
      56,
      "0"
    );
  } else {
    revenue_withdrawal_state = revenue_withdrawal_state_create(
      "failed",
      56,
      "0"
    );
  }

  return revenue_withdrawal_state;
}


#ifdef revenue_withdrawal_state_MAIN

void test_revenue_withdrawal_state(int include_optional) {
    revenue_withdrawal_state_t* revenue_withdrawal_state_1 = instantiate_revenue_withdrawal_state(include_optional);

	cJSON* jsonrevenue_withdrawal_state_1 = revenue_withdrawal_state_convertToJSON(revenue_withdrawal_state_1);
	printf("revenue_withdrawal_state :\n%s\n", cJSON_Print(jsonrevenue_withdrawal_state_1));
	revenue_withdrawal_state_t* revenue_withdrawal_state_2 = revenue_withdrawal_state_parseFromJSON(jsonrevenue_withdrawal_state_1);
	cJSON* jsonrevenue_withdrawal_state_2 = revenue_withdrawal_state_convertToJSON(revenue_withdrawal_state_2);
	printf("repeating revenue_withdrawal_state:\n%s\n", cJSON_Print(jsonrevenue_withdrawal_state_2));
}

int main() {
  test_revenue_withdrawal_state(1);
  test_revenue_withdrawal_state(0);

  printf("Hello world \n");
  return 0;
}

#endif // revenue_withdrawal_state_MAIN
#endif // revenue_withdrawal_state_TEST
