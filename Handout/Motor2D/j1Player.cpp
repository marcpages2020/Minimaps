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

	if ((App->input->GetMouseButtonDown(SDL_BUTTON_LEFT) == KEY_DOWN)|| (App->input->GetMouseButtonDown(SDL_BUTTON_LEFT) == KEY_REPEAT))
	{
		App->input->GetMousePosition(mouse_x, mouse_y);
		SDL_Rect minimap = { App->minimap->position.x, App->minimap->position.y, App->minimap->width, App->minimap->height };

		if ((mouse_x > minimap.x) && (mouse_x < minimap.x + minimap.w) && (mouse_y > minimap.y) && (mouse_y < minimap.y + minimap.h))
		{
		App->input->GetMousePosition(mouse_x, mouse_y);
		SDL_Rect minimap = { App->minimap->position.x, App->minimap->position.y, App->minimap->width, App->minimap->height };

		iPoint minimap_mouse_position;
		//minimap_mouse_position = App->minimap->WorldToMinimap(mouse_x, mouse_y);
		//minimap_mouse_position = App->minimap->MinimapToWorld(minimap_mouse_position.x, minimap_mouse_position.x);
		minimap_mouse_position = App->minimap->ScreenToMinimap(mouse_x, mouse_y);
		LOG("Minimap position: x: %i y: %i", minimap_mouse_position.x, minimap_mouse_position.y);

		App->render->camera.x = -(minimap_mouse_position.x - App->render->camera.w * 0.5f);
		App->render->camera.y = -(minimap_mouse_position.y - App->render->camera.h * 0.5f);

		}
	}

	/*
	if (App->input->GetMouseButtonDown(SDL_BUTTON_LEFT) == KEY_REPEAT)
	{
		App->input->GetMousePosition(mouse_x, mouse_y);
		SDL_Rect minimap = {App->minimap->position.x, App->minimap->position.y, App->minimap->width, App->minimap->height};

		//if the mouse is inside the minimap
		if ((mouse_x > minimap.x)&&(mouse_x < minimap.x + minimap.w)&&(mouse_y > minimap.y)&&(mouse_y < minimap.y + minimap.h))
		{
			int mouse_motion_x, mouse_motion_y;
			int map_speed = 3;
			App->input->GetMouseMotion(mouse_motion_x, mouse_motion_y);
			App->render->camera.x -= floor(map_speed * mouse_motion_x);
			App->render->camera.y -= floor(map_speed * mouse_motion_y);
		}
	}
	*/
	return ret;
}