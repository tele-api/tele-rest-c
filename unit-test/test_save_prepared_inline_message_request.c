#ifndef save_prepared_inline_message_request_TEST
#define save_prepared_inline_message_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define save_prepared_inline_message_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/save_prepared_inline_message_request.h"
save_prepared_inline_message_request_t* instantiate_save_prepared_inline_message_request(int include_optional);

#include "test_inline_query_result.c"


save_prepared_inline_message_request_t* instantiate_save_prepared_inline_message_request(int include_optional) {
  save_prepared_inline_message_request_t* save_prepared_inline_message_request = NULL;
  if (include_optional) {
    save_prepared_inline_message_request = save_prepared_inline_message_request_create(
      56,
      null,
      1,
      1,
      1,
      1
    );
  } else {
    save_prepared_inline_message_request = save_prepared_inline_message_request_create(
      56,
      null,
      1,
      1,
      1,
      1
    );
  }

  return save_prepared_inline_message_request;
}


#ifdef save_prepared_inline_message_request_MAIN

void test_save_prepared_inline_message_request(int include_optional) {
    save_prepared_inline_message_request_t* save_prepared_inline_message_request_1 = instantiate_save_prepared_inline_message_request(include_optional);

	cJSON* jsonsave_prepared_inline_message_request_1 = save_prepared_inline_message_request_convertToJSON(save_prepared_inline_message_request_1);
	printf("save_prepared_inline_message_request :\n%s\n", cJSON_Print(jsonsave_prepared_inline_message_request_1));
	save_prepared_inline_message_request_t* save_prepared_inline_message_request_2 = save_prepared_inline_message_request_parseFromJSON(jsonsave_prepared_inline_message_request_1);
	cJSON* jsonsave_prepared_inline_message_request_2 = save_prepared_inline_message_request_convertToJSON(save_prepared_inline_message_request_2);
	printf("repeating save_prepared_inline_message_request:\n%s\n", cJSON_Print(jsonsave_prepared_inline_message_request_2));
}

int main() {
  test_save_prepared_inline_message_request(1);
  test_save_prepared_inline_message_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // save_prepared_inline_message_request_MAIN
#endif // save_prepared_inline_message_request_TEST
