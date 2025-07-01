#ifndef chat_permissions_TEST
#define chat_permissions_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define chat_permissions_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/chat_permissions.h"
chat_permissions_t* instantiate_chat_permissions(int include_optional);



chat_permissions_t* instantiate_chat_permissions(int include_optional) {
  chat_permissions_t* chat_permissions = NULL;
  if (include_optional) {
    chat_permissions = chat_permissions_create(
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
    chat_permissions = chat_permissions_create(
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

  return chat_permissions;
}


#ifdef chat_permissions_MAIN

void test_chat_permissions(int include_optional) {
    chat_permissions_t* chat_permissions_1 = instantiate_chat_permissions(include_optional);

	cJSON* jsonchat_permissions_1 = chat_permissions_convertToJSON(chat_permissions_1);
	printf("chat_permissions :\n%s\n", cJSON_Print(jsonchat_permissions_1));
	chat_permissions_t* chat_permissions_2 = chat_permissions_parseFromJSON(jsonchat_permissions_1);
	cJSON* jsonchat_permissions_2 = chat_permissions_convertToJSON(chat_permissions_2);
	printf("repeating chat_permissions:\n%s\n", cJSON_Print(jsonchat_permissions_2));
}

int main() {
  test_chat_permissions(1);
  test_chat_permissions(0);

  printf("Hello world \n");
  return 0;
}

#endif // chat_permissions_MAIN
#endif // chat_permissions_TEST
