#ifndef __j1MAP_H__
#define __j1MAP_H__

#include "PugiXml/src/pugixml.hpp"
#include "p2List.h"
#include "p2Point.h"
#include "j1Module.h"

// TODO 2: Create a struct to hold information for a TileSet
// Ignore Terrain Types and Tile Types for now, but we want the image!
// ----------------------------------------------------
struct TileSet {

	p2SString name;

	int firstgid = 0;

	uint tileWidth = 0u;
	uint tileHeight = 0u;

	int spacing = 0;
	int margin = 0;

	SDL_Texture* source;
};

// TODO 1: Create a struct needed to hold the information to Map node

enum Orientation
{
	OR_INVALID, // OLDSCHOOL WAY TO PUT SAME NAME IN SAME WORKSPACE, PUT NOMENCLATURE BEFORE EVERY NAME.
	OR_ORTHOGONAL,
	OR_ISOMETRIC,
	OR_STAGGERED,
	OR_HEXAGONAL
};

enum class RenderOrder
{
	INVALID,
	RIGHT_DOWN,
	RIGHT_UP,
	LEFT_DOWN,
	LEFT_UP
};

struct MapLayer
{

	p2SString name;

	int firstgid = 0;

	enum Orientation mapOrientation = OR_INVALID; // INITIALIZE WITH THE ERROR TO ALWAYS KNOW IF THE CODE WORKS OR NOT.
	enum RenderOrder order = RenderOrder::INVALID; // IF YOU MADE AN ENUM CLASS, YOU HAVE TO ACTUALLY WRITE THE CLASS THEN :: AND W/E ATTRIBUTE YOU WANT.

	uint width = 0u; //INITIALIZE WITH 0 TO ALWAYS KNOW IF THE CODE WORKS OR NOT.
	uint height = 0u;

	uint tileWidth = 0u; // PUT A u AFTER THE 0 SO THE COMPILER DOES NOT STORE THE 0 AS INT AND THEN TRANSFORM IT TO UINT.
	uint tileHeight = 0u;

};

// ----------------------------------------------------
class j1Map : public j1Module
{
public:

	j1Map();

	// Destructor
	virtual ~j1Map();

	// Called before render is available
	bool Awake(pugi::xml_node& conf);

	// Called each loop iteration
	void Draw();

	// Called before quitting
	bool CleanUp();

	// Load new map
	bool Load(const char* path);

private:

	bool LoadMap();

public:

	// TODO 1: Add your struct for map info as public for now
	MapLayer data;

private:

	pugi::xml_document	map_file;
	p2SString			folder;
	bool				map_loaded;
};

#endif // __j1MAP_H__