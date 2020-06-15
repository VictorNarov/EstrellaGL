#include "stdafx.h"
#include <glew.h>
#include <math.h>
#include "Figure3D.h"
#include "Estrella.h"
#define PI 3.14159

Estrella::Estrella(GLfloat s)
{
	s = 30;
	numFaces = 20;     // Number of faces
	numVertices = 60;  // Number of vertices

	vertices = new GLfloat[numVertices * 3];

	GLfloat profundidad = 5;
	GLfloat R = s;
	GLfloat r = s/4;



	//PUNTO CENTRAL DELANTE
	for (int i = 0; i < 30; i+=3) //0-9
	{
		vertices[i] = 0;
		vertices[i+1] = 0;
		vertices[i+2] = profundidad;
	}

	//PUNTO CENTRAL DETRAS
	for (int i = 30; i < 60; i += 3) //10-19
	{
		vertices[i] = 0;
		vertices[i + 1] = 0;
		vertices[i + 2] = -profundidad;
	}

	//VERTICES PENTAGONO GRANDE
	int contador = 0; // Va contando el giro 
	for (int i = 60; i < 120; i += 3) //20-39
	{
		vertices[i] = R * cos( PI/2 + 2*PI/5 * contador );     //X
		vertices[i + 1] = R * sin(PI/2 + 2 * PI / 5 * contador); //Y
		vertices[i + 2] = 0;
		contador++;
	}

	//VERTICES PENTAGONO PEQUEÑO
	contador = 0; // Va contando el giro 
	for (int i = 120; i < 180; i += 3) //40-59
	{
		vertices[i] = r * cos(7*PI/10 + 2 * PI / 5 * contador);     //X
		vertices[i + 1] = r * sin(7 * PI / 10 + 2 * PI / 5 * contador); //Y
		vertices[i + 2] = 0;
		contador++;
	}
	

	indexes = new GLushort[numFaces * 3] {  // Array of indexes

		// https://es.wikipedia.org/wiki/Pent%C3%A1gono
		// https://www.101computing.net/pentagram-challenge/
		// https://authors.unicadpublish.com/~jack_xu/images/wpf_examples01.gif

		// CARA DELANTERA
		0, 20, 40, // CENTRO - V0 - v0  
		1, 44, 25, // CENTRO - v4 - V0
		2, 45, 21, // CENTRO - v0 - V1
		3, 26, 41, // CENTRO - V1 - v1
		4, 46, 22, // CENTRO - v1 - V2
		5, 27, 42, // CENTRO - V2 - v2
		6, 47, 23, // CENTRO - v2 - V3
		7, 28, 43, // CENTRO - V3 - v3
		8, 48, 24, // CENTRO - v3 - V4
		9, 29, 49, // CENTRO - V4 - v4

		// CARA TRASERA
		10, 50, 30,// CENTRO - v0 - V0
		11, 35, 54,// CENTRO - V0 - v4
		12, 31, 55,// CENTRO - V1 - v0
		13, 51, 36,// CENTRO - v1 - V1
		14, 32, 56,// CENTRO - V2 - v1
		15, 52, 37,// CENTRO - v2 - V2
		16, 33, 57,// CENTRO - V3 - v2
		17, 53, 38,// CENTRO - v3 - V3
		18, 34, 58,// CENTRO - V4 - v3
		19, 54, 39 // CENTRO - v4 - V4
		 
	};

	

	InitBuffers();
}
