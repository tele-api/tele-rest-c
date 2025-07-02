#ifndef set_message_reaction_request_TEST
#define set_message_reaction_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define set_message_reaction_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/set_message_reaction_request.h"
set_message_reaction_request_t* instantiate_set_message_reaction_request(int include_optional);

#include "test_send_message_request_chat_id.c"


set_message_reaction_request_t* instantiate_set_message_reaction_request(int include_optional) {
  set_message_reaction_request_t* set_message_reaction_request = NULL;
  if (include_optional) {
    set_message_reaction_request = set_message_reaction_request_create(
      null,
      56,
      list_createList(),
      1
    );
  } else {
    set_message_reaction_request = set_message_reaction_request_create(
      null,
      56,
      list_createList(),
      1
    );
  }

  return set_message_reaction_request;
}


#ifdef set_message_reaction_request_MAIN

void test_set_message_reaction_request(int include_optional) {
    set_message_reaction_request_t* set_message_reaction_request_1 = instantiate_set_message_reaction_request(include_optional);

	cJSON* jsonset_message_reaction_request_1 = set_message_reaction_request_convertToJSON(set_message_reaction_request_1);
	printf("set_message_reaction_request :\n%s\n", cJSON_Print(jsonset_message_reaction_request_1));
	set_message_reaction_request_t* set_message_reaction_request_2 = set_message_reaction_request_parseFromJSON(jsonset_message_reaction_request_1);
	cJSON* jsonset_message_reaction_request_2 = set_message_reaction_request_convertToJSON(set_message_reaction_request_2);
	printf("repeating set_message_reaction_request:\n%s\n", cJSON_Print(jsonset_message_reaction_request_2));
}

int main() {
  test_set_message_reaction_request(1);
  test_set_message_reaction_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // set_message_reaction_request_MAIN
#endif // set_message_reaction_request_TEST
