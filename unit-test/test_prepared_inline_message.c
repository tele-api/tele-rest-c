#ifndef prepared_inline_message_TEST
#define prepared_inline_message_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define prepared_inline_message_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/prepared_inline_message.h"
prepared_inline_message_t* instantiate_prepared_inline_message(int include_optional);



prepared_inline_message_t* instantiate_prepared_inline_message(int include_optional) {
  prepared_inline_message_t* prepared_inline_message = NULL;
  if (include_optional) {
    prepared_inline_message = prepared_inline_message_create(
      "0",
      56
    );
  } else {
    prepared_inline_message = prepared_inline_message_create(
      "0",
      56
    );
  }

  return prepared_inline_message;
}


#ifdef prepared_inline_message_MAIN

void test_prepared_inline_message(int include_optional) {
    prepared_inline_message_t* prepared_inline_message_1 = instantiate_prepared_inline_message(include_optional);

	cJSON* jsonprepared_inline_message_1 = prepared_inline_message_convertToJSON(prepared_inline_message_1);
	printf("prepared_inline_message :\n%s\n", cJSON_Print(jsonprepared_inline_message_1));
	prepared_inline_message_t* prepared_inline_message_2 = prepared_inline_message_parseFromJSON(jsonprepared_inline_message_1);
	cJSON* jsonprepared_inline_message_2 = prepared_inline_message_convertToJSON(prepared_inline_message_2);
	printf("repeating prepared_inline_message:\n%s\n", cJSON_Print(jsonprepared_inline_message_2));
}

int main() {
  test_prepared_inline_message(1);
  test_prepared_inline_message(0);

  printf("Hello world \n");
  return 0;
}

#endif // prepared_inline_message_MAIN
#endif // prepared_inline_message_TEST
