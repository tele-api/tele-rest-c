#ifndef stop_poll_response_TEST
#define stop_poll_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define stop_poll_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/stop_poll_response.h"
stop_poll_response_t* instantiate_stop_poll_response(int include_optional);

#include "test_poll.c"


stop_poll_response_t* instantiate_stop_poll_response(int include_optional) {
  stop_poll_response_t* stop_poll_response = NULL;
  if (include_optional) {
    stop_poll_response = stop_poll_response_create(
      1,
       // false, not to have infinite recursion
      instantiate_poll(0)
    );
  } else {
    stop_poll_response = stop_poll_response_create(
      1,
      NULL
    );
  }

  return stop_poll_response;
}


#ifdef stop_poll_response_MAIN

void test_stop_poll_response(int include_optional) {
    stop_poll_response_t* stop_poll_response_1 = instantiate_stop_poll_response(include_optional);

	cJSON* jsonstop_poll_response_1 = stop_poll_response_convertToJSON(stop_poll_response_1);
	printf("stop_poll_response :\n%s\n", cJSON_Print(jsonstop_poll_response_1));
	stop_poll_response_t* stop_poll_response_2 = stop_poll_response_parseFromJSON(jsonstop_poll_response_1);
	cJSON* jsonstop_poll_response_2 = stop_poll_response_convertToJSON(stop_poll_response_2);
	printf("repeating stop_poll_response:\n%s\n", cJSON_Print(jsonstop_poll_response_2));
}

int main() {
  test_stop_poll_response(1);
  test_stop_poll_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // stop_poll_response_MAIN
#endif // stop_poll_response_TEST
