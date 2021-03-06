#include <pebble.h>
#include "typer.h"

static Window *window;
static TextLayer *text_layer;


static void animFinished()
{
  app_log(APP_LOG_LEVEL_DEBUG, "file.c", 10, "%s", "Finished");

}

static void window_load(Window *window) {
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);

  text_layer = text_layer_create((GRect) { .origin = { 0, 72 }, .size = { bounds.size.w, 60 } });
  //text_layer_set_text(text_layer, "Press a button");
  text_layer_set_text_alignment(text_layer, GTextAlignmentCenter);
  layer_add_child(window_layer, text_layer_get_layer(text_layer));

  struct typer_data * data = init_typer("This text is being\ntyped by the pebble\ntyping library\n--by David.", text_layer, 200, animFinished, 0); 
  typeTextInTextLayer((void*) data);
}


static void window_unload(Window *window) {
  text_layer_destroy(text_layer);
}

static void init(void) {
  window = window_create();
  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
  const bool animated = true;
  window_stack_push(window, animated);
}

static void deinit(void) {
  window_destroy(window);
}

int main(void) {
  init();

  APP_LOG(APP_LOG_LEVEL_DEBUG, "Done initializing, pushed window: %p", window);

  app_event_loop();
  deinit();
}
