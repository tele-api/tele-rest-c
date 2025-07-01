#ifndef inline_query_TEST
#define inline_query_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define inline_query_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/inline_query.h"
inline_query_t* instantiate_inline_query(int include_optional);

#include "test_user.c"
#include "test_location.c"


inline_query_t* instantiate_inline_query(int include_optional) {
  inline_query_t* inline_query = NULL;
  if (include_optional) {
    inline_query = inline_query_create(
      "0",
       // false, not to have infinite recursion
      instantiate_user(0),
      "0",
      "0",
      telegram_bot_api_inline_query_CHATTYPE_sender,
       // false, not to have infinite recursion
      instantiate_location(0)
    );
  } else {
    inline_query = inline_query_create(
      "0",
      NULL,
      "0",
      "0",
      telegram_bot_api_inline_query_CHATTYPE_sender,
      NULL
    );
  }

  return inline_query;
}


#ifdef inline_query_MAIN

void test_inline_query(int include_optional) {
    inline_query_t* inline_query_1 = instantiate_inline_query(include_optional);

	cJSON* jsoninline_query_1 = inline_query_convertToJSON(inline_query_1);
	printf("inline_query :\n%s\n", cJSON_Print(jsoninline_query_1));
	inline_query_t* inline_query_2 = inline_query_parseFromJSON(jsoninline_query_1);
	cJSON* jsoninline_query_2 = inline_query_convertToJSON(inline_query_2);
	printf("repeating inline_query:\n%s\n", cJSON_Print(jsoninline_query_2));
}

int main() {
  test_inline_query(1);
  test_inline_query(0);

  printf("Hello world \n");
  return 0;
}

#endif // inline_query_MAIN
#endif // inline_query_TEST
