#ifndef set_user_emoji_status_response_TEST
#define set_user_emoji_status_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define set_user_emoji_status_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/set_user_emoji_status_response.h"
set_user_emoji_status_response_t* instantiate_set_user_emoji_status_response(int include_optional);



set_user_emoji_status_response_t* instantiate_set_user_emoji_status_response(int include_optional) {
  set_user_emoji_status_response_t* set_user_emoji_status_response = NULL;
  if (include_optional) {
    set_user_emoji_status_response = set_user_emoji_status_response_create(
      1,
      1
    );
  } else {
    set_user_emoji_status_response = set_user_emoji_status_response_create(
      1,
      1
    );
  }

  return set_user_emoji_status_response;
}


#ifdef set_user_emoji_status_response_MAIN

void test_set_user_emoji_status_response(int include_optional) {
    set_user_emoji_status_response_t* set_user_emoji_status_response_1 = instantiate_set_user_emoji_status_response(include_optional);

	cJSON* jsonset_user_emoji_status_response_1 = set_user_emoji_status_response_convertToJSON(set_user_emoji_status_response_1);
	printf("set_user_emoji_status_response :\n%s\n", cJSON_Print(jsonset_user_emoji_status_response_1));
	set_user_emoji_status_response_t* set_user_emoji_status_response_2 = set_user_emoji_status_response_parseFromJSON(jsonset_user_emoji_status_response_1);
	cJSON* jsonset_user_emoji_status_response_2 = set_user_emoji_status_response_convertToJSON(set_user_emoji_status_response_2);
	printf("repeating set_user_emoji_status_response:\n%s\n", cJSON_Print(jsonset_user_emoji_status_response_2));
}

int main() {
  test_set_user_emoji_status_response(1);
  test_set_user_emoji_status_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // set_user_emoji_status_response_MAIN
#endif // set_user_emoji_status_response_TEST
