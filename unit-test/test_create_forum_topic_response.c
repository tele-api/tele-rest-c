#ifndef create_forum_topic_response_TEST
#define create_forum_topic_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define create_forum_topic_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/create_forum_topic_response.h"
create_forum_topic_response_t* instantiate_create_forum_topic_response(int include_optional);

#include "test_forum_topic.c"


create_forum_topic_response_t* instantiate_create_forum_topic_response(int include_optional) {
  create_forum_topic_response_t* create_forum_topic_response = NULL;
  if (include_optional) {
    create_forum_topic_response = create_forum_topic_response_create(
      1,
       // false, not to have infinite recursion
      instantiate_forum_topic(0)
    );
  } else {
    create_forum_topic_response = create_forum_topic_response_create(
      1,
      NULL
    );
  }

  return create_forum_topic_response;
}


#ifdef create_forum_topic_response_MAIN

void test_create_forum_topic_response(int include_optional) {
    create_forum_topic_response_t* create_forum_topic_response_1 = instantiate_create_forum_topic_response(include_optional);

	cJSON* jsoncreate_forum_topic_response_1 = create_forum_topic_response_convertToJSON(create_forum_topic_response_1);
	printf("create_forum_topic_response :\n%s\n", cJSON_Print(jsoncreate_forum_topic_response_1));
	create_forum_topic_response_t* create_forum_topic_response_2 = create_forum_topic_response_parseFromJSON(jsoncreate_forum_topic_response_1);
	cJSON* jsoncreate_forum_topic_response_2 = create_forum_topic_response_convertToJSON(create_forum_topic_response_2);
	printf("repeating create_forum_topic_response:\n%s\n", cJSON_Print(jsoncreate_forum_topic_response_2));
}

int main() {
  test_create_forum_topic_response(1);
  test_create_forum_topic_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // create_forum_topic_response_MAIN
#endif // create_forum_topic_response_TEST
