#ifndef _send_gift_post_request_chat_id_TEST
#define _send_gift_post_request_chat_id_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _send_gift_post_request_chat_id_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_send_gift_post_request_chat_id.h"
_send_gift_post_request_chat_id_t* instantiate__send_gift_post_request_chat_id(int include_optional);



_send_gift_post_request_chat_id_t* instantiate__send_gift_post_request_chat_id(int include_optional) {
  _send_gift_post_request_chat_id_t* _send_gift_post_request_chat_id = NULL;
  if (include_optional) {
    _send_gift_post_request_chat_id = _send_gift_post_request_chat_id_create(
    );
  } else {
    _send_gift_post_request_chat_id = _send_gift_post_request_chat_id_create(
    );
  }

  return _send_gift_post_request_chat_id;
}


#ifdef _send_gift_post_request_chat_id_MAIN

void test__send_gift_post_request_chat_id(int include_optional) {
    _send_gift_post_request_chat_id_t* _send_gift_post_request_chat_id_1 = instantiate__send_gift_post_request_chat_id(include_optional);

	cJSON* json_send_gift_post_request_chat_id_1 = _send_gift_post_request_chat_id_convertToJSON(_send_gift_post_request_chat_id_1);
	printf("_send_gift_post_request_chat_id :\n%s\n", cJSON_Print(json_send_gift_post_request_chat_id_1));
	_send_gift_post_request_chat_id_t* _send_gift_post_request_chat_id_2 = _send_gift_post_request_chat_id_parseFromJSON(json_send_gift_post_request_chat_id_1);
	cJSON* json_send_gift_post_request_chat_id_2 = _send_gift_post_request_chat_id_convertToJSON(_send_gift_post_request_chat_id_2);
	printf("repeating _send_gift_post_request_chat_id:\n%s\n", cJSON_Print(json_send_gift_post_request_chat_id_2));
}

int main() {
  test__send_gift_post_request_chat_id(1);
  test__send_gift_post_request_chat_id(0);

  printf("Hello world \n");
  return 0;
}

#endif // _send_gift_post_request_chat_id_MAIN
#endif // _send_gift_post_request_chat_id_TEST
