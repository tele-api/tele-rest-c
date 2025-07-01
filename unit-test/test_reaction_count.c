#ifndef reaction_count_TEST
#define reaction_count_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define reaction_count_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/reaction_count.h"
reaction_count_t* instantiate_reaction_count(int include_optional);

#include "test_reaction_type.c"


reaction_count_t* instantiate_reaction_count(int include_optional) {
  reaction_count_t* reaction_count = NULL;
  if (include_optional) {
    reaction_count = reaction_count_create(
      null,
      56
    );
  } else {
    reaction_count = reaction_count_create(
      null,
      56
    );
  }

  return reaction_count;
}


#ifdef reaction_count_MAIN

void test_reaction_count(int include_optional) {
    reaction_count_t* reaction_count_1 = instantiate_reaction_count(include_optional);

	cJSON* jsonreaction_count_1 = reaction_count_convertToJSON(reaction_count_1);
	printf("reaction_count :\n%s\n", cJSON_Print(jsonreaction_count_1));
	reaction_count_t* reaction_count_2 = reaction_count_parseFromJSON(jsonreaction_count_1);
	cJSON* jsonreaction_count_2 = reaction_count_convertToJSON(reaction_count_2);
	printf("repeating reaction_count:\n%s\n", cJSON_Print(jsonreaction_count_2));
}

int main() {
  test_reaction_count(1);
  test_reaction_count(0);

  printf("Hello world \n");
  return 0;
}

#endif // reaction_count_MAIN
#endif // reaction_count_TEST
