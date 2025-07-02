#ifndef bot_command_scope_TEST
#define bot_command_scope_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define bot_command_scope_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/bot_command_scope.h"
bot_command_scope_t* instantiate_bot_command_scope(int include_optional);

#include "test_post_restrict_chat_member_request_chat_id.c"


bot_command_scope_t* instantiate_bot_command_scope(int include_optional) {
  bot_command_scope_t* bot_command_scope = NULL;
  if (include_optional) {
    bot_command_scope = bot_command_scope_create(
      "chat_member",
      null,
      56
    );
  } else {
    bot_command_scope = bot_command_scope_create(
      "chat_member",
      null,
      56
    );
  }

  return bot_command_scope;
}


#ifdef bot_command_scope_MAIN

void test_bot_command_scope(int include_optional) {
    bot_command_scope_t* bot_command_scope_1 = instantiate_bot_command_scope(include_optional);

	cJSON* jsonbot_command_scope_1 = bot_command_scope_convertToJSON(bot_command_scope_1);
	printf("bot_command_scope :\n%s\n", cJSON_Print(jsonbot_command_scope_1));
	bot_command_scope_t* bot_command_scope_2 = bot_command_scope_parseFromJSON(jsonbot_command_scope_1);
	cJSON* jsonbot_command_scope_2 = bot_command_scope_convertToJSON(bot_command_scope_2);
	printf("repeating bot_command_scope:\n%s\n", cJSON_Print(jsonbot_command_scope_2));
}

int main() {
  test_bot_command_scope(1);
  test_bot_command_scope(0);

  printf("Hello world \n");
  return 0;
}

#endif // bot_command_scope_MAIN
#endif // bot_command_scope_TEST
