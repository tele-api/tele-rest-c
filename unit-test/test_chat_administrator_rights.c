#ifndef chat_administrator_rights_TEST
#define chat_administrator_rights_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define chat_administrator_rights_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/chat_administrator_rights.h"
chat_administrator_rights_t* instantiate_chat_administrator_rights(int include_optional);



chat_administrator_rights_t* instantiate_chat_administrator_rights(int include_optional) {
  chat_administrator_rights_t* chat_administrator_rights = NULL;
  if (include_optional) {
    chat_administrator_rights = chat_administrator_rights_create(
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1
    );
  } else {
    chat_administrator_rights = chat_administrator_rights_create(
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1
    );
  }

  return chat_administrator_rights;
}


#ifdef chat_administrator_rights_MAIN

void test_chat_administrator_rights(int include_optional) {
    chat_administrator_rights_t* chat_administrator_rights_1 = instantiate_chat_administrator_rights(include_optional);

	cJSON* jsonchat_administrator_rights_1 = chat_administrator_rights_convertToJSON(chat_administrator_rights_1);
	printf("chat_administrator_rights :\n%s\n", cJSON_Print(jsonchat_administrator_rights_1));
	chat_administrator_rights_t* chat_administrator_rights_2 = chat_administrator_rights_parseFromJSON(jsonchat_administrator_rights_1);
	cJSON* jsonchat_administrator_rights_2 = chat_administrator_rights_convertToJSON(chat_administrator_rights_2);
	printf("repeating chat_administrator_rights:\n%s\n", cJSON_Print(jsonchat_administrator_rights_2));
}

int main() {
  test_chat_administrator_rights(1);
  test_chat_administrator_rights(0);

  printf("Hello world \n");
  return 0;
}

#endif // chat_administrator_rights_MAIN
#endif // chat_administrator_rights_TEST
