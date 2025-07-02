#ifndef get_game_high_scores_request_TEST
#define get_game_high_scores_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define get_game_high_scores_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/get_game_high_scores_request.h"
get_game_high_scores_request_t* instantiate_get_game_high_scores_request(int include_optional);



get_game_high_scores_request_t* instantiate_get_game_high_scores_request(int include_optional) {
  get_game_high_scores_request_t* get_game_high_scores_request = NULL;
  if (include_optional) {
    get_game_high_scores_request = get_game_high_scores_request_create(
      56,
      56,
      56,
      "0"
    );
  } else {
    get_game_high_scores_request = get_game_high_scores_request_create(
      56,
      56,
      56,
      "0"
    );
  }

  return get_game_high_scores_request;
}


#ifdef get_game_high_scores_request_MAIN

void test_get_game_high_scores_request(int include_optional) {
    get_game_high_scores_request_t* get_game_high_scores_request_1 = instantiate_get_game_high_scores_request(include_optional);

	cJSON* jsonget_game_high_scores_request_1 = get_game_high_scores_request_convertToJSON(get_game_high_scores_request_1);
	printf("get_game_high_scores_request :\n%s\n", cJSON_Print(jsonget_game_high_scores_request_1));
	get_game_high_scores_request_t* get_game_high_scores_request_2 = get_game_high_scores_request_parseFromJSON(jsonget_game_high_scores_request_1);
	cJSON* jsonget_game_high_scores_request_2 = get_game_high_scores_request_convertToJSON(get_game_high_scores_request_2);
	printf("repeating get_game_high_scores_request:\n%s\n", cJSON_Print(jsonget_game_high_scores_request_2));
}

int main() {
  test_get_game_high_scores_request(1);
  test_get_game_high_scores_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // get_game_high_scores_request_MAIN
#endif // get_game_high_scores_request_TEST
