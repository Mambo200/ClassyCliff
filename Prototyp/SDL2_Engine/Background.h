#pragma once
#include "MoveObject.h"
class GBackground :
	public CMoveObject
{
public:
	GBackground();
	~GBackground();

	static void CreateWalls(int _world, int _position);
	static void GenerateBackgorund(int _world);
	static void LoadTexture1(int _world);
	static void LoadTexture2(int _world);
	static void LoadTexture3(int _world);
	static void LoadTexture4(int _world);
	static void LoadLeftWall(int _world, int _position);
	static void LoadRightWall(int _world, int _position);


private:

};

