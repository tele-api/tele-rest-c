#ifndef stop_message_live_location_response_TEST
#define stop_message_live_location_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define stop_message_live_location_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/stop_message_live_location_response.h"
stop_message_live_location_response_t* instantiate_stop_message_live_location_response(int include_optional);

#include "test_edit_message_text_response_result.c"


stop_message_live_location_response_t* instantiate_stop_message_live_location_response(int include_optional) {
  stop_message_live_location_response_t* stop_message_live_location_response = NULL;
  if (include_optional) {
    stop_message_live_location_response = stop_message_live_location_response_create(
      1,
      null
    );
  } else {
    stop_message_live_location_response = stop_message_live_location_response_create(
      1,
      null
    );
  }

  return stop_message_live_location_response;
}


#ifdef stop_message_live_location_response_MAIN

void test_stop_message_live_location_response(int include_optional) {
    stop_message_live_location_response_t* stop_message_live_location_response_1 = instantiate_stop_message_live_location_response(include_optional);

	cJSON* jsonstop_message_live_location_response_1 = stop_message_live_location_response_convertToJSON(stop_message_live_location_response_1);
	printf("stop_message_live_location_response :\n%s\n", cJSON_Print(jsonstop_message_live_location_response_1));
	stop_message_live_location_response_t* stop_message_live_location_response_2 = stop_message_live_location_response_parseFromJSON(jsonstop_message_live_location_response_1);
	cJSON* jsonstop_message_live_location_response_2 = stop_message_live_location_response_convertToJSON(stop_message_live_location_response_2);
	printf("repeating stop_message_live_location_response:\n%s\n", cJSON_Print(jsonstop_message_live_location_response_2));
}

int main() {
  test_stop_message_live_location_response(1);
  test_stop_message_live_location_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // stop_message_live_location_response_MAIN
#endif // stop_message_live_location_response_TEST
