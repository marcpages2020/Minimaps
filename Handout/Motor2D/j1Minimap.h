#ifndef _j1MINIMAP_H
#define _j1MINIMAP_H
#include "j1Module.h"
#include "p2Point.h"
#include "SDL/include/SDL.h"

enum class Corner {
	TOP_LEFT,
	TOP_RIGHT,
	BOTTOM_LEFT,
	BOTTOM_RIGHT
};

class j1Minimap : public j1Module {
public:
	j1Minimap();
	~j1Minimap();

	bool Start();
	bool Awake(pugi::xml_node& config);
	bool CreateMinimap();
	bool PostUpdate();
private:
	SDL_Texture* minimap_texture;
	SDL_Texture* texture;
	SDL_Surface* map_surface;
	SDL_Renderer* map_renderer;

	float scale;
	int width;
	int height;
	iPoint position;
	int margin;
	Corner corner;
};

#endif // !_j1MINIMAP_H


