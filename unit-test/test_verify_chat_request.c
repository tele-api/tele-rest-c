#ifndef verify_chat_request_TEST
#define verify_chat_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define verify_chat_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/verify_chat_request.h"
verify_chat_request_t* instantiate_verify_chat_request(int include_optional);

#include "test_send_message_request_chat_id.c"


verify_chat_request_t* instantiate_verify_chat_request(int include_optional) {
  verify_chat_request_t* verify_chat_request = NULL;
  if (include_optional) {
    verify_chat_request = verify_chat_request_create(
      null,
      "0"
    );
  } else {
    verify_chat_request = verify_chat_request_create(
      null,
      "0"
    );
  }

  return verify_chat_request;
}


#ifdef verify_chat_request_MAIN

void test_verify_chat_request(int include_optional) {
    verify_chat_request_t* verify_chat_request_1 = instantiate_verify_chat_request(include_optional);

	cJSON* jsonverify_chat_request_1 = verify_chat_request_convertToJSON(verify_chat_request_1);
	printf("verify_chat_request :\n%s\n", cJSON_Print(jsonverify_chat_request_1));
	verify_chat_request_t* verify_chat_request_2 = verify_chat_request_parseFromJSON(jsonverify_chat_request_1);
	cJSON* jsonverify_chat_request_2 = verify_chat_request_convertToJSON(verify_chat_request_2);
	printf("repeating verify_chat_request:\n%s\n", cJSON_Print(jsonverify_chat_request_2));
}

int main() {
  test_verify_chat_request(1);
  test_verify_chat_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // verify_chat_request_MAIN
#endif // verify_chat_request_TEST
