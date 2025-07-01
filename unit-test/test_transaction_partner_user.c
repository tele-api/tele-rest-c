#ifndef transaction_partner_user_TEST
#define transaction_partner_user_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define transaction_partner_user_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/transaction_partner_user.h"
transaction_partner_user_t* instantiate_transaction_partner_user(int include_optional);

#include "test_user.c"
#include "test_affiliate_info.c"
#include "test_gift.c"


transaction_partner_user_t* instantiate_transaction_partner_user(int include_optional) {
  transaction_partner_user_t* transaction_partner_user = NULL;
  if (include_optional) {
    transaction_partner_user = transaction_partner_user_create(
      "user",
      telegram_bot_api_transaction_partner_user_TRANSACTIONTYPE_invoice_payment,
       // false, not to have infinite recursion
      instantiate_user(0),
       // false, not to have infinite recursion
      instantiate_affiliate_info(0),
      "0",
      56,
      list_createList(),
      "0",
       // false, not to have infinite recursion
      instantiate_gift(0),
      56
    );
  } else {
    transaction_partner_user = transaction_partner_user_create(
      "user",
      telegram_bot_api_transaction_partner_user_TRANSACTIONTYPE_invoice_payment,
      NULL,
      NULL,
      "0",
      56,
      list_createList(),
      "0",
      NULL,
      56
    );
  }

  return transaction_partner_user;
}


#ifdef transaction_partner_user_MAIN

void test_transaction_partner_user(int include_optional) {
    transaction_partner_user_t* transaction_partner_user_1 = instantiate_transaction_partner_user(include_optional);

	cJSON* jsontransaction_partner_user_1 = transaction_partner_user_convertToJSON(transaction_partner_user_1);
	printf("transaction_partner_user :\n%s\n", cJSON_Print(jsontransaction_partner_user_1));
	transaction_partner_user_t* transaction_partner_user_2 = transaction_partner_user_parseFromJSON(jsontransaction_partner_user_1);
	cJSON* jsontransaction_partner_user_2 = transaction_partner_user_convertToJSON(transaction_partner_user_2);
	printf("repeating transaction_partner_user:\n%s\n", cJSON_Print(jsontransaction_partner_user_2));
}

int main() {
  test_transaction_partner_user(1);
  test_transaction_partner_user(0);

  printf("Hello world \n");
  return 0;
}

#endif // transaction_partner_user_MAIN
#endif // transaction_partner_user_TEST
