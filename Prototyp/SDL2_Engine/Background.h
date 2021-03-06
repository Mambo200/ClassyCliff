#pragma once
#include "MoveObject.h"
#include "Macro.h"
#include "ContentManagement.h"
#include "Engine.h"
class GBackground :
	public CObject
{
public:
	GBackground();
	~GBackground()
	{
	}
	/// <summary>
	/// create left and right wall
	/// </summary>
	/// <param name="_world">number how close the walls are</param>
	/// <param name="_position">position of texture</param>
	static void CreateWalls(int _world, int _position);

	/// <summary>
	/// create complete background
	/// </summary>
	/// <param name="_world">position of texture</param>
	static void GenerateBackgorund(int _world);

	/// <summary>
	/// create background 1
	/// </summary>
	/// <param name="_world">position of texture</param>
	static void LoadTexture1(int _world);

	/// <summary>
	/// create background 2
	/// </summary>
	/// <param name="_world">position of texture</param>
	static void LoadTexture2(int _world);

	/// <summary>
	/// create background 3
	/// </summary>
	/// <param name="_world">position of texture</param>
	static void LoadTexture3(int _world);

	/// <summary>
	/// create background 4
	/// </summary>
	/// <param name="_world">position of texture</param>
	static void LoadTexture4(int _world);

	/// <summary>
	/// create background 1
	/// </summary>
	/// <param name="_world">position of texture</param>
	static void LoadBackground1(int _pos);

	/// <summary>
	/// create background 2
	/// </summary>
	/// <param name="_world">position of texture</param>
	static void LoadBackground2(int _pos);

	/// <summary>
	/// create background 3
	/// </summary>
	/// <param name="_world">position of texture</param>
	static void LoadBackground3(int _pos);

	/// <summary>
	/// create background 4
	/// </summary>
	/// <param name="_world">position of texture</param>
	static void LoadBackground4(int _pos);

	/// <summary>
	/// create left wall
	/// </summary>
	/// <param name="_world">number how close the walls are</param>
	/// <param name="_position">position of texture</param>
	static void LoadLeftWall(int _world, int _position);

	/// <summary>
	/// create right wall
	/// </summary>
	/// <param name="_world">number how close the walls are</param>
	/// <param name="_position">position of texture</param>
	static void LoadRightWall(int _world, int _position);

	static void Ground();

	/// <summary>
	/// get number of how close the walls are
	/// </summary>
	/// <returns>number of how close the walls are</returns>
	static int GetCollisionWallDistance() { return m_backGround; }
	static void SetCollisionWallDistance(int _distance) { m_backGround = _distance; }

	static int GetPositionOfTexture() { return m_afterFifty; }
	static void SetPositionOfTexture(int _position) { m_afterFifty = _position; }

	private:

	/// <summary>
	/// how close the walls are
	/// </summary>
	static int m_backGround;

	/// <summary>
	/// position of texture
	/// </summary>
	static int m_afterFifty;

};

