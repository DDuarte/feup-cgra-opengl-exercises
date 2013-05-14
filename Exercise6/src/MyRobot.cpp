#include "MyRobot.h"


#include "NewellsMethod.h"
#include <iostream>

#define YBASE 0.3f
#define RADIUS 0.25f
#define SLICES 12

float ambR[3] = {0.2, 0.2, 0.2};
float difR[3] = {0.6, 0.6, 0.6};
float specR[3] = {0.2, 0.2, 0.2};
float shininessR = 10.f;

MyRobot::MyRobot(int stacks) : _position(10.0f, 0.5f, 8.0f), _stacks(stacks + 1)
{
	_currentSkin = 0;
	for (int i = 0; i < MAX_ROBOT_TEXTURES; ++i)
	{
		_skins[i] = new CGFappearance(AVAILABLE_ROBOT_TEXTURES[i], GL_CLAMP, GL_CLAMP);
		_skins[i]->setAmbient(ambR);
		_skins[i]->setDiffuse(difR);
		_skins[i]->setSpecular(specR);
		_skins[i]->setShininess(shininessR);
	}

	SetAngle(200.0f);
	_vertices.resize(_stacks);
	_normals.resize(_stacks);
	Point p;
	p.Y = YBASE;
	p.X = -0.5;
	p.Z = -0.5;

	for (int i = 0 ; i < 3; ++i)
	{
		_vertices[0].push_back(p);
		p.Z += 1.0/3.0;
	}

	for (int i = 0 ; i < 3; ++i)
	{
		_vertices[0].push_back(p);
		p.X += 1.0/3.0;
	}

	for (int i = 0 ; i < 3; ++i)
	{
		_vertices[0].push_back(p);
		p.Z -= 1.0/3.0;
	}

	for (int i = 0 ; i < 3; ++i)
	{
		_vertices[0].push_back(p);
		p.X -= 1.0/3.0;
	}

	double ang = M_PI / 4 + M_PI;

	for (int i = 0; i < SLICES; ++i)
	{
		p.X = RADIUS * sin(ang);
		p.Y = 1;
		p.Z = RADIUS * cos(ang);

		_vertices[_stacks - 1].push_back(p);

		ang += M_PI / 6;
	}

	double x, y, z;

	for (unsigned int i = 0 ; i < _vertices.size() - 1; ++i)
	{
		for (unsigned int j = 0 ; j < _vertices[i].size(); ++j)
		{
			p = _vertices[i][j];

			x = _vertices[_stacks - 1][j].X - _vertices[0][j].X;
			y = _vertices[_stacks - 1][j].Y - _vertices[0][j].Y;
			z = _vertices[_stacks - 1][j].Z - _vertices[0][j].Z;

			p.X += x/(_stacks - 1);
			p.Y += y/(_stacks - 1);
			p.Z += z/(_stacks - 1);

			_vertices[i + 1].push_back(p);
		}
	}

	// calculate normals

	std::vector<Point> points;

	for (int i = 0; i < _stacks; ++i)
	{
		for (int j = 0; j < SLICES; ++j)
		{
			
			if (i != 0 && i != _stacks - 1) // Middle
			{
				points.push_back(_vertices[(i + 1) % _stacks][(j + 1) % SLICES]);
				points.push_back(_vertices[(i + 1) % _stacks][(j - 1) < 0 ? SLICES - 1 : j - 1]);
				points.push_back(_vertices[(i - 1) < 0 ? _stacks - 1 : i - 1][(j - 1) < 0 ? SLICES - 1 : j - 1]);
				points.push_back(_vertices[(i - 1) < 0 ? _stacks - 1 : i - 1][(j + 1) % SLICES]);
			}
			else if (i == _stacks - 1) // Top
			{
				points.push_back( _vertices[i][j]);
				points.push_back( _vertices[i][(j - 1) < 0 ? SLICES - 1 : j - 1]);
				points.push_back( _vertices[(i - 1) < 0 ? _stacks - 1 : i - 1][(j - 1) < 0 ? SLICES - 1 : j - 1]);
				points.push_back( _vertices[(i - 1) < 0 ? _stacks - 1 : i - 1][j]);
				points.push_back( _vertices[(i - 1) < 0 ? _stacks - 1 : i - 1][(j + 1) % SLICES]);
				points.push_back( _vertices[i][(j + 1) % SLICES]);
			}
			else if (i == 0) // Bottom
			{
				points.push_back( _vertices[i][j]);
				points.push_back( _vertices[i][(j + 1) % SLICES]);
				points.push_back( _vertices[(i + 1) % _stacks][(j + 1) % SLICES]);
				points.push_back( _vertices[(i + 1) % _stacks][j]);
				points.push_back( _vertices[(i + 1) % _stacks][(j - 1) < 0 ? SLICES - 1 : j - 1]);
				points.push_back( _vertices[i][(j - 1) < 0 ? SLICES - 1 : j - 1]);
			}

			_normals[i].push_back(CalculateSurfaceNormal(points));
			points.clear();
		}
	}
}

MyRobot::~MyRobot()
{
	for (int i = 0; i < MAX_ROBOT_TEXTURES; ++i)
		delete _skins[i];
}

void MyRobot::draw()
{
	_skins[_currentSkin]->apply();

	// base (square)
	glBegin(GL_QUADS);
	glNormal3f(0.0f, -1.0f, 0.0f);
	for (int i = 3; i >= 0; --i)
	{
		glTexCoord2f(0.5 + _vertices[0][i*3].X, 0.5 - _vertices[0][i*3].Z);
		_vertices[0][i*3].glVertex();
	}
	glEnd();

	// top (circle)
	glBegin(GL_POLYGON);
	glNormal3f(0.0f, 1.0f, 0.0f);
	for (int i = 0; i < SLICES; i++)
	{
		glTexCoord2f(0.5 + _vertices[_stacks - 1][i].X, 0.5 - _vertices[_stacks - 1][i].Z);
		_vertices[_stacks - 1][i].glVertex();
	}
	glEnd();

#define helper(i, j) glTexCoord2f(0.5 + _vertices[i][j].X, 0.5 - _vertices[i][j].Z); \
	_normals[i][j].glNormal();  \
	_vertices[i][j].glVertex();

	// sides
	for (int i = 0; i < _stacks; ++i)
	{
		for (int j = 0; j < SLICES; ++j)
		{
			glBegin(GL_POLYGON);

			helper(i, j);
			helper(i, (j + 1) % SLICES);
			helper((i + 1) % _stacks, (j + 1) % SLICES);
			helper((i + 1) % _stacks, j);

			glEnd();
		}
	}

#undef helper
}
