function B = myimresize(A, xout, yout, method)

% resize original imagbe A to resized B

xval = xout;
yval = yout;

%input image size
[m, n] = size(A);

xr = xout / m;
yr = yout / n;

%output image with proper size
B = uint8(zeros(xval,yval));


            %use interpolation to determine the value at this location
            if strcmp(method, 'nearest')
                    for i = 1:1:xval
                        for j = 1:1:yval
                %map pixel values from new image to original
                            B(i,j) = A(ceil(i/xr), ceil(j/yr));
                        end
                    end
                    
                    
                elseif strcmp(method, 'bilinear')
            end
end

                    
            
            