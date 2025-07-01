#ifndef inline_query_result_cached_sticker_TEST
#define inline_query_result_cached_sticker_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define inline_query_result_cached_sticker_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/inline_query_result_cached_sticker.h"
inline_query_result_cached_sticker_t* instantiate_inline_query_result_cached_sticker(int include_optional);

#include "test_inline_keyboard_markup.c"
#include "test_input_message_content.c"


inline_query_result_cached_sticker_t* instantiate_inline_query_result_cached_sticker(int include_optional) {
  inline_query_result_cached_sticker_t* inline_query_result_cached_sticker = NULL;
  if (include_optional) {
    inline_query_result_cached_sticker = inline_query_result_cached_sticker_create(
      "sticker",
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_inline_keyboard_markup(0),
      null
    );
  } else {
    inline_query_result_cached_sticker = inline_query_result_cached_sticker_create(
      "sticker",
      "0",
      "0",
      NULL,
      null
    );
  }

  return inline_query_result_cached_sticker;
}


#ifdef inline_query_result_cached_sticker_MAIN

void test_inline_query_result_cached_sticker(int include_optional) {
    inline_query_result_cached_sticker_t* inline_query_result_cached_sticker_1 = instantiate_inline_query_result_cached_sticker(include_optional);

	cJSON* jsoninline_query_result_cached_sticker_1 = inline_query_result_cached_sticker_convertToJSON(inline_query_result_cached_sticker_1);
	printf("inline_query_result_cached_sticker :\n%s\n", cJSON_Print(jsoninline_query_result_cached_sticker_1));
	inline_query_result_cached_sticker_t* inline_query_result_cached_sticker_2 = inline_query_result_cached_sticker_parseFromJSON(jsoninline_query_result_cached_sticker_1);
	cJSON* jsoninline_query_result_cached_sticker_2 = inline_query_result_cached_sticker_convertToJSON(inline_query_result_cached_sticker_2);
	printf("repeating inline_query_result_cached_sticker:\n%s\n", cJSON_Print(jsoninline_query_result_cached_sticker_2));
}

int main() {
  test_inline_query_result_cached_sticker(1);
  test_inline_query_result_cached_sticker(0);

  printf("Hello world \n");
  return 0;
}

#endif // inline_query_result_cached_sticker_MAIN
#endif // inline_query_result_cached_sticker_TEST
