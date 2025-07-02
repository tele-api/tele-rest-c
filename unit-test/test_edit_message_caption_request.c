#ifndef edit_message_caption_request_TEST
#define edit_message_caption_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define edit_message_caption_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/edit_message_caption_request.h"
edit_message_caption_request_t* instantiate_edit_message_caption_request(int include_optional);

#include "test_edit_message_text_request_chat_id.c"
#include "test_inline_keyboard_markup.c"


edit_message_caption_request_t* instantiate_edit_message_caption_request(int include_optional) {
  edit_message_caption_request_t* edit_message_caption_request = NULL;
  if (include_optional) {
    edit_message_caption_request = edit_message_caption_request_create(
      "0",
      null,
      56,
      "0",
      "0",
      "0",
      list_createList(),
      1,
       // false, not to have infinite recursion
      instantiate_inline_keyboard_markup(0)
    );
  } else {
    edit_message_caption_request = edit_message_caption_request_create(
      "0",
      null,
      56,
      "0",
      "0",
      "0",
      list_createList(),
      1,
      NULL
    );
  }

  return edit_message_caption_request;
}


#ifdef edit_message_caption_request_MAIN

void test_edit_message_caption_request(int include_optional) {
    edit_message_caption_request_t* edit_message_caption_request_1 = instantiate_edit_message_caption_request(include_optional);

	cJSON* jsonedit_message_caption_request_1 = edit_message_caption_request_convertToJSON(edit_message_caption_request_1);
	printf("edit_message_caption_request :\n%s\n", cJSON_Print(jsonedit_message_caption_request_1));
	edit_message_caption_request_t* edit_message_caption_request_2 = edit_message_caption_request_parseFromJSON(jsonedit_message_caption_request_1);
	cJSON* jsonedit_message_caption_request_2 = edit_message_caption_request_convertToJSON(edit_message_caption_request_2);
	printf("repeating edit_message_caption_request:\n%s\n", cJSON_Print(jsonedit_message_caption_request_2));
}

int main() {
  test_edit_message_caption_request(1);
  test_edit_message_caption_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // edit_message_caption_request_MAIN
#endif // edit_message_caption_request_TEST
