#ifndef edit_message_text_response_TEST
#define edit_message_text_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define edit_message_text_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/edit_message_text_response.h"
edit_message_text_response_t* instantiate_edit_message_text_response(int include_optional);

#include "test_edit_message_text_response_result.c"


edit_message_text_response_t* instantiate_edit_message_text_response(int include_optional) {
  edit_message_text_response_t* edit_message_text_response = NULL;
  if (include_optional) {
    edit_message_text_response = edit_message_text_response_create(
      1,
      null
    );
  } else {
    edit_message_text_response = edit_message_text_response_create(
      1,
      null
    );
  }

  return edit_message_text_response;
}


#ifdef edit_message_text_response_MAIN

void test_edit_message_text_response(int include_optional) {
    edit_message_text_response_t* edit_message_text_response_1 = instantiate_edit_message_text_response(include_optional);

	cJSON* jsonedit_message_text_response_1 = edit_message_text_response_convertToJSON(edit_message_text_response_1);
	printf("edit_message_text_response :\n%s\n", cJSON_Print(jsonedit_message_text_response_1));
	edit_message_text_response_t* edit_message_text_response_2 = edit_message_text_response_parseFromJSON(jsonedit_message_text_response_1);
	cJSON* jsonedit_message_text_response_2 = edit_message_text_response_convertToJSON(edit_message_text_response_2);
	printf("repeating edit_message_text_response:\n%s\n", cJSON_Print(jsonedit_message_text_response_2));
}

int main() {
  test_edit_message_text_response(1);
  test_edit_message_text_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // edit_message_text_response_MAIN
#endif // edit_message_text_response_TEST
