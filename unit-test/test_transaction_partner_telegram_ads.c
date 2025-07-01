#ifndef transaction_partner_telegram_ads_TEST
#define transaction_partner_telegram_ads_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define transaction_partner_telegram_ads_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/transaction_partner_telegram_ads.h"
transaction_partner_telegram_ads_t* instantiate_transaction_partner_telegram_ads(int include_optional);



transaction_partner_telegram_ads_t* instantiate_transaction_partner_telegram_ads(int include_optional) {
  transaction_partner_telegram_ads_t* transaction_partner_telegram_ads = NULL;
  if (include_optional) {
    transaction_partner_telegram_ads = transaction_partner_telegram_ads_create(
      "telegram_ads"
    );
  } else {
    transaction_partner_telegram_ads = transaction_partner_telegram_ads_create(
      "telegram_ads"
    );
  }

  return transaction_partner_telegram_ads;
}


#ifdef transaction_partner_telegram_ads_MAIN

void test_transaction_partner_telegram_ads(int include_optional) {
    transaction_partner_telegram_ads_t* transaction_partner_telegram_ads_1 = instantiate_transaction_partner_telegram_ads(include_optional);

	cJSON* jsontransaction_partner_telegram_ads_1 = transaction_partner_telegram_ads_convertToJSON(transaction_partner_telegram_ads_1);
	printf("transaction_partner_telegram_ads :\n%s\n", cJSON_Print(jsontransaction_partner_telegram_ads_1));
	transaction_partner_telegram_ads_t* transaction_partner_telegram_ads_2 = transaction_partner_telegram_ads_parseFromJSON(jsontransaction_partner_telegram_ads_1);
	cJSON* jsontransaction_partner_telegram_ads_2 = transaction_partner_telegram_ads_convertToJSON(transaction_partner_telegram_ads_2);
	printf("repeating transaction_partner_telegram_ads:\n%s\n", cJSON_Print(jsontransaction_partner_telegram_ads_2));
}

int main() {
  test_transaction_partner_telegram_ads(1);
  test_transaction_partner_telegram_ads(0);

  printf("Hello world \n");
  return 0;
}

#endif // transaction_partner_telegram_ads_MAIN
#endif // transaction_partner_telegram_ads_TEST
