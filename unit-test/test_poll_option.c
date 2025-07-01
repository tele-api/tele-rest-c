#ifndef poll_option_TEST
#define poll_option_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define poll_option_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/poll_option.h"
poll_option_t* instantiate_poll_option(int include_optional);



poll_option_t* instantiate_poll_option(int include_optional) {
  poll_option_t* poll_option = NULL;
  if (include_optional) {
    poll_option = poll_option_create(
      "0",
      56,
      list_createList()
    );
  } else {
    poll_option = poll_option_create(
      "0",
      56,
      list_createList()
    );
  }

  return poll_option;
}


#ifdef poll_option_MAIN

void test_poll_option(int include_optional) {
    poll_option_t* poll_option_1 = instantiate_poll_option(include_optional);

	cJSON* jsonpoll_option_1 = poll_option_convertToJSON(poll_option_1);
	printf("poll_option :\n%s\n", cJSON_Print(jsonpoll_option_1));
	poll_option_t* poll_option_2 = poll_option_parseFromJSON(jsonpoll_option_1);
	cJSON* jsonpoll_option_2 = poll_option_convertToJSON(poll_option_2);
	printf("repeating poll_option:\n%s\n", cJSON_Print(jsonpoll_option_2));
}

int main() {
  test_poll_option(1);
  test_poll_option(0);

  printf("Hello world \n");
  return 0;
}

#endif // poll_option_MAIN
#endif // poll_option_TEST
