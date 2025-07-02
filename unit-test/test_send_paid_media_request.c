#ifndef send_paid_media_request_TEST
#define send_paid_media_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define send_paid_media_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/send_paid_media_request.h"
send_paid_media_request_t* instantiate_send_paid_media_request(int include_optional);

#include "test_send_paid_media_request_chat_id.c"
#include "test_reply_parameters.c"
#include "test_send_message_request_reply_markup.c"


send_paid_media_request_t* instantiate_send_paid_media_request(int include_optional) {
  send_paid_media_request_t* send_paid_media_request = NULL;
  if (include_optional) {
    send_paid_media_request = send_paid_media_request_create(
      null,
      56,
      list_createList(),
      "0",
      "0",
      "0",
      "0",
      list_createList(),
      1,
      1,
      1,
      1,
       // false, not to have infinite recursion
      instantiate_reply_parameters(0),
      null
    );
  } else {
    send_paid_media_request = send_paid_media_request_create(
      null,
      56,
      list_createList(),
      "0",
      "0",
      "0",
      "0",
      list_createList(),
      1,
      1,
      1,
      1,
      NULL,
      null
    );
  }

  return send_paid_media_request;
}


#ifdef send_paid_media_request_MAIN

void test_send_paid_media_request(int include_optional) {
    send_paid_media_request_t* send_paid_media_request_1 = instantiate_send_paid_media_request(include_optional);

	cJSON* jsonsend_paid_media_request_1 = send_paid_media_request_convertToJSON(send_paid_media_request_1);
	printf("send_paid_media_request :\n%s\n", cJSON_Print(jsonsend_paid_media_request_1));
	send_paid_media_request_t* send_paid_media_request_2 = send_paid_media_request_parseFromJSON(jsonsend_paid_media_request_1);
	cJSON* jsonsend_paid_media_request_2 = send_paid_media_request_convertToJSON(send_paid_media_request_2);
	printf("repeating send_paid_media_request:\n%s\n", cJSON_Print(jsonsend_paid_media_request_2));
}

int main() {
  test_send_paid_media_request(1);
  test_send_paid_media_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // send_paid_media_request_MAIN
#endif // send_paid_media_request_TEST
