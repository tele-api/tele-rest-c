#ifndef copy_messages_request_TEST
#define copy_messages_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define copy_messages_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/copy_messages_request.h"
copy_messages_request_t* instantiate_copy_messages_request(int include_optional);

#include "test_send_message_request_chat_id.c"
#include "test_forward_messages_request_from_chat_id.c"


copy_messages_request_t* instantiate_copy_messages_request(int include_optional) {
  copy_messages_request_t* copy_messages_request = NULL;
  if (include_optional) {
    copy_messages_request = copy_messages_request_create(
      null,
      null,
      list_createList(),
      56,
      1,
      1,
      1
    );
  } else {
    copy_messages_request = copy_messages_request_create(
      null,
      null,
      list_createList(),
      56,
      1,
      1,
      1
    );
  }

  return copy_messages_request;
}


#ifdef copy_messages_request_MAIN

void test_copy_messages_request(int include_optional) {
    copy_messages_request_t* copy_messages_request_1 = instantiate_copy_messages_request(include_optional);

	cJSON* jsoncopy_messages_request_1 = copy_messages_request_convertToJSON(copy_messages_request_1);
	printf("copy_messages_request :\n%s\n", cJSON_Print(jsoncopy_messages_request_1));
	copy_messages_request_t* copy_messages_request_2 = copy_messages_request_parseFromJSON(jsoncopy_messages_request_1);
	cJSON* jsoncopy_messages_request_2 = copy_messages_request_convertToJSON(copy_messages_request_2);
	printf("repeating copy_messages_request:\n%s\n", cJSON_Print(jsoncopy_messages_request_2));
}

int main() {
  test_copy_messages_request(1);
  test_copy_messages_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // copy_messages_request_MAIN
#endif // copy_messages_request_TEST
