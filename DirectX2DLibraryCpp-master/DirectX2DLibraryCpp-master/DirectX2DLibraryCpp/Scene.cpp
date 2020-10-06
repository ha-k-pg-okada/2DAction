#include "Src/Engine/Engine.h"
#include "Scene.h"

SceneKind g_CurrentSceneKind = SceneKind::TitleScene;
int alpha = 0;
bool FadeControl01 = false;
bool FadeControl02 = false;
bool FadeControl03 = false;
bool FadeControl04 = false;

//SceneKind g_CurrentSceneKind;

void  UpdateTitleScene()
{






	if (FadeControl01 == false && FadeControl03 == false && FadeControl02 == false && FadeControl04 == false)
	{
		if (Engine::IsKeyboardKeyPushed(DIK_RETURN))
		{

			FadeControl01 = true;


		}
	}
	//Engine::DrawFont(200.0f, 200.0f, "タイトルシーン", Regular, White);

	Engine::DrawTexture(0.0f, 0.0f, "01");


	if (FadeControl04 == true)
	{
		Engine::DrawRect(0.0f, 0.0f, 1920.0f, 1080.0f, 0xffffff, alpha--);

		if (alpha == 0)
		{
			FadeControl04 = false;
		}
	}

	if (FadeControl01 == true)
	{
		Engine::DrawRect(0.0f, 0.0f, 1920.0f, 1080.0f, 0xffffff, alpha++);
		if (alpha >= 255)
		{

			g_CurrentSceneKind = SceneKind::GameScene;
			FadeControl01 = false;
			FadeControl02 = true;
		}

	}


}




void UpdateGameScene()
{
	Engine::DrawTexture(0.0f, 0.0f, "02");
	if (FadeControl02 == true)
	{


		Engine::DrawRect(0.0f, 0.0f, 1920.0f, 1080.0f, 0xffffff, alpha--);


		if (alpha == 0)
		{

			FadeControl02 = false;
		}


	}





	//Engine::DrawFont(200.0f, 200.0f, "ゲームシーン", Regular, White);

	if (FadeControl01 == false && FadeControl02 == false)
	{
		if (Engine::IsKeyboardKeyPushed(DIK_RETURN))
		{
			FadeControl03 = true;


		}
	}

	if (FadeControl03 == true)
	{
		Engine::DrawRect(0.0f, 0.0f, 1920.0f, 1080.0f, 0xffffff, alpha++);

		if (alpha >= 255)
		{

			g_CurrentSceneKind = SceneKind::TitleScene;
			FadeControl03 = false;
			FadeControl04 = true;
		}
	}

}

void UpdateScene()
{
	Engine::Update();

	switch (g_CurrentSceneKind)
	{
	case SceneKind::TitleScene:
		UpdateTitleScene();
		break;
	case SceneKind::GameScene:
		UpdateGameScene();
		break;
	}
}