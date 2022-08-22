%main function to run
dark = imread('Lab_03_image1_dark.tif'); 
%imwrite(dark, 'dark_img.png'); 
dark1 = equalize(dark) 
light = imread('Lab_03_image2_light.tif'); 
%imwrite(light, 'light_img.png'); 
light1 = equalize(light) 


