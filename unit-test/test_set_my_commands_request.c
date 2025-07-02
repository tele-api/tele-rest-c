#ifndef set_my_commands_request_TEST
#define set_my_commands_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define set_my_commands_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/set_my_commands_request.h"
set_my_commands_request_t* instantiate_set_my_commands_request(int include_optional);

#include "test_bot_command_scope.c"


set_my_commands_request_t* instantiate_set_my_commands_request(int include_optional) {
  set_my_commands_request_t* set_my_commands_request = NULL;
  if (include_optional) {
    set_my_commands_request = set_my_commands_request_create(
      list_createList(),
      null,
      "0"
    );
  } else {
    set_my_commands_request = set_my_commands_request_create(
      list_createList(),
      null,
      "0"
    );
  }

  return set_my_commands_request;
}


#ifdef set_my_commands_request_MAIN

void test_set_my_commands_request(int include_optional) {
    set_my_commands_request_t* set_my_commands_request_1 = instantiate_set_my_commands_request(include_optional);

	cJSON* jsonset_my_commands_request_1 = set_my_commands_request_convertToJSON(set_my_commands_request_1);
	printf("set_my_commands_request :\n%s\n", cJSON_Print(jsonset_my_commands_request_1));
	set_my_commands_request_t* set_my_commands_request_2 = set_my_commands_request_parseFromJSON(jsonset_my_commands_request_1);
	cJSON* jsonset_my_commands_request_2 = set_my_commands_request_convertToJSON(set_my_commands_request_2);
	printf("repeating set_my_commands_request:\n%s\n", cJSON_Print(jsonset_my_commands_request_2));
}

int main() {
  test_set_my_commands_request(1);
  test_set_my_commands_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // set_my_commands_request_MAIN
#endif // set_my_commands_request_TEST
