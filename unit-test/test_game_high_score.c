#ifndef game_high_score_TEST
#define game_high_score_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define game_high_score_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/game_high_score.h"
game_high_score_t* instantiate_game_high_score(int include_optional);

#include "test_user.c"


game_high_score_t* instantiate_game_high_score(int include_optional) {
  game_high_score_t* game_high_score = NULL;
  if (include_optional) {
    game_high_score = game_high_score_create(
      56,
       // false, not to have infinite recursion
      instantiate_user(0),
      56
    );
  } else {
    game_high_score = game_high_score_create(
      56,
      NULL,
      56
    );
  }

  return game_high_score;
}


#ifdef game_high_score_MAIN

void test_game_high_score(int include_optional) {
    game_high_score_t* game_high_score_1 = instantiate_game_high_score(include_optional);

	cJSON* jsongame_high_score_1 = game_high_score_convertToJSON(game_high_score_1);
	printf("game_high_score :\n%s\n", cJSON_Print(jsongame_high_score_1));
	game_high_score_t* game_high_score_2 = game_high_score_parseFromJSON(jsongame_high_score_1);
	cJSON* jsongame_high_score_2 = game_high_score_convertToJSON(game_high_score_2);
	printf("repeating game_high_score:\n%s\n", cJSON_Print(jsongame_high_score_2));
}

int main() {
  test_game_high_score(1);
  test_game_high_score(0);

  printf("Hello world \n");
  return 0;
}

#endif // game_high_score_MAIN
#endif // game_high_score_TEST
