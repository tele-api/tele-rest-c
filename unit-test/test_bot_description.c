#ifndef bot_description_TEST
#define bot_description_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define bot_description_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/bot_description.h"
bot_description_t* instantiate_bot_description(int include_optional);



bot_description_t* instantiate_bot_description(int include_optional) {
  bot_description_t* bot_description = NULL;
  if (include_optional) {
    bot_description = bot_description_create(
      "0"
    );
  } else {
    bot_description = bot_description_create(
      "0"
    );
  }

  return bot_description;
}


#ifdef bot_description_MAIN

void test_bot_description(int include_optional) {
    bot_description_t* bot_description_1 = instantiate_bot_description(include_optional);

	cJSON* jsonbot_description_1 = bot_description_convertToJSON(bot_description_1);
	printf("bot_description :\n%s\n", cJSON_Print(jsonbot_description_1));
	bot_description_t* bot_description_2 = bot_description_parseFromJSON(jsonbot_description_1);
	cJSON* jsonbot_description_2 = bot_description_convertToJSON(bot_description_2);
	printf("repeating bot_description:\n%s\n", cJSON_Print(jsonbot_description_2));
}

int main() {
  test_bot_description(1);
  test_bot_description(0);

  printf("Hello world \n");
  return 0;
}

#endif // bot_description_MAIN
#endif // bot_description_TEST
