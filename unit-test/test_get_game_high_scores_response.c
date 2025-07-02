#ifndef get_game_high_scores_response_TEST
#define get_game_high_scores_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define get_game_high_scores_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/get_game_high_scores_response.h"
get_game_high_scores_response_t* instantiate_get_game_high_scores_response(int include_optional);



get_game_high_scores_response_t* instantiate_get_game_high_scores_response(int include_optional) {
  get_game_high_scores_response_t* get_game_high_scores_response = NULL;
  if (include_optional) {
    get_game_high_scores_response = get_game_high_scores_response_create(
      1,
      list_createList()
    );
  } else {
    get_game_high_scores_response = get_game_high_scores_response_create(
      1,
      list_createList()
    );
  }

  return get_game_high_scores_response;
}


#ifdef get_game_high_scores_response_MAIN

void test_get_game_high_scores_response(int include_optional) {
    get_game_high_scores_response_t* get_game_high_scores_response_1 = instantiate_get_game_high_scores_response(include_optional);

	cJSON* jsonget_game_high_scores_response_1 = get_game_high_scores_response_convertToJSON(get_game_high_scores_response_1);
	printf("get_game_high_scores_response :\n%s\n", cJSON_Print(jsonget_game_high_scores_response_1));
	get_game_high_scores_response_t* get_game_high_scores_response_2 = get_game_high_scores_response_parseFromJSON(jsonget_game_high_scores_response_1);
	cJSON* jsonget_game_high_scores_response_2 = get_game_high_scores_response_convertToJSON(get_game_high_scores_response_2);
	printf("repeating get_game_high_scores_response:\n%s\n", cJSON_Print(jsonget_game_high_scores_response_2));
}

int main() {
  test_get_game_high_scores_response(1);
  test_get_game_high_scores_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // get_game_high_scores_response_MAIN
#endif // get_game_high_scores_response_TEST
