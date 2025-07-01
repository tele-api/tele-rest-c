#ifndef input_media_audio_TEST
#define input_media_audio_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define input_media_audio_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/input_media_audio.h"
input_media_audio_t* instantiate_input_media_audio(int include_optional);



input_media_audio_t* instantiate_input_media_audio(int include_optional) {
  input_media_audio_t* input_media_audio = NULL;
  if (include_optional) {
    input_media_audio = input_media_audio_create(
      "audio",
      "0",
      "0",
      "0",
      "0",
      list_createList(),
      56,
      "0",
      "0"
    );
  } else {
    input_media_audio = input_media_audio_create(
      "audio",
      "0",
      "0",
      "0",
      "0",
      list_createList(),
      56,
      "0",
      "0"
    );
  }

  return input_media_audio;
}


#ifdef input_media_audio_MAIN

void test_input_media_audio(int include_optional) {
    input_media_audio_t* input_media_audio_1 = instantiate_input_media_audio(include_optional);

	cJSON* jsoninput_media_audio_1 = input_media_audio_convertToJSON(input_media_audio_1);
	printf("input_media_audio :\n%s\n", cJSON_Print(jsoninput_media_audio_1));
	input_media_audio_t* input_media_audio_2 = input_media_audio_parseFromJSON(jsoninput_media_audio_1);
	cJSON* jsoninput_media_audio_2 = input_media_audio_convertToJSON(input_media_audio_2);
	printf("repeating input_media_audio:\n%s\n", cJSON_Print(jsoninput_media_audio_2));
}

int main() {
  test_input_media_audio(1);
  test_input_media_audio(0);

  printf("Hello world \n");
  return 0;
}

#endif // input_media_audio_MAIN
#endif // input_media_audio_TEST
