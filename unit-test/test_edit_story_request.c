#ifndef edit_story_request_TEST
#define edit_story_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define edit_story_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/edit_story_request.h"
edit_story_request_t* instantiate_edit_story_request(int include_optional);

#include "test_input_story_content.c"


edit_story_request_t* instantiate_edit_story_request(int include_optional) {
  edit_story_request_t* edit_story_request = NULL;
  if (include_optional) {
    edit_story_request = edit_story_request_create(
      "0",
      56,
      null,
      "0",
      "0",
      list_createList(),
      list_createList()
    );
  } else {
    edit_story_request = edit_story_request_create(
      "0",
      56,
      null,
      "0",
      "0",
      list_createList(),
      list_createList()
    );
  }

  return edit_story_request;
}


#ifdef edit_story_request_MAIN

void test_edit_story_request(int include_optional) {
    edit_story_request_t* edit_story_request_1 = instantiate_edit_story_request(include_optional);

	cJSON* jsonedit_story_request_1 = edit_story_request_convertToJSON(edit_story_request_1);
	printf("edit_story_request :\n%s\n", cJSON_Print(jsonedit_story_request_1));
	edit_story_request_t* edit_story_request_2 = edit_story_request_parseFromJSON(jsonedit_story_request_1);
	cJSON* jsonedit_story_request_2 = edit_story_request_convertToJSON(edit_story_request_2);
	printf("repeating edit_story_request:\n%s\n", cJSON_Print(jsonedit_story_request_2));
}

int main() {
  test_edit_story_request(1);
  test_edit_story_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // edit_story_request_MAIN
#endif // edit_story_request_TEST
