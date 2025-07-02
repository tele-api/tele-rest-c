#ifndef delete_message_request_TEST
#define delete_message_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define delete_message_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/delete_message_request.h"
delete_message_request_t* instantiate_delete_message_request(int include_optional);

#include "test_send_message_request_chat_id.c"


delete_message_request_t* instantiate_delete_message_request(int include_optional) {
  delete_message_request_t* delete_message_request = NULL;
  if (include_optional) {
    delete_message_request = delete_message_request_create(
      null,
      56
    );
  } else {
    delete_message_request = delete_message_request_create(
      null,
      56
    );
  }

  return delete_message_request;
}


#ifdef delete_message_request_MAIN

void test_delete_message_request(int include_optional) {
    delete_message_request_t* delete_message_request_1 = instantiate_delete_message_request(include_optional);

	cJSON* jsondelete_message_request_1 = delete_message_request_convertToJSON(delete_message_request_1);
	printf("delete_message_request :\n%s\n", cJSON_Print(jsondelete_message_request_1));
	delete_message_request_t* delete_message_request_2 = delete_message_request_parseFromJSON(jsondelete_message_request_1);
	cJSON* jsondelete_message_request_2 = delete_message_request_convertToJSON(delete_message_request_2);
	printf("repeating delete_message_request:\n%s\n", cJSON_Print(jsondelete_message_request_2));
}

int main() {
  test_delete_message_request(1);
  test_delete_message_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // delete_message_request_MAIN
#endif // delete_message_request_TEST
