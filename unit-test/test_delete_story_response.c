#ifndef delete_story_response_TEST
#define delete_story_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define delete_story_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/delete_story_response.h"
delete_story_response_t* instantiate_delete_story_response(int include_optional);



delete_story_response_t* instantiate_delete_story_response(int include_optional) {
  delete_story_response_t* delete_story_response = NULL;
  if (include_optional) {
    delete_story_response = delete_story_response_create(
      1,
      1
    );
  } else {
    delete_story_response = delete_story_response_create(
      1,
      1
    );
  }

  return delete_story_response;
}


#ifdef delete_story_response_MAIN

void test_delete_story_response(int include_optional) {
    delete_story_response_t* delete_story_response_1 = instantiate_delete_story_response(include_optional);

	cJSON* jsondelete_story_response_1 = delete_story_response_convertToJSON(delete_story_response_1);
	printf("delete_story_response :\n%s\n", cJSON_Print(jsondelete_story_response_1));
	delete_story_response_t* delete_story_response_2 = delete_story_response_parseFromJSON(jsondelete_story_response_1);
	cJSON* jsondelete_story_response_2 = delete_story_response_convertToJSON(delete_story_response_2);
	printf("repeating delete_story_response:\n%s\n", cJSON_Print(jsondelete_story_response_2));
}

int main() {
  test_delete_story_response(1);
  test_delete_story_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // delete_story_response_MAIN
#endif // delete_story_response_TEST
