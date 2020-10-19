#include "Button.h"
#include "Src/Engine/Engine.h"

Vec2 Position(100.0f, 100.0f);


Button g_Button;

bool UpdateButton()
{
	Vec2 Pos = Engine::GetMousePos();
	Size Button_Size = Size(256.0f, 128.0f);

	// 点が矩形の中にあるかチェック
	if (Position.X <= Pos.X && 
		Position.X + Button_Size.Width >= Pos.X && 
		Position.Y <= Pos.Y && Position.Y && 
		Position.Y +  Button_Size.Height >= Pos.Y)
	{
		//IsActive = false;
		g_Button = Button::Button001;
	}
	else
	{
		/*IsActive = true;*/
		g_Button = Button::Button002;

	}



	return false;

	
}

void Drow()
{

	

	switch (g_Button)
	{
	case Button::Button001:Engine::DrawTextureUV(Position.X, Position.Y, "Button", 256.0f, 0.0f, 256.0f, 128.0f, 255, 0.0f);
		break;

	case Button::Button002:Engine::DrawTextureUV(Position.X, Position.Y, "Button", 0.0f, 0.0f, 256.0f, 128.0f, 255, 0.0f);
		break;

	case Button::Button003:Engine::DrawTextureUV(Position.X, Position.Y, "Button", 256.0f, 128.0f, 256.0f, 128.0f, 255, 0.0f);
		break;
	
	}
	/*if (IsActive == false)
	{
		Engine::DrawTextureUV(Position.X, Position.Y, "Button", 256.0f, 0.0f, 256.0f, 128.0f, 255, 0.0f);
	}*/
	/*if (IsActive == true)
	{
		Engine::DrawTextureUV(Position.X, Position.Y, "Button", 0.0f, 0.0f, 256.0f, 128.0f, 255, 0.0f);
	}*/
	
	
}