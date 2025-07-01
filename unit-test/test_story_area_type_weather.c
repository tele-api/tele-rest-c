#ifndef story_area_type_weather_TEST
#define story_area_type_weather_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define story_area_type_weather_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/story_area_type_weather.h"
story_area_type_weather_t* instantiate_story_area_type_weather(int include_optional);



story_area_type_weather_t* instantiate_story_area_type_weather(int include_optional) {
  story_area_type_weather_t* story_area_type_weather = NULL;
  if (include_optional) {
    story_area_type_weather = story_area_type_weather_create(
      "weather",
      1.337,
      "0",
      56
    );
  } else {
    story_area_type_weather = story_area_type_weather_create(
      "weather",
      1.337,
      "0",
      56
    );
  }

  return story_area_type_weather;
}


#ifdef story_area_type_weather_MAIN

void test_story_area_type_weather(int include_optional) {
    story_area_type_weather_t* story_area_type_weather_1 = instantiate_story_area_type_weather(include_optional);

	cJSON* jsonstory_area_type_weather_1 = story_area_type_weather_convertToJSON(story_area_type_weather_1);
	printf("story_area_type_weather :\n%s\n", cJSON_Print(jsonstory_area_type_weather_1));
	story_area_type_weather_t* story_area_type_weather_2 = story_area_type_weather_parseFromJSON(jsonstory_area_type_weather_1);
	cJSON* jsonstory_area_type_weather_2 = story_area_type_weather_convertToJSON(story_area_type_weather_2);
	printf("repeating story_area_type_weather:\n%s\n", cJSON_Print(jsonstory_area_type_weather_2));
}

int main() {
  test_story_area_type_weather(1);
  test_story_area_type_weather(0);

  printf("Hello world \n");
  return 0;
}

#endif // story_area_type_weather_MAIN
#endif // story_area_type_weather_TEST
