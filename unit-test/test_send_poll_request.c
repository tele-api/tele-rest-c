#ifndef send_poll_request_TEST
#define send_poll_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define send_poll_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/send_poll_request.h"
send_poll_request_t* instantiate_send_poll_request(int include_optional);

#include "test_send_message_request_chat_id.c"
#include "test_reply_parameters.c"
#include "test_send_message_request_reply_markup.c"


send_poll_request_t* instantiate_send_poll_request(int include_optional) {
  send_poll_request_t* send_poll_request = NULL;
  if (include_optional) {
    send_poll_request = send_poll_request_create(
      null,
      "0",
      list_createList(),
      "0",
      56,
      "0",
      list_createList(),
      1,
      telegram_bot_api_send_poll_request_TYPE_quiz,
      1,
      56,
      "0",
      "0",
      list_createList(),
      56,
      56,
      1,
      1,
      1,
      1,
      "0",
       // false, not to have infinite recursion
      instantiate_reply_parameters(0),
      null
    );
  } else {
    send_poll_request = send_poll_request_create(
      null,
      "0",
      list_createList(),
      "0",
      56,
      "0",
      list_createList(),
      1,
      telegram_bot_api_send_poll_request_TYPE_quiz,
      1,
      56,
      "0",
      "0",
      list_createList(),
      56,
      56,
      1,
      1,
      1,
      1,
      "0",
      NULL,
      null
    );
  }

  return send_poll_request;
}


#ifdef send_poll_request_MAIN

void test_send_poll_request(int include_optional) {
    send_poll_request_t* send_poll_request_1 = instantiate_send_poll_request(include_optional);

	cJSON* jsonsend_poll_request_1 = send_poll_request_convertToJSON(send_poll_request_1);
	printf("send_poll_request :\n%s\n", cJSON_Print(jsonsend_poll_request_1));
	send_poll_request_t* send_poll_request_2 = send_poll_request_parseFromJSON(jsonsend_poll_request_1);
	cJSON* jsonsend_poll_request_2 = send_poll_request_convertToJSON(send_poll_request_2);
	printf("repeating send_poll_request:\n%s\n", cJSON_Print(jsonsend_poll_request_2));
}

int main() {
  test_send_poll_request(1);
  test_send_poll_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // send_poll_request_MAIN
#endif // send_poll_request_TEST
