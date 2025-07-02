#ifndef set_game_score_response_TEST
#define set_game_score_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define set_game_score_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/set_game_score_response.h"
set_game_score_response_t* instantiate_set_game_score_response(int include_optional);

#include "test_edit_message_text_response_result.c"


set_game_score_response_t* instantiate_set_game_score_response(int include_optional) {
  set_game_score_response_t* set_game_score_response = NULL;
  if (include_optional) {
    set_game_score_response = set_game_score_response_create(
      1,
      null
    );
  } else {
    set_game_score_response = set_game_score_response_create(
      1,
      null
    );
  }

  return set_game_score_response;
}


#ifdef set_game_score_response_MAIN

void test_set_game_score_response(int include_optional) {
    set_game_score_response_t* set_game_score_response_1 = instantiate_set_game_score_response(include_optional);

	cJSON* jsonset_game_score_response_1 = set_game_score_response_convertToJSON(set_game_score_response_1);
	printf("set_game_score_response :\n%s\n", cJSON_Print(jsonset_game_score_response_1));
	set_game_score_response_t* set_game_score_response_2 = set_game_score_response_parseFromJSON(jsonset_game_score_response_1);
	cJSON* jsonset_game_score_response_2 = set_game_score_response_convertToJSON(set_game_score_response_2);
	printf("repeating set_game_score_response:\n%s\n", cJSON_Print(jsonset_game_score_response_2));
}

int main() {
  test_set_game_score_response(1);
  test_set_game_score_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // set_game_score_response_MAIN
#endif // set_game_score_response_TEST
