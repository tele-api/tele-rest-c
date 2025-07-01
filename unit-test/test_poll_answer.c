#ifndef poll_answer_TEST
#define poll_answer_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define poll_answer_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/poll_answer.h"
poll_answer_t* instantiate_poll_answer(int include_optional);

#include "test_chat.c"
#include "test_user.c"


poll_answer_t* instantiate_poll_answer(int include_optional) {
  poll_answer_t* poll_answer = NULL;
  if (include_optional) {
    poll_answer = poll_answer_create(
      "0",
      list_createList(),
       // false, not to have infinite recursion
      instantiate_chat(0),
       // false, not to have infinite recursion
      instantiate_user(0)
    );
  } else {
    poll_answer = poll_answer_create(
      "0",
      list_createList(),
      NULL,
      NULL
    );
  }

  return poll_answer;
}


#ifdef poll_answer_MAIN

void test_poll_answer(int include_optional) {
    poll_answer_t* poll_answer_1 = instantiate_poll_answer(include_optional);

	cJSON* jsonpoll_answer_1 = poll_answer_convertToJSON(poll_answer_1);
	printf("poll_answer :\n%s\n", cJSON_Print(jsonpoll_answer_1));
	poll_answer_t* poll_answer_2 = poll_answer_parseFromJSON(jsonpoll_answer_1);
	cJSON* jsonpoll_answer_2 = poll_answer_convertToJSON(poll_answer_2);
	printf("repeating poll_answer:\n%s\n", cJSON_Print(jsonpoll_answer_2));
}

int main() {
  test_poll_answer(1);
  test_poll_answer(0);

  printf("Hello world \n");
  return 0;
}

#endif // poll_answer_MAIN
#endif // poll_answer_TEST
