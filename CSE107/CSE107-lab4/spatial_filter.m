function [output] = spatial_filter(image, filter) 
%applies edge detection filter onto grayscale image outputting a matrix of type double
%image size in rows and columns
[IR,IC] = size(image);
[FR, FC] = size(filter);
    
matrix = zeros(IR + (FR - 2) * 2, IC + (FC - 2) * 2);
convertedMatrix = matrix;
output = zeros(IR,IC);
%type cast to double 
matrix = double(matrix);
image = double(image);
filter = double(filter);
output = double(output);

mid = FR - floor(FC / 2);

%apply image matrix onto matrix
for i = 1:IR
    for j = 1:IC
        matrix(i + (mid), j + (mid)) = image(i, j);
    end
end
    
[matrixRow,matrixColumn] = size(matrix);
 %spatial filering equation:
for i = mid:(matrixRow - mid + 1)
    for j = mid:(matrixColumn - mid + 1)
        sum = 0;
        for m = 1:FR
            for n = 1:FC
                sum = sum + filter(m,n) * matrix(i - (mid - m), j - (mid - n));
            end
        end
        convertedMatrix(i,j) = sum;
    end
end
%Convert Filtered Matrix to output
for i = 1:IR
    for j = 1:IC
        output(i,j) = double(convertedMatrix(i + (FR - 1), j + (FC - 1)));
    end
end


