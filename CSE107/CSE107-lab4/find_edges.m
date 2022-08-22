function[output] = find_edges(mat, thresh)

%computes gradient magnitude of image
output = gradient_magnitude(mat);

%dimension of grayscale image
[row, column] = size(output);
%detect edges and set them to value of 255 and 0 elsewhere
for i = 1:row
    for j = 1:column
        if(output(i,j) < thresh)
            output(i,j) = 0;
        else 
            output(i,j) = 255;
        end
    end
end
%typecast 
output = uint8(output);