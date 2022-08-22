function [out] = equilize(Matrix) 
% equalize turns an input image, makes a histogram of it, % and then transforms the image into a more equalized version % of itself. 
%Syntax: 
% out = equilize(Input) 
%Input: 
% Input = the original grayscale image which you wish to % give an equalized histogram as input %Output: 
% out = the rendered image of black and white pixels of % the picture which has an equalized histogram % as input 
%History: 
% V. Nguyen 04/10/2022 created 
%Matrix = imread('Lab_03_image1_dark.tif');
Original = Matrix; 
[rows,column] = size(Matrix); 
A = compute_histogram(Original); plot_histogram(A); 
%out = plot_histogram(A); 
Transformed = histogram_transform(A); Transformed = round(Transformed);
temp = 0; 
for i = 1:rows 
for j = 1:column 
temp = Matrix(i,j) + 1; 
Matrix(i,j) = Transformed(temp); 
end 
end 
%imwrite(Matrix, 'equilized_dark_img.png'); B = compute_histogram(Matrix); 
plot_histogram(B); 
out = B; 
Original = double(Original); 
Original = Original(:); 
Mo = mean(Original); 
So = std(Original); 
disp("mean origional: " + Mo); 
disp("std origional: " + So); 
Matrix = double(Matrix); 
Matrix = Matrix(:);
Mb = mean(Matrix); 
Sb = std(Matrix); 
disp("mean equilized: " + Mb); disp("std equilized: " + Sb);
