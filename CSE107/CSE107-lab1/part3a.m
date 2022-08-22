face = uint8(zeros(256,256));

%iterates through values 0-255
for i = 1:256
    face(i,:) = i -1;
end

%read face image
face = imread('Fig0225(a)(face).tif');
imshow(face)

%get the halftone
out = halftone(face);
figure;

imshow(out)
%halftoned image is wrote to new tif file
imwrite(out, 'face_halftone.tif');
