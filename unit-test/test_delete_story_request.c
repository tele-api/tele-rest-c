#ifndef delete_story_request_TEST
#define delete_story_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define delete_story_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/delete_story_request.h"
delete_story_request_t* instantiate_delete_story_request(int include_optional);



delete_story_request_t* instantiate_delete_story_request(int include_optional) {
  delete_story_request_t* delete_story_request = NULL;
  if (include_optional) {
    delete_story_request = delete_story_request_create(
      "0",
      56
    );
  } else {
    delete_story_request = delete_story_request_create(
      "0",
      56
    );
  }

  return delete_story_request;
}


#ifdef delete_story_request_MAIN

void test_delete_story_request(int include_optional) {
    delete_story_request_t* delete_story_request_1 = instantiate_delete_story_request(include_optional);

	cJSON* jsondelete_story_request_1 = delete_story_request_convertToJSON(delete_story_request_1);
	printf("delete_story_request :\n%s\n", cJSON_Print(jsondelete_story_request_1));
	delete_story_request_t* delete_story_request_2 = delete_story_request_parseFromJSON(jsondelete_story_request_1);
	cJSON* jsondelete_story_request_2 = delete_story_request_convertToJSON(delete_story_request_2);
	printf("repeating delete_story_request:\n%s\n", cJSON_Print(jsondelete_story_request_2));
}

int main() {
  test_delete_story_request(1);
  test_delete_story_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // delete_story_request_MAIN
#endif // delete_story_request_TEST
