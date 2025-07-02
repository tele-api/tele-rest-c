#ifndef send_message_request_chat_id_TEST
#define send_message_request_chat_id_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define send_message_request_chat_id_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/send_message_request_chat_id.h"
send_message_request_chat_id_t* instantiate_send_message_request_chat_id(int include_optional);



send_message_request_chat_id_t* instantiate_send_message_request_chat_id(int include_optional) {
  send_message_request_chat_id_t* send_message_request_chat_id = NULL;
  if (include_optional) {
    send_message_request_chat_id = send_message_request_chat_id_create(
    );
  } else {
    send_message_request_chat_id = send_message_request_chat_id_create(
    );
  }

  return send_message_request_chat_id;
}


#ifdef send_message_request_chat_id_MAIN

void test_send_message_request_chat_id(int include_optional) {
    send_message_request_chat_id_t* send_message_request_chat_id_1 = instantiate_send_message_request_chat_id(include_optional);

	cJSON* jsonsend_message_request_chat_id_1 = send_message_request_chat_id_convertToJSON(send_message_request_chat_id_1);
	printf("send_message_request_chat_id :\n%s\n", cJSON_Print(jsonsend_message_request_chat_id_1));
	send_message_request_chat_id_t* send_message_request_chat_id_2 = send_message_request_chat_id_parseFromJSON(jsonsend_message_request_chat_id_1);
	cJSON* jsonsend_message_request_chat_id_2 = send_message_request_chat_id_convertToJSON(send_message_request_chat_id_2);
	printf("repeating send_message_request_chat_id:\n%s\n", cJSON_Print(jsonsend_message_request_chat_id_2));
}

int main() {
  test_send_message_request_chat_id(1);
  test_send_message_request_chat_id(0);

  printf("Hello world \n");
  return 0;
}

#endif // send_message_request_chat_id_MAIN
#endif // send_message_request_chat_id_TEST
