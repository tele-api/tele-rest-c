#ifndef edit_chat_invite_link_response_TEST
#define edit_chat_invite_link_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define edit_chat_invite_link_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/edit_chat_invite_link_response.h"
edit_chat_invite_link_response_t* instantiate_edit_chat_invite_link_response(int include_optional);

#include "test_chat_invite_link.c"


edit_chat_invite_link_response_t* instantiate_edit_chat_invite_link_response(int include_optional) {
  edit_chat_invite_link_response_t* edit_chat_invite_link_response = NULL;
  if (include_optional) {
    edit_chat_invite_link_response = edit_chat_invite_link_response_create(
      1,
       // false, not to have infinite recursion
      instantiate_chat_invite_link(0)
    );
  } else {
    edit_chat_invite_link_response = edit_chat_invite_link_response_create(
      1,
      NULL
    );
  }

  return edit_chat_invite_link_response;
}


#ifdef edit_chat_invite_link_response_MAIN

void test_edit_chat_invite_link_response(int include_optional) {
    edit_chat_invite_link_response_t* edit_chat_invite_link_response_1 = instantiate_edit_chat_invite_link_response(include_optional);

	cJSON* jsonedit_chat_invite_link_response_1 = edit_chat_invite_link_response_convertToJSON(edit_chat_invite_link_response_1);
	printf("edit_chat_invite_link_response :\n%s\n", cJSON_Print(jsonedit_chat_invite_link_response_1));
	edit_chat_invite_link_response_t* edit_chat_invite_link_response_2 = edit_chat_invite_link_response_parseFromJSON(jsonedit_chat_invite_link_response_1);
	cJSON* jsonedit_chat_invite_link_response_2 = edit_chat_invite_link_response_convertToJSON(edit_chat_invite_link_response_2);
	printf("repeating edit_chat_invite_link_response:\n%s\n", cJSON_Print(jsonedit_chat_invite_link_response_2));
}

int main() {
  test_edit_chat_invite_link_response(1);
  test_edit_chat_invite_link_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // edit_chat_invite_link_response_MAIN
#endif // edit_chat_invite_link_response_TEST
