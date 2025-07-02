#ifndef set_game_score_request_TEST
#define set_game_score_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define set_game_score_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/set_game_score_request.h"
set_game_score_request_t* instantiate_set_game_score_request(int include_optional);



set_game_score_request_t* instantiate_set_game_score_request(int include_optional) {
  set_game_score_request_t* set_game_score_request = NULL;
  if (include_optional) {
    set_game_score_request = set_game_score_request_create(
      56,
      56,
      1,
      1,
      56,
      56,
      "0"
    );
  } else {
    set_game_score_request = set_game_score_request_create(
      56,
      56,
      1,
      1,
      56,
      56,
      "0"
    );
  }

  return set_game_score_request;
}


#ifdef set_game_score_request_MAIN

void test_set_game_score_request(int include_optional) {
    set_game_score_request_t* set_game_score_request_1 = instantiate_set_game_score_request(include_optional);

	cJSON* jsonset_game_score_request_1 = set_game_score_request_convertToJSON(set_game_score_request_1);
	printf("set_game_score_request :\n%s\n", cJSON_Print(jsonset_game_score_request_1));
	set_game_score_request_t* set_game_score_request_2 = set_game_score_request_parseFromJSON(jsonset_game_score_request_1);
	cJSON* jsonset_game_score_request_2 = set_game_score_request_convertToJSON(set_game_score_request_2);
	printf("repeating set_game_score_request:\n%s\n", cJSON_Print(jsonset_game_score_request_2));
}

int main() {
  test_set_game_score_request(1);
  test_set_game_score_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // set_game_score_request_MAIN
#endif // set_game_score_request_TEST
