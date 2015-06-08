#pragma once
/*
	SceneBase

	Sceneクラス基底クラス
	これは抽象クラスにする
*/
class SceneBase
{
	public:
		virtual ~SceneBase() = default;

		virtual void  Render() = 0;

};

