#ifndef transaction_partner_fragment_TEST
#define transaction_partner_fragment_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define transaction_partner_fragment_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/transaction_partner_fragment.h"
transaction_partner_fragment_t* instantiate_transaction_partner_fragment(int include_optional);

#include "test_revenue_withdrawal_state.c"


transaction_partner_fragment_t* instantiate_transaction_partner_fragment(int include_optional) {
  transaction_partner_fragment_t* transaction_partner_fragment = NULL;
  if (include_optional) {
    transaction_partner_fragment = transaction_partner_fragment_create(
      "fragment",
      null
    );
  } else {
    transaction_partner_fragment = transaction_partner_fragment_create(
      "fragment",
      null
    );
  }

  return transaction_partner_fragment;
}


#ifdef transaction_partner_fragment_MAIN

void test_transaction_partner_fragment(int include_optional) {
    transaction_partner_fragment_t* transaction_partner_fragment_1 = instantiate_transaction_partner_fragment(include_optional);

	cJSON* jsontransaction_partner_fragment_1 = transaction_partner_fragment_convertToJSON(transaction_partner_fragment_1);
	printf("transaction_partner_fragment :\n%s\n", cJSON_Print(jsontransaction_partner_fragment_1));
	transaction_partner_fragment_t* transaction_partner_fragment_2 = transaction_partner_fragment_parseFromJSON(jsontransaction_partner_fragment_1);
	cJSON* jsontransaction_partner_fragment_2 = transaction_partner_fragment_convertToJSON(transaction_partner_fragment_2);
	printf("repeating transaction_partner_fragment:\n%s\n", cJSON_Print(jsontransaction_partner_fragment_2));
}

int main() {
  test_transaction_partner_fragment(1);
  test_transaction_partner_fragment(0);

  printf("Hello world \n");
  return 0;
}

#endif // transaction_partner_fragment_MAIN
#endif // transaction_partner_fragment_TEST
