#ifndef set_chat_description_response_TEST
#define set_chat_description_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define set_chat_description_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/set_chat_description_response.h"
set_chat_description_response_t* instantiate_set_chat_description_response(int include_optional);



set_chat_description_response_t* instantiate_set_chat_description_response(int include_optional) {
  set_chat_description_response_t* set_chat_description_response = NULL;
  if (include_optional) {
    set_chat_description_response = set_chat_description_response_create(
      1,
      1
    );
  } else {
    set_chat_description_response = set_chat_description_response_create(
      1,
      1
    );
  }

  return set_chat_description_response;
}


#ifdef set_chat_description_response_MAIN

void test_set_chat_description_response(int include_optional) {
    set_chat_description_response_t* set_chat_description_response_1 = instantiate_set_chat_description_response(include_optional);

	cJSON* jsonset_chat_description_response_1 = set_chat_description_response_convertToJSON(set_chat_description_response_1);
	printf("set_chat_description_response :\n%s\n", cJSON_Print(jsonset_chat_description_response_1));
	set_chat_description_response_t* set_chat_description_response_2 = set_chat_description_response_parseFromJSON(jsonset_chat_description_response_1);
	cJSON* jsonset_chat_description_response_2 = set_chat_description_response_convertToJSON(set_chat_description_response_2);
	printf("repeating set_chat_description_response:\n%s\n", cJSON_Print(jsonset_chat_description_response_2));
}

int main() {
  test_set_chat_description_response(1);
  test_set_chat_description_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // set_chat_description_response_MAIN
#endif // set_chat_description_response_TEST
