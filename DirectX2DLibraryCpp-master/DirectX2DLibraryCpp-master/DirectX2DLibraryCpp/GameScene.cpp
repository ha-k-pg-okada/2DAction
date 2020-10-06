#include "GameScene.h"
#include "Scene.h"

extern SceneKind g_CurrentSceneKind;
extern SceneStep g_CurrentSceneStep;

void InitGameScene();
void RunGameScene();
void FinishGameScene();

void InitGameScene()
{

}

void RunGameScene()
{

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