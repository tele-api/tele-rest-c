#ifndef audio_TEST
#define audio_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define audio_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/audio.h"
audio_t* instantiate_audio(int include_optional);

#include "test_photo_size.c"


audio_t* instantiate_audio(int include_optional) {
  audio_t* audio = NULL;
  if (include_optional) {
    audio = audio_create(
      "0",
      "0",
      56,
      "0",
      "0",
      "0",
      "0",
      56,
       // false, not to have infinite recursion
      instantiate_photo_size(0)
    );
  } else {
    audio = audio_create(
      "0",
      "0",
      56,
      "0",
      "0",
      "0",
      "0",
      56,
      NULL
    );
  }

  return audio;
}


#ifdef audio_MAIN

void test_audio(int include_optional) {
    audio_t* audio_1 = instantiate_audio(include_optional);

	cJSON* jsonaudio_1 = audio_convertToJSON(audio_1);
	printf("audio :\n%s\n", cJSON_Print(jsonaudio_1));
	audio_t* audio_2 = audio_parseFromJSON(jsonaudio_1);
	cJSON* jsonaudio_2 = audio_convertToJSON(audio_2);
	printf("repeating audio:\n%s\n", cJSON_Print(jsonaudio_2));
}

int main() {
  test_audio(1);
  test_audio(0);

  printf("Hello world \n");
  return 0;
}

#endif // audio_MAIN
#endif // audio_TEST
