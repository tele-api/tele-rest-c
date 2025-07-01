#ifndef transaction_partner_TEST
#define transaction_partner_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define transaction_partner_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/transaction_partner.h"
transaction_partner_t* instantiate_transaction_partner(int include_optional);

#include "test_user.c"
#include "test_chat.c"
#include "test_affiliate_info.c"
#include "test_gift.c"
#include "test_user.c"
#include "test_revenue_withdrawal_state.c"


transaction_partner_t* instantiate_transaction_partner(int include_optional) {
  transaction_partner_t* transaction_partner = NULL;
  if (include_optional) {
    transaction_partner = transaction_partner_create(
      "other",
      telegram_bot_api_transaction_partner_TRANSACTIONTYPE_invoice_payment,
       // false, not to have infinite recursion
      instantiate_user(0),
       // false, not to have infinite recursion
      instantiate_chat(0),
      56,
      56,
       // false, not to have infinite recursion
      instantiate_affiliate_info(0),
      "0",
      56,
      list_createList(),
      "0",
       // false, not to have infinite recursion
      instantiate_gift(0),
      56,
       // false, not to have infinite recursion
      instantiate_user(0),
      null
    );
  } else {
    transaction_partner = transaction_partner_create(
      "other",
      telegram_bot_api_transaction_partner_TRANSACTIONTYPE_invoice_payment,
      NULL,
      NULL,
      56,
      56,
      NULL,
      "0",
      56,
      list_createList(),
      "0",
      NULL,
      56,
      NULL,
      null
    );
  }

  return transaction_partner;
}


#ifdef transaction_partner_MAIN

void test_transaction_partner(int include_optional) {
    transaction_partner_t* transaction_partner_1 = instantiate_transaction_partner(include_optional);

	cJSON* jsontransaction_partner_1 = transaction_partner_convertToJSON(transaction_partner_1);
	printf("transaction_partner :\n%s\n", cJSON_Print(jsontransaction_partner_1));
	transaction_partner_t* transaction_partner_2 = transaction_partner_parseFromJSON(jsontransaction_partner_1);
	cJSON* jsontransaction_partner_2 = transaction_partner_convertToJSON(transaction_partner_2);
	printf("repeating transaction_partner:\n%s\n", cJSON_Print(jsontransaction_partner_2));
}

int main() {
  test_transaction_partner(1);
  test_transaction_partner(0);

  printf("Hello world \n");
  return 0;
}

#endif // transaction_partner_MAIN
#endif // transaction_partner_TEST
