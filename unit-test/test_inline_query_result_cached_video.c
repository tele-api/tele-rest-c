#ifndef inline_query_result_cached_video_TEST
#define inline_query_result_cached_video_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define inline_query_result_cached_video_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/inline_query_result_cached_video.h"
inline_query_result_cached_video_t* instantiate_inline_query_result_cached_video(int include_optional);

#include "test_inline_keyboard_markup.c"
#include "test_input_message_content.c"


inline_query_result_cached_video_t* instantiate_inline_query_result_cached_video(int include_optional) {
  inline_query_result_cached_video_t* inline_query_result_cached_video = NULL;
  if (include_optional) {
    inline_query_result_cached_video = inline_query_result_cached_video_create(
      "video",
      "0",
      "0",
      "0",
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
    inline_query_result_cached_video = inline_query_result_cached_video_create(
      "video",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      list_createList(),
      1,
      NULL,
      null
    );
  }

  return inline_query_result_cached_video;
}


#ifdef inline_query_result_cached_video_MAIN

void test_inline_query_result_cached_video(int include_optional) {
    inline_query_result_cached_video_t* inline_query_result_cached_video_1 = instantiate_inline_query_result_cached_video(include_optional);

	cJSON* jsoninline_query_result_cached_video_1 = inline_query_result_cached_video_convertToJSON(inline_query_result_cached_video_1);
	printf("inline_query_result_cached_video :\n%s\n", cJSON_Print(jsoninline_query_result_cached_video_1));
	inline_query_result_cached_video_t* inline_query_result_cached_video_2 = inline_query_result_cached_video_parseFromJSON(jsoninline_query_result_cached_video_1);
	cJSON* jsoninline_query_result_cached_video_2 = inline_query_result_cached_video_convertToJSON(inline_query_result_cached_video_2);
	printf("repeating inline_query_result_cached_video:\n%s\n", cJSON_Print(jsoninline_query_result_cached_video_2));
}

int main() {
  test_inline_query_result_cached_video(1);
  test_inline_query_result_cached_video(0);

  printf("Hello world \n");
  return 0;
}

#endif // inline_query_result_cached_video_MAIN
#endif // inline_query_result_cached_video_TEST
