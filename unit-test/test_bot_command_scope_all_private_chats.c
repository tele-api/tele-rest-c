#ifndef bot_command_scope_all_private_chats_TEST
#define bot_command_scope_all_private_chats_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define bot_command_scope_all_private_chats_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/bot_command_scope_all_private_chats.h"
bot_command_scope_all_private_chats_t* instantiate_bot_command_scope_all_private_chats(int include_optional);



bot_command_scope_all_private_chats_t* instantiate_bot_command_scope_all_private_chats(int include_optional) {
  bot_command_scope_all_private_chats_t* bot_command_scope_all_private_chats = NULL;
  if (include_optional) {
    bot_command_scope_all_private_chats = bot_command_scope_all_private_chats_create(
      "all_private_chats"
    );
  } else {
    bot_command_scope_all_private_chats = bot_command_scope_all_private_chats_create(
      "all_private_chats"
    );
  }

  return bot_command_scope_all_private_chats;
}


#ifdef bot_command_scope_all_private_chats_MAIN

void test_bot_command_scope_all_private_chats(int include_optional) {
    bot_command_scope_all_private_chats_t* bot_command_scope_all_private_chats_1 = instantiate_bot_command_scope_all_private_chats(include_optional);

	cJSON* jsonbot_command_scope_all_private_chats_1 = bot_command_scope_all_private_chats_convertToJSON(bot_command_scope_all_private_chats_1);
	printf("bot_command_scope_all_private_chats :\n%s\n", cJSON_Print(jsonbot_command_scope_all_private_chats_1));
	bot_command_scope_all_private_chats_t* bot_command_scope_all_private_chats_2 = bot_command_scope_all_private_chats_parseFromJSON(jsonbot_command_scope_all_private_chats_1);
	cJSON* jsonbot_command_scope_all_private_chats_2 = bot_command_scope_all_private_chats_convertToJSON(bot_command_scope_all_private_chats_2);
	printf("repeating bot_command_scope_all_private_chats:\n%s\n", cJSON_Print(jsonbot_command_scope_all_private_chats_2));
}

int main() {
  test_bot_command_scope_all_private_chats(1);
  test_bot_command_scope_all_private_chats(0);

  printf("Hello world \n");
  return 0;
}

#endif // bot_command_scope_all_private_chats_MAIN
#endif // bot_command_scope_all_private_chats_TEST
