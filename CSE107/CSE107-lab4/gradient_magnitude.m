function gradient_magnitude = gradient_magnitude(input_image)
 
% Convert the image to double
input_image = double(input_image);
  
% Sobel Operator Mask
Mx = [-1 0 1; -2 0 2; -1 0 1];
My = [-1 -2 -1; 0 0 0; 1 2 1];

%convolution of kernels with input image
Gx = spatial_filter(input_image, Mx);
Gy = spatial_filter(input_image, My);

%gradient magnitude
gradient_magnitude = sqrt(Gx.^2 + Gy.^2);

end