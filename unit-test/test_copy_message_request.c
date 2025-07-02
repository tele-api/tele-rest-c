#ifndef copy_message_request_TEST
#define copy_message_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define copy_message_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/copy_message_request.h"
copy_message_request_t* instantiate_copy_message_request(int include_optional);

#include "test_send_message_request_chat_id.c"
#include "test_forward_message_request_from_chat_id.c"
#include "test_reply_parameters.c"
#include "test_send_message_request_reply_markup.c"


copy_message_request_t* instantiate_copy_message_request(int include_optional) {
  copy_message_request_t* copy_message_request = NULL;
  if (include_optional) {
    copy_message_request = copy_message_request_create(
      null,
      null,
      56,
      56,
      56,
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
    copy_message_request = copy_message_request_create(
      null,
      null,
      56,
      56,
      56,
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

  return copy_message_request;
}


#ifdef copy_message_request_MAIN

void test_copy_message_request(int include_optional) {
    copy_message_request_t* copy_message_request_1 = instantiate_copy_message_request(include_optional);

	cJSON* jsoncopy_message_request_1 = copy_message_request_convertToJSON(copy_message_request_1);
	printf("copy_message_request :\n%s\n", cJSON_Print(jsoncopy_message_request_1));
	copy_message_request_t* copy_message_request_2 = copy_message_request_parseFromJSON(jsoncopy_message_request_1);
	cJSON* jsoncopy_message_request_2 = copy_message_request_convertToJSON(copy_message_request_2);
	printf("repeating copy_message_request:\n%s\n", cJSON_Print(jsoncopy_message_request_2));
}

int main() {
  test_copy_message_request(1);
  test_copy_message_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // copy_message_request_MAIN
#endif // copy_message_request_TEST
