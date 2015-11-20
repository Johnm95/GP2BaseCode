#version 150

//The input vertex
in vec3 vertexPosition;
in vec2 vertexTexCoords;

out vec2 vertexTexCoordsOut;

//The MVP matrix
uniform mat4 MVP;

//The main function
void main()
{
  //Calculate the transformed position
  vertexTexCoordsOut = vertexTexCoords;
  gl_Position = MVP * vec4(vertexPosition, 1.0);
}
