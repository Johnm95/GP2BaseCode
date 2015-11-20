//
//  Texture.h
//  GP2BaseCode
//
//  Created by John McMillan on 20/11/2015.
//
//

#ifndef Texture_h
#define Texture_h

#include "Common.h"

GLuint loadTextureFromFile(const string& filename);

GLuint converetSDLSurfaceToTexture(SDL_Surface*surface);
#endif /* Texture_h */
