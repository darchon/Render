/******************************
* Triangle.h
******************************/
#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

// Includes
#include <D3D11.h>
#include <D3DX10math.h>

class Triangle
{
private:
	struct VertexType
	{
		D3DXVECTOR3 position;
		D3DXVECTOR4 color;
	};

public:
	Triangle();
	Triangle(const Triangle&);
	~Triangle();

	bool Initialize(ID3D11Device* device);
	void Shutdown();
	void Render(ID3D11DeviceContext* dContext);

	int GetIndexCount();

private:
	bool InitializeBuffers(ID3D11Device* device);
	void ShutdownBuffers();
	void RenderBuffers(ID3D11DeviceContext* dContext);

	ID3D11Buffer*		m_vertexBuffer;
	ID3D11Buffer*		m_indexBuffer;
	int					m_vertexCount;
	int					m_indexCount;

};

#endif