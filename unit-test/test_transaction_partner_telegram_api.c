#ifndef transaction_partner_telegram_api_TEST
#define transaction_partner_telegram_api_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define transaction_partner_telegram_api_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/transaction_partner_telegram_api.h"
transaction_partner_telegram_api_t* instantiate_transaction_partner_telegram_api(int include_optional);



transaction_partner_telegram_api_t* instantiate_transaction_partner_telegram_api(int include_optional) {
  transaction_partner_telegram_api_t* transaction_partner_telegram_api = NULL;
  if (include_optional) {
    transaction_partner_telegram_api = transaction_partner_telegram_api_create(
      "telegram_api",
      56
    );
  } else {
    transaction_partner_telegram_api = transaction_partner_telegram_api_create(
      "telegram_api",
      56
    );
  }

  return transaction_partner_telegram_api;
}


#ifdef transaction_partner_telegram_api_MAIN

void test_transaction_partner_telegram_api(int include_optional) {
    transaction_partner_telegram_api_t* transaction_partner_telegram_api_1 = instantiate_transaction_partner_telegram_api(include_optional);

	cJSON* jsontransaction_partner_telegram_api_1 = transaction_partner_telegram_api_convertToJSON(transaction_partner_telegram_api_1);
	printf("transaction_partner_telegram_api :\n%s\n", cJSON_Print(jsontransaction_partner_telegram_api_1));
	transaction_partner_telegram_api_t* transaction_partner_telegram_api_2 = transaction_partner_telegram_api_parseFromJSON(jsontransaction_partner_telegram_api_1);
	cJSON* jsontransaction_partner_telegram_api_2 = transaction_partner_telegram_api_convertToJSON(transaction_partner_telegram_api_2);
	printf("repeating transaction_partner_telegram_api:\n%s\n", cJSON_Print(jsontransaction_partner_telegram_api_2));
}

int main() {
  test_transaction_partner_telegram_api(1);
  test_transaction_partner_telegram_api(0);

  printf("Hello world \n");
  return 0;
}

#endif // transaction_partner_telegram_api_MAIN
#endif // transaction_partner_telegram_api_TEST
