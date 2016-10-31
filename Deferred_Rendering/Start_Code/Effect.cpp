#include "Effect.h"


Effect::Effect()
{
}


Effect::~Effect()
{
}

void Effect::Init(ID3D11Device* a_d3dDevice, const std::wstring& a_filePath)
{
	//Init effect.
	DirectXHelper::CompileShaderFromData(a_filePath, a_d3dDevice, &m_effect);

	m_techBasic		= m_effect->GetTechniqueByName("BasicTech");

	m_model			= m_effect->GetVariableByName ("gModel")->AsMatrix();
	m_view			= m_effect->GetVariableByName ("gView")->AsMatrix();
	m_projection	= m_effect->GetVariableByName ("gProjection")->AsMatrix();
	//Set the input layout.
	D3DX11_PASS_DESC passDesc;
	m_techBasic->GetPassByIndex(0)->GetDesc(&passDesc);
	HR(a_d3dDevice->CreateInputLayout(VERTEX_DESCRIPTION, sizeof(VERTEX_DESCRIPTION) / sizeof(*VERTEX_DESCRIPTION),
										passDesc.pIAInputSignature, passDesc.IAInputSignatureSize, &m_inputLayout));
}

void Effect::ApplyPass(ID3D11DeviceContext * a_d3dDeviceContext)
{
	m_techBasic->GetPassByIndex(0)->Apply(0, a_d3dDeviceContext);
}

D3DX11_TECHNIQUE_DESC Effect::GetSelectedTechDescription() const
{
	D3DX11_TECHNIQUE_DESC techniqueDesc;
	m_techBasic->GetDesc(&techniqueDesc);

	return techniqueDesc;
}
