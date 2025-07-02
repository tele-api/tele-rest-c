#ifndef verify_chat_response_TEST
#define verify_chat_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define verify_chat_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/verify_chat_response.h"
verify_chat_response_t* instantiate_verify_chat_response(int include_optional);



verify_chat_response_t* instantiate_verify_chat_response(int include_optional) {
  verify_chat_response_t* verify_chat_response = NULL;
  if (include_optional) {
    verify_chat_response = verify_chat_response_create(
      1,
      1
    );
  } else {
    verify_chat_response = verify_chat_response_create(
      1,
      1
    );
  }

  return verify_chat_response;
}


#ifdef verify_chat_response_MAIN

void test_verify_chat_response(int include_optional) {
    verify_chat_response_t* verify_chat_response_1 = instantiate_verify_chat_response(include_optional);

	cJSON* jsonverify_chat_response_1 = verify_chat_response_convertToJSON(verify_chat_response_1);
	printf("verify_chat_response :\n%s\n", cJSON_Print(jsonverify_chat_response_1));
	verify_chat_response_t* verify_chat_response_2 = verify_chat_response_parseFromJSON(jsonverify_chat_response_1);
	cJSON* jsonverify_chat_response_2 = verify_chat_response_convertToJSON(verify_chat_response_2);
	printf("repeating verify_chat_response:\n%s\n", cJSON_Print(jsonverify_chat_response_2));
}

int main() {
  test_verify_chat_response(1);
  test_verify_chat_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // verify_chat_response_MAIN
#endif // verify_chat_response_TEST
