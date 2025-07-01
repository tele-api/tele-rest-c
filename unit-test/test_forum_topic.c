#ifndef forum_topic_TEST
#define forum_topic_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define forum_topic_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/forum_topic.h"
forum_topic_t* instantiate_forum_topic(int include_optional);



forum_topic_t* instantiate_forum_topic(int include_optional) {
  forum_topic_t* forum_topic = NULL;
  if (include_optional) {
    forum_topic = forum_topic_create(
      56,
      "0",
      56,
      "0"
    );
  } else {
    forum_topic = forum_topic_create(
      56,
      "0",
      56,
      "0"
    );
  }

  return forum_topic;
}


#ifdef forum_topic_MAIN

void test_forum_topic(int include_optional) {
    forum_topic_t* forum_topic_1 = instantiate_forum_topic(include_optional);

	cJSON* jsonforum_topic_1 = forum_topic_convertToJSON(forum_topic_1);
	printf("forum_topic :\n%s\n", cJSON_Print(jsonforum_topic_1));
	forum_topic_t* forum_topic_2 = forum_topic_parseFromJSON(jsonforum_topic_1);
	cJSON* jsonforum_topic_2 = forum_topic_convertToJSON(forum_topic_2);
	printf("repeating forum_topic:\n%s\n", cJSON_Print(jsonforum_topic_2));
}

int main() {
  test_forum_topic(1);
  test_forum_topic(0);

  printf("Hello world \n");
  return 0;
}

#endif // forum_topic_MAIN
#endif // forum_topic_TEST
