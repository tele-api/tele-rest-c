#ifndef edit_story_response_TEST
#define edit_story_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define edit_story_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/edit_story_response.h"
edit_story_response_t* instantiate_edit_story_response(int include_optional);

#include "test_story.c"


edit_story_response_t* instantiate_edit_story_response(int include_optional) {
  edit_story_response_t* edit_story_response = NULL;
  if (include_optional) {
    edit_story_response = edit_story_response_create(
      1,
       // false, not to have infinite recursion
      instantiate_story(0)
    );
  } else {
    edit_story_response = edit_story_response_create(
      1,
      NULL
    );
  }

  return edit_story_response;
}


#ifdef edit_story_response_MAIN

void test_edit_story_response(int include_optional) {
    edit_story_response_t* edit_story_response_1 = instantiate_edit_story_response(include_optional);

	cJSON* jsonedit_story_response_1 = edit_story_response_convertToJSON(edit_story_response_1);
	printf("edit_story_response :\n%s\n", cJSON_Print(jsonedit_story_response_1));
	edit_story_response_t* edit_story_response_2 = edit_story_response_parseFromJSON(jsonedit_story_response_1);
	cJSON* jsonedit_story_response_2 = edit_story_response_convertToJSON(edit_story_response_2);
	printf("repeating edit_story_response:\n%s\n", cJSON_Print(jsonedit_story_response_2));
}

int main() {
  test_edit_story_response(1);
  test_edit_story_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // edit_story_response_MAIN
#endif // edit_story_response_TEST
