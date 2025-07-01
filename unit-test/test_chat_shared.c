#ifndef chat_shared_TEST
#define chat_shared_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define chat_shared_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/chat_shared.h"
chat_shared_t* instantiate_chat_shared(int include_optional);



chat_shared_t* instantiate_chat_shared(int include_optional) {
  chat_shared_t* chat_shared = NULL;
  if (include_optional) {
    chat_shared = chat_shared_create(
      56,
      56,
      "0",
      "0",
      list_createList()
    );
  } else {
    chat_shared = chat_shared_create(
      56,
      56,
      "0",
      "0",
      list_createList()
    );
  }

  return chat_shared;
}


#ifdef chat_shared_MAIN

void test_chat_shared(int include_optional) {
    chat_shared_t* chat_shared_1 = instantiate_chat_shared(include_optional);

	cJSON* jsonchat_shared_1 = chat_shared_convertToJSON(chat_shared_1);
	printf("chat_shared :\n%s\n", cJSON_Print(jsonchat_shared_1));
	chat_shared_t* chat_shared_2 = chat_shared_parseFromJSON(jsonchat_shared_1);
	cJSON* jsonchat_shared_2 = chat_shared_convertToJSON(chat_shared_2);
	printf("repeating chat_shared:\n%s\n", cJSON_Print(jsonchat_shared_2));
}

int main() {
  test_chat_shared(1);
  test_chat_shared(0);

  printf("Hello world \n");
  return 0;
}

#endif // chat_shared_MAIN
#endif // chat_shared_TEST
