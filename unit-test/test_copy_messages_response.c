#ifndef copy_messages_response_TEST
#define copy_messages_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define copy_messages_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/copy_messages_response.h"
copy_messages_response_t* instantiate_copy_messages_response(int include_optional);



copy_messages_response_t* instantiate_copy_messages_response(int include_optional) {
  copy_messages_response_t* copy_messages_response = NULL;
  if (include_optional) {
    copy_messages_response = copy_messages_response_create(
      1,
      list_createList()
    );
  } else {
    copy_messages_response = copy_messages_response_create(
      1,
      list_createList()
    );
  }

  return copy_messages_response;
}


#ifdef copy_messages_response_MAIN

void test_copy_messages_response(int include_optional) {
    copy_messages_response_t* copy_messages_response_1 = instantiate_copy_messages_response(include_optional);

	cJSON* jsoncopy_messages_response_1 = copy_messages_response_convertToJSON(copy_messages_response_1);
	printf("copy_messages_response :\n%s\n", cJSON_Print(jsoncopy_messages_response_1));
	copy_messages_response_t* copy_messages_response_2 = copy_messages_response_parseFromJSON(jsoncopy_messages_response_1);
	cJSON* jsoncopy_messages_response_2 = copy_messages_response_convertToJSON(copy_messages_response_2);
	printf("repeating copy_messages_response:\n%s\n", cJSON_Print(jsoncopy_messages_response_2));
}

int main() {
  test_copy_messages_response(1);
  test_copy_messages_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // copy_messages_response_MAIN
#endif // copy_messages_response_TEST
