#ifndef send_media_group_request_TEST
#define send_media_group_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define send_media_group_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/send_media_group_request.h"
send_media_group_request_t* instantiate_send_media_group_request(int include_optional);

#include "test_send_message_request_chat_id.c"
#include "test_reply_parameters.c"


send_media_group_request_t* instantiate_send_media_group_request(int include_optional) {
  send_media_group_request_t* send_media_group_request = NULL;
  if (include_optional) {
    send_media_group_request = send_media_group_request_create(
      null,
      list_createList(),
      "0",
      56,
      1,
      1,
      1,
      "0",
       // false, not to have infinite recursion
      instantiate_reply_parameters(0)
    );
  } else {
    send_media_group_request = send_media_group_request_create(
      null,
      list_createList(),
      "0",
      56,
      1,
      1,
      1,
      "0",
      NULL
    );
  }

  return send_media_group_request;
}


#ifdef send_media_group_request_MAIN

void test_send_media_group_request(int include_optional) {
    send_media_group_request_t* send_media_group_request_1 = instantiate_send_media_group_request(include_optional);

	cJSON* jsonsend_media_group_request_1 = send_media_group_request_convertToJSON(send_media_group_request_1);
	printf("send_media_group_request :\n%s\n", cJSON_Print(jsonsend_media_group_request_1));
	send_media_group_request_t* send_media_group_request_2 = send_media_group_request_parseFromJSON(jsonsend_media_group_request_1);
	cJSON* jsonsend_media_group_request_2 = send_media_group_request_convertToJSON(send_media_group_request_2);
	printf("repeating send_media_group_request:\n%s\n", cJSON_Print(jsonsend_media_group_request_2));
}

int main() {
  test_send_media_group_request(1);
  test_send_media_group_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // send_media_group_request_MAIN
#endif // send_media_group_request_TEST
