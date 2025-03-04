#include "dyn_arr.h"
#include <stdio.h>
#include <stdbool.h>

typedef struct {
  float x;
  float y;
} Point;

typedef DynArr(Point) PointArr;

void deinit_point(Point *p) {
  printf("Goodbye, (%g, %g)\n", p->x, p->y);
}

bool point_in_arr(PointArr *arr, Point p) {
  darr_foreach(Point, arr, item)
    if (item->x == p.x && item->y == p.y) return true;

  return false;
}

void print_arr(PointArr *arr) {
  darr_foreach(Point, arr, p)
    printf("(%g, %g)\n", p->x, p->y);
}

int main() {
  PointArr arr;
  darr_init(&arr, deinit_point);

  darr_resize(&arr, 3);

  *darr_get(&arr, 0) = (Point) { 2.5, 2.5 };
  *darr_get(&arr, 1) = (Point) { 3.0, 1.0 };
  *darr_get(&arr, 2) = (Point) { 0.0, .5 };

  darr_push_slice(&arr, ((Point[]) { { 1.0, 2.0 }, { 4.0, 2.1 } }), 2);
  
  printf("---------\n");
  print_arr(&arr);
  printf("---------\n");

  if (point_in_arr(&arr, (Point) { 3, 1 }))
    printf("WOW, point (3, 1) is in the array!\n");

  darr_deinit(&arr);
  return 0;
}
