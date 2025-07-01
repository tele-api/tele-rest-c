#ifndef inline_query_result_cached_audio_TEST
#define inline_query_result_cached_audio_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define inline_query_result_cached_audio_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/inline_query_result_cached_audio.h"
inline_query_result_cached_audio_t* instantiate_inline_query_result_cached_audio(int include_optional);

#include "test_inline_keyboard_markup.c"
#include "test_input_message_content.c"


inline_query_result_cached_audio_t* instantiate_inline_query_result_cached_audio(int include_optional) {
  inline_query_result_cached_audio_t* inline_query_result_cached_audio = NULL;
  if (include_optional) {
    inline_query_result_cached_audio = inline_query_result_cached_audio_create(
      "audio",
      "0",
      "0",
      "0",
      "0",
      list_createList(),
       // false, not to have infinite recursion
      instantiate_inline_keyboard_markup(0),
      null
    );
  } else {
    inline_query_result_cached_audio = inline_query_result_cached_audio_create(
      "audio",
      "0",
      "0",
      "0",
      "0",
      list_createList(),
      NULL,
      null
    );
  }

  return inline_query_result_cached_audio;
}


#ifdef inline_query_result_cached_audio_MAIN

void test_inline_query_result_cached_audio(int include_optional) {
    inline_query_result_cached_audio_t* inline_query_result_cached_audio_1 = instantiate_inline_query_result_cached_audio(include_optional);

	cJSON* jsoninline_query_result_cached_audio_1 = inline_query_result_cached_audio_convertToJSON(inline_query_result_cached_audio_1);
	printf("inline_query_result_cached_audio :\n%s\n", cJSON_Print(jsoninline_query_result_cached_audio_1));
	inline_query_result_cached_audio_t* inline_query_result_cached_audio_2 = inline_query_result_cached_audio_parseFromJSON(jsoninline_query_result_cached_audio_1);
	cJSON* jsoninline_query_result_cached_audio_2 = inline_query_result_cached_audio_convertToJSON(inline_query_result_cached_audio_2);
	printf("repeating inline_query_result_cached_audio:\n%s\n", cJSON_Print(jsoninline_query_result_cached_audio_2));
}

int main() {
  test_inline_query_result_cached_audio(1);
  test_inline_query_result_cached_audio(0);

  printf("Hello world \n");
  return 0;
}

#endif // inline_query_result_cached_audio_MAIN
#endif // inline_query_result_cached_audio_TEST
