#ifndef delete_messages_response_TEST
#define delete_messages_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define delete_messages_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/delete_messages_response.h"
delete_messages_response_t* instantiate_delete_messages_response(int include_optional);



delete_messages_response_t* instantiate_delete_messages_response(int include_optional) {
  delete_messages_response_t* delete_messages_response = NULL;
  if (include_optional) {
    delete_messages_response = delete_messages_response_create(
      1,
      1
    );
  } else {
    delete_messages_response = delete_messages_response_create(
      1,
      1
    );
  }

  return delete_messages_response;
}


#ifdef delete_messages_response_MAIN

void test_delete_messages_response(int include_optional) {
    delete_messages_response_t* delete_messages_response_1 = instantiate_delete_messages_response(include_optional);

	cJSON* jsondelete_messages_response_1 = delete_messages_response_convertToJSON(delete_messages_response_1);
	printf("delete_messages_response :\n%s\n", cJSON_Print(jsondelete_messages_response_1));
	delete_messages_response_t* delete_messages_response_2 = delete_messages_response_parseFromJSON(jsondelete_messages_response_1);
	cJSON* jsondelete_messages_response_2 = delete_messages_response_convertToJSON(delete_messages_response_2);
	printf("repeating delete_messages_response:\n%s\n", cJSON_Print(jsondelete_messages_response_2));
}

int main() {
  test_delete_messages_response(1);
  test_delete_messages_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // delete_messages_response_MAIN
#endif // delete_messages_response_TEST
