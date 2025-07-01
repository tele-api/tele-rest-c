#ifndef inline_query_result_mpeg4_gif_TEST
#define inline_query_result_mpeg4_gif_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define inline_query_result_mpeg4_gif_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/inline_query_result_mpeg4_gif.h"
inline_query_result_mpeg4_gif_t* instantiate_inline_query_result_mpeg4_gif(int include_optional);

#include "test_inline_keyboard_markup.c"
#include "test_input_message_content.c"


inline_query_result_mpeg4_gif_t* instantiate_inline_query_result_mpeg4_gif(int include_optional) {
  inline_query_result_mpeg4_gif_t* inline_query_result_mpeg4_gif = NULL;
  if (include_optional) {
    inline_query_result_mpeg4_gif = inline_query_result_mpeg4_gif_create(
      "mpeg4_gif",
      "0",
      "0",
      "0",
      56,
      56,
      56,
      telegram_bot_api_inline_query_result_mpeg4_gif_THUMBNAILMIMETYPE_"image/jpeg",
      "0",
      "0",
      "0",
      list_createList(),
      1,
       // false, not to have infinite recursion
      instantiate_inline_keyboard_markup(0),
      null
    );
  } else {
    inline_query_result_mpeg4_gif = inline_query_result_mpeg4_gif_create(
      "mpeg4_gif",
      "0",
      "0",
      "0",
      56,
      56,
      56,
      telegram_bot_api_inline_query_result_mpeg4_gif_THUMBNAILMIMETYPE_"image/jpeg",
      "0",
      "0",
      "0",
      list_createList(),
      1,
      NULL,
      null
    );
  }

  return inline_query_result_mpeg4_gif;
}


#ifdef inline_query_result_mpeg4_gif_MAIN

void test_inline_query_result_mpeg4_gif(int include_optional) {
    inline_query_result_mpeg4_gif_t* inline_query_result_mpeg4_gif_1 = instantiate_inline_query_result_mpeg4_gif(include_optional);

	cJSON* jsoninline_query_result_mpeg4_gif_1 = inline_query_result_mpeg4_gif_convertToJSON(inline_query_result_mpeg4_gif_1);
	printf("inline_query_result_mpeg4_gif :\n%s\n", cJSON_Print(jsoninline_query_result_mpeg4_gif_1));
	inline_query_result_mpeg4_gif_t* inline_query_result_mpeg4_gif_2 = inline_query_result_mpeg4_gif_parseFromJSON(jsoninline_query_result_mpeg4_gif_1);
	cJSON* jsoninline_query_result_mpeg4_gif_2 = inline_query_result_mpeg4_gif_convertToJSON(inline_query_result_mpeg4_gif_2);
	printf("repeating inline_query_result_mpeg4_gif:\n%s\n", cJSON_Print(jsoninline_query_result_mpeg4_gif_2));
}

int main() {
  test_inline_query_result_mpeg4_gif(1);
  test_inline_query_result_mpeg4_gif(0);

  printf("Hello world \n");
  return 0;
}

#endif // inline_query_result_mpeg4_gif_MAIN
#endif // inline_query_result_mpeg4_gif_TEST
