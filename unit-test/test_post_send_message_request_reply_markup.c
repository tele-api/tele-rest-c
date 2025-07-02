#ifndef post_send_message_request_reply_markup_TEST
#define post_send_message_request_reply_markup_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define post_send_message_request_reply_markup_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/post_send_message_request_reply_markup.h"
post_send_message_request_reply_markup_t* instantiate_post_send_message_request_reply_markup(int include_optional);



post_send_message_request_reply_markup_t* instantiate_post_send_message_request_reply_markup(int include_optional) {
  post_send_message_request_reply_markup_t* post_send_message_request_reply_markup = NULL;
  if (include_optional) {
    post_send_message_request_reply_markup = post_send_message_request_reply_markup_create(
      list_createList(),
      list_createList(),
      1,
      1,
      1,
      1,
      1,
      "0",
      1
    );
  } else {
    post_send_message_request_reply_markup = post_send_message_request_reply_markup_create(
      list_createList(),
      list_createList(),
      1,
      1,
      1,
      1,
      1,
      "0",
      1
    );
  }

  return post_send_message_request_reply_markup;
}


#ifdef post_send_message_request_reply_markup_MAIN

void test_post_send_message_request_reply_markup(int include_optional) {
    post_send_message_request_reply_markup_t* post_send_message_request_reply_markup_1 = instantiate_post_send_message_request_reply_markup(include_optional);

	cJSON* jsonpost_send_message_request_reply_markup_1 = post_send_message_request_reply_markup_convertToJSON(post_send_message_request_reply_markup_1);
	printf("post_send_message_request_reply_markup :\n%s\n", cJSON_Print(jsonpost_send_message_request_reply_markup_1));
	post_send_message_request_reply_markup_t* post_send_message_request_reply_markup_2 = post_send_message_request_reply_markup_parseFromJSON(jsonpost_send_message_request_reply_markup_1);
	cJSON* jsonpost_send_message_request_reply_markup_2 = post_send_message_request_reply_markup_convertToJSON(post_send_message_request_reply_markup_2);
	printf("repeating post_send_message_request_reply_markup:\n%s\n", cJSON_Print(jsonpost_send_message_request_reply_markup_2));
}

int main() {
  test_post_send_message_request_reply_markup(1);
  test_post_send_message_request_reply_markup(0);

  printf("Hello world \n");
  return 0;
}

#endif // post_send_message_request_reply_markup_MAIN
#endif // post_send_message_request_reply_markup_TEST
