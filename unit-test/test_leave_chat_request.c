#ifndef leave_chat_request_TEST
#define leave_chat_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define leave_chat_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/leave_chat_request.h"
leave_chat_request_t* instantiate_leave_chat_request(int include_optional);

#include "test_leave_chat_request_chat_id.c"


leave_chat_request_t* instantiate_leave_chat_request(int include_optional) {
  leave_chat_request_t* leave_chat_request = NULL;
  if (include_optional) {
    leave_chat_request = leave_chat_request_create(
      null
    );
  } else {
    leave_chat_request = leave_chat_request_create(
      null
    );
  }

  return leave_chat_request;
}


#ifdef leave_chat_request_MAIN

void test_leave_chat_request(int include_optional) {
    leave_chat_request_t* leave_chat_request_1 = instantiate_leave_chat_request(include_optional);

	cJSON* jsonleave_chat_request_1 = leave_chat_request_convertToJSON(leave_chat_request_1);
	printf("leave_chat_request :\n%s\n", cJSON_Print(jsonleave_chat_request_1));
	leave_chat_request_t* leave_chat_request_2 = leave_chat_request_parseFromJSON(jsonleave_chat_request_1);
	cJSON* jsonleave_chat_request_2 = leave_chat_request_convertToJSON(leave_chat_request_2);
	printf("repeating leave_chat_request:\n%s\n", cJSON_Print(jsonleave_chat_request_2));
}

int main() {
  test_leave_chat_request(1);
  test_leave_chat_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // leave_chat_request_MAIN
#endif // leave_chat_request_TEST
