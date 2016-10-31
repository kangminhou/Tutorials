#pragma once
#include "DirectX_Include.h"
#include "DeferredRenderer.h"

#define DEBUG_DETAIL 40

class DebugModels
{
public:
	DebugModels(DeferredRenderer* a_DeferredRenderer);
	~DebugModels();

	void Release();

	const ObjectData& GetModelCube()	  const { return m_cube;		}
	const ObjectData& GetModelSphere()	  const { return m_sphere;		}

private:
	ObjectData m_cube;
	ObjectData m_sphere;
};

