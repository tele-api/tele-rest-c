#ifndef bot_short_description_TEST
#define bot_short_description_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define bot_short_description_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/bot_short_description.h"
bot_short_description_t* instantiate_bot_short_description(int include_optional);



bot_short_description_t* instantiate_bot_short_description(int include_optional) {
  bot_short_description_t* bot_short_description = NULL;
  if (include_optional) {
    bot_short_description = bot_short_description_create(
      "0"
    );
  } else {
    bot_short_description = bot_short_description_create(
      "0"
    );
  }

  return bot_short_description;
}


#ifdef bot_short_description_MAIN

void test_bot_short_description(int include_optional) {
    bot_short_description_t* bot_short_description_1 = instantiate_bot_short_description(include_optional);

	cJSON* jsonbot_short_description_1 = bot_short_description_convertToJSON(bot_short_description_1);
	printf("bot_short_description :\n%s\n", cJSON_Print(jsonbot_short_description_1));
	bot_short_description_t* bot_short_description_2 = bot_short_description_parseFromJSON(jsonbot_short_description_1);
	cJSON* jsonbot_short_description_2 = bot_short_description_convertToJSON(bot_short_description_2);
	printf("repeating bot_short_description:\n%s\n", cJSON_Print(jsonbot_short_description_2));
}

int main() {
  test_bot_short_description(1);
  test_bot_short_description(0);

  printf("Hello world \n");
  return 0;
}

#endif // bot_short_description_MAIN
#endif // bot_short_description_TEST
