#ifndef post_edit_message_live_location_request_TEST
#define post_edit_message_live_location_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define post_edit_message_live_location_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/post_edit_message_live_location_request.h"
post_edit_message_live_location_request_t* instantiate_post_edit_message_live_location_request(int include_optional);

#include "test_post_edit_message_text_request_chat_id.c"
#include "test_inline_keyboard_markup.c"


post_edit_message_live_location_request_t* instantiate_post_edit_message_live_location_request(int include_optional) {
  post_edit_message_live_location_request_t* post_edit_message_live_location_request = NULL;
  if (include_optional) {
    post_edit_message_live_location_request = post_edit_message_live_location_request_create(
      1.337,
      1.337,
      "0",
      null,
      56,
      "0",
      56,
      1.337,
      56,
      56,
       // false, not to have infinite recursion
      instantiate_inline_keyboard_markup(0)
    );
  } else {
    post_edit_message_live_location_request = post_edit_message_live_location_request_create(
      1.337,
      1.337,
      "0",
      null,
      56,
      "0",
      56,
      1.337,
      56,
      56,
      NULL
    );
  }

  return post_edit_message_live_location_request;
}


#ifdef post_edit_message_live_location_request_MAIN

void test_post_edit_message_live_location_request(int include_optional) {
    post_edit_message_live_location_request_t* post_edit_message_live_location_request_1 = instantiate_post_edit_message_live_location_request(include_optional);

	cJSON* jsonpost_edit_message_live_location_request_1 = post_edit_message_live_location_request_convertToJSON(post_edit_message_live_location_request_1);
	printf("post_edit_message_live_location_request :\n%s\n", cJSON_Print(jsonpost_edit_message_live_location_request_1));
	post_edit_message_live_location_request_t* post_edit_message_live_location_request_2 = post_edit_message_live_location_request_parseFromJSON(jsonpost_edit_message_live_location_request_1);
	cJSON* jsonpost_edit_message_live_location_request_2 = post_edit_message_live_location_request_convertToJSON(post_edit_message_live_location_request_2);
	printf("repeating post_edit_message_live_location_request:\n%s\n", cJSON_Print(jsonpost_edit_message_live_location_request_2));
}

int main() {
  test_post_edit_message_live_location_request(1);
  test_post_edit_message_live_location_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // post_edit_message_live_location_request_MAIN
#endif // post_edit_message_live_location_request_TEST
