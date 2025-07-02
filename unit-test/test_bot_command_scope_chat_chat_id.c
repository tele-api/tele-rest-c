#ifndef bot_command_scope_chat_chat_id_TEST
#define bot_command_scope_chat_chat_id_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define bot_command_scope_chat_chat_id_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/bot_command_scope_chat_chat_id.h"
bot_command_scope_chat_chat_id_t* instantiate_bot_command_scope_chat_chat_id(int include_optional);



bot_command_scope_chat_chat_id_t* instantiate_bot_command_scope_chat_chat_id(int include_optional) {
  bot_command_scope_chat_chat_id_t* bot_command_scope_chat_chat_id = NULL;
  if (include_optional) {
    bot_command_scope_chat_chat_id = bot_command_scope_chat_chat_id_create(
    );
  } else {
    bot_command_scope_chat_chat_id = bot_command_scope_chat_chat_id_create(
    );
  }

  return bot_command_scope_chat_chat_id;
}


#ifdef bot_command_scope_chat_chat_id_MAIN

void test_bot_command_scope_chat_chat_id(int include_optional) {
    bot_command_scope_chat_chat_id_t* bot_command_scope_chat_chat_id_1 = instantiate_bot_command_scope_chat_chat_id(include_optional);

	cJSON* jsonbot_command_scope_chat_chat_id_1 = bot_command_scope_chat_chat_id_convertToJSON(bot_command_scope_chat_chat_id_1);
	printf("bot_command_scope_chat_chat_id :\n%s\n", cJSON_Print(jsonbot_command_scope_chat_chat_id_1));
	bot_command_scope_chat_chat_id_t* bot_command_scope_chat_chat_id_2 = bot_command_scope_chat_chat_id_parseFromJSON(jsonbot_command_scope_chat_chat_id_1);
	cJSON* jsonbot_command_scope_chat_chat_id_2 = bot_command_scope_chat_chat_id_convertToJSON(bot_command_scope_chat_chat_id_2);
	printf("repeating bot_command_scope_chat_chat_id:\n%s\n", cJSON_Print(jsonbot_command_scope_chat_chat_id_2));
}

int main() {
  test_bot_command_scope_chat_chat_id(1);
  test_bot_command_scope_chat_chat_id(0);

  printf("Hello world \n");
  return 0;
}

#endif // bot_command_scope_chat_chat_id_MAIN
#endif // bot_command_scope_chat_chat_id_TEST
