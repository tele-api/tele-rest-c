#ifndef poll_TEST
#define poll_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define poll_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/poll.h"
poll_t* instantiate_poll(int include_optional);



poll_t* instantiate_poll(int include_optional) {
  poll_t* poll = NULL;
  if (include_optional) {
    poll = poll_create(
      "0",
      "0",
      list_createList(),
      56,
      1,
      1,
      telegram_bot_api_poll_TYPE_regular,
      1,
      list_createList(),
      56,
      "0",
      list_createList(),
      56,
      56
    );
  } else {
    poll = poll_create(
      "0",
      "0",
      list_createList(),
      56,
      1,
      1,
      telegram_bot_api_poll_TYPE_regular,
      1,
      list_createList(),
      56,
      "0",
      list_createList(),
      56,
      56
    );
  }

  return poll;
}


#ifdef poll_MAIN

void test_poll(int include_optional) {
    poll_t* poll_1 = instantiate_poll(include_optional);

	cJSON* jsonpoll_1 = poll_convertToJSON(poll_1);
	printf("poll :\n%s\n", cJSON_Print(jsonpoll_1));
	poll_t* poll_2 = poll_parseFromJSON(jsonpoll_1);
	cJSON* jsonpoll_2 = poll_convertToJSON(poll_2);
	printf("repeating poll:\n%s\n", cJSON_Print(jsonpoll_2));
}

int main() {
  test_poll(1);
  test_poll(0);

  printf("Hello world \n");
  return 0;
}

#endif // poll_MAIN
#endif // poll_TEST
