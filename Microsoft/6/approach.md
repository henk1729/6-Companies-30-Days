## 391. Perfect Rectangle

1. If the sum total of areas of individual rectangles is not equal to the rectangle seemingly formed by min and max x and y coordinates, return `false`.
2. If the first condition is `true`, check for overlap.
3. For no overlap, for corners, if they(corners) appear in the `rectangles[i]` never or more than once, return `false'.
4. For no overlap, for other points, their(points') frequency should be `2`(two rectangles sharing a corner) or `4`(four rectangles sharing a corner).
5. If all the above conditions are met, the given rectangles form a proper rectangle cover.

#### To check for overlap
1. Create a vector of pair for coordinates of points.
2. Sort the vector, firstly by `first`, then by `second`.
3. Then count for adjacent coordinates in the vector if they are same.
4. Apply the conditions for overlap as discussed above in `4.`.
