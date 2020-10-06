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

//int alpha = 0;
//bool FadeControl01 = false;
//bool FadeControl02 = false;
//bool FadeControl03 = false;
//bool FadeControl04 = false;


void InitGameScene()
{
	g_GameFadeControl.alpha = 255;
	g_GameFadeControl.FadeControl01 = false;
	

	
	//Engine::DrawFont(200.0f, 200.0f, "ゲームシーン", Regular, White);

	g_CurrentSceneStep = SceneStep::Run;
}

void RunGameScene()
{
	
		Engine::DrawTexture(0.0f, 0.0f, "02");
	
	


	if (g_GameFadeControl.FadeControl01 == false)
	{
		
		Engine::DrawRect(0.0f, 0.0f, 1920.0f, 1080.0f, 0xffffff, g_GameFadeControl.alpha--);
		
		

		if (g_GameFadeControl.alpha == 0)
		{

			g_GameFadeControl.FadeControl01 = true;
		}


	}
	




	//Engine::DrawFont(200.0f, 200.0f, "ゲームシーン", Regular, White);

	
		/*if (Engine::IsKeyboardKeyPushed(DIK_RETURN))
		{
			

				g_FadeControl.FadeControl02 = true;


			
		}*/
	
	

	//if (g_FadeControl.FadeControl02 == true)
	//{
	//	Engine::DrawRect(0.0f, 0.0f, 1920.0f, 1080.0f, 0xffffff, g_FadeControl.alpha++);

	//	if (g_FadeControl.alpha >= 255)
	//	{

	//		g_CurrentSceneKind = SceneKind::TitleScene;
	//		g_CurrentSceneStep = SceneStep::Init;
	//		/*FadeControl03 = false;
	//		FadeControl04 = true;*/
	//	}
	//}
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