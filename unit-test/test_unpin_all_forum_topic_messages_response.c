#ifndef unpin_all_forum_topic_messages_response_TEST
#define unpin_all_forum_topic_messages_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define unpin_all_forum_topic_messages_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/unpin_all_forum_topic_messages_response.h"
unpin_all_forum_topic_messages_response_t* instantiate_unpin_all_forum_topic_messages_response(int include_optional);



unpin_all_forum_topic_messages_response_t* instantiate_unpin_all_forum_topic_messages_response(int include_optional) {
  unpin_all_forum_topic_messages_response_t* unpin_all_forum_topic_messages_response = NULL;
  if (include_optional) {
    unpin_all_forum_topic_messages_response = unpin_all_forum_topic_messages_response_create(
      1,
      1
    );
  } else {
    unpin_all_forum_topic_messages_response = unpin_all_forum_topic_messages_response_create(
      1,
      1
    );
  }

  return unpin_all_forum_topic_messages_response;
}


#ifdef unpin_all_forum_topic_messages_response_MAIN

void test_unpin_all_forum_topic_messages_response(int include_optional) {
    unpin_all_forum_topic_messages_response_t* unpin_all_forum_topic_messages_response_1 = instantiate_unpin_all_forum_topic_messages_response(include_optional);

	cJSON* jsonunpin_all_forum_topic_messages_response_1 = unpin_all_forum_topic_messages_response_convertToJSON(unpin_all_forum_topic_messages_response_1);
	printf("unpin_all_forum_topic_messages_response :\n%s\n", cJSON_Print(jsonunpin_all_forum_topic_messages_response_1));
	unpin_all_forum_topic_messages_response_t* unpin_all_forum_topic_messages_response_2 = unpin_all_forum_topic_messages_response_parseFromJSON(jsonunpin_all_forum_topic_messages_response_1);
	cJSON* jsonunpin_all_forum_topic_messages_response_2 = unpin_all_forum_topic_messages_response_convertToJSON(unpin_all_forum_topic_messages_response_2);
	printf("repeating unpin_all_forum_topic_messages_response:\n%s\n", cJSON_Print(jsonunpin_all_forum_topic_messages_response_2));
}

int main() {
  test_unpin_all_forum_topic_messages_response(1);
  test_unpin_all_forum_topic_messages_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // unpin_all_forum_topic_messages_response_MAIN
#endif // unpin_all_forum_topic_messages_response_TEST
