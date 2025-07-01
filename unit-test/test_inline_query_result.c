#ifndef inline_query_result_TEST
#define inline_query_result_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define inline_query_result_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/inline_query_result.h"
inline_query_result_t* instantiate_inline_query_result(int include_optional);

#include "test_input_message_content.c"
#include "test_inline_keyboard_markup.c"


inline_query_result_t* instantiate_inline_query_result(int include_optional) {
  inline_query_result_t* inline_query_result = NULL;
  if (include_optional) {
    inline_query_result = inline_query_result_create(
      "voice",
      "0",
      "0",
      null,
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      telegram_bot_api_inline_query_result_MIMETYPE_text/html,
      "0",
      1.337,
      1.337,
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      list_createList(),
       // false, not to have infinite recursion
      instantiate_inline_keyboard_markup(0),
      "0",
      1,
      "0",
      56,
      56,
      "0",
      56,
      "0",
      "0",
      56,
      56,
      56,
      telegram_bot_api_inline_query_result_THUMBNAILMIMETYPE_"image/jpeg",
      1.337,
      56,
      56,
      56,
      56,
      56,
      56,
      56,
      56,
      "0",
      "0",
      "0",
      "0",
      56,
      56,
      56,
      56
    );
  } else {
    inline_query_result = inline_query_result_create(
      "voice",
      "0",
      "0",
      null,
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      telegram_bot_api_inline_query_result_MIMETYPE_text/html,
      "0",
      1.337,
      1.337,
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      list_createList(),
      NULL,
      "0",
      1,
      "0",
      56,
      56,
      "0",
      56,
      "0",
      "0",
      56,
      56,
      56,
      telegram_bot_api_inline_query_result_THUMBNAILMIMETYPE_"image/jpeg",
      1.337,
      56,
      56,
      56,
      56,
      56,
      56,
      56,
      56,
      "0",
      "0",
      "0",
      "0",
      56,
      56,
      56,
      56
    );
  }

  return inline_query_result;
}


#ifdef inline_query_result_MAIN

void test_inline_query_result(int include_optional) {
    inline_query_result_t* inline_query_result_1 = instantiate_inline_query_result(include_optional);

	cJSON* jsoninline_query_result_1 = inline_query_result_convertToJSON(inline_query_result_1);
	printf("inline_query_result :\n%s\n", cJSON_Print(jsoninline_query_result_1));
	inline_query_result_t* inline_query_result_2 = inline_query_result_parseFromJSON(jsoninline_query_result_1);
	cJSON* jsoninline_query_result_2 = inline_query_result_convertToJSON(inline_query_result_2);
	printf("repeating inline_query_result:\n%s\n", cJSON_Print(jsoninline_query_result_2));
}

int main() {
  test_inline_query_result(1);
  test_inline_query_result(0);

  printf("Hello world \n");
  return 0;
}

#endif // inline_query_result_MAIN
#endif // inline_query_result_TEST
