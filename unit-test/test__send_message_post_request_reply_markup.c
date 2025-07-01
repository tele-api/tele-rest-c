#ifndef _send_message_post_request_reply_markup_TEST
#define _send_message_post_request_reply_markup_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _send_message_post_request_reply_markup_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_send_message_post_request_reply_markup.h"
_send_message_post_request_reply_markup_t* instantiate__send_message_post_request_reply_markup(int include_optional);



_send_message_post_request_reply_markup_t* instantiate__send_message_post_request_reply_markup(int include_optional) {
  _send_message_post_request_reply_markup_t* _send_message_post_request_reply_markup = NULL;
  if (include_optional) {
    _send_message_post_request_reply_markup = _send_message_post_request_reply_markup_create(
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
    _send_message_post_request_reply_markup = _send_message_post_request_reply_markup_create(
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

  return _send_message_post_request_reply_markup;
}


#ifdef _send_message_post_request_reply_markup_MAIN

void test__send_message_post_request_reply_markup(int include_optional) {
    _send_message_post_request_reply_markup_t* _send_message_post_request_reply_markup_1 = instantiate__send_message_post_request_reply_markup(include_optional);

	cJSON* json_send_message_post_request_reply_markup_1 = _send_message_post_request_reply_markup_convertToJSON(_send_message_post_request_reply_markup_1);
	printf("_send_message_post_request_reply_markup :\n%s\n", cJSON_Print(json_send_message_post_request_reply_markup_1));
	_send_message_post_request_reply_markup_t* _send_message_post_request_reply_markup_2 = _send_message_post_request_reply_markup_parseFromJSON(json_send_message_post_request_reply_markup_1);
	cJSON* json_send_message_post_request_reply_markup_2 = _send_message_post_request_reply_markup_convertToJSON(_send_message_post_request_reply_markup_2);
	printf("repeating _send_message_post_request_reply_markup:\n%s\n", cJSON_Print(json_send_message_post_request_reply_markup_2));
}

int main() {
  test__send_message_post_request_reply_markup(1);
  test__send_message_post_request_reply_markup(0);

  printf("Hello world \n");
  return 0;
}

#endif // _send_message_post_request_reply_markup_MAIN
#endif // _send_message_post_request_reply_markup_TEST
