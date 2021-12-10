#include <cstdio>
#include <vector>
#include "pnt.h"
#include "triangle.h"
#include "line.h"
#include "common.h"
#include "bvhtree.h"


using namespace std;


int main() {
	Line3 a(Vector3(0, 0, -200), Vector3(0, 1.23, 30));

	Vector4 v;
	int index;

	vector<Triangle> triangles;
	read_obj_file("../data/yaya.obj", triangles);

	BVHTree tree;
	tree.create_tree(triangles.size(), &triangles[0]);


	for (int i = 0; i < triangles.size(); ++i)
		if (triangles[i].intersect(a, v)) {
			printf("%d\n", i);
		}


	tree.CCOUNT = 0;
	if (tree.intersect(a, v, index)) {
		printf("%f %f %f  |  %d\n", v.x, v.y, v.z, index);
		printf("%d\n", tree.CCOUNT);
	}

	return 0;
}
