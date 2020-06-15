#include "stdafx.h"
#include <glew.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Scene3D.h"
#include "ShaderProgram.h"
#include "Figure3D.h"
#include "Estrella.h"
#include "Ground3D.h"


//
// FUNCI�N: Scene3D::Scene3D()
//
// PROP�SITO: Construye el objeto que representa la escena
//
Scene3D::Scene3D()
{
    ground = new Ground3D(50.0f, 50.0f);

    fig0 = new Estrella(10.0f);
    fig0->Translate(glm::vec3(0, 5.0f, 0));
    fig0->Rotate(45.0f, glm::vec3(0.0f, 1.0f, 0.0f));
}

//
// FUNCI�N: Scene3D::~Scene3D()
//
// PROP�SITO: Destruye el objeto que representa la escena
//
Scene3D::~Scene3D()
{
    delete ground;
    delete fig0;

}


//
// FUNCI�N: Scene3D::Draw()
//
// PROP�SITO: Dibuja la escena
//
void Scene3D::Draw(ShaderProgram* program, glm::mat4 proj, glm::mat4 view)
{
    ground->Draw(program, proj, view);
    fig0->Draw(program, proj, view);
}

// ACCIONES A REALIZAR  A LO LARGO DEL TIEMPO
void Scene3D::timerAction() {

    // DAR UNA VUELTA COMPLETA CADA 3s
    fig0->Rotate(4.8f, glm::vec3(0.0f, 1.0f, 0.0f));

}