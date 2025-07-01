#ifndef transaction_partner_other_TEST
#define transaction_partner_other_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define transaction_partner_other_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/transaction_partner_other.h"
transaction_partner_other_t* instantiate_transaction_partner_other(int include_optional);



transaction_partner_other_t* instantiate_transaction_partner_other(int include_optional) {
  transaction_partner_other_t* transaction_partner_other = NULL;
  if (include_optional) {
    transaction_partner_other = transaction_partner_other_create(
      "other"
    );
  } else {
    transaction_partner_other = transaction_partner_other_create(
      "other"
    );
  }

  return transaction_partner_other;
}


#ifdef transaction_partner_other_MAIN

void test_transaction_partner_other(int include_optional) {
    transaction_partner_other_t* transaction_partner_other_1 = instantiate_transaction_partner_other(include_optional);

	cJSON* jsontransaction_partner_other_1 = transaction_partner_other_convertToJSON(transaction_partner_other_1);
	printf("transaction_partner_other :\n%s\n", cJSON_Print(jsontransaction_partner_other_1));
	transaction_partner_other_t* transaction_partner_other_2 = transaction_partner_other_parseFromJSON(jsontransaction_partner_other_1);
	cJSON* jsontransaction_partner_other_2 = transaction_partner_other_convertToJSON(transaction_partner_other_2);
	printf("repeating transaction_partner_other:\n%s\n", cJSON_Print(jsontransaction_partner_other_2));
}

int main() {
  test_transaction_partner_other(1);
  test_transaction_partner_other(0);

  printf("Hello world \n");
  return 0;
}

#endif // transaction_partner_other_MAIN
#endif // transaction_partner_other_TEST
