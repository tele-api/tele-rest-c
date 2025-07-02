#ifndef hide_general_forum_topic_response_TEST
#define hide_general_forum_topic_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define hide_general_forum_topic_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/hide_general_forum_topic_response.h"
hide_general_forum_topic_response_t* instantiate_hide_general_forum_topic_response(int include_optional);



hide_general_forum_topic_response_t* instantiate_hide_general_forum_topic_response(int include_optional) {
  hide_general_forum_topic_response_t* hide_general_forum_topic_response = NULL;
  if (include_optional) {
    hide_general_forum_topic_response = hide_general_forum_topic_response_create(
      1,
      1
    );
  } else {
    hide_general_forum_topic_response = hide_general_forum_topic_response_create(
      1,
      1
    );
  }

  return hide_general_forum_topic_response;
}


#ifdef hide_general_forum_topic_response_MAIN

void test_hide_general_forum_topic_response(int include_optional) {
    hide_general_forum_topic_response_t* hide_general_forum_topic_response_1 = instantiate_hide_general_forum_topic_response(include_optional);

	cJSON* jsonhide_general_forum_topic_response_1 = hide_general_forum_topic_response_convertToJSON(hide_general_forum_topic_response_1);
	printf("hide_general_forum_topic_response :\n%s\n", cJSON_Print(jsonhide_general_forum_topic_response_1));
	hide_general_forum_topic_response_t* hide_general_forum_topic_response_2 = hide_general_forum_topic_response_parseFromJSON(jsonhide_general_forum_topic_response_1);
	cJSON* jsonhide_general_forum_topic_response_2 = hide_general_forum_topic_response_convertToJSON(hide_general_forum_topic_response_2);
	printf("repeating hide_general_forum_topic_response:\n%s\n", cJSON_Print(jsonhide_general_forum_topic_response_2));
}

int main() {
  test_hide_general_forum_topic_response(1);
  test_hide_general_forum_topic_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // hide_general_forum_topic_response_MAIN
#endif // hide_general_forum_topic_response_TEST
