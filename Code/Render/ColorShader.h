/******************************
* ColorShader.h
******************************/
#ifndef _COLORSHADER_H_
#define _COLORSHADER_H_

// Includes
#include <d3d11.h>
#include <d3dx10math.h>
#include <d3dx11async.h>
#include <fstream>
using namespace std;

class ColorShader
{
private:
	struct MatrixBufferType
	{
		D3DXMATRIX world;
		D3DXMATRIX view;
		D3DXMATRIX projection;
	};
	
public:
	ColorShader();
	ColorShader(const ColorShader& other);
	~ColorShader();

	bool Initialize(ID3D11Device* device, HWND hwnd);
	void Shutdown();
	bool Render(ID3D11DeviceContext* dContext, int, D3DXMATRIX, D3DXMATRIX, D3DXMATRIX);

private:
	bool InitializeShader(ID3D11Device* device, HWND hwnd, WCHAR*, WCHAR*);
	void ShutdownShader();
	void OutputShaderErrorMessage(ID3D10Blob*, HWND hwnd, WCHAR*);

	bool SetShaderParameters(ID3D11DeviceContext* dContext, D3DXMATRIX, D3DXMATRIX, D3DXMATRIX);
	void RenderShader(ID3D11DeviceContext* dContext, int);

	ID3D11VertexShader*				m_vertexShader;
	ID3D11PixelShader*				m_pixelShader;
	ID3D11InputLayout*				m_layout;
	ID3D11Buffer*					m_matrixBuffer;
};

#endif