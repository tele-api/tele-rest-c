#ifndef reopen_general_forum_topic_response_TEST
#define reopen_general_forum_topic_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define reopen_general_forum_topic_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/reopen_general_forum_topic_response.h"
reopen_general_forum_topic_response_t* instantiate_reopen_general_forum_topic_response(int include_optional);



reopen_general_forum_topic_response_t* instantiate_reopen_general_forum_topic_response(int include_optional) {
  reopen_general_forum_topic_response_t* reopen_general_forum_topic_response = NULL;
  if (include_optional) {
    reopen_general_forum_topic_response = reopen_general_forum_topic_response_create(
      1,
      1
    );
  } else {
    reopen_general_forum_topic_response = reopen_general_forum_topic_response_create(
      1,
      1
    );
  }

  return reopen_general_forum_topic_response;
}


#ifdef reopen_general_forum_topic_response_MAIN

void test_reopen_general_forum_topic_response(int include_optional) {
    reopen_general_forum_topic_response_t* reopen_general_forum_topic_response_1 = instantiate_reopen_general_forum_topic_response(include_optional);

	cJSON* jsonreopen_general_forum_topic_response_1 = reopen_general_forum_topic_response_convertToJSON(reopen_general_forum_topic_response_1);
	printf("reopen_general_forum_topic_response :\n%s\n", cJSON_Print(jsonreopen_general_forum_topic_response_1));
	reopen_general_forum_topic_response_t* reopen_general_forum_topic_response_2 = reopen_general_forum_topic_response_parseFromJSON(jsonreopen_general_forum_topic_response_1);
	cJSON* jsonreopen_general_forum_topic_response_2 = reopen_general_forum_topic_response_convertToJSON(reopen_general_forum_topic_response_2);
	printf("repeating reopen_general_forum_topic_response:\n%s\n", cJSON_Print(jsonreopen_general_forum_topic_response_2));
}

int main() {
  test_reopen_general_forum_topic_response(1);
  test_reopen_general_forum_topic_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // reopen_general_forum_topic_response_MAIN
#endif // reopen_general_forum_topic_response_TEST
