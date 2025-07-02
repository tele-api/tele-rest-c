#ifndef unhide_general_forum_topic_response_TEST
#define unhide_general_forum_topic_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define unhide_general_forum_topic_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/unhide_general_forum_topic_response.h"
unhide_general_forum_topic_response_t* instantiate_unhide_general_forum_topic_response(int include_optional);



unhide_general_forum_topic_response_t* instantiate_unhide_general_forum_topic_response(int include_optional) {
  unhide_general_forum_topic_response_t* unhide_general_forum_topic_response = NULL;
  if (include_optional) {
    unhide_general_forum_topic_response = unhide_general_forum_topic_response_create(
      1,
      1
    );
  } else {
    unhide_general_forum_topic_response = unhide_general_forum_topic_response_create(
      1,
      1
    );
  }

  return unhide_general_forum_topic_response;
}


#ifdef unhide_general_forum_topic_response_MAIN

void test_unhide_general_forum_topic_response(int include_optional) {
    unhide_general_forum_topic_response_t* unhide_general_forum_topic_response_1 = instantiate_unhide_general_forum_topic_response(include_optional);

	cJSON* jsonunhide_general_forum_topic_response_1 = unhide_general_forum_topic_response_convertToJSON(unhide_general_forum_topic_response_1);
	printf("unhide_general_forum_topic_response :\n%s\n", cJSON_Print(jsonunhide_general_forum_topic_response_1));
	unhide_general_forum_topic_response_t* unhide_general_forum_topic_response_2 = unhide_general_forum_topic_response_parseFromJSON(jsonunhide_general_forum_topic_response_1);
	cJSON* jsonunhide_general_forum_topic_response_2 = unhide_general_forum_topic_response_convertToJSON(unhide_general_forum_topic_response_2);
	printf("repeating unhide_general_forum_topic_response:\n%s\n", cJSON_Print(jsonunhide_general_forum_topic_response_2));
}

int main() {
  test_unhide_general_forum_topic_response(1);
  test_unhide_general_forum_topic_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // unhide_general_forum_topic_response_MAIN
#endif // unhide_general_forum_topic_response_TEST
