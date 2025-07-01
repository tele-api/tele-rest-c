#ifndef inline_query_result_location_TEST
#define inline_query_result_location_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define inline_query_result_location_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/inline_query_result_location.h"
inline_query_result_location_t* instantiate_inline_query_result_location(int include_optional);

#include "test_inline_keyboard_markup.c"
#include "test_input_message_content.c"


inline_query_result_location_t* instantiate_inline_query_result_location(int include_optional) {
  inline_query_result_location_t* inline_query_result_location = NULL;
  if (include_optional) {
    inline_query_result_location = inline_query_result_location_create(
      "location",
      "0",
      1.337,
      1.337,
      "0",
      1.337,
      56,
      56,
      56,
       // false, not to have infinite recursion
      instantiate_inline_keyboard_markup(0),
      null,
      "0",
      56,
      56
    );
  } else {
    inline_query_result_location = inline_query_result_location_create(
      "location",
      "0",
      1.337,
      1.337,
      "0",
      1.337,
      56,
      56,
      56,
      NULL,
      null,
      "0",
      56,
      56
    );
  }

  return inline_query_result_location;
}


#ifdef inline_query_result_location_MAIN

void test_inline_query_result_location(int include_optional) {
    inline_query_result_location_t* inline_query_result_location_1 = instantiate_inline_query_result_location(include_optional);

	cJSON* jsoninline_query_result_location_1 = inline_query_result_location_convertToJSON(inline_query_result_location_1);
	printf("inline_query_result_location :\n%s\n", cJSON_Print(jsoninline_query_result_location_1));
	inline_query_result_location_t* inline_query_result_location_2 = inline_query_result_location_parseFromJSON(jsoninline_query_result_location_1);
	cJSON* jsoninline_query_result_location_2 = inline_query_result_location_convertToJSON(inline_query_result_location_2);
	printf("repeating inline_query_result_location:\n%s\n", cJSON_Print(jsoninline_query_result_location_2));
}

int main() {
  test_inline_query_result_location(1);
  test_inline_query_result_location(0);

  printf("Hello world \n");
  return 0;
}

#endif // inline_query_result_location_MAIN
#endif // inline_query_result_location_TEST
