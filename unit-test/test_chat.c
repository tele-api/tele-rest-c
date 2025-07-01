#ifndef chat_TEST
#define chat_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define chat_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/chat.h"
chat_t* instantiate_chat(int include_optional);



chat_t* instantiate_chat(int include_optional) {
  chat_t* chat = NULL;
  if (include_optional) {
    chat = chat_create(
      56,
      telegram_bot_api_chat_TYPE_private,
      "0",
      "0",
      "0",
      "0",
      1
    );
  } else {
    chat = chat_create(
      56,
      telegram_bot_api_chat_TYPE_private,
      "0",
      "0",
      "0",
      "0",
      1
    );
  }

  return chat;
}


#ifdef chat_MAIN

void test_chat(int include_optional) {
    chat_t* chat_1 = instantiate_chat(include_optional);

	cJSON* jsonchat_1 = chat_convertToJSON(chat_1);
	printf("chat :\n%s\n", cJSON_Print(jsonchat_1));
	chat_t* chat_2 = chat_parseFromJSON(jsonchat_1);
	cJSON* jsonchat_2 = chat_convertToJSON(chat_2);
	printf("repeating chat:\n%s\n", cJSON_Print(jsonchat_2));
}

int main() {
  test_chat(1);
  test_chat(0);

  printf("Hello world \n");
  return 0;
}

#endif // chat_MAIN
#endif // chat_TEST
