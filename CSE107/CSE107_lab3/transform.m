function [V] = transform(h) 
[~, column] = size(h); 
V = 1:256;
for i = 1:256 
sum = 0; 
for j = 1:i 
sum = sum + h(1,j); 
end 
V(i) = (column - 1)*sum; 
end 
