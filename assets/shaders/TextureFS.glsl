#version 150

//the output Frag Colour
out vec4 FragColor;
in vec2 vertexTexCoordsOut;

uniform sampler2D texture0;
//The main function
void main()
{
  //The frag colour
  FragColor = texture(texture0, vertexTexCoordsOut);
}
