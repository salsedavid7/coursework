%this is script for lab 3 
dark = imread('Lab_03_image1_dark.tif'); 
darke = equilize(dark); 
imwrite(darke, 'dark2_img.png'); 
%light = imread('Lab_03_image2_light.tif'); 
%imwrite(light, 'light_img.png'); 
%lighte = equilize(light); 
