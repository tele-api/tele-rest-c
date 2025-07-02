#ifndef send_invoice_request_TEST
#define send_invoice_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define send_invoice_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/send_invoice_request.h"
send_invoice_request_t* instantiate_send_invoice_request(int include_optional);

#include "test_send_message_request_chat_id.c"
#include "test_reply_parameters.c"
#include "test_inline_keyboard_markup.c"


send_invoice_request_t* instantiate_send_invoice_request(int include_optional) {
  send_invoice_request_t* send_invoice_request = NULL;
  if (include_optional) {
    send_invoice_request = send_invoice_request_create(
      null,
      "0",
      "0",
      "0",
      "0",
      list_createList(),
      56,
      "0",
      56,
      list_createList(),
      "0",
      "0",
      "0",
      56,
      56,
      56,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      "0",
       // false, not to have infinite recursion
      instantiate_reply_parameters(0),
       // false, not to have infinite recursion
      instantiate_inline_keyboard_markup(0)
    );
  } else {
    send_invoice_request = send_invoice_request_create(
      null,
      "0",
      "0",
      "0",
      "0",
      list_createList(),
      56,
      "0",
      56,
      list_createList(),
      "0",
      "0",
      "0",
      56,
      56,
      56,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      "0",
      NULL,
      NULL
    );
  }

  return send_invoice_request;
}


#ifdef send_invoice_request_MAIN

void test_send_invoice_request(int include_optional) {
    send_invoice_request_t* send_invoice_request_1 = instantiate_send_invoice_request(include_optional);

	cJSON* jsonsend_invoice_request_1 = send_invoice_request_convertToJSON(send_invoice_request_1);
	printf("send_invoice_request :\n%s\n", cJSON_Print(jsonsend_invoice_request_1));
	send_invoice_request_t* send_invoice_request_2 = send_invoice_request_parseFromJSON(jsonsend_invoice_request_1);
	cJSON* jsonsend_invoice_request_2 = send_invoice_request_convertToJSON(send_invoice_request_2);
	printf("repeating send_invoice_request:\n%s\n", cJSON_Print(jsonsend_invoice_request_2));
}

int main() {
  test_send_invoice_request(1);
  test_send_invoice_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // send_invoice_request_MAIN
#endif // send_invoice_request_TEST
