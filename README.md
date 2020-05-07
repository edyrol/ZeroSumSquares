# Zero-sum Squares

Given an *n* x *m {-1,1}*-matrix

![$M=(a_{i,j}),$](https://render.githubusercontent.com/render/math?math=%24M%3D(a_%7Bi%2Cj%7D)%2C%24)

the discrepancy disc(*M*) is the sum of all its entries.

A square *S* in *M* is a *2* x *2* sub-matrix of *M* of the form

![$S=\begin{pmatrix}a_{i,j} & a_{i,j+s}\\a_{i+s,j} & a_{i+s,j+s}\end{pmatrix}$](https://render.githubusercontent.com/render/math?math=%24S%3D%5Cbegin%7Bpmatrix%7Da_%7Bi%2Cj%7D%20%26%20a_%7Bi%2Cj%2Bs%7D%5C%5Ca_%7Bi%2Bs%2Cj%7D%20%26%20a_%7Bi%2Bs%2Cj%2Bs%7D%5Cend%7Bpmatrix%7D%24)

for some positive integer *s*.

A zero-sum square is a square *S* with disc(*S*)*=0*.

This program finds all {-1,1}-colorings of a N by M matrix with discrepancy d and no zero-sum squares.

usage: ./main N M d [stop_at_first]

The results we obtained can be found in text format in the Results folder.
