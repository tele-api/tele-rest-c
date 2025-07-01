#ifndef callback_query_TEST
#define callback_query_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define callback_query_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/callback_query.h"
callback_query_t* instantiate_callback_query(int include_optional);

#include "test_user.c"
#include "test_maybe_inaccessible_message.c"


callback_query_t* instantiate_callback_query(int include_optional) {
  callback_query_t* callback_query = NULL;
  if (include_optional) {
    callback_query = callback_query_create(
      "0",
       // false, not to have infinite recursion
      instantiate_user(0),
      "0",
      null,
      "0",
      "0",
      "0"
    );
  } else {
    callback_query = callback_query_create(
      "0",
      NULL,
      "0",
      null,
      "0",
      "0",
      "0"
    );
  }

  return callback_query;
}


#ifdef callback_query_MAIN

void test_callback_query(int include_optional) {
    callback_query_t* callback_query_1 = instantiate_callback_query(include_optional);

	cJSON* jsoncallback_query_1 = callback_query_convertToJSON(callback_query_1);
	printf("callback_query :\n%s\n", cJSON_Print(jsoncallback_query_1));
	callback_query_t* callback_query_2 = callback_query_parseFromJSON(jsoncallback_query_1);
	cJSON* jsoncallback_query_2 = callback_query_convertToJSON(callback_query_2);
	printf("repeating callback_query:\n%s\n", cJSON_Print(jsoncallback_query_2));
}

int main() {
  test_callback_query(1);
  test_callback_query(0);

  printf("Hello world \n");
  return 0;
}

#endif // callback_query_MAIN
#endif // callback_query_TEST
