#ifndef delete_my_commands_request_TEST
#define delete_my_commands_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define delete_my_commands_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/delete_my_commands_request.h"
delete_my_commands_request_t* instantiate_delete_my_commands_request(int include_optional);

#include "test_bot_command_scope.c"


delete_my_commands_request_t* instantiate_delete_my_commands_request(int include_optional) {
  delete_my_commands_request_t* delete_my_commands_request = NULL;
  if (include_optional) {
    delete_my_commands_request = delete_my_commands_request_create(
      null,
      "0"
    );
  } else {
    delete_my_commands_request = delete_my_commands_request_create(
      null,
      "0"
    );
  }

  return delete_my_commands_request;
}


#ifdef delete_my_commands_request_MAIN

void test_delete_my_commands_request(int include_optional) {
    delete_my_commands_request_t* delete_my_commands_request_1 = instantiate_delete_my_commands_request(include_optional);

	cJSON* jsondelete_my_commands_request_1 = delete_my_commands_request_convertToJSON(delete_my_commands_request_1);
	printf("delete_my_commands_request :\n%s\n", cJSON_Print(jsondelete_my_commands_request_1));
	delete_my_commands_request_t* delete_my_commands_request_2 = delete_my_commands_request_parseFromJSON(jsondelete_my_commands_request_1);
	cJSON* jsondelete_my_commands_request_2 = delete_my_commands_request_convertToJSON(delete_my_commands_request_2);
	printf("repeating delete_my_commands_request:\n%s\n", cJSON_Print(jsondelete_my_commands_request_2));
}

int main() {
  test_delete_my_commands_request(1);
  test_delete_my_commands_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // delete_my_commands_request_MAIN
#endif // delete_my_commands_request_TEST
