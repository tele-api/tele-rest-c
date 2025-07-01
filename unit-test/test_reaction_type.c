#ifndef reaction_type_TEST
#define reaction_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define reaction_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/reaction_type.h"
reaction_type_t* instantiate_reaction_type(int include_optional);



reaction_type_t* instantiate_reaction_type(int include_optional) {
  reaction_type_t* reaction_type = NULL;
  if (include_optional) {
    reaction_type = reaction_type_create(
      "paid",
      telegram_bot_api_reaction_type_EMOJI_❤,
      "0"
    );
  } else {
    reaction_type = reaction_type_create(
      "paid",
      telegram_bot_api_reaction_type_EMOJI_❤,
      "0"
    );
  }

  return reaction_type;
}


#ifdef reaction_type_MAIN

void test_reaction_type(int include_optional) {
    reaction_type_t* reaction_type_1 = instantiate_reaction_type(include_optional);

	cJSON* jsonreaction_type_1 = reaction_type_convertToJSON(reaction_type_1);
	printf("reaction_type :\n%s\n", cJSON_Print(jsonreaction_type_1));
	reaction_type_t* reaction_type_2 = reaction_type_parseFromJSON(jsonreaction_type_1);
	cJSON* jsonreaction_type_2 = reaction_type_convertToJSON(reaction_type_2);
	printf("repeating reaction_type:\n%s\n", cJSON_Print(jsonreaction_type_2));
}

int main() {
  test_reaction_type(1);
  test_reaction_type(0);

  printf("Hello world \n");
  return 0;
}

#endif // reaction_type_MAIN
#endif // reaction_type_TEST
