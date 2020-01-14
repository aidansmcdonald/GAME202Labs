/*
Name: Aidan McDonald
Course: O.O.P.
prof: Majid Moghadam
Title of Program: Game Programming
Date: 1/13/20
*/


// include SDL functions and datatypes for the program to use
#include "SDL.h"

// Initializing the attributes of the screen/window
#define WINDOW_WIDTH	800
#define WINDOW_HEIGHT	600

// Create SDL renderer
SDL_Renderer *renderer;

// Tell SDL to beging recording events
SDL_Event event;

// Mouse coordinates;
int mouse_x, mouse_y;

// Initialize game status to on
bool running = true;

// Create 4 rectagles called player paddle, AI paddle, ball, and halfline using SDL_Rect
SDL_Rect PlayerPaddle;
SDL_Rect AIPaddle;
SDL_Rect Ball;
SDL_Rect HalfLine;

/*
Purpose of the LoadGame function: Load all game objects/assets, windows etc.
*/
void LoadGame()
{
	// Create a window named window
	SDL_Window *window;

	// Set window attributes
	window = SDL_CreateWindow("Basic SDL Sprites",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		WINDOW_WIDTH, WINDOW_HEIGHT,
		SDL_WINDOW_SHOWN);
	if (!window) {
		return;
	}

	//
	renderer = SDL_CreateRenderer(window, -1, 0);
	if (!renderer) {
		return;
	}

	// Initializing the location and size of the PlayerPaddle rectangle
	PlayerPaddle.x = 20;
	PlayerPaddle.y = 250;
	PlayerPaddle.h = 100;
	PlayerPaddle.w = 20;

	// Initializing the location and size of the AIPaddle rectangle
	AIPaddle.x = 760;
	AIPaddle.y = 250;
	AIPaddle.h = 100;
	AIPaddle.w = 20;

	// Initializing the location and size of the Ball rectangle
	Ball.x = 370;
	Ball.y = 290;
	Ball.w = 20;
	Ball.h = 20;

	// Initializing the location and size of the HalfLine rectangle
	HalfLine.x = 395;
	HalfLine.y = 0;
	HalfLine.w = 10;
	HalfLine.h = 600;
}

/*
Purpose of the Input() function: Capture the users input
*/
void Input() {
	
	//Queuing events
	while (SDL_PollEvent(&event)) {

		// Track mouse movement
		if (event.type == SDL_MOUSEMOTION)
			SDL_GetMouseState(&mouse_x, &mouse_y);

		// Clicking 'x' or pressing F4
		if (event.type == SDL_QUIT)
			running = false;

		// Pressing a key
		if (event.type == SDL_KEYDOWN)
			switch (event.key.keysym.sym)
			{

				//Pressing ESC exits from the game
			case SDLK_ESCAPE:
				running = false;
				break;

			}
	}
}

/*
Purpose of the Update() function: Update assets based on input and events
*/
void Update()
{
	PlayerPaddle.y = mouse_y;

	Ball.x += 1;
	Ball.y += 1;

	SDL_Delay(10);
}

/*
Purpose of the DrawScreen function: This function repeatedly draws the game objects
*/
void DrawScreen()
{
	//clears screen
	SDL_RenderClear(renderer);

	// Colors the background
	SDL_Rect background = { 0, 0, 800, 600 };
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderFillRect(renderer, &background);

	// Colors Paddles
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &PlayerPaddle);
	SDL_RenderFillRect(renderer, &AIPaddle);

	// Colors Ball
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(renderer, &Ball);

	// Colors HalfLine
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &HalfLine);

	// Display final drawing
	SDL_RenderPresent(renderer);
}

	/*
	Purpose of the Quit() function: To quit SDL
	*/
	void Quit()
	{
		//
		SDL_Quit();
	}

	/*
	Purpose of the Main() function: To run all of the games functions
	*/
	int main(int argc, char *argv[])
	{
		// Call LoadGame function
		LoadGame();

		// While game is set to running...
		while (running == true)
		{
			Input();		// Call Input funtion
			Update();		// Call Update function
			DrawScreen();	// Call DrawScreen function
		}

		// Quit
		Quit();

		return 0;
	}
