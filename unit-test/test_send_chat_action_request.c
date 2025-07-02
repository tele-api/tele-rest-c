#ifndef send_chat_action_request_TEST
#define send_chat_action_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define send_chat_action_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/send_chat_action_request.h"
send_chat_action_request_t* instantiate_send_chat_action_request(int include_optional);

#include "test_send_message_request_chat_id.c"


send_chat_action_request_t* instantiate_send_chat_action_request(int include_optional) {
  send_chat_action_request_t* send_chat_action_request = NULL;
  if (include_optional) {
    send_chat_action_request = send_chat_action_request_create(
      null,
      telegram_bot_api_send_chat_action_request_ACTION_typing,
      "0",
      56
    );
  } else {
    send_chat_action_request = send_chat_action_request_create(
      null,
      telegram_bot_api_send_chat_action_request_ACTION_typing,
      "0",
      56
    );
  }

  return send_chat_action_request;
}


#ifdef send_chat_action_request_MAIN

void test_send_chat_action_request(int include_optional) {
    send_chat_action_request_t* send_chat_action_request_1 = instantiate_send_chat_action_request(include_optional);

	cJSON* jsonsend_chat_action_request_1 = send_chat_action_request_convertToJSON(send_chat_action_request_1);
	printf("send_chat_action_request :\n%s\n", cJSON_Print(jsonsend_chat_action_request_1));
	send_chat_action_request_t* send_chat_action_request_2 = send_chat_action_request_parseFromJSON(jsonsend_chat_action_request_1);
	cJSON* jsonsend_chat_action_request_2 = send_chat_action_request_convertToJSON(send_chat_action_request_2);
	printf("repeating send_chat_action_request:\n%s\n", cJSON_Print(jsonsend_chat_action_request_2));
}

int main() {
  test_send_chat_action_request(1);
  test_send_chat_action_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // send_chat_action_request_MAIN
#endif // send_chat_action_request_TEST
