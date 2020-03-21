#include "j1Minimap.h"
#include "j1Map.h"
#include "j1App.h"
#include "j1Textures.h"
#include "j1Scene.h"
#include "j1Window.h"
#include "j1Render.h"
#include "p2Log.h"

j1Minimap::j1Minimap() : j1Module() {
	name.create("minimap");

	texture = nullptr;
	height = 100;
	width = 200;
	map_height = 200;
	scale = 1;
	width = 100;
	margin = 0;
	corner = Corner::TOP_LEFT;
	minimap_test_rect = { 0,0,4,4 };
}

j1Minimap::~j1Minimap() {
}

bool j1Minimap::Awake(pugi::xml_node& config) {
	uint window_width, window_height;

	//TODO 0: Take into account for the next TODO that the minimap widht is set in config
	width = config.attribute("width").as_int();

	//corner
	p2SString corner_string(config.attribute("corner").as_string());
	margin = config.attribute("margin").as_int();

	if (corner_string == "top_left") {
		corner = Corner::TOP_LEFT;
	}
	else if (corner_string == "top_right") {
		corner = Corner::TOP_RIGHT;
	}
	else if (corner_string == "bottom_left") {
		corner = Corner::BOTTOM_LEFT;
	}
	else if (corner_string == "bottom_right") {
		corner = Corner::BOTTOM_RIGHT;
	}

	return true;
}

bool j1Minimap::Start() {
	bool ret = true;
	uint window_width, window_height;
	App->win->GetWindowSize(window_width, window_height);

	//TODO 1: Calculate the dimensions of the minimap

	//TODO 2: Create a texture for the minimap
	
	//TODO 3: Set this texture as a rendering target and create the minimap

	//calculate position depending on the chosen corner
	switch (corner)
	{
	case Corner::TOP_LEFT:
		position.x = margin;
		position.y = margin;
		break;
	case Corner::TOP_RIGHT:
		position.x = window_width - width - margin;
		position.y = margin;
		break;
	case Corner::BOTTOM_LEFT:
		position.x = margin;
		position.y = window_height - height - margin;
		break;
	case Corner::BOTTOM_RIGHT:
		position.x = window_width - width - margin;
		position.y = window_height - height - margin;
		break;
	}

	return ret;
}

bool j1Minimap::PostUpdate() {

	//TODO 3: When you have the texture try blitting it on screen
	
	//TODO 4.1: Fill the function WorldToMinimap to make the representation of the rect in the minimap be in the position it should 

	//TODO 4.2: Using WorldToMinimap create a white rect which represents the area that the camera records of the world onto the minimap 

	return true;
}

bool j1Minimap::CreateMinimap() {

	PERF_START(ptimer);
	p2List_item<MapLayer*>* item = App->map->data.layers.start;

	for (; item != NULL; item = item->next)
	{
		MapLayer* layer = item->data;

		if (layer->properties.Get("Nodraw") != 0)
			continue;

		int half_width = map_width * 0.5f;

		for (int y = 0; y < App->map->data.height; ++y)
		{
			for (int x = 0; x < App->map->data.width; ++x)
			{
				int tile_id = layer->Get(x, y);
				if (tile_id > 0)
				{
					TileSet* tileset = App->map->GetTilesetFromTileId(tile_id);

					SDL_Rect r = tileset->GetTileRect(tile_id);
					iPoint pos = App->map->MapToWorld(x, y);
					pos = App->render->WorldToScreen(pos.x, pos.y);

					App->render->Blit(tileset->texture, pos.x + half_width, pos.y, &r, scale);
				}
			}
		}
	}
	PERF_PEEK(ptimer);

	return true;
}

iPoint j1Minimap::WorldToMinimap(int x, int y) {
	//TODO 4.1: Fill this function
	iPoint minimap_position = {0,0};
	return minimap_position;
}

iPoint j1Minimap::ScreenToMinimapToWorld(int x, int y) {
	//TODO 5: Fill this function to convert a position from screen to the Minimap and directly to world
	iPoint minimap_position = {0,0};
	return minimap_position;
}