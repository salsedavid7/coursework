%main function to call helper functions
A = imread('watertower.tif');
%imshow(A);

in = find_edges(A, 200);
imshow(in);

%canny = edge(A, 'canny');
%figure;
%imshow(canny);



