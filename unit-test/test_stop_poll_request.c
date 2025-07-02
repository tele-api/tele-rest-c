#ifndef stop_poll_request_TEST
#define stop_poll_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define stop_poll_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/stop_poll_request.h"
stop_poll_request_t* instantiate_stop_poll_request(int include_optional);

#include "test_send_message_request_chat_id.c"
#include "test_inline_keyboard_markup.c"


stop_poll_request_t* instantiate_stop_poll_request(int include_optional) {
  stop_poll_request_t* stop_poll_request = NULL;
  if (include_optional) {
    stop_poll_request = stop_poll_request_create(
      null,
      56,
      "0",
       // false, not to have infinite recursion
      instantiate_inline_keyboard_markup(0)
    );
  } else {
    stop_poll_request = stop_poll_request_create(
      null,
      56,
      "0",
      NULL
    );
  }

  return stop_poll_request;
}


#ifdef stop_poll_request_MAIN

void test_stop_poll_request(int include_optional) {
    stop_poll_request_t* stop_poll_request_1 = instantiate_stop_poll_request(include_optional);

	cJSON* jsonstop_poll_request_1 = stop_poll_request_convertToJSON(stop_poll_request_1);
	printf("stop_poll_request :\n%s\n", cJSON_Print(jsonstop_poll_request_1));
	stop_poll_request_t* stop_poll_request_2 = stop_poll_request_parseFromJSON(jsonstop_poll_request_1);
	cJSON* jsonstop_poll_request_2 = stop_poll_request_convertToJSON(stop_poll_request_2);
	printf("repeating stop_poll_request:\n%s\n", cJSON_Print(jsonstop_poll_request_2));
}

int main() {
  test_stop_poll_request(1);
  test_stop_poll_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // stop_poll_request_MAIN
#endif // stop_poll_request_TEST
