#include "GameScene.h"
#include "Scene.h"
#include "Src/Engine/Engine.h"

extern SceneKind g_CurrentSceneKind;
extern SceneStep g_CurrentSceneStep;

void InitGameScene();
void RunGameScene();
void FinishGameScene();

extern SceneKind g_CurrentSceneKind;
extern SceneStep g_CurrentSceneStep;

GameFadeControl g_GameFadeControl;

Vec2 tex_Pos;
Vec2 chip_size(64.0f, 64.0f);
Vec2 Pos;



int map_date[5][5] =
{
	{1,5,1,1,1},
	{1,1,1,1,1},
	{2,1,1,1,1},
	{2,1,1,1,1},
	{2,1,1,1,1},

};



void InitGameScene()
{
	g_GameFadeControl.alpha = 255;
	g_GameFadeControl.FadeControl01 = false;
	
	//Engine::DrawFont(200.0f, 200.0f, "ゲームシーン", Regular, White);

	g_CurrentSceneStep = SceneStep::Run;
}

float max = 1800.0f;
float min = 0.0f;
float current = 0.0f;
float ratio;


void RunGameScene()
{

	
	/*Engine::LoadTexture("Slider01", "Res/Slider01.png");

	current++;
	ratio = (current - min) / (max - min);

	if (current >= 1800.0f)
	{
		current = 0;
	}

	Engine::DrawRect(0.0f, 450.0f, 640.0f, 480.0f, 0xaaaaaa, 100);

	Engine::DrawTextureUV(0.0f, 450.0f, "Slider01", 0.0f, 0.0f, 385.0f * ratio, 60.0f, 255, 0.0f, 1.66f, 1.0f);*/

	//(現在値－最小値)/(最大値-最小値)
	//float current = 0.0f;
	//float max = 1800.0f;
	//float min = 0.0f;
	//float ratio;

	current++;
	ratio = (current - min) / (max - min);
	if (current >= 1800.0f)
	{
		current = 0.0f;
	}


	//Engine::LoadTexture("map", "Res/MapChip.png");
	Engine::LoadTexture("Slider01", "Res/Slider01.png");
	Engine::DrawRect(0.0f, 0.0f, 384.0f, 64.0f, 0xffffff, 125);
	Engine::DrawTextureUV(0.0f, 0.0f, "Slider01", 0.0f, 0.0f, 384.0f * ratio, 64.0f, 255, 0.0f);
	//Engine::DrawTexture(0.0f, 0.0f, "Slider01", 255, 0.0f, 1.0f * ratio, 1.0f);
	
	//Engine::DrawTextureUV(0.0f, 0.0f, "map", 320.0f, 0.0f, map * 1, 64.0f, 255, 0.0f);
	
	

	/*for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			tex_Pos.X = map_date[j][i] % 4 * chip_size.X;
			tex_Pos.Y = map_date[j][i] / 4 * chip_size.Y;

			Pos = Vec2(i * chip_size.X, j * chip_size.X);

			Engine::DrawTextureUV(Pos.X, Pos.Y, "map", tex_Pos.X, tex_Pos.Y, chip_size.X, chip_size.Y, 255, 0.0f);

		
		}
	}*/

	
	
		//Engine::DrawTexture(0.0f, 0.0f, "map");
	
	


	if (g_GameFadeControl.FadeControl01 == false)
	{
		
		Engine::DrawRect(0.0f, 0.0f, 1920.0f, 1080.0f, 0xffffff, g_GameFadeControl.alpha--);
		
		

		if (g_GameFadeControl.alpha == 0)
		{

			g_GameFadeControl.FadeControl01 = true;
		}


	}
	




}

void FinishGameScene()
{

}



void UpdateGameScene()
{
	switch (g_CurrentSceneStep)
	{
	case SceneStep::Init:
		InitGameScene();
		break;
	case SceneStep::Run:
		RunGameScene();
		break;
	case SceneStep::Finish:
		FinishGameScene();
		break;
	}

	//DrawGameScene();
}