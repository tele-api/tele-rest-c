#ifndef forum_topic_edited_TEST
#define forum_topic_edited_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define forum_topic_edited_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/forum_topic_edited.h"
forum_topic_edited_t* instantiate_forum_topic_edited(int include_optional);



forum_topic_edited_t* instantiate_forum_topic_edited(int include_optional) {
  forum_topic_edited_t* forum_topic_edited = NULL;
  if (include_optional) {
    forum_topic_edited = forum_topic_edited_create(
      "0",
      "0"
    );
  } else {
    forum_topic_edited = forum_topic_edited_create(
      "0",
      "0"
    );
  }

  return forum_topic_edited;
}


#ifdef forum_topic_edited_MAIN

void test_forum_topic_edited(int include_optional) {
    forum_topic_edited_t* forum_topic_edited_1 = instantiate_forum_topic_edited(include_optional);

	cJSON* jsonforum_topic_edited_1 = forum_topic_edited_convertToJSON(forum_topic_edited_1);
	printf("forum_topic_edited :\n%s\n", cJSON_Print(jsonforum_topic_edited_1));
	forum_topic_edited_t* forum_topic_edited_2 = forum_topic_edited_parseFromJSON(jsonforum_topic_edited_1);
	cJSON* jsonforum_topic_edited_2 = forum_topic_edited_convertToJSON(forum_topic_edited_2);
	printf("repeating forum_topic_edited:\n%s\n", cJSON_Print(jsonforum_topic_edited_2));
}

int main() {
  test_forum_topic_edited(1);
  test_forum_topic_edited(0);

  printf("Hello world \n");
  return 0;
}

#endif // forum_topic_edited_MAIN
#endif // forum_topic_edited_TEST
