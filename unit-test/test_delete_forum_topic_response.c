#ifndef delete_forum_topic_response_TEST
#define delete_forum_topic_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define delete_forum_topic_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/delete_forum_topic_response.h"
delete_forum_topic_response_t* instantiate_delete_forum_topic_response(int include_optional);



delete_forum_topic_response_t* instantiate_delete_forum_topic_response(int include_optional) {
  delete_forum_topic_response_t* delete_forum_topic_response = NULL;
  if (include_optional) {
    delete_forum_topic_response = delete_forum_topic_response_create(
      1,
      1
    );
  } else {
    delete_forum_topic_response = delete_forum_topic_response_create(
      1,
      1
    );
  }

  return delete_forum_topic_response;
}


#ifdef delete_forum_topic_response_MAIN

void test_delete_forum_topic_response(int include_optional) {
    delete_forum_topic_response_t* delete_forum_topic_response_1 = instantiate_delete_forum_topic_response(include_optional);

	cJSON* jsondelete_forum_topic_response_1 = delete_forum_topic_response_convertToJSON(delete_forum_topic_response_1);
	printf("delete_forum_topic_response :\n%s\n", cJSON_Print(jsondelete_forum_topic_response_1));
	delete_forum_topic_response_t* delete_forum_topic_response_2 = delete_forum_topic_response_parseFromJSON(jsondelete_forum_topic_response_1);
	cJSON* jsondelete_forum_topic_response_2 = delete_forum_topic_response_convertToJSON(delete_forum_topic_response_2);
	printf("repeating delete_forum_topic_response:\n%s\n", cJSON_Print(jsondelete_forum_topic_response_2));
}

int main() {
  test_delete_forum_topic_response(1);
  test_delete_forum_topic_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // delete_forum_topic_response_MAIN
#endif // delete_forum_topic_response_TEST
