/******************************
* Triangle.cpp
******************************/
#include "Triangle.h"

Triangle::Triangle()
	: m_vertexBuffer(0),
	m_indexBuffer(0)
{
}

Triangle::Triangle(const Triangle& other)
{
}

Triangle::~Triangle()
{
}

bool Triangle::Initialize(ID3D11Device* device)
{
	//Init Buffers
	return InitializeBuffers(device);
}

void Triangle::Shutdown()
{
	// Release the vertex and index buffers.
	ShutdownBuffers();

	return;
}

void Triangle::Render(ID3D11DeviceContext* dContext)
{
	// Put the vertex and index buffers on the graphics pipeline to prepare them for drawing.
	RenderBuffers(dContext);

	return;
}

int Triangle::GetIndexCount()
{
	return m_indexCount;
}

bool Triangle::InitializeBuffers(ID3D11Device* device)
{
	VertexType* vertices;
	unsigned long* indices;
	D3D11_BUFFER_DESC vertexBufferDesc, indexBufferDesc;
	D3D11_SUBRESOURCE_DATA vertexData, indexData;
	HRESULT result;

	//setup arrays to temp hold data
	m_vertexCount = 3;
	m_indexCount=3;

	vertices = new VertexType[m_vertexCount];
	if(!vertices)
		return false;

	indices = new unsigned long[m_indexCount];
	if(!indices)
		return false;

	//Create Triangle information
	vertices[0].position = D3DXVECTOR3(-1.0f, -1.0f, 0.0f);
	vertices[0].color = D3DXVECTOR4(0.0f, 1.0f, 0.0f, 1.0f);

	vertices[1].position = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	vertices[1].color = D3DXVECTOR4(0.0f, 1.0f, 0.0f, 1.0f);

	vertices[2].position = D3DXVECTOR3(1.0f, -1.0f, 0.0f);
	vertices[2].color = D3DXVECTOR4(0.0f, 1.0f, 0.0f, 1.0f);

	indices[0] = 0;
	indices[1] = 1;
	indices[2] = 2;

	// Set up the description of the static vertex buffer.
	vertexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	vertexBufferDesc.ByteWidth = sizeof(VertexType) * m_vertexCount;
	vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vertexBufferDesc.CPUAccessFlags = 0;
	vertexBufferDesc.MiscFlags = 0;
	vertexBufferDesc.StructureByteStride = 0;

	// Give the subresource structure a pointer to the vertex data.
	vertexData.pSysMem = vertices;
	vertexData.SysMemPitch = 0;
	vertexData.SysMemSlicePitch = 0;

	// Now create the vertex buffer.
	result = device->CreateBuffer(&vertexBufferDesc, &vertexData, &m_vertexBuffer);
	if(FAILED(result))
		return false;

	// Set up the description of the static index buffer.
	indexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	indexBufferDesc.ByteWidth = sizeof(unsigned long) * m_indexCount;
	indexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	indexBufferDesc.CPUAccessFlags = 0;
	indexBufferDesc.MiscFlags = 0;
	indexBufferDesc.StructureByteStride = 0;

	// Give the subresource structure a pointer to the index data.
	indexData.pSysMem = indices;
	indexData.SysMemPitch = 0;
	indexData.SysMemSlicePitch = 0;

	// Create the index buffer.
	result = device->CreateBuffer(&indexBufferDesc, &indexData, &m_indexBuffer);
	if(FAILED(result))
		return false;

	//free temp arrays
	delete [] vertices;
	vertices = 0;

	delete [] indices;
	indices = 0;

	return true;

}

void Triangle::ShutdownBuffers()
{
	//Release buffers
	if(m_indexBuffer)
	{
		m_indexBuffer->Release();
		m_indexBuffer = 0;
	}

	if(m_vertexBuffer)
	{
		m_vertexBuffer->Release();
		m_vertexBuffer = 0;
	}

	return;
}

void Triangle::RenderBuffers(ID3D11DeviceContext* dContext)
{
	unsigned int stride, offset;

	stride = sizeof(VertexType);
	offset = 0;

	//Set vertex and index buffers as active
	dContext->IASetVertexBuffers(0, 1, &m_vertexBuffer, &stride, &offset);
	dContext->IASetIndexBuffer(m_indexBuffer, DXGI_FORMAT_R32_UINT, 0);

	//set type of primative
	dContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	return;
}