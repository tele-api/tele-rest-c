#ifndef transaction_partner_chat_TEST
#define transaction_partner_chat_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define transaction_partner_chat_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/transaction_partner_chat.h"
transaction_partner_chat_t* instantiate_transaction_partner_chat(int include_optional);

#include "test_chat.c"
#include "test_gift.c"


transaction_partner_chat_t* instantiate_transaction_partner_chat(int include_optional) {
  transaction_partner_chat_t* transaction_partner_chat = NULL;
  if (include_optional) {
    transaction_partner_chat = transaction_partner_chat_create(
      "chat",
       // false, not to have infinite recursion
      instantiate_chat(0),
       // false, not to have infinite recursion
      instantiate_gift(0)
    );
  } else {
    transaction_partner_chat = transaction_partner_chat_create(
      "chat",
      NULL,
      NULL
    );
  }

  return transaction_partner_chat;
}


#ifdef transaction_partner_chat_MAIN

void test_transaction_partner_chat(int include_optional) {
    transaction_partner_chat_t* transaction_partner_chat_1 = instantiate_transaction_partner_chat(include_optional);

	cJSON* jsontransaction_partner_chat_1 = transaction_partner_chat_convertToJSON(transaction_partner_chat_1);
	printf("transaction_partner_chat :\n%s\n", cJSON_Print(jsontransaction_partner_chat_1));
	transaction_partner_chat_t* transaction_partner_chat_2 = transaction_partner_chat_parseFromJSON(jsontransaction_partner_chat_1);
	cJSON* jsontransaction_partner_chat_2 = transaction_partner_chat_convertToJSON(transaction_partner_chat_2);
	printf("repeating transaction_partner_chat:\n%s\n", cJSON_Print(jsontransaction_partner_chat_2));
}

int main() {
  test_transaction_partner_chat(1);
  test_transaction_partner_chat(0);

  printf("Hello world \n");
  return 0;
}

#endif // transaction_partner_chat_MAIN
#endif // transaction_partner_chat_TEST
