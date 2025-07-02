#ifndef stop_message_live_location_request_TEST
#define stop_message_live_location_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define stop_message_live_location_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/stop_message_live_location_request.h"
stop_message_live_location_request_t* instantiate_stop_message_live_location_request(int include_optional);

#include "test_edit_message_text_request_chat_id.c"
#include "test_inline_keyboard_markup.c"


stop_message_live_location_request_t* instantiate_stop_message_live_location_request(int include_optional) {
  stop_message_live_location_request_t* stop_message_live_location_request = NULL;
  if (include_optional) {
    stop_message_live_location_request = stop_message_live_location_request_create(
      "0",
      null,
      56,
      "0",
       // false, not to have infinite recursion
      instantiate_inline_keyboard_markup(0)
    );
  } else {
    stop_message_live_location_request = stop_message_live_location_request_create(
      "0",
      null,
      56,
      "0",
      NULL
    );
  }

  return stop_message_live_location_request;
}


#ifdef stop_message_live_location_request_MAIN

void test_stop_message_live_location_request(int include_optional) {
    stop_message_live_location_request_t* stop_message_live_location_request_1 = instantiate_stop_message_live_location_request(include_optional);

	cJSON* jsonstop_message_live_location_request_1 = stop_message_live_location_request_convertToJSON(stop_message_live_location_request_1);
	printf("stop_message_live_location_request :\n%s\n", cJSON_Print(jsonstop_message_live_location_request_1));
	stop_message_live_location_request_t* stop_message_live_location_request_2 = stop_message_live_location_request_parseFromJSON(jsonstop_message_live_location_request_1);
	cJSON* jsonstop_message_live_location_request_2 = stop_message_live_location_request_convertToJSON(stop_message_live_location_request_2);
	printf("repeating stop_message_live_location_request:\n%s\n", cJSON_Print(jsonstop_message_live_location_request_2));
}

int main() {
  test_stop_message_live_location_request(1);
  test_stop_message_live_location_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // stop_message_live_location_request_MAIN
#endif // stop_message_live_location_request_TEST
