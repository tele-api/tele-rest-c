#ifndef game_TEST
#define game_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define game_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/game.h"
game_t* instantiate_game(int include_optional);

#include "test_animation.c"


game_t* instantiate_game(int include_optional) {
  game_t* game = NULL;
  if (include_optional) {
    game = game_create(
      "0",
      "0",
      list_createList(),
      "0",
      list_createList(),
       // false, not to have infinite recursion
      instantiate_animation(0)
    );
  } else {
    game = game_create(
      "0",
      "0",
      list_createList(),
      "0",
      list_createList(),
      NULL
    );
  }

  return game;
}


#ifdef game_MAIN

void test_game(int include_optional) {
    game_t* game_1 = instantiate_game(include_optional);

	cJSON* jsongame_1 = game_convertToJSON(game_1);
	printf("game :\n%s\n", cJSON_Print(jsongame_1));
	game_t* game_2 = game_parseFromJSON(jsongame_1);
	cJSON* jsongame_2 = game_convertToJSON(game_2);
	printf("repeating game:\n%s\n", cJSON_Print(jsongame_2));
}

int main() {
  test_game(1);
  test_game(0);

  printf("Hello world \n");
  return 0;
}

#endif // game_MAIN
#endif // game_TEST
