#ifndef transaction_partner_affiliate_program_TEST
#define transaction_partner_affiliate_program_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define transaction_partner_affiliate_program_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/transaction_partner_affiliate_program.h"
transaction_partner_affiliate_program_t* instantiate_transaction_partner_affiliate_program(int include_optional);

#include "test_user.c"


transaction_partner_affiliate_program_t* instantiate_transaction_partner_affiliate_program(int include_optional) {
  transaction_partner_affiliate_program_t* transaction_partner_affiliate_program = NULL;
  if (include_optional) {
    transaction_partner_affiliate_program = transaction_partner_affiliate_program_create(
      "affiliate_program",
      56,
       // false, not to have infinite recursion
      instantiate_user(0)
    );
  } else {
    transaction_partner_affiliate_program = transaction_partner_affiliate_program_create(
      "affiliate_program",
      56,
      NULL
    );
  }

  return transaction_partner_affiliate_program;
}


#ifdef transaction_partner_affiliate_program_MAIN

void test_transaction_partner_affiliate_program(int include_optional) {
    transaction_partner_affiliate_program_t* transaction_partner_affiliate_program_1 = instantiate_transaction_partner_affiliate_program(include_optional);

	cJSON* jsontransaction_partner_affiliate_program_1 = transaction_partner_affiliate_program_convertToJSON(transaction_partner_affiliate_program_1);
	printf("transaction_partner_affiliate_program :\n%s\n", cJSON_Print(jsontransaction_partner_affiliate_program_1));
	transaction_partner_affiliate_program_t* transaction_partner_affiliate_program_2 = transaction_partner_affiliate_program_parseFromJSON(jsontransaction_partner_affiliate_program_1);
	cJSON* jsontransaction_partner_affiliate_program_2 = transaction_partner_affiliate_program_convertToJSON(transaction_partner_affiliate_program_2);
	printf("repeating transaction_partner_affiliate_program:\n%s\n", cJSON_Print(jsontransaction_partner_affiliate_program_2));
}

int main() {
  test_transaction_partner_affiliate_program(1);
  test_transaction_partner_affiliate_program(0);

  printf("Hello world \n");
  return 0;
}

#endif // transaction_partner_affiliate_program_MAIN
#endif // transaction_partner_affiliate_program_TEST
