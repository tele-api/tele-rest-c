#ifndef unban_chat_sender_chat_response_TEST
#define unban_chat_sender_chat_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define unban_chat_sender_chat_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/unban_chat_sender_chat_response.h"
unban_chat_sender_chat_response_t* instantiate_unban_chat_sender_chat_response(int include_optional);



unban_chat_sender_chat_response_t* instantiate_unban_chat_sender_chat_response(int include_optional) {
  unban_chat_sender_chat_response_t* unban_chat_sender_chat_response = NULL;
  if (include_optional) {
    unban_chat_sender_chat_response = unban_chat_sender_chat_response_create(
      1,
      1
    );
  } else {
    unban_chat_sender_chat_response = unban_chat_sender_chat_response_create(
      1,
      1
    );
  }

  return unban_chat_sender_chat_response;
}


#ifdef unban_chat_sender_chat_response_MAIN

void test_unban_chat_sender_chat_response(int include_optional) {
    unban_chat_sender_chat_response_t* unban_chat_sender_chat_response_1 = instantiate_unban_chat_sender_chat_response(include_optional);

	cJSON* jsonunban_chat_sender_chat_response_1 = unban_chat_sender_chat_response_convertToJSON(unban_chat_sender_chat_response_1);
	printf("unban_chat_sender_chat_response :\n%s\n", cJSON_Print(jsonunban_chat_sender_chat_response_1));
	unban_chat_sender_chat_response_t* unban_chat_sender_chat_response_2 = unban_chat_sender_chat_response_parseFromJSON(jsonunban_chat_sender_chat_response_1);
	cJSON* jsonunban_chat_sender_chat_response_2 = unban_chat_sender_chat_response_convertToJSON(unban_chat_sender_chat_response_2);
	printf("repeating unban_chat_sender_chat_response:\n%s\n", cJSON_Print(jsonunban_chat_sender_chat_response_2));
}

int main() {
  test_unban_chat_sender_chat_response(1);
  test_unban_chat_sender_chat_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // unban_chat_sender_chat_response_MAIN
#endif // unban_chat_sender_chat_response_TEST
