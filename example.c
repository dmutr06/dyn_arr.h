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
  darr_foreach(arr, item)
    if (item->x == p.x && item->y == p.y) return true;

  return false;
}

void print_arr(PointArr *arr) {
  darr_foreach(arr, p)
    printf("(%g, %g)\n", p->x, p->y);
}

int main() {
  PointArr arr = darr_init(Point, NULL);
  darr_push(&arr, (Point) { 2.5, 2.5 });
  darr_push(&arr, (Point) { 3, 1.0 });
  darr_push(&arr, (Point) { 0.0, 0.5 });
  
  printf("---------\n");
  print_arr(&arr);
  printf("---------\n");

  if (point_in_arr(&arr, (Point) { 3, 1 }))
    printf("WOW, point (3, 1) is in the array!\n");

  printf("---------\n");
  darr_deinit(&arr);
  return 0;
}
