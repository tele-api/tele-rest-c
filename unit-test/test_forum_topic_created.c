#ifndef forum_topic_created_TEST
#define forum_topic_created_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define forum_topic_created_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/forum_topic_created.h"
forum_topic_created_t* instantiate_forum_topic_created(int include_optional);



forum_topic_created_t* instantiate_forum_topic_created(int include_optional) {
  forum_topic_created_t* forum_topic_created = NULL;
  if (include_optional) {
    forum_topic_created = forum_topic_created_create(
      "0",
      56,
      "0"
    );
  } else {
    forum_topic_created = forum_topic_created_create(
      "0",
      56,
      "0"
    );
  }

  return forum_topic_created;
}


#ifdef forum_topic_created_MAIN

void test_forum_topic_created(int include_optional) {
    forum_topic_created_t* forum_topic_created_1 = instantiate_forum_topic_created(include_optional);

	cJSON* jsonforum_topic_created_1 = forum_topic_created_convertToJSON(forum_topic_created_1);
	printf("forum_topic_created :\n%s\n", cJSON_Print(jsonforum_topic_created_1));
	forum_topic_created_t* forum_topic_created_2 = forum_topic_created_parseFromJSON(jsonforum_topic_created_1);
	cJSON* jsonforum_topic_created_2 = forum_topic_created_convertToJSON(forum_topic_created_2);
	printf("repeating forum_topic_created:\n%s\n", cJSON_Print(jsonforum_topic_created_2));
}

int main() {
  test_forum_topic_created(1);
  test_forum_topic_created(0);

  printf("Hello world \n");
  return 0;
}

#endif // forum_topic_created_MAIN
#endif // forum_topic_created_TEST
