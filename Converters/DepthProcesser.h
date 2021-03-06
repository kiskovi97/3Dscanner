#pragma once

#include "Camera.h"
#include <iostream>
#include <fstream>
#include "ICP.h"
#include "MarchCubes.h"
#include <matrix.h>


#define HEIGHT 200
#define WIDTH 200
#define DEPTH 100
#define HEIGHT_MAX 1000
#define HEIGHT_MIN -1000
#define WIDTH_MAX 1000
#define WIDTH_MIN -1000
#define DEPTH_MAX 1000


typedef unsigned short uint16;
typedef unsigned int uint32;
class DepthProcesser
{
private:
	int elozo_size=0;
	std::vector<vec3> eltolas = {
		vec3(0.5,0,0),
		vec3(1,0,0.5),
		vec3(0.5,0,1),
		vec3(0,0,0.5),
		vec3(0.5,1,0),
		vec3(1,1,0.5),
		vec3(0.5,1,1),
		vec3(0,1,0.5),
		vec3(0,0.5,0),
		vec3(1,0.5,0),
		vec3(1,0.5,1),
		vec3(0,0.5,1)
	};
	
	double *Elozoframe;
	double *Mostaniframe;
	Matrix Forgatas;
	Matrix Eltolas;

	ICP icp;
	MarchCubes mcb;
	std::vector<vec3> pontok;
	std::vector<std::vector<std::vector<bool> > > array3D;
	std::vector<std::vector<vec3> > haromszogek;
	MyCamera cam;
	MyCamera nezo;
	bool elore = true;
	bool elso_frame = true;
	void MyIcp();
public:
	
	DepthProcesser();
	~DepthProcesser();

	void WriteOut();
	void MarchingCubes();
	void MCube(int x, int y, int z);
	
	uint32 Convert(uint16 depth);
	void Process(uint16* depthfield, uint32* RGBfield, const int m_depthWidth, const int m_depthHeight);
};

