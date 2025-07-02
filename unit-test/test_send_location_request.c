#ifndef send_location_request_TEST
#define send_location_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define send_location_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/send_location_request.h"
send_location_request_t* instantiate_send_location_request(int include_optional);

#include "test_send_message_request_chat_id.c"
#include "test_reply_parameters.c"
#include "test_send_message_request_reply_markup.c"


send_location_request_t* instantiate_send_location_request(int include_optional) {
  send_location_request_t* send_location_request = NULL;
  if (include_optional) {
    send_location_request = send_location_request_create(
      null,
      1.337,
      1.337,
      "0",
      56,
      1.337,
      56,
      56,
      56,
      1,
      1,
      1,
      "0",
       // false, not to have infinite recursion
      instantiate_reply_parameters(0),
      null
    );
  } else {
    send_location_request = send_location_request_create(
      null,
      1.337,
      1.337,
      "0",
      56,
      1.337,
      56,
      56,
      56,
      1,
      1,
      1,
      "0",
      NULL,
      null
    );
  }

  return send_location_request;
}


#ifdef send_location_request_MAIN

void test_send_location_request(int include_optional) {
    send_location_request_t* send_location_request_1 = instantiate_send_location_request(include_optional);

	cJSON* jsonsend_location_request_1 = send_location_request_convertToJSON(send_location_request_1);
	printf("send_location_request :\n%s\n", cJSON_Print(jsonsend_location_request_1));
	send_location_request_t* send_location_request_2 = send_location_request_parseFromJSON(jsonsend_location_request_1);
	cJSON* jsonsend_location_request_2 = send_location_request_convertToJSON(send_location_request_2);
	printf("repeating send_location_request:\n%s\n", cJSON_Print(jsonsend_location_request_2));
}

int main() {
  test_send_location_request(1);
  test_send_location_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // send_location_request_MAIN
#endif // send_location_request_TEST
