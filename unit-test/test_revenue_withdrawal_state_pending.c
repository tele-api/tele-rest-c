#ifndef revenue_withdrawal_state_pending_TEST
#define revenue_withdrawal_state_pending_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define revenue_withdrawal_state_pending_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/revenue_withdrawal_state_pending.h"
revenue_withdrawal_state_pending_t* instantiate_revenue_withdrawal_state_pending(int include_optional);



revenue_withdrawal_state_pending_t* instantiate_revenue_withdrawal_state_pending(int include_optional) {
  revenue_withdrawal_state_pending_t* revenue_withdrawal_state_pending = NULL;
  if (include_optional) {
    revenue_withdrawal_state_pending = revenue_withdrawal_state_pending_create(
      "pending"
    );
  } else {
    revenue_withdrawal_state_pending = revenue_withdrawal_state_pending_create(
      "pending"
    );
  }

  return revenue_withdrawal_state_pending;
}


#ifdef revenue_withdrawal_state_pending_MAIN

void test_revenue_withdrawal_state_pending(int include_optional) {
    revenue_withdrawal_state_pending_t* revenue_withdrawal_state_pending_1 = instantiate_revenue_withdrawal_state_pending(include_optional);

	cJSON* jsonrevenue_withdrawal_state_pending_1 = revenue_withdrawal_state_pending_convertToJSON(revenue_withdrawal_state_pending_1);
	printf("revenue_withdrawal_state_pending :\n%s\n", cJSON_Print(jsonrevenue_withdrawal_state_pending_1));
	revenue_withdrawal_state_pending_t* revenue_withdrawal_state_pending_2 = revenue_withdrawal_state_pending_parseFromJSON(jsonrevenue_withdrawal_state_pending_1);
	cJSON* jsonrevenue_withdrawal_state_pending_2 = revenue_withdrawal_state_pending_convertToJSON(revenue_withdrawal_state_pending_2);
	printf("repeating revenue_withdrawal_state_pending:\n%s\n", cJSON_Print(jsonrevenue_withdrawal_state_pending_2));
}

int main() {
  test_revenue_withdrawal_state_pending(1);
  test_revenue_withdrawal_state_pending(0);

  printf("Hello world \n");
  return 0;
}

#endif // revenue_withdrawal_state_pending_MAIN
#endif // revenue_withdrawal_state_pending_TEST
