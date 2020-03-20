#include "j1Player.h"
#include "j1Minimap.h"
#include "j1Input.h"
#include "j1App.h"
#include "p2Log.h"
#include "j1Render.h"

j1Player::j1Player() {}

j1Player::~j1Player(){}

bool j1Player::PreUpdate() {
	bool ret = true;
	int mouse_x, mouse_y;

	//TODO 7: Move the camera when the player clicks on the minimap or scrolls the mouse on it while holding the left button
	if ((App->input->GetMouseButtonDown(SDL_BUTTON_LEFT) == KEY_DOWN)|| (App->input->GetMouseButtonDown(SDL_BUTTON_LEFT) == KEY_REPEAT))
	{
		App->input->GetMousePosition(mouse_x, mouse_y);
		SDL_Rect minimap = { App->minimap->position.x, App->minimap->position.y, App->minimap->width, App->minimap->height };

		if ((mouse_x > minimap.x) && (mouse_x < minimap.x + minimap.w) && (mouse_y > minimap.y) && (mouse_y < minimap.y + minimap.h))
		{
		//TODO 6: Use the function created in the previous TODO to transform the position of the mouse into Minimap coordinates and then to the world
		iPoint minimap_mouse_position;
		minimap_mouse_position = App->minimap->ScreenToMinimap(mouse_x, mouse_y);
		//LOG("Minimap position: x: %i y: %i", minimap_mouse_position.x, minimap_mouse_position.y);
		App->render->camera.x = -(minimap_mouse_position.x - App->render->camera.w * 0.5f);
		App->render->camera.y = -(minimap_mouse_position.y - App->render->camera.h * 0.5f);
		}
	}

	return ret;
}