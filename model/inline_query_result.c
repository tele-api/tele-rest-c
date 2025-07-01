#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "inline_query_result.h"


char* inline_query_result_mime_type_ToString(telegram_bot_api_inline_query_result_MIMETYPE_e mime_type) {
    char* mime_typeArray[] =  { "NULL", "text/html", "video/mp4" };
    return mime_typeArray[mime_type];
}

telegram_bot_api_inline_query_result_MIMETYPE_e inline_query_result_mime_type_FromString(char* mime_type){
    int stringToReturn = 0;
    char *mime_typeArray[] =  { "NULL", "text/html", "video/mp4" };
    size_t sizeofArray = sizeof(mime_typeArray) / sizeof(mime_typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(mime_type, mime_typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}
char* inline_query_result_thumbnail_mime_type_ToString(telegram_bot_api_inline_query_result_THUMBNAILMIMETYPE_e thumbnail_mime_type) {
    char* thumbnail_mime_typeArray[] =  { "NULL", "image/jpeg", "image/gif", "video/mp4" };
    return thumbnail_mime_typeArray[thumbnail_mime_type];
}

telegram_bot_api_inline_query_result_THUMBNAILMIMETYPE_e inline_query_result_thumbnail_mime_type_FromString(char* thumbnail_mime_type){
    int stringToReturn = 0;
    char *thumbnail_mime_typeArray[] =  { "NULL", "image/jpeg", "image/gif", "video/mp4" };
    size_t sizeofArray = sizeof(thumbnail_mime_typeArray) / sizeof(thumbnail_mime_typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(thumbnail_mime_type, thumbnail_mime_typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static inline_query_result_t *inline_query_result_create_internal(
    char *type,
    char *id,
    char *audio_file_id,
    input_message_content_t *input_message_content,
    char *title,
    char *document_file_id,
    char *gif_file_id,
    char *mpeg4_file_id,
    char *photo_file_id,
    char *sticker_file_id,
    char *video_file_id,
    char *voice_file_id,
    char *thumbnail_url,
    char *audio_url,
    char *phone_number,
    char *first_name,
    char *game_short_name,
    char *document_url,
    telegram_bot_api_inline_query_result_MIMETYPE_e mime_type,
    char *gif_url,
    double latitude,
    double longitude,
    char *mpeg4_url,
    char *photo_url,
    char *address,
    char *video_url,
    char *voice_url,
    char *caption,
    char *parse_mode,
    list_t *caption_entities,
    inline_keyboard_markup_t *reply_markup,
    char *description,
    int show_caption_above_media,
    char *url,
    int thumbnail_width,
    int thumbnail_height,
    char *performer,
    int audio_duration,
    char *last_name,
    char *vcard,
    int gif_width,
    int gif_height,
    int gif_duration,
    telegram_bot_api_inline_query_result_THUMBNAILMIMETYPE_e thumbnail_mime_type,
    double horizontal_accuracy,
    int live_period,
    int heading,
    int proximity_alert_radius,
    int mpeg4_width,
    int mpeg4_height,
    int mpeg4_duration,
    int photo_width,
    int photo_height,
    char *foursquare_id,
    char *foursquare_type,
    char *google_place_id,
    char *google_place_type,
    int video_width,
    int video_height,
    int video_duration,
    int voice_duration
    ) {
    inline_query_result_t *inline_query_result_local_var = malloc(sizeof(inline_query_result_t));
    if (!inline_query_result_local_var) {
        return NULL;
    }
    inline_query_result_local_var->type = type;
    inline_query_result_local_var->id = id;
    inline_query_result_local_var->audio_file_id = audio_file_id;
    inline_query_result_local_var->input_message_content = input_message_content;
    inline_query_result_local_var->title = title;
    inline_query_result_local_var->document_file_id = document_file_id;
    inline_query_result_local_var->gif_file_id = gif_file_id;
    inline_query_result_local_var->mpeg4_file_id = mpeg4_file_id;
    inline_query_result_local_var->photo_file_id = photo_file_id;
    inline_query_result_local_var->sticker_file_id = sticker_file_id;
    inline_query_result_local_var->video_file_id = video_file_id;
    inline_query_result_local_var->voice_file_id = voice_file_id;
    inline_query_result_local_var->thumbnail_url = thumbnail_url;
    inline_query_result_local_var->audio_url = audio_url;
    inline_query_result_local_var->phone_number = phone_number;
    inline_query_result_local_var->first_name = first_name;
    inline_query_result_local_var->game_short_name = game_short_name;
    inline_query_result_local_var->document_url = document_url;
    inline_query_result_local_var->mime_type = mime_type;
    inline_query_result_local_var->gif_url = gif_url;
    inline_query_result_local_var->latitude = latitude;
    inline_query_result_local_var->longitude = longitude;
    inline_query_result_local_var->mpeg4_url = mpeg4_url;
    inline_query_result_local_var->photo_url = photo_url;
    inline_query_result_local_var->address = address;
    inline_query_result_local_var->video_url = video_url;
    inline_query_result_local_var->voice_url = voice_url;
    inline_query_result_local_var->caption = caption;
    inline_query_result_local_var->parse_mode = parse_mode;
    inline_query_result_local_var->caption_entities = caption_entities;
    inline_query_result_local_var->reply_markup = reply_markup;
    inline_query_result_local_var->description = description;
    inline_query_result_local_var->show_caption_above_media = show_caption_above_media;
    inline_query_result_local_var->url = url;
    inline_query_result_local_var->thumbnail_width = thumbnail_width;
    inline_query_result_local_var->thumbnail_height = thumbnail_height;
    inline_query_result_local_var->performer = performer;
    inline_query_result_local_var->audio_duration = audio_duration;
    inline_query_result_local_var->last_name = last_name;
    inline_query_result_local_var->vcard = vcard;
    inline_query_result_local_var->gif_width = gif_width;
    inline_query_result_local_var->gif_height = gif_height;
    inline_query_result_local_var->gif_duration = gif_duration;
    inline_query_result_local_var->thumbnail_mime_type = thumbnail_mime_type;
    inline_query_result_local_var->horizontal_accuracy = horizontal_accuracy;
    inline_query_result_local_var->live_period = live_period;
    inline_query_result_local_var->heading = heading;
    inline_query_result_local_var->proximity_alert_radius = proximity_alert_radius;
    inline_query_result_local_var->mpeg4_width = mpeg4_width;
    inline_query_result_local_var->mpeg4_height = mpeg4_height;
    inline_query_result_local_var->mpeg4_duration = mpeg4_duration;
    inline_query_result_local_var->photo_width = photo_width;
    inline_query_result_local_var->photo_height = photo_height;
    inline_query_result_local_var->foursquare_id = foursquare_id;
    inline_query_result_local_var->foursquare_type = foursquare_type;
    inline_query_result_local_var->google_place_id = google_place_id;
    inline_query_result_local_var->google_place_type = google_place_type;
    inline_query_result_local_var->video_width = video_width;
    inline_query_result_local_var->video_height = video_height;
    inline_query_result_local_var->video_duration = video_duration;
    inline_query_result_local_var->voice_duration = voice_duration;

    inline_query_result_local_var->_library_owned = 1;
    return inline_query_result_local_var;
}

__attribute__((deprecated)) inline_query_result_t *inline_query_result_create(
    char *type,
    char *id,
    char *audio_file_id,
    input_message_content_t *input_message_content,
    char *title,
    char *document_file_id,
    char *gif_file_id,
    char *mpeg4_file_id,
    char *photo_file_id,
    char *sticker_file_id,
    char *video_file_id,
    char *voice_file_id,
    char *thumbnail_url,
    char *audio_url,
    char *phone_number,
    char *first_name,
    char *game_short_name,
    char *document_url,
    telegram_bot_api_inline_query_result_MIMETYPE_e mime_type,
    char *gif_url,
    double latitude,
    double longitude,
    char *mpeg4_url,
    char *photo_url,
    char *address,
    char *video_url,
    char *voice_url,
    char *caption,
    char *parse_mode,
    list_t *caption_entities,
    inline_keyboard_markup_t *reply_markup,
    char *description,
    int show_caption_above_media,
    char *url,
    int thumbnail_width,
    int thumbnail_height,
    char *performer,
    int audio_duration,
    char *last_name,
    char *vcard,
    int gif_width,
    int gif_height,
    int gif_duration,
    telegram_bot_api_inline_query_result_THUMBNAILMIMETYPE_e thumbnail_mime_type,
    double horizontal_accuracy,
    int live_period,
    int heading,
    int proximity_alert_radius,
    int mpeg4_width,
    int mpeg4_height,
    int mpeg4_duration,
    int photo_width,
    int photo_height,
    char *foursquare_id,
    char *foursquare_type,
    char *google_place_id,
    char *google_place_type,
    int video_width,
    int video_height,
    int video_duration,
    int voice_duration
    ) {
    return inline_query_result_create_internal (
        type,
        id,
        audio_file_id,
        input_message_content,
        title,
        document_file_id,
        gif_file_id,
        mpeg4_file_id,
        photo_file_id,
        sticker_file_id,
        video_file_id,
        voice_file_id,
        thumbnail_url,
        audio_url,
        phone_number,
        first_name,
        game_short_name,
        document_url,
        mime_type,
        gif_url,
        latitude,
        longitude,
        mpeg4_url,
        photo_url,
        address,
        video_url,
        voice_url,
        caption,
        parse_mode,
        caption_entities,
        reply_markup,
        description,
        show_caption_above_media,
        url,
        thumbnail_width,
        thumbnail_height,
        performer,
        audio_duration,
        last_name,
        vcard,
        gif_width,
        gif_height,
        gif_duration,
        thumbnail_mime_type,
        horizontal_accuracy,
        live_period,
        heading,
        proximity_alert_radius,
        mpeg4_width,
        mpeg4_height,
        mpeg4_duration,
        photo_width,
        photo_height,
        foursquare_id,
        foursquare_type,
        google_place_id,
        google_place_type,
        video_width,
        video_height,
        video_duration,
        voice_duration
        );
}

void inline_query_result_free(inline_query_result_t *inline_query_result) {
    if(NULL == inline_query_result){
        return ;
    }
    if(inline_query_result->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "inline_query_result_free");
        return ;
    }
    listEntry_t *listEntry;
    if (inline_query_result->type) {
        free(inline_query_result->type);
        inline_query_result->type = NULL;
    }
    if (inline_query_result->id) {
        free(inline_query_result->id);
        inline_query_result->id = NULL;
    }
    if (inline_query_result->audio_file_id) {
        free(inline_query_result->audio_file_id);
        inline_query_result->audio_file_id = NULL;
    }
    if (inline_query_result->input_message_content) {
        input_message_content_free(inline_query_result->input_message_content);
        inline_query_result->input_message_content = NULL;
    }
    if (inline_query_result->title) {
        free(inline_query_result->title);
        inline_query_result->title = NULL;
    }
    if (inline_query_result->document_file_id) {
        free(inline_query_result->document_file_id);
        inline_query_result->document_file_id = NULL;
    }
    if (inline_query_result->gif_file_id) {
        free(inline_query_result->gif_file_id);
        inline_query_result->gif_file_id = NULL;
    }
    if (inline_query_result->mpeg4_file_id) {
        free(inline_query_result->mpeg4_file_id);
        inline_query_result->mpeg4_file_id = NULL;
    }
    if (inline_query_result->photo_file_id) {
        free(inline_query_result->photo_file_id);
        inline_query_result->photo_file_id = NULL;
    }
    if (inline_query_result->sticker_file_id) {
        free(inline_query_result->sticker_file_id);
        inline_query_result->sticker_file_id = NULL;
    }
    if (inline_query_result->video_file_id) {
        free(inline_query_result->video_file_id);
        inline_query_result->video_file_id = NULL;
    }
    if (inline_query_result->voice_file_id) {
        free(inline_query_result->voice_file_id);
        inline_query_result->voice_file_id = NULL;
    }
    if (inline_query_result->thumbnail_url) {
        free(inline_query_result->thumbnail_url);
        inline_query_result->thumbnail_url = NULL;
    }
    if (inline_query_result->audio_url) {
        free(inline_query_result->audio_url);
        inline_query_result->audio_url = NULL;
    }
    if (inline_query_result->phone_number) {
        free(inline_query_result->phone_number);
        inline_query_result->phone_number = NULL;
    }
    if (inline_query_result->first_name) {
        free(inline_query_result->first_name);
        inline_query_result->first_name = NULL;
    }
    if (inline_query_result->game_short_name) {
        free(inline_query_result->game_short_name);
        inline_query_result->game_short_name = NULL;
    }
    if (inline_query_result->document_url) {
        free(inline_query_result->document_url);
        inline_query_result->document_url = NULL;
    }
    if (inline_query_result->gif_url) {
        free(inline_query_result->gif_url);
        inline_query_result->gif_url = NULL;
    }
    if (inline_query_result->mpeg4_url) {
        free(inline_query_result->mpeg4_url);
        inline_query_result->mpeg4_url = NULL;
    }
    if (inline_query_result->photo_url) {
        free(inline_query_result->photo_url);
        inline_query_result->photo_url = NULL;
    }
    if (inline_query_result->address) {
        free(inline_query_result->address);
        inline_query_result->address = NULL;
    }
    if (inline_query_result->video_url) {
        free(inline_query_result->video_url);
        inline_query_result->video_url = NULL;
    }
    if (inline_query_result->voice_url) {
        free(inline_query_result->voice_url);
        inline_query_result->voice_url = NULL;
    }
    if (inline_query_result->caption) {
        free(inline_query_result->caption);
        inline_query_result->caption = NULL;
    }
    if (inline_query_result->parse_mode) {
        free(inline_query_result->parse_mode);
        inline_query_result->parse_mode = NULL;
    }
    if (inline_query_result->caption_entities) {
        list_ForEach(listEntry, inline_query_result->caption_entities) {
            message_entity_free(listEntry->data);
        }
        list_freeList(inline_query_result->caption_entities);
        inline_query_result->caption_entities = NULL;
    }
    if (inline_query_result->reply_markup) {
        inline_keyboard_markup_free(inline_query_result->reply_markup);
        inline_query_result->reply_markup = NULL;
    }
    if (inline_query_result->description) {
        free(inline_query_result->description);
        inline_query_result->description = NULL;
    }
    if (inline_query_result->url) {
        free(inline_query_result->url);
        inline_query_result->url = NULL;
    }
    if (inline_query_result->performer) {
        free(inline_query_result->performer);
        inline_query_result->performer = NULL;
    }
    if (inline_query_result->last_name) {
        free(inline_query_result->last_name);
        inline_query_result->last_name = NULL;
    }
    if (inline_query_result->vcard) {
        free(inline_query_result->vcard);
        inline_query_result->vcard = NULL;
    }
    if (inline_query_result->foursquare_id) {
        free(inline_query_result->foursquare_id);
        inline_query_result->foursquare_id = NULL;
    }
    if (inline_query_result->foursquare_type) {
        free(inline_query_result->foursquare_type);
        inline_query_result->foursquare_type = NULL;
    }
    if (inline_query_result->google_place_id) {
        free(inline_query_result->google_place_id);
        inline_query_result->google_place_id = NULL;
    }
    if (inline_query_result->google_place_type) {
        free(inline_query_result->google_place_type);
        inline_query_result->google_place_type = NULL;
    }
    free(inline_query_result);
}

cJSON *inline_query_result_convertToJSON(inline_query_result_t *inline_query_result) {
    cJSON *item = cJSON_CreateObject();

    // inline_query_result->type
    if (!inline_query_result->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", inline_query_result->type) == NULL) {
    goto fail; //String
    }


    // inline_query_result->id
    if (!inline_query_result->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", inline_query_result->id) == NULL) {
    goto fail; //String
    }


    // inline_query_result->audio_file_id
    if (!inline_query_result->audio_file_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "audio_file_id", inline_query_result->audio_file_id) == NULL) {
    goto fail; //String
    }


    // inline_query_result->input_message_content
    if (!inline_query_result->input_message_content) {
        goto fail;
    }
    cJSON *input_message_content_local_JSON = input_message_content_convertToJSON(inline_query_result->input_message_content);
    if(input_message_content_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "input_message_content", input_message_content_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // inline_query_result->title
    if (!inline_query_result->title) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "title", inline_query_result->title) == NULL) {
    goto fail; //String
    }


    // inline_query_result->document_file_id
    if (!inline_query_result->document_file_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "document_file_id", inline_query_result->document_file_id) == NULL) {
    goto fail; //String
    }


    // inline_query_result->gif_file_id
    if (!inline_query_result->gif_file_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "gif_file_id", inline_query_result->gif_file_id) == NULL) {
    goto fail; //String
    }


    // inline_query_result->mpeg4_file_id
    if (!inline_query_result->mpeg4_file_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "mpeg4_file_id", inline_query_result->mpeg4_file_id) == NULL) {
    goto fail; //String
    }


    // inline_query_result->photo_file_id
    if (!inline_query_result->photo_file_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "photo_file_id", inline_query_result->photo_file_id) == NULL) {
    goto fail; //String
    }


    // inline_query_result->sticker_file_id
    if (!inline_query_result->sticker_file_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "sticker_file_id", inline_query_result->sticker_file_id) == NULL) {
    goto fail; //String
    }


    // inline_query_result->video_file_id
    if (!inline_query_result->video_file_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "video_file_id", inline_query_result->video_file_id) == NULL) {
    goto fail; //String
    }


    // inline_query_result->voice_file_id
    if (!inline_query_result->voice_file_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "voice_file_id", inline_query_result->voice_file_id) == NULL) {
    goto fail; //String
    }


    // inline_query_result->thumbnail_url
    if (!inline_query_result->thumbnail_url) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "thumbnail_url", inline_query_result->thumbnail_url) == NULL) {
    goto fail; //String
    }


    // inline_query_result->audio_url
    if (!inline_query_result->audio_url) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "audio_url", inline_query_result->audio_url) == NULL) {
    goto fail; //String
    }


    // inline_query_result->phone_number
    if (!inline_query_result->phone_number) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "phone_number", inline_query_result->phone_number) == NULL) {
    goto fail; //String
    }


    // inline_query_result->first_name
    if (!inline_query_result->first_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "first_name", inline_query_result->first_name) == NULL) {
    goto fail; //String
    }


    // inline_query_result->game_short_name
    if (!inline_query_result->game_short_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "game_short_name", inline_query_result->game_short_name) == NULL) {
    goto fail; //String
    }


    // inline_query_result->document_url
    if (!inline_query_result->document_url) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "document_url", inline_query_result->document_url) == NULL) {
    goto fail; //String
    }


    // inline_query_result->mime_type
    if (telegram_bot_api_inline_query_result_MIMETYPE_NULL == inline_query_result->mime_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "mime_type", inline_query_result_mime_type_ToString(inline_query_result->mime_type)) == NULL)
    {
    goto fail; //Enum
    }


    // inline_query_result->gif_url
    if (!inline_query_result->gif_url) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "gif_url", inline_query_result->gif_url) == NULL) {
    goto fail; //String
    }


    // inline_query_result->latitude
    if (!inline_query_result->latitude) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "latitude", inline_query_result->latitude) == NULL) {
    goto fail; //Numeric
    }


    // inline_query_result->longitude
    if (!inline_query_result->longitude) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "longitude", inline_query_result->longitude) == NULL) {
    goto fail; //Numeric
    }


    // inline_query_result->mpeg4_url
    if (!inline_query_result->mpeg4_url) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "mpeg4_url", inline_query_result->mpeg4_url) == NULL) {
    goto fail; //String
    }


    // inline_query_result->photo_url
    if (!inline_query_result->photo_url) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "photo_url", inline_query_result->photo_url) == NULL) {
    goto fail; //String
    }


    // inline_query_result->address
    if (!inline_query_result->address) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "address", inline_query_result->address) == NULL) {
    goto fail; //String
    }


    // inline_query_result->video_url
    if (!inline_query_result->video_url) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "video_url", inline_query_result->video_url) == NULL) {
    goto fail; //String
    }


    // inline_query_result->voice_url
    if (!inline_query_result->voice_url) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "voice_url", inline_query_result->voice_url) == NULL) {
    goto fail; //String
    }


    // inline_query_result->caption
    if(inline_query_result->caption) {
    if(cJSON_AddStringToObject(item, "caption", inline_query_result->caption) == NULL) {
    goto fail; //String
    }
    }


    // inline_query_result->parse_mode
    if(inline_query_result->parse_mode) {
    if(cJSON_AddStringToObject(item, "parse_mode", inline_query_result->parse_mode) == NULL) {
    goto fail; //String
    }
    }


    // inline_query_result->caption_entities
    if(inline_query_result->caption_entities) {
    cJSON *caption_entities = cJSON_AddArrayToObject(item, "caption_entities");
    if(caption_entities == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *caption_entitiesListEntry;
    if (inline_query_result->caption_entities) {
    list_ForEach(caption_entitiesListEntry, inline_query_result->caption_entities) {
    cJSON *itemLocal = message_entity_convertToJSON(caption_entitiesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(caption_entities, itemLocal);
    }
    }
    }


    // inline_query_result->reply_markup
    if(inline_query_result->reply_markup) {
    cJSON *reply_markup_local_JSON = inline_keyboard_markup_convertToJSON(inline_query_result->reply_markup);
    if(reply_markup_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "reply_markup", reply_markup_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // inline_query_result->description
    if(inline_query_result->description) {
    if(cJSON_AddStringToObject(item, "description", inline_query_result->description) == NULL) {
    goto fail; //String
    }
    }


    // inline_query_result->show_caption_above_media
    if(inline_query_result->show_caption_above_media) {
    if(cJSON_AddBoolToObject(item, "show_caption_above_media", inline_query_result->show_caption_above_media) == NULL) {
    goto fail; //Bool
    }
    }


    // inline_query_result->url
    if(inline_query_result->url) {
    if(cJSON_AddStringToObject(item, "url", inline_query_result->url) == NULL) {
    goto fail; //String
    }
    }


    // inline_query_result->thumbnail_width
    if(inline_query_result->thumbnail_width) {
    if(cJSON_AddNumberToObject(item, "thumbnail_width", inline_query_result->thumbnail_width) == NULL) {
    goto fail; //Numeric
    }
    }


    // inline_query_result->thumbnail_height
    if(inline_query_result->thumbnail_height) {
    if(cJSON_AddNumberToObject(item, "thumbnail_height", inline_query_result->thumbnail_height) == NULL) {
    goto fail; //Numeric
    }
    }


    // inline_query_result->performer
    if(inline_query_result->performer) {
    if(cJSON_AddStringToObject(item, "performer", inline_query_result->performer) == NULL) {
    goto fail; //String
    }
    }


    // inline_query_result->audio_duration
    if(inline_query_result->audio_duration) {
    if(cJSON_AddNumberToObject(item, "audio_duration", inline_query_result->audio_duration) == NULL) {
    goto fail; //Numeric
    }
    }


    // inline_query_result->last_name
    if(inline_query_result->last_name) {
    if(cJSON_AddStringToObject(item, "last_name", inline_query_result->last_name) == NULL) {
    goto fail; //String
    }
    }


    // inline_query_result->vcard
    if(inline_query_result->vcard) {
    if(cJSON_AddStringToObject(item, "vcard", inline_query_result->vcard) == NULL) {
    goto fail; //String
    }
    }


    // inline_query_result->gif_width
    if(inline_query_result->gif_width) {
    if(cJSON_AddNumberToObject(item, "gif_width", inline_query_result->gif_width) == NULL) {
    goto fail; //Numeric
    }
    }


    // inline_query_result->gif_height
    if(inline_query_result->gif_height) {
    if(cJSON_AddNumberToObject(item, "gif_height", inline_query_result->gif_height) == NULL) {
    goto fail; //Numeric
    }
    }


    // inline_query_result->gif_duration
    if(inline_query_result->gif_duration) {
    if(cJSON_AddNumberToObject(item, "gif_duration", inline_query_result->gif_duration) == NULL) {
    goto fail; //Numeric
    }
    }


    // inline_query_result->thumbnail_mime_type
    if(inline_query_result->thumbnail_mime_type != telegram_bot_api_inline_query_result_THUMBNAILMIMETYPE_NULL) {
    if(cJSON_AddStringToObject(item, "thumbnail_mime_type", inline_query_result_thumbnail_mime_type_ToString(inline_query_result->thumbnail_mime_type)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // inline_query_result->horizontal_accuracy
    if(inline_query_result->horizontal_accuracy) {
    if(cJSON_AddNumberToObject(item, "horizontal_accuracy", inline_query_result->horizontal_accuracy) == NULL) {
    goto fail; //Numeric
    }
    }


    // inline_query_result->live_period
    if(inline_query_result->live_period) {
    if(cJSON_AddNumberToObject(item, "live_period", inline_query_result->live_period) == NULL) {
    goto fail; //Numeric
    }
    }


    // inline_query_result->heading
    if(inline_query_result->heading) {
    if(cJSON_AddNumberToObject(item, "heading", inline_query_result->heading) == NULL) {
    goto fail; //Numeric
    }
    }


    // inline_query_result->proximity_alert_radius
    if(inline_query_result->proximity_alert_radius) {
    if(cJSON_AddNumberToObject(item, "proximity_alert_radius", inline_query_result->proximity_alert_radius) == NULL) {
    goto fail; //Numeric
    }
    }


    // inline_query_result->mpeg4_width
    if(inline_query_result->mpeg4_width) {
    if(cJSON_AddNumberToObject(item, "mpeg4_width", inline_query_result->mpeg4_width) == NULL) {
    goto fail; //Numeric
    }
    }


    // inline_query_result->mpeg4_height
    if(inline_query_result->mpeg4_height) {
    if(cJSON_AddNumberToObject(item, "mpeg4_height", inline_query_result->mpeg4_height) == NULL) {
    goto fail; //Numeric
    }
    }


    // inline_query_result->mpeg4_duration
    if(inline_query_result->mpeg4_duration) {
    if(cJSON_AddNumberToObject(item, "mpeg4_duration", inline_query_result->mpeg4_duration) == NULL) {
    goto fail; //Numeric
    }
    }


    // inline_query_result->photo_width
    if(inline_query_result->photo_width) {
    if(cJSON_AddNumberToObject(item, "photo_width", inline_query_result->photo_width) == NULL) {
    goto fail; //Numeric
    }
    }


    // inline_query_result->photo_height
    if(inline_query_result->photo_height) {
    if(cJSON_AddNumberToObject(item, "photo_height", inline_query_result->photo_height) == NULL) {
    goto fail; //Numeric
    }
    }


    // inline_query_result->foursquare_id
    if(inline_query_result->foursquare_id) {
    if(cJSON_AddStringToObject(item, "foursquare_id", inline_query_result->foursquare_id) == NULL) {
    goto fail; //String
    }
    }


    // inline_query_result->foursquare_type
    if(inline_query_result->foursquare_type) {
    if(cJSON_AddStringToObject(item, "foursquare_type", inline_query_result->foursquare_type) == NULL) {
    goto fail; //String
    }
    }


    // inline_query_result->google_place_id
    if(inline_query_result->google_place_id) {
    if(cJSON_AddStringToObject(item, "google_place_id", inline_query_result->google_place_id) == NULL) {
    goto fail; //String
    }
    }


    // inline_query_result->google_place_type
    if(inline_query_result->google_place_type) {
    if(cJSON_AddStringToObject(item, "google_place_type", inline_query_result->google_place_type) == NULL) {
    goto fail; //String
    }
    }


    // inline_query_result->video_width
    if(inline_query_result->video_width) {
    if(cJSON_AddNumberToObject(item, "video_width", inline_query_result->video_width) == NULL) {
    goto fail; //Numeric
    }
    }


    // inline_query_result->video_height
    if(inline_query_result->video_height) {
    if(cJSON_AddNumberToObject(item, "video_height", inline_query_result->video_height) == NULL) {
    goto fail; //Numeric
    }
    }


    // inline_query_result->video_duration
    if(inline_query_result->video_duration) {
    if(cJSON_AddNumberToObject(item, "video_duration", inline_query_result->video_duration) == NULL) {
    goto fail; //Numeric
    }
    }


    // inline_query_result->voice_duration
    if(inline_query_result->voice_duration) {
    if(cJSON_AddNumberToObject(item, "voice_duration", inline_query_result->voice_duration) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

inline_query_result_t *inline_query_result_parseFromJSON(cJSON *inline_query_resultJSON){

    inline_query_result_t *inline_query_result_local_var = NULL;

    // define the local variable for inline_query_result->input_message_content
    input_message_content_t *input_message_content_local_nonprim = NULL;

    // define the local list for inline_query_result->caption_entities
    list_t *caption_entitiesList = NULL;

    // define the local variable for inline_query_result->reply_markup
    inline_keyboard_markup_t *reply_markup_local_nonprim = NULL;

    // inline_query_result->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(inline_query_resultJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }

    // inline_query_result->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(inline_query_resultJSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (!id) {
        goto end;
    }

    
    if(!cJSON_IsString(id))
    {
    goto end; //String
    }

    // inline_query_result->audio_file_id
    cJSON *audio_file_id = cJSON_GetObjectItemCaseSensitive(inline_query_resultJSON, "audio_file_id");
    if (cJSON_IsNull(audio_file_id)) {
        audio_file_id = NULL;
    }
    if (!audio_file_id) {
        goto end;
    }

    
    if(!cJSON_IsString(audio_file_id))
    {
    goto end; //String
    }

    // inline_query_result->input_message_content
    cJSON *input_message_content = cJSON_GetObjectItemCaseSensitive(inline_query_resultJSON, "input_message_content");
    if (cJSON_IsNull(input_message_content)) {
        input_message_content = NULL;
    }
    if (!input_message_content) {
        goto end;
    }

    
    input_message_content_local_nonprim = input_message_content_parseFromJSON(input_message_content); //nonprimitive

    // inline_query_result->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(inline_query_resultJSON, "title");
    if (cJSON_IsNull(title)) {
        title = NULL;
    }
    if (!title) {
        goto end;
    }

    
    if(!cJSON_IsString(title))
    {
    goto end; //String
    }

    // inline_query_result->document_file_id
    cJSON *document_file_id = cJSON_GetObjectItemCaseSensitive(inline_query_resultJSON, "document_file_id");
    if (cJSON_IsNull(document_file_id)) {
        document_file_id = NULL;
    }
    if (!document_file_id) {
        goto end;
    }

    
    if(!cJSON_IsString(document_file_id))
    {
    goto end; //String
    }

    // inline_query_result->gif_file_id
    cJSON *gif_file_id = cJSON_GetObjectItemCaseSensitive(inline_query_resultJSON, "gif_file_id");
    if (cJSON_IsNull(gif_file_id)) {
        gif_file_id = NULL;
    }
    if (!gif_file_id) {
        goto end;
    }

    
    if(!cJSON_IsString(gif_file_id))
    {
    goto end; //String
    }

    // inline_query_result->mpeg4_file_id
    cJSON *mpeg4_file_id = cJSON_GetObjectItemCaseSensitive(inline_query_resultJSON, "mpeg4_file_id");
    if (cJSON_IsNull(mpeg4_file_id)) {
        mpeg4_file_id = NULL;
    }
    if (!mpeg4_file_id) {
        goto end;
    }

    
    if(!cJSON_IsString(mpeg4_file_id))
    {
    goto end; //String
    }

    // inline_query_result->photo_file_id
    cJSON *photo_file_id = cJSON_GetObjectItemCaseSensitive(inline_query_resultJSON, "photo_file_id");
    if (cJSON_IsNull(photo_file_id)) {
        photo_file_id = NULL;
    }
    if (!photo_file_id) {
        goto end;
    }

    
    if(!cJSON_IsString(photo_file_id))
    {
    goto end; //String
    }

    // inline_query_result->sticker_file_id
    cJSON *sticker_file_id = cJSON_GetObjectItemCaseSensitive(inline_query_resultJSON, "sticker_file_id");
    if (cJSON_IsNull(sticker_file_id)) {
        sticker_file_id = NULL;
    }
    if (!sticker_file_id) {
        goto end;
    }

    
    if(!cJSON_IsString(sticker_file_id))
    {
    goto end; //String
    }

    // inline_query_result->video_file_id
    cJSON *video_file_id = cJSON_GetObjectItemCaseSensitive(inline_query_resultJSON, "video_file_id");
    if (cJSON_IsNull(video_file_id)) {
        video_file_id = NULL;
    }
    if (!video_file_id) {
        goto end;
    }

    
    if(!cJSON_IsString(video_file_id))
    {
    goto end; //String
    }

    // inline_query_result->voice_file_id
    cJSON *voice_file_id = cJSON_GetObjectItemCaseSensitive(inline_query_resultJSON, "voice_file_id");
    if (cJSON_IsNull(voice_file_id)) {
        voice_file_id = NULL;
    }
    if (!voice_file_id) {
        goto end;
    }

    
    if(!cJSON_IsString(voice_file_id))
    {
    goto end; //String
    }

    // inline_query_result->thumbnail_url
    cJSON *thumbnail_url = cJSON_GetObjectItemCaseSensitive(inline_query_resultJSON, "thumbnail_url");
    if (cJSON_IsNull(thumbnail_url)) {
        thumbnail_url = NULL;
    }
    if (!thumbnail_url) {
        goto end;
    }

    
    if(!cJSON_IsString(thumbnail_url))
    {
    goto end; //String
    }

    // inline_query_result->audio_url
    cJSON *audio_url = cJSON_GetObjectItemCaseSensitive(inline_query_resultJSON, "audio_url");
    if (cJSON_IsNull(audio_url)) {
        audio_url = NULL;
    }
    if (!audio_url) {
        goto end;
    }

    
    if(!cJSON_IsString(audio_url))
    {
    goto end; //String
    }

    // inline_query_result->phone_number
    cJSON *phone_number = cJSON_GetObjectItemCaseSensitive(inline_query_resultJSON, "phone_number");
    if (cJSON_IsNull(phone_number)) {
        phone_number = NULL;
    }
    if (!phone_number) {
        goto end;
    }

    
    if(!cJSON_IsString(phone_number))
    {
    goto end; //String
    }

    // inline_query_result->first_name
    cJSON *first_name = cJSON_GetObjectItemCaseSensitive(inline_query_resultJSON, "first_name");
    if (cJSON_IsNull(first_name)) {
        first_name = NULL;
    }
    if (!first_name) {
        goto end;
    }

    
    if(!cJSON_IsString(first_name))
    {
    goto end; //String
    }

    // inline_query_result->game_short_name
    cJSON *game_short_name = cJSON_GetObjectItemCaseSensitive(inline_query_resultJSON, "game_short_name");
    if (cJSON_IsNull(game_short_name)) {
        game_short_name = NULL;
    }
    if (!game_short_name) {
        goto end;
    }

    
    if(!cJSON_IsString(game_short_name))
    {
    goto end; //String
    }

    // inline_query_result->document_url
    cJSON *document_url = cJSON_GetObjectItemCaseSensitive(inline_query_resultJSON, "document_url");
    if (cJSON_IsNull(document_url)) {
        document_url = NULL;
    }
    if (!document_url) {
        goto end;
    }

    
    if(!cJSON_IsString(document_url))
    {
    goto end; //String
    }

    // inline_query_result->mime_type
    cJSON *mime_type = cJSON_GetObjectItemCaseSensitive(inline_query_resultJSON, "mime_type");
    if (cJSON_IsNull(mime_type)) {
        mime_type = NULL;
    }
    if (!mime_type) {
        goto end;
    }

    telegram_bot_api_inline_query_result_MIMETYPE_e mime_typeVariable;
    
    if(!cJSON_IsString(mime_type))
    {
    goto end; //Enum
    }
    mime_typeVariable = inline_query_result_mime_type_FromString(mime_type->valuestring);

    // inline_query_result->gif_url
    cJSON *gif_url = cJSON_GetObjectItemCaseSensitive(inline_query_resultJSON, "gif_url");
    if (cJSON_IsNull(gif_url)) {
        gif_url = NULL;
    }
    if (!gif_url) {
        goto end;
    }

    
    if(!cJSON_IsString(gif_url))
    {
    goto end; //String
    }

    // inline_query_result->latitude
    cJSON *latitude = cJSON_GetObjectItemCaseSensitive(inline_query_resultJSON, "latitude");
    if (cJSON_IsNull(latitude)) {
        latitude = NULL;
    }
    if (!latitude) {
        goto end;
    }

    
    if(!cJSON_IsNumber(latitude))
    {
    goto end; //Numeric
    }

    // inline_query_result->longitude
    cJSON *longitude = cJSON_GetObjectItemCaseSensitive(inline_query_resultJSON, "longitude");
    if (cJSON_IsNull(longitude)) {
        longitude = NULL;
    }
    if (!longitude) {
        goto end;
    }

    
    if(!cJSON_IsNumber(longitude))
    {
    goto end; //Numeric
    }

    // inline_query_result->mpeg4_url
    cJSON *mpeg4_url = cJSON_GetObjectItemCaseSensitive(inline_query_resultJSON, "mpeg4_url");
    if (cJSON_IsNull(mpeg4_url)) {
        mpeg4_url = NULL;
    }
    if (!mpeg4_url) {
        goto end;
    }

    
    if(!cJSON_IsString(mpeg4_url))
    {
    goto end; //String
    }

    // inline_query_result->photo_url
    cJSON *photo_url = cJSON_GetObjectItemCaseSensitive(inline_query_resultJSON, "photo_url");
    if (cJSON_IsNull(photo_url)) {
        photo_url = NULL;
    }
    if (!photo_url) {
        goto end;
    }

    
    if(!cJSON_IsString(photo_url))
    {
    goto end; //String
    }

    // inline_query_result->address
    cJSON *address = cJSON_GetObjectItemCaseSensitive(inline_query_resultJSON, "address");
    if (cJSON_IsNull(address)) {
        address = NULL;
    }
    if (!address) {
        goto end;
    }

    
    if(!cJSON_IsString(address))
    {
    goto end; //String
    }

    // inline_query_result->video_url
    cJSON *video_url = cJSON_GetObjectItemCaseSensitive(inline_query_resultJSON, "video_url");
    if (cJSON_IsNull(video_url)) {
        video_url = NULL;
    }
    if (!video_url) {
        goto end;
    }

    
    if(!cJSON_IsString(video_url))
    {
    goto end; //String
    }

    // inline_query_result->voice_url
    cJSON *voice_url = cJSON_GetObjectItemCaseSensitive(inline_query_resultJSON, "voice_url");
    if (cJSON_IsNull(voice_url)) {
        voice_url = NULL;
    }
    if (!voice_url) {
        goto end;
    }

    
    if(!cJSON_IsString(voice_url))
    {
    goto end; //String
    }

    // inline_query_result->caption
    cJSON *caption = cJSON_GetObjectItemCaseSensitive(inline_query_resultJSON, "caption");
    if (cJSON_IsNull(caption)) {
        caption = NULL;
    }
    if (caption) { 
    if(!cJSON_IsString(caption) && !cJSON_IsNull(caption))
    {
    goto end; //String
    }
    }

    // inline_query_result->parse_mode
    cJSON *parse_mode = cJSON_GetObjectItemCaseSensitive(inline_query_resultJSON, "parse_mode");
    if (cJSON_IsNull(parse_mode)) {
        parse_mode = NULL;
    }
    if (parse_mode) { 
    if(!cJSON_IsString(parse_mode) && !cJSON_IsNull(parse_mode))
    {
    goto end; //String
    }
    }

    // inline_query_result->caption_entities
    cJSON *caption_entities = cJSON_GetObjectItemCaseSensitive(inline_query_resultJSON, "caption_entities");
    if (cJSON_IsNull(caption_entities)) {
        caption_entities = NULL;
    }
    if (caption_entities) { 
    cJSON *caption_entities_local_nonprimitive = NULL;
    if(!cJSON_IsArray(caption_entities)){
        goto end; //nonprimitive container
    }

    caption_entitiesList = list_createList();

    cJSON_ArrayForEach(caption_entities_local_nonprimitive,caption_entities )
    {
        if(!cJSON_IsObject(caption_entities_local_nonprimitive)){
            goto end;
        }
        message_entity_t *caption_entitiesItem = message_entity_parseFromJSON(caption_entities_local_nonprimitive);

        list_addElement(caption_entitiesList, caption_entitiesItem);
    }
    }

    // inline_query_result->reply_markup
    cJSON *reply_markup = cJSON_GetObjectItemCaseSensitive(inline_query_resultJSON, "reply_markup");
    if (cJSON_IsNull(reply_markup)) {
        reply_markup = NULL;
    }
    if (reply_markup) { 
    reply_markup_local_nonprim = inline_keyboard_markup_parseFromJSON(reply_markup); //nonprimitive
    }

    // inline_query_result->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(inline_query_resultJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (description) { 
    if(!cJSON_IsString(description) && !cJSON_IsNull(description))
    {
    goto end; //String
    }
    }

    // inline_query_result->show_caption_above_media
    cJSON *show_caption_above_media = cJSON_GetObjectItemCaseSensitive(inline_query_resultJSON, "show_caption_above_media");
    if (cJSON_IsNull(show_caption_above_media)) {
        show_caption_above_media = NULL;
    }
    if (show_caption_above_media) { 
    if(!cJSON_IsBool(show_caption_above_media))
    {
    goto end; //Bool
    }
    }

    // inline_query_result->url
    cJSON *url = cJSON_GetObjectItemCaseSensitive(inline_query_resultJSON, "url");
    if (cJSON_IsNull(url)) {
        url = NULL;
    }
    if (url) { 
    if(!cJSON_IsString(url) && !cJSON_IsNull(url))
    {
    goto end; //String
    }
    }

    // inline_query_result->thumbnail_width
    cJSON *thumbnail_width = cJSON_GetObjectItemCaseSensitive(inline_query_resultJSON, "thumbnail_width");
    if (cJSON_IsNull(thumbnail_width)) {
        thumbnail_width = NULL;
    }
    if (thumbnail_width) { 
    if(!cJSON_IsNumber(thumbnail_width))
    {
    goto end; //Numeric
    }
    }

    // inline_query_result->thumbnail_height
    cJSON *thumbnail_height = cJSON_GetObjectItemCaseSensitive(inline_query_resultJSON, "thumbnail_height");
    if (cJSON_IsNull(thumbnail_height)) {
        thumbnail_height = NULL;
    }
    if (thumbnail_height) { 
    if(!cJSON_IsNumber(thumbnail_height))
    {
    goto end; //Numeric
    }
    }

    // inline_query_result->performer
    cJSON *performer = cJSON_GetObjectItemCaseSensitive(inline_query_resultJSON, "performer");
    if (cJSON_IsNull(performer)) {
        performer = NULL;
    }
    if (performer) { 
    if(!cJSON_IsString(performer) && !cJSON_IsNull(performer))
    {
    goto end; //String
    }
    }

    // inline_query_result->audio_duration
    cJSON *audio_duration = cJSON_GetObjectItemCaseSensitive(inline_query_resultJSON, "audio_duration");
    if (cJSON_IsNull(audio_duration)) {
        audio_duration = NULL;
    }
    if (audio_duration) { 
    if(!cJSON_IsNumber(audio_duration))
    {
    goto end; //Numeric
    }
    }

    // inline_query_result->last_name
    cJSON *last_name = cJSON_GetObjectItemCaseSensitive(inline_query_resultJSON, "last_name");
    if (cJSON_IsNull(last_name)) {
        last_name = NULL;
    }
    if (last_name) { 
    if(!cJSON_IsString(last_name) && !cJSON_IsNull(last_name))
    {
    goto end; //String
    }
    }

    // inline_query_result->vcard
    cJSON *vcard = cJSON_GetObjectItemCaseSensitive(inline_query_resultJSON, "vcard");
    if (cJSON_IsNull(vcard)) {
        vcard = NULL;
    }
    if (vcard) { 
    if(!cJSON_IsString(vcard) && !cJSON_IsNull(vcard))
    {
    goto end; //String
    }
    }

    // inline_query_result->gif_width
    cJSON *gif_width = cJSON_GetObjectItemCaseSensitive(inline_query_resultJSON, "gif_width");
    if (cJSON_IsNull(gif_width)) {
        gif_width = NULL;
    }
    if (gif_width) { 
    if(!cJSON_IsNumber(gif_width))
    {
    goto end; //Numeric
    }
    }

    // inline_query_result->gif_height
    cJSON *gif_height = cJSON_GetObjectItemCaseSensitive(inline_query_resultJSON, "gif_height");
    if (cJSON_IsNull(gif_height)) {
        gif_height = NULL;
    }
    if (gif_height) { 
    if(!cJSON_IsNumber(gif_height))
    {
    goto end; //Numeric
    }
    }

    // inline_query_result->gif_duration
    cJSON *gif_duration = cJSON_GetObjectItemCaseSensitive(inline_query_resultJSON, "gif_duration");
    if (cJSON_IsNull(gif_duration)) {
        gif_duration = NULL;
    }
    if (gif_duration) { 
    if(!cJSON_IsNumber(gif_duration))
    {
    goto end; //Numeric
    }
    }

    // inline_query_result->thumbnail_mime_type
    cJSON *thumbnail_mime_type = cJSON_GetObjectItemCaseSensitive(inline_query_resultJSON, "thumbnail_mime_type");
    if (cJSON_IsNull(thumbnail_mime_type)) {
        thumbnail_mime_type = NULL;
    }
    telegram_bot_api_inline_query_result_THUMBNAILMIMETYPE_e thumbnail_mime_typeVariable;
    if (thumbnail_mime_type) { 
    if(!cJSON_IsString(thumbnail_mime_type))
    {
    goto end; //Enum
    }
    thumbnail_mime_typeVariable = inline_query_result_thumbnail_mime_type_FromString(thumbnail_mime_type->valuestring);
    }

    // inline_query_result->horizontal_accuracy
    cJSON *horizontal_accuracy = cJSON_GetObjectItemCaseSensitive(inline_query_resultJSON, "horizontal_accuracy");
    if (cJSON_IsNull(horizontal_accuracy)) {
        horizontal_accuracy = NULL;
    }
    if (horizontal_accuracy) { 
    if(!cJSON_IsNumber(horizontal_accuracy))
    {
    goto end; //Numeric
    }
    }

    // inline_query_result->live_period
    cJSON *live_period = cJSON_GetObjectItemCaseSensitive(inline_query_resultJSON, "live_period");
    if (cJSON_IsNull(live_period)) {
        live_period = NULL;
    }
    if (live_period) { 
    if(!cJSON_IsNumber(live_period))
    {
    goto end; //Numeric
    }
    }

    // inline_query_result->heading
    cJSON *heading = cJSON_GetObjectItemCaseSensitive(inline_query_resultJSON, "heading");
    if (cJSON_IsNull(heading)) {
        heading = NULL;
    }
    if (heading) { 
    if(!cJSON_IsNumber(heading))
    {
    goto end; //Numeric
    }
    }

    // inline_query_result->proximity_alert_radius
    cJSON *proximity_alert_radius = cJSON_GetObjectItemCaseSensitive(inline_query_resultJSON, "proximity_alert_radius");
    if (cJSON_IsNull(proximity_alert_radius)) {
        proximity_alert_radius = NULL;
    }
    if (proximity_alert_radius) { 
    if(!cJSON_IsNumber(proximity_alert_radius))
    {
    goto end; //Numeric
    }
    }

    // inline_query_result->mpeg4_width
    cJSON *mpeg4_width = cJSON_GetObjectItemCaseSensitive(inline_query_resultJSON, "mpeg4_width");
    if (cJSON_IsNull(mpeg4_width)) {
        mpeg4_width = NULL;
    }
    if (mpeg4_width) { 
    if(!cJSON_IsNumber(mpeg4_width))
    {
    goto end; //Numeric
    }
    }

    // inline_query_result->mpeg4_height
    cJSON *mpeg4_height = cJSON_GetObjectItemCaseSensitive(inline_query_resultJSON, "mpeg4_height");
    if (cJSON_IsNull(mpeg4_height)) {
        mpeg4_height = NULL;
    }
    if (mpeg4_height) { 
    if(!cJSON_IsNumber(mpeg4_height))
    {
    goto end; //Numeric
    }
    }

    // inline_query_result->mpeg4_duration
    cJSON *mpeg4_duration = cJSON_GetObjectItemCaseSensitive(inline_query_resultJSON, "mpeg4_duration");
    if (cJSON_IsNull(mpeg4_duration)) {
        mpeg4_duration = NULL;
    }
    if (mpeg4_duration) { 
    if(!cJSON_IsNumber(mpeg4_duration))
    {
    goto end; //Numeric
    }
    }

    // inline_query_result->photo_width
    cJSON *photo_width = cJSON_GetObjectItemCaseSensitive(inline_query_resultJSON, "photo_width");
    if (cJSON_IsNull(photo_width)) {
        photo_width = NULL;
    }
    if (photo_width) { 
    if(!cJSON_IsNumber(photo_width))
    {
    goto end; //Numeric
    }
    }

    // inline_query_result->photo_height
    cJSON *photo_height = cJSON_GetObjectItemCaseSensitive(inline_query_resultJSON, "photo_height");
    if (cJSON_IsNull(photo_height)) {
        photo_height = NULL;
    }
    if (photo_height) { 
    if(!cJSON_IsNumber(photo_height))
    {
    goto end; //Numeric
    }
    }

    // inline_query_result->foursquare_id
    cJSON *foursquare_id = cJSON_GetObjectItemCaseSensitive(inline_query_resultJSON, "foursquare_id");
    if (cJSON_IsNull(foursquare_id)) {
        foursquare_id = NULL;
    }
    if (foursquare_id) { 
    if(!cJSON_IsString(foursquare_id) && !cJSON_IsNull(foursquare_id))
    {
    goto end; //String
    }
    }

    // inline_query_result->foursquare_type
    cJSON *foursquare_type = cJSON_GetObjectItemCaseSensitive(inline_query_resultJSON, "foursquare_type");
    if (cJSON_IsNull(foursquare_type)) {
        foursquare_type = NULL;
    }
    if (foursquare_type) { 
    if(!cJSON_IsString(foursquare_type) && !cJSON_IsNull(foursquare_type))
    {
    goto end; //String
    }
    }

    // inline_query_result->google_place_id
    cJSON *google_place_id = cJSON_GetObjectItemCaseSensitive(inline_query_resultJSON, "google_place_id");
    if (cJSON_IsNull(google_place_id)) {
        google_place_id = NULL;
    }
    if (google_place_id) { 
    if(!cJSON_IsString(google_place_id) && !cJSON_IsNull(google_place_id))
    {
    goto end; //String
    }
    }

    // inline_query_result->google_place_type
    cJSON *google_place_type = cJSON_GetObjectItemCaseSensitive(inline_query_resultJSON, "google_place_type");
    if (cJSON_IsNull(google_place_type)) {
        google_place_type = NULL;
    }
    if (google_place_type) { 
    if(!cJSON_IsString(google_place_type) && !cJSON_IsNull(google_place_type))
    {
    goto end; //String
    }
    }

    // inline_query_result->video_width
    cJSON *video_width = cJSON_GetObjectItemCaseSensitive(inline_query_resultJSON, "video_width");
    if (cJSON_IsNull(video_width)) {
        video_width = NULL;
    }
    if (video_width) { 
    if(!cJSON_IsNumber(video_width))
    {
    goto end; //Numeric
    }
    }

    // inline_query_result->video_height
    cJSON *video_height = cJSON_GetObjectItemCaseSensitive(inline_query_resultJSON, "video_height");
    if (cJSON_IsNull(video_height)) {
        video_height = NULL;
    }
    if (video_height) { 
    if(!cJSON_IsNumber(video_height))
    {
    goto end; //Numeric
    }
    }

    // inline_query_result->video_duration
    cJSON *video_duration = cJSON_GetObjectItemCaseSensitive(inline_query_resultJSON, "video_duration");
    if (cJSON_IsNull(video_duration)) {
        video_duration = NULL;
    }
    if (video_duration) { 
    if(!cJSON_IsNumber(video_duration))
    {
    goto end; //Numeric
    }
    }

    // inline_query_result->voice_duration
    cJSON *voice_duration = cJSON_GetObjectItemCaseSensitive(inline_query_resultJSON, "voice_duration");
    if (cJSON_IsNull(voice_duration)) {
        voice_duration = NULL;
    }
    if (voice_duration) { 
    if(!cJSON_IsNumber(voice_duration))
    {
    goto end; //Numeric
    }
    }


    inline_query_result_local_var = inline_query_result_create_internal (
        strdup(type->valuestring),
        strdup(id->valuestring),
        strdup(audio_file_id->valuestring),
        input_message_content_local_nonprim,
        strdup(title->valuestring),
        strdup(document_file_id->valuestring),
        strdup(gif_file_id->valuestring),
        strdup(mpeg4_file_id->valuestring),
        strdup(photo_file_id->valuestring),
        strdup(sticker_file_id->valuestring),
        strdup(video_file_id->valuestring),
        strdup(voice_file_id->valuestring),
        strdup(thumbnail_url->valuestring),
        strdup(audio_url->valuestring),
        strdup(phone_number->valuestring),
        strdup(first_name->valuestring),
        strdup(game_short_name->valuestring),
        strdup(document_url->valuestring),
        mime_typeVariable,
        strdup(gif_url->valuestring),
        latitude->valuedouble,
        longitude->valuedouble,
        strdup(mpeg4_url->valuestring),
        strdup(photo_url->valuestring),
        strdup(address->valuestring),
        strdup(video_url->valuestring),
        strdup(voice_url->valuestring),
        caption && !cJSON_IsNull(caption) ? strdup(caption->valuestring) : NULL,
        parse_mode && !cJSON_IsNull(parse_mode) ? strdup(parse_mode->valuestring) : NULL,
        caption_entities ? caption_entitiesList : NULL,
        reply_markup ? reply_markup_local_nonprim : NULL,
        description && !cJSON_IsNull(description) ? strdup(description->valuestring) : NULL,
        show_caption_above_media ? show_caption_above_media->valueint : 0,
        url && !cJSON_IsNull(url) ? strdup(url->valuestring) : NULL,
        thumbnail_width ? thumbnail_width->valuedouble : 0,
        thumbnail_height ? thumbnail_height->valuedouble : 0,
        performer && !cJSON_IsNull(performer) ? strdup(performer->valuestring) : NULL,
        audio_duration ? audio_duration->valuedouble : 0,
        last_name && !cJSON_IsNull(last_name) ? strdup(last_name->valuestring) : NULL,
        vcard && !cJSON_IsNull(vcard) ? strdup(vcard->valuestring) : NULL,
        gif_width ? gif_width->valuedouble : 0,
        gif_height ? gif_height->valuedouble : 0,
        gif_duration ? gif_duration->valuedouble : 0,
        thumbnail_mime_type ? thumbnail_mime_typeVariable : telegram_bot_api_inline_query_result_THUMBNAILMIMETYPE_NULL,
        horizontal_accuracy ? horizontal_accuracy->valuedouble : 0,
        live_period ? live_period->valuedouble : 0,
        heading ? heading->valuedouble : 0,
        proximity_alert_radius ? proximity_alert_radius->valuedouble : 0,
        mpeg4_width ? mpeg4_width->valuedouble : 0,
        mpeg4_height ? mpeg4_height->valuedouble : 0,
        mpeg4_duration ? mpeg4_duration->valuedouble : 0,
        photo_width ? photo_width->valuedouble : 0,
        photo_height ? photo_height->valuedouble : 0,
        foursquare_id && !cJSON_IsNull(foursquare_id) ? strdup(foursquare_id->valuestring) : NULL,
        foursquare_type && !cJSON_IsNull(foursquare_type) ? strdup(foursquare_type->valuestring) : NULL,
        google_place_id && !cJSON_IsNull(google_place_id) ? strdup(google_place_id->valuestring) : NULL,
        google_place_type && !cJSON_IsNull(google_place_type) ? strdup(google_place_type->valuestring) : NULL,
        video_width ? video_width->valuedouble : 0,
        video_height ? video_height->valuedouble : 0,
        video_duration ? video_duration->valuedouble : 0,
        voice_duration ? voice_duration->valuedouble : 0
        );

    return inline_query_result_local_var;
end:
    if (input_message_content_local_nonprim) {
        input_message_content_free(input_message_content_local_nonprim);
        input_message_content_local_nonprim = NULL;
    }
    if (caption_entitiesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, caption_entitiesList) {
            message_entity_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(caption_entitiesList);
        caption_entitiesList = NULL;
    }
    if (reply_markup_local_nonprim) {
        inline_keyboard_markup_free(reply_markup_local_nonprim);
        reply_markup_local_nonprim = NULL;
    }
    return NULL;

}
