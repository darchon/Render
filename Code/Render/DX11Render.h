/******************************
* DX11Render.h
******************************/
#ifndef _DX11RENDER_H_
#define _DX11RENDER_H_


//////////////
// INCLUDES //
//////////////
#include "IRender.h"
#include <DXGI.h>
#include <D3Dcommon.h>
#include <D3D11.h>
#include <D3DX10math.h>

class DX11Render : public IRender
{
public:
	DX11Render();
	DX11Render(const DX11Render&);
	~DX11Render();

	//inherited
	bool Initialize(int screenWidth, int screenHeight, bool fullscreen, HWND hwnd);
	void Shutdown();
	bool Frame();

	//helpers
	ID3D11Device* GetDevice();
	ID3D11DeviceContext* GetDeviceContext();

	void GetProjectionMatrix(D3DXMATRIX&);
	void GetWorldMatrix(D3DXMATRIX&);
	void GetOrthoMatrix(D3DXMATRIX&);

	void GetVideoCardInfo(char* cardName, int& memory);

private:
	void BeginScene(float red, float green, float blue, float alpha);
	void EndScene();

private:
	bool						m_vsync_enabled;
	int							m_videoCardMemory;
	char						m_videoCardDescription[128];
	IDXGISwapChain*				m_swapChain;
	ID3D11Device*				m_device;
	ID3D11DeviceContext*		m_deviceContext;
	ID3D11RenderTargetView*		m_renderTargetView;
	ID3D11Texture2D*			m_depthStencilBuffer;
	ID3D11DepthStencilState*	m_depthStencilState;
	ID3D11DepthStencilView*		m_depthStencilView;
	ID3D11RasterizerState*		m_rasterState;
	D3DXMATRIX					m_projectionMatrix;
	D3DXMATRIX					m_worldMatrix;
	D3DXMATRIX					m_orthoMatrix;

};

#endif