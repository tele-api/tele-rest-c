#ifndef remove_chat_verification_response_TEST
#define remove_chat_verification_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define remove_chat_verification_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/remove_chat_verification_response.h"
remove_chat_verification_response_t* instantiate_remove_chat_verification_response(int include_optional);



remove_chat_verification_response_t* instantiate_remove_chat_verification_response(int include_optional) {
  remove_chat_verification_response_t* remove_chat_verification_response = NULL;
  if (include_optional) {
    remove_chat_verification_response = remove_chat_verification_response_create(
      1,
      1
    );
  } else {
    remove_chat_verification_response = remove_chat_verification_response_create(
      1,
      1
    );
  }

  return remove_chat_verification_response;
}


#ifdef remove_chat_verification_response_MAIN

void test_remove_chat_verification_response(int include_optional) {
    remove_chat_verification_response_t* remove_chat_verification_response_1 = instantiate_remove_chat_verification_response(include_optional);

	cJSON* jsonremove_chat_verification_response_1 = remove_chat_verification_response_convertToJSON(remove_chat_verification_response_1);
	printf("remove_chat_verification_response :\n%s\n", cJSON_Print(jsonremove_chat_verification_response_1));
	remove_chat_verification_response_t* remove_chat_verification_response_2 = remove_chat_verification_response_parseFromJSON(jsonremove_chat_verification_response_1);
	cJSON* jsonremove_chat_verification_response_2 = remove_chat_verification_response_convertToJSON(remove_chat_verification_response_2);
	printf("repeating remove_chat_verification_response:\n%s\n", cJSON_Print(jsonremove_chat_verification_response_2));
}

int main() {
  test_remove_chat_verification_response(1);
  test_remove_chat_verification_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // remove_chat_verification_response_MAIN
#endif // remove_chat_verification_response_TEST
