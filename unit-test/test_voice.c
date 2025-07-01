#ifndef voice_TEST
#define voice_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define voice_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/voice.h"
voice_t* instantiate_voice(int include_optional);



voice_t* instantiate_voice(int include_optional) {
  voice_t* voice = NULL;
  if (include_optional) {
    voice = voice_create(
      "0",
      "0",
      56,
      "0",
      56
    );
  } else {
    voice = voice_create(
      "0",
      "0",
      56,
      "0",
      56
    );
  }

  return voice;
}


#ifdef voice_MAIN

void test_voice(int include_optional) {
    voice_t* voice_1 = instantiate_voice(include_optional);

	cJSON* jsonvoice_1 = voice_convertToJSON(voice_1);
	printf("voice :\n%s\n", cJSON_Print(jsonvoice_1));
	voice_t* voice_2 = voice_parseFromJSON(jsonvoice_1);
	cJSON* jsonvoice_2 = voice_convertToJSON(voice_2);
	printf("repeating voice:\n%s\n", cJSON_Print(jsonvoice_2));
}

int main() {
  test_voice(1);
  test_voice(0);

  printf("Hello world \n");
  return 0;
}

#endif // voice_MAIN
#endif // voice_TEST
