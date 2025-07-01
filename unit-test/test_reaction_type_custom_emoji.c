#ifndef reaction_type_custom_emoji_TEST
#define reaction_type_custom_emoji_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define reaction_type_custom_emoji_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/reaction_type_custom_emoji.h"
reaction_type_custom_emoji_t* instantiate_reaction_type_custom_emoji(int include_optional);



reaction_type_custom_emoji_t* instantiate_reaction_type_custom_emoji(int include_optional) {
  reaction_type_custom_emoji_t* reaction_type_custom_emoji = NULL;
  if (include_optional) {
    reaction_type_custom_emoji = reaction_type_custom_emoji_create(
      "custom_emoji",
      "0"
    );
  } else {
    reaction_type_custom_emoji = reaction_type_custom_emoji_create(
      "custom_emoji",
      "0"
    );
  }

  return reaction_type_custom_emoji;
}


#ifdef reaction_type_custom_emoji_MAIN

void test_reaction_type_custom_emoji(int include_optional) {
    reaction_type_custom_emoji_t* reaction_type_custom_emoji_1 = instantiate_reaction_type_custom_emoji(include_optional);

	cJSON* jsonreaction_type_custom_emoji_1 = reaction_type_custom_emoji_convertToJSON(reaction_type_custom_emoji_1);
	printf("reaction_type_custom_emoji :\n%s\n", cJSON_Print(jsonreaction_type_custom_emoji_1));
	reaction_type_custom_emoji_t* reaction_type_custom_emoji_2 = reaction_type_custom_emoji_parseFromJSON(jsonreaction_type_custom_emoji_1);
	cJSON* jsonreaction_type_custom_emoji_2 = reaction_type_custom_emoji_convertToJSON(reaction_type_custom_emoji_2);
	printf("repeating reaction_type_custom_emoji:\n%s\n", cJSON_Print(jsonreaction_type_custom_emoji_2));
}

int main() {
  test_reaction_type_custom_emoji(1);
  test_reaction_type_custom_emoji(0);

  printf("Hello world \n");
  return 0;
}

#endif // reaction_type_custom_emoji_MAIN
#endif // reaction_type_custom_emoji_TEST
