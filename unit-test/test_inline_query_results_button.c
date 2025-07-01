#ifndef inline_query_results_button_TEST
#define inline_query_results_button_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define inline_query_results_button_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/inline_query_results_button.h"
inline_query_results_button_t* instantiate_inline_query_results_button(int include_optional);

#include "test_web_app_info.c"


inline_query_results_button_t* instantiate_inline_query_results_button(int include_optional) {
  inline_query_results_button_t* inline_query_results_button = NULL;
  if (include_optional) {
    inline_query_results_button = inline_query_results_button_create(
      "0",
       // false, not to have infinite recursion
      instantiate_web_app_info(0),
      "0"
    );
  } else {
    inline_query_results_button = inline_query_results_button_create(
      "0",
      NULL,
      "0"
    );
  }

  return inline_query_results_button;
}


#ifdef inline_query_results_button_MAIN

void test_inline_query_results_button(int include_optional) {
    inline_query_results_button_t* inline_query_results_button_1 = instantiate_inline_query_results_button(include_optional);

	cJSON* jsoninline_query_results_button_1 = inline_query_results_button_convertToJSON(inline_query_results_button_1);
	printf("inline_query_results_button :\n%s\n", cJSON_Print(jsoninline_query_results_button_1));
	inline_query_results_button_t* inline_query_results_button_2 = inline_query_results_button_parseFromJSON(jsoninline_query_results_button_1);
	cJSON* jsoninline_query_results_button_2 = inline_query_results_button_convertToJSON(inline_query_results_button_2);
	printf("repeating inline_query_results_button:\n%s\n", cJSON_Print(jsoninline_query_results_button_2));
}

int main() {
  test_inline_query_results_button(1);
  test_inline_query_results_button(0);

  printf("Hello world \n");
  return 0;
}

#endif // inline_query_results_button_MAIN
#endif // inline_query_results_button_TEST
