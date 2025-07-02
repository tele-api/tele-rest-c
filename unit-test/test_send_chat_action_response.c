#ifndef send_chat_action_response_TEST
#define send_chat_action_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define send_chat_action_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/send_chat_action_response.h"
send_chat_action_response_t* instantiate_send_chat_action_response(int include_optional);



send_chat_action_response_t* instantiate_send_chat_action_response(int include_optional) {
  send_chat_action_response_t* send_chat_action_response = NULL;
  if (include_optional) {
    send_chat_action_response = send_chat_action_response_create(
      1,
      1
    );
  } else {
    send_chat_action_response = send_chat_action_response_create(
      1,
      1
    );
  }

  return send_chat_action_response;
}


#ifdef send_chat_action_response_MAIN

void test_send_chat_action_response(int include_optional) {
    send_chat_action_response_t* send_chat_action_response_1 = instantiate_send_chat_action_response(include_optional);

	cJSON* jsonsend_chat_action_response_1 = send_chat_action_response_convertToJSON(send_chat_action_response_1);
	printf("send_chat_action_response :\n%s\n", cJSON_Print(jsonsend_chat_action_response_1));
	send_chat_action_response_t* send_chat_action_response_2 = send_chat_action_response_parseFromJSON(jsonsend_chat_action_response_1);
	cJSON* jsonsend_chat_action_response_2 = send_chat_action_response_convertToJSON(send_chat_action_response_2);
	printf("repeating send_chat_action_response:\n%s\n", cJSON_Print(jsonsend_chat_action_response_2));
}

int main() {
  test_send_chat_action_response(1);
  test_send_chat_action_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // send_chat_action_response_MAIN
#endif // send_chat_action_response_TEST
