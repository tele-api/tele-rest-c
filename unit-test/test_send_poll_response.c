#ifndef send_poll_response_TEST
#define send_poll_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define send_poll_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/send_poll_response.h"
send_poll_response_t* instantiate_send_poll_response(int include_optional);

#include "test_message.c"


send_poll_response_t* instantiate_send_poll_response(int include_optional) {
  send_poll_response_t* send_poll_response = NULL;
  if (include_optional) {
    send_poll_response = send_poll_response_create(
      1,
       // false, not to have infinite recursion
      instantiate_message(0)
    );
  } else {
    send_poll_response = send_poll_response_create(
      1,
      NULL
    );
  }

  return send_poll_response;
}


#ifdef send_poll_response_MAIN

void test_send_poll_response(int include_optional) {
    send_poll_response_t* send_poll_response_1 = instantiate_send_poll_response(include_optional);

	cJSON* jsonsend_poll_response_1 = send_poll_response_convertToJSON(send_poll_response_1);
	printf("send_poll_response :\n%s\n", cJSON_Print(jsonsend_poll_response_1));
	send_poll_response_t* send_poll_response_2 = send_poll_response_parseFromJSON(jsonsend_poll_response_1);
	cJSON* jsonsend_poll_response_2 = send_poll_response_convertToJSON(send_poll_response_2);
	printf("repeating send_poll_response:\n%s\n", cJSON_Print(jsonsend_poll_response_2));
}

int main() {
  test_send_poll_response(1);
  test_send_poll_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // send_poll_response_MAIN
#endif // send_poll_response_TEST
