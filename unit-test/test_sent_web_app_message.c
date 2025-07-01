#ifndef sent_web_app_message_TEST
#define sent_web_app_message_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define sent_web_app_message_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/sent_web_app_message.h"
sent_web_app_message_t* instantiate_sent_web_app_message(int include_optional);



sent_web_app_message_t* instantiate_sent_web_app_message(int include_optional) {
  sent_web_app_message_t* sent_web_app_message = NULL;
  if (include_optional) {
    sent_web_app_message = sent_web_app_message_create(
      "0"
    );
  } else {
    sent_web_app_message = sent_web_app_message_create(
      "0"
    );
  }

  return sent_web_app_message;
}


#ifdef sent_web_app_message_MAIN

void test_sent_web_app_message(int include_optional) {
    sent_web_app_message_t* sent_web_app_message_1 = instantiate_sent_web_app_message(include_optional);

	cJSON* jsonsent_web_app_message_1 = sent_web_app_message_convertToJSON(sent_web_app_message_1);
	printf("sent_web_app_message :\n%s\n", cJSON_Print(jsonsent_web_app_message_1));
	sent_web_app_message_t* sent_web_app_message_2 = sent_web_app_message_parseFromJSON(jsonsent_web_app_message_1);
	cJSON* jsonsent_web_app_message_2 = sent_web_app_message_convertToJSON(sent_web_app_message_2);
	printf("repeating sent_web_app_message:\n%s\n", cJSON_Print(jsonsent_web_app_message_2));
}

int main() {
  test_sent_web_app_message(1);
  test_sent_web_app_message(0);

  printf("Hello world \n");
  return 0;
}

#endif // sent_web_app_message_MAIN
#endif // sent_web_app_message_TEST
