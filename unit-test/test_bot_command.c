#ifndef bot_command_TEST
#define bot_command_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define bot_command_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/bot_command.h"
bot_command_t* instantiate_bot_command(int include_optional);



bot_command_t* instantiate_bot_command(int include_optional) {
  bot_command_t* bot_command = NULL;
  if (include_optional) {
    bot_command = bot_command_create(
      "0",
      "0"
    );
  } else {
    bot_command = bot_command_create(
      "0",
      "0"
    );
  }

  return bot_command;
}


#ifdef bot_command_MAIN

void test_bot_command(int include_optional) {
    bot_command_t* bot_command_1 = instantiate_bot_command(include_optional);

	cJSON* jsonbot_command_1 = bot_command_convertToJSON(bot_command_1);
	printf("bot_command :\n%s\n", cJSON_Print(jsonbot_command_1));
	bot_command_t* bot_command_2 = bot_command_parseFromJSON(jsonbot_command_1);
	cJSON* jsonbot_command_2 = bot_command_convertToJSON(bot_command_2);
	printf("repeating bot_command:\n%s\n", cJSON_Print(jsonbot_command_2));
}

int main() {
  test_bot_command(1);
  test_bot_command(0);

  printf("Hello world \n");
  return 0;
}

#endif // bot_command_MAIN
#endif // bot_command_TEST
