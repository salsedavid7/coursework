function[h] = compute (matrix) 
[row, column] = size(matrix); 
h = zeros(1,256); 
for i = 1:row 
for j = 1:column 
value = double(matrix(i,j)); 
value = value + 1; 
h(value) = h (value) + 1; 
end 
end 
a = 0; 
for i = 1:256 
a = a + h(i); 
end
h = h / a; 
%(disp("check") 
% a = 0; 
% for i = 1:256 
% a = a + h(i); 
% end 
% if (a = 1) 
% disp("histogram complete"); % else 
% disp("histogram failed"); % end 
