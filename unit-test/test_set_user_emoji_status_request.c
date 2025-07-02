#ifndef set_user_emoji_status_request_TEST
#define set_user_emoji_status_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define set_user_emoji_status_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/set_user_emoji_status_request.h"
set_user_emoji_status_request_t* instantiate_set_user_emoji_status_request(int include_optional);



set_user_emoji_status_request_t* instantiate_set_user_emoji_status_request(int include_optional) {
  set_user_emoji_status_request_t* set_user_emoji_status_request = NULL;
  if (include_optional) {
    set_user_emoji_status_request = set_user_emoji_status_request_create(
      56,
      "0",
      56
    );
  } else {
    set_user_emoji_status_request = set_user_emoji_status_request_create(
      56,
      "0",
      56
    );
  }

  return set_user_emoji_status_request;
}


#ifdef set_user_emoji_status_request_MAIN

void test_set_user_emoji_status_request(int include_optional) {
    set_user_emoji_status_request_t* set_user_emoji_status_request_1 = instantiate_set_user_emoji_status_request(include_optional);

	cJSON* jsonset_user_emoji_status_request_1 = set_user_emoji_status_request_convertToJSON(set_user_emoji_status_request_1);
	printf("set_user_emoji_status_request :\n%s\n", cJSON_Print(jsonset_user_emoji_status_request_1));
	set_user_emoji_status_request_t* set_user_emoji_status_request_2 = set_user_emoji_status_request_parseFromJSON(jsonset_user_emoji_status_request_1);
	cJSON* jsonset_user_emoji_status_request_2 = set_user_emoji_status_request_convertToJSON(set_user_emoji_status_request_2);
	printf("repeating set_user_emoji_status_request:\n%s\n", cJSON_Print(jsonset_user_emoji_status_request_2));
}

int main() {
  test_set_user_emoji_status_request(1);
  test_set_user_emoji_status_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // set_user_emoji_status_request_MAIN
#endif // set_user_emoji_status_request_TEST
