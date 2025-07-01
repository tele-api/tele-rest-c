#ifndef _edit_message_text_post_request_chat_id_TEST
#define _edit_message_text_post_request_chat_id_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define _edit_message_text_post_request_chat_id_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/_edit_message_text_post_request_chat_id.h"
_edit_message_text_post_request_chat_id_t* instantiate__edit_message_text_post_request_chat_id(int include_optional);



_edit_message_text_post_request_chat_id_t* instantiate__edit_message_text_post_request_chat_id(int include_optional) {
  _edit_message_text_post_request_chat_id_t* _edit_message_text_post_request_chat_id = NULL;
  if (include_optional) {
    _edit_message_text_post_request_chat_id = _edit_message_text_post_request_chat_id_create(
    );
  } else {
    _edit_message_text_post_request_chat_id = _edit_message_text_post_request_chat_id_create(
    );
  }

  return _edit_message_text_post_request_chat_id;
}


#ifdef _edit_message_text_post_request_chat_id_MAIN

void test__edit_message_text_post_request_chat_id(int include_optional) {
    _edit_message_text_post_request_chat_id_t* _edit_message_text_post_request_chat_id_1 = instantiate__edit_message_text_post_request_chat_id(include_optional);

	cJSON* json_edit_message_text_post_request_chat_id_1 = _edit_message_text_post_request_chat_id_convertToJSON(_edit_message_text_post_request_chat_id_1);
	printf("_edit_message_text_post_request_chat_id :\n%s\n", cJSON_Print(json_edit_message_text_post_request_chat_id_1));
	_edit_message_text_post_request_chat_id_t* _edit_message_text_post_request_chat_id_2 = _edit_message_text_post_request_chat_id_parseFromJSON(json_edit_message_text_post_request_chat_id_1);
	cJSON* json_edit_message_text_post_request_chat_id_2 = _edit_message_text_post_request_chat_id_convertToJSON(_edit_message_text_post_request_chat_id_2);
	printf("repeating _edit_message_text_post_request_chat_id:\n%s\n", cJSON_Print(json_edit_message_text_post_request_chat_id_2));
}

int main() {
  test__edit_message_text_post_request_chat_id(1);
  test__edit_message_text_post_request_chat_id(0);

  printf("Hello world \n");
  return 0;
}

#endif // _edit_message_text_post_request_chat_id_MAIN
#endif // _edit_message_text_post_request_chat_id_TEST
