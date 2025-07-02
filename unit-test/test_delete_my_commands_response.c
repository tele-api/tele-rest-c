#ifndef delete_my_commands_response_TEST
#define delete_my_commands_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define delete_my_commands_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/delete_my_commands_response.h"
delete_my_commands_response_t* instantiate_delete_my_commands_response(int include_optional);



delete_my_commands_response_t* instantiate_delete_my_commands_response(int include_optional) {
  delete_my_commands_response_t* delete_my_commands_response = NULL;
  if (include_optional) {
    delete_my_commands_response = delete_my_commands_response_create(
      1,
      1
    );
  } else {
    delete_my_commands_response = delete_my_commands_response_create(
      1,
      1
    );
  }

  return delete_my_commands_response;
}


#ifdef delete_my_commands_response_MAIN

void test_delete_my_commands_response(int include_optional) {
    delete_my_commands_response_t* delete_my_commands_response_1 = instantiate_delete_my_commands_response(include_optional);

	cJSON* jsondelete_my_commands_response_1 = delete_my_commands_response_convertToJSON(delete_my_commands_response_1);
	printf("delete_my_commands_response :\n%s\n", cJSON_Print(jsondelete_my_commands_response_1));
	delete_my_commands_response_t* delete_my_commands_response_2 = delete_my_commands_response_parseFromJSON(jsondelete_my_commands_response_1);
	cJSON* jsondelete_my_commands_response_2 = delete_my_commands_response_convertToJSON(delete_my_commands_response_2);
	printf("repeating delete_my_commands_response:\n%s\n", cJSON_Print(jsondelete_my_commands_response_2));
}

int main() {
  test_delete_my_commands_response(1);
  test_delete_my_commands_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // delete_my_commands_response_MAIN
#endif // delete_my_commands_response_TEST
