#ifndef edit_message_text_request_chat_id_TEST
#define edit_message_text_request_chat_id_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define edit_message_text_request_chat_id_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/edit_message_text_request_chat_id.h"
edit_message_text_request_chat_id_t* instantiate_edit_message_text_request_chat_id(int include_optional);



edit_message_text_request_chat_id_t* instantiate_edit_message_text_request_chat_id(int include_optional) {
  edit_message_text_request_chat_id_t* edit_message_text_request_chat_id = NULL;
  if (include_optional) {
    edit_message_text_request_chat_id = edit_message_text_request_chat_id_create(
    );
  } else {
    edit_message_text_request_chat_id = edit_message_text_request_chat_id_create(
    );
  }

  return edit_message_text_request_chat_id;
}


#ifdef edit_message_text_request_chat_id_MAIN

void test_edit_message_text_request_chat_id(int include_optional) {
    edit_message_text_request_chat_id_t* edit_message_text_request_chat_id_1 = instantiate_edit_message_text_request_chat_id(include_optional);

	cJSON* jsonedit_message_text_request_chat_id_1 = edit_message_text_request_chat_id_convertToJSON(edit_message_text_request_chat_id_1);
	printf("edit_message_text_request_chat_id :\n%s\n", cJSON_Print(jsonedit_message_text_request_chat_id_1));
	edit_message_text_request_chat_id_t* edit_message_text_request_chat_id_2 = edit_message_text_request_chat_id_parseFromJSON(jsonedit_message_text_request_chat_id_1);
	cJSON* jsonedit_message_text_request_chat_id_2 = edit_message_text_request_chat_id_convertToJSON(edit_message_text_request_chat_id_2);
	printf("repeating edit_message_text_request_chat_id:\n%s\n", cJSON_Print(jsonedit_message_text_request_chat_id_2));
}

int main() {
  test_edit_message_text_request_chat_id(1);
  test_edit_message_text_request_chat_id(0);

  printf("Hello world \n");
  return 0;
}

#endif // edit_message_text_request_chat_id_MAIN
#endif // edit_message_text_request_chat_id_TEST
