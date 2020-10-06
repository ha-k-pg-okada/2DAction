#include "Scene.h"
#include "TitleScene.h"
#include "Src/Engine/Engine.h"


void InitTitleScene();
void RunTitleScene();
void FinishTitleScene();

extern SceneKind g_CurrentSceneKind;
extern SceneStep g_CurrentSceneStep;

int alpha = 0;
bool FadeControl01 = false;
bool FadeControl02 = false;
bool FadeControl03 = false;
bool FadeControl04 = false;

void InitTitleScene()
{

	Engine::DrawFont(200.0f, 200.0f, "タイトルシーン", Regular, White);
	g_CurrentSceneKind = SceneKind::GameScene;


}

void RunTitleScene()
{

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