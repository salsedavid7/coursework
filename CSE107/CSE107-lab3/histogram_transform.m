%transforms the normalized histogram into pixels
function T = histogram_transform(h)
    [row,column] = size(h);
    T = 1:256;
    for i = 1:256 
        sum = 0; 
        for j = 1:i 
            sum = sum + h(1,j); 
        end 
        T(i) = (column - 1)*sum; 
    end 