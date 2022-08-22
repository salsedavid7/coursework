%Create or read test image
test_img = uint8(zeros(256,256));

for c=1:256
    test_img(c,:) = c -1; % we want value from 0 to 255
end

%or
test_img = imread('Fig0225(a)(face).tif');
imshow(test_img)

% get the halftone
out = halftone(test_img);


figure;

imshow(out)

imwrite(out, 'face_halftone.tif');