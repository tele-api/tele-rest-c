#ifndef _forward_message_post_request_from_chat_id_TEST
#define _forward_message_post_request_from_chat_id_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _forward_message_post_request_from_chat_id_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_forward_message_post_request_from_chat_id.h"
_forward_message_post_request_from_chat_id_t* instantiate__forward_message_post_request_from_chat_id(int include_optional);



_forward_message_post_request_from_chat_id_t* instantiate__forward_message_post_request_from_chat_id(int include_optional) {
  _forward_message_post_request_from_chat_id_t* _forward_message_post_request_from_chat_id = NULL;
  if (include_optional) {
    _forward_message_post_request_from_chat_id = _forward_message_post_request_from_chat_id_create(
    );
  } else {
    _forward_message_post_request_from_chat_id = _forward_message_post_request_from_chat_id_create(
    );
  }

  return _forward_message_post_request_from_chat_id;
}


#ifdef _forward_message_post_request_from_chat_id_MAIN

void test__forward_message_post_request_from_chat_id(int include_optional) {
    _forward_message_post_request_from_chat_id_t* _forward_message_post_request_from_chat_id_1 = instantiate__forward_message_post_request_from_chat_id(include_optional);

	cJSON* json_forward_message_post_request_from_chat_id_1 = _forward_message_post_request_from_chat_id_convertToJSON(_forward_message_post_request_from_chat_id_1);
	printf("_forward_message_post_request_from_chat_id :\n%s\n", cJSON_Print(json_forward_message_post_request_from_chat_id_1));
	_forward_message_post_request_from_chat_id_t* _forward_message_post_request_from_chat_id_2 = _forward_message_post_request_from_chat_id_parseFromJSON(json_forward_message_post_request_from_chat_id_1);
	cJSON* json_forward_message_post_request_from_chat_id_2 = _forward_message_post_request_from_chat_id_convertToJSON(_forward_message_post_request_from_chat_id_2);
	printf("repeating _forward_message_post_request_from_chat_id:\n%s\n", cJSON_Print(json_forward_message_post_request_from_chat_id_2));
}

int main() {
  test__forward_message_post_request_from_chat_id(1);
  test__forward_message_post_request_from_chat_id(0);

  printf("Hello world \n");
  return 0;
}

#endif // _forward_message_post_request_from_chat_id_MAIN
#endif // _forward_message_post_request_from_chat_id_TEST
