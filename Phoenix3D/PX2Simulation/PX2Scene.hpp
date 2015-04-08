// PX2Scene.hpp

#ifndef PX2SCENE_HPP
#define PX2SCENE_HPP

#include "PX2Node.hpp"
#include "PX2Actor.hpp"
#include "PX2RenderStep.hpp"
#include "PX2CameraActor.hpp"
#include "PX2AmbientRegionActor.hpp"
#include "PX2TerrainActor.hpp"
#include "PX2SkyActor.hpp"
#include "PX2CellSpace.hpp"
#include "PX2SimulationDataDefine.hpp"

namespace PX2
{

	class Scene : public Node
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_PROPERTY;
		PX2_DECLARE_STREAM(Scene);

	public:
		Scene();
		virtual ~Scene();

		virtual void SetAlpha(float alpha);
		virtual void SetColor(const Float3 &color);
		virtual void SetBrightness(float brightness);

		EnvirParam *GetEnvirParam();

		void SetUseCameraActor(CameraActor *cameraActor);
		CameraActor *GetUseCameraActor();

		AmbientRegionActor *GetDefaultAmbientRegionActor();
		TerrainActor *GetTerrainActor();
		SkyActor *GetSkyActor();

		virtual int AttachChild(Movable* child);
		virtual int DetachChild(Movable* child);

		Actor *GetActorByID(int id);

		void SetShowHelpNode(bool showHelpNode);
		bool IsShowHelpNode() const;

	protected:
		virtual void OnChildAdded(Movable *child);
		virtual void OnChildRemoved(Movable *child);
		virtual void UpdateWorldData(double applicationTime, double elapsedTime);

		EnvirParamPtr mEnvirParam;

		std::map<int, ActorPtr> mActors;
		CameraActorPtr mCameraActor;
		AmbientRegionActorPtr mDefaultAmbientRegionActor;
		TerrainActorPtr mTerrainActor;
		SkyActorPtr mSkyActor;
		bool mIsShowHelpNode;

	public:
		static int GetNextID();
		static const int msIDCover = 100000;

	protected:
		static int msNextID;

		// scene manager
	public:
		enum SceneManageType
		{
			SMT_NONE,
			SMT_OCTREE,
			SMT_CELL2D,
			SMT_MAX_TYPE
		};
		void SetSceneManageType(SceneManageType type);
		SceneManageType GetSceneManageType();

		void SetSize(const Sizef &size);
		const Sizef &GetSize() const;

		void GetRangeActors(std::vector<Actor*> &actors, const APoint &center,
			float radius, bool useActorSelfRadius, const std::bitset<PX2_ACTOR_BS_SIZE> &bits);
		void GetRangeActorsExcept(Actor *except, std::vector<Actor*> &actors,
			const APoint &center, float radius, bool useActorSelfRadius,
			const std::bitset<PX2_ACTOR_BS_SIZE> &bits);

	protected:
		SceneManageType mSceneManageType;
		CellSpacePtr mCellSpace;
		Sizef mSize;

		// rendering
	public:
		void SetScene_UseBloom(bool isUseBloom);
		bool IsScene_UseBloom() const;
		void SetScene_BloomRenderTargetSizeSameWithScreen(bool sizeSameWithScreen);
		bool IsScene_BloomRenderTargetSizeSameWithScreen() const;
		void SetScene_BloomRenderTargetSize(const Float2 &size);
		const Float2 &GetScene_BloomRenderTargetSize() const;
		void SetScene_BloomBrightWeight(float weight);
		float GetScene_BloomBrightWeight() const;
		void SetScene_BloomBlurDeviation(float deviation);
		float GetScene_BloomBlurDeviation() const;
		void SetScene_BloomBlurWeight(float weight);
		float GetScene_BloomBlurWeight() const;
		void SetScene_BloomWeight(float weight);
		float GetScene_BloomWeight() const;
		const Float4 &GetBloomBrightParam() const;
		const Float4 &GetBloomParam() const;

		void SetScene_UseShadowMap(bool isUseShadowMap);
		bool IsScene_UseShadowMap() const;
		void SetScene_ShadowRenderTargetSizeSameWithScreen(bool sameWithScreen);
		bool IsScene_ShadowRenderTargetSizeSameWithScreen() const;
		void SetScene_ShadowRenderTargetSize(const Float2 &size);
		const Float2 &GetScene_ShadowRenderTargetSize() const;

	protected:
		bool mIsScene_UseBloom;
		bool mIsScene_BloomRenderTargetSizeSameWithScreen;
		Float2 mScene_BloomRenderTargetSize;
		float mScene_BloomBrightWeight;
		Float4 mBloomBrightParam;
		float mScene_BloomBlurDeviation;
		float mScene_BloomBlurWeight;
		float mScene_BloomWeight;
		Float4 mBloomParam;

		bool mIsScene_UseShadowMap;
		bool mIsScene_ShadowRenderTargetSizeSameWithScreen;
		Float2 mScene_ShadowRenderTargetSize;
	};

#include "PX2Scene.inl"
	PX2_REGISTER_STREAM(Scene);
	typedef Pointer0<Scene> ScenePtr;

}

#endif