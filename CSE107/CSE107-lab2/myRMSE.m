function e = myRMSE(A,B)
%we will compare each value and position and get the difference then we
%compare
%all the squares of these differences. Next, we add and get the summation
%of all the squares

%find rows and columns of original mat
[r,c] = size(A);
sum = double(0);

%solving using given equation
for i = 1:r
    for j = 1:c
        sum = sum + double(double(A(i,j)-double(B(i,j)))^2);
    end
end

e = sqrt(sum/(r*c));
end