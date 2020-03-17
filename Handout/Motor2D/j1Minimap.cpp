#include "j1Minimap.h"
#include "j1Map.h"
#include "j1App.h"
#include "j1Textures.h"
#include "j1Scene.h"
#include "j1Window.h"
#include "j1Render.h"

j1Minimap::j1Minimap() : j1Module() {
	name.create("minimap");

	texture = nullptr;
	surface = nullptr;
	map_renderer = nullptr;

	scale = 1;
	width = 100;
	margin = 0;
	corner = Corner::TOP_LEFT;
}

j1Minimap::~j1Minimap() {
}

bool j1Minimap::Awake(pugi::xml_node& config) {
	uint window_width, window_height;
	//scale
	width = config.attribute("width").as_int();

	//corner
	p2SString corner_string(config.attribute("corner").as_string());
	margin = config.attribute("margin").as_int();

	if (corner_string == "top_left") {
		corner = Corner::TOP_LEFT;
		position.x = margin;
		position.y = margin;
	}
	else if (corner_string == "top_right") {
		corner = Corner::TOP_RIGHT;
		App->win->GetWindowSize(window_width, window_height);
		position.x = window_width - margin;
		position.y = margin;
	}
	else if (corner_string == "bottom_left") {
		corner = Corner::BOTTOM_LEFT;
		App->win->GetWindowSize(window_width, window_height);
		position.x = margin;
		position.y = window_height - margin;
	}
	else if (corner_string == "bottom_right") {
		corner = Corner::BOTTOM_RIGHT;
		App->win->GetWindowSize(window_width, window_height);
		position.x = window_width - margin;
		position.y = window_height - margin;
	}

	return true;
}

bool j1Minimap::Start() {
	bool ret = true;
	width = 300;
	map_width = App->map->data.tile_width * App->map->data.width;
	map_height = App->map->data.tile_height * App->map->data.height;
	scale = ((width) / ((float)map_width));
	height = (map_height) * scale;

	surface = SDL_CreateRGBSurface(0, width, height, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
	//texture = App->tex->Load("maps/isometric_grass_and_water.png");

	texture = SDL_CreateTexture(App->render->renderer, SDL_GetWindowPixelFormat(App->win->window), SDL_TEXTUREACCESS_TARGET,1.05f * width, 1.05f *height);
	SDL_SetRenderTarget(App->render->renderer, texture);
	CreateMinimap();
	//texture = SDL_CreateTextureFromSurface(App->render->renderer, surface);
	SDL_SetRenderTarget(App->render->renderer, NULL);

	return ret;
}

bool j1Minimap::CreateMinimap() {

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

					App->render->Blit(tileset->texture, pos.x + half_width, pos.y, &r,scale);
				}
			}
		}
	}
	return true;
}

bool j1Minimap::PostUpdate() {
	App->render->Blit(texture, position.x, position.y, NULL, 1.0, 0);
	return true;
}
