#ifndef copy_message_response_TEST
#define copy_message_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define copy_message_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/copy_message_response.h"
copy_message_response_t* instantiate_copy_message_response(int include_optional);

#include "test_message_id.c"


copy_message_response_t* instantiate_copy_message_response(int include_optional) {
  copy_message_response_t* copy_message_response = NULL;
  if (include_optional) {
    copy_message_response = copy_message_response_create(
      1,
       // false, not to have infinite recursion
      instantiate_message_id(0)
    );
  } else {
    copy_message_response = copy_message_response_create(
      1,
      NULL
    );
  }

  return copy_message_response;
}


#ifdef copy_message_response_MAIN

void test_copy_message_response(int include_optional) {
    copy_message_response_t* copy_message_response_1 = instantiate_copy_message_response(include_optional);

	cJSON* jsoncopy_message_response_1 = copy_message_response_convertToJSON(copy_message_response_1);
	printf("copy_message_response :\n%s\n", cJSON_Print(jsoncopy_message_response_1));
	copy_message_response_t* copy_message_response_2 = copy_message_response_parseFromJSON(jsoncopy_message_response_1);
	cJSON* jsoncopy_message_response_2 = copy_message_response_convertToJSON(copy_message_response_2);
	printf("repeating copy_message_response:\n%s\n", cJSON_Print(jsoncopy_message_response_2));
}

int main() {
  test_copy_message_response(1);
  test_copy_message_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // copy_message_response_MAIN
#endif // copy_message_response_TEST
