#ifndef bot_command_scope_default_TEST
#define bot_command_scope_default_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define bot_command_scope_default_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/bot_command_scope_default.h"
bot_command_scope_default_t* instantiate_bot_command_scope_default(int include_optional);



bot_command_scope_default_t* instantiate_bot_command_scope_default(int include_optional) {
  bot_command_scope_default_t* bot_command_scope_default = NULL;
  if (include_optional) {
    bot_command_scope_default = bot_command_scope_default_create(
      "default"
    );
  } else {
    bot_command_scope_default = bot_command_scope_default_create(
      "default"
    );
  }

  return bot_command_scope_default;
}


#ifdef bot_command_scope_default_MAIN

void test_bot_command_scope_default(int include_optional) {
    bot_command_scope_default_t* bot_command_scope_default_1 = instantiate_bot_command_scope_default(include_optional);

	cJSON* jsonbot_command_scope_default_1 = bot_command_scope_default_convertToJSON(bot_command_scope_default_1);
	printf("bot_command_scope_default :\n%s\n", cJSON_Print(jsonbot_command_scope_default_1));
	bot_command_scope_default_t* bot_command_scope_default_2 = bot_command_scope_default_parseFromJSON(jsonbot_command_scope_default_1);
	cJSON* jsonbot_command_scope_default_2 = bot_command_scope_default_convertToJSON(bot_command_scope_default_2);
	printf("repeating bot_command_scope_default:\n%s\n", cJSON_Print(jsonbot_command_scope_default_2));
}

int main() {
  test_bot_command_scope_default(1);
  test_bot_command_scope_default(0);

  printf("Hello world \n");
  return 0;
}

#endif // bot_command_scope_default_MAIN
#endif // bot_command_scope_default_TEST
