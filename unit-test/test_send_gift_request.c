#ifndef send_gift_request_TEST
#define send_gift_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define send_gift_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/send_gift_request.h"
send_gift_request_t* instantiate_send_gift_request(int include_optional);

#include "test_send_gift_request_chat_id.c"


send_gift_request_t* instantiate_send_gift_request(int include_optional) {
  send_gift_request_t* send_gift_request = NULL;
  if (include_optional) {
    send_gift_request = send_gift_request_create(
      "0",
      56,
      null,
      1,
      "0",
      "0",
      list_createList()
    );
  } else {
    send_gift_request = send_gift_request_create(
      "0",
      56,
      null,
      1,
      "0",
      "0",
      list_createList()
    );
  }

  return send_gift_request;
}


#ifdef send_gift_request_MAIN

void test_send_gift_request(int include_optional) {
    send_gift_request_t* send_gift_request_1 = instantiate_send_gift_request(include_optional);

	cJSON* jsonsend_gift_request_1 = send_gift_request_convertToJSON(send_gift_request_1);
	printf("send_gift_request :\n%s\n", cJSON_Print(jsonsend_gift_request_1));
	send_gift_request_t* send_gift_request_2 = send_gift_request_parseFromJSON(jsonsend_gift_request_1);
	cJSON* jsonsend_gift_request_2 = send_gift_request_convertToJSON(send_gift_request_2);
	printf("repeating send_gift_request:\n%s\n", cJSON_Print(jsonsend_gift_request_2));
}

int main() {
  test_send_gift_request(1);
  test_send_gift_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // send_gift_request_MAIN
#endif // send_gift_request_TEST
