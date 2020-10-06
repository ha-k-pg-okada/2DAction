#include "Scene.h"
#include "TitleScene.h"
#include "Src/Engine/Engine.h"


void InitTitleScene();
void RunTitleScene();
void FinishTitleScene();

extern SceneKind g_CurrentSceneKind;
extern SceneStep g_CurrentSceneStep;

//int alpha = 0;
//bool FadeControl01 = false;
//bool FadeControl02 = false;
//bool FadeControl03 = false;
//bool FadeControl04 = false;

TitleFadeControl g_TitleFadeControl;

void InitTitleScene()
{
	g_TitleFadeControl.alpha = 0;
	g_TitleFadeControl.FadeControl01 = false;
	
	//Engine::DrawFont(200.0f, 200.0f, "タイトルシーン", Regular, White);

	g_CurrentSceneStep = SceneStep::Run;
		
}
	
	//g_CurrentSceneKind = SceneKind::GameScene;




void RunTitleScene()
{
	if (Engine::IsKeyboardKeyPushed(DIK_RETURN))
	{

	if (g_TitleFadeControl.FadeControl01 == false)
	   {
		

		g_TitleFadeControl.FadeControl01 = true;


		}
	}
	//Engine::DrawFont(200.0f, 200.0f, "タイトルシーン", Regular, White);

	Engine::DrawTexture(0.0f, 0.0f, "01");


	if (g_TitleFadeControl.FadeControl01 == true)
	{
		Engine::DrawRect(0.0f, 0.0f, 1920.0f, 1080.0f, 0xffffff, g_TitleFadeControl.alpha++);

		if (g_TitleFadeControl.alpha == 255)
		{
			g_CurrentSceneKind = SceneKind::GameScene;
			g_CurrentSceneStep = SceneStep::Init;
			/*g_FadeControl.FadeControl01 = false;
			g_FadeControl.FadeControl02 = true;*/
		}
	}

	//if (g_FadeControl.FadeControl02 == true)
	//{
	//	Engine::DrawRect(0.0f, 0.0f, 1920.0f, 1080.0f, 0xffffff, g_FadeControl.alpha--);
	//	if (g_FadeControl.alpha >= 0)
	//	{

	//		
	//		g_FadeControl.FadeControl02 = false;
	//		
	//		
	//	}
		/*if (g_FadeControl.FadeControl02 == false)
		{
			g_CurrentSceneKind = SceneKind::GameScene;
			g_CurrentSceneStep = SceneStep::Init;
		}*/

	}




void FinishTitleScene()
{


}



void UpdateTitleScene()
{
	switch (g_CurrentSceneStep)
	{
	case SceneStep::Init:
		InitTitleScene();
		break;
	case SceneStep::Run:
		RunTitleScene();
		break;
	case SceneStep::Finish:
		FinishTitleScene();
		break;
	}
}