#ifndef get_chat_member_response_TEST
#define get_chat_member_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define get_chat_member_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/get_chat_member_response.h"
get_chat_member_response_t* instantiate_get_chat_member_response(int include_optional);

#include "test_chat_member.c"


get_chat_member_response_t* instantiate_get_chat_member_response(int include_optional) {
  get_chat_member_response_t* get_chat_member_response = NULL;
  if (include_optional) {
    get_chat_member_response = get_chat_member_response_create(
      1,
      null
    );
  } else {
    get_chat_member_response = get_chat_member_response_create(
      1,
      null
    );
  }

  return get_chat_member_response;
}


#ifdef get_chat_member_response_MAIN

void test_get_chat_member_response(int include_optional) {
    get_chat_member_response_t* get_chat_member_response_1 = instantiate_get_chat_member_response(include_optional);

	cJSON* jsonget_chat_member_response_1 = get_chat_member_response_convertToJSON(get_chat_member_response_1);
	printf("get_chat_member_response :\n%s\n", cJSON_Print(jsonget_chat_member_response_1));
	get_chat_member_response_t* get_chat_member_response_2 = get_chat_member_response_parseFromJSON(jsonget_chat_member_response_1);
	cJSON* jsonget_chat_member_response_2 = get_chat_member_response_convertToJSON(get_chat_member_response_2);
	printf("repeating get_chat_member_response:\n%s\n", cJSON_Print(jsonget_chat_member_response_2));
}

int main() {
  test_get_chat_member_response(1);
  test_get_chat_member_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // get_chat_member_response_MAIN
#endif // get_chat_member_response_TEST
