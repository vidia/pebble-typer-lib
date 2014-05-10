libtyper
=========

A simple library to create a typing animation on the pebble.

## Usage

To use this library, copy the typer.c and typer.h files into your pebble src folder.

### Functions 

/**
 * Initialize a typer struct that will hold the data of a given typing animation
 * effect. 
 *
 * Warning: The struct created by this function must be free'd by a call to destroy_typer. 
 *
 * text: The text that will be typed onto the screen
 * tl: The text layer that will hold the typing text
 * time: The time (in ms) between "keystrokes" 
 * onFinish: A callback function that is called upon completion of the typing. 
 * start_index: The character of the text to begin the animation on. 
 */
struct typer_data *init_typer(char* text, TextLayer* tl, int time, void (*onFinish)(), int start_index);

/*
 * Frees the data for the given typer_data struct. 
 *
 * Must call this function for every struct created with init_typer. 
 * 
 * data: The struct that will be free'd.
 */
void destroy_typer(struct typer_data* data);

/*
 * Begins the typing animation that is represented by the given data struct. 
 *
 * data: The animation to start.
 */
void typeTextInTextLayer(void *data);

/*
 * Stops a running animation. 
 *
 * data: The animation that should be stopped. 
 */
void typer_cancel(struct typer_data* data);

