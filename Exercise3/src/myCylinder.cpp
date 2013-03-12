#include "myCylinder.h"

myCylinder::myCylinder(int slices, int stacks/*, bool smooth*/) {
    _slices = slices;
    _stacks = stacks;

    const double angle = 2*PI / _slices;

    double ang = 0.0;
    double z = 0.0;
    for(int j = 0; j < _stacks ; ++j)
    {
        std::vector<Point> aux;
        vec.push_back(aux);

        for(int i = 0 ; i < _slices ; ++i)
        {
            Point p(cos(ang),sin(ang),z);
            vec[j].push_back(p);

                ang += angle;
        }

        z += 1.0/_stacks;
    }

}

void myCylinder::draw()
{
        glBegin(GL_POLYGON);
        for(int i = _slices - 1 ; i >= 0 ; --i)
                glVertex3d(vec[0][i].x , vec[0][i].y , vec[0][i].z);
        glEnd();

        glBegin(GL_POLYGON);
        for(int i = 0 ; i < _slices ; ++i)
            glVertex3d(vec[_stacks-1][i].x , vec[_stacks-1][i].y , vec[_stacks-1][i].z);
        glEnd();

        for(int i = 0 ; i < _stacks - 1; ++i)
            for(int j = 0 ; j < _slices; ++j)
            {
                if(j == _slices - 1)
                {
                    glBegin(GL_POLYGON);
                    glVertex3d(vec[i][j].x,vec[i][j].y,vec[i][j].z);
                    glVertex3d(vec[i][0].x,vec[i][0].y,vec[i][0].z);
                    glVertex3d(vec[i+1][0].x,vec[i+1][0].y,vec[i+1][0].z);
                    glVertex3d(vec[i+1][j].x,vec[i+1][j].y,vec[i+1][j].z);
                    glEnd();
                }
                else{

                    glBegin(GL_POLYGON);
                    glVertex3d(vec[i][j].x,vec[i][j].y,vec[i][j].z);
                    glVertex3d(vec[i][j+1].x,vec[i][j+1].y,vec[i][j+1].z);
                    glVertex3d(vec[i+1][j+1].x,vec[i+1][j+1].y,vec[i+1][j+1].z);
                    glVertex3d(vec[i+1][j].x,vec[i+1][j].y,vec[i+1][j].z);
                    glEnd();
                }
            }
}
