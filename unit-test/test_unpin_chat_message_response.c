#ifndef unpin_chat_message_response_TEST
#define unpin_chat_message_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define unpin_chat_message_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/unpin_chat_message_response.h"
unpin_chat_message_response_t* instantiate_unpin_chat_message_response(int include_optional);



unpin_chat_message_response_t* instantiate_unpin_chat_message_response(int include_optional) {
  unpin_chat_message_response_t* unpin_chat_message_response = NULL;
  if (include_optional) {
    unpin_chat_message_response = unpin_chat_message_response_create(
      1,
      1
    );
  } else {
    unpin_chat_message_response = unpin_chat_message_response_create(
      1,
      1
    );
  }

  return unpin_chat_message_response;
}


#ifdef unpin_chat_message_response_MAIN

void test_unpin_chat_message_response(int include_optional) {
    unpin_chat_message_response_t* unpin_chat_message_response_1 = instantiate_unpin_chat_message_response(include_optional);

	cJSON* jsonunpin_chat_message_response_1 = unpin_chat_message_response_convertToJSON(unpin_chat_message_response_1);
	printf("unpin_chat_message_response :\n%s\n", cJSON_Print(jsonunpin_chat_message_response_1));
	unpin_chat_message_response_t* unpin_chat_message_response_2 = unpin_chat_message_response_parseFromJSON(jsonunpin_chat_message_response_1);
	cJSON* jsonunpin_chat_message_response_2 = unpin_chat_message_response_convertToJSON(unpin_chat_message_response_2);
	printf("repeating unpin_chat_message_response:\n%s\n", cJSON_Print(jsonunpin_chat_message_response_2));
}

int main() {
  test_unpin_chat_message_response(1);
  test_unpin_chat_message_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // unpin_chat_message_response_MAIN
#endif // unpin_chat_message_response_TEST
