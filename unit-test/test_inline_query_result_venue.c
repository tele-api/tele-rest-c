#ifndef inline_query_result_venue_TEST
#define inline_query_result_venue_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define inline_query_result_venue_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/inline_query_result_venue.h"
inline_query_result_venue_t* instantiate_inline_query_result_venue(int include_optional);

#include "test_inline_keyboard_markup.c"
#include "test_input_message_content.c"


inline_query_result_venue_t* instantiate_inline_query_result_venue(int include_optional) {
  inline_query_result_venue_t* inline_query_result_venue = NULL;
  if (include_optional) {
    inline_query_result_venue = inline_query_result_venue_create(
      "venue",
      "0",
      1.337,
      1.337,
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_inline_keyboard_markup(0),
      null,
      "0",
      56,
      56
    );
  } else {
    inline_query_result_venue = inline_query_result_venue_create(
      "venue",
      "0",
      1.337,
      1.337,
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      NULL,
      null,
      "0",
      56,
      56
    );
  }

  return inline_query_result_venue;
}


#ifdef inline_query_result_venue_MAIN

void test_inline_query_result_venue(int include_optional) {
    inline_query_result_venue_t* inline_query_result_venue_1 = instantiate_inline_query_result_venue(include_optional);

	cJSON* jsoninline_query_result_venue_1 = inline_query_result_venue_convertToJSON(inline_query_result_venue_1);
	printf("inline_query_result_venue :\n%s\n", cJSON_Print(jsoninline_query_result_venue_1));
	inline_query_result_venue_t* inline_query_result_venue_2 = inline_query_result_venue_parseFromJSON(jsoninline_query_result_venue_1);
	cJSON* jsoninline_query_result_venue_2 = inline_query_result_venue_convertToJSON(inline_query_result_venue_2);
	printf("repeating inline_query_result_venue:\n%s\n", cJSON_Print(jsoninline_query_result_venue_2));
}

int main() {
  test_inline_query_result_venue(1);
  test_inline_query_result_venue(0);

  printf("Hello world \n");
  return 0;
}

#endif // inline_query_result_venue_MAIN
#endif // inline_query_result_venue_TEST
