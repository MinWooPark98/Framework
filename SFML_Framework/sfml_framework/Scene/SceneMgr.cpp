#include "SceneMgr.h"

bool SceneMgr::Init()
{
    //sceneMap[Scenes::Title] = new SceneDev1();
    currScene = Scenes::SceneDev1;

    for (auto& pair : sceneMap)
    {
        pair.second->Init();
    }

    sceneMap[currScene]->Enter();

    return true;
}

Scene* SceneMgr::GetScene(Scenes scene)
{
    return sceneMap[scene];
}

void SceneMgr::ChangeScene(Scenes scene)
{
    sceneMap[currScene]->Exit();
    currScene = scene;
    sceneMap[currScene]->Enter();
}

Scene* SceneMgr::GetCurrentScene()
{
    return sceneMap[currScene];
}

void SceneMgr::Update(float dt)
{
    sceneMap[currScene]->Update(dt);
}

void SceneMgr::Draw(RenderWindow& window)
{
    sceneMap[currScene]->Draw(window);
}

