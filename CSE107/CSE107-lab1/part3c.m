%Read image
crowd = uint8(zeros(256,256));

%iterates through values 0-255
for i = 1:256
    crowd(i,:) = i - 1; 
end

%read crowd image
crowd = imread('Fig0225(c)(crowd).tif');
imshow(crowd)

% get the halftone
out = halftone(crowd);
figure;

imshow(out)
%halftoned image is wrote to new tif file
imwrite(out, 'crowd_halftone.tif');