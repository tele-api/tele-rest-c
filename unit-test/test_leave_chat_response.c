#ifndef leave_chat_response_TEST
#define leave_chat_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define leave_chat_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/leave_chat_response.h"
leave_chat_response_t* instantiate_leave_chat_response(int include_optional);



leave_chat_response_t* instantiate_leave_chat_response(int include_optional) {
  leave_chat_response_t* leave_chat_response = NULL;
  if (include_optional) {
    leave_chat_response = leave_chat_response_create(
      1,
      1
    );
  } else {
    leave_chat_response = leave_chat_response_create(
      1,
      1
    );
  }

  return leave_chat_response;
}


#ifdef leave_chat_response_MAIN

void test_leave_chat_response(int include_optional) {
    leave_chat_response_t* leave_chat_response_1 = instantiate_leave_chat_response(include_optional);

	cJSON* jsonleave_chat_response_1 = leave_chat_response_convertToJSON(leave_chat_response_1);
	printf("leave_chat_response :\n%s\n", cJSON_Print(jsonleave_chat_response_1));
	leave_chat_response_t* leave_chat_response_2 = leave_chat_response_parseFromJSON(jsonleave_chat_response_1);
	cJSON* jsonleave_chat_response_2 = leave_chat_response_convertToJSON(leave_chat_response_2);
	printf("repeating leave_chat_response:\n%s\n", cJSON_Print(jsonleave_chat_response_2));
}

int main() {
  test_leave_chat_response(1);
  test_leave_chat_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // leave_chat_response_MAIN
#endif // leave_chat_response_TEST
