#ifndef __BVHTREE_H__
#define __BVHTREE_H__

#include "triangle.h"
#include "pnt.h"
#include "line.h"

#include <cstdlib>

class BVHBox {
public:
	Vector2 x_range, y_range, z_range;
	int count;

	void calc_box(Triangle *t, int n);
	void clear();
	bool is_empty();
	void add(const Triangle& t);
	void add(const Vector3& p);
	float get_surface_area();
	void merge(const BVHBox& b);


	bool intersect(const Line3& line, float& min_intersect) const;
private:
};

class BVHTree {
public:

	Triangle *triangles;


	BVHBox box;


	BVHTree *left_son, *right_son;


	int l, r;


	bool is_leaf() const;

	void create_tree(int n, Triangle *triangles = NULL);

	bool intersect(const Line3& line, Vector3& result, int& index);
	bool intersect(const Line3& line, Vector4& result, int& index);

	static int CCOUNT;


	~BVHTree();

private:

	void _create(int l, int r);
	int _get_diff(const Triangle& t, float block_length, int type);
	float _get_block_length(int type);


	static const int BLOCK_SIZE;
	static BVHBox *_piece_box;
};

#endif // __BVHTREE_H__
