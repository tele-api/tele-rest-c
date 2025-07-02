#ifndef save_prepared_inline_message_response_TEST
#define save_prepared_inline_message_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define save_prepared_inline_message_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/save_prepared_inline_message_response.h"
save_prepared_inline_message_response_t* instantiate_save_prepared_inline_message_response(int include_optional);

#include "test_prepared_inline_message.c"


save_prepared_inline_message_response_t* instantiate_save_prepared_inline_message_response(int include_optional) {
  save_prepared_inline_message_response_t* save_prepared_inline_message_response = NULL;
  if (include_optional) {
    save_prepared_inline_message_response = save_prepared_inline_message_response_create(
      1,
       // false, not to have infinite recursion
      instantiate_prepared_inline_message(0)
    );
  } else {
    save_prepared_inline_message_response = save_prepared_inline_message_response_create(
      1,
      NULL
    );
  }

  return save_prepared_inline_message_response;
}


#ifdef save_prepared_inline_message_response_MAIN

void test_save_prepared_inline_message_response(int include_optional) {
    save_prepared_inline_message_response_t* save_prepared_inline_message_response_1 = instantiate_save_prepared_inline_message_response(include_optional);

	cJSON* jsonsave_prepared_inline_message_response_1 = save_prepared_inline_message_response_convertToJSON(save_prepared_inline_message_response_1);
	printf("save_prepared_inline_message_response :\n%s\n", cJSON_Print(jsonsave_prepared_inline_message_response_1));
	save_prepared_inline_message_response_t* save_prepared_inline_message_response_2 = save_prepared_inline_message_response_parseFromJSON(jsonsave_prepared_inline_message_response_1);
	cJSON* jsonsave_prepared_inline_message_response_2 = save_prepared_inline_message_response_convertToJSON(save_prepared_inline_message_response_2);
	printf("repeating save_prepared_inline_message_response:\n%s\n", cJSON_Print(jsonsave_prepared_inline_message_response_2));
}

int main() {
  test_save_prepared_inline_message_response(1);
  test_save_prepared_inline_message_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // save_prepared_inline_message_response_MAIN
#endif // save_prepared_inline_message_response_TEST
