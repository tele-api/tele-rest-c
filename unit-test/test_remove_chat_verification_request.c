#ifndef remove_chat_verification_request_TEST
#define remove_chat_verification_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define remove_chat_verification_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/remove_chat_verification_request.h"
remove_chat_verification_request_t* instantiate_remove_chat_verification_request(int include_optional);

#include "test_send_message_request_chat_id.c"


remove_chat_verification_request_t* instantiate_remove_chat_verification_request(int include_optional) {
  remove_chat_verification_request_t* remove_chat_verification_request = NULL;
  if (include_optional) {
    remove_chat_verification_request = remove_chat_verification_request_create(
      null
    );
  } else {
    remove_chat_verification_request = remove_chat_verification_request_create(
      null
    );
  }

  return remove_chat_verification_request;
}


#ifdef remove_chat_verification_request_MAIN

void test_remove_chat_verification_request(int include_optional) {
    remove_chat_verification_request_t* remove_chat_verification_request_1 = instantiate_remove_chat_verification_request(include_optional);

	cJSON* jsonremove_chat_verification_request_1 = remove_chat_verification_request_convertToJSON(remove_chat_verification_request_1);
	printf("remove_chat_verification_request :\n%s\n", cJSON_Print(jsonremove_chat_verification_request_1));
	remove_chat_verification_request_t* remove_chat_verification_request_2 = remove_chat_verification_request_parseFromJSON(jsonremove_chat_verification_request_1);
	cJSON* jsonremove_chat_verification_request_2 = remove_chat_verification_request_convertToJSON(remove_chat_verification_request_2);
	printf("repeating remove_chat_verification_request:\n%s\n", cJSON_Print(jsonremove_chat_verification_request_2));
}

int main() {
  test_remove_chat_verification_request(1);
  test_remove_chat_verification_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // remove_chat_verification_request_MAIN
#endif // remove_chat_verification_request_TEST
