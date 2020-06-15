#ifndef ESTRELLA_

#define ESTRELLA_H

#include <glew.h>
#include "Figure3D.h"

//
// CLASE: Estrella
//
// DESCRIPCIÓN: Representa una pirámide de base cuadrada de 
//              lado 2·s y altura 2·s.
// 
class Estrella : public Figure3D {
public:
	Estrella(GLfloat s);
};


#endif