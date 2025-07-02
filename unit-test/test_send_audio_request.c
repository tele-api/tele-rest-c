#ifndef send_audio_request_TEST
#define send_audio_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define send_audio_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/send_audio_request.h"
send_audio_request_t* instantiate_send_audio_request(int include_optional);

#include "test_send_message_request_chat_id.c"
#include "test_reply_parameters.c"
#include "test_send_message_request_reply_markup.c"


send_audio_request_t* instantiate_send_audio_request(int include_optional) {
  send_audio_request_t* send_audio_request = NULL;
  if (include_optional) {
    send_audio_request = send_audio_request_create(
      null,
      "0",
      "0",
      56,
      "0",
      "0",
      list_createList(),
      56,
      "0",
      "0",
      "0",
      1,
      1,
      1,
      "0",
       // false, not to have infinite recursion
      instantiate_reply_parameters(0),
      null
    );
  } else {
    send_audio_request = send_audio_request_create(
      null,
      "0",
      "0",
      56,
      "0",
      "0",
      list_createList(),
      56,
      "0",
      "0",
      "0",
      1,
      1,
      1,
      "0",
      NULL,
      null
    );
  }

  return send_audio_request;
}


#ifdef send_audio_request_MAIN

void test_send_audio_request(int include_optional) {
    send_audio_request_t* send_audio_request_1 = instantiate_send_audio_request(include_optional);

	cJSON* jsonsend_audio_request_1 = send_audio_request_convertToJSON(send_audio_request_1);
	printf("send_audio_request :\n%s\n", cJSON_Print(jsonsend_audio_request_1));
	send_audio_request_t* send_audio_request_2 = send_audio_request_parseFromJSON(jsonsend_audio_request_1);
	cJSON* jsonsend_audio_request_2 = send_audio_request_convertToJSON(send_audio_request_2);
	printf("repeating send_audio_request:\n%s\n", cJSON_Print(jsonsend_audio_request_2));
}

int main() {
  test_send_audio_request(1);
  test_send_audio_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // send_audio_request_MAIN
#endif // send_audio_request_TEST
