#include "j1Minimap.h"
#include "j1Map.h"

j1Minimap::j1Minimap() : j1Module() {
	name.create("minimap");
}

j1Minimap::~j1Minimap() {
}

bool j1Minimap::Awake(pugi::xml_node& config) {
	//scale
	width = config.attribute("width").as_int();
	//minimap.scale = (minimap_width / (data.tile_width * data.width));

	//corner
	p2SString corner_string(config.attribute("corner").as_string());

	if (corner_string == "top_left") corner = Corner::TOP_LEFT;
	else if (corner_string == "top_right") corner = Corner::TOP_RIGHT;
	else if (corner_string == "bottom_left") corner = Corner::BOTTOM_LEFT;
	else if (corner_string == "bottom_right") corner = Corner::BOTTOM_RIGHT;

	margin.y = config.attribute("margin").as_int();

	return true;
}

bool j1Minimap::Start() {
	return true;
}
