cameraman = uint8(zeros(256,256));

%iterates through values 0-255
for i = 1:256
    cameraman(i,:) = i - 1; 
end

%read cameraman image
cameraman = imread('Fig0225(b)(cameraman).tif');
imshow(cameraman)

% get the halftone
out = halftone(cameraman);


figure;

imshow(out)
%halftoned image is wrote to new tif file
imwrite(out, 'cameraman_halftone.tif');