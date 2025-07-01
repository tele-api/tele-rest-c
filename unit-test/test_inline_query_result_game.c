#ifndef inline_query_result_game_TEST
#define inline_query_result_game_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define inline_query_result_game_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/inline_query_result_game.h"
inline_query_result_game_t* instantiate_inline_query_result_game(int include_optional);

#include "test_inline_keyboard_markup.c"


inline_query_result_game_t* instantiate_inline_query_result_game(int include_optional) {
  inline_query_result_game_t* inline_query_result_game = NULL;
  if (include_optional) {
    inline_query_result_game = inline_query_result_game_create(
      "game",
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_inline_keyboard_markup(0)
    );
  } else {
    inline_query_result_game = inline_query_result_game_create(
      "game",
      "0",
      "0",
      NULL
    );
  }

  return inline_query_result_game;
}


#ifdef inline_query_result_game_MAIN

void test_inline_query_result_game(int include_optional) {
    inline_query_result_game_t* inline_query_result_game_1 = instantiate_inline_query_result_game(include_optional);

	cJSON* jsoninline_query_result_game_1 = inline_query_result_game_convertToJSON(inline_query_result_game_1);
	printf("inline_query_result_game :\n%s\n", cJSON_Print(jsoninline_query_result_game_1));
	inline_query_result_game_t* inline_query_result_game_2 = inline_query_result_game_parseFromJSON(jsoninline_query_result_game_1);
	cJSON* jsoninline_query_result_game_2 = inline_query_result_game_convertToJSON(inline_query_result_game_2);
	printf("repeating inline_query_result_game:\n%s\n", cJSON_Print(jsoninline_query_result_game_2));
}

int main() {
  test_inline_query_result_game(1);
  test_inline_query_result_game(0);

  printf("Hello world \n");
  return 0;
}

#endif // inline_query_result_game_MAIN
#endif // inline_query_result_game_TEST
