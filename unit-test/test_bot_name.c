#ifndef bot_name_TEST
#define bot_name_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define bot_name_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/bot_name.h"
bot_name_t* instantiate_bot_name(int include_optional);



bot_name_t* instantiate_bot_name(int include_optional) {
  bot_name_t* bot_name = NULL;
  if (include_optional) {
    bot_name = bot_name_create(
      "0"
    );
  } else {
    bot_name = bot_name_create(
      "0"
    );
  }

  return bot_name;
}


#ifdef bot_name_MAIN

void test_bot_name(int include_optional) {
    bot_name_t* bot_name_1 = instantiate_bot_name(include_optional);

	cJSON* jsonbot_name_1 = bot_name_convertToJSON(bot_name_1);
	printf("bot_name :\n%s\n", cJSON_Print(jsonbot_name_1));
	bot_name_t* bot_name_2 = bot_name_parseFromJSON(jsonbot_name_1);
	cJSON* jsonbot_name_2 = bot_name_convertToJSON(bot_name_2);
	printf("repeating bot_name:\n%s\n", cJSON_Print(jsonbot_name_2));
}

int main() {
  test_bot_name(1);
  test_bot_name(0);

  printf("Hello world \n");
  return 0;
}

#endif // bot_name_MAIN
#endif // bot_name_TEST
