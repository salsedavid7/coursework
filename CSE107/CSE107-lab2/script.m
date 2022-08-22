%main script for lab 2

A = imread('Lab_02_image1.tif');

%nearest neighbor interpolation image resize
B = myimresize(A, 40, 75, 'nearest');
B1 = myimresize(B, 300, 300, 'nearest');

%used for the 425x600 image
%B = myimresize(A, 425, 600, 'nearest');

%bilinear interpolation image resize
C = imresize(A,[600, 750], 'bilinear');
C1 = imresize(C,[300, 300], 'bilinear');

imshow(B);
imshow(B1);

E = myRMSE(A, B);




