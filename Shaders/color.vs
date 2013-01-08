//////////////
// color.vs
//////////////


// Globals

cbuffer MatrixBuffer
{
	matrix worldMatrix;
	matrix viewMatrix;
	matrix projectionMatrix;	
};

// TypeDefs

struct VertexInputType
{
	float4 position : POSITION;
	float4 color : COLOR;
};

struct PixelInputType
{
	float4 position : SV_POSITION;
	float4 color : COLOR;
};

// Vertex Shader
PixelInputType ColorVertexShader(VertexInputType input)
{
	PixelInputType output;
	
	//Change position vector to be 4 units for matrix math
	input.position.w = 1.0f;
	
	//Calc position of vertex via world, view, and projection matrices
	output.position = mul(input.position, worldMatrix);
	output.position = mul(output.position, viewMatrix);
	output.position = mul(output.position, projectionMatrix);
	
	//store the input color
	output.color = input.color;
	
	return output;
}

	