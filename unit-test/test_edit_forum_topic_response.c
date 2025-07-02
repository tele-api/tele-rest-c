#ifndef edit_forum_topic_response_TEST
#define edit_forum_topic_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define edit_forum_topic_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/edit_forum_topic_response.h"
edit_forum_topic_response_t* instantiate_edit_forum_topic_response(int include_optional);



edit_forum_topic_response_t* instantiate_edit_forum_topic_response(int include_optional) {
  edit_forum_topic_response_t* edit_forum_topic_response = NULL;
  if (include_optional) {
    edit_forum_topic_response = edit_forum_topic_response_create(
      1,
      1
    );
  } else {
    edit_forum_topic_response = edit_forum_topic_response_create(
      1,
      1
    );
  }

  return edit_forum_topic_response;
}


#ifdef edit_forum_topic_response_MAIN

void test_edit_forum_topic_response(int include_optional) {
    edit_forum_topic_response_t* edit_forum_topic_response_1 = instantiate_edit_forum_topic_response(include_optional);

	cJSON* jsonedit_forum_topic_response_1 = edit_forum_topic_response_convertToJSON(edit_forum_topic_response_1);
	printf("edit_forum_topic_response :\n%s\n", cJSON_Print(jsonedit_forum_topic_response_1));
	edit_forum_topic_response_t* edit_forum_topic_response_2 = edit_forum_topic_response_parseFromJSON(jsonedit_forum_topic_response_1);
	cJSON* jsonedit_forum_topic_response_2 = edit_forum_topic_response_convertToJSON(edit_forum_topic_response_2);
	printf("repeating edit_forum_topic_response:\n%s\n", cJSON_Print(jsonedit_forum_topic_response_2));
}

int main() {
  test_edit_forum_topic_response(1);
  test_edit_forum_topic_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // edit_forum_topic_response_MAIN
#endif // edit_forum_topic_response_TEST
